#include "dcel.h"
#include<stdio.h>

void printDcel(Dcel* dcel){
    printf ("vertex\n");
    for(int i = 0 ; i < dcel->totalVertices;i++)
    {
        printf("%f %f \n", dcel->vertices[i].x, dcel->vertices[i].y);
    }
    printf ("edges\n");
    for(int i = 0 ; i < dcel->totalEdges;i++)
    {
        printf("%d\n", dcel->edges[i].edgeIndex);
    }
    printf ("halfedges\n");
    for(int i = 0 ; i < dcel->totalHalfEdges;i++)
    {
        //printf("startVertexIndex=%d ,endVertexIndex=%d ,faceIndex=%d ,edgeIndex=%d\n", dcel->halfEdges[i].startVertexIndex, dcel->halfEdges[i].endVertexIndex, dcel->halfEdges[i].faceIndex, dcel->halfEdges[i].edgeIndex);

        printf("startVertexIndex=%d ,endVertexIndex=%d ,nextEdge=%d ,previousEdge=%d ,faceIndex=%d ,edgeIndex=%d\n",
            dcel->halfEdges[i].startVertexIndex,
            dcel->halfEdges[i].endVertexIndex,
            dcel->halfEdges[i].nextEdge->edgeIndex,
            dcel->halfEdges[i].previousEdge->edgeIndex,
            dcel->halfEdges[i].faceIndex,
            dcel->halfEdges[i].edgeIndex);
    }
    printf ("faces\n");
    for(int i = 0 ; i < dcel->totalFaces;i++)
    {
        printf("FaceIndex:%d, Edges=> %d, ", i, dcel->faces[i].halfEdge->edgeIndex);
        halfEdge* temp = dcel->faces[i].halfEdge->nextEdge;
        while (temp != dcel->faces[i].halfEdge)
        {
            printf("%d, ", temp->edgeIndex);
            temp = temp->nextEdge;
        }
        printf("\n");
    }
}
// Assuming CW traversal
void split(Dcel* dcel,unsigned int edge1, unsigned int edge2)
{

    // Find mid points of the passed edges;
    // new x from edge1
    double xs1 = dcel->vertices[dcel->edges[edge1].halfECW->startVertexIndex].x; // start x
    double xe1 = dcel->vertices[dcel->edges[edge1].halfECW->endVertexIndex].x; // end x
    double newX1 = (xe1 - xs1) / 2.0;

    // new y from edge1
    double ys1 = dcel->vertices[dcel->edges[edge1].halfECW->startVertexIndex].y; // start x
    double ye1 = dcel->vertices[dcel->edges[edge1].halfECW->endVertexIndex].y; // end x
    double newY1 = (ye1 - ys1) / 2.0;


    // new x from edge2
    double xs2 = dcel->vertices[dcel->edges[edge2].halfECW->startVertexIndex].x; // start x
    double xe2 = dcel->vertices[dcel->edges[edge2].halfECW->endVertexIndex].x; // end x
    double newX2 = (xe2 - xs2) / 2.0;

    // new y from edge2
    double ys2 = dcel->vertices[dcel->edges[edge2].halfECW->startVertexIndex].y; // start x
    double ye2 = dcel->vertices[dcel->edges[edge2].halfECW->endVertexIndex].y; // end x
    double newY2 = (ye2 - ys2) / 2.0;

    // Create new partined edged.
    // A----------B -> A-----S----B ;;  P--------------Q -> P---------T-----Q
    // X = (newX, newY) as calculated above
    // Update edge A->B to now become A->S and then added another edge S->B to edge list.
    // Face will also get updated, edge1 will become A-S, and the newly created edge will become part of this face.

    // add new vertex to vertices array. Let say it was added at inedx newVE1
    // New vertex was added on index newVertexIndex;
    int newVertexIndex = dcel->totalVertices;
    dcel->vertices[newVertexIndex].x = newX1;
    dcel->vertices[newVertexIndex].y = newY1;

    // New vertex added onto edge 2, lets say it was added at index newVE2
    dcel->vertices[newVertexIndex + 1].x = newX2;
    dcel->vertices[newVertexIndex + 1].y = newY2;

    dcel->totalVertices += 2;

    /// Create new half edge for newly created edge S->T
    /// no. of total half edges were = totalHalfEdges.
    // allocate new halfEdge data item then set values toas below.

    ///New half edge
    unsigned int edgeIndexNewHalfEdge = dcel->totalEdges;
    halfEdge* newHalfEdge = &dcel->halfEdges[dcel->totalHalfEdges];
    newHalfEdge->startVertexIndex = newVertexIndex;
    newHalfEdge->endVertexIndex = newVertexIndex + 1;
    newHalfEdge->nextEdge = dcel->edges[edge2].halfECW; // assuming a CW traversal, else edge1;
    newHalfEdge->previousEdge = dcel->edges[edge1].halfECW;
    newHalfEdge->faceIndex = dcel->edges[edge1].halfECW->faceIndex;
    newHalfEdge->edgeIndex = edgeIndexNewHalfEdge; // we are adding new edge hence increment totalEdges variable

    dcel->edges[edgeIndexNewHalfEdge].halfECW = newHalfEdge;
    dcel->edges[edgeIndexNewHalfEdge].edgeIndex = edgeIndexNewHalfEdge;
    dcel->totalEdges++;
    dcel->totalHalfEdges++;


    // New halfEdge out of edge1
    unsigned int edgeIndexNewHalfEdge1 = dcel->totalEdges;
    halfEdge* newHalfEdge1 = &dcel->halfEdges[dcel->totalHalfEdges];
    newHalfEdge1->startVertexIndex = newVertexIndex;
    newHalfEdge1->endVertexIndex = dcel->edges[edge1].halfECW->endVertexIndex;
    newHalfEdge1->previousEdge = newHalfEdge;
    newHalfEdge1->faceIndex = dcel->totalFaces;
    newHalfEdge1->edgeIndex = edgeIndexNewHalfEdge1; // we are adding new edge hence increment totalEdges variable
    dcel->edges[edgeIndexNewHalfEdge1].halfECW = newHalfEdge1;
    dcel->edges[edgeIndexNewHalfEdge1].edgeIndex = edgeIndexNewHalfEdge1;
    dcel->totalHalfEdges++;
    // Add a CCW half edge as well
    if (dcel->edges[edge1].halfECCW)
    {
        halfEdge* newHalfEdge1ccw = &dcel->halfEdges[dcel->totalHalfEdges];
        dcel->edges[edgeIndexNewHalfEdge1].halfECCW = newHalfEdge1ccw;
        newHalfEdge1ccw->startVertexIndex = newHalfEdge1->endVertexIndex;
        newHalfEdge1ccw->endVertexIndex = newHalfEdge1->startVertexIndex;
        newHalfEdge1ccw->nextEdge = dcel->edges[edge1].halfECCW; // assuming a CW traversal, else edge1;
        newHalfEdge1ccw->previousEdge = dcel->edges[edge1].halfECCW->previousEdge;
        newHalfEdge1ccw->faceIndex = dcel->edges[edge1].halfECCW->faceIndex;
        newHalfEdge1ccw->edgeIndex = edgeIndexNewHalfEdge1;
        dcel->totalHalfEdges++;
    }
    dcel->totalEdges++;


    //new halfEdge out of edge2
    unsigned int edgeIndexNewHalfEdge2 = dcel->totalEdges;
    halfEdge* newHalfEdge2 = &dcel->halfEdges[dcel->totalHalfEdges];
    newHalfEdge2->startVertexIndex = dcel->edges[edge2].halfECW->startVertexIndex;
    newHalfEdge2->endVertexIndex = newVertexIndex;
    newHalfEdge2->previousEdge = dcel->edges[dcel->totalEdges - 1].halfECW;
    newHalfEdge2->faceIndex = dcel->totalFaces;
    newHalfEdge2->edgeIndex = edgeIndexNewHalfEdge2; // we are adding new edge hence increment totalEdges variable
    dcel->edges[edgeIndexNewHalfEdge2].halfECW = newHalfEdge2;
    dcel->edges[edgeIndexNewHalfEdge2].edgeIndex = edgeIndexNewHalfEdge2;
    dcel->totalHalfEdges++;
    // Add a CCW half edge as well
    if (dcel->edges[edge2].halfECCW)
    {
        halfEdge* newHalfEdge2ccw = &dcel->halfEdges[dcel->totalHalfEdges];
        dcel->edges[edgeIndexNewHalfEdge2].halfECCW = newHalfEdge2ccw;
        newHalfEdge2ccw->startVertexIndex = newHalfEdge2->endVertexIndex;
        newHalfEdge2ccw->endVertexIndex = newHalfEdge2->startVertexIndex;
        newHalfEdge2ccw->nextEdge = dcel->edges[edge2].halfECCW->nextEdge; // assuming a CW traversal, else edge1;
        newHalfEdge2ccw->previousEdge = dcel->edges[edge2].halfECCW;
        newHalfEdge2ccw->faceIndex = dcel->edges[edge2].halfECCW->faceIndex;
        newHalfEdge2ccw->edgeIndex = edgeIndexNewHalfEdge2;
        dcel->totalHalfEdges++;
    }
    dcel->totalEdges++;
    newHalfEdge1->nextEdge = newHalfEdge2; // assuming a CW traversal, else edge1;

    // Twin of the newly added halfEdge
    halfEdge* newHalfTwin = &dcel->halfEdges[dcel->totalHalfEdges];
    newHalfTwin->startVertexIndex = newHalfEdge2->endVertexIndex;
    newHalfTwin->endVertexIndex = newHalfEdge1->startVertexIndex;
    newHalfTwin->nextEdge = dcel->edges[edgeIndexNewHalfEdge1].halfECW; // assuming a CW traversal, else edge1;
    newHalfTwin->previousEdge = dcel->edges[edgeIndexNewHalfEdge2].halfECW;
    newHalfTwin->faceIndex = dcel->totalFaces;
    newHalfTwin->edgeIndex = edgeIndexNewHalfEdge; // we are adding new edge hence increment totalEdges variable
    dcel->edges[edgeIndexNewHalfEdge].halfECCW = newHalfTwin;
    dcel->totalHalfEdges++;

    newHalfEdge2->nextEdge = newHalfTwin; // assuming a CW traversal, else edge1;


    dcel->edges[edge1].halfECW->endVertexIndex = newVertexIndex; // set end of edge1 to S
    dcel->edges[edge1].halfECW->nextEdge = newHalfEdge;
    if (dcel->edges[edge1].halfECCW)
        dcel->edges[edge1].halfECCW->startVertexIndex = newVertexIndex; // set start of CCW edge1 to S

    dcel->edges[edge2].halfECW->startVertexIndex = newVertexIndex + 1; // set end of edge2 to new vertex T
    if (dcel->edges[edge2].halfECCW)
        dcel->edges[edge2].halfECCW->endVertexIndex = newVertexIndex + 1; // set end of edge2 to new vertex T

    face* newFace = &dcel->faces[dcel->totalFaces];
    newFace->halfEdge = newHalfTwin;
    dcel->totalFaces++;
}

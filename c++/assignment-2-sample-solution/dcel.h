#ifndef _DCEL_H
#define _DCEL_H

typedef struct halfEdge
{
	unsigned int startVertexIndex;
	unsigned int endVertexIndex;
	struct halfEdge* nextEdge;
	struct halfEdge* previousEdge;
	struct halfEdge* twinEdge;
	unsigned int faceIndex;
	unsigned int edgeIndex;
}halfEdge;

typedef struct vertex
{
	double x;
	double y;
}vertex;

typedef struct edge
{
	unsigned int edgeIndex;
	struct halfEdge* halfECCW; // half edge counter clock wise
	struct halfEdge* halfECW;	// half endge clock wise
}edge;

typedef struct face
{
	struct halfEdge* halfEdge;
}face;


typedef struct Dcel
{
	int totalVertices;
	int totalHalfEdges;
	int totalFaces;
	int totalEdges;

	struct vertex* vertices;
	struct edge* edges;
	struct face* faces;
	struct halfEdge* halfEdges;

	//halfEdge
	// void setStartIndexVertex(unsigned int);
	// int getStartIndexVertex();
	// void setEndIndexVertex(unsigned int);
	// int getEndIndexVertex();
	// void setNextEdge(halfEdge*);
	// halfEdge* getNextEdge();
	// void setPreviousEdge(halfEdge*);
	// halfEdge* getPreviousEdge();
	// void setTwinEdge(halfEdge*);
	// halfEdge* getTwinEdge();
	// void setFaceIndex(unsigned int);
	// int getFaceIndex();
	// void setEdgeIndex(unsigned int);
	// int getEdgeIndex();
}Dcel;

void printDcel(Dcel* dcel);

void split(Dcel* dcel,unsigned int edge1, unsigned int edge2);

#endif
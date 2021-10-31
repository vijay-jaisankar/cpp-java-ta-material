#include<bits/stdc++.h>
#include "Point.h"

int main(){

    // Constructing Objects
    Point p1(10,20,"Point1");
    Point p2(30,50,"Point2");
    Point p3;
    Point p4(p3); // Note: Copy construction doesn't increment the Index (in our implementation)

    // Calling delete explicitly

    // delete &p1; - Gives error "Invalid free() / delete / delete[] / realloc()" - Double Free
    return 0;

}
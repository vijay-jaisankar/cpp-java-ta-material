#include<bits/stdc++.h>
#include "Point.h"

int Point::index = 1;

// Contructors
Point::Point(){
    this->x = 10;
    this->y = 20;
    this->name = "Thanos";
    this->pointIndex = Point::index++;
}

Point::Point(int x, int y, std::string name){
    this->x = x;
    this->y = y;
    this->name = name;
    this->pointIndex = Point::index++;
}

Point::Point(Point &obj){
    this->x = obj.x;
    this->y = obj.y;
    this->pointIndex = obj.pointIndex;
    this->name = obj.name;
}

// Setters
void Point::setX(int x){
    this->x = x;
}

void Point::setY(int y){
    this->y = y;
}

void Point::setName(std::string name){
    this->name = name;
}

// Getters
int Point::getX(){
    return this->x;
}

int Point::getY(){
    return this->y;
}

std::string Point::getName(){
    return this->name;
}

/*
    Destructors have the following properties
        - Do not accept arguments
        - Do not have a return type
        - Can't be declared as const/static but can "destroy" const/static objects
*/

// Destructor
Point::~Point(){
    std::cout<<"Point with index "<<this->pointIndex<<" has been yeeted.\n";

    // delete &(this->name); - Double Free Error again! C++ gives us an "automatic" destructor : _Tidy
}







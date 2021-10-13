#include<bits/stdc++.h>
#include "Image.h"

/*
    "this" keyword can be used as follows: https://www.geeksforgeeks.org/this-pointer-in-c/
*/

// Default Constructor
Image::Image(){
    width = 10.0;
    height = 10.0;
}

// Parameterised Constructor. Note: Can add default values here too.
Image::Image(float w, float h){
    width = w;
    height = h;
}

// Copy Constructor
Image::Image(Image& obj){
    width = obj.width;
    height = obj.height;
}

// Destructor
Image::~Image(){
     std::cout<<"Object with height "<<height<<" and width "<<width<<" Out of Scope!"<<"\n";
}

// Setters and Getters
void Image::setWidth(float w){
    if(w >= 0){
        width = w;
    }
}

void Image::setHeight(float h){
    if(h >= 0){
        height = h;
    }
}

float Image::getWidth(){
    return width;
}

float Image::getHeight(){
    return height;
}

// Implementation of the Aspect Ratio Function
float Image::getAspectRatio(){
    return width/height;
}


#include<bits/stdc++.h>
#ifndef POINT_H
#define POINT_H

class Point{
    private:
        // Variables
        int x;
        int y;
        std::string name;
        int pointIndex;
    
    public:

        // ID Generator
        static int index;

        // Constructors
        Point(int,int,std::string);
        Point();
        Point(Point&);

        // Setters
        void setX(int x);
        void setY(int y);
        void setName(std::string);

        // Getters
        int getX();
        int getY();
        std::string getName();

        // Destructor
        ~Point();

};

#endif
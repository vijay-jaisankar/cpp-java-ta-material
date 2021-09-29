#include<bits/stdc++.h>


    /*
        This is a docstring - good idea
    */
    int thisIsARandomFunction(int x, int y){
        
        // Functionality 1 - must
        int z = x+y; // Adds two numbers - overkill


        // Functionality 2
        int a = x*y; // ...

        // Functionality 3
        int b = x/y; // ...

        return z*a*b;   
    }



int main(){

    int x = 10;
    int y = 20;

    int z = thisIsARandomFunction(x,y);
    std::cout<<z;

    return 0;

}
#include "base.h"

#include "derived.h"

#include <bits/stdc++.h>


int main(){

    /*
        GROUP 0
    */

      Base b(4,5,6);
      Derived d(1,2,3);

    /*
        GROUP 1
    */

    // d = b;

    /*
        GROUP 2
    */

    // b = d;


    /*
        GROUP 3
    */

    // std::cout<<b.privateVariable;
    // b.privateFunctionality();

    /*
        GROUP 4
    */

    // std::cout<<b.protectedVariable;
    // b.protectedFunctionality();

    /*
        GROUP 5
    */

    //b.publicFunctionality();
    //std::cout<<b.publicVariable<<std::endl;

    /*
        GROUP 6
    */

    // std::cout<<d.privateVariable;
    // d.privateFunctionality();

    /*
        GROUP 7
    */

    // std::cout<<d.protectedVariable;
    // d.protectedFunctionality();

    /*
        GROUP 8
    */

    // d.publicFunctionality();
    // std::cout<<d.publicVariable<<std::endl;

    /*
        GROUP 9
    */

    // Base::coolFunction();
    
    /*
        GROUP 10
    */
   
    // Derived::coolFunction();

    /*
        GROUP 11
    */

   // d.accessFunctionality();
    return 0;
}
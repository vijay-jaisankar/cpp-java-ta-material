#include <bits/stdc++.h>
#include "Image.h"


int main(){

    // Using the three constructors declared and defined.
    Image image1(10.0,20.0);
    Image image2;
    Image image3(image1);
    Image image4(100.0,60.0);

    // Printing the aspect ratios of the images.
    std::cout<<image1.getAspectRatio()<<"\n";
    std::cout<<image2.getAspectRatio()<<"\n";
    std::cout<<image3.getAspectRatio()<<"\n";

    // Note that the output signifies that the objects are destroyed in reverse order of their construction. 
    // What Data Structure pops into your head when you read this sentence?
    return 0;
}
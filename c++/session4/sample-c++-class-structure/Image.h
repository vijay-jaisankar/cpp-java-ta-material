/*
    DECLARE GUARDS
*/
#ifndef IMAGE_H
#define IMAGE_H

/*
    This class represents an image and provides the following functionalities:
        - Ability to manipulate heights and widths
        - Get the aspect ratio of the image
*/

class Image{
    private:
        /*
            DATA MEMBERS
        */
        float width;
        float height;

    public:
        /*
            COPY CONSTRUCTORS
        */
        Image();
        Image(float, float);
        Image(Image&);

        /*
            DESTRUCTOR
        */
        ~Image();

        /*
            GETTERS AND SETTERS
        */
        void setWidth(float);
        void setHeight(float);

        float getWidth();
        float getHeight();

        /*
            Function to get the aspect ratio of the image
        */
        float getAspectRatio(); 

};




#endif
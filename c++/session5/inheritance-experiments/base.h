#ifndef BASE_H
#define BASE_H

class Base{

    private:
        int privateVariable;

        void privateFunctionality();
    
    protected:
        int protectedVariable;

        void protectedFunctionality();
    
    public:
        int publicVariable;

        Base(int,int,int);
        Base(const Base&);
        ~Base();

        void publicFunctionality();
        static void coolFunction();

};


#endif
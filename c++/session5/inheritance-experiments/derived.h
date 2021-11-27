#include "base.h"

#ifndef DERIVED_H
#define DERIVED_H

class Derived : public Base{
    private:
        int newPrivateVariable;
    
    protected:
        int newProtectedVariable;

        static void coolFunction();

        //void protectedFunctionality();
    
    public:
        int newPublicVariable;

        Derived(int,int,int);
        Derived(const Derived&);
        ~Derived();

        void publicFunctionality();
        void newPublicFunctionality();
        void privateFunctionality();

        void accessFunctionality();
}; 



#endif
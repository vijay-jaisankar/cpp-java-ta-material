#include "derived.h"
#include <bits/stdc++.h>

Derived::Derived(int privateVar, int protectedVar, int publicVar) : Base(privateVar,protectedVar,publicVar){

    this->newPrivateVariable = privateVar;
    this->newProtectedVariable = protectedVar;
    this->newPublicVariable = publicVar;
}

Derived::Derived(const Derived &obj) : Base(obj.newPrivateVariable,obj.newProtectedVariable,obj.newPublicVariable){
    this->newPrivateVariable = obj.newPrivateVariable;
    this->newProtectedVariable = obj.newProtectedVariable;
    this->newPublicVariable = obj.newPublicVariable;
}

Derived::~Derived(){
    std::cout<<"Derived class object with private variable :  "<<this->newPrivateVariable<<", protected variable : "<<this->newProtectedVariable<<" and public variable : "<<this->newPublicVariable<<" has been yeeted."<<std::endl; 
}

void Derived::privateFunctionality(){
    std::cout<<"Derived class has changed the access specifier of the private base class method."<<std::endl;
}

void Derived::newPublicFunctionality(){
    std::cout<<"New functionality of derived class, this is what differentiates inheritance from abstract classes."<<std::endl;
}

void Derived::publicFunctionality(){
    Base::publicFunctionality();
    std::cout<<"Derived class Public functionality."<<std::endl;
}

void Derived::coolFunction(){
    std::cout<<"Derived class is cool"<<std::endl;
}

void Derived::accessFunctionality(){

    std::cout<<"Private Stuff"<<std::endl;
    this->privateFunctionality();
    //Base::privateFunctionality();   // This line Won't work

    std::cout<<"Protected stuff"<<std::endl;
    this->protectedFunctionality();
    Base::protectedFunctionality();

    std::cout<<"Public stuff"<<std::endl;
    this->publicFunctionality();
    Base::publicFunctionality();
}
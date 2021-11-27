#include "base.h"
#include <bits/stdc++.h>

Base::Base(int privateVar, int protectedVar, int publicVar){
    this->privateVariable = privateVar;
    this->protectedVariable = protectedVar;
    this->publicVariable = publicVar;
}

Base::Base(const Base& obj){
    this->privateVariable = obj.privateVariable;
    this->protectedVariable = obj.protectedVariable;
    this->publicVariable = obj.publicVariable;
}

Base::~Base(){
    std::cout<<"Base class object with private variable :  "<<this->privateVariable<<", protected variable : "<<this->protectedVariable<<" and public variable : "<<this->publicVariable<<" has been yeeted."<<std::endl; 
}

void Base::privateFunctionality(){
    std::cout<<"Base class Private Functionality"<<std::endl;
}

void Base::protectedFunctionality(){
    std::cout<<"Base class Protected Functionality"<<std::endl;
}

void Base::publicFunctionality(){
    std::cout<<"Base class Public Functionality"<<std::endl;
}

void Base::coolFunction(){
    std::cout<<"Base class is cool"<<std::endl;
}
#ifndef DOG
#define DOG

#include "Animal.h"

class Dog: public Animal { 
    public: 
        Dog(); 
        Dog(string );
        Dog(int ); // overloading the constructor
   
        // overriding
        void makeNoise() override; 
    
        void woof(); 
};

#endif
#ifndef CAT
#define CAT

#include "Animal.h"

class Cat: public Animal {
      public: 
        Cat(); 
        Cat(string ); 
          
        // overriding
        void makeNoise() override; 
    
        void meow(); 

};

#endif
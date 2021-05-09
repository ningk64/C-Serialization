#include "Animal.h"
#include "Cat.h"

#include <iostream> 

using namespace std; 

Cat::Cat():Animal(){}

// pass the n to the superclass constructor
Cat::Cat(string n): Animal(n){}

void Cat::makeNoise(){ 
    cout << "I'm a cat so... "; 
    meow(); 
}

void Cat::meow(){ 
    cout << "Meow, said " << name << endl; 
}

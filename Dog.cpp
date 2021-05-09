#include "Dog.h" 
#include "Animal.h"

#include <iostream> 
#include <stdio.h> 
#include <unistd.h>

using namespace std;

Dog::Dog():Animal(){}

Dog::Dog(string n):Animal(n){}

Dog::Dog(int n):Animal(""){
    //char* tmp = new char[20]; // actually leaking memory lol
    //sprintf(tmp, "Dog number %d", n);
    name = "Dog number " + to_string(n);
}

void Dog::makeNoise(){ 
    cout << "I'm a dog so... "; 
    woof(); 
}

void Dog::woof(){ 
    cout << "Woof, said " << name << endl; 
}
    

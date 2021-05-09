#include "Animal.h"

Animal::Animal(){ // needed by cereal
    name = "Unnamed"; 
}

Animal::Animal(string s):name(s){ }

Animal::~Animal(){ 
}

string Animal::getName(){ 
    return name;  
}

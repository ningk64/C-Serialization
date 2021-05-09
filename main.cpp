#include <iostream> 
#include <fstream> 
#include <unistd.h>
 
#include "cereal/archives/binary.hpp" // for binary serialization
#include "cereal/archives/xml.hpp" // for XML serialization

#include "AnimalPerson.h"
#include "Dog.h"
#include "Cat.h"

using namespace std; 

int main() { 
   
    // make objects 
    AnimalPerson<Dog> charlie = 
        AnimalPerson<Dog>("Charlie", Dog("Cookie"));
    AnimalPerson<Cat> dan = 
        AnimalPerson<Cat>("Dan", Cat("Dusty"));
      
    charlie.playWithPet(); 
    cout << endl; 
    
    dan.playWithPet();
    cout << endl; 
    
    // serialize our objects to files 

    { // make a new scope to destroy the archive    
        
        // create a file stream
        ofstream xmlout("storagefile.xml"); 
        // create a serializable archive
        cereal::XMLOutputArchive xmlar( xmlout );
        // serialize the classes we want
        xmlar(charlie);
        xmlar(dan);
        
        // create a file stream
        ofstream binout("storagefile.bin", std::ios::binary);
        // create a serializable archive
        cereal::BinaryOutputArchive binar( binout );
        // serialize the classes we want
        binar(charlie);
        binar(dan);
        
        // the archives go out of scope and finish serializing
    }
    
    // deserialize our objects from files
    
    { // make another scope for reading from archives  
        
        // variables for reading objects
        AnimalPerson<Dog> newCharlie; 
        AnimalPerson<Cat> newDan; 
         
        // make a file stream
        ifstream xmlin("storagefile.xml"); 
        // make an input archive
        cereal::XMLInputArchive xmlar(xmlin);
        // read the archive into variables
        xmlar(newCharlie);
        xmlar(newDan);
        
        // test that our objects behave as expected 
        cout << "Extracted from XML archive: " << endl; 
        newCharlie.playWithPet();
        cout << endl; 
        newDan.playWithPet();
        cout << endl; 
        
        // make a file stream
        ifstream binin("storagefile.bin", std::ios::binary);
        // make an input archive
        cereal::BinaryInputArchive binar( binin );
        // read the archive into variables
        binar(newCharlie);
        binar(newDan);
        
        // test that our objects behave as expected
        cout << "Extracted from binary archive: " << endl; 
        newCharlie.playWithPet();
        cout << endl; 
        newDan.playWithPet();
        cout << endl; 
        
    }

    return 0; 
}
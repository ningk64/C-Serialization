#ifndef ANIMALPERSON
#define ANIMALPERSON

#include <string> 
#include <cereal/types/string.hpp>

using namespace std; 

template<typename Animaltype>
class AnimalPerson { 
    public: 
    
        // needed for cereal 
        AnimalPerson(): 
            name("Unnamed"), adoptedPet(Animaltype()){ }
    
        AnimalPerson(string n, Animaltype pet): 
            name(n), adoptedPet(pet){ }
            
        ~AnimalPerson(){} 
     
        string getName(){ 
            return name; 
        } 
    
        void playWithPet(){ 
            cout << "Fetch, says " << getName() << endl;
            adoptedPet.makeNoise(); 
        }
        
        template<class Archive>
        void serialize(Archive & archive){
            // serialize things by passing them to the archive
            archive(name, adoptedPet); 
        }
        
        
    private: 
        Animaltype adoptedPet;
        string name; 
};



#endif
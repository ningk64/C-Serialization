#ifndef ANIMAL
#define ANIMAL

#include <pthread.h>
#include <semaphore.h> 
#include <string>

#include <cereal/types/string.hpp> // needed for cereal

using namespace std; 

class Animal { 
    public: 
        Animal();
        Animal(string s);
        virtual ~Animal();
     
        string getName(); 
    
        virtual void makeNoise() = 0; 
     
        // counting treats
        static int treats; 
    
        // guarding the treats variable
        static pthread_mutex_t treatsMux; 
   
        // guarding animal release
        static sem_t petsReleaseSem; 

        // for cereal
        template<class Archive>
        void serialize(Archive & archive){
            archive(name); 
        }
    
       bool operator < (const Animal& a) const {
           return name < a.name;
       }
    
    protected: // subclasses can access, assuming that the inheritance is public/protected
        string name;  
};

#endif
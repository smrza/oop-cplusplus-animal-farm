#include <iostream>
#include "dog.h"
using std::cout;
Dog::Dog() //default pes
 : Mammal("Bezejmenny pes"), mBreed(DOG_DOBERMAN)
{
 cout << "Dog constructor called\n";
}
Dog::Dog(string name, int age, int weight, DogBreed breed) //konstruktor pro zapsani psa z klavesnice
 : Mammal(name, age, weight), mBreed(breed)
{
 mWeight = weight;
 cout << "Dog(string, int, int, DogBreed) constructor called\n";
}
Dog::~Dog() //destruktor
{
 cout << "Dog destructor called\n";
}

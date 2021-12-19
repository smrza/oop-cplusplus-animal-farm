#ifndef DOG_H
#define DOG_H
#include <iostream>
#include "mammal.h"
using std::cout;
// Vyctovy typ pro plemeno psa
enum DogBreed { DOG_DOBERMAN, DOG_TERRIER, DOG_MALAMUTE, DOG_BULLDOG };
// Trida Pes odvozena od Savec
class Dog : public Mammal
{
public:
 //konstruktory
 Dog();
 Dog(string name, int age, int weight, DogBreed breed);
 virtual ~Dog(); //destruktor
 int GetBreed() const { return mBreed; }
 void SetBreed(DogBreed breed) { mBreed = breed; }
 string GetBreedByName(enum DogBreed breed) const { //funkce vracející název plemene pro vypis
     switch (breed) { case DOG_DOBERMAN: return "Doberman"; case DOG_TERRIER: return "Terrier"; case DOG_MALAMUTE: return "Malamute"; case DOG_BULLDOG: return "Bulldog"; }
 }
 void WagTail() const { cout << "Vrteni ocaskem...\n"; }
 virtual void Speak() const { cout << "Haf Haf!\n"; }
 virtual void PrintName() const { cout << "Pes se jmenuje: " << Dog::GetName() << "\n"; }
 virtual void PrintAge() const { cout << "Psovi je: " << Dog::GetAge() << " let.\n"; }
 virtual void PrintWeight() const { cout << "Pes vazi: " << Dog::GetWeight() << " kg.\n"; }
 //virtual void PrintMilkProduced() const { cout << "Mleko od psu nepijeme.\n"; } ... nevyužito
 virtual void PrintAnimal() const {
     Dog::PrintName();
     cout << "Plemeno psa je: ";
     cout << Dog::GetBreedByName(Dog::mBreed);
     cout << "\n";
     Dog::PrintAge(); Dog::PrintWeight(); Dog::Speak();
 }
protected:
 DogBreed mBreed; // plemeno psa
};
#endif // DOG_H

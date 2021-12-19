#ifndef BIRD_H
#define BIRD_H
#include <iostream>
#include "animal.h"
using std::cout;

// Trida Bird odvozena od Animal
class Bird : public Animal
{
public:
 //konstruktory
 Bird();
 Bird(string name);
 Bird(string name, int age, int weight, int wingspan);
 virtual ~Bird(); //destruktor
 int GetWingspan() const { return mWingspan; }
 void SetWingspan(int wingspan) { mWingspan = wingspan; }
 virtual void Speak() const { cout << "Ptaci zvuk!\n"; }
 virtual void PrintName() const { cout << "Ptak se jmenuje: " << Bird::GetName() << "\n"; }
 virtual void PrintAge() const { cout << "Ptaku je: " << Bird::GetAge() << " let.\n"; }
 virtual void PrintWeight() const { cout << "Ptak vazi: " << Bird::GetWeight() << " kg.\n"; }
 virtual void PrintWingspan() const { cout << "Rozpeti kridel ptaka je: " << Bird::GetWingspan() << " m.\n"; }
 virtual void PrintAnimal() const { Bird::PrintName(); Bird::PrintAge(); Bird::PrintWeight(); Bird::Speak(); Bird::PrintWingspan(); }
protected:
 int mWingspan; //rozpeti kridel
};
#endif // BIRD_H

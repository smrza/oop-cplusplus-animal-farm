#ifndef CHICKEN_H
#define CHICKEN_H
#include <iostream>
#include "bird.h"
using std::cout;
// Trida Chicken odvozena od Bird
class Chicken : public Bird
{
public:
 //konstruktory
 Chicken();
 Chicken(string name, int age, int weight, int wingspan);
 virtual ~Chicken(); //destruktor
 virtual void Speak() const { cout << "Pip pip, kokodak!\n"; }
 virtual void PrintName() const { cout << "Slepice se jmenuje: " << Chicken::GetName() << "\n"; }
 virtual void PrintAge() const { cout << "Slepici je: " << Chicken::GetAge() << " let.\n"; }
 virtual void PrintWeight() const { cout << "Slepice vazi: " << Chicken::GetWeight() << " kg.\n"; }
 virtual void PrintWingspan() const { cout << "Rozpeti kridel slepice je: " << Chicken::GetWingspan() << " m.\n"; }
 virtual void PrintAnimal() const { Chicken::PrintName(); Chicken::PrintAge(); Chicken::PrintWeight(); Chicken::Speak(); Chicken::PrintWingspan(); }
};
#endif // CAT_H

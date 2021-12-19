#ifndef MAMMAL_H
#define MAMMAL_H
#include <iostream>
#include "animal.h"
using std::cout;
// Trida Savec odvozena od Animal
class Mammal : public Animal
{
public:
 // konstruktory
 Mammal();
 Mammal(string name);
 Mammal(string name, int age, int weight);
 Mammal(string name, int age, int weight, int milkProduced);
 virtual ~Mammal(); //destruktor
 int GetMilkProduced() const { return mMilkProduced; }
 void SetMilkProduced(int milkProduced) { mMilkProduced = milkProduced; }
 virtual void Speak() const { cout << "Savci zvuk!\n"; }
 virtual void PrintName() const { cout << "Savec se jmenuje: " << Mammal::GetName() << "\n"; }
 virtual void PrintAge() const { cout << "Savci je: " << Mammal::GetAge() << " let.\n"; }
 virtual void PrintWeight() const { cout << "Savec vazi: " << Mammal::GetWeight() << " kg.\n"; }
 virtual void PrintMilkProduced() const { cout << "Savec vyprodukoval: " << Mammal::GetMilkProduced() << " litru mleka.\n"; }
 virtual void PrintAnimal() const { Mammal::PrintName(); Mammal::PrintAge(); Mammal::PrintWeight(); Mammal::Speak(); Mammal::PrintMilkProduced(); }
protected:
 int mMilkProduced; //vyprodukované mléko v litrech
};
#endif // MAMMAL_H

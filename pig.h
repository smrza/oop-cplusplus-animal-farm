#ifndef PIG_H
#define PIG_H
#include <iostream>
#include "mammal.h"
using std::cout;
// Trida Pig odvozena od Savec
class Pig : public Mammal
{
public:
 //konstruktory
 Pig();
 Pig(string name, int age, int weight, int milkProduced);
 virtual ~Pig(); //destruktor
 virtual void Speak() const { cout << "Oink oink!\n"; }
 virtual void PrintName() const { cout << "Prase se jmenuje: " << Pig::GetName() << "\n"; }
 virtual void PrintAge() const { cout << "Praseti je: " << Pig::GetAge() << " let.\n"; }
 virtual void PrintWeight() const { cout << "Prase vazi: " << Pig::GetWeight() << " kg.\n"; }
 virtual void PrintMilkProduced() const { cout << "Prasatko vyprodukovalo: " << Pig::GetMilkProduced() << " litru mleka pro technicke ucely.\n"; }
 virtual void PrintAnimal() const { Pig::PrintName(); Pig::PrintAge(); Pig::PrintWeight(); Pig::Speak(); Pig::PrintMilkProduced(); }
};
#endif // PIG_H

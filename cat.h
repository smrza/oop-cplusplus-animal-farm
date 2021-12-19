#ifndef CAT_H
#define CAT_H
#include <iostream>
#include "mammal.h"
using std::cout;
// Trida Cat odvozena od Savec
class Cat : public Mammal
{
public:
 //kontruktory
 Cat();
 Cat(string name, int age, int weight);
 virtual ~Cat(); //destruktor
 virtual void Speak() const { cout << "Mnau Mnau!\n"; }
 virtual void PrintName() const { cout << "Kocka se jmenuje: " << Cat::GetName() << "\n"; }
 virtual void PrintAge() const { cout << "Kocce je: " << Cat::GetAge() << " let.\n"; }
 virtual void PrintWeight() const { cout << "Kocka vazi: " << Cat::GetWeight() << " kg.\n"; }
 //virtual void PrintMilkProduced() const { cout << "Mleko od kocek nepijeme.\n"; } ... nevyužito
 virtual void PrintAnimal() const { Cat::PrintName(); Cat::PrintAge(); Cat::PrintWeight(); Cat::Speak(); }
};
#endif // CAT_H

#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include <string>
using std::cout;
using std::string;

// Trida Animal
class Animal
{
public:
 // konstruktory
 Animal();
 Animal(string name);
 Animal(string name, int age, int weight);
 virtual ~Animal(); //destruktor
 int GetAge() const { return mAge; }
 void SetAge(int age) { mAge = age; }
 string GetName() const { return mName; }
 void SetName(string name) { mName = name; }
 int GetWeight() const { return mWeight; }
 void SetWeight(int weight) { mWeight = weight; }
 virtual void Speak() const { cout << "Zvireci zvuk!\n"; }
 virtual void PrintAge() const { cout << "Zvireti je: " << Animal::GetAge() << " let.\n"; }
 virtual void PrintWeight() const { cout << "Zvire vazi: " << Animal::GetWeight() << " kg.\n"; }
 virtual void PrintName() const { cout << "Zvire se jmenuje: " << Animal::GetName() << "\n"; }
 //funkce pro vypsání celého zvířete verbose
 virtual void PrintAnimal() const { Animal::PrintName(); Animal::PrintAge(); Animal::PrintWeight(); Animal::Speak(); }
protected:
 string mName;
 int mAge;
 int mWeight;
};
#endif // MAMMAL_H

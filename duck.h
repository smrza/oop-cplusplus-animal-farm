#ifndef DUCK_H
#define DUCK_H
#include <iostream>
#include "bird.h"
using std::cout;
// Trida Duck odvozena od Bird
class Duck : public Bird
{
public:
 //konstruktory
 Duck();
 Duck(string name, int age, int weight, int wingspan);
 virtual ~Duck(); //destruktor
 virtual void Speak() const { cout << "Kvak, kvak!\n"; }
 virtual void PrintName() const { cout << "Kachna se jmenuje: " << Duck::GetName() << "\n"; }
 virtual void PrintAge() const { cout << "Kachne je: " << Duck::GetAge() << " let.\n"; }
 virtual void PrintWeight() const { cout << "Kachna vazi: " << Duck::GetWeight() << " kg.\n"; }
 virtual void PrintWingspan() const { cout << "Rozpeti kridel kachny je: " << Duck::GetWingspan() << " m.\n"; }
 virtual void PrintAnimal() const { Duck::PrintName(); Duck::PrintAge(); Duck::PrintWeight(); Duck::Speak(); }
};
#endif // DUCK_H

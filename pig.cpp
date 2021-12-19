#include <iostream>
#include "pig.h"
using std::cout;
Pig::Pig()
 : Mammal("Bezejmenne prase") //default prase
{
 cout << "Pig constructor called\n";
}
Pig::Pig(string name, int age, int weight, int milkProduced) //konstruktor pro zadani prasete z klavesnice
 : Mammal(name, age, weight, milkProduced)
{
 cout << "Pig(string, int, int, int) constructor called\n";
}
Pig::~Pig() //destruktor
{
 cout << "Pig destructor called\n";
}

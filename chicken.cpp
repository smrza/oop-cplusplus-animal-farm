#include <iostream>
#include "chicken.h"
using std::cout;
Chicken::Chicken()
 : Bird("Bezejmenna slepice") //default slepice
{
 cout << "Chicken constructor called\n";
}
Chicken::Chicken(string name, int age, int weight, int wingspan) //konstruktor pro zapsani slepice z klavesnice
 : Bird(name, age, weight, wingspan)
{
 cout << "Chicken(string, int, int, int) constructor called\n";
}
Chicken::~Chicken() //destruktor
{
 cout << "Chicken destructor called\n";
}

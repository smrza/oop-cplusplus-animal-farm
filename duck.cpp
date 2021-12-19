#include <iostream>
#include "duck.h"
using std::cout;
Duck::Duck() //default kachna
 : Bird("Bezejmenna kachna")
{
 cout << "Duck constructor called\n";
}
Duck::Duck(string name, int age, int weight, int wingspan) //konstruktor pro zapsani kachny z klavesnice
 : Bird(name, age, weight, wingspan)
{
 cout << "Duck(string, int, int, int) constructor called\n";
}
Duck::~Duck() //destruktor
{
 cout << "Duck destructor called\n";
}

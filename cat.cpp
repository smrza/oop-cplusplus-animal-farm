#include <iostream>
#include "cat.h"
using std::cout;
Cat::Cat() //default kocka
 : Mammal("Bezejmenna kocka")
{
 cout << "Cat constructor called\n";
}
Cat::Cat(string name, int age, int weight) //konstruktor pro kocku zapsanou z klavesnice
 : Mammal(name, age, weight)
{
 cout << "Cat(string, int, int) constructor called\n";
}
Cat::~Cat() //destruktor
{
 cout << "Cat destructor called\n";
}

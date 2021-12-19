#include <iostream>
#include "animal.h"
using std::cout;

Animal::Animal() //konstruktor pro vytvoení default zvířete bez jména a s výchozím věkem a váhou
 : mName("Bezejmenne zvire"), mAge(1), mWeight(1)
{
 cout << "Animal constructor called\n";
}
Animal::Animal(string name) //konstruktor, který používají potomci pro vytváření bezejmeného zvířete
 : mName(name), mAge(1), mWeight(1)
{
 cout << "Animal(string) constructor called\n";
}
Animal::Animal(string name, int age, int weight) //konstruktor používán při zadávání zvířete z klávesnice
 : mName(name), mAge(age), mWeight(weight)
{
 cout << "Animal(string, int, int) constructor called\n";
}
Animal::~Animal() //destruktor
{
 cout << "Animal destructor called\n";
}

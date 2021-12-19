#include <iostream>
#include "mammal.h"
using std::cout;

Mammal::Mammal() //default samec
 : Animal ("Bezejmenny savec"), mMilkProduced(0)
{
 cout << "Mammal constructor called\n";
}
Mammal::Mammal(string name) //konstruktor pro zapsani default potomku (bezejmennych)
 : Animal (name), mMilkProduced(0)
{
 cout << "Mammal(string) constructor called\n";
}
Mammal::Mammal(string name, int age, int weight) //konstruktor pro zapsani savce z klavesnice
 : Animal (name, age, weight), mMilkProduced(0)
{
 cout << "Mammal(string, int, int, int) constructor called\n";
}
Mammal::Mammal(string name, int age, int weight, int milkProduced) //konstruktor pro zapsani savce, ktery produkuje mleko, z klavesnice
 : Animal (name, age, weight), mMilkProduced(milkProduced)
{
 cout << "Mammal(string, int, int, int) constructor called\n";
}
Mammal::~Mammal() //destruktor
{
 cout << "Mammal destructor called\n";
}

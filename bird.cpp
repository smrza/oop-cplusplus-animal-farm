#include <iostream>
#include "bird.h"
using std::cout;

Bird::Bird() //default ptak bez zadani z klavesnice
 : Animal ("Bezejmenny ptak"), mWingspan(1)
{
 cout << "Bird constructor called\n";
}
Bird::Bird(string name) //konstruktor pro potomky diky nemuz se zapisuji bezejmenni default ptaci
 : Animal (name), mWingspan(1)
{
 cout << "Bird(string) constructor called\n";
}
Bird::Bird(string name, int age, int weight, int wingspan) //konstruktor pro zapsání ptáka z klávesnice
 : Animal (name, age, weight), mWingspan(wingspan)
{
 cout << "Bird(string, int, int, int) constructor called\n";
}
Bird::~Bird() //destruktor
{
 cout << "Bird destructor\n";
}

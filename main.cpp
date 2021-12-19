//vzhledem k tomu, že máme strukturu
// animal -> mammal -> dog, cat, pig
//        -> bird -> chicken, duck
// rozhodl jsem se pro potomky třídy animal, tedy bird a mammal, přidat unikátní member variables. Konkrétně wingspan (rozpětí křídel) pro ptáky
// a milkProduced (vyprodukované mléko) pro savce (i když lidé nevyužívají mléko psů a koček, případně prasat ... bohužel mě nenapadlo nic jiného pro savce)

#include <iostream>
#include <vector>
#include <memory>
#include "dog.h"
#include "cat.h"
#include "animal.h"
#include "bird.h"
#include "chicken.h"
#include "duck.h"
#include "pig.h"
#include "mammal.h"
#include <string>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::unique_ptr;
using std::string;

void printMenu(void); //tisk menu do konzole
char defaultOrManualAnimal(); //zjistuje a vraci volbu uzivatele, zda-li ma byt zvire zadano manualne nebo vytvoreno default
void enterAnimal(char defaultOrManual, vector<unique_ptr<Animal>> &animals); //samotna funkce pro zapsani zvirete

int main()
{
    vector<unique_ptr<Animal>> animals; //kontejner ukladajici zvirata
    vector<unique_ptr<Animal>>::iterator walker; //iterator pro vypsani zvirat

    cout << "Vitejte na sve farme zvirat.\n\n";
    char choice = '0'; //vyber funkcionality
    while(choice != '3')
    {
        printMenu();
        cin >> choice; //volba

        switch (choice) {
        case '1': //zapis zvirat
            enterAnimal(defaultOrManualAnimal(), animals);
            break;
        case '2': //vypis zvirat
            system("cls");
            // pouziti iteratoru
            walker = animals.begin();
            if(animals.size() == 0){
                cout << "Bohuzel nemate na farme zatim zadne zvirata. Zapiste je volbou v menu!\n";
                break;
            }
            cout << "Na vasi farme jsou: \n\n";
            while ( walker != animals.end() ) {
            (*walker)->PrintAnimal();
            cout << "\n";
            walker++; // posun na dalsi prvek
            }
            break;
        case '3': //konec
            printf("Preji prijemny den.\n\n");
            break;
        default:
            cout << "Neplatna volba. Prosim zkuste to znovu.\n";
            break;
        }
    }

    // Pamet je uvolnena automaticky, destruktory uspesne zavolany
    // v pripade potomka se volají od potomka smerem nahoru (napr pro psa se zavola prvni destruktor Dog, potom Mammal a nakonec Animal)
    return 0;
}

//vypsani menu
void printMenu(void){
    cout << "\n";
    cout << "Prejete si:\n";
    cout << "Pridat zvire (1)\n";
    cout << "Vypsat zvirata na farme (2)\n";
    cout << "Ukoncit program (3)\n";
    cout << "Vase volba: ";
}

//zjistuje a vraci volbu uzivatele, zda-li ma byt zvire zadano manualne nebo vytvoreno default
char defaultOrManualAnimal(){
    system("cls");
    cout << "Budete vypisovat udaje zvirete, nebo chcete vyuzit vychozi sablony? (1 = vypsat, 2 = default): ";

    char choice = '0'; //vyber funkcionality
    while(choice != '1' && choice != '2')
    {
        cin >> choice; //volba
        switch (choice) {
        case '1':
            break;
        case '2':
            break;
        default:
            cout << "Neplatna volba. Prosim zkuste to znovu:\n";
            break;
        }
    }
    system("cls");
    return choice;
}

//zapsani zvirete
void enterAnimal(char defaultOrManual, vector<unique_ptr<Animal>> &animals){ //char ... volba, vector ... kontejner zvirat
    cout << "Jake zvire chcete zapsat:\n";
    cout << "Zvire (1)\n";
    cout << "Savce (2)\n";
    cout << "Ptaka (3)\n";
    cout << "Psa (4)\n";
    cout << "Kocku (5)\n";
    cout << "Prase (6)\n";
    cout << "Slepici (7)\n";
    cout << "Kachnu (8)\n";
    cout << "Vase volba: ";

    char choice = '0'; //vyber funkcionality
    string name = ""; //pripadne jmeno pro zapsani
    int age = 0; //pripadny vek pro zapsani
    int weight = 0; //pripadna vaha pro zapsani
    int wingSpanOrMilkProduced = 0; //pripadne rozpeti kridel (pro ptaky a potomky) nebo produkovane mleko (pro savce a potomky) pro zapsani
    cin >> choice; //volba

    if(defaultOrManual == '1'){ //v pripade, ze uzivatel zapisuje udaje manualne, zjistime jmeno, vek a vahu
        cout << "Zadejte jmeno: ";
        cin >> name;
        cout << "Zadejte vek (roky): ";
        cin >> age;
        cout << "Zadejte vahu (v kg): ";
        cin >> weight;
    }

    //podle toho jake zvire zapisujeme se dale uzivatele zeptame na pripadne doplnujici informace
    switch (choice) {
    //pro demostrovani funkcionality programu zahrnuji moznost zapsani vsech trid (tedy i trid Animal, Mammal a Bird)
    case '1':
        if(defaultOrManual == '2') animals.push_back(unique_ptr<Animal>(new Animal)); //zvire je zapsano default pri volbe 2
        else {
            animals.push_back(unique_ptr<Animal>(new Animal(name, age, weight)));
            cout << "Zvire uspesne zapsano. Vracim se do menu.\n";
            system("pause");
            system("cls");
        }
        break;
    case '2':
        if(defaultOrManual == '2') animals.push_back(unique_ptr<Animal>(new Mammal));
        else {
            cout << "Zadejte kolik mleka (v litrech) vas savec vyprodukoval: ";
            cin >> wingSpanOrMilkProduced;
            animals.push_back(unique_ptr<Animal>(new Mammal(name, age, weight, wingSpanOrMilkProduced)));
            cout << "Savec uspesne zapsan. Vracim se do menu.\n";
            system("pause");
            system("cls");
        }
        break;
    case '3':
        if(defaultOrManual == '2') animals.push_back(unique_ptr<Animal>(new Bird));
        else {
            cout << "Zadejte rozpeti kridel (v metrech) vaseho ptaka: ";
            cin >> wingSpanOrMilkProduced;
            animals.push_back(unique_ptr<Animal>(new Bird(name, age, weight, wingSpanOrMilkProduced)));
            cout << "Ptak uspesne zapsan. Vracim se do menu.\n";
            system("pause");
            system("cls");
        }
        break;
    case '4':
        if(defaultOrManual == '2') animals.push_back(unique_ptr<Animal>(new Dog));
        else {
            //pro psa musime zjistit jeho plemeno
            char dogBreedChoice = '0';
            cout << "Zvolte plemeno:\n";
            cout << "Bulldog (1)\n";
            cout << "Terrier (2)\n";
            cout << "Doberman (3)\n";
            cout << "Malamut (4)\n";
            cin >> dogBreedChoice;

            if(dogBreedChoice == '1') animals.push_back(unique_ptr<Animal>(new Dog(name, age, weight, DOG_BULLDOG)));
            else if (dogBreedChoice == '2') animals.push_back(unique_ptr<Animal>(new Dog(name, age, weight, DOG_TERRIER)));
            else if (dogBreedChoice == '3') animals.push_back(unique_ptr<Animal>(new Dog(name, age, weight, DOG_DOBERMAN)));
            else if (dogBreedChoice == '4') animals.push_back(unique_ptr<Animal>(new Dog(name, age, weight, DOG_MALAMUTE)));
            else {
                cout << "Spatne zadane plemeno, vas pes je nyni Bulldog.\n";
                animals.push_back(unique_ptr<Animal>(new Dog(name, age, weight, DOG_BULLDOG)));
            }
            cout << "Pes uspesne zapsan. Vracim se do menu.\n";
            system("pause");
            system("cls");
        }
        break;
    case '5':
        if(defaultOrManual == '2') animals.push_back(unique_ptr<Animal>(new Cat));
        else {
            animals.push_back(unique_ptr<Animal>(new Cat(name, age, weight)));
            cout << "Kocka uspesne zapsana. Vracim se do menu.\n";
            system("pause");
            system("cls");
        }
        break;
    case '6':
        if(defaultOrManual == '2') animals.push_back(unique_ptr<Animal>(new Pig));
        else {
            cout << "Zadejte kolik mleka (v litrech) pro technicke ucely vase prase vyprodukovalo: ";
            cin >> wingSpanOrMilkProduced;
            animals.push_back(unique_ptr<Animal>(new Pig(name, age, weight, wingSpanOrMilkProduced)));
            cout << "Prase uspesne zapsano. Vracim se do menu.\n";
            system("pause");
            system("cls");
        }
        break;
    case '7':
        if(defaultOrManual == '2') animals.push_back(unique_ptr<Animal>(new Chicken));
        else {
            cout << "Zadejte rozpeti kridel (v metrech) vaseho kurete: ";
            cin >> wingSpanOrMilkProduced;
            animals.push_back(unique_ptr<Animal>(new Chicken(name, age, weight, wingSpanOrMilkProduced)));
            cout << "Slepice uspesne zapsana. Vracim se do menu.\n";
            system("pause");
            system("cls");
        }
        break;
    case '8':
        if(defaultOrManual == '2') animals.push_back(unique_ptr<Animal>(new Duck));
        else {
            cout << "Zadejte rozpeti kridel (v metrech) vasi kachny: ";
            cin >> wingSpanOrMilkProduced;
            animals.push_back(unique_ptr<Animal>(new Duck(name, age, weight, wingSpanOrMilkProduced)));
            cout << "Kachna uspesne zapsana. Vracim se do menu.\n";
            system("pause");
            system("cls");
        }
        break;
    default:
        cout << "Neplatna volba. Vracim se do menu.\n";
        system("pause");
        system("cls");
        break;
    }
}

#ifndef MYCPPDEF
#define MYCPPDEF

//Biblioteki:

#include <iostream>
#include <sstream>
#include <fstream>
#include <conio.h>
#include <Windows.h>
#include <ctime>
#include <stdlib.h>
#include <math.h>

//-----------------------------------------------

//Domyœlne przestrzenie nazw:

using namespace std;

//-----------------------------------------------

//Rozmiar tablicy:

#define newEmptyArray(Y,X,s); Y* X = new Y; tabs[l] = new tab; tabs[l]->size = s; tabs[l]->name = #X; l++;
#define macrobuff(X)  tabs[l] = new tab; tabs[l]->size = sizeof(X)/sizeof(X[0]);
#define newFullfilArray(Y,X,...); Y X[] = {__VA_ARGS__}; macrobuff(X) tabs[l]->name = #X; tabs[l]->an=tabs[l]->size; l++;
#define arraySize(X) dm->sizeOfArray(#X) /* MO¯E POWODOWAÆ B£ÊDY! NIE U¯YWAÆ NA PARAMETRZE FUNKCJI/KONSTRUKTORA/DESTRUKTORA, JE¯ELI
MA INN¥ NAZWÊ NI¯ ZMIENNA! Nale¿y u¿ywaæ nazwy zmiennej takiej jakiej u¿yliœmy w makrodefinicji newEmptyArray lub newFullfilArray
lub setArray. NIE U¯YWAÆ DLA FUNCJI, KTÓRA ZWRACA TABLICÊ.*/ 
#define awn(X) X,#X
#define setArray(Y,X); X = Y; tabs[l]->size = arraySize(Y); tabs[l]->name = #X; l++; /* MO¯E POWODOWAÆ B£ÊDY! NIE U¯YWAÆ NA PARAMETRZE
FUNKCJI/KONSTRUKTORA/DESTRUKTORA, JE¯ELI MA INN¥ NAZWÊ NI¯ ZMIENNA!
Nale¿y u¿ywaæ nazwy zmiennej takiej jakiej u¿yliœmy w makrodefinicji newEmptyArray lub newFullfilArray
lub setArray. NIE U¯YWAÆ DLA FUNCJI, KTÓRA ZWRACA TABLICÊ.*/
#define addToArray(Y,X); dm->arrayAdding(#Y,Y,X);

int l = 0;

//Y - rodzaj tablicy (int, double, string, itp.)
//X - nazwa zmiennej
//s - rozmiar tablicy
//... - wartoœci tablicy
//newEmptyArray(Y,X,s) - tworzy tablicê jako wskaŸnik (Y* X = new Y), o rozmiarze s
//newFullfilArray(Y,X,...) - tworzy tablicê i odrazu inicjuje j¹ wartoœciami, oblicza rozmiar tablicy (Y X[] = {...}
//arraySize(X) - zwraca wartoœæ tablicy X
//setArray(Y,X) - przypisuje wartoœæ tablicy do drugiej tablicy
//awn = Array with name
/* Ka¿da zmienna zdefiniowana za pomoc¹ newEmptyArray lub newFullfilArray lub setArray posiada globalne informacje na temat rozmiaru.
 NALE¯Y ZATEM U¯YWAÆ UNIKATOWYCH NAZW ZMIENNYCH! */
//-----------------------------------------------

//Wprowadzanie polskich znaków przez cin/getline
#define cinp(x); cin >> x; x = dm->plString(x);
#define cins(x); string x; cin >> x; x = dm->plString(x);
#define glinep(y,x); getline(y,x); x = dm->plString(x);
#define glines(y,x); string x; getline(y,x); x = dm->plString(x);
#define glinep(y,x,z); getline(y,x,z); x = dm->plString(x);
#define glines(y,x,z); string x; getline(y,x,z); x = dm->plString(x);

//x - nazwa zmiennej, do której wprowadzamy zawartoœæ
//y - strumieñ danych wejœciowych
//z - ogranicznik (wczytuj, dopóki nie nast¹pi), jeœli nie jest podany, getline wczyta tylko jedn¹ liniê
//cinp(x) - wprowadza ci¹g znaków do istniej¹cego stringa
//cins(x) - tworzy nowy string i wprowadza do niego ci¹g znaków
//glinep(y,x) - to samo co cinp(x), ale mo¿e wczytaæ ca³¹ liniê
//glines(y,x) - to samo co cins(x), ale mo¿e wczytaæ ca³¹ liniê
//glinep(y,x,z) - glinep(y,x) z ogranicznikiem
//glines(y,x,z) - glines(y,x) z ogranicznikiem
//-----------------------------------------------

#endif

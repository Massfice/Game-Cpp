#ifndef MYCPPDEF
#define MYCPPDEF

//Biblioteki:

#include <iostream>
#include <sstream>
#include <conio.h>

//-----------------------------------------------

//Domyœlne przestrzenie nazw:

using namespace std;

//-----------------------------------------------

//Rozmiar tablicy:

#define newEmptyArray(Y,X,s); Y* X = new Y; tabs[l] = new tab; tabs[l]->size = s; tabs[l]->name = #X; l++;
#define newFullfilArray(Y,X,...); Y X[] = {__VA_ARGS__}; tabs[l] = new tab; tabs[l]->size = sizeof(X)/sizeof(X[0]); tabs[l]->name = #X; tabs[l]->an=tabs[l]->size; l++;
#define arraySize(X) dm->sizeOfArray(#X) //MO¯E POWODOWAÆ B£ÊDY! NIE U¯YWAÆ NA PARAMETRZE FUNKCJI/KONSTRUKTORA/DESTRUKTORA!
#define awn(X) X,#X
#define setArray(Y,X); X = Y; tabs[l]->size = arraySize(Y); tabs[l]->name = #X; l++;
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

//-----------------------------------------------

#endif

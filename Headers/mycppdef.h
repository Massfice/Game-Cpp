#ifndef MYCPPDEF
#define MYCPPDEF

//Biblioteki:

#include <iostream>
#include <sstream>
#include <conio.h>

//-----------------------------------------------

//Domy�lne przestrzenie nazw:

using namespace std;

//-----------------------------------------------

//Rozmiar tablicy:

#define newEmptyArray(Y,X,s); Y* X = new Y; tabs[l] = new tab; tabs[l]->size = s; tabs[l]->name = #X; l++;
#define macrobuff(X)  tabs[l] = new tab; tabs[l]->size = sizeof(X)/sizeof(X[0]);
#define newFullfilArray(Y,X,...); Y X[] = {__VA_ARGS__}; macrobuff(X) tabs[l]->name = #X; tabs[l]->an=tabs[l]->size; l++;
#define arraySize(X) dm->sizeOfArray(#X) /* MO�E POWODOWA� B��DY! NIE U�YWA� NA PARAMETRZE FUNKCJI/KONSTRUKTORA/DESTRUKTORA, JE�ELI
MA INN� NAZW� NI� ZMIENNA! Nale�y u�ywa� nazwy zmiennej takiej jakiej u�yli�my w makrodefinicji newEmptyArray lub newFullfilArray
lub setArray */ 
#define awn(X) X,#X
#define setArray(Y,X); X = Y; tabs[l]->size = arraySize(Y); tabs[l]->name = #X; l++; /* MO�E POWODOWA� B��DY! NIE U�YWA� NA PARAMETRZE
FUNKCJI/KONSTRUKTORA/DESTRUKTORA, JE�ELI MA INN� NAZW� NI� ZMIENNA!
Nale�y u�ywa� nazwy zmiennej takiej jakiej u�yli�my w makrodefinicji newEmptyArray lub newFullfilArray
lub setArray */
#define addToArray(Y,X); dm->arrayAdding(#Y,Y,X);

int l = 0;

//Y - rodzaj tablicy (int, double, string, itp.)
//X - nazwa zmiennej
//s - rozmiar tablicy
//... - warto�ci tablicy
//newEmptyArray(Y,X,s) - tworzy tablic� jako wska�nik (Y* X = new Y), o rozmiarze s
//newFullfilArray(Y,X,...) - tworzy tablic� i odrazu inicjuje j� warto�ciami, oblicza rozmiar tablicy (Y X[] = {...}
//arraySize(X) - zwraca warto�� tablicy X
//setArray(Y,X) - przypisuje warto�� tablicy do drugiej tablicy
//awn = Array with name
/* Ka�da zmienna zdefiniowana za pomoc� newEmptyArray lub newFullfilArray lub setArray posiada globalne informacje na temat rozmiaru.
 NALE�Y ZATEM U�YWA� UNIKATOWYCH NAZW ZMIENNYCH! */
//-----------------------------------------------

#endif

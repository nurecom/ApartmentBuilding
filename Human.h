#pragma once
#define _CRT_SECURE_NO_WARNINGS // for strcpy !
#include <iostream>
#include <Windows.h> // for cin >> с русскими буквами
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include <conio.h> // for getch_! 
//#include <iomanip>

class Human
{
	int number;
	char* FIO;
	char* Phone;
	int NumberOfFlat;
public:
	Human();
	// Constructor with full parameters
	Human(int numberP, const char* fio, const char* Phone, int numberOfFlatP);
	// Copy Constructor
	Human(const Human& obj);
	// Search for a person
	void SearchHuman(Human* p, char const* charsearch, int const countHuman);
	// Adding a person
	void AddHuman(Human*& p, int* countHuman, int* _number);
	// Delete a person
	void DelHuman(Human*& p, int* countHuman, int* _number);
	// Destructor
	~Human();
	//Print
	void ShowHumans();
	int  Getnumber();
	char GetFIO();
	char GetPhone();
};
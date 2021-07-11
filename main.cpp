#include <iostream>
#include "House.h"
#include "Flat.h"
#include "Human.h"

void draw(int counter);

int	main() 
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);// #include <Windows.h>
	SetConsoleOutputCP(1251); // #include <Windows.h>
	std::cout << "\tВстреча №4 Тема: Указатель this. Побитовое копирование. Конструктор копирования"
		<< std::endl << std::endl;
	draw(80);
	// Maximum of flats
	int const MAXFLATS = 100;
	// Count of humans in the house
	int countHuman = 3;
	// Key of owner in the list of the tenant of the house
	int number = 1;
	// Number of menu
	int number_menu = 0;
	// Array of flats
	Flat* flat = new Flat [MAXFLATS];
	
	// Filling in the database
	Human* p = new Human[countHuman]
	{
		{number++," Nurimanov Ruslan Faritivich","+79177738764",83},
		{number++," Ivanov Ivan Ivanivich","+79324718273",23},
		{number++," Fedorov Ilya Maksimovich","+79324718271",34}
	};

	do {
		std::cout << "\tSelect an action\n";
		std::cout << "\t1: List of apartment owners" << std::endl;
		std::cout << "\t2: Adding an apartment owner" << std::endl;
		std::cout << "\t3: Deleting an apartment owner " << std::endl;
		std::cout << "\t4: Search for an apartment owner " << std::endl;
		std::cout << "\t5: Exiting the program" << std::endl;
		std::cout << "\t ==>";
		std::cin >> number_menu;
		switch (number_menu)
		{
		case 1:
			draw(80);
			std::cout << "\tCount of flats in DataBase : " << countHuman << " from TOTAL:" << MAXFLATS <<std::endl;
			for (int i = 0; i < countHuman; i++)
			{
				p[i].ShowHumans();
			}
			draw(80);
			_getch;
			break;
		case 2:
			p->AddHuman (p, &countHuman, &number);
			_getch;
			break;
		case 3:
			p->DelHuman(p, &countHuman, &number);
			_getch;
			break;
		case 4: {
			char charsearch[30] = "";
			std::cout << "\tInput phone of the owner of the apartment : ";
			std::cin.ignore();
			std::cin.getline(charsearch, 30);
			p->SearchHuman(p, charsearch, countHuman);
			_getch;
			break;
		}
		case 5:
			delete[]p;
			std::cout << "\tExit from program...." << std::endl;
			_getch;
			break;
		default:
			std::cout << "\tChoose correctly !!!" << std::endl;
		}
	} while (number_menu != 5);

	return 0;
};

void draw(int counter) {
	std::cout << "\t";
	for (int i = 0; i < counter; i++) {
		std::cout << "*";
	}
	std::cout << '\n';
}
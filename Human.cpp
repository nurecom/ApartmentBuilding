#include "Human.h"

Human::Human() 
{
	number = 0;
	FIO = new char[3]{ "No" };
	Phone = new char[3]{ "No" };
	NumberOfFlat = 0;
}

Human::Human(int numberP, const char* fioP, const char* phoneP, int numberOfFlatP)
{
	int count_fio, count_phone;
	count_fio = strlen (fioP);
	count_phone = strlen (phoneP);
	number = numberP;
	NumberOfFlat = numberOfFlatP;
	FIO = new char[count_fio + 1];
	Phone = new char[count_phone + 1];
	strcpy(FIO, fioP);
	strcpy(Phone, phoneP);
}

Human::Human(const Human& obj) : 
	number{ obj.number }, FIO{ new char[strlen(obj.FIO) + 1] }, Phone{ new char[strlen(obj.Phone) + 1] },
	NumberOfFlat {obj.NumberOfFlat} 
{
	strcpy(FIO, obj.FIO);
	strcpy(Phone, obj.Phone);
}
void Human::SearchHuman(Human* p, char const* charsearch, int const countHuman)
{
	int countsearch = 0;
	for (int i = 0; i < countHuman; i++)
	{
		char* temp = strstr(p[i].FIO, charsearch);
		if (temp)
		{
			countsearch++;
			if (countsearch == 1)
			{
				std::cout << "№ " << " | " << "Owner of the apartment" << std::endl;
			}
			std::cout << p[i].number << " . " << p[i].FIO << " . " << p[i].Phone << std::endl;
		}
	}
	if (countsearch < 1)
	{
		std::cout << "The owner of the apartment was not found" << std::endl;
	}
}
void Human::AddHuman (Human*& p, int* countHuman, int* _number)
{
	Human* temp = new Human[*countHuman + 1];
	char _fio, _phone;
	int _numberOfFlat;

	int numbertmp = *_number;
	for (int i = 0; i < *countHuman; i++)
	{
		temp[i].number = p[i].number;
		temp[i].NumberOfFlat = p[i].NumberOfFlat;
		_fio = strlen(p[i].FIO);
		_phone = strlen(p[i].Phone);
		temp[i].FIO = new char[_fio + 1];
		temp[i].Phone = new char[_phone + 1];
		strcpy(temp[i].FIO, p[i].FIO);
		strcpy(temp[i].Phone, p[i].Phone);
	}

	temp[*countHuman].number = numbertmp;

	char buff[80];
	std::cin.ignore();
	std::cout << "\tInput FIO of the owner of the apartment: ";
	std::cin.getline(buff, 80);
	_fio = strlen(buff);
	temp[*countHuman].FIO = new char[_fio + 1];

	strcpy(temp[*countHuman].FIO, buff);
	std::cout << std::endl;

	std::cout << "\tInput phone of the owner of the apartment : ";
	std::cin.getline(buff, 80);
	_phone = strlen(buff);
	temp[*countHuman].Phone = new char[_phone + 1];
	strcpy(temp[*countHuman].Phone, buff);
	std::cout << std::endl;

	std::cout << "\tInput number of flat of the owner of the apartment: ";
	std::cin.getline(buff, 80);
	_numberOfFlat = atoi(buff);
	temp[*countHuman].NumberOfFlat = _numberOfFlat;

	(*countHuman)++;
	(*_number)++;
	delete[] p;
	p = temp;
	std::cout << "\tChanges have been made...\n";
}
void Human::DelHuman(Human*& p, int* countHuman, int* _number)
{
	char _fio, _phone;
	int numbertmp = *_number;
	int p_count = 0;
	// Порядковый номер для удаления
	int delnumber;
	// Счетчик был ли удален абонент
	int countdel = 0;
	std::cout << "\tInput number for delete: ";
	std::cin >> delnumber;
	std::cin.ignore();
	for (int i = 0; i < *countHuman; i++)
	{
		if (p[i].number == delnumber)
		{
			(*countHuman)--;
			countdel++;
		}
	}
	Human* temp = new Human[*countHuman];
	for (size_t i = 0; i < *countHuman; i++)
	{
		if (p[p_count].number == delnumber)
		{
			p_count++;
			i--;
		}
		else if (p[p_count].number != delnumber)
		{ 
			temp[i].number = p[p_count].number;
			temp[i].NumberOfFlat = p[p_count].NumberOfFlat;
			_fio = strlen(p[p_count].FIO);
			_phone = strlen(p[p_count].Phone);
			temp[i].FIO = new char[_fio + 1];
			temp[i].Phone = new char[_phone + 1];
			strcpy(temp[i].FIO, p[p_count].FIO);
			strcpy(temp[i].Phone, p[p_count].Phone);
			p_count++;
		}
	}
	if (countdel)
	{
		std::cout << "\tChanges have been made... \n";
	}
	delete[]p;
	p = temp;
	if (!countdel)
	{
		std::cout << "\tThe owner of the apartment was not found \n";
	}
}
Human:: ~ Human()
{
	delete[] FIO;
	delete[] Phone;
}
void Human::ShowHumans()
{
	std::cout << number << " . ";
	std::cout << " FIO : " << FIO << "\tTelephone : " << Phone << "\tNumberOfFlat :" << NumberOfFlat;
	std::cout << std::endl;
}
int Human::Getnumber() { return number; }
char Human::GetFIO() { return *FIO; }
char Human::GetPhone() { return *Phone; }

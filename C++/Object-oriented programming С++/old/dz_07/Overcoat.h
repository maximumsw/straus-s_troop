#pragma once
#include <windows.h>
using namespace std;

void setConsoleColor(int color) {
	// Отримуємо дескриптор стандартного виходу
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	// Встановлюємо колір
	SetConsoleTextAttribute(hConsole, color);
}

class Overcoat
{
	static const int N = 40;  // Константа для розміру масивів
	char* name = new char[N];
	char* type = new char[N];
	float* price = new float;  // Одна змінна типу float
	
	

public:
	
	Overcoat() = default;
	Overcoat(const char* Name) // конструктор з переданим параметром "Ім'я"
	{
		setName(Name);
	}
	Overcoat(const char* Name, const char* Type, int num) // конструктор з переданими параметроми "Ім'я,Тип,Ціна"
	{
		setName(Name);
		setType(Type);
		setPrice(num);
	}

	bool cmpType(const Overcoat& other);
	
	bool operator==(const Overcoat& other) const {
		for (int i = 0; i < N; ++i) {
			// Якщо знаходимо різні символи, рядки не однакові
			if (type[i] != other.type[i]) {
				return false;
			}
			// Якщо обидва рядки завершуються (досягли '\0'), вони однакові
			if (type[i] == '\0' && other.type[i] == '\0') {
				break;
			}
		}
		return true;
	}

	int operator>(const Overcoat& other)
	{
		if (cmpType(other) == true)
		{
			if (*(this->price) > *(other.price))
			{
				cout << "більше" << endl;
				return 1; //True
			}
			else if (*(this->price) < *(other.price))
			{
				cout << "менше" << endl;
				return 0; //False
			}
			else
			{
				return -1;
			}
		}
		else
		{
			setConsoleColor(4);
			cout << "Error!!!" << endl;
			setConsoleColor(7);
			cout << "Types are not the same!";
			exit(true);
		} 
	}
	Overcoat& operator=(const Overcoat& other) 
	{
		if (this != &other) 
		{
			
			strcpy_s(type, N, other.type);
			type[sizeof(type) - 1] = '\0';
			price = other.price;
		}
	}



	



	void setName(const char* txt);
	void setType(const char* txt);
	void setPrice(int a);

	char* getName();
	char* getType();
	int getPrice();

	void showObject();



	
	~Overcoat();
};


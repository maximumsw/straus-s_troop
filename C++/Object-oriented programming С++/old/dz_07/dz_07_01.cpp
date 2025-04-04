#include <iostream>

#include "Overcoat.h"


void Overcoat::showObject()
{
    cout << "Name: " << getName() << endl << "Type: " << getType() << endl << "Price: " << getPrice() << endl;
}
void Overcoat::setName(const char* txt)
{
	strcpy_s(this->name, N, txt);
	type[sizeof(name) - 1] = '\0';
}
void Overcoat::setType(const char* txt)
{
	strcpy_s(this->type, N, txt);
	type[sizeof(type) - 1] = '\0';
}
void Overcoat::setPrice(int a)
{
	*price = a;
}

bool Overcoat::cmpType(const Overcoat& other)
{
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


char* Overcoat::getName()
{
	return this->name;
}
char* Overcoat::getType()
{
	return this->type;
}
int Overcoat::getPrice()
{
	return *price;
}





Overcoat::~Overcoat()
{
	delete[] name;
	delete[] type;
	delete price;

}

int main()
{
    
    Overcoat shirt1("Object1");
    shirt1.setType("Shirt1");
    shirt1.setPrice(10);
    shirt1.showObject();


	Overcoat shirt2("Object1");
	shirt2.setType("Shirt");
	shirt2.setPrice(10);
	shirt2.showObject();
	cout << (shirt1 == shirt2)<<endl;
	cout << (shirt1 > shirt2);
}
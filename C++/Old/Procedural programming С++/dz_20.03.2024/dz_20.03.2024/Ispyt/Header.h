#pragma once
#include <iostream>
#include <cstring> // for strcpy
using namespace std;

void gap() {
	cout << "\n====================\n";
}

struct Date {
	int year;
	int month;
	int day;
};

struct Product {
	char title[255];
	char maker[255];
	double price;
	char product_class[255];
	Date arrival_date_in_stock; // Date of arrival at the warehouse
	Date shelf_life; // Shelf life
};


// Add product to the warehouse
Product input() {
	Product aProduct; // Create a new object of the Product structure
	int day, month, year;
	cin.ignore();
	cout << "Enter title: ";
	cin.getline(aProduct.title, 255);
	cout << "Enter manufacturer: ";
	cin.getline(aProduct.maker, 255);
	cout << "Enter price: ";
	cin >> aProduct.price;
	cin.ignore();
	cout << "Enter product class: ";
	cin.getline(aProduct.product_class, 255);
	cout << "Enter dates of arrival at the warehouse (DD MM YYYY): ";
	cin >> day >> month >> year;
	aProduct.arrival_date_in_stock = { day, month, year };
	cout << "Enter expiration date: ";
	cin >> day >> month >> year;
	aProduct.shelf_life = { day, month, year };

	return aProduct;
}

//Menu
int Menu() {
	int choice;
	cout << "1)Add product to the warehouse\n"
		<< "2)Print all products\n"
		<< "3)Delete product from the warehouse\n"
		<< "4)Replace product\n"
		<< "5)Search product by name\n"
		<< "6)Search product by manufacturer\n"
		<< "7)Search product by price\n"
		<< "8)Search product by product group\n"
		<< "9)Search product by date of arrival at the warehouse\n"
		<< "10)Search product by expiration date\n"
		<< "11)Sort product by price\n"
		<< "12)Sort product by product group\n"
		<< "0)exit\n"
		<< "Choice what do you need: \n";
	cin >> choice;
	return choice;
}


// Display data from the warehouse
void Print(Product aProduct) {
	cout << "Title: " << aProduct.title << endl;
	cout << "Manufacturer: " << aProduct.maker << endl;
	cout << "Price: " << aProduct.price << endl;
	cout << "Product class: " << aProduct.product_class << endl;
	cout << "Date of arrival at the warehouse: " << aProduct.arrival_date_in_stock.day << "." <<
		aProduct.arrival_date_in_stock.month << "." << aProduct.arrival_date_in_stock.year << endl;
	cout << "Expiration date: " << aProduct.shelf_life.day << "." <<
		aProduct.shelf_life.month << "." << aProduct.shelf_life.year << endl;
}

// Remove product from the warehouse
void remove(Product aProduct[], int& size, int indexToDelete) {
	if (indexToDelete < 0 || indexToDelete >= size) {
		cout << "Invalid index\n";
		return;
	}
	// Shift the remaining elements to the left
	for (int i = indexToDelete; i < size - 1; ++i) {
		aProduct[i] = aProduct[i + 1];
	}

	// Reduce the size of the array
	size--;
}


Product* change(Product*& array, int& size, Product newElement) {
	// Create a new array with one more element
	Product* newArray = new Product[size + 1];

	// Copy existing elements to the new array
	for (int i = 0; i < size; ++i) {
		newArray[i] = array[i];
	}

	// Add a new element
	newArray[size] = newElement;

	// Delete the old array

	delete[] array;

	// Increase size
	++size;

	return newArray;
}

// Search by Name
void searchOfTitle(Product aProduct[], int size, const char* whichTitle) {
	bool found = false;
	for (int i = 0; i < size; ++i) {
		if (strcmp(aProduct[i].title, whichTitle) == 0) {
			Print(aProduct[i]);
			found = true;
		}
	}
	if (!found) {
		cout << "Product by title not found: " << whichTitle << endl;
	}
}

//Search by maker
void searchOfMaker(Product aProduct[], int size, const char* whichMaker) {
	bool found = false;
	for (int i = 0; i < size; ++i) {
		if (strcmp(aProduct[i].maker, whichMaker) == 0) {
			Print(aProduct[i]);
			found = true;
		}
	}
	if (!found) {
		cout << "Product by manufacturer not found: " << whichMaker << endl;
	}
}

//Search by Price
void searchOfPrice(Product aProduct[], int size, int whichPrice) {
	bool found = false;
	for (int i = 0; i < size; ++i) {
		if (aProduct[i].price == whichPrice) {
			Print(aProduct[i]);
			found = true;
		}
	}
	if (!found) {
		cout << "Product by price not found: " << whichPrice << endl;
	}
}

//Search by Group
void searchOfProductClass(Product aProduct[], int size, const char* whichProductClass) {
	bool found = false;
	for (int i = 0; i < size; ++i) {
		if (strcmp(aProduct[i].product_class, whichProductClass) == 0) {
			Print(aProduct[i]);
			found = true;
		}
	}
	if (!found) {
		cout << "Product by group not found: " << whichProductClass << endl;
	}
}

// Search by Date(added)
void searchOfdate(Product aProduct[], int size, int whichDay, int whichMonth, int whichYear) {
	bool found = false;
	for (int i = 0; i < size; ++i) {
		if (aProduct[i].arrival_date_in_stock.day == whichDay) {
			if (aProduct[i].arrival_date_in_stock.month == whichMonth) {
				if (aProduct[i].arrival_date_in_stock.year == whichYear) {
					Print(aProduct[i]);
					found = true;
				}
			}
		}
	}
	if (!found) {
		cout << "Product by date not found: " << whichDay << "." << whichMonth << "." << whichYear << endl;
	}
}

//Sort by price
Product* sortingOfPrice(Product aProduct[], int ROWS) {
	bool swapped;
	for (int i = 0; i < ROWS - 1; i++) {
		swapped = false;
		for (int j = 0; j < ROWS - i - 1; j++) {
			if (aProduct[j].price > aProduct[j + 1].price) {
				// Swap elements
				Product temp = aProduct[j];
				aProduct[j] = aProduct[j + 1];
				aProduct[j + 1] = temp;
				swapped = true;
			}
		}
		if (!swapped)
			break;
	}
	return aProduct;
}

//Sort by group
Product* sortingOfproduct_class(Product* aProduct, int ROWS) {
	bool swapped;
	for (int i = 0; i < ROWS - 1; i++) {
		swapped = false;
		for (int j = 0; j < ROWS - i - 1; j++) {
			if (strcmp(aProduct[j].product_class, aProduct[j + 1].product_class) > 0) {
				Product temp = aProduct[j];

				aProduct[j] = aProduct[j + 1];
				aProduct[j + 1] = temp;
				swapped = true;
			}
		}
		if (!swapped)
			break;
	}
	return aProduct;
}

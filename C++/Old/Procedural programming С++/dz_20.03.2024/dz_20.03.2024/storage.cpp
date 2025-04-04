#include <iostream>
#include "Header.h" // Include the "Header.h" header file to use custom functions and classes
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru"); // Set locale to Russian for proper input/output
	// int N = 255; 
	int choice; // Declare 'choice' variable to store user's choice
	int howManyitems = 0; // Initialize 'howManyitems' variable to track the number of items, starting at 0
	bool isTrue = true; // Initialize 'isTrue' variable to control error message display logic

	// Loop continues until the user enters a non-zero number of items
	while (howManyitems == 0) {
		if (!isTrue) {
			cout << "ERROR, try again" << endl; // Display error message if 'isTrue' is false
			isTrue = true;
		}
		cout << "================================\n";
		cout << "Enter the number of items (no symbols !!!): ";
		cin >> howManyitems;
		isTrue = false;
	}
	Product* storage = new Product[howManyitems]; // Create a dynamic array of 'Product' objects
	cout << "\n================================\n";
	for (int i = 0; i < howManyitems; i++) {
		storage[i] = input(); // Get input for each item and store it in the array
		cout << "================================\n";
	}
	while (true)
	{
		cout << "\n================================\n";
		choice = Menu(); // Display the menu and get user's choice
		cout << "\n================================\n";

		switch (choice) {
		case 0:
			delete[] storage; // Free memory before exiting
			return 0; // Correct program termination

		case 1: {
			Product newElement = input(); // Get input for a new product
			storage = change(storage, howManyitems, newElement);// Add the new product to the array
			break;
		}
		case 2:
			for (int i = 0; i < howManyitems; i++) {
				gap();
				cout << "Item: " << i << endl;
				Print(storage[i]);// Print information about the item
				gap();
			}
			break;
		case 3: {
			int whichItemDelete;
			cout << "Enter the item you want to delete: ";
			cin >> whichItemDelete;
			if (whichItemDelete >= 0 && whichItemDelete < howManyitems) {
				remove(storage, howManyitems, whichItemDelete);// Remove the item if the index is correct
			}
			else {
				cout << "Invalid index\n";
			}
			break;
		}
		case 4: {
			int whichItemChange;
			cout << "Enter the item you want to change: ";
			cin >> whichItemChange;
			if (whichItemChange >= 0 && whichItemChange < howManyitems) {
				Product newElement = input();
				storage = change(storage, howManyitems, newElement);// Replace the item with a new one
			}
			else {
				cout << "Invalid index\n";
			}
			break;
		}

		case 5:
			char whichTitle[255];
			cout << "Enter the product name: ";
			cin.ignore();
			cin.getline(whichTitle, 255);
			gap();
			searchOfTitle(storage, howManyitems, whichTitle);// Search for the product by name
			gap();
			break;
		case 6:
			char whichMaker[255];
			cout << "Enter the product manufacturer: ";

			cin.ignore();
			cin.getline(whichMaker, 255);
			gap();
			searchOfMaker(storage, howManyitems, whichMaker);// Search for the product by manufacturer
			gap();
			break;
		case 7:
			int whichPrice;
			cout << "Enter the product price: ";
			cin >> whichPrice;
			gap();
			searchOfPrice(storage, howManyitems, whichPrice);// Search for the product by price
			gap();
			break;
		case 8:
			char whichProductClass[255];
			cout << "Enter the product category: ";
			cin.ignore();
			cin.getline(whichProductClass, 255);
			gap();
			searchOfProductClass(storage, howManyitems, whichProductClass);// Search for the product by category
			gap();
			break;
		case 9: {
			int whichDay1, whichMonth1, whichYear1;
			cout << "Enter the date of arrival (DD MM YYYY): ";
			cin >> whichDay1 >> whichMonth1 >> whichYear1;
			searchOfdate(storage, howManyitems, whichDay1, whichMonth1, whichYear1);// Search for the product by arrival date
			break;
		}
		case 10: {
			int whichDay2, whichMonth2, whichYear2;
			cout << "Enter the expiration date (DD MM YYYY): ";
			cin >> whichDay2 >> whichMonth2 >> whichYear2;
			searchOfdate(storage, howManyitems, whichDay2, whichMonth2, whichYear2);// Search for the product by expiration date
			break;
		}

		case 11:
			storage = sortingOfPrice(storage, howManyitems);// Sort items by price
			break;
		case 12:
			storage = sortingOfproduct_class(storage, howManyitems);// Sort items by category
			break;


		}
	}
}

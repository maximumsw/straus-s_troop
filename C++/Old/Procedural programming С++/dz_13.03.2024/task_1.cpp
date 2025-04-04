#include <iostream>
#include <cstring> // for strcpy
using namespace std;

struct book {
    char title[255];
    char author[255];
    char publisher[255];
    char genre[255];
};


book input() {
    book skripture;
    cin.ignore(); 
    cout << "Input title: ";
    cin.getline(skripture.title, 255);
    cout << "Input author: ";
    cin.getline(skripture.author, 255);
    cout << "Input publisher: ";
    cin.getline(skripture.publisher, 255);
    cout << "Input genre: ";
    cin.getline(skripture.genre, 255);

    return skripture;
}

void print(book skripture) {
    cout << "Title: " << skripture.title << endl;
    cout << "Author: " << skripture.author << endl;
    cout << "Publisher: " << skripture.publisher << endl;
    cout << "Genre: " << skripture.genre << endl;
}


void searchOfAuthor(book skripture[], int size, const char* whichAuthor) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (strcmp(skripture[i].author, whichAuthor) == 0) {
            print(skripture[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "No books found for author: " << whichAuthor << endl;
    }
}

void searchOfTitle(book skripture[], int size, const char* whichTitle) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (strcmp(skripture[i].title, whichTitle) == 0) {
            print(skripture[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "No books found for author: " << whichTitle << endl;
    }
}


void sortingOfTitle(book array[], int ROWS) {
    for (int i = 0; i < ROWS - 1; i++) {
        for (int j = 0; j < ROWS - i - 1; j++) {
            if (strcmp(array[j].title, array[j + 1].title) > 0) {
                book temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
void sortingOfAuthor(book array[], int ROWS) {
    for (int i = 0; i < ROWS - 1; i++) {
        for (int j = 0; j < ROWS - i - 1; j++) {
            if (strcmp(array[j].author, array[j + 1].author) > 0) {
                book temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void sortingOfPublisher(book array[], int ROWS) {
    for (int i = 0; i < ROWS - 1; i++) {
        for (int j = 0; j < ROWS - i - 1; j++) {
            if (strcmp(array[j].publisher, array[j + 1].publisher) > 0) {
                book temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
int main() {
    setlocale(LC_ALL, "ru"); 
    const int N = 255;
    int choice;
    int howManyBooks = 0;
    bool isTrue = true;

    while (howManyBooks <= 0 || howManyBooks > 10) {
        if (!isTrue) {
            cout << "ERROR, try again" << endl;
        }
        cout << "How many books in library (max 10 books): ";
        cin >> howManyBooks;
        isTrue = false;
    }

    book* arr_of_books = new book[howManyBooks];

    while (true) {
        cout << "1)Редактировать книгу\n"
            << "2)Печать всех книг\n"
            << "3)Поиск книги по автору\n"
            << "4)Поиск книги под названием\n"
            << "5)Сортировка массива под названием книг\n"
            << "6)Сортировка массива по автору\n"
            << "7)Сортировка массива по издательству\n"
            << "0)exit\n"
            << "Choice what do you need: \n";
        cin >> choice;

        switch (choice) {
        case 0:
            exit(0);
        case 1:
            for (int i = 0; i < howManyBooks; i++) {
                arr_of_books[i] = input();
            }
            break;
        case 2:
            for (int i = 0; i < howManyBooks; i++) {
                print(arr_of_books[i]);
            }
            break;
        case 3:
            char whichAuthor[255];
            cout << "write which author are you interested: ";
            cin.ignore();
            cin.getline(whichAuthor, 255);
            searchOfAuthor(arr_of_books, howManyBooks, whichAuthor);
            break;
        case 4:
            char whichTitle[255];
            cout << "write which title are you interested: ";
            cin.ignore();
            cin.getline(whichTitle, 255);
            searchOfTitle(arr_of_books, howManyBooks, whichTitle);
            break;
        case 5:
            sortingOfTitle(arr_of_books, howManyBooks);
            cout << "Array is sorted by title." << endl;
            break;
        case 6:
            sortingOfAuthor(arr_of_books, howManyBooks);
            cout << "Array is sorted by title." << endl;
            break;
        case 7:
            sortingOfTitle(arr_of_books, howManyBooks);
            cout << "Array is sorted by title." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }
    }

    delete[] arr_of_books; 
    return 0;
}

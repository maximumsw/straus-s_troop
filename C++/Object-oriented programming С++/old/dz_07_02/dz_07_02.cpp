#include <iostream>
#include <cstring>  // Для роботи з функціями рядків

using namespace std;

class Flat {
private:
    static const int N = 40;  // Константа для розміру масивів
    char* address = new char[N];  // Масив для адреси квартири
    float* area = new float;  // Площа квартири
    float* price = new float;  // Ціна квартири

public:
    Flat() = default;

    Flat(const char* Address, float Area, float Price) {
        setAddress(Address);
        setArea(Area);
        setPrice(Price);
    }

    void setAddress(const char* txt) {
        strcpy_s(address, N, txt);
    }

    void setArea(float a) {
        *area = a;
    }

    void setPrice(float p) {
        *price = p;
    }

    char* getAddress() const {
        return address;
    }

    float getArea() const {
        return *area;
    }

    float getPrice() const {
        return *price;
    }

    void showFlat() const {
        cout << "Address: " << getAddress() << "\nArea: " << getArea() << " sq.m\nPrice: " << getPrice() << " USD" << endl;
    }

    // Перевантаження оператора рівності для порівняння площ
    bool operator==(const Flat& other) const {
        return getArea() == other.getArea();
    }

    // Перевантаження оператора присвоєння
    Flat& operator=(const Flat& other) {
        if (this != &other) {
            strcpy_s(address, N, other.address);
            *area = other.getArea();
            *price = other.getPrice();
        }
        return *this;
    }

    // Перевантаження оператора порівняння за ціною
    bool operator>(const Flat& other) const {
        return getPrice() > other.getPrice();
    }

    ~Flat() {
        delete[] address;
        delete area;
        delete price;
    }
};

int main() {
    Flat flat1("123 Elm Street", 55.5, 120000);
    Flat flat2("456 Oak Avenue", 60.0, 135000);

    flat1.showFlat();
    flat2.showFlat();

    if (flat1 == flat2) {
        cout << "Flats have the same area." << endl;
    }
    else {
        cout << "Flats have different areas." << endl;
    }

    if (flat1 > flat2) {
        cout << "Flat1 is more expensive than Flat2." << endl;
    }
    else {
        cout << "Flat1 is cheaper than Flat2." << endl;
    }

    Flat flat3;
    flat3 = flat1;
    flat3.showFlat();

    return 0;
}

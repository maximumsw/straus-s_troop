#include <iostream>
#include <string>
using namespace std;

class Pet {
protected:
    string name;
    string characteristics;

public:
    Pet(const string& name, const string& characteristics)
        : name(name), characteristics(characteristics) {}

    virtual void showInfo() const {
        cout << "Name: " << name << ", Characteristics: " << characteristics << endl;
    }

    virtual ~Pet() {}
};

class Dog : public Pet {
public:
    Dog(const string& name, const string& characteristics)
        : Pet(name, characteristics) {}

    void showInfo() const override {
        cout << "Dog - ";
        Pet::showInfo();
    }
};

class Cat : public Pet {
public:
    Cat(const string& name, const string& characteristics)
        : Pet(name, characteristics) {}

    void showInfo() const override {
        cout << "Cat - ";
        Pet::showInfo();
    }
};

class Parrot : public Pet {
public:
    Parrot(const string& name, const string& characteristics)
        : Pet(name, characteristics) {}

    void showInfo() const override {
        cout << "Parrot - ";
        Pet::showInfo();
    }
};

int main() {
    Dog dog("Rex", "Friendly and loyal");
    Cat cat("Whiskers", "Quiet and playful");
    Parrot parrot("Polly", "Talkative and colorful");

    dog.showInfo();
    cat.showInfo();
    parrot.showInfo();

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

// Базовий клас "Домашня тварина"
class Pet {
protected:
    string name;
    string characteristics;

public:
    Pet(const string& name, const string& characteristics)
        : name(name), characteristics(characteristics) {}

    virtual void Sound() const = 0; // Віртуальна функція для звуку
    virtual void Show() const {
        cout << "Name: " << name << endl;
    }
    virtual void Type() const = 0; // Віртуальна функція для типу тварини

    virtual ~Pet() {}
};

// Клас "Собака"
class Dog : public Pet {
public:
    Dog(const string& name, const string& characteristics)
        : Pet(name, characteristics) {}

    void Sound() const override {
        cout << name << " says: Woof!" << endl;
    }

    void Type() const override {
        cout << name << " is a Dog." << endl;
    }
};

// Клас "Кішка"
class Cat : public Pet {
public:
    Cat(const string& name, const string& characteristics)
        : Pet(name, characteristics) {}

    void Sound() const override {
        cout << name << " says: Meow!" << endl;
    }

    void Type() const override {
        cout << name << " is a Cat." << endl;
    }
};

// Клас "Папуга"
class Parrot : public Pet {
public:
    Parrot(const string& name, const string& characteristics)
        : Pet(name, characteristics) {}

    void Sound() const override {
        cout << name << " says: Squawk!" << endl;
    }

    void Type() const override {
        cout << name << " is a Parrot." << endl;
    }
};

// Клас "Хом’як"
class Hamster : public Pet {
public:
    Hamster(const string& name, const string& characteristics)
        : Pet(name, characteristics) {}

    void Sound() const override {
        cout << name << " says: Squeak!" << endl;
    }

    void Type() const override {
        cout << name << " is a Hamster." << endl;
    }
};

int main() {
    Pet* dog = new Dog("Rex", "Friendly and loyal");
    Pet* cat = new Cat("Whiskers", "Quiet and playful");
    Pet* parrot = new Parrot("Polly", "Talkative and colorful");
    Pet* hamster = new Hamster("Hammy", "Small and cute");

    dog->Show();
    dog->Sound();
    dog->Type();

    cat->Show();
    cat->Sound();
    cat->Type();

    parrot->Show();
    parrot->Sound();
    parrot->Type();

    hamster->Show();
    hamster->Sound();
    hamster->Type();

    delete dog;
    delete cat;
    delete parrot;
    delete hamster;

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

// Базовий клас "Список"
class List {
public:
    virtual void insert(int value) = 0;  // Віртуальна функція для вставлення
    virtual int remove() = 0;           // Віртуальна функція для видалення
    virtual void display() const = 0;   // Віртуальна функція для відображення списку
    virtual ~List() {}
};

// Похідний клас "Стек"
class Stack : public List {
private:
    vector<int> data;

public:
    void insert(int value) override {
        data.push_back(value);
    }

    int remove() override {
        if (data.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        int value = data.back();
        data.pop_back();
        return value;
    }

    void display() const override {
        cout << "Stack: ";
        for (auto it = data.rbegin(); it != data.rend(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }
};

// Похідний клас "Черга"
class Queue : public List {
private:
    vector<int> data;

public:
    void insert(int value) override {
        data.push_back(value);
    }

    int remove() override {
        if (data.empty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        int value = data.front();
        data.erase(data.begin());
        return value;
    }

    void display() const override {
        cout << "Queue: ";
        for (const int& val : data) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    List* stack = new Stack();
    List* queue = new Queue();

    stack->insert(10);
    stack->insert(20);
    stack->insert(30);
    stack->display();
    cout << "Removed from stack: " << stack->remove() << endl;
    stack->display();

    queue->insert(1);
    queue->insert(2);
    queue->insert(3);
    queue->display();
    cout << "Removed from queue: " << queue->remove() << endl;
    queue->display();

    delete stack;
    delete queue;

    return 0;
}

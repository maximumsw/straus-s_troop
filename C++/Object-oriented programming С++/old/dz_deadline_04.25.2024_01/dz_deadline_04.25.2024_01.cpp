#include <iostream>
#include <stdexcept>  // Для генерації виключень

using namespace std;

class CharStack {
private:
    int maxSize;  // Максимальний розмір стеку
    int top;      // Індекс верхнього елемента
    char* stackArray;  // Масив для зберігання символів

public:
    // Конструктор
    CharStack(int size) : maxSize(size), top(-1) {
        stackArray = new char[maxSize];
    }

    

    // Додавання символу в стек
    void push(char c) {
        if (isFull()) {
            throw overflow_error("Stack overflow: unable to push, the stack is full.");
        }
        stackArray[++top] = c;
    }

    // Видалення символу зі стеку
    char pop() {
        if (isEmpty()) {
            throw underflow_error("Stack underflow: unable to pop, the stack is empty.");
        }
        return stackArray[top--];
    }

    // Отримання верхнього символу без видалення
    char peek() const {
        if (isEmpty()) {
            throw underflow_error("Stack underflow: unable to peek, the stack is empty.");
        }
        return stackArray[top];
    }

    // Підрахунок кількості символів в стеці
    int count() const {
        return top + 1;
    }

    // Перевірка, чи стек порожній
    bool isEmpty() const {
        return top == -1;
    }

    // Перевірка, чи стек повний
    bool isFull() const {
        return top == maxSize - 1;
    }

    // Очищення стеку
    void clear() {
        top = -1;
    }

    
    ~CharStack() {
        delete[] stackArray;
    }
};

int main() {
    CharStack stack(5);

    stack.push('A');
    stack.push('B');
    stack.push('C');
    cout << "Count after pushing 3 elements: " << stack.count() << endl;

    cout << "Peek: " << stack.peek() << endl;

    cout << "Pop: " << stack.pop() << endl;
    cout << "Count after popping 1 element: " << stack.count() << endl;

    stack.clear();
    cout << "Count after clearing the stack: " << stack.count() << endl;

    return 0;
}

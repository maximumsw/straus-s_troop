#include <iostream>
#include <stdexcept>  // Для генерації виключень

using namespace std;

class CharStack {
private:
    int maxSize;  // Поточний розмір стеку (максимальна кількість елементів)
    int top;      // Індекс верхнього елемента
    char* stackArray;  // Масив для зберігання символів

    // Допоміжний метод для збільшення розміру масиву
    void resize(int newSize) {
        char* newArray = new char[newSize];
        for (int i = 0; i < maxSize; ++i) {
            newArray[i] = stackArray[i];
        }
        delete[] stackArray;
        stackArray = newArray;
        maxSize = newSize;
    }

public:
    // Конструктор
    CharStack(int size = 10) : maxSize(size), top(-1) {
        stackArray = new char[maxSize];
    }

    // Деструктор
    ~CharStack() {
        delete[] stackArray;
    }

    // Додавання символу в стек
    void push(char c) {
        if (isFull()) {
            resize(maxSize * 2);  // Збільшуємо розмір масиву вдвічі
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
};

int main() {
    CharStack stack(5);

    stack.push('A');
    stack.push('B');
    stack.push('C');
    stack.push('D');
    stack.push('E');
    stack.push('F');  // Цей виклик змусить стек розширитися

    cout << "Count after pushing 6 elements: " << stack.count() << endl;

    while (!stack.isEmpty()) {
        cout << "Pop: " << stack.pop() << endl;
    }

    return 0;
}

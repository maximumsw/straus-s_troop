#include <iostream>
#include <stdexcept>  // Для генерації виключень

using namespace std;

template<typename T>
class Queue {
private:
    int front;     // Індекс переднього елемента черги
    int rear;      // Індекс заднього елемента черги
    int maxSize;   // Максимальний розмір черги
    int itemCount; // Кількість елементів у черзі
    T* queueArray; // Масив для зберігання елементів черги

public:
    // Конструктор
    Queue(int size) : maxSize(size), front(0), rear(-1), itemCount(0) {
        queueArray = new T[maxSize];
    }

    // Деструктор
    ~Queue() {
        delete[] queueArray;
    }

    // Перевірка черги на порожнечу
    bool IsEmpty() const {
        return itemCount == 0;
    }

    // Перевірка черги на заповнення
    bool IsFull() const {
        return itemCount == maxSize;
    }

    // Додавання елемента в чергу
    void Enqueue(T value) {
        if (IsFull()) {
            throw overflow_error("Queue overflow: unable to enqueue, the queue is full.");
        }

        if (rear == maxSize - 1) {
            rear = -1; // Кільцева структура
        }

        queueArray[++rear] = value;
        itemCount++;
    }

    // Видалення елемента з черги
    T Dequeue() {
        if (IsEmpty()) {
            throw underflow_error("Queue underflow: unable to dequeue, the queue is empty.");
        }

        T value = queueArray[front++];

        if (front == maxSize) {
            front = 0; // Кільцева структура
        }

        itemCount--;
        return value;
    }

    // Відображення всіх елементів черги на екран
    void Show() const {
        if (IsEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        int count = itemCount;
        int index = front;

        while (count > 0) {
            cout << queueArray[index] << " ";
            index = (index + 1) % maxSize;
            count--;
        }
        cout << endl;
    }
};

int main() {
    Queue<int> queue(5);

    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);
    queue.Enqueue(4);
    queue.Enqueue(5);

    cout << "Queue contents after enqueuing 5 elements: ";
    queue.Show();

    cout << "Dequeued element: " << queue.Dequeue() << endl;

    cout << "Queue contents after dequeueing 1 element: ";
    queue.Show();

    queue.Enqueue(6);
    cout << "Queue contents after enqueuing 1 more element: ";
    queue.Show();

    return 0;
}

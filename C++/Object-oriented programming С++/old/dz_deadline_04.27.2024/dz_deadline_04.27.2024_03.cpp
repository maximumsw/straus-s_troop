#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

template<typename T>
class PriorityQueue {
private:
    struct Element {
        T value;
        int priority;
    };

    vector<Element> queue;

    // Пошук індексу елемента з найвищим пріоритетом
    int findHighestPriorityIndex() const {
        if (IsEmpty()) {
            throw runtime_error("Queue is empty, cannot find highest priority element.");
        }

        int highestPriorityIndex = 0;
        for (int i = 1; i < queue.size(); ++i) {
            if (queue[i].priority > queue[highestPriorityIndex].priority) {
                highestPriorityIndex = i;
            }
        }
        return highestPriorityIndex;
    }

public:
    // Перевірка черги на порожнечу
    bool IsEmpty() const {
        return queue.empty();
    }

    // Перевірка черги на заповнення (для даної реалізації черга ніколи не заповнена)
    bool IsFull() const {
        return false; // Вектор динамічно розширюється, тому черга не має фіксованого розміру
    }

    // Додавання елемента з пріоритетом в чергу
    void InsertWithPriority(const T& value, int priority) {
        queue.push_back({ value, priority });
    }

    // Видалення елемента з найвищим пріоритетом
    T PullHighestPriorityElement() {
        int highestPriorityIndex = findHighestPriorityIndex();
        T value = queue[highestPriorityIndex].value;
        queue.erase(queue.begin() + highestPriorityIndex);
        return value;
    }

    // Повернення найбільшого за пріоритетом елемента (без видалення)
    T Peek() const {
        int highestPriorityIndex = findHighestPriorityIndex();
        return queue[highestPriorityIndex].value;
    }

    // Виведення всіх елементів черги на екран
    void Show() const {
        if (IsEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue contents: " << endl;
        for (const auto& elem : queue) {
            cout << "Value: " << elem.value << ", Priority: " << elem.priority << endl;
        }
    }
};

int main() {
    // Приклад з цілими числами
    PriorityQueue<int> intQueue;
    intQueue.InsertWithPriority(10, 1);
    intQueue.InsertWithPriority(20, 2);
    intQueue.InsertWithPriority(30, 3);
    intQueue.InsertWithPriority(40, 1);

    cout << "Integer queue after insertions:" << endl;
    intQueue.Show();

    cout << "Peek highest priority element: " << intQueue.Peek() << endl;

    cout << "Pull highest priority element: " << intQueue.PullHighestPriorityElement() << endl;

    cout << "Integer queue after pulling highest priority element:" << endl;
    intQueue.Show();

    // Приклад з рядками
    PriorityQueue<string> stringQueue;
    stringQueue.InsertWithPriority("Low priority", 1);
    stringQueue.InsertWithPriority("Medium priority", 2);
    stringQueue.InsertWithPriority("High priority", 3);

    cout << "\nString queue after insertions:" << endl;
    stringQueue.Show();

    cout << "Peek highest priority element: " << stringQueue.Peek() << endl;

    cout << "Pull highest priority element: " << stringQueue.PullHighestPriorityElement() << endl;

    cout << "String queue after pulling highest priority element:" << endl;
    stringQueue.Show();

    return 0;
}

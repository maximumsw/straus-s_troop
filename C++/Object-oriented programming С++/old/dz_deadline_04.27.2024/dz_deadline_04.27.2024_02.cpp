#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class PriorityQueue {
private:
    struct Element {
        int value;
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
    void InsertWithPriority(int value, int priority) {
        queue.push_back({ value, priority });
    }

    // Видалення елемента з найвищим пріоритетом
    int PullHighestPriorityElement() {
        int highestPriorityIndex = findHighestPriorityIndex();
        int value = queue[highestPriorityIndex].value;
        queue.erase(queue.begin() + highestPriorityIndex);
        return value;
    }

    // Повернення найбільшого за пріоритетом елемента (без видалення)
    int Peek() const {
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
    PriorityQueue pq;

    pq.InsertWithPriority(10, 1);
    pq.InsertWithPriority(20, 2);
    pq.InsertWithPriority(30, 3);
    pq.InsertWithPriority(40, 1);

    cout << "Queue after insertions:" << endl;
    pq.Show();

    cout << "Peek highest priority element: " << pq.Peek() << endl;
    cout << "Pull highest priority element: " << pq.PullHighestPriorityElement() << endl;
    cout << "Queue after pulling highest priority element:" << endl;
    pq.Show();

    return 0;
}

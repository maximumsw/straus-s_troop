#include <iostream>

template <typename T>
class SinglyLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(T value) : data(value), next(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    SinglyLinkedList() : head(nullptr), tail(nullptr) {}

    ~SinglyLinkedList() {
        DeleteAll();
    }

    // Додавання елемента до голови списку
    void AddToHead(T value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    // Додавання елемента до хвоста списку
    void AddToTail(T value) {
        Node* newNode = new Node(value);
        if (!tail) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Видалення елемента з голови списку
    void DeleteFromHead() {
        if (!head) {
            std::cout << "Список порожній.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        if (!head) {
            tail = nullptr;
        }
        delete temp;
    }

    // Видалення елемента з хвоста списку
    void DeleteFromTail() {
        if (!tail) {
            std::cout << "Список порожній.\n";
            return;
        }
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        }
        else {
            Node* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = nullptr;
        }
    }

    // Видалення всіх елементів списку
    void DeleteAll() {
        while (head) {
            DeleteFromHead();
        }
    }

    // Виведення всіх елементів списку на екран
    void Show() const {
        if (!head) {
            std::cout << "Список порожній.\n";
            return;
        }
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << "\n";
    }

    // Вставлення елемента на задану позицію
    void InsertAtPosition(T value, int position) {
        if (position < 0) {
            std::cout << "Невірна позиція.\n";
            return;
        }

        if (position == 0) {
            AddToHead(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* temp = head;
        for (int i = 0; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (!temp) {
            std::cout << "Позиція за межами списку.\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
        if (!newNode->next) {
            tail = newNode;
        }
    }

    // Видалення елемента із заданої позиції
    void DeleteAtPosition(int position) {
        if (position < 0 || !head) {
            std::cout << "Невірна позиція або список порожній.\n";
            return;
        }

        if (position == 0) {
            DeleteFromHead();
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (!temp || !temp->next) {
            std::cout << "Позиція за межами списку.\n";
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        if (nodeToDelete == tail) {
            tail = temp;
        }
        delete nodeToDelete;
    }

    // Пошук заданого елемента (повертає позицію або NULL)
    int Find(T value) const {
        Node* temp = head;
        int position = 0;
        while (temp) {
            if (temp->data == value) {
                return position;
            }
            temp = temp->next;
            position++;
        }
        return -1; // Якщо елемент не знайдено
    }

    // Пошук і заміна заданого елемента (повертає кількість замінених або -1)
    int FindAndReplace(T oldValue, T newValue) {
        Node* temp = head;
        int count = 0;
        while (temp) {
            if (temp->data == oldValue) {
                temp->data = newValue;
                count++;
            }
            temp = temp->next;
        }
        return count > 0 ? count : -1;
    }

    // Перевертання списку
    void Reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        tail = head; // Оновлюємо хвіст
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev; // Оновлюємо голову
    }
};

int main() {
    SinglyLinkedList<int> list;

    list.AddToHead(1);
    list.AddToTail(2);
    list.AddToTail(3);
    list.AddToHead(0);

    std::cout << "Список після додавання елементів: ";
    list.Show();

    list.InsertAtPosition(5, 2);
    std::cout << "Список після вставлення 5 на позицію 2: ";
    list.Show();

    list.DeleteAtPosition(3);
    std::cout << "Список після видалення елемента на позиції 3: ";
    list.Show();

    int position = list.Find(5);
    if (position != -1) {
        std::cout << "Елемент 5 знайдено на позиції: " << position << "\n";
    }
    else {
        std::cout << "Елемент 5 не знайдено.\n";
    }

    int replacements = list.FindAndReplace(2, 8);
    if (replacements != -1) {
        std::cout << "Кількість замінених елементів: " << replacements << "\n";
    }
    else {
        std::cout << "Елемент для заміни не знайдено.\n";
    }

    std::cout << "Список після заміни: ";
    list.Show();

    list.Reverse();
    std::cout << "Список після перевертання: ";
    list.Show();

    return 0;
}

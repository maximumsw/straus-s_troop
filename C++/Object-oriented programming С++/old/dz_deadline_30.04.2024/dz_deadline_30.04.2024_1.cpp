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
};

int main() {
    SinglyLinkedList<int> list;

    list.AddToHead(1);
    list.AddToTail(2);
    list.AddToTail(3);
    list.AddToHead(0);

    std::cout << "Список після додавання елементів: ";
    list.Show();

    list.DeleteFromHead();
    std::cout << "Список після видалення з голови: ";
    list.Show();

    list.DeleteFromTail();
    std::cout << "Список після видалення з хвоста: ";
    list.Show();

    list.DeleteAll();
    std::cout << "Список після видалення всіх елементів: ";
    list.Show();

    return 0;
}

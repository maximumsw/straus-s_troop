#include <iostream>
#include <stdexcept>  // Для виключень
#include <cstring>    // Для роботи з пам'яттю (використання memset)

template <typename T>
class Array {
private:
    T* data;
    int size;
    int capacity;
    int grow;

    void resize(int newCapacity) {
        if (newCapacity < size) {
            size = newCapacity;
        }

        T* newData = new T[newCapacity];
        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    Array(int initialSize = 0, int growSize = 1) : size(0), grow(growSize) {
        capacity = initialSize > 0 ? initialSize : growSize;
        data = new T[capacity];
    }

    ~Array() {
        delete[] data;
    }

    int GetSize() const {
        return size;
    }

    void SetSize(int newSize, int growSize = 1) {
        grow = growSize;
        if (newSize > capacity) {
            resize(newSize);
        }
        else if (newSize < size) {
            size = newSize;  // Просто зменшуємо розмір, без звільнення пам'яті
        }
    }

    int GetUpperBound() const {
        return size - 1;
    }

    bool IsEmpty() const {
        return size == 0;
    }

    void FreeExtra() {
        if (size < capacity) {
            resize(size);
        }
    }

    void RemoveAll() {
        delete[] data;
        size = 0;
        capacity = grow;
        data = new T[capacity];
    }

    T GetAt(int index) const {
        if (index >= size || index < 0) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    void SetAt(int index, const T& value) {
        if (index >= size || index < 0) {
            throw std::out_of_range("Index out of range");
        }
        data[index] = value;
    }

    T& operator[](int index) {
        if (index >= size || index < 0) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    const T& operator[](int index) const {
        if (index >= size || index < 0) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    void Add(const T& value) {
        if (size >= capacity) {
            resize(capacity + grow);
        }
        data[size++] = value;
    }

    void Append(const Array<T>& other) {
        for (int i = 0; i < other.size; ++i) {
            Add(other.data[i]);
        }
    }

    Array<T>& operator=(const Array<T>& other) {
        if (this != &other) {
            delete[] data;

            size = other.size;
            capacity = other.capacity;
            grow = other.grow;
            data = new T[capacity];

            for (int i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    T* GetData() {
        return data;
    }

    void InsertAt(int index, const T& value) {
        if (index > size || index < 0) {
            throw std::out_of_range("Index out of range");
        }
        if (size >= capacity) {
            resize(capacity + grow);
        }
        for (int i = size; i > index; --i) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        size++;
    }

    void RemoveAt(int index) {
        if (index >= size || index < 0) {
            throw std::out_of_range("Index out of range");
        }
        for (int i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        size--;
    }
};

int main() {
    Array<int> arr(5, 2);
    arr.Add(1);
    arr.Add(2);
    arr.Add(3);

    std::cout << "Array size: " << arr.GetSize() << std::endl;
    std::cout << "Array elements: ";
    for (int i = 0; i < arr.GetSize(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    arr.InsertAt(1, 5);
    std::cout << "After insertion: ";
    for (int i = 0; i < arr.GetSize(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    arr.RemoveAt(2);
    std::cout << "After removal: ";
    for (int i = 0; i < arr.GetSize(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

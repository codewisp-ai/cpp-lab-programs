#include <iostream>
using namespace std;

template <typename T>
class Stack {
public:
    T *arr;
    int length;
    int capacity;

    Stack(int capacity) {
        this->capacity = capacity;
        arr = new T[capacity];
        length = 0;
    }

    // Copy Constructor
    Stack(const Stack<T> &s) {
        capacity = s.capacity;
        length = s.length;
        arr = new T[capacity];
        for (int i = 0; i < length; i++) {
            arr[i] = s.arr[i];
        }
    }

    // Copy Assignment Operator
    Stack& operator=(const Stack<T> &s) {
        if (this != &s) {
            delete[] arr;
            capacity = s.capacity;
            length = s.length;
            arr = new T[capacity];
            for (int i = 0; i < length; i++) {
                arr[i] = s.arr[i];
            }
        }
        return *this;
    }

    // Destructor
    ~Stack() {
        delete[] arr;
    }

    void push(T val) {
        if (length == capacity) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[length++] = val;
    }

    T pop() {
        if (length == 0) {
            cout << "Stack Underflow" << endl;
            return T();   // return default value
        }
        return arr[--length];
    }

    T top() const {
        if (length == 0) {
            cout << "Stack Empty" << endl;
            return T();
        }
        return arr[length - 1];
    }

    int size() const {
        return length;
    }

    void display() const {
        for (int i = 0; i < length; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack<int> s(5);

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();   // 10 20 30

    cout << "Top: " << s.top() << endl;
    cout << "Pop: " << s.pop() << endl;

    s.display();   // 10 20

    return 0;
}

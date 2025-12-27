#include <iostream>
using namespace std;

class Vector {
public:
    int n;
    int* ptr;

    Vector(int n) {
        this->n = n;
        ptr = new int[n];
        for (int i = 0; i < n; i++)
            ptr[i] = 0;
    }

    Vector(const Vector& v) {
        n = v.n;
        ptr = new int[n];
        for (int i = 0; i < n; i++)
            ptr[i] = v.ptr[i];
    }

    ~Vector() {               // 🔥 Destructor added
        delete[] ptr;
    }

    void input() {
        for (int i = 0; i < n; i++) {
            cout << "Enter element: ";
            cin >> ptr[i];
        }
    }

    void display() const {
        for (int i = 0; i < n; i++)
            cout << ptr[i] << " ";
        cout << endl;
    }

    Vector operator+(const Vector& v) const {
        Vector result(n);
        for (int i = 0; i < n; i++)
            result.ptr[i] = ptr[i] + v.ptr[i];
        return result;
    }

    Vector operator-(const Vector& v) const {
        Vector result(n);
        for (int i = 0; i < n; i++)
            result.ptr[i] = ptr[i] - v.ptr[i];
        return result;
    }

    int operator*(const Vector& v) const {
        int dot = 0;
        for (int i = 0; i < n; i++)
            dot += ptr[i] * v.ptr[i];
        return dot;
    }
};

int main() {
    Vector v1(3);
    Vector v2(3);

    v1.input();
    v2.input();

    Vector v3 = v1;
    Vector v4(v2);

    v3.display();
    v4.display();

    Vector v5 = v1 + v2;
    Vector v6 = v2 - v1;

    cout << v1 * v2 << endl;

    v5.display();
    v6.display();
}

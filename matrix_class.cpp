#include <iostream>
using namespace std;

class matrix
{
public:
    int n;
    int **ptr;

    matrix(int n)
    {
        this->n = n;
        ptr = new int *[n];
        for (int i = 0; i < n; i++)
            ptr[i] = new int[n]{0};
    }

    matrix(const matrix &m)
    {
        n = m.n;
        ptr = new int *[n];
        for (int i = 0; i < n; i++)
        {
            ptr[i] = new int[n];
            for (int j = 0; j < n; j++)
                ptr[i][j] = m.ptr[i][j];
        }
    }

    ~matrix()
    {
        for (int i = 0; i < n; i++)
            delete[] ptr[i];
        delete[] ptr;
    }

    void input()
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> ptr[i][j];
    }

    void display()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << ptr[i][j] << " ";
            cout << endl;
        }
    }

    matrix operator+(const matrix &m)
    {
        matrix r(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                r.ptr[i][j] = ptr[i][j] + m.ptr[i][j];
        return r;
    }

    matrix operator-(const matrix &m)
    {
        matrix r(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                r.ptr[i][j] = ptr[i][j] - m.ptr[i][j];
        return r;
    }

    matrix operator*(const matrix &m)
    {
        matrix r(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    r.ptr[i][j] += ptr[i][k] * m.ptr[k][j];
        return r;
    }
};
int main()
{
    int n;
    cout << "Enter matrix size: ";
    cin >> n;

    matrix A(n), B(n);

    cout << "Enter Matrix A:\n";
    A.input();

    cout << "Enter Matrix B:\n";
    B.input();

    matrix C = A + B;
    matrix D = A - B;
    matrix E = A * B;

    cout << "\nA + B:\n";
    C.display();

    cout << "\nA - B:\n";
    D.display();

    cout << "\nA * B:\n";
    E.display();

    return 0;
}

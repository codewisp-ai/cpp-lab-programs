#include <iostream>
#include <stdexcept> // for out_of_range
using namespace std;

template <typename T>
class Pair
{
public:
    T x;
    T y;

    Pair(T x, T y)
    {
        this->x = x;
        this->y = y;
    }

    Pair(const Pair<T> &p)
    {
        x = p.x;
        y = p.y;
    }

    // Copy assignment operator
    Pair<T> &operator=(const Pair<T> &p)
    {
        if (this != &p)
        {
            x = p.x;
            y = p.y;
        }
        return *this;
    }

    // Non-const version
    T &operator[](int t)
    {
        if (t == 0)
            return x;
        if (t == 1)
            return y;
        throw out_of_range("Index must be 0 or 1");
    }

    // Const version
    const T &operator[](int t) const
    {
        if (t == 0)
            return x;
        if (t == 1)
            return y;
        throw out_of_range("Index must be 0 or 1");
    }
};

int main()
{
    Pair<int> p1(10, 20);
    Pair<int> p2(30, 40);

    try
    {
        p1 = p2;
        cout << p1[0] << " " << p1[1] << endl;

        p1[0] = 99;
        cout << p1[0] << endl;

        // Uncomment to test exception
        // cout << p1[2] << endl;
    }
    catch (const out_of_range &e)
    {
        cout << "Exception caught: " << e.what() << endl;
    }

    cout << "Program finished safely." << endl;
    return 0;
}

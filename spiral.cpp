#include <iostream>
using namespace std;

void spiral(int **mat, int r, int c)
{
    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;

    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
            cout << mat[top][i] << " ";
        top++;

        for (int i = top; i <= bottom; i++)
            cout << mat[i][right] << " ";
        right--;

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
                cout << mat[bottom][i] << " ";
            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                cout << mat[i][left] << " ";
            left++;
        }
    }
}

int main()
{
    int **mat;
    int m, n;

    cout << "Enter the row and column number: ";
    cin >> m >> n;

    mat = new int*[m];
    for (int i = 0; i < m; i++)
        mat[i] = new int[n];

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    cout << "\nSpiral order: ";
    spiral(mat, m, n);

    // Free memory
    for (int i = 0; i < m; i++)
        delete[] mat[i];
    delete[] mat;

    return 0;
}

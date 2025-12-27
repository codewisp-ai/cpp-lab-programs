#include <iostream>
#include <iomanip>
using namespace std;

int **getMinor(int **mat, int n, int row, int col)
{
    int **minor = new int *[n - 1];
    for (int i = 0; i < n - 1; i++)
        minor[i] = new int[n - 1];

    int r = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == row)
            continue;
        int c = 0;
        for (int j = 0; j < n; j++)
        {
            if (j == col)
                continue;
            minor[r][c++] = mat[i][j];
        }
        r++;
    }
    return minor;
}

int determinant(int **mat, int n)
{
    if (n == 1)
        return mat[0][0];
    if (n == 2)
        return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];

    int det = 0;
    for (int j = 0; j < n; j++)
    {
        int **minor = getMinor(mat, n, 0, j);
        int sign = (j % 2 == 0) ? 1 : -1;
        det += sign * mat[0][j] * determinant(minor, n - 1);

        for (int i = 0; i < n - 1; i++)
            delete[] minor[i];
        delete[] minor;
    }
    return det;
}

void cofactorMatrix(int **mat, int n, int **cof)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int **minor = getMinor(mat, n, i, j);
            int sign = ((i + j) % 2 == 0) ? 1 : -1;
            cof[i][j] = sign * determinant(minor, n - 1);

            for (int k = 0; k < n - 1; k++)
                delete[] minor[k];
            delete[] minor;
        }
    }
}

void transpose(int **mat, int n, double **trans)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            trans[j][i] = mat[i][j];
}

int main()
{
    int n;
    cout << "Enter order of matrix: ";
    cin >> n;

    int **mat = new int *[n];
    for (int i = 0; i < n; i++)
        mat[i] = new int[n];

    cout << "Enter matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    int det = determinant(mat, n);
    if (det == 0)
    {
        cout << "Inverse does not exist (determinant = 0).\n";
        return 0;
    }

    int **cof = new int *[n];
    for (int i = 0; i < n; i++)
        cof[i] = new int[n];

    cofactorMatrix(mat, n, cof);

    double **adj = new double *[n];
    for (int i = 0; i < n; i++)
        adj[i] = new double[n];

    transpose(cof, n, adj);

    double **inv = new double *[n];
    for (int i = 0; i < n; i++)
        inv[i] = new double[n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            inv[i][j] = adj[i][j] / det;

    cout << "\nInverse Matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(10) << fixed << setprecision(3) << inv[i][j];
        cout << endl;
    }

    // Free memory
    for (int i = 0; i < n; i++)
    {
        delete[] mat[i];
        delete[] cof[i];
        delete[] adj[i];
        delete[] inv[i];
    }
    delete[] mat;
    delete[] cof;
    delete[] adj;
    delete[] inv;

    return 0;
}

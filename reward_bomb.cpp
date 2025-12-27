#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int n;
    cout << "Enter matrix size (>=3): ";
    cin >> n;

    if (n < 3) {
        cout << "Matrix size must be at least 3.\n";
        return 0;
    }

    srand(time(0));

    int grid[50][50] = {0}; // 0 = empty, -1 = bomb, 1 = reward

    // Place 3 bombs
    int placed = 0;
    while (placed < 3) {
        int r = rand() % n;
        int c = rand() % n;
        if ((r != 0 || c != 0) && grid[r][c] == 0) {
            grid[r][c] = -1;
            placed++;
        }
    }

    // Place reward
    while (true) {
        int r = rand() % n;
        int c = rand() % n;
        if ((r != 0 || c != 0) && grid[r][c] == 0) {
            grid[r][c] = 1;
            break;
        }
    }

    int x = 0, y = 0; // starting position
    char move;

    cout << "\nGame started! You are at (0,0)\n";
    cout << "Controls: U = Up, D = Down, L = Left, R = Right\n";

    while (true) {
        cout << "\nEnter move: ";
        cin >> move;

        if (move == 'U' || move == 'u') x--;
        else if (move == 'D' || move == 'd') x++;
        else if (move == 'L' || move == 'l') y--;
        else if (move == 'R' || move == 'r') y++;
        else {
            cout << "Invalid move.\n";
            continue;
        }

        if (x < 0 || x >= n || y < 0 || y >= n) {
            cout << "You hit the boundary! Game over.\n";
            break;
        }

        cout << "You moved to (" << x << "," << y << ")\n";

        if (grid[x][y] == -1) {
            cout << "💣 You hit a bomb! Game over.\n";
            break;
        }
        if (grid[x][y] == 1) {
            cout << "🎉 You found the reward! You win!\n";
            break;
        }
    }

    return 0;
}

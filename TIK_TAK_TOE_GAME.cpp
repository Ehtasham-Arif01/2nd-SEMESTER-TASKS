#include<iostream>
using namespace std;

class tick {
    int arr[3][3];
    static int count;

public:
    tick() {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                arr[i][j] = 0; // Initialize all cells to 0 (empty)
            }
        }
    }

    ~tick() {}

    void set(int r, int c, int player) {
        if(arr[r][c] == 0) {
            arr[r][c] = player; // Set the cell to the player's number
            count++;
        }
        else {
            cout << "\nInvalid move! Cell already taken.\n\n";
        }
    }

    void display() {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(arr[i][j] == 0)
                    cout << " - "; // Empty cell
                else if(arr[i][j] == 1)
                    cout << " X "; // Player 1's move
                else
                    cout << " O "; // Player 2's move
            }
            cout << endl;
        }
    }

    bool checkWin(int player) {
        // Check rows and columns
        for(int i = 0; i < 3; i++) {
            if(arr[i][0] == player && arr[i][1] == player && arr[i][2] == player)
                return true; // Row win
            if(arr[0][i] == player && arr[1][i] == player && arr[2][i] == player)
                return true; // Column win
        }
        // Check diagonals
        if(arr[0][0] == player && arr[1][1] == player && arr[2][2] == player)
            return true; // Main diagonal win
        if(arr[0][2] == player && arr[1][1] == player && arr[2][0] == player)
            return true; // Other diagonal win
        return false;
    }
};

int tick::count = 0;

int main() {
    tick obj;
    int r, c;
    int player = 1; // Player 1 starts

    do {
        cout << "\nPlayer " << player << "'s turn: \n";
        cout << "Enter row: ";
        cin >> r;
        cout << "Enter column: ";
        cin >> c;

        obj.set(r, c, player);
        obj.display();

        // Check for win
        if(obj.checkWin(player)) {
            cout << "Player " << player << " wins!\n";
            break;
        }

        // Switch player
        player = (player == 1) ? 2 : 1;

        // Check for draw
        if(tick::count == 9) {
            cout << "It's a draw!\n";
            break;
        }
    } while(true);

    return 0;
}

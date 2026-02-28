#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define CYAN   "\033[36m"
#define LIME   "\033[92m"
#define RED    "\033[91m"
#define YELLOW "\033[93m"
#define RESET  "\033[0m"

const int R = 4, C = 4;

struct Pos {
    int r, c;
};

bool h[5][4] = {
    {true, true, true, true},   // top border
    {false, true, false, false},
    {false, false, true, false},
    {true, false, false, true},
    {true, true, true, true}    // bottom border
};

bool v[4][5] = {
    {true,  false, true,  false, true}, // row 0
    {true,  false, false, false, true}, // row 1
    {true,  false, false, true,  true}, // row 2
    {true,  false, false, false, true}  // row 3
};

vector<vector<char>> maze = {
    {'S',' ',' ',' '},
    {' ',' ',' ',' '},
    {' ',' ',' ',' '},
    {' ',' ',' ','E'}
};

void printStack(stack<Pos> st) {
    cout << CYAN << "StackFrames (top ---> bottom):\n" << RESET;

    if (st.empty()) {
        cout << "   [empty]\n";
        return;
    }

    while (!st.empty()) {
        Pos p = st.top();
        st.pop();
        cout << "   {" << p.r << "," << p.c << "}\n";
    }
    cout << "\n";
}

bool solveRecursive(int r, int c) {
    if (maze[r][c] == 'E') return true;

    if (maze[r][c] == ' ')
        maze[r][c] = '*';

    // Up
    if (r > 0 && !h[r][c] && maze[r - 1][c] != '*' && maze[r - 1][c] != '.')
        if (solveRecursive(r - 1, c)) return true;

    // Right
    if (c < C - 1 && !v[r][c + 1] && maze[r][c + 1] != '*' && maze[r][c + 1] != '.')
        if (solveRecursive(r, c + 1)) return true;

    // Down
    if (r < R - 1 && !h[r + 1][c] && maze[r + 1][c] != '*' && maze[r + 1][c] != '.')
        if (solveRecursive(r + 1, c)) return true;

    // Left
    if (c > 0 && !v[r][c] && maze[r][c - 1] != '*' && maze[r][c - 1] != '.')
        if (solveRecursive(r, c - 1)) return true;

    // Backtrack
    if (maze[r][c] == '*')
        maze[r][c] = '.';

    return false;
}

bool solveWithStack(int sr, int sc) {
    stack<Pos> st;

    // Mark S as visited so we don't re-enter it
    maze[sr][sc] = '*';
    st.push({ sr, sc });

    cout << LIME << "PUSH: (" << sr << "," << sc << ")\n" << RESET;
    printStack(st);

    while (!st.empty()) {
        Pos cur = st.top();
        int r = cur.r, c = cur.c;

        if (maze[r][c] == 'E')
            return true;

        bool moved = false;

        auto tryMove = [&](int nr, int nc) {
            st.push({ nr, nc });
            if (maze[nr][nc] == ' ') maze[nr][nc] = '*';

            cout << LIME << "PUSH: (" << nr << "," << nc << ")\n" << RESET;
            printStack(st);

            moved = true;
            };

        // Up
        if (!moved && r > 0 && !h[r][c] &&
            maze[r - 1][c] != '*' && maze[r - 1][c] != '.')
            tryMove(r - 1, c);

        // Right
        if (!moved && c < C - 1 && !v[r][c + 1] &&
            maze[r][c + 1] != '*' && maze[r][c + 1] != '.')
            tryMove(r, c + 1);

        // Down
        if (!moved && r < R - 1 && !h[r + 1][c] &&
            maze[r + 1][c] != '*' && maze[r + 1][c] != '.')
            tryMove(r + 1, c);

        // Left
        if (!moved && c > 0 && !v[r][c] &&
            maze[r][c - 1] != '*' && maze[r][c - 1] != '.')
            tryMove(r, c - 1);

        // Dead end → backtrack
        if (!moved) {
            if (maze[r][c] == '*')
                maze[r][c] = '.';

            cout << RED << "POP:  (" << r << "," << c << ")\n" << RESET;
            st.pop();
            printStack(st);
        }
    }

    return false;
}



// ANSI-colored renderer
void printMaze() {
    for (int r = 0; r <= R; ++r) {

        // Horizontal walls
        for (int c = 0; c < C; ++c) {
            cout << CYAN << "+";
            if (h[r][c]) cout << "---";
            else         cout << "   ";
        }
        cout << "+" << RESET << "\n";

        if (r == R) break;

        // Cell row with vertical walls
        for (int c = 0; c < C; ++c) {

            // Vertical wall
            if (v[r][c]) cout << CYAN << "|" << RESET;
            else         cout << " ";

            // Cell contents with color
            char cell = maze[r][c];

            if (cell == '*')
                cout << " " << LIME << "*" << RESET << " ";
            else if (cell == '.')
                cout << " " << RED << "." << RESET << " ";
            else if (cell == 'S' || cell == 'E')
                cout << " " << YELLOW << cell << RESET << " ";
            else
                cout << " " << cell << " ";
        }

        // Right border
        if (v[r][C]) cout << CYAN << "|" << RESET << "\n";
        else         cout << " \n";
    }
    cout << "\n";
}

int main() {
    cout << "Initial Maze:\n";
    printMaze();

    //solveRecursive(0, 0);
    solveWithStack(0, 0);


    cout << "Solved Maze:\n";
    printMaze();
    return 0;
}
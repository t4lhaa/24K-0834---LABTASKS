#include <iostream>
using namespace std;

#define N 7

int maze[N][N] = {
    {1,0,1,1,1,0,1},
    {1,1,1,0,1,1,1},
    {0,1,0,1,0,1,0},
    {1,1,1,1,1,0,1},
    {0,0,0,0,1,1,1},
    {1,1,1,0,1,0,1},
    {0,0,1,1,1,1,1}
};

int path[N][N];

bool isPath(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1 && path[x][y] == 0);
}

bool solveMazeUtil(int x, int y){
    if (x == N-1 && y == N-1 && maze[x][y] == 1) {
        path[x][y] = 1;
        return true;
    }

    if (isPath(x, y)) {
        path[x][y] = 1;

        if (solveMazeUtil(x+1, y)){ 
            return true;
        }

        if (solveMazeUtil(x, y+1)){ 
            return true;
        }
        if (solveMazeUtil(x-1, y)){ 
            return true;
        }
        if (solveMazeUtil(x, y-1)){ 
            return true;
        }

        path[x][y] = 0;
    }
    return false;
}

void printSolution();

void solveMaze() {
    for (int i=0;i<N;i++)
        for (int j=0;j<N;j++)
            path[i][j] = 0;

    if (solveMazeUtil(0, 0)) {
        printSolution();
    } else {
        cout << "No path found!!!!"<<endl;
    }
}


void printSolution() {
    cout << "Solution Path:"<<endl;
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++)
            cout << path[i][j] << " ";
        cout << endl;
    }
}

int main() {
    solveMaze();
    return 0;
}

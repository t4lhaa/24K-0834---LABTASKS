#include <iostream>
using namespace std;

class Matrix
{
private:
    int **mat;
    int row, col;

    void allocate(int r, int c)
    {
        row = r;
        col = c;
        mat = new int *[row];
        for (int i = 0; i < row; i++)
        {
            mat[i] = new int[col];
        }
    }

public:
    Matrix(int r, int c)
    {
        allocate(r, c);
    }

    void fillMatrix()
    {
        cout << "Enter values of Matrix: " << endl;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cin >> mat[i][j];
            }
        }
    }

    void resize(int rNew, int cNew, int fillVal)
    {
        int **mat1 = new int *[rNew];
        for (int i = 0; i < rNew; i++)
        {
            mat1[i] = new int[cNew];
            for (int j = 0; j < cNew; j++)
            {
                if (i < row && j < col)
                    mat1[i][j] = mat[i][j];
                else
                    mat1[i][j] = fillVal;
            }
        }

        for (int i = 0; i < row; i++)
        {
            delete[] mat[i];
            delete[] mat;
        }

        mat = mat1;
        row = rNew;
        col = cNew;
    }

    void transpose()
    {
        int **transpose1 = new int *[col];
        for (int i = 0; i < col; i++)
        {
            transpose1[i] = new int[row];
            for (int j = 0; j < row; j++)
            {
                transpose1[i][j] = mat[j][i];
            }
        }

        for (int i = 0; i < row; i++)
            delete[] mat[i];
        delete[] mat;

        mat = transpose1;
        int temp = row;
        row = col;
        col = temp;
    }

    void printMatrix()
    {
        cout << "Matrix:" << endl;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                int val = mat[i][j];
                if ((i + j) % 2 == 1)
                    val += 2;
                cout << val << " ";
            }
            cout << endl;
        }
    }

    ~Matrix()
    {
        for (int i = 0; i < row; i++)
            delete[] mat[i];
        delete[] mat;
        delete mat;
    }
};

int main()
{
    int row, col;
    cout << "Enter Rows: ";
    cin >> row;
    cout << "Enter Columns:  ";
    cin >> col;

    Matrix M1(row, col);

    M1.fillMatrix();
    cout << "Old Matrix:" << endl;
    M1.printMatrix();

    M1.transpose();
    cout << "Transpose matrix:" << endl;
    M1.printMatrix();

    M1.resize(row + 1, col + 1, 0);
    cout << "Resize:" << endl;
    M1.printMatrix();

    return 0;
}

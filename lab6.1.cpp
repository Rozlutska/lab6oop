#include <iostream>
using namespace std;

template <typename T>
class DynamicArrayCopy {
private:
    T** array;
    int rows;
    int cols;

public:
    DynamicArrayCopy(int numRows, int numCols) : rows(numRows), cols(numCols) {
        array = new T * [rows];
        for (int i = 0; i < rows; ++i) {
            array[i] = new T[cols];
        }
    }

    ~DynamicArrayCopy() {
        for (int i = 0; i < rows; ++i) {
            delete[] array[i];
        }
        delete[] array;
    }

    void copySelectedRow(int fromRow, T* inArray) {
        for (int i = 0; i < cols; ++i) {
            inArray[i] = array[fromRow][i];
        }
    }

    void copySelectedColumn(int fromCol, T* inArray) {
        for (int i = 0; i < rows; ++i) {
            inArray[i] = array[i][fromCol];
        }
    }

    void copyMainDiagonal(T* inArray) {
        for (int i = 0; i < min(rows, cols); ++i) {
            inArray[i] = array[i][i];
        }
    }

    void displayArray() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << array[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    void inputArray() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << "Enter value for element [" << i << "][" << j << "]: ";
                cin >> array[i][j];
            }
        }
    }
};

int main() {
    /*int rows, cols;
    cout << "Enter rows:" << endl;
    cin >> rows;
    cout << "Enter cols:" << endl;
    cin >> cols;*/
    DynamicArrayCopy<string> arrayCopy(3, 3);

    cout << "Enter values for the array:\n";
    arrayCopy.inputArray();

    cout << "\nOriginal Array:\n";
    arrayCopy.displayArray();

    cout << "Enter row you want to copy: " << endl;
    int selectedRow;
    cin >> selectedRow;
    cout << endl;

    string selectedRowArray[3];
    arrayCopy.copySelectedRow(selectedRow, selectedRowArray);


    cout << "Enter col you want to copy: " << endl;
    int selectedCol;
    cin >> selectedCol;
    cout << endl;

    string selectedColArray[3];
    arrayCopy.copySelectedColumn(selectedCol, selectedColArray);

    string mainDiagonalArray[3];
    arrayCopy.copyMainDiagonal(mainDiagonalArray);

    cout << "\nCopied Row:\n";
    for (int i = 0; i < 3; ++i) {
        cout << selectedRowArray[i] << ' ';
    }

    cout << "\nCopied Column:\n";
    for (int i = 0; i < 3; ++i) {
        cout << selectedColArray[i] << ' ';
    }

    cout << "\nMain Diagonal:\n";
    for (int i = 0; i < 3; ++i) {
        cout << mainDiagonalArray[i] << ' ';
    }


    return 0;
}
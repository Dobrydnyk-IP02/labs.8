#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

int const size_array = 5;
typedef float matrix_A[size_array][size_array];
typedef float matrix_B[size_array][size_array];
matrix_A array_A;
matrix_B array_B;

void fill_array_A(matrix_A);
void output_array_A(matrix_A);
float s_a1(matrix_A, int, int, int*);
float s_a(matrix_A, int, int);
void create_array_B(matrix_A, matrix_B);
void output_array_B(matrix_B array_B);


    void fill_array_A(matrix_A array_A) {
        srand(time(NULL));
        for (int i = 0; i < size_array; i++) {
            for (int j = 0; j < size_array; j++) {
                array_A[i][j] = rand() % 10;
            }
        }
    }

    void output_array_A(matrix_A array_A) {
        for (int i = 0; i < size_array; i++) {
            for (int j = 0; j < size_array; j++) {

                cout << setw(5) << array_A[i][j];
            }
            cout << endl;
        }
    }


    float s_a1(matrix_A array_A, int i, int j, int* a) {
        int value = array_A[i][j];
        if (i == size_array || j == size_array || i < 0 || j < 0) {
            value = 0;
            *a = *a - 1;
        }
        return value;
    }

    float s_a(matrix_A array_A, int i, int j) {
        int amount = size_array - 1;
        return (s_a1(array_A, i + 1, j, &amount) + s_a1(array_A, i, j + 1, &amount) + s_a1(array_A, i - 1, j, &amount) + s_a1(array_A, i, j - 1, &amount)) / amount;
    }

    void create_array_B(matrix_A array_A, matrix_B array_B) {
        for (int i = 0; i < size_array; i++) {
            for (int j = 0; j < size_array; j++) {
                array_B[i][j] = s_a(array_A, i, j);
            }
        }
    }

    void output_array_B(matrix_B array_B) {
        for (int i = 0; i < size_array; i++) {
            for (int j = 0; j < size_array; j++) {
                cout << setw(12) << array_B[i][j] << "\t ";
            }
            cout << endl;
        }
    }

#include <iostream>
#include <ctime>
#include <iomanip>
#include "Header.h"
using namespace std;

int main() {
  
    fill_array_A(array_A);
    output_array_A(array_A);
    cout << "==============================" << endl;
    create_array_B(array_A, array_B);
    output_array_B(array_B);
    system("pause");
}


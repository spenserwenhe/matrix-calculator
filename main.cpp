#include "matrix.h"

#include <iostream>

int main() {
    unsigned row = 0;
    unsigned col = 0;
    std::cout<<"Enter dimensions [row, col]: "<<std::endl;
    std::cin>>row>>col;
    Matrix newMat = Matrix(row, col);
    newMat.printMatrix();
    newMat.rref();
    newMat.printMatrix();
    return 0;
}
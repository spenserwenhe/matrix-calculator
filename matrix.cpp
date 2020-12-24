#include "matrix.h"

#include <iostream>

Matrix::Matrix() {

}

Matrix::Matrix(int m, int n) {
    for (int row = 0; row < m; ++row) {
        std::vector<double> v;
        mat.push_back(v);
        for (int col = 0; col < n; ++col) {
            mat[row].push_back(0);
        }
    }
    std::cout<<"Type your entries: "<<std::endl;
    for (int row = 0; row < m; ++row) {
        for (int col = 0; col < n; ++col) {
            std::cin>>mat[row][col];
        }
    }
}

void Matrix::printMatrix() {
    std::cout<<"______________________________"<<std::endl;
    for (unsigned row = 0; row < mat.size(); ++row) {
        for (unsigned col = 0; col < mat[row].size(); ++col) {
            if (col == mat[row].size() - 1) {
                std::cout<<mat[row][col]<<std::endl;
            }
            else {
                std::cout<<mat[row][col]<<"    ";
            }
        }
    }
}
/*
std::vector<std::vector<int>> Matrix::getMatrix() {
    return mat;
}
*/

void Matrix::rowSwitch(unsigned rowA, unsigned rowB) {
    if (rowA > mat.size() || rowA <= 0 ||
        rowB > mat.size() || rowB <= 0) {
            std::cout<<"Invalid operation. Please enter valid rows."<<std::endl;
            return;
    }
    for (unsigned i = 0; i < mat[rowA - 1].size(); ++i) {
        double temp = mat[rowA - 1][i];
        mat[rowA - 1][i] = mat[rowB - 1][i];
        mat[rowB - 1][i] = temp;
    }
}

void Matrix::rowScale(unsigned row, double scale) {
    if ( row > mat.size() || row <= 0) {
        std::cout<<"Invalid operation. Please enter a valid row."<<std::endl;
        return;
    }
    for (int i = 0; i < mat[row].size(); ++i) {
        mat[row - 1][i] = mat[row - 1][i] * scale;
    }
}

void Matrix::rowAdd(unsigned rowDest, unsigned rowSource, double scale) {
    if (rowDest > mat.size() || rowDest <= 0 ||
        rowSource > mat.size() || rowSource <= 0) {
            std::cout<<"Invalid operation. Please enter valid rows."<<std::endl;
            return;
    }
    for (unsigned i = 0; i < mat[rowDest].size(); ++i) {
        mat[rowDest - 1][i] += mat[rowSource - 1][i] * scale;
    }
}

/*std::vector<std::vector<double>> findEchelon() {

}

std::vector<std::vector<double>> rref() {

}*/

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

void Matrix::rowSwitch(int rowA, int rowB) {
    for (unsigned i = 0; i < mat[rowA - 1].size(); ++i) {
        double temp = mat[rowA - 1][i];
        mat[rowA - 1][i] = mat[rowB - 1][i];
        mat[rowB - 1][i] = temp;
    }
}

void Matrix::rowScale(int row, double scale) {

}

void Matrix::rowAdd(int rowDest, int rowSoure, double scale) {

}

/*std::vector<std::vector<double>> findEchelon() {

}

std::vector<std::vector<double>> rref() {

}*/

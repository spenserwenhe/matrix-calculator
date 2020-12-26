#include "matrix.h"

#include <iostream>
#include <string>

int main() {
    while (true) {
        char a;
        while (true) {
            std::cout<<"New matrix? [y / n]"<<std::endl;
            std::cin>>a;
            if (a == 'y') {
                break;
            }
            if (a == 'n') {
                return 0;
            }
            if (a != 'y' && a != 'n') {
                std::cout<<"Please enter a valid command."<<std::endl;
            }
        }
        int m, n;
        while (true) {
            std::cout<<"Enter matrix dimensions: [row col]"<<std::endl;
            std::cin>>m>>n;
            if (m < 1 || n < 1) {
                std::cout<<"Please enter valid dimensions."<<std::endl;
                continue;
            }
            else {
                break;
            }
        }
        Matrix newMat = Matrix(m, n);
        std::cout<<"Type your entries: "<<std::endl;
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                double temp;
                std::cin>>temp;
                newMat.setEntry(row, col, temp);
            }
        }
        newMat.printMatrix();
        std::string funcInput;
        while (true) {
            std::cout<<"Choose: [Echelon / RREF]"<<std::endl;
            std::cin>>funcInput;
            if (funcInput == "Echelon") {
                newMat.findEchelon();
                newMat.printMatrix();
                break;
            }
            if (funcInput == "RREF") {
                newMat.rref();
                newMat.printMatrix();
                break;
            }
            if (funcInput != "Echelon" && funcInput != "RREF") {
                std::cout<<"Please enter a valid command."<<std::endl;
            }
        }
    }
    return 0;
}
#include "matrix.h"

#include <iostream>
#include <string>

int main() {
    while (true) {
        std::cout<<"New matrix? [y / n]"<<std::endl;
        char a;
        std::cin>>a;
        if (a == 'n') {
            return 0;
        }
        if (a != 'y' && a != 'n') {
            std::cout<<"Please enter a valid command."<<std::endl;
            continue;
        }
        std::cout<<"Enter matrix dimensions: [row col]"<<std::endl;
        int m, n;
        std::cin>>m>>n;
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
        std::cout<<"Choose: [Echelon / RREF]"<<std::endl;
        std::string funcInput;
        std::cin>>funcInput;
        if (funcInput == "Echelon") {
            newMat.findEchelon();
            newMat.printMatrix();
        }
        if (funcInput == "RREF") {
            newMat.rref();
            newMat.printMatrix();
        }
    }
}
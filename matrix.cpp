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

std::vector<std::vector<double> > Matrix::getMatrix() {
    return mat;
}

void Matrix::rowSwitch(unsigned rowA, unsigned rowB) {
    if (rowA >= mat.size() || rowA < 0 ||
        rowB >= mat.size() || rowB < 0) {
            std::cout<<"Invalid operation. Please enter valid rows."<<std::endl;
            return;
    }
    for (unsigned i = 0; i < mat[rowA].size(); ++i) {
        double temp = mat[rowA][i];
        mat[rowA][i] = mat[rowB][i];
        mat[rowB][i] = temp;
    }
}

void Matrix::rowScale(unsigned row, double scale) {
    if ( row >= mat.size() || row < 0) {
        std::cout<<"Invalid operation. Please enter a valid row."<<std::endl;
        return;
    }
    for (int i = 0; i < mat[row].size(); ++i) {
        if (mat[row][i] != 0) {
            mat[row][i] = mat[row][i] * scale;
        }
    }
}

void Matrix::rowAdd(unsigned rowDest, unsigned rowSource, double scale) {
    if (rowDest >= mat.size() || rowDest < 0 ||
        rowSource >= mat.size() || rowSource < 0) {
            std::cout<<"Invalid operation. Please enter valid rows."<<std::endl;
            return;
    }
    for (unsigned i = 0; i < mat[rowDest].size(); ++i) {
        if (mat[rowSource][i] != 0) {
            mat[rowDest][i] += mat[rowSource][i] * scale;
        }
    }
}

/*
1) Swap the 1st row with a lower one so a leftmost nonzero entry is in the
    1st row.
2) Scale the 1st row so that its first nonzero entry is equal to 1.
3) Use row replacement so all entries below this 1 are 0.
4) Swap the 2nd row with a lower one so that the leftmost nonzero entry is
    in the 2nd row, etc.
*/
void Matrix::findEchelon() {
    if (Matrix::zeroMatCheck() == 1) {
        return;
    }
    int rowCounter = 0;
    std::cout<<mat[0].size()<<std::endl;
    for (unsigned col = 0; col < mat[0].size(); ++col) {
        if (rowCounter >= mat.size()) {
            break;
        }
        if (Matrix::zeroCol(col) == 0) {

            /*Swap the 1st row with a lower one so a leftmost nonzero entry
            is in the first row. */
            if (mat[rowCounter][col] == 0 && rowCounter < mat.size() - 1) {
                for (int i = rowCounter + 1; i < mat.size(); ++i) {
                    if (mat[i][col] != 0) {
                        Matrix::rowSwitch(rowCounter, i);
                        Matrix::printMatrix();
                        break;
                    }
                }
            }
            
            //Make pivot entry a 1 and entries below 0
            double scale1 = 1 / mat[rowCounter][col];
            Matrix::rowScale(rowCounter, scale1);
            Matrix::printMatrix();
            if (rowCounter < mat.size() - 1) {
                for (int i = rowCounter + 1; i < mat.size(); ++i) {
                    if (mat[i][col] != 0) {
                        if (mat[i][col] == mat[rowCounter][col]) {
                            Matrix::rowAdd(i, rowCounter, -1);
                            Matrix::printMatrix();
                        }
                         else {
                            Matrix::rowAdd(i, rowCounter, (-1) * mat[i][col]);
                        }
                    }
                }
            }
            ++rowCounter;
        }
        std::cout<<"check"<<std::endl;
    }
    std::cout<<"check2"<<std::endl;
}

bool Matrix::zeroCol(unsigned col) {
    for (unsigned i = 0; i < mat.size(); ++i) {
        if (mat[i][col] != 0) {
            return 0;
        }
    }
    return 1;
}

bool Matrix::zeroMatCheck() {
   for (unsigned row = 0; row < mat.size(); ++row) {
       for (unsigned col = 0; col < mat[row].size(); ++col) {
           if (mat[row][col] != 0) {
               return 0;
           }
       }
   }
   return 1;
}

/*std::vector<std::vector<double>> Matrix::rref() {
    Matrix::findEchelon();
}*/

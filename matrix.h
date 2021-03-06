#pragma once

#include <vector>

class Matrix {
    private:
        std::vector<std::vector<double> > mat;
    public:
        //Default constructor, empty matrix
        Matrix();

        //Constructs 
        Matrix(int m, int n);

        //Print matrix
        void printMatrix();

        //Returns the matrix for the matrix object
        std::vector<std::vector<double> > getMatrix();

        //Elementary row operations
        void rowSwitch(unsigned rowA, unsigned rowB);      //Switches two rows
        void rowScale(unsigned row, double scale);       //scales a row
        void rowAdd(unsigned rowDest, unsigned rowSource, double scale);       //adds a scaled row to another row

        //Finds an echelon form and an RREF of the matrix
        void findEchelon();
        void rref();

        //Helper functions
        bool zeroCol(unsigned col);   //Returns 1 if it's a zero column, 0 if not
        bool zeroMatCheck();        //Returns 1 if it's a zero matrix, 0 if not

        //Testing functions
        double getEntry(unsigned row, unsigned col);
        void setEntry(unsigned row, unsigned col, double num);
};

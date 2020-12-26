#include "../matrix.h"
//#define CATCH_CONFIG_MAIN
#include "../cs225/catch/catch.hpp"

//Echelon test cases
TEST_CASE("echelon", "[echelon]") {
    std::vector<std::vector<double> > echelonKey1 = {
        {1, 1, 1, 1},
        {0, 1, 2, 3},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    Matrix mat1 = Matrix(4, 4);
    mat1.setEntry(0, 0, 1);
    mat1.setEntry(0, 1, 1);
    mat1.setEntry(0, 2, 1);
    mat1.setEntry(0, 3, 1);
    mat1.setEntry(1, 0, 1);
    mat1.setEntry(1, 1, 1);
    mat1.setEntry(1, 2, 1);
    mat1.setEntry(1, 3, 1);
    mat1.setEntry(2, 0, 0);
    mat1.setEntry(2, 1, 1);
    mat1.setEntry(2, 2, 2);
    mat1.setEntry(2, 3, 3);
    mat1.setEntry(3, 0, 0);
    mat1.setEntry(3, 1, 1);
    mat1.setEntry(3, 2, 2);
    mat1.setEntry(3, 3, 3);
    mat1.findEchelon();
    REQUIRE(mat1.getMatrix() == echelonKey1);

    std::vector<std::vector<double> > echelonKey2 = {
        {1, 2, 1},
        {0, 1, 0},
        {0, 0, 0}
    };
    Matrix mat2 = Matrix(3, 3);
    mat2.setEntry(0, 0, 1);
    mat2.setEntry(0, 1, 2);
    mat2.setEntry(0, 2, 1);
    mat2.setEntry(1, 0, 2);
    mat2.setEntry(1, 1, 2);
    mat2.setEntry(1, 2, 2);
    mat2.setEntry(2, 0, 1);
    mat2.setEntry(2, 1, 0);
    mat2.setEntry(2, 2, 1);
    mat2.findEchelon();
    REQUIRE(mat2.getMatrix() == echelonKey2);

    std::vector<std::vector<double> > echelonKey3 = {
        {1, 2, 3},
        {0, 1, 2}
    };
    Matrix mat3 = Matrix(2, 3);
    mat3.setEntry(0, 0, 1);
    mat3.setEntry(0, 1, 2);
    mat3.setEntry(0, 2, 3);
    mat3.setEntry(1, 0, 2);
    mat3.setEntry(1, 1, 3);
    mat3.setEntry(1, 2, 4);
    mat3.findEchelon();
    REQUIRE(mat3.getMatrix() == echelonKey3);
}

//RREF test cases
TEST_CASE("RREF_1", "[rref]") {
    std::vector<std::vector<double> > rrefKey1 = {
        {1, 0, -1, -2},
        {0, 1, 2, 3},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    Matrix mat1 = Matrix(4, 4);
    mat1.setEntry(0, 0, 1);
    mat1.setEntry(0, 1, 1);
    mat1.setEntry(0, 2, 1);
    mat1.setEntry(0, 3, 1);
    mat1.setEntry(1, 0, 1);
    mat1.setEntry(1, 1, 1);
    mat1.setEntry(1, 2, 1);
    mat1.setEntry(1, 3, 1);
    mat1.setEntry(2, 0, 0);
    mat1.setEntry(2, 1, 1);
    mat1.setEntry(2, 2, 2);
    mat1.setEntry(2, 3, 3);
    mat1.setEntry(3, 0, 0);
    mat1.setEntry(3, 1, 1);
    mat1.setEntry(3, 2, 2);
    mat1.setEntry(3, 3, 3);
    mat1.rref();
    REQUIRE(mat1.getMatrix() == rrefKey1);

    std::vector<std::vector<double> > rrefKey2 = {
        {1, 0, 1},
        {0, 1, 0},
        {0, 0, 0}
    };
    Matrix mat2 = Matrix(3, 3);
    mat2.setEntry(0, 0, 1);
    mat2.setEntry(0, 1, 2);
    mat2.setEntry(0, 2, 1);
    mat2.setEntry(1, 0, 2);
    mat2.setEntry(1, 1, 2);
    mat2.setEntry(1, 2, 2);
    mat2.setEntry(2, 0, 1);
    mat2.setEntry(2, 1, 0);
    mat2.setEntry(2, 2, 1);
    mat2.rref();
    REQUIRE(mat2.getMatrix() == rrefKey2);

    std::vector<std::vector<double> > rrefKey3 = {
        {1, 0, -1},
        {0, 1, 2}
    };
    Matrix mat3 = Matrix(2, 3);
    mat3.setEntry(0, 0, 1);
    mat3.setEntry(0, 1, 2);
    mat3.setEntry(0, 2, 3);
    mat3.setEntry(1, 0, 2);
    mat3.setEntry(1, 1, 3);
    mat3.setEntry(1, 2, 4);
    mat3.rref();
    REQUIRE(mat3.getMatrix() == rrefKey3);
}
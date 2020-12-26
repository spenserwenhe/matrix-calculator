#include "../matrix.h"
//#define CATCH_CONFIG_MAIN
#include "../cs225/catch/catch.hpp"

TEST_CASE("echelon_1", "[echelon]") {
    std::vector<std::vector<double> > mat1key = {
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
    REQUIRE(mat1.getMatrix() == mat1key);
}
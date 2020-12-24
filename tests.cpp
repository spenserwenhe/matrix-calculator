#include "matrix.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("echelon_1", "[echelon]") {
    std::vector<std::vector<double> > mat1key = {
        {1, 1, 1, 1},
        {0, 1, 2, 3},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    Matrix mat1 = Matrix(4, 4);
    mat1.findEchelon();
}
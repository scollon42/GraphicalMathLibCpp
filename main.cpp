#include <iostream>
#include "Vector3D.h"
#include "Matrix3D.h"

int main() {
    Matrix3D M(
        1, 0, 0,
        0, 1, 0,
        0, 0, 1
    );

    Matrix3D M1(
            3, 6, 2,
            2, 1, 0,
            4, 7, 1
    );

    Vector3D v(4.1, 2.3, 1.98);


    std::cout << M << std::endl;
    std::cout << M1 << std::endl;
    std::cout << M1 * v << std::endl;
    std::cout << M * 5.231 << std::endl;
    std::cout << M / 5 << std::endl;
    std::cout << M + M1 << std::endl;

    return 0;
}
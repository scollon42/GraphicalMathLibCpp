#include <iostream>
#include "Vector3D.h"
#include "Matrix3D.h"

int main()
{
    Vector3D I(1, 0, 0);
    Vector3D J(0, 1, 0);
    Vector3D K(0, 0, 1);

    std::cout << Cross(I, J) << std::endl;
    std::cout << Cross(J, I) << std::endl;
    std::cout << Cross(J, K) << std::endl;
    std::cout << Cross(K, J) << std::endl;
    std::cout << Cross(K, I) << std::endl;
    std::cout << Cross(I, K) << std::endl;
    return 0;
}
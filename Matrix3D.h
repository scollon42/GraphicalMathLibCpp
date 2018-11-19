#ifndef GRAPHICALMATH_MATRIX_H
#define GRAPHICALMATH_MATRIX_H

#include <sstream>
#include "Vector3D.h"

struct Matrix3D
{
private:
    float n[3][3];

public:
    Matrix3D(
            float n00, float n01, float n02,
            float n10, float n11, float n12,
            float n20, float n21, float n22
    );

    Matrix3D(const Vector3D &a, const Vector3D &b, const Vector3D &c);

    float &operator()(int i, int j);

    const float &operator()(int i, int j) const;

    Vector3D &operator[](int i);

    const Vector3D &operator[](int i) const;

    Matrix3D &operator+=(const Matrix3D &other);

    Matrix3D &operator-=(const Matrix3D &other);

    Matrix3D &operator*=(const float &scalar);

    Matrix3D &operator/=(const float &scalar);

    friend std::ostream &operator<<(std::ostream &, const Matrix3D &);
};

inline Matrix3D operator+(const Matrix3D &ma, const Matrix3D &mb)
{
    return (
            Matrix3D(
                    ma(0, 0) + mb(0, 0), ma(0, 1) + mb(0, 1), ma(0, 2) + mb(0, 2),
                    ma(1, 0) + mb(1, 0), ma(1, 1) + mb(1, 1), ma(1, 2) + mb(1, 2),
                    ma(2, 0) + mb(2, 0), ma(2, 1) + mb(2, 1), ma(2, 2) + mb(2, 2)
            )
    );
}

inline Matrix3D operator-(const Matrix3D &ma, const Matrix3D &mb)
{
    return (
            Matrix3D(
                    ma(0, 0) - mb(0, 0), ma(0, 1) - mb(0, 1), ma(0, 2) - mb(0, 2),
                    ma(1, 0) - mb(1, 0), ma(1, 1) - mb(1, 1), ma(1, 2) - mb(1, 2),
                    ma(2, 0) - mb(2, 0), ma(2, 1) - mb(2, 1), ma(2, 2) - mb(2, 2)
            )
    );
}

inline Matrix3D operator*(const Matrix3D &M, float t)
{
    return Matrix3D(
            M(0, 0) * t, M(0, 1) * t, M(0, 2) * t,
            M(1, 0) * t, M(1, 1) * t, M(1, 2) * t,
            M(2, 0) * t, M(2, 1) * t, M(2, 2) * t
    );
}

inline Matrix3D operator/(const Matrix3D &M, float t)
{
    return Matrix3D(
            M(0, 0) / t, M(0, 1) / t, M(0, 2) / t,
            M(1, 0) / t, M(1, 1) / t, M(1, 2) / t,
            M(2, 0) / t, M(2, 1) / t, M(2, 2) / t
    );
}

inline Vector3D operator*(const Matrix3D &M, const Vector3D &v)
{
    return Vector3D(
            M(0, 0) * v.x + M(0, 1) * v.y + M(0, 2) * v.z,
            M(1, 0) * v.x + M(1, 1) * v.y + M(1, 2) * v.z,
            M(2, 0) * v.x + M(2, 1) * v.y + M(2, 2) * v.z
    );
}

inline Matrix3D operator*(const Matrix3D &A, const Matrix3D &B)
{
    return Matrix3D(
            A(0, 0) * B(0, 0) + A(0, 1) * B(1, 0) + A(0, 2) * B(2, 0),
            A(0, 0) * B(0, 1) + A(0, 1) * B(1, 1) + A(0, 2) * B(2, 1),
            A(0, 0) * B(0, 2) + A(0, 1) * B(1, 2) + A(0, 2) * B(2, 2),
            A(1, 0) * B(0, 0) + A(1, 1) * B(1, 0) + A(1, 2) * B(2, 0),
            A(1, 0) * B(0, 1) + A(1, 1) * B(1, 1) + A(1, 2) * B(2, 1),
            A(1, 0) * B(0, 2) + A(1, 1) * B(1, 2) + A(1, 2) * B(2, 2),
            A(2, 0) * B(0, 0) + A(2, 1) * B(1, 0) + A(2, 2) * B(2, 0),
            A(2, 0) * B(0, 1) + A(2, 1) * B(1, 1) + A(2, 2) * B(2, 1),
            A(2, 0) * B(0, 2) + A(2, 1) * B(1, 2) + A(2, 2) * B(2, 2)
    );
}

inline std::ostream &operator<<(std::ostream &stream, const Matrix3D &v)
{
    stream << v(0, 0) << ", " << v(0, 1) << ", " << v(0, 2) << std::endl;
    stream << v(1, 0) << ", " << v(1, 1) << ", " << v(1, 2) << std::endl;
    stream << v(2, 0) << ", " << v(2, 1) << ", " << v(2, 2) << std::endl;

    return stream;
}

#endif //GRAPHICALMATH_MATRIX_H

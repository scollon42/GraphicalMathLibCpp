//
// Created by Sam on 11/17/2018.
//

#include "Vector3D.h"
#include <cmath>

Vector3D::Vector3D()
        : x(0), y(0), z(0)
{}

Vector3D::Vector3D(float a, float b, float c)
        : x(a), y(b), z(c)
{}

Vector3D::Vector3D(const Vector3D &v)
        : x(v.x), y(v.y), z(v.z)
{}

Vector3D &Vector3D::operator+=(const Vector3D &otherVector)
{
    x += otherVector.x;
    y += otherVector.y;
    z += otherVector.z;
    return *this;
}

Vector3D &Vector3D::operator-=(const Vector3D &otherVector)
{
    x -= otherVector.x;
    y -= otherVector.y;
    z -= otherVector.z;
    return *this;
}

Vector3D &Vector3D::operator*=(const float &scalar)
{
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}

Vector3D &Vector3D::operator/=(const float &scalar)
{
    x /= scalar;
    y /= scalar;
    z /= scalar;
    return *this;
}

float Vector3D::magnitude() const
{
    return (std::sqrt(x * x + y * y + z * z));
}

Vector3D &Vector3D::cross(const Vector3D &other)
{
    float nx, ny, nz;

    nx = y * other.z - z * other.y;
    ny = z * other.x - x * other.z;
    nz = x * other.y - y * other.x;

    x = nx;
    y = ny;
    z = nz;

    return *this;
}

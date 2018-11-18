//
// Created by Sam on 11/17/2018.
//

#ifndef GRAPHICAL_MATH_VECTOR3D_H
#define GRAPHICAL_MATH_VECTOR3D_H

#include <iosfwd>
#include <sstream>

struct Vector3D
{
    Vector3D();
    Vector3D(float a, float b, float c);
    Vector3D(const Vector3D &vector3d);

    Vector3D &operator+=(const Vector3D &otherVector);

    Vector3D &operator-=(const Vector3D &otherVector);

    Vector3D &operator*=(const float &scalar);

    Vector3D &operator/=(const float &scalar);

    float magnitude() const;

    friend std::ostream &operator<<(std::ostream &, const Vector3D &);

    float x;
    float y;
    float z;
};

inline bool operator==(const Vector3D &a, const Vector3D &b)
{
    return (a.x == b.x && a.y == b.y && a.z == b.z);
}

inline Vector3D operator+(const Vector3D &a, const Vector3D &b)
{
    return (Vector3D(a.x + b.x, a.y + b.y, a.z + b.z));
}

inline Vector3D operator-(const Vector3D &a, const Vector3D &b)
{
    return (Vector3D(a.x - b.x, a.y - b.y, a.z - b.z));
}

inline Vector3D operator*(const Vector3D &vector, const float &scalar)
{
    return (Vector3D(vector.x * scalar, vector.y * scalar, vector.z * scalar));
}

inline Vector3D operator/(const Vector3D &vector, const float &scalar)
{
    return (Vector3D(vector.x / scalar, vector.y / scalar, vector.z / scalar));
}

inline Vector3D operator-(const Vector3D &v)
{
    return (Vector3D(-v.x, -v.y, -v.z));
}

inline Vector3D Normalize(const Vector3D &v)
{
    return (v / v.magnitude());
}

inline std::ostream &operator<<(std::ostream &stream, const Vector3D &v)
{
    return stream << "Vector3D(x: " << v.x << ", y: " << v.y << ", z: " << v.z << ");";
}

#endif //GRAPHICAL_MATH_VECTOR3D_H

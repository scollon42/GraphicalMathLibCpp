//
// Created by scollon on 17/11/18.
//

#include "Matrix3D.h"

Matrix3D::Matrix3D(float n00, float n01, float n02, float n10, float n11, float n12, float n20, float n21, float n22) {
    n[0][0] = n00;
    n[0][1] = n01;
    n[0][2] = n02;
    n[1][0] = n10;
    n[1][1] = n11;
    n[1][2] = n12;
    n[2][0] = n20;
    n[2][1] = n21;
    n[2][2] = n22;
}

Matrix3D::Matrix3D(const Vector3D &a, const Vector3D &b, const Vector3D &c) {
    n[0][0] = a.x;
    n[0][1] = a.y;
    n[0][2] = a.z;
    n[1][0] = b.x;
    n[1][1] = b.y;
    n[1][2] = b.z;
    n[2][0] = c.x;
    n[2][1] = c.y;
    n[2][2] = c.z;
}

float &Matrix3D::operator()(int i, int j) {
    return n[i][j];
}

const float &Matrix3D::operator()(int i, int j) const {
    return n[i][j];
}

Vector3D &Matrix3D::operator[](int i) {
    return (*reinterpret_cast<Vector3D *>(n[i]));
}

const Vector3D &Matrix3D::operator[](int i) const {
    return (*reinterpret_cast<const Vector3D *>(n[i]));
}


Matrix3D &Matrix3D::operator+=(const Matrix3D &other) {
    for (auto i = 0; i < 3; i++) {
        n[i][0] += other(i, 0);
        n[i][1] += other(i, 1);
        n[i][2] += other(i, 2);
    }

    return *this;
}

Matrix3D &Matrix3D::operator-=(const Matrix3D &other) {
    for (auto i = 0; i < 3; i++) {
        n[i][0] -= other(i, 0);
        n[i][1] -= other(i, 1);
        n[i][2] -= other(i, 2);
    }

    return *this;
}

Matrix3D &Matrix3D::operator*=(const float &scalar) {
    for (auto &e : n) {
        e[0] *= scalar;
        e[1] *= scalar;
        e[2] *= scalar;
    }

    return *this;
}

Matrix3D &Matrix3D::operator/=(const float &scalar) {
    for (auto &e : n) {
        e[0] /= scalar;
        e[1] /= scalar;
        e[2] /= scalar;
    }

    return *this;
}

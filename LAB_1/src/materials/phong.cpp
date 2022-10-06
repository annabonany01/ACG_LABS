#include "phong.h"
#include <iostream>


Phong::Phong()
{ }

Phong::Phong(Vector3D kd_, Vector3D ks_):
    Material(), kd(kd_), ks(ks_)
{ }

double Phong::getIndexOfRefraction() const
{
    std::cout << "Warning! Calling \"Material::getIndexOfRefraction()\" for a non-transmissive material"
              << std::endl;

    return -1;
}

Vector3D Phong::getReflectance(const Vector3D &n, const Vector3D &wo, const Vector3D &wi) const
{
    // ωr =2(n·ωi)n−ωi
    Vector3D wr = Vector3D(2.0) * dot(n, wi) - wi;
    // r(ωi,ωo)=kd(ωi ·n)+ks(ωo ·ωr)n,
    Vector3D reflectance = kd * dot(wi, n) + ks * dot(wo, wr) * n;

    return reflectance;
}

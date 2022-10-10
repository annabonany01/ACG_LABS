#include "phong.h"
#include <iostream>

#include "../core/utils.h"


Phong::Phong(const Vector3D& kd_, const Vector3D& ks_, const double s_):
    Material(), kd(kd_), ks(ks_), s(s_)
{ }

double Phong::getIndexOfRefraction() const
{
    std::cout << "Warning! Calling \"Material::getIndexOfRefraction()\" for a non-transmissive material"
              << std::endl;

    return -1;
}

Vector3D Phong::getReflectance(const Vector3D &n, const Vector3D &wo, const Vector3D &wi) const
{
    Vector3D wr = Utils::computeReflectionDirection(wi, n);
    Vector3D reflectance = kd * dot(wi, n) + ks * pow(dot(wo, wr), s);

    return reflectance;
}

bool Phong::hasSpecular() const
{
    return false;
}

bool Phong::hasTransmission() const
{
    return false;
}

bool Phong::hasDiffuseOrGlossy() const
{
    return true;
}
#ifndef PHONG
#define PHONG

#include "material.h"

class Phong : public Material
{
public:
    Phong() = delete;
    Phong(const Vector3D &kd_, const Vector3D &ks_, double s_);

    Vector3D getReflectance(const Vector3D &n, const Vector3D &wo,
                            const Vector3D &wi) const;
    bool hasSpecular() const;
    bool hasTransmission() const;
    bool hasDiffuseOrGlossy() const;
    double getIndexOfRefraction() const;

    Vector3D kd;      // diffuse color
    Vector3D ks;      // specular color
    double s;       // shininess coefficient (roughness)
};


#endif // PHONG

#ifndef PHONG
#define PHONG

#include "../core/vector3d.h"
#include "material.h"

class Phong : public Material
{
public:
    Phong();
    Phong(Vector3D kd_, Vector3D ks_);

    virtual Vector3D getReflectance(const Vector3D &n, const Vector3D &wo,
                                    const Vector3D &wi) const = 0;
    virtual bool hasSpecular() const = 0;
    virtual bool hasTransmission() const = 0;
    virtual bool hasDiffuseOrGlossy() const = 0;
    virtual double getIndexOfRefraction() const;

    Vector3D kd;      // diffuse color
    Vector3D ks;      // specular color
    //Vector3D n;       // shininess coefficient (roughness)
};


#endif // PHONG

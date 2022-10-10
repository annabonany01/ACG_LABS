#ifndef NORMALSHADER_H
#define NORMALSHADER_H

#include "shader.h"

class NormalShader : public Shader
{
public:
    NormalShader();
    NormalShader(Vector3D color_, double maxDist_, Vector3D bgColor_);

    virtual Vector3D computeColor(const Ray &r,
                             const std::vector<Shape*> &objList,
                             const std::vector<PointLightSource> &lsList) const;


    double maxDist;
    Vector3D color;
};


#endif // NORMALSHADER_H

#ifndef DEPTHSHADER_H
#define DEPTHSHADER_H

#include "shader.h"

class DepthShader : public Shader
{
public:
    DepthShader();
    DepthShader(Vector3D color_, double maxDist_, Vector3D bgColor_);

    virtual Vector3D computeColor(const Ray &r,
                             const std::vector<Shape*> &objList,
                             const std::vector<PointLightSource> &lsList) const;


    double maxDist;
    Vector3D color;
};


#endif // DEPTHSHADER_H

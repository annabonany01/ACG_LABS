#include "normalshader.h"
#include "../core/utils.h"

NormalShader::NormalShader():
    color(Vector3D(0, 1, 0))
{ }

NormalShader::NormalShader(Vector3D color_, double maxDist_, Vector3D bgColor_):
    Shader(bgColor_), color(color_), maxDist(maxDist_)
{ }

Vector3D NormalShader::computeColor(const Ray &r, const std::vector<Shape*> &objList, const std::vector<PointLightSource> &lsList) const
{
    Intersection its;
    if (Utils::getClosestIntersection(r, objList, its))
    {
        Vector3D its_normal = its.normal;
        return (its_normal+Vector3D(1.0)) / 2.0;
    }
    else
        return bgColor;
}

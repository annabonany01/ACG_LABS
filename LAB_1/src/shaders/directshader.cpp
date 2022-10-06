#include "directshader.h"
#include "../core/utils.h"

DirectShader::DirectShader():
    color(Vector3D(0, 1, 0))
{ }

DirectShader::DirectShader(Vector3D color_, double maxDist_, Vector3D bgColor_):
    Shader(bgColor_), color(color_), maxDist(maxDist_)
{ }

Vector3D DirectShader::computeColor(const Ray &r, const std::vector<Shape*> &objList, const std::vector<PointLightSource> &lsList) const
{
    Intersection its;
    if (Utils::getClosestIntersection(r, objList, its))
    {
        double hitDistance = (its.itsPoint - r.o).length();
        if (hitDistance >= maxDist)
            return bgColor;
        else
            return color * fmax(1.0 - hitDistance/maxDist, 0);
    }
    else
        return bgColor;
}

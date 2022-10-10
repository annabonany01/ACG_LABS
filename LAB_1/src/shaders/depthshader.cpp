#include "depthshader.h"
#include "../core/utils.h"

DepthShader::DepthShader():
    color(Vector3D(0, 1, 0))
{ }

DepthShader::DepthShader(Vector3D color_, double maxDist_, Vector3D bgColor_):
    Shader(bgColor_), color(color_), maxDist(maxDist_)
{ }

Vector3D DepthShader::computeColor(const Ray &r, const std::vector<Shape*> &objList, const std::vector<PointLightSource> &lsList) const
{
    Intersection its;
    if (Utils::getClosestIntersection(r, objList, its))
    {
        double hitDistance = (its.itsPoint - r.o).length();
        return color * fmax(1.0 - hitDistance/maxDist, 0);
    }
    else
        return bgColor;
}

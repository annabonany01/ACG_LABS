#include "directshader.h"
#include "../core/utils.h"
#include <iostream>


DirectShader::DirectShader(const Vector3D& bgColor_):
    Shader(bgColor_)
{ }

Vector3D DirectShader::computeColor(const Ray &r, const std::vector<Shape*> &objList, const std::vector<PointLightSource> &lsList) const
{
    Intersection its;
    Vector3D new_color = Vector3D(0.0);

    if (Utils::getClosestIntersection(r, objList, its))
    {
        if (its.shape->getMaterial().hasDiffuseOrGlossy())
        {
            Vector3D wo = (r.o - its.itsPoint).normalized();

            for (const auto& light : lsList)
            {
                Vector3D wi = (light.getPosition() - its.itsPoint).normalized();
                Vector3D Li = light.getIntensity(its.itsPoint);

                Ray rr;
                rr.o = its.itsPoint;
                rr.d = wi;
                rr.depth = 0.0;
                rr.minT = Epsilon;
                rr.maxT = (light.getPosition() - its.itsPoint).length();

                if (!Utils::hasIntersection(rr, objList))
                {
                    Vector3D wr = its.shape->getMaterial().getReflectance(its.normal, wo, wi);
                    //std::cout << " " << wr; break;
                    new_color += Li * wr;
                }
            }
        }
        return new_color;
    }
    else
        return bgColor;
}



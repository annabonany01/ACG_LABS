#include "depthshader.h"
#include "../core/utils.h"


DepthShader::DepthShader(Vector3D color_, double maxDist_, Vector3D bgColor_) :
	Shader(bgColor_), color(color_), maxDist(maxDist_)
{ }

Vector3D DepthShader::computeColor(const Ray& r, const std::vector<Shape*>& objList, const std::vector<PointLightSource>& lsList) const 
{
	Intersection its;
    if (Utils::getClosestIntersection(r, objList, its)) {
        Vector3D distAux = its.itsPoint - r.o;
		double dist = distAux.length();

		if (dist >= maxDist) {
			return bgColor;
		}
		else {
			return color * (1.0 - dist / maxDist);
		}
	}
	else
	{
		return bgColor;
	}
}

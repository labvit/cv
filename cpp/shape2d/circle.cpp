#include "vmath.h"
#include "icontext.hpp"
#include "circle.hpp"
#include <cmath>

#define M_PI2 (M_PI * 2)

#define MAX_PRECISION 100
void Circle::draw(const IContext2D* ctx) const{
	if(r>0 && precision < MAX_PRECISION)
	{
		vec2_t points[precision+1];
		float phi_step = M_PI2/float(precision-1);
		for(int i = 0; i <= precision; i++)
		{
			points[i].x = std::cos(phi_step * i) * r + center.x;
			points[i].y = std::sin(phi_step * i) * r + center.y;
		}
		ctx->draw_polyline(points, precision);
	}
}

Circle::~Circle() 
{

}

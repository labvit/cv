#include <vector>
#include "vmath.h"
#include "icontext.hpp"
#include "ishape.hpp"
#include "bezier_curve.hpp"

Bezier::~Bezier(){}

#include <iostream>
vec2_t&& Bezier::deCasteljau(float dt) const{
	std::vector<vec2_t> pointsQ; 
	auto size = control_points.size();

	pointsQ.reserve(size);
	for(int j = 0; j < size; j++){
	  pointsQ.push_back(control_points[j]);
	}

	for(int k = 1; k < size; k++){
	  for(int j = 0; j< size - k; j++){
	    pointsQ[j].x = (1-dt) * pointsQ[j].x + dt * pointsQ[(j+1)].x;
	    pointsQ[j].y = (1-dt) * pointsQ[j].y + dt * pointsQ[(j+1)].y;
	  }
	}
	vec2_t * result = new vec2_t();
	result->x = pointsQ[0].x;
	result->y = pointsQ[1].y;
	//std::cout << result->x << " " << result->y << std::endl;
	return std::move(*result);
} 


std::vector<vec2_t> Bezier::draw_bezier() const
{
	std::vector<vec2_t> curve_points;
	for(int i = 0; i <= precision; i++) {
	  float dt = float(i)/float(precision);
	  curve_points.emplace_back(
	    deCasteljau(dt));
	}

	return curve_points;
}

void Bezier::draw(const IContext2D* ctx) const 
{
	if(control_points.size()>0 )
	{
	  auto points = draw_bezier();
	  if(points.size()>2)
	    ctx->draw_polyline(&points[0], points.size());
	}
}
#include "vmath.h"
#include "box.hpp"
#include "icontext.hpp"
Box::~Box(){}

void Box::draw(const IContext2D* ctx) const  {
  float h2=height/2e0;
  float w2=width/2e0;
  /// clockwise
  vec2_t points[5] = { 
    vec2_t{center.x + w2, center.y + h2},
    vec2_t{center.x + w2, center.y - h2},
    vec2_t{center.x - w2, center.y - h2},
    vec2_t{center.x - w2, center.y + h2},
    vec2_t{center.x + w2, center.y + h2},
  };

  ctx->draw_polyline(points, 5);
}

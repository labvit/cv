#ifndef GLContext_HPP
#define GLContext_HPP
#include "icontext.hpp"

class GLContext : public IContext2D
{
public:
  void draw_line(float x1, float y1, float x2, float y2) override;

  void draw_polyline(const vec2_t* vectors, int size) const override;
  
  ~GLContext()override; 
};

#endif
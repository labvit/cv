#ifndef CONTEXT_HPP
#define CONTEXT_HPP

class IContext2D
{
public:

  virtual void draw_line(float x1,float y1,float x2,float y2) = 0;
  // virtual void draw_polyline(vec2_t* points, int size) = 0;
  virtual void draw_polyline(const vec2_t* points, int size) const = 0;
  virtual ~IContext2D()=0;
};

#endif
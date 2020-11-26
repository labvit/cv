#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "ishape.hpp"

class Circle : public IShape{
public:
  
  // detailization
  int precision{30};

  // central point
  vec2_t center;

  // radius
  float r;

  virtual void draw(const IContext2D*) const override;
  ~Circle() override;

};

#endif
#ifndef BOX_HPP
#define BOX_HPP

#include "ishape.hpp"

class Box : public IShape
{
public:

  ~Box() override;
  void draw(const IContext2D* ctx) const override;

  vec2_t center{0.0f,0.0f};

  float height{0.0f};
  float width{0.0f};
  
};


#endif
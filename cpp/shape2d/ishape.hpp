#ifndef ISHAPE_HPP
#define ISHAPE_HPP

class IContext2D;
/// interface
class IShape{
public:
  // virtual void draw(IContext2D*) = 0;
  virtual void draw(const IContext2D*) const = 0;
  virtual ~IShape() = 0;
};

#endif
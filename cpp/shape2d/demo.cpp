#include <vector>
#include <memory>
#include "vmath.h"

#include "ishape.hpp"
#include "circle.hpp"
#include "box.hpp"
#include "bezier_curve.hpp" 
#include "demo.hpp"


void DemoScene::Init(){

  auto box = std::make_unique<Box>();
  box->height =1;
  box->width = 1;
  box->center = {1e0f, 0e0f};

  auto box2 = std::make_unique<Box>();
  box2->height =1;
  box2->width = 1;
  box2->center = {0e0f, 1e0f};

  auto curve = std::make_unique<Bezier>();
  curve->precision = 10;
  curve->control_points.emplace_back(vec2_t{0e0f, 0e0f});
  curve->control_points.emplace_back(vec2_t{3e0f, 1e0f});
  curve->control_points.emplace_back(vec2_t{1e0f, 0e0f});

  auto face = std::make_unique<Circle>();
  face->center.x = 0;
  face->center.y = 0;
  face->r = 2;

  auto eyeL = std::make_unique<Circle>();
  eyeL->center.x = -0.;
  eyeL->center.y = 0.;
  eyeL->r = .3;
  auto eyeR = std::make_unique<Circle>();
  eyeR->center.x = 1.;
  eyeR->center.y = 1.;
  eyeR->r = .3;

  auto earL = std::make_unique<Circle>();
  eyeL->center.x = -.3;
  eyeL->center.y = .3;
  eyeL->r = .7;
  auto earR = std::make_unique<Circle>();
  eyeR->center.x = .3;
  eyeR->center.y = .3;
  eyeR->r = .7;
  
  _shapes.emplace_back(std::move(box));
  _shapes.emplace_back(std::move(box2));
  _shapes.emplace_back(std::move(curve));
  _shapes.emplace_back(std::move(face));
  _shapes.emplace_back(std::move(eyeL));
  _shapes.emplace_back(std::move(eyeR));
  _shapes.emplace_back(std::move(earL));
  _shapes.emplace_back(std::move(earR));
}

void DemoScene::Draw(IContext2D* ctx){
    for(auto& shape : _shapes)
      shape->draw(ctx);
}

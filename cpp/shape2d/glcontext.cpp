#include "vmath.h"

#include "glcontext.hpp"
#include "GL/gl.h"
GLContext::~GLContext(){} 

void GLContext::draw_line(float x1, float y1, float x2, float y2) 
{
  float color[3] = {.5f,1.,0.2f};
  glPushMatrix();
  glLineWidth(2.f);
  glBegin(GL_LINE_STRIP);
    glColor3fv(color);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
  glEnd();
  glPopMatrix();
}


void GLContext::draw_polyline(const vec2_t* vectors, int size) const
{
  float color[3] = {.5f,1.,0.2f};
  glPushMatrix();
  glLineWidth(2.f);
  glBegin(GL_LINE_STRIP);
    glColor3fv(color);
    for(int i =0 ; i < size; i++)
    {
      const GLfloat* v = &vectors[i].x;
      glVertex2fv(v);
    }
  glEnd();
  glPopMatrix(); 
}

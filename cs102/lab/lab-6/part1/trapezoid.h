#ifndef TRAPEZOID_H_
#define TRAPEZOID_H_

#include "shape.h"

class Trapezoid : public Shape {

  private:
    int lenght;
    int width;
    int height;

  public:
    Trapezoid(int l, int w, int h, int x, int y);

    int getLenght() const;
    void setLenght(int l);
    int getWidth() const;
    void setWidth(int w);

    virtual std::string getType() const;
};

#endif

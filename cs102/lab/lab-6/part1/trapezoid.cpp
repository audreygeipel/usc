#include "trapezoid.h"

using namespace std;

Trapezoid::Trapezoid(int l, int w, int h, int x, int y) : Shape(x,y), lenght(l), width(w){
  height = h;
}

string Trapezoid::getType() const {
  return "Trapezoid";
}

int Trapezoid::getLenght() const {
  return lenght;
}

void Trapezoid::setLenght(int l) {
  lenght = l;
}

int Trapezoid::getWidth() const {
  return width;
}

void Trapezoid::setWidth(int w) {
  width = w;
}


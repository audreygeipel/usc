#include <iostream>
#include "shape.h"
#include "rectangle.h"
#include "trapezoid.h"

using namespace std;

void print(const Shape &s) {
	cout << "I am a " << s.getType() << "!" << endl;
	cout << "My perimeter is " << s.getPerimeter() << "!" << endl;
}

int main()
{
	Trapezoid t(1, 1, 1, 1, 1);
	Rectangle r(3, 8, 0, 0);

  print(t);
  print(r);
}

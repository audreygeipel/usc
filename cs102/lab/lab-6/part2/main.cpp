#include <iostream>
#include "shape.h"
#include "rectangle.h"
#include "trapezoid.h"

using namespace std;

int main()
{
	Trapezoid r(5, 5, 4, 0, 0);
	cout << "I am a " << r.getType() << "!" << endl;
}

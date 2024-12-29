#pragma once
#include "SDL.h"

class Circle
{
private:
	double radius;
	double x; // the x-value of the center of the circle
	double y; // the y-value of the center of the circle
public:
	Circle(double, double, double);

	void draw(SDL_Surface*);
};


#pragma once
#include "SDL.h"

class Circle
{
private:
	double radius;
	double x, y; // the x and y-value of the center of the circle

	double vx, vy;  // the x and y velocities of the circle
public:
	Circle(double, double, double);

	void draw(SDL_Surface*);
	void update(int, int);

	/* physics */
	void gravity();
	void wallCollisions(int, int);
	void bounceX();
	void bounceY();
};


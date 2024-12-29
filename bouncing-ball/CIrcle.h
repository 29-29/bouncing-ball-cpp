#pragma once
#include "SDL.h"
#include "Vector2.h"

class Circle
{
private:
	double radius;
	Vector2 <double> position; // the position of the center of the circle

	Vector2 <double> velocity; // the velocity of the circle
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


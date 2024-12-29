#include "Circle.h"
#include <math.h>

Circle::Circle(double x_, double y_, double r_)
{
	this->x = x_;
	this->y = y_;
	this->radius = r_;
}

double
dist(double x1, double y1, double x2, double y2)
{
	return fabs(sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

void
Circle::draw(SDL_Surface* surface)
{
	double lowX = this->x - this->radius;
	double lowY = this->y - this->radius;
	double highX = this->x + this->radius;
	double highY = this->y + this->radius;

	for (double x = lowX; x <= highX; x++)
	{
		for (double y = lowY; y < highY; y++)
		{
			SDL_Rect pixel = { int(x), int(y), 1, 1};
			if (dist(x, y, this->x, this->y) < this->radius)
				SDL_FillRect(surface, &pixel, 0xffffffff);
		}
	}
}

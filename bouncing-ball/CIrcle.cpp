#include "Circle.h"
#include <math.h>

Circle::Circle(double x_, double y_, double r_)
{
	this->x = x_;
	this->y = y_;
	this->radius = r_;

	this->vx = 10;
	this->vy = 0;
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

void
Circle::update(int sw, int sh)
{
	this->gravity();

	/* updating position with velocity */
	this->x += this->vx;
	this->y += this->vy;

	this->wallCollisions(sw, sh);
}

void
Circle::gravity()
{
	this->vy += 1;
}

void
Circle::wallCollisions(int screenWidth, int screenHeight)
{
	// left wall
	if (this->x - this->radius < 0)
	{
		this->x = this->radius;
		bounceX();
	}
	// right wall
	if (this->x + this->radius > screenWidth)
	{
		this->x = screenWidth - this->radius;
		bounceX();
	}
	// bottom wall
	if (this->y + this->radius > screenHeight)
	{
		this->y = screenHeight - this->radius;
		bounceY();
	}
	// upper wall
	if (this->y - this->radius < 0)
	{
		this->y = this->radius;
		bounceY();
	}
}

void
Circle::bounceX()
{
	this->vx *= -1;
}

void
Circle::bounceY()
{
	this->vy *= -1;
}

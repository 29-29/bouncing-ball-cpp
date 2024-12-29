#include "Circle.h"
#include <math.h>

Circle::Circle(double x_, double y_, double r_)
{
	this->position = Vector2<double>{ x_, y_ };
	this->radius = r_;

	this->velocity = Vector2<double>{ 12, 0 };
}

void
Circle::draw(SDL_Surface* surface)
{
	double lowX = this->position.x - this->radius;
	double lowY = this->position.y - this->radius;
	double highX = this->position.x + this->radius;
	double highY = this->position.y + this->radius;

	for (double x = lowX; x <= highX; x++)
	{
		for (double y = lowY; y < highY; y++)
		{
			SDL_Rect pixel = { int(x), int(y), 1, 1};
			double distance = fabs(sqrt(pow(x - this->position.x, 2) + pow(y - this->position.y, 2))); /* the distance of the point from the center of the circle. */
			if (distance < this->radius)
				SDL_FillRect(surface, &pixel, 0xffffffff);
		}
	}
}

void
Circle::update(int sw, int sh)
{
	this->gravity();

	/* updating position with velocity */
	this->position.x += this->velocity.x;
	this->position.y += this->velocity.y;

	this->wallCollisions(sw, sh);
}

void
Circle::gravity()
{
	this->velocity.y += 1;
}

void
Circle::wallCollisions(int screenWidth, int screenHeight)
{
	bool collideLeft = this->position.x - this->radius < 0;
	bool collideRight = this->position.x + this->radius > screenWidth;
	bool collideUp = this->position.y - this->radius < 0;
	bool collideDown = this->position.y + this->radius > screenHeight;
	// left wall
	if (collideLeft)
	{
		this->position.x = this->radius;
		bounceX();
	}
	// right wall
	if (collideRight)
	{
		this->position.x = screenWidth - this->radius;
		bounceX();
	}
	// bottom wall
	if (collideDown)
	{
		this->position.y = screenHeight - this->radius;
		bounceY();
	}
	// upper wall
	if (collideUp)
	{
		this->position.y = this->radius;
		bounceY();
	}
}

void
Circle::bounceX()
{
	this->velocity.x *= -1;
}

void
Circle::bounceY()
{
	this->velocity.y *= -1;
}

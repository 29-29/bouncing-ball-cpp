#include "Vector2.h"

template <class T>
void
Vector2<T>::add(const Vector2<T>& other)
{
	this->x += other.x;
	this->y += other.y;
}

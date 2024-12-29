#pragma once
template <class T>
class Vector2
{
public:
	T x;
	T y;

	void add(const Vector2<T>&);
};


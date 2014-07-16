#ifndef VEC2_H
#define VEC2_H


struct Vec2
{
	float x;
	float y;

	Vec2(float x = 0.0, float y = 0.0) : x(x), y(y)
	{}
};

inline const Vec2 operator-(const Vec2& vec)
{
	return Vec2(-vec.x, -vec.y);
}

inline const Vec2 operator-(const Vec2& lhs, const Vec2 rhs)
{
	return Vec2(lhs.x - rhs.x, lhs.y - rhs.y);
}

inline const Vec2 operator+(const Vec2& lhs, const Vec2 rhs)
{
	return Vec2(lhs.x + rhs.x, lhs.y + rhs.y);
}

inline void operator+=(Vec2& lhs, const Vec2 rhs)
{
	lhs.x += rhs.x; 
	lhs.y += rhs.y;
}

inline const Vec2 operator*(const Vec2& lhs, float multiplier)
{
	return Vec2(lhs.x * multiplier, lhs.y * multiplier);
}

inline const Vec2 operator/(const Vec2& lhs, float multiplier)
{
	return Vec2(lhs.x / multiplier, lhs.y / multiplier);
}

inline bool operator!=(const Vec2& lhs, const Vec2& rhs)
{
	return (lhs.x != rhs.x && lhs.y != rhs.y);
}

inline bool operator==(const Vec2& lhs, const Vec2& rhs)
{
	return (lhs.x == rhs.x && lhs.y == rhs.y);
}


#endif
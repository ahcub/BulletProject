#ifndef MATH_UTILS_H
#define MATH_UTILS_H

struct Vec2;

namespace MathUtils
{
	float get_vector_multiplier(const Vec2& start, const Vec2& end);
	bool is_existst_intersection_point(Vec2* result, const Vec2& start1, const Vec2& end1, const Vec2& start2, const Vec2& end2);
	float length(const Vec2& x);
	float distance(const Vec2& first, const Vec2& second);
	float dot(const Vec2& first, const Vec2& second);
	Vec2 reflect(const Vec2& first, const Vec2& second);
	Vec2 normalize(const Vec2& vec);
}

#endif
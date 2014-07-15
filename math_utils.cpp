#include "math_utils.h"
#include "vec2.h"

#include <math.h>

inline float MathUtils::get_vector_multiplier(const Vec2& start, const Vec2& end)
{
	return start.x * end.y - start.y * end.x;
}


bool MathUtils::is_existst_intersection_point(Vec2* result, const Vec2& start1, const Vec2& end1, const Vec2& start2, const Vec2& end2)
{
	Vec2 first_vector_len = start1 - end1;
	Vec2 second_vector_len = start2 - end2;


	float c = get_vector_multiplier(first_vector_len, second_vector_len);

	if (fabs(c) < 0.01)
		return false;
	else
	{
		float a = get_vector_multiplier(start1, end1);
		float b = get_vector_multiplier(start2, end2);

		result->x = (a * second_vector_len.x - b * first_vector_len.x) / c;
		result->y = (a * second_vector_len.y - b * first_vector_len.y) / c;

		return true;
	}
}

float MathUtils::length(const Vec2& vec)
{
	float sqr = vec.x * vec.x + vec.y * vec.y;
	return sqrt(sqr);
}

float MathUtils::distance(const Vec2& first, const Vec2& second)
{
	return length(first - second);
}

float MathUtils::dot(const Vec2& first, const Vec2& second)
{
	return first.x * second.x + first.y * second.y;
}

Vec2 MathUtils::reflect(const Vec2& first, const Vec2& second)
{
	return first - second * dot(second, first) * 2;
}

Vec2 MathUtils::normalize(const Vec2& vec)
{
	float inverse_sqrt = 1 / length(vec);
	return vec * inverse_sqrt;
}

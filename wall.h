#ifndef WALL_H
#define WALL_H

#include "vec2.h"

struct Wall
{
	Vec2 start;
	Vec2 end;

	Wall::Wall(float x_start, float y_start, float x_end, float y_end) : start(x_start, y_start),
																		 end(x_end, y_end)
	{}
};

#endif

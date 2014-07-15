#ifndef BULLET_H
#define BULLET_H

#include "vec2.h"

struct Wall;

class Bullet
{
	Vec2 position;
	Vec2 velocity;

public:
	Bullet(float x_pos, float y_pos, float x_velocity, float y_velocity);
	void update_position(float delta_time);
	void update_position(const Vec2& new_position);
	void reflect_velocity_vector(const Wall& collition_wall);
	const Vec2& get_current_pos() const;
	Vec2 get_future_pos(float delta_time) const;
};

#endif
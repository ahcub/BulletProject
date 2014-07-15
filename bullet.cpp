#include "bullet.h"
#include "wall.h"
#include "math_utils.h"

using MathUtils::length;
using MathUtils::reflect;
using MathUtils::normalize;

Bullet::Bullet(float x_pos, float y_pos, float x_velocity, float y_velocity)
{
	this->position = Vec2(x_pos, y_pos);
	this->velocity = Vec2(x_velocity, y_velocity);
}

void Bullet::update_position(float delta_time)
{
	this->position += this->velocity * delta_time;
}

void Bullet::update_position(const Vec2& new_position)
{
	this->position = new_position;
}

const Vec2& Bullet::get_current_pos() const
{
	return this->position;
}

Vec2 Bullet::get_future_pos(float delta_time) const
{
	return this->position + this->velocity * delta_time;
}

void Bullet::reflect_velocity_vector(const Wall& collition_wall)
{
	Vec2 collision_vector = normalize(collition_wall.start - collition_wall.end);
	Vec2 veclocity_vector = normalize(-this->velocity);

	Vec2 reflected_vector = reflect(veclocity_vector, collision_vector);
	float velocity_vector_length = length(this->velocity);
	this->velocity = reflected_vector * velocity_vector_length;
}
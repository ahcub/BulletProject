#include "bullet_manager.h"
#include "vec2.h"
#include "math_utils.h"

using MathUtils::is_existst_intersection_point;
using MathUtils::distance;


void BulletManager::add_bullet(float x_pos, float y_pos, float x_direction, float y_direction)
{
	this->bullets.push_back(Bullet(x_pos, y_pos, x_direction, y_direction));
}

void BulletManager::add_wall(float x_start, float y_start, float x_end, float y_end)
{
	this->walls.push_back(Wall(x_start, y_start, x_end, y_end));
}

void BulletManager::update(float delta_time)
{
	for (vector<Bullet>::iterator bullets_it = bullets.begin(); bullets_it != bullets.end(); ++bullets_it)
	{
		update_bullet(bullets_it, delta_time);
	}
}

void BulletManager::update_bullet(vector<Bullet>::iterator bullets_it, float delta_time)
{
	vector<Wall>::iterator closest_wall = walls.end();
	Vec2 intersection_point;
	float closest_distance = 0;
	Vec2 bullet_future_position = bullets_it->get_future_pos(delta_time);
	for (vector<Wall>::iterator walls_it = walls.begin(); walls_it != walls.end(); ++walls_it)
	{
		if (is_existst_intersection_point(&intersection_point, bullets_it->get_current_pos(), bullet_future_position,
										  walls_it->start, walls_it->end) && 
			(intersection_point != bullets_it->get_current_pos()))
		{
			float distance_to_wall = distance(bullets_it->get_current_pos(), intersection_point);
			if (!closest_distance || closest_distance > distance_to_wall)
			{
				closest_distance = distance_to_wall;
				closest_wall = walls_it;
			}
		}
	}
	if (closest_wall != walls.end())
	{
		float processed_time_coef = closest_distance / distance(bullets_it->get_current_pos(), bullet_future_position);
		float delta_time_left = delta_time - delta_time * processed_time_coef;
		bullets_it->update_position(intersection_point);
		bullets_it->reflect_velocity_vector(*closest_wall);
		this->update_bullet(bullets_it, delta_time_left);
	}
	else
		bullets_it->update_position(delta_time);
}

const vector<Bullet>& BulletManager::get_bullets()
{
	return this->bullets;
}
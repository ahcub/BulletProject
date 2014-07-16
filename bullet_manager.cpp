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
	for each (Bullet bullet in bullets)
		update_bullet(&bullet, delta_time);
	
}

void BulletManager::update_bullet(Bullet* bullet, float delta_time)
{
	Wall* closest_wall = 0;
	Vec2 intersection_point;
	float closest_distance = 0;
	Vec2 bullet_future_position = bullet->get_future_pos(delta_time);
	
	for each (Wall wall in walls)
	{
		if (is_existst_intersection_point(&intersection_point, bullet->get_current_pos(), bullet_future_position,
			wall.start, wall.end) &&
			(intersection_point != bullet->get_current_pos()))
		{
			float distance_to_wall = distance(bullet->get_current_pos(), intersection_point);
			if (!closest_distance || closest_distance > distance_to_wall)
			{
				closest_distance = distance_to_wall;
				closest_wall = &wall;
			}
		}
	}
	
	if (closest_wall)
	{
		float processed_time_coef = closest_distance / distance(bullet->get_current_pos(), bullet_future_position);
		float delta_time_left = delta_time - delta_time * processed_time_coef;
		bullet->update_position(intersection_point);
		bullet->reflect_velocity_vector(*closest_wall);
		this->update_bullet(bullet, delta_time_left);
	}
	else
		bullet->update_position(delta_time);
}

const vector<Bullet>& BulletManager::get_bullets()
{
	return this->bullets;
}

const vector<Wall>& BulletManager::get_walls()
{
	return this->walls;
}

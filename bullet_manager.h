#ifndef BULLET_MANAGER_H
#define BULLET_MANAGER_H

#include "bullet.h"
#include "wall.h"

#include <vector>

using std::vector;

class BulletManager
{
	vector<Bullet> bullets;
	vector<Wall> walls;

	void update_bullet(vector<Bullet>::iterator bullets_it, float delta_time);

public:
	void add_bullet(float x_pos, float y_pos, float x_direction, float y_direction);
	void add_wall(float x_start, float y_start, float x_end, float y_end);
	void update(float delta_time);

	const vector<Bullet>& get_bullets();
};

#endif
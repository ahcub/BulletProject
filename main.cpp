#include "bullet_manager.h"
#include "bullet.h"
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main()
{
	BulletManager bullet_manager;

	bullet_manager.add_bullet(1.0, 1.0, 2.0, 2.0);

	bullet_manager.add_wall(1.0, 2.0, 3.0, 1.0);

	for (vector<Bullet>::const_iterator it = bullet_manager.get_bullets().begin(); it != bullet_manager.get_bullets().end(); ++it)
	{
		cout << it->get_current_pos().x << " " << it->get_current_pos().y << endl;
	}

	bullet_manager.update(1.0);

	for (vector<Bullet>::const_iterator it = bullet_manager.get_bullets().begin(); it != bullet_manager.get_bullets().end(); ++it)
	{
		cout << it->get_current_pos().x << " " << it->get_current_pos().y << endl;
	}


}



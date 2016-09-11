#include <SFML/Graphics.hpp>
using namespace sf;
float offsetX = 0, offsetY = 0;

class PLAYER {

public:

	float dx, dy;
	FloatRect rect;
	bool onGround;
	Sprite sprite;
	float currentFrame;
	int count, health;
	bool life;

	PLAYER(Texture &image)
	{
		sprite.setTexture(image);
		rect = FloatRect(1 * 34, 1 * 34, 20, 34);
		dx = dy = 0.1;
		currentFrame = 0;
		count = 0;
		health = 3;
		life = true;
	}
	void update(float time)
	{
		rect.left += dx * time;
		Collision(0);

		if (!onGround) dy = dy + 0.0005*time;
		rect.top += dy*time;
		onGround = false;
		Collision(1);


		currentFrame += time * 0.005;
		if (currentFrame > 6) currentFrame -= 6;

		if (dx > 0)sprite.setTextureRect(IntRect(20 * int(currentFrame), 0, 20, 34));//анимация
		if (dx < 0)sprite.setTextureRect(IntRect(20 * int(currentFrame) + 20, 0, -20, 34));//анимация
		sprite.setPosition(rect.left - offsetX, rect.top - offsetY);
		dx = 0;

	}
	void Collision(int dir)//fizica(na zemle ili net)
	{
		for (int i = rect.top / 16; i < (rect.top + rect.height) / 16; i++)
			for (int j = rect.left / 16; j < (rect.left + rect.width) / 16; j++)
			{
				if (TileMap[i][j] == 'f') { count++; TileMap[i][j] = ' '; }
				if ((TileMap[i][j] == 'P') || (TileMap[i][j] == '0') || (TileMap[i][j] == 'r'))
				{
					if ((dx > 0) && (dir == 0)) rect.left = j * 16 - rect.width;
					if ((dx < 0) && (dir == 0)) rect.left = j * 16 + 16;
					if ((dy > 0) && (dir == 1)) { rect.top = i * 16 - rect.height;  dy = 0;   onGround = true; }
					if ((dy < 0) && (dir == 1)) { rect.top = i * 16 + 16;   dy = 0; }
				}

				if (TileMap[i][j] == 'k')
				{
					if ((dy > 0) && (dir == 1)) { rect.top = i * 16 - rect.height;  dy = 0;   onGround = true; }
					if ((dy < 0) && (dir == 1)) { rect.top = i * 16 + 16;   dy = 0; TileMap[i][j] = 'f'; }
				}

			}
	}
};
#include <SFML/Graphics.hpp>
float offset_x = 16, offset_y = 16;
const int H = 39;
const int W = 52;
std::string TileMap[39];
std::string TileMapB[52];
#include"Map.h"
#include"plaer.h"
#include"ENEMY.h"
#include <sstream>

using namespace sf;
using namespace std;


bool startGame()
{
	RenderWindow window(VideoMode(600, 400), "Mario");
	menu(window);
	Texture t;
	t.loadFromFile("image/simpson.png");
	PLAYER p(t);
	Image map_image;
	map_image.loadFromFile("image/Mario_tileset.png");
	Texture m;
	m.loadFromImage(map_image);
	Sprite tile;
	tile.setTexture(m);
	ENEMY  enemy;
	enemy.set(m, 48 * 16, 13 * 16);
	float currentFrame = 0;
	Sprite money;
	money.setTexture(m);
	Clock clock;
	RectangleShape rectangle(Vector2f(16, 16));


	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();

		time = time / 500;
		if (time > 20) time = 20;

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

		}

		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			p.dx = -0.1;

		}

		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			p.dx = 0.1;
		}

		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			p.dy = -0.1;
		}
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			p.dy = 0.1;
		}
		if (Keyboard::isKeyPressed(Keyboard::Tab)) { map_create(1); return true; }
		if (Keyboard::isKeyPressed(Keyboard::Escape)) { return false; }
		p.update(time);
		enemy.update(time);


		if (p.rect.intersects(enemy.rect))//обработка столкновений с врагом
		{
			if (enemy.life)
			{
				if (p.dy > 0) { enemy.dx = 0; p.dy = -0.2; enemy.life = false; }
				else
				{
					p.dy = -1; p.health--; if (p.health <= 0) {
						p.life = false;  map_create(1); return true;
					}
				}
			}
		}

		if (p.rect.left > 300) offsetX = p.rect.left - 300;
		offsetY = p.rect.top - 200;

		window.clear(Color::Blue);
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
			{
				if (TileMap[i][j] == 'P')  tile.setTextureRect(IntRect(143 - 16 * 3, 112, 16, 16));
				if (TileMap[i][j] == 'f')  tile.setTextureRect(IntRect(17, 22, 13, 10));
				if ((TileMap[i][j] == ' ') || (TileMap[i][j] == '0')) continue;

				tile.setPosition(j * 16 - offsetX, i * 16 - offsetY);
				window.draw(tile);
			}
		//очки и жизни________________________________________________________________
		Font font;//шрифт 
		font.loadFromFile("CyrilicOld.ttf");
		Text Life("", font, 20);
		Life.setStyle(sf::Text::Bold | sf::Text::Underlined);
		Text Score("", font, 20);
		Score.setStyle(sf::Text::Bold | sf::Text::Underlined);
		ostringstream playerScoreString;
		ostringstream playerLife;
		playerLife << p.health;
		playerScoreString << p.count;
		Score.setString("Очки:" + playerScoreString.str());
		Score.setPosition(1, 1);
		Life.setString("Жизнь:" + playerLife.str());
		Life.setPosition(100, 1);
		window.draw(Life);//рисую этот текст
		window.draw(Score);
		window.draw(p.sprite);
		window.draw(enemy.sprite);
		window.display();
	}
	return false;
}

void RunGame() {
	if (startGame()) { RunGame(); }
}
int main()
{
	RunGame();
	return 0;
}





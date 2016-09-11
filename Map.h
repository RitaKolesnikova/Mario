#include <SFML/Graphics.hpp>

using namespace sf;
//menu
void menu(RenderWindow & window)
{
	int MenuNum = 0;
	bool Menu = 1;
	Texture menu_texture1, menu_texture2, menu_texture3, about_texture;
	menu_texture1.loadFromFile("image/111.png");
	menu_texture2.loadFromFile("image/222.png");
	menu_texture3.loadFromFile("image/333.png");
	about_texture.loadFromFile("image/about.png");
	Sprite menu1(menu_texture1), menu2(menu_texture2), menu3(menu_texture3), about(about_texture);

	menu1.setPosition(100, 30);
	menu2.setPosition(100, 90);
	menu3.setPosition(100, 150);
	while (Menu)
	{
		menu1.setColor(Color::White);
		menu2.setColor(Color::White);
		menu3.setColor(Color::White);
		MenuNum = 0;
		window.clear(Color(0, 0, 0));

		if (IntRect(100, 30, 300, 50).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Yellow); MenuNum = 1; }
		if (IntRect(100, 90, 300, 50).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Yellow); MenuNum = 2; }
		if (IntRect(100, 150, 300, 50).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Yellow); MenuNum = 3; }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (MenuNum == 1) Menu = false;
			if (MenuNum == 2) {
				window.draw(about); window.display();
				while (!Keyboard::isKeyPressed(Keyboard::Escape));
			}
			if (MenuNum == 3) { window.close(); }
		}
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);
		window.display();
	}
}
//zagruzka karty
void map_create(int level) {
	if (level == 1) {

		TileMap[0] = "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
		TileMap[1] = "0                                                                                                                                                     0";
		TileMap[2] = "0                                                                                     w                                                               0";
		TileMap[3] = "0                   w                                  w                   w                                                                          0";
		TileMap[4] = "0                                      w                                        kk                                                                    0";
		TileMap[5] = "0                                                                              k  k    k    k                                                         0";
		TileMap[6] = "0                                                                        f     k      kkk  kkk  w                                                     0";
		TileMap[7] = "0                                                                        r     k       k    k                                                         0";
		TileMap[8] = "0                                                                       rr     k  k                                        A                          0";
		TileMap[9] = "0               f                                                      rrr      kk                                                                    0";
		TileMap[10] = "0               k    kkkkk                                           rrrr                                                                            0";
		TileMap[11] = "0                                      t0                           rrrrr                                                                            0";
		TileMap[12] = "0G                                     00              t0          rrrrrr            G                                                               0";
		TileMap[13] = "0           d    g       d             00              00         rrrrrrr                                                                            0";
		TileMap[14] = "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP";
		TileMap[15] = "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP";
		TileMap[16] = "PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP";

	}
}

#include <SFML/Audio.hpp>
#include "Orbital.h"
#include "config.h"
#include <iostream>
using namespace sf;
using namespace std;

int main()
{
	// Edit window settings in 'config.h'
	VideoMode vm(WINDOW_WIDTH, WINDOW_HEIGHT);
	RenderWindow window(vm, WINDOW_TITLE);
	window.setFramerateLimit(TARGET_FPS);

	vector<Orbital> orbitals;

	while (window.isOpen())

	{
		Event event;

		while (window.pollEvent(event))
		{
			Vector2i mousePos(event.mouseButton.x, event.mouseButton.y);

			if (event.type == Event::Closed)
			{
				window.close();
			}

			if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
			{
				if (orbitals.size() < 3)
				{
					orbitals.emplace_back(Vector2f(mousePos), Vector2f(50, 0), 100.0f);
				}
			}

			if (Keyboard::isKeyPressed(Keyboard::Escape))

			{

				window.close();

			}
		}

		///Update
		float deltaTime = 1.0f / TARGET_FPS; // simple fixed timestep
		for (auto& o : orbitals)
		{
			o.update(deltaTime);
		}

		///Draw
		window.clear();

		//window.draw(...);
		for (auto& o : orbitals)
		{
			o.draw(window);
			cout << "Drawing orbital with radius: " << o.getRadius() << endl;

		}

		window.display();

	}

}
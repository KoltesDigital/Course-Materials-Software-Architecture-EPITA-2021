#pragma once

#include <SFML/Window/Keyboard.hpp>

namespace engine
{
	namespace input
	{
		class StateProvider
		{
		public:
			// True during all frames while the key is pressed.
			virtual bool isKeyPressed(sf::Keyboard::Key key) const = 0;

			// True only the first frame after that the key is pressed.
			virtual bool isKeyJustPressed(sf::Keyboard::Key key) const = 0;

			// True only the first frame after that the key is released.
			virtual bool isKeyJustReleased(sf::Keyboard::Key key) const = 0;
		};
	}
}

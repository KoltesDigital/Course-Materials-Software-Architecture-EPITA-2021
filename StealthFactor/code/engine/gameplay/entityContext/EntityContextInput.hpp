#pragma once

#include <SFML/Window/Keyboard.hpp>
#include <engine/graphics/ShapeListId.hpp>

namespace engine
{
	namespace input
	{
		class Manager;
	}

	namespace gameplay
	{
		class EntityContextInput
		{
		public:
			EntityContextInput(input::Manager& manager);

			// True during all frames while the key is pressed.
			bool isKeyPressed(sf::Keyboard::Key key) const;

			// True only the first frame after that the key is pressed.
			bool isKeyJustPressed(sf::Keyboard::Key key) const;

			// True only the first frame after that the key is released.
			bool isKeyJustReleased(sf::Keyboard::Key key) const;

		private:
			input::Manager& _manager;
		};
	}
}

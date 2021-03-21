#include "EntityContextInput.hpp"

#include <engine/input/InputManager.hpp>

namespace engine
{
	namespace gameplay
	{
		EntityContextInput::EntityContextInput(input::Manager& manager)
			: _manager{ manager }
		{}

		bool EntityContextInput::isKeyPressed(sf::Keyboard::Key key) const
		{
			return _manager.isKeyPressed(key);
		}

		bool EntityContextInput::isKeyJustPressed(sf::Keyboard::Key key) const
		{
			return _manager.isKeyJustPressed(key);
		}

		bool EntityContextInput::isKeyJustReleased(sf::Keyboard::Key key) const
		{
			return _manager.isKeyJustReleased(key);
		}

	}
}

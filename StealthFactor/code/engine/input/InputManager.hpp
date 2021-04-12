#pragma once

#include <set>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <engine/input/StateProvider.hpp>

namespace engine
{
	namespace input
	{
		class Manager : public StateProvider
		{
		public:
			void clear();
			void onKeyPressed(const sf::Event::KeyEvent& event);
			void onKeyReleased(const sf::Event::KeyEvent& event);

			void setActive(bool active);

			// StateProvider
			bool isKeyPressed(sf::Keyboard::Key key) const override;
			bool isKeyJustPressed(sf::Keyboard::Key key) const override;
			bool isKeyJustReleased(sf::Keyboard::Key key) const override;

		private:
			std::set<sf::Keyboard::Key> _justPressedKeys;
			std::set<sf::Keyboard::Key> _justReleasedKeys;
			bool _active{ true };
		};
	}
}

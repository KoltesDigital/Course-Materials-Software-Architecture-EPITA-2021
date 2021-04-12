#include "Player.hpp"

#include <engine/input/InputManager.hpp>
#include <engine/backend/Character.hpp>
#include <engine/backend/GameplayActuator.hpp>

namespace engine
{
	namespace backend
	{
		namespace controls
		{
			Player::Player(Character& character, ControlContext& context)
				: Control{ character, context }
			{
			}

			void Player::update()
			{
				auto& character = getCharacter();

				bool justMoved = false;

				if (getInputStateProvider().isKeyJustPressed(sf::Keyboard::Left))
				{
					justMoved = true;
					character.position.column -= 1;
					character.orientation = Orientation::Left;
				}

				if (getInputStateProvider().isKeyJustPressed(sf::Keyboard::Right))
				{
					justMoved = true;
					character.position.column += 1;
					character.orientation = Orientation::Right;
				}

				if (getInputStateProvider().isKeyJustPressed(sf::Keyboard::Up))
				{
					justMoved = true;
					character.position.row -= 1;
					character.orientation = Orientation::Top;
				}

				if (getInputStateProvider().isKeyJustPressed(sf::Keyboard::Down))
				{
					justMoved = true;
					character.position.row += 1;
					character.orientation = Orientation::Bottom;
				}

				if (justMoved)
				{
					getGameplayActuator().characterMoved(getCharacter());
				}
			}

			std::string Player::getPrefabName() const
			{
				return "prefabs/player.xml";
			}
		}
	}
}

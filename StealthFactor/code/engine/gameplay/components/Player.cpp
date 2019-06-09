#include "Player.hpp"

#include <ode/collision.h>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <engine/gameplay/Entity.hpp>
#include <engine/gameplay/GameplayManager.hpp>
#include <engine/gameplay/components/CollisionBox.hpp>
#include <engine/gameplay/components/Target.hpp>
#include <engine/gameplay/components/Transform.hpp>
#include <engine/gameplay/entityContext/EntityContextGameplay.hpp>
#include <engine/gameplay/entityContext/EntityContextInput.hpp>

namespace engine
{
	namespace gameplay
	{
		namespace components
		{
			Player::Player(Entity& entity)
				: Component{ entity }
			{
			}

			void Player::update()
			{
				auto transform = getEntity().getComponent<Transform>();

				_justMoved = false;
				auto position = transform->getPosition();
				float rotation = transform->getRotation();

				if (getInput().isKeyJustPressed(sf::Keyboard::Left))
				{
					_justMoved = true;
					position.x -= gameplay::Manager::CELL_SIZE;
					rotation = 180.f;
				}

				if (getInput().isKeyJustPressed(sf::Keyboard::Right))
				{
					_justMoved = true;
					position.x += gameplay::Manager::CELL_SIZE;
					rotation = 0.f;
				}

				if (getInput().isKeyJustPressed(sf::Keyboard::Up))
				{
					_justMoved = true;
					position.y -= gameplay::Manager::CELL_SIZE;
					rotation = -90.f;
				}

				if (getInput().isKeyJustPressed(sf::Keyboard::Down))
				{
					_justMoved = true;
					position.y += gameplay::Manager::CELL_SIZE;
					rotation = 90.f;
				}

				if (_justMoved)
				{
					transform->setPosition(position);
					transform->setRotation(rotation);
				}

				auto collisions = getEntity().getComponent<CollisionBox>()->getCollisions();
				for (auto& entity : collisions)
				{
					auto targetComponent = entity->getComponent<Target>();
					if (targetComponent)
					{
						getGameplay().loadNextMap();
					}
				}
			}

			bool Player::hasJustMoved() const
			{
				return _justMoved;
			}
		}
	}
}

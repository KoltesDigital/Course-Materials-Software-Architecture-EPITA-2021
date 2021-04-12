#include "Enemy.hpp"

#include <engine/assets/AssetProvider.hpp>
#include <engine/backend/Character.hpp>
#include <engine/backend/GameplayActuator.hpp>
#include <engine/backend/MapDescriptor.hpp>

namespace engine
{
	namespace backend
	{
		namespace controls
		{
			Enemy::Enemy(Character& character, ControlContext& context, const EnemyDescriptor& descriptor, Character& playerCharacter)
				: Control{ character, context }
				, _playerCharacter{ playerCharacter }
			{
				_archetype = getAssetProvider().getAsset<Archetype>(descriptor.archetypeName);
			}

			void Enemy::update()
			{
				auto& playerPosition = _playerCharacter.position;
				auto& myPosition = getCharacter().position;

				auto offsetRow = myPosition.row - playerPosition.row;
				auto offsetColumn = myPosition.column - playerPosition.column;
				int distance2 = offsetRow * offsetRow + offsetColumn * offsetColumn;
				if (distance2 <= _archetype->visionRadius * _archetype->visionRadius)
				{
					if (_shootDelayCounter < _archetype->shootDelay)
					{
						++_shootDelayCounter;
					}
					else
					{
						getGameplayActuator().gameOver();
					}
				}
				else
				{
					_shootDelayCounter = 0;
				}
			}

			std::string Enemy::getPrefabName() const
			{
				return _archetype->prefabName;
			}
		}
	}
}

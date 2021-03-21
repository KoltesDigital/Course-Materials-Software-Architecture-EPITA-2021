#include "Character.hpp"

#include <cassert>
#include <engine/gameplay/GameplayManager.hpp>
#include <engine/gameplay/entityContext/EntityContext.hpp>
#include <engine/graphics/GraphicsManager.hpp>

namespace engine
{
	namespace gameplay
	{
		namespace entities
		{
			Character::Character(EntityContext& context)
				: Entity{ context }
			{
				_collisionVolumeId = _context.physics().createCollisionBox(this, gameplay::Manager::CELL_SIZE * 0.9f, gameplay::Manager::CELL_SIZE * 0.9f);
				assert(_collisionVolumeId);
			}

			Character::~Character()
			{
				_context.graphics().destroyShapeListInstance(_shapeListId);
				_context.physics().destroyCollisionVolume(_collisionVolumeId);
			}

			void Character::propagateTransform()
			{
				_context.graphics().setShapeListInstanceTransform(_shapeListId, getTransform());
				_context.physics().setCollisionVolumePosition(_collisionVolumeId, getPosition());
			}
		}
	}
}

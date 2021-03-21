#include "Target.hpp"

#include <cassert>
#include <engine/gameplay/entityContext/EntityContext.hpp>
#include <engine/gameplay/GameplayManager.hpp>

namespace engine
{
	namespace gameplay
	{
		namespace entities
		{
			Target::Target(EntityContext& context)
				: Entity{ context }
			{
				_shapeListId = _context.graphics().createShapeListInstance("target");
				assert(_shapeListId);

				_collisionVolumeId = _context.physics().createCollisionBox(this, gameplay::Manager::CELL_SIZE * 0.9f, gameplay::Manager::CELL_SIZE * 0.9f);
				assert(_collisionVolumeId);
			}

			Target::~Target()
			{
				_context.graphics().destroyShapeListInstance(_shapeListId);
				_context.physics().destroyCollisionVolume(_collisionVolumeId);
			}

			void Target::update()
			{
				propagateTransform();
			}

			void Target::propagateTransform()
			{
				_context.graphics().setShapeListInstanceTransform(_shapeListId, getTransform());

				auto& position = getPosition();
				dGeomSetPosition(_collisionVolumeId, position.x, position.y, 0);
			}
		}
	}
}

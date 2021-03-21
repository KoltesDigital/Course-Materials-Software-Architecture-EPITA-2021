#include "EntityContextPhysics.hpp"

#include <engine/physics/PhysicsManager.hpp>

namespace engine
{
	namespace gameplay
	{
		EntityContextPhysics::EntityContextPhysics(physics::Manager& manager)
			: _manager{ manager }
		{}

		physics::CollisionVolumeId EntityContextPhysics::createCollisionBox(Entity* entity, float width, float height)
		{
			return _manager.createCollisionBox(entity, width, height);
		}

		void EntityContextPhysics::destroyCollisionVolume(physics::CollisionVolumeId id)
		{
			_manager.destroyCollisionVolume(id);
		}

		void EntityContextPhysics::setCollisionVolumePosition(physics::CollisionVolumeId id, const sf::Vector2f& position)
		{
			_manager.setCollisionVolumePosition(id, position);
		}

		std::set<Entity*> EntityContextPhysics::getCollisionsWith(physics::CollisionVolumeId id) const
		{
			return _manager.getCollisionsWith(id);
		}
	}
}

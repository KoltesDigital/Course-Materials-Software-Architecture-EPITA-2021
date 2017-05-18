#include "EntityContextPhysics.hpp"

#include <engine/physics/PhysicsManager.hpp>

namespace engine
{
	namespace gameplay
	{
		EntityContextPhysics::EntityContextPhysics(physics::Manager& manager)
			: _manager{ manager }
		{}

		physics::CollisionVolumeId EntityContextPhysics::createCollisionBox(const Entity& entity)
		{
			return _manager.createCollisionBox(entity);
		}

		void EntityContextPhysics::destroyCollisionVolume(physics::CollisionVolumeId id)
		{
			_manager.destroyCollisionVolume(id);
		}

		void EntityContextPhysics::setCollisionVolumePosition(physics::CollisionVolumeId id, const sf::Vector2f& position)
		{
			_manager.setCollisionVolumePosition(id, position);
		}

		void EntityContextPhysics::setCollisionBoxSize(physics::CollisionVolumeId id, const sf::Vector2f& size)
		{
			_manager.setCollisionBoxSize(id, size);
		}

		physics::EntitySet EntityContextPhysics::getCollisionsWith(physics::CollisionVolumeId id) const
		{
			return _manager.getCollisionsWith(id);
		}
	}
}

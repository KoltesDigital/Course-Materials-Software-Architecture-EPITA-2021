#pragma once

#include <SFML/System/Vector2.hpp>
#include <engine/physics/CollisionEntities.hpp>
#include <engine/physics/CollisionVolumeId.hpp>

namespace engine
{
	namespace physics
	{
		class Manager;
	}

	namespace gameplay
	{
		class Entity;

		class EntityContextPhysics
		{
		public:
			EntityContextPhysics(physics::Manager& manager);

			physics::CollisionVolumeId createCollisionBox(const Entity& entity);
			void destroyCollisionVolume(physics::CollisionVolumeId id);

			void setCollisionVolumePosition(physics::CollisionVolumeId id, const sf::Vector2f& position);
			void setCollisionBoxSize(physics::CollisionVolumeId id, const sf::Vector2f& size);

			physics::EntitySet getCollisionsWith(physics::CollisionVolumeId id) const;

		private:
			physics::Manager& _manager;
		};
	}
}

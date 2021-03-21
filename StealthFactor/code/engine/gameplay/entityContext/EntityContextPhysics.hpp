#pragma once

#include <set>
#include <SFML/System/Vector2.hpp>
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

			physics::CollisionVolumeId createCollisionBox(Entity* entity, float width, float height);
			void destroyCollisionVolume(physics::CollisionVolumeId id);

			void setCollisionVolumePosition(physics::CollisionVolumeId id, const sf::Vector2f& position);

			std::set<Entity*> getCollisionsWith(physics::CollisionVolumeId id) const;

		private:
			physics::Manager& _manager;
		};
	}
}

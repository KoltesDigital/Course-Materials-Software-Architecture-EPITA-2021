#include "CollisionBox.hpp"

#include <engine/physics/PhysicsManager.hpp>
#include <engine/gameplay/Entity.hpp>
#include <engine/gameplay/components/Transform.hpp>
#include <engine/gameplay/entityContext/EntityContextPhysics.hpp>
#include <engine/util/Assert.hpp>

namespace engine
{
	namespace gameplay
	{
		namespace components
		{
			CollisionBox::CollisionBox(Entity& entity)
				: Component{ entity }
			{
				_collisionGeomId = getPhysics().createCollisionBox(getEntity());
				ASSERT(_collisionGeomId);
			}

			CollisionBox::~CollisionBox()
			{
				getPhysics().destroyCollisionVolume(_collisionGeomId);
			}

			void CollisionBox::onTransformChange()
			{
				auto transform = getEntity().getComponent<Transform>();
				auto& position = transform->getPosition();
				getPhysics().setCollisionVolumePosition(_collisionGeomId, position);
			}

			void CollisionBox::setSize(const sf::Vector2f& size)
			{
				getPhysics().setCollisionBoxSize(_collisionGeomId, size);
			}

			physics::EntitySet CollisionBox::getCollisions() const
			{
				return getPhysics().getCollisionsWith(_collisionGeomId);
			}
		}
	}
}

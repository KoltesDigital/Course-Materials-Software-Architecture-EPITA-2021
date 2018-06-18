#include "Component.hpp"

#include <engine/gameplay/Entity.hpp>
#include <engine/gameplay/entityContext/EntityContext.hpp>

namespace engine
{
	namespace gameplay
	{
		Component::Component(Entity& entity)
			: _entity{ entity }
		{
		}

		void Component::update()
		{
		}

		void Component::onTransformChange()
		{
		}

		Entity& Component::getEntity()
		{
			return _entity;
		}

		const Entity& Component::getEntity() const
		{
			return const_cast<Component*>(this)->getEntity();
		}

		EntityContextAssets& Component::getAssets()
		{
			return getEntity().getContext().getAssets();
		}

		const EntityContextAssets& Component::getAssets() const
		{
			return const_cast<Component*>(this)->getAssets();
		}

		EntityContextGameplay& Component::getGameplay()
		{
			return getEntity().getContext().getGameplay();
		}

		const EntityContextGameplay& Component::getGameplay() const
		{
			return const_cast<Component*>(this)->getGameplay();
		}

		EntityContextGraphics& Component::getGraphics()
		{
			return getEntity().getContext().getGraphics();
		}

		const EntityContextGraphics& Component::getGraphics() const
		{
			return const_cast<Component*>(this)->getGraphics();
		}

		EntityContextInput& Component::getInput()
		{
			return getEntity().getContext().getInput();
		}

		const EntityContextInput& Component::getInput() const
		{
			return const_cast<Component*>(this)->getInput();
		}

		EntityContextPhysics& Component::getPhysics()
		{
			return getEntity().getContext().getPhysics();
		}

		const EntityContextPhysics& Component::getPhysics() const
		{
			return const_cast<Component*>(this)->getPhysics();
		}
	}
}

#include "Component.hpp"

#include <engine/frontend/Entity.hpp>
#include <engine/frontend/entityContext/EntityContext.hpp>

namespace engine
{
	namespace frontend
	{
		Component::Component(Entity& entity)
			: _entity{ entity }
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

		assets::AssetProvider& Component::getAssetProvider()
		{
			return getEntity().getContext().getAssetProvider();
		}

		const assets::AssetProvider& Component::getAssetProvider() const
		{
			return const_cast<Component*>(this)->getAssetProvider();
		}

		EntityContextGraphics& Component::getGraphics()
		{
			return getEntity().getContext().getGraphics();
		}

		const EntityContextGraphics& Component::getGraphics() const
		{
			return const_cast<Component*>(this)->getGraphics();
		}
	}
}

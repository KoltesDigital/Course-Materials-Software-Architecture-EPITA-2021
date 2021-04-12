#include "EntityContext.hpp"

namespace engine
{
	namespace frontend
	{
		EntityContext::EntityContext(assets::AssetProvider& assetProvider, graphics::Manager& graphicsManager)
			: _assetProvider{ assetProvider }
			, _graphics{ graphicsManager }
		{}

		assets::AssetProvider& EntityContext::getAssetProvider()
		{
			return _assetProvider;
		}

		EntityContextGraphics& EntityContext::getGraphics()
		{
			return _graphics;
		}

		const EntityContextGraphics& EntityContext::getGraphics() const
		{
			return const_cast<EntityContext*>(this)->getGraphics();
		}
	}
}

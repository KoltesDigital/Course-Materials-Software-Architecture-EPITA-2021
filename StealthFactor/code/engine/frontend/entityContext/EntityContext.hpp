#pragma once

#include <engine/frontend/entityContext/EntityContextGraphics.hpp>

namespace engine
{
	namespace assets
	{
		class AssetProvider;
	}

	namespace frontend
	{
		class EntityContext
		{
		public:
			EntityContext(assets::AssetProvider& assetProvider, graphics::Manager& graphicsManager);

			assets::AssetProvider& getAssetProvider();

			EntityContextGraphics& getGraphics();
			const EntityContextGraphics& getGraphics() const;

		private:
			assets::AssetProvider& _assetProvider;
			EntityContextGraphics _graphics;
		};
	}
}

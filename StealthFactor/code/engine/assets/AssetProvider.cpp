#include "AssetProvider.hpp"

#include <engine/assets/AssetManager.hpp>

namespace engine
{
	namespace assets
	{
		AssetProvider::AssetProvider(Manager& manager)
			: _manager{ manager }
		{}
	}
}

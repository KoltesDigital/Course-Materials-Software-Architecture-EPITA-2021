#include "EntityContextAssets.hpp"

#include <engine/assets/AssetManager.hpp>

namespace engine
{
	namespace gameplay
	{
		EntityContextAssets::EntityContextAssets(assets::Manager& manager)
			: _manager{ manager }
		{}
	}
}

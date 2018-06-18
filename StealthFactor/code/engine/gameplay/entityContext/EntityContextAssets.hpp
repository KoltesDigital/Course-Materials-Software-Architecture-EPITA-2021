#pragma once

#include <string>
#include <engine/graphics/ShapeListId.hpp>

namespace engine
{
	namespace assets
	{
		class Manager;
	}

	namespace gameplay
	{
		class EntityContextAssets
		{
		public:
			EntityContextAssets(assets::Manager& manager);

			template <typename Type>
			const Type* getAsset(const std::string& name)
			{
				return _manager.getAsset<Type>(name);
			}

		private:
			assets::Manager& _manager;
		};
	}
}

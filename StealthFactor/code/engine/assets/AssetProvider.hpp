#pragma once

#include <string>
#include <engine/assets/AssetManager.hpp>

namespace engine
{
	namespace assets
	{
		class AssetProvider
		{
		public:
			AssetProvider(Manager& manager);

			template <typename Type>
			const Type* getAsset(const std::string& name)
			{
				return _manager.getAsset<Type>(name);
			}

		private:
			Manager& _manager;
		};
	}
}

#pragma once

#include <memory>
#include <string>

namespace engine
{
	namespace gameplay
	{
		class Entity;
		class EntityContext;

		class Prefab
		{
		public:
			Prefab(const std::string& name);

			std::unique_ptr<Entity> instantiate(EntityContext& context) const;

		private:
			std::string _name;
		};
	}
}

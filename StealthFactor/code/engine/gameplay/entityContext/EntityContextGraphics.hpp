#pragma once

#include <string>
#include <SFML/Graphics/Transform.hpp>
#include <engine/graphics/ShapeListId.hpp>

namespace engine
{
	namespace graphics
	{
		class Manager;
	}

	namespace gameplay
	{
		class EntityContextGraphics
		{
		public:
			EntityContextGraphics(graphics::Manager& manager);

			graphics::ShapeListId createShapeListInstance(const std::string& name);
			void destroyShapeListInstance(graphics::ShapeListId id);

			void setShapeListInstanceTransform(graphics::ShapeListId id, const sf::Transform& transform);

		private:
			graphics::Manager& _manager;
		};
	}
}

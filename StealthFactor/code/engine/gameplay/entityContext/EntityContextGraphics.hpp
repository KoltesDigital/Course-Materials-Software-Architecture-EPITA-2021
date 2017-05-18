#pragma once

#include <string>
#include <SFML/Graphics/Transform.hpp>
#include <engine/graphics/CameraId.hpp>
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

			// Cameras

			graphics::CameraId createCamera();
			void destroyCamera(graphics::CameraId id);

			void setActiveCamera(graphics::CameraId id);
			void setCameraPosition(graphics::CameraId id, const sf::Vector2f& position);

			// ShapeListInstance

			graphics::ShapeListId createShapeListInstance(const std::string& name);
			void destroyShapeListInstance(graphics::ShapeListId id);

			void setShapeListInstanceMatrix(graphics::ShapeListId id, const sf::Transform& transform);

		private:
			graphics::Manager& _manager;
		};
	}
}

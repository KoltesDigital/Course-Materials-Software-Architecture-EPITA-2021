#include "EntityContextGraphics.hpp"

#include <engine/graphics/GraphicsManager.hpp>

namespace engine
{
	namespace gameplay
	{
		EntityContextGraphics::EntityContextGraphics(graphics::Manager& manager)
			: _manager{ manager }
		{}

		graphics::CameraId EntityContextGraphics::createCamera()
		{
			return _manager.createCamera();
		}

		void EntityContextGraphics::destroyCamera(graphics::CameraId id)
		{
			_manager.destroyCamera(id);
		}

		void EntityContextGraphics::setActiveCamera(graphics::CameraId id)
		{
			_manager.setActiveCamera(id);
		}

		void EntityContextGraphics::setCameraPosition(graphics::CameraId id, const sf::Vector2f& position)
		{
			_manager.setCameraPosition(id, position);
		}

		graphics::ShapeListId EntityContextGraphics::createShapeListInstance(const std::string& name)
		{
			return _manager.createShapeListInstance(name);
		}

		void EntityContextGraphics::destroyShapeListInstance(graphics::ShapeListId id)
		{
			_manager.destroyShapeListInstance(id);
		}

		void EntityContextGraphics::setShapeListInstanceMatrix(graphics::ShapeListId id, const sf::Transform& matrix)
		{
			_manager.setShapeListInstanceMatrix(id, matrix);
		}
	}
}

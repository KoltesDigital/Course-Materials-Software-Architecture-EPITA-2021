#include "Camera.hpp"

#include <engine/graphics/GraphicsManager.hpp>
#include <engine/frontend/Entity.hpp>
#include <engine/frontend/components/Transform.hpp>
#include <engine/frontend/entityContext/EntityContextGraphics.hpp>

namespace engine
{
	namespace frontend
	{
		namespace components
		{
			Camera::Camera(Entity& entity)
				: Component{ entity }
			{
				_cameraId = getGraphics().createCamera();
			}

			Camera::~Camera()
			{
				getGraphics().destroyCamera(_cameraId);
			}

			void Camera::onTransformChange()
			{
				auto transform = getEntity().getComponent<Transform>();
				auto& position = transform->getPosition();
				getGraphics().setCameraPosition(_cameraId, position);
			}

			void Camera::setActive()
			{
				getGraphics().setActiveCamera(_cameraId);
			}
		}
	}
}

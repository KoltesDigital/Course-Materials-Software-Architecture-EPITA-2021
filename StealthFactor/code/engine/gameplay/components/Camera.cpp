#include "Camera.hpp"

#include <engine/graphics/GraphicsManager.hpp>
#include <engine/gameplay/Entity.hpp>
#include <engine/gameplay/components/Transform.hpp>
#include <engine/gameplay/entityContext/EntityContextGraphics.hpp>

namespace engine
{
	namespace gameplay
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

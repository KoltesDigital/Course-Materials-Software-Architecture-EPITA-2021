#include "Renderer.hpp"

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
			Renderer::Renderer(Entity& entity)
				: Component{ entity }
			{
			}

			Renderer::~Renderer()
			{
				clear();
			}

			void Renderer::onTransformChange()
			{
				if (_shapeListId)
				{
					auto transform = getEntity().getComponent<Transform>();
					getGraphics().setShapeListInstanceMatrix(_shapeListId, transform->getMatrix());
				}
			}

			void Renderer::setShapeListName(const std::string& name)
			{
				clear();

				if (!name.empty())
				{
					_shapeListId = getGraphics().createShapeListInstance(name);
					onTransformChange();
				}
			}

			void Renderer::clear()
			{
				if (_shapeListId)
				{
					getGraphics().destroyShapeListInstance(_shapeListId);
					_shapeListId = 0;
				}
			}
		}
	}
}

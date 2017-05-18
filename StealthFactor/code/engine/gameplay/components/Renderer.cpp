#include "Renderer.hpp"

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

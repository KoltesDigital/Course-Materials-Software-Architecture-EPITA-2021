#include "EntityContext.hpp"

namespace engine
{
	namespace gameplay
	{
		EntityContext::EntityContext(assets::Manager& assetManager, graphics::Manager& graphicsManager, input::Manager& inputManager, physics::Manager& physicsManager, EntityListener& entityListener)
			: _assets{ assetManager }
			, _gameplay{ entityListener }
			, _graphics{ graphicsManager }
			, _input{ inputManager }
			, _physics{ physicsManager }
		{}

		EntityContextAssets& EntityContext::getAssets()
		{
			return _assets;
		}

		const EntityContextAssets& EntityContext::getAssets() const
		{
			return const_cast<EntityContext*>(this)->getAssets();
		}

		EntityContextGameplay& EntityContext::getGameplay()
		{
			return _gameplay;
		}

		const EntityContextGameplay& EntityContext::getGameplay() const
		{
			return const_cast<EntityContext*>(this)->getGameplay();
		}

		EntityContextGraphics& EntityContext::getGraphics()
		{
			return _graphics;
		}

		const EntityContextGraphics& EntityContext::getGraphics() const
		{
			return const_cast<EntityContext*>(this)->getGraphics();
		}

		EntityContextInput& EntityContext::getInput()
		{
			return _input;
		}

		const EntityContextInput& EntityContext::getInput() const
		{
			return const_cast<EntityContext*>(this)->getInput();
		}

		EntityContextPhysics& EntityContext::getPhysics()
		{
			return _physics;
		}

		const EntityContextPhysics& EntityContext::getPhysics() const
		{
			return const_cast<EntityContext*>(this)->getPhysics();
		}
	}
}

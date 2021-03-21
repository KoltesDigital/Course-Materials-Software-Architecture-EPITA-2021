#include "EntityContext.hpp"

namespace engine
{
	namespace gameplay
	{
		EntityContext::EntityContext(graphics::Manager& graphicsManager, input::Manager& inputManager, physics::Manager& physicsManager, EntityListener& entityListener)
			: _gameplay{ entityListener }
			, _graphics{ graphicsManager }
			, _input{ inputManager }
			, _physics{ physicsManager }
		{}

		EntityContextGameplay& EntityContext::gameplay()
		{
			return _gameplay;
		}

		EntityContextGraphics& EntityContext::graphics()
		{
			return _graphics;
		}

		EntityContextInput& EntityContext::input()
		{
			return _input;
		}

		EntityContextPhysics& EntityContext::physics()
		{
			return _physics;
		}
	}
}

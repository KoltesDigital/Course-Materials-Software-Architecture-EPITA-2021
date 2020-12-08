#pragma once

#include <engine/gameplay/entityContext/EntityContextGameplay.hpp>
#include <engine/gameplay/entityContext/EntityContextGraphics.hpp>
#include <engine/gameplay/entityContext/EntityContextInput.hpp>
#include <engine/gameplay/entityContext/EntityContextPhysics.hpp>

namespace engine
{
	namespace gameplay
	{
		class EntityContext
		{
		public:
			EntityContext(graphics::Manager& graphicsManager, input::Manager& inputManager, physics::Manager& physicsManager, EntityListener& entityListener);

			EntityContextGameplay& gameplay();
			EntityContextGraphics& graphics();
			EntityContextInput& input();
			EntityContextPhysics& physics();

		private:
			EntityContextGameplay _gameplay;
			EntityContextGraphics _graphics;
			EntityContextInput _input;
			EntityContextPhysics _physics;
		};
	}
}
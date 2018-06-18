#pragma once

#include <engine/gameplay/entityContext/EntityContextAssets.hpp>
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
			EntityContext(assets::Manager& assetManager, graphics::Manager& graphicsManager, input::Manager& inputManager, physics::Manager& physicsManager, EntityListener& entityListener);

			EntityContextAssets& getAssets();
			const EntityContextAssets& getAssets() const;

			EntityContextGameplay& getGameplay();
			const EntityContextGameplay& getGameplay() const;

			EntityContextGraphics& getGraphics();
			const EntityContextGraphics& getGraphics() const;

			EntityContextInput& getInput();
			const EntityContextInput& getInput() const;

			EntityContextPhysics& getPhysics();
			const EntityContextPhysics& getPhysics() const;

		private:
			EntityContextAssets _assets;
			EntityContextGameplay _gameplay;
			EntityContextGraphics _graphics;
			EntityContextInput _input;
			EntityContextPhysics _physics;
		};
	}
}

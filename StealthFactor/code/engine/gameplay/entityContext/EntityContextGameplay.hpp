#pragma once

#include <engine/graphics/ShapeListId.hpp>

namespace engine
{
	namespace gameplay
	{
		class EntityListener;

		namespace components
		{
			class Player;
		}

		class EntityContextGameplay
		{
		public:
			EntityContextGameplay(EntityListener& entityListener);

			void loadNextMap();
			void gameOver();
			const components::Player& getPlayer() const;

		private:
			EntityListener& _entityListener;
		};
	}
}

#pragma once

#include <engine/graphics/ShapeListId.hpp>

namespace engine
{
	namespace gameplay
	{
		class EntityListener;

		namespace entities
		{
			class Player;
		}

		class EntityContextGameplay
		{
		public:
			EntityContextGameplay(EntityListener& entityListener);

			void loadNextMap();
			void gameOver();
			const entities::Player& getPlayer() const;

		private:
			EntityListener& _entityListener;
		};
	}
}

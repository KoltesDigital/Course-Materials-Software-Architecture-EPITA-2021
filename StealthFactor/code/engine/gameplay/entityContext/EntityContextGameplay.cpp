#include "EntityContextGameplay.hpp"

#include <engine/gameplay/EntityListener.hpp>

namespace engine
{
	namespace gameplay
	{
		EntityContextGameplay::EntityContextGameplay(EntityListener& entityListener)
			: _entityListener{ entityListener }
		{}

		void EntityContextGameplay::loadNextMap()
		{
			_entityListener.loadNextMap();
		}

		void EntityContextGameplay::gameOver()
		{
			_entityListener.gameOver();
		}

		const entities::Player& EntityContextGameplay::getPlayer() const
		{
			return _entityListener.getPlayer();
		}
	}
}

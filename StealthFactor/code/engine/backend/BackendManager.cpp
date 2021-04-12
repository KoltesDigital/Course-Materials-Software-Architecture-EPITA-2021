#include "BackendManager.hpp"

#include <iostream>
#include <engine/backend/Listener.hpp>
#include <engine/backend/MapDescriptor.hpp>

namespace engine
{
	namespace backend
	{
		Manager::Manager(Listener& listener, assets::Manager& assetManager, input::StateProvider& inputStateProvider)
			: _assetProvider{ assetManager }
			, _listener{ listener }
			, _context{ _assetProvider, inputStateProvider, *this }
		{
		}

		void Manager::update()
		{
			for (auto& character : _map->characters)
			{
				character->control->update();
			}

			if (_map->playerCharacter->position == _map->target)
			{
				loadMap(_map->nextMap);
			}
		}

		void Manager::loadMap(const std::string& mapName)
		{
			auto mapDescriptor{ _context.getAssetProvider().getAsset<MapDescriptor>(mapName) };
			if (!mapDescriptor)
			{
				std::cerr << "Map " << mapName << " failed to load.";
				return;
			}

			_currentMapName = mapName;
			_map.reset(new Map{ *mapDescriptor, _context });

			_listener.onMapLoaded(*_map);
		}

		void Manager::characterMoved(Character& character)
		{
			_listener.onCharacterMoved(character);
		}

		void Manager::gameOver()
		{
			std::cout << "Game over" << std::endl;
			loadMap(_currentMapName);
		}
	}
}

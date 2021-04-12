#pragma once

#include <memory>
#include <engine/assets/AssetProvider.hpp>
#include <engine/backend/ControlContext.hpp>
#include <engine/backend/GameplayActuator.hpp>
#include <engine/backend/Map.hpp>

namespace engine
{
	namespace assets
	{
		class Manager;
	}

	namespace input
	{
		class StateProvider;
	}

	namespace backend
	{
		class Listener;

		class Manager : public GameplayActuator
		{
		public:
			Manager(Listener& listener, assets::Manager& assetManager, input::StateProvider& inputStateProvider);

			void update();

			void loadMap(const std::string& mapName);

			// GameplayActuator
			void characterMoved(Character& character) override;
			void gameOver() override;

		private:
			assets::AssetProvider _assetProvider;
			Listener& _listener;

			ControlContext _context;

			std::string _currentMapName;
			std::unique_ptr<Map> _map;
		};
	}
}

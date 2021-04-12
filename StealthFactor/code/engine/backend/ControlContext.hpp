#pragma once

namespace engine
{
	namespace assets
	{
		class AssetProvider;
	}

	namespace input
	{
		class StateProvider;
	}

	namespace backend
	{
		class GameplayActuator;

		class ControlContext
		{
		public:
			ControlContext(assets::AssetProvider& assetProvider, input::StateProvider& inputStateProvider, GameplayActuator& gameplayActuator);

			assets::AssetProvider& getAssetProvider();
			GameplayActuator& getGameplayActuator();
			const input::StateProvider& getInputStateProvider() const;

		private:
			assets::AssetProvider& _assetProvider;
			GameplayActuator& _gameplayActuator;
			input::StateProvider& _inputStateProvider;
		};
	}
}

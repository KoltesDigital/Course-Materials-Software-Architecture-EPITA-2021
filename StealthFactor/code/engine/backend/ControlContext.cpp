#include "ControlContext.hpp"

namespace engine
{
	namespace backend
	{
		ControlContext::ControlContext(assets::AssetProvider& assetProvider, input::StateProvider& inputStateProvider, GameplayActuator& gameplayActuator)
			: _assetProvider{ assetProvider }
			, _gameplayActuator{ gameplayActuator }
			, _inputStateProvider{ inputStateProvider }
		{}

		assets::AssetProvider& ControlContext::getAssetProvider()
		{
			return _assetProvider;
		}

		GameplayActuator& ControlContext::getGameplayActuator()
		{
			return _gameplayActuator;
		}

		const input::StateProvider& ControlContext::getInputStateProvider() const
		{
			return _inputStateProvider;
		}
	}
}

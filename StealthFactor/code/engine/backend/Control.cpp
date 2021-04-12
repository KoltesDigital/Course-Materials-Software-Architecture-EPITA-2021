#include "Control.hpp"

#include <engine/backend/ControlContext.hpp>

namespace engine
{
	namespace backend
	{
		Control::Control(Character& character, ControlContext& context)
			: _character{ character }
			, _context{ context }
		{
		}

		Character& Control::getCharacter() const
		{
			return _character;
		}

		assets::AssetProvider& Control::getAssetProvider()
		{
			return _context.getAssetProvider();
		}

		GameplayActuator& Control::getGameplayActuator()
		{
			return _context.getGameplayActuator();
		}

		const input::StateProvider& Control::getInputStateProvider() const
		{
			return _context.getInputStateProvider();
		}
	}
}

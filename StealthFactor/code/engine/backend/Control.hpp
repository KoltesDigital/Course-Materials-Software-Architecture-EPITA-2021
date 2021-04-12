#pragma once

#include <string>

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
		struct Character;
		class ControlContext;
		class GameplayActuator;

		class Control
		{
		public:
			Control(Character& character, ControlContext& context);
			virtual ~Control() = default;

			virtual void update() = 0;

			virtual std::string getPrefabName() const = 0;

		protected:
			Character& getCharacter() const;

			assets::AssetProvider& getAssetProvider();
			GameplayActuator& getGameplayActuator();
			const input::StateProvider& getInputStateProvider() const;

		private:
			Character& _character;
			ControlContext& _context;
		};
	}
}

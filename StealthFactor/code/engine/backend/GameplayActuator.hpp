#pragma once

namespace engine
{
	namespace backend
	{
		struct Character;

		class GameplayActuator
		{
		public:
			virtual void characterMoved(Character& character) = 0;
			virtual void gameOver() = 0;
		};
	}
}

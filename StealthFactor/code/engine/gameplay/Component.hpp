#pragma once

namespace engine
{
	namespace gameplay
	{
		class Entity;

		class EntityContextGameplay;
		class EntityContextGraphics;
		class EntityContextInput;
		class EntityContextPhysics;

		class Component
		{
		public:
			virtual ~Component() = default;

			virtual void update();
			virtual void onTransformChange();

			Entity& getEntity();
			const Entity& getEntity() const;

		protected:
			Component(Entity& entity);

			EntityContextGameplay& getGameplay();
			const EntityContextGameplay& getGameplay() const;

			EntityContextGraphics& getGraphics();
			const EntityContextGraphics& getGraphics() const;

			EntityContextInput& getInput();
			const EntityContextInput& getInput() const;

			EntityContextPhysics& getPhysics();
			const EntityContextPhysics& getPhysics() const;

		private:
			Entity& _entity;
		};
	}
}

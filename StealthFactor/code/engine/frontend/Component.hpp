#pragma once

namespace engine
{
	namespace assets
	{
		class AssetProvider;
	}

	namespace frontend
	{
		class Entity;

		class EntityContextAssets;
		class EntityContextGraphics;

		class Component
		{
		public:
			virtual ~Component() = default;

			virtual void onTransformChange();

			Entity& getEntity();
			const Entity& getEntity() const;

		protected:
			Component(Entity& entity);

			assets::AssetProvider& getAssetProvider();
			const assets::AssetProvider& getAssetProvider() const;

			EntityContextGraphics& getGraphics();
			const EntityContextGraphics& getGraphics() const;

		private:
			Entity& _entity;
		};
	}
}

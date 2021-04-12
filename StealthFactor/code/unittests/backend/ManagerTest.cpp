#include <gtest/gtest.h>

#include <memory>
#include <set>
#include <engine/assets/AssetManager.hpp>
#include <engine/backend/BackendManager.hpp>
#include <engine/backend/Listener.hpp>
#include <engine/input/StateProvider.hpp>

namespace engine
{
	namespace backend
	{
		// Note: actually rather an integration test.
		class ManagerTest : public ::testing::Test
		{
		protected:
			class SpyListener : public Listener
			{
			public:
				const Map* getMap() const
				{
					return _map;
				}

				// Listener

				void onMapLoaded(Map& map) override
				{
					_map = &map;
				}

				void onCharacterMoved(const Character& character) override
				{
					UNUSED(character);
				}

			private:
				Map* _map{};
			};

			class MockInputStateProvider : public input::StateProvider
			{
			public:
				void pressKey(sf::Keyboard::Key key)
				{
					auto itPressed = pressedKeys.insert(key);
					EXPECT_TRUE(itPressed.second) << "Key " << key << " is already pressed.";

					justPressedKeys.insert(key);

					auto justReleasedCount = justReleasedKeys.erase(key);
					EXPECT_EQ(0, justReleasedCount) << "Key " << key << " has just been released, wait for the next frame before pressing it again.";
				}

				void releaseKey(sf::Keyboard::Key key)
				{
					auto pressedCount = pressedKeys.erase(key);
					EXPECT_EQ(1, pressedCount) << "Key " << key << " is already released.";

					auto justPressedCount = justPressedKeys.erase(key);
					EXPECT_EQ(0, justPressedCount) << "Key " << key << " has just been pressed, wait for the next frame before releasing it.";

					justReleasedKeys.insert(key);
				}

				void prepareForNextFrame()
				{
					justPressedKeys.clear();
					justReleasedKeys.clear();
				}

				// StateProvider

				bool isKeyPressed(sf::Keyboard::Key key) const override
				{
					return pressedKeys.find(key) != pressedKeys.end();
				}

				bool isKeyJustPressed(sf::Keyboard::Key key) const override
				{
					return justPressedKeys.find(key) != justPressedKeys.end();
				}

				bool isKeyJustReleased(sf::Keyboard::Key key) const override
				{
					return justReleasedKeys.find(key) != justReleasedKeys.end();
				}

			private:
				std::set<sf::Keyboard::Key> justPressedKeys;
				std::set<sf::Keyboard::Key> justReleasedKeys;
				std::set<sf::Keyboard::Key> pressedKeys;
			};

			assets::Manager _assetManager;
			SpyListener _listener;
			MockInputStateProvider _inputStateProvider;
			std::unique_ptr<Manager> _manager;

			void SetUp() override
			{
				_manager.reset(new Manager{ _listener, _assetManager , _inputStateProvider });
				_manager->loadMap("maps/map.xml");
			}

			void ExpectPlayerAtPosition(int row, int column)
			{
				auto map = _listener.getMap();
				ASSERT_TRUE(map);
				ASSERT_TRUE(map->playerCharacter);
				EXPECT_EQ(Position(row, column), map->playerCharacter->position);
			}
		};

		TEST_F(ManagerTest, MapIsInitialized)
		{
			ExpectPlayerAtPosition(1, 2);
		}

		TEST_F(ManagerTest, PlayerDoesntMoveByItself)
		{
			_inputStateProvider.prepareForNextFrame();
			_manager->update();

			ExpectPlayerAtPosition(1, 2);
		}

		TEST_F(ManagerTest, PlayerMovesWhenKeyIsPressed)
		{
			_inputStateProvider.prepareForNextFrame();
			_inputStateProvider.pressKey(sf::Keyboard::Right);
			_manager->update();

			ExpectPlayerAtPosition(1, 3);
		}

		TEST_F(ManagerTest, PlayerDoesNotMoveAnymoreWhileKeyIsPressed)
		{
			_inputStateProvider.prepareForNextFrame();
			_inputStateProvider.pressKey(sf::Keyboard::Right);
			_manager->update();

			_inputStateProvider.prepareForNextFrame();
			_manager->update();

			ExpectPlayerAtPosition(1, 3);
		}

		TEST_F(ManagerTest, PlayerDoesNotMoveAnymoreWhenKeyIsReleased)
		{
			_inputStateProvider.prepareForNextFrame();
			_inputStateProvider.pressKey(sf::Keyboard::Right);
			_manager->update();

			_inputStateProvider.prepareForNextFrame();
			_inputStateProvider.releaseKey(sf::Keyboard::Right);
			_manager->update();

			ExpectPlayerAtPosition(1, 3);
		}

		TEST_F(ManagerTest, PlayerMovesAgainWhenKeyIsPressedAgain)
		{
			_inputStateProvider.prepareForNextFrame();
			_inputStateProvider.pressKey(sf::Keyboard::Right);
			_manager->update();

			_inputStateProvider.prepareForNextFrame();
			_inputStateProvider.releaseKey(sf::Keyboard::Right);
			_manager->update();

			_inputStateProvider.prepareForNextFrame();
			_inputStateProvider.pressKey(sf::Keyboard::Right);
			_manager->update();

			ExpectPlayerAtPosition(1, 4);
		}
	}
}

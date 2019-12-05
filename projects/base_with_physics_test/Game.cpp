#include "Game.h"

Game::Game(): App()
{
}

Game::~Game()
{
}

Game &Game::inst()
{
	static Game s_instance;
	return s_instance;
}

bool Game::start()
{kage::Physics::init(b2Vec2(0, 9.8));
	//Loading the map
	makeMap.CreateTiles();
	makeMap.Load();

	// Initialise the physics system. Set the default gravity to 9.8m/s^2 down.
	
	// Floor, left wall and right wall static colliders.
	kage::Physics::BoxBuilder().pos(kf::Vector2(15, 16)).size(30, 1).build(kage::Physics::getDefaultStatic());
	kage::Physics::BoxBuilder().pos(kf::Vector2(-0.6f, 8)).size(1, 16).build(kage::Physics::getDefaultStatic());
	kage::Physics::BoxBuilder().pos(kf::Vector2(30.4f, 8)).size(1, 16).build(kage::Physics::getDefaultStatic());



	Ball *theBall = kage::World::build<Ball>();
	theBall->position(6, 12);

	return true;
}

void Game::update(float deltaT)
{
	// You need to update the physics system every game update

	kage::Physics::update(deltaT);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_window.hasFocus())
	{
		m_running = false;
	}

	ImGui::Begin("Kage2D");
	ImGui::End();
}

void Game::render()
{
	// The next line draws the physics debug info. This should be removed in a final release.
	kage::Physics::debugDraw(&m_window, 64);
}

void Game::cleanup()
{
}


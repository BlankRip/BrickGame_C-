#include "example.h"

TheEditor::TheEditor(): App()
{
}

TheEditor::~TheEditor()
{
}

TheEditor &TheEditor::inst()
{
	static TheEditor s_instance;
	return s_instance;
}

bool TheEditor::start()
{kage::Physics::init(b2Vec2(0, 9.8));
	//Loading the map
	makeMap.CreateTiles();
	makeMap.Load();

	// Initialise the physics system. Set the default gravity to 9.8m/s^2 down.
	
	// Floor, left wall and right wall static colliders.
	//kage::Physics::BoxBuilder().pos(kf::Vector2(20, 16)).size(30, 1).build(kage::Physics::getDefaultStatic());
	//kage::Physics::BoxBuilder().pos(kf::Vector2(0, 8)).size(1, 16).build(kage::Physics::getDefaultStatic());
	//kage::Physics::BoxBuilder().pos(kf::Vector2(30, 8)).size(1, 16).build(kage::Physics::getDefaultStatic());


	Rabbit *rabbit = kage::World::build<Rabbit>();
	rabbit->position(2, 4); // Note that this now uses metres instead of pixels.

	return true;
}

void TheEditor::update(float deltaT)
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

void TheEditor::render()
{
	// The next line draws the physics debug info. This should be removed in a final release.
	kage::Physics::debugDraw(&m_window, 64);
}

void TheEditor::cleanup()
{
}


#include "TheEditor.h"


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
{
	//Function to creating the grid on the window
	mapEditorGrid.CreateGrid(m_window);
	//Placeing transparent tiles without colliders in the grid on start
	tilesOnMap.CreateTiles();
	return true;
}

void TheEditor::update(float deltaT)
{
	//Close window when esc is pressed
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_window.hasFocus())
	{
		m_running = false;
	}

	// Function that checks if clicked on a tile and addes a brick if clicked
	tilesOnMap.TileClicked(m_window);

	//The GIU Window stuff
	ImGui::Begin("Kage2D");
	if (ImGui::IsMouseHoveringWindow())
		tilesOnMap.onGuiWindow = true;
	else
		tilesOnMap.onGuiWindow = false;

	tilesOnMap.CreateSpriteChangeButtons();
	if(ImGui::Button("Exit"))
	{ 
		m_running = false;
	}
	ImGui::End();

}

void TheEditor::render()
{
	mapEditorGrid.Draw(m_window);
	// The next line draws the physics debug info. This should be removed in a final release.
	//kage::Physics::debugDraw(&m_window, 64);
}

void TheEditor::cleanup()
{
	delete m_backgroundSprite;
}


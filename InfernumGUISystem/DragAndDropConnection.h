#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Event.hpp>
#include "IGUISElement.h"
#include "Line.h"

namespace IGUIS
{
	/// <summary>
	/// It's a point, that can be connected to other point/s using Line
	/// </summary>
	class DragAndDropConnection : public IGUISElement//TODO: poprawiæ summary
	{
		sf::FloatRect ShapeRect;
		bool MouseOnButton = false;
        sf::RectangleShape Shape;
		std::vector<IGUIS::Line> Line;// TODO: Zrobiæ linije(shape) specjalnie do tego zastosowania
		char ActuallyUsedLine = 0;
		char MaxOutGoingLineCount = 1;
		bool Dragging = false;
	public:
		std::vector<DragAndDropConnection*> CanBeConnectedTo;
		std::vector<DragAndDropConnection*> ConnectedTo;
		int ID = 0;

		/// <summary>
		/// Default 255, 255, 255
		/// </summary>
		sf::Color ShapeColourUnhovered = sf::Color(255, 255, 255);// TODO: zrobiæ state jak w przycisku

		/// <summary>
		/// Default 235, 235, 235
		/// </summary>
		sf::Color ShapeColourHovered = sf::Color(235, 235, 235);

		/// <summary>
		/// Default 215, 215, 215
		/// </summary>
		sf::Color ShapeColourClicked = sf::Color(215, 215, 215);

		/// <summary>
		/// Default 195, 195, 195
		/// </summary>
		sf::Color ShapeColourDeactivated = sf::Color(195, 195, 195);

		DragAndDropConnection();

		/// <param name="MaxOutGoingLineCount"> 0 - 255 </param>
		DragAndDropConnection(IGUIS::Origin Origin, sf::Color ColourUnhovered, sf::Color ColourHovered, sf::Color ColourClicked, sf::Color ColourDeactivated, char MaxOutGoingLineCount, float PositionX, float PositionY, float SizeX, float SizeY, bool IsPositionRelativeToScreen);
		DragAndDropConnection(IGUIS::Origin Origin, char MaxOutGoingLineCount, float PositionX, float PositionY, float SizeX, float SizeY, bool IsPositionRelativeToScreen);
		
		bool ContainPoint(sf::Vector2f Point);

		/// <summary>
		/// Position on screen in %, 1% == 0.1f
		/// </summary>
		void SetPosition(sf::Vector2f Position);

		/// <summary>
		/// Position on screen in %, 1% == 0.1f
		/// </summary>
		void SetPosition(float X, float Y);

		/// <summary>
		/// Position on screen in %, 1% == 0.1f
		/// </summary>
		sf::Vector2f GetPosition();

		void Update(sf::Event* Event);
		void Draw();
	};
}
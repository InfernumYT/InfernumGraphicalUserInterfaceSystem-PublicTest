#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include "IGUISElement.h"

namespace IGUIS
{
	class Slider : public IGUISElement
	{
		sf::RectangleShape ShapeBackground;
		sf::RectangleShape ShapeProgress;
		sf::RectangleShape ShapeHandle;// niech bêdzie mia³o teksturke, ¿eby nie kminiæ nad tym czy kwadratowe zrobiæ czy okr¹g³e
		float FillSize = 0;
	public:
		bool DrawHandle = true;
		Slider();
		Slider(sf::Color BackgroundFillColor, sf::Color BackgroundOutlineColor, sf::Color FillShapeFillColor, sf::Color FillShapeOutlineColor, IGUIS::Origin OriginOfObject, float PositionX, float PositionY, float SizeX, float SizeY, bool IsPositionRelativeToScreen);
		void SetFillSize(float FillSize);
		float GetFillSize();

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

		/// <summary>
		/// Size on screen in %, 1% == 0.1f
		/// </summary>
		void SetSize(sf::Vector2f Size);

		/// <summary>
		/// Size on screen in %, 1% == 0.1f
		/// </summary>
		void SetSize(float X, float Y);

		/// <summary>
		/// Size on screen in %, 1% == 0.1f
		/// </summary>
		sf::Vector2f GetSize();

		void Update();
		void Draw();
	};
}
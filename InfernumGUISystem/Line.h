#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include "IGUISElement.h"

namespace IGUIS
{
	class Line : public IGUISElement
	{
		sf::RectangleShape Shape;
		float Thickness = 1;
		// first point is on position
		// second point is on size
	public:
		Line();
		Line(IGUIS::Origin OriginOfObject, sf::Color FillColor, sf::Color OutlineColor, float Thickness, float OutlineThickness, float Position1X, float Position1Y, float Position2X, float Position2Y, bool IsPositionRelativeToScreen);
		Line(IGUIS::Origin OriginOfObject, sf::Color FillColor, float Thickness, float Position1X, float Position1Y, float Position2X, float Position2Y, bool IsPositionRelativeToScreen);
		bool ContainPoint(sf::Vector2f Point);

		/// <summary>
		/// Position on screen in %, 1% == 0.1f
		/// </summary>
		void SetPositionA(sf::Vector2f Position);

		/// <summary>
		/// Position on screen in %, 1% == 0.1f
		/// </summary>
		void SetPositionA(float X, float Y);

		/// <summary>
		/// Position on screen in %, 1% == 0.1f
		/// </summary>
		sf::Vector2f GetPositionA();

		/// <summary>
		/// Size on screen in %, 1% == 0.1f
		/// </summary>
		void SetPositionB(sf::Vector2f Size);

		/// <summary>
		/// Size on screen in %, 1% == 0.1f
		/// </summary>
		void SetPositionB(float X, float Y);

		/// <summary>
		/// Size on screen in %, 1% == 0.1f
		/// </summary>
		sf::Vector2f GetPositionB();

		void Update();
		void Draw();
	};
}
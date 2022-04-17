#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Event.hpp>
#include "IGUISElement.h"

namespace IGUIS
{
	class Progressbar : public IGUISElement
	{
		sf::RectangleShape ShapeBackground;
		sf::RectangleShape FillShape;
		float FillSize = 0;
	public:
		Progressbar();
		/// <param name="SizeX"> set (1 / 16.0f * x) to make square :) </param>
		/// <param name="SizeY"> set (1 / 9.0f * x) to make square :) </param>
		Progressbar(sf::Color BackgroundFillColor, sf::Color BackgroundOutlineColor, sf::Color FillShapeFillColor, sf::Color FillShapeOutlineColor, IGUIS::Origin OriginOfObject, float PositionX, float PositionY, float SizeX, float SizeY, bool IsPositionRelativeToScreen);
		void SetBackgroundFillColor(sf::Color Color);
		const sf::Color GetBackgroundFillColor();
		void SetBackgroundOutlineColor(sf::Color OutlineColor);
		const sf::Color GetBackgroundOutlineColor();
		void SetFillShapeFillColor(sf::Color Color);
		const sf::Color GetFillShapeFillColor();
		void SetFillShapeOutlineColor(sf::Color OutlineColor);
		const sf::Color GetFillShapeOutlineColor();
		void SetFillSize(float FillSize);
		float GetFillSize();
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
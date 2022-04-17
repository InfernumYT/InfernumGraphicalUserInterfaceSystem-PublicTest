#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "IGUISElement.h"

namespace IGUIS
{
	class Shape : public IGUISElement
	{
		sf::RectangleShape ShapeVar;
	public:
		Shape();
		/// <param name="SizeX"> set (1 / 16.0f * x) to make square :) </param>
		/// <param name="SizeY"> set (1 / 9.0f * x) to make square :) </param>
		Shape(const sf::Texture* Texture, sf::Color Color, IGUIS::Origin OriginOfObject, float PositionX, float PositionY, float SizeX, float SizeY, bool IsPositionRelativeToScreen);
		/// <param name="SizeX"> set (1 / 16.0f * x) to make square :) </param>
		/// <param name="SizeY"> set (1 / 9.0f * x) to make square :) </param>
		Shape(const sf::Texture* Texture, IGUIS::Origin OriginOfObject, float PositionX, float PositionY, float SizeX, float SizeY, bool IsPositionRelativeToScreen);
		/// <param name="SizeX"> set (1 / 16.0f * x) to make square :) </param>
		/// <param name="SizeY"> set (1 / 9.0f * x) to make square :) </param>
		Shape(sf::Color Color, IGUIS::Origin OriginOfObject, float PositionX, float PositionY, float SizeX, float SizeY, bool IsPositionRelativeToScreen);
		void SetFillColor(sf::Color Color);
		const sf::Color GetFillColor();
		void SetOutlineColor(sf::Color OutlineColor);
		const sf::Color GetOutlineColor();
		void SetOutlineThickness(float OutlineThickness);
		const float GetOutlineThickness();
		void SetTexture(const sf::Texture* Texture);
		const sf::Texture* GetTexture();
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
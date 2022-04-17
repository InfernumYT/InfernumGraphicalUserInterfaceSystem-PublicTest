#pragma once
#include <SFML/Graphics/Text.hpp>
#include "IGUISElement.h"

namespace IGUIS
{
	class Text : public IGUISElement
	{
		float MaxSize = 0.1f;// zrobiæ z tym po¿ytek
		sf::Text TextVar;
	public:
		Text();
		/// <param name="Quality"> - default is 30 </param>
		/// <param name="FillColor"> - default is white </param>
		/// <param name="OutlineColor"> - default is transparent </param>
		Text(std::wstring String, sf::Font* Font, IGUIS::Origin OriginOfObject, unsigned int Quality, sf::Color FillColor, sf::Color OutlineColor, float OutlineThickness, float PositionX, float PositionY, float SizeX, float SizeY, bool IsPositionRelativeToScreen);
		Text(std::wstring String, sf::Font* Font, IGUIS::Origin OriginOfObject, unsigned int Quality, sf::Color FillColor, float PositionX, float PositionY, float SizeX, float SizeY, bool IsPositionRelativeToScreen);
		void SetQuality(unsigned int Quality);// wywaliæ to i zrobiæ ¿eby quality by³o zawsze ustawiane na tyle na ile wysoki jest tekst|| nie mo¿na tak zrobiæ bo wydajnoœæ zabija dos³ownie ca³¹
		unsigned int GetQuality();
		// AlignmentHorizontal
		// AlignmentVertical
		void SetFont(sf::Font Font);
		const sf::Font* GetFont();
		void SetFillColor(sf::Color Color);
		const sf::Color GetFillColor();
		void SetOutlineColor(sf::Color OutlineColor);
		const sf::Color GetOutlineColor();
		void SetOutlineThickness(float OutlineThickness);
		const float GetOutlineThickness();
		void SetString(std::wstring String);
		std::wstring GetString();
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
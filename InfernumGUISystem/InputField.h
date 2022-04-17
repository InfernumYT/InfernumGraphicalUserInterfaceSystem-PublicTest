#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>
#include "IGUISElement.h"

namespace IGUIS
{
	class InputField : public IGUISElement
	{
		sf::RectangleShape Background;
		sf::Text TextVar;
		bool Typing = false;
	public:
		InputField();
		/// <param name="Quality"> - default is 30 </param>
		/// <param name="FillColor"> - default is white </param>
		/// <param name="OutlineColor"> - default is transparent </param>
		InputField(std::wstring String, sf::Font* Font, IGUIS::Origin OriginOfObject, float PositionX, float PositionY, float SizeX, float SizeY, bool IsPositionRelativeToScreen);
		InputField(sf::Font* Font, IGUIS::Origin OriginOfObject, float PositionX, float PositionY, float SizeX, float SizeY, bool IsPositionRelativeToScreen);
		void SetQuality(uint8_t ID, unsigned int Quality);
		unsigned int GetQuality(uint8_t ID);
		void SetFont(uint8_t ID, sf::Font Font);
		const sf::Font* GetFont(uint8_t ID);
		void SetFillColor(uint8_t ID, sf::Color Color);
		const sf::Color GetFillColor(uint8_t ID);
		void SetOutlineColor(uint8_t ID, sf::Color OutlineColor);
		const sf::Color GetOutlineColor(uint8_t ID);
		void SetString(uint8_t ID, std::wstring String);
		std::wstring GetString(uint8_t ID);
		bool ContainPoint(sf::Vector2f Point);
		void TextEntred(sf::Uint32 Key);

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

		void Update(sf::Event* Event);
		void Draw();
	};
}
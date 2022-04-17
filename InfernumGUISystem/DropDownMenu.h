#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Text.hpp>
#include "IGUISElement.h"

namespace IGUIS
{
	class DropDownMenu : public IGUISElement
	{
		std::vector<std::string> Options;
		sf::RectangleShape Background;
		sf::Text Text;
		sf::RectangleShape xBackground;
		sf::Text xText;
		sf::FloatRect ShapeRect;
		bool MouseOnButton = false;
	public:
		/// <summary>
		/// Possible output:
		/// <para>0 - unhovered once</para>
		/// <para>1 - unhovered</para>
		/// <para>2 - hovered once</para>
		/// <para>3 - hovered</para>
		/// <para>4 - clicked once</para>
		/// <para>5 - clicked</para>
		/// <para>6 - unclicked once</para>
		/// <para>7 - unactive</para>
		/// </summary>
		uint8_t State = 1;
		bool IsOpen = false;

		/// <summary>
		/// Default 255, 255, 255
		/// </summary>
		sf::Color ShapeColourUnhovered = sf::Color(255, 255, 255);

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

		/// <summary>
		/// Can be clicked?
		/// </summary>
		bool IsActive = true;

		DropDownMenu();
		/// <param name="SizeX"> set (1 / 16.0f * x) to make square :) </param>
		/// <param name="SizeY"> set (1 / 9.0f * x) to make square :) </param>
		DropDownMenu(sf::Font* Font, sf::Color ColourUnhovered, sf::Color ColourHovered, sf::Color ColourClicked, sf::Color ColourDeactivated, IGUIS::Origin OriginOfObject, float PositionX, float PositionY, float SizeX, float SizeY, bool IsPositionRelativeToScreen);
		DropDownMenu(sf::Font* Font, IGUIS::Origin OriginOfObject, float PositionX, float PositionY, float SizeX, float SizeY, bool IsPositionRelativeToScreen);
		void AddOption(std::string String);
		//void AddOption(std::vector<std::string> String);
		//void RemoveOption(std::string String);
		//void RemoveOptions();
		//std::vector<std::string> GetOptions();
		std::string GetSellectedOption();
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

		void Update(sf::Event *Event);
		void Draw();
	};
}
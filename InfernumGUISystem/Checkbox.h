#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "IGUISElement.h"

namespace IGUIS
{
	/// <summary>
	/// Checkbox maked with image, it changes colour on hover and click
	/// </summary>
	class Checkbox : public IGUISElement
	{
		sf::FloatRect ShapeRect;
		bool MouseOnButton = false;
		sf::RectangleShape Shape;
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
		uint8_t State = 7;

		const sf::Texture* ShapeTextureIfTurnedOff;

		const sf::Texture* ShapeTextureIfTurnedOn;

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

		/// <summary>
		/// Used for read on/off, or setting on/off
		/// </summary>
		bool IsTurnedOn = false;

		Checkbox();
		/// <param name="SizeX"> set (1 / 16.0f * x) to make square :) </param>
		/// <param name="SizeY"> set (1 / 9.0f * x) to make square :) </param>
		Checkbox(const sf::Texture* TextureIfTurnedOff, const sf::Texture* TextureIfTurnedOn, sf::Color ColourUnhovered, sf::Color ColourHovered, sf::Color ColourClicked, sf::Color ColourDeactivated, IGUIS::Origin OriginOfObject, float PositionX, float PositionY, float SizeX, float SizeY, bool IsPositionRelativeToScreen);
		Checkbox(const sf::Texture* TextureIfTurnedOff, const sf::Texture* TextureIfTurnedOn, IGUIS::Origin OriginOfObject, float PositionX, float PositionY, float SizeX, float SizeY, bool IsPositionRelativeToScreen);
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

		void Update(sf::Event* Event);
		void Draw();
	};
}
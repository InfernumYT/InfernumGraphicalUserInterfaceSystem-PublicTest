#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Origin.h"

namespace IGUIS
{
	/// <summary>
	/// Every IGUIS element inherits that class
	/// </summary>
	class IGUISElement
	{
	protected:
		static sf::Sound SpeakerHovered;//TODO: porobiæ metody np. setPitch()
		static sf::Sound SpeakerUnhovered;
		static sf::Sound SpeakerClicked;
		static sf::RenderWindow* Window;
		sf::Vector2f Position = sf::Vector2f();
		sf::Vector2f Size = sf::Vector2f();//TODO: zrobiæ outlinethickness jako RelativeToZoom,  zrobiæ void co bêdzie do tego s³u¿y³(jak bedzie potrzeba to bêdzie to wo³ane)
		sf::Vector2f GetPositionOnScreenInPxUsingPencentageAndOrigin(IGUIS::Origin Origin, sf::Vector2f Position, sf::Vector2f Size);
		sf::Vector2f GetPositionOnScreenInPxUsingPencentageAndOrigin(IGUIS::Origin Origin, sf::Vector2f Position);
	public:
		static const std::string VersionOfIGUIS;

		/// <summary>
		/// Used to set static Window* variable in IGUIS
		/// </summary>
		static void SetWindow(sf::RenderWindow* Window);

		/// <summary>
		/// Used to get static Window* variable from IGUIS
		/// </summary>
		static sf::RenderWindow* GetWindow();

		/// <summary>
		/// Used to set where is 0, 0 position for that object
		/// </summary>
		IGUIS::Origin Origin = Origin::Middle;

		/// <summary>
		/// if false, origin is not used and position is in px
		/// </summary>
		bool PositionRelativeToScreen = true;

		/// <summary>
		/// Used to set static volume of sounds in IGUIS
		/// <para> Scale from 0 to 100 </para>
		/// </summary>
		static void SetVolume(float Volume);

		/// <summary>
		/// Used to set static sounds in IGUIS
		/// </summary>
		static void SetSounds(sf::SoundBuffer* Hovered, sf::SoundBuffer* Unhovered, sf::SoundBuffer* Clicked);

		/// <summary>
		/// Used to set static sound in IGUIS
		/// </summary>
		static void SetSoundWhenHovered(sf::SoundBuffer* Hovered);

		/// <summary>
		/// Used to set static sound in IGUIS
		/// </summary>
		static void SetSoundWhenUnhovered(sf::SoundBuffer* Unhovered);

		/// <summary>
		/// Used to set static sound in IGUIS
		/// </summary>
		static void SetSoundWhenClicked(sf::SoundBuffer* Clicked);
	};
}
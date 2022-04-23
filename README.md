# InfernumGraphicalUserInterfaceSystem-PublicTest
Publiczne testy projektu GUI dla c++/SFML<br/>
Discord: https://discord.gg/qNuvdCDqz7

Projekt będzie rozwijany powoli(ze zwględu na mało czasu wolnego), chyba że będzie cieszył się zainteresowaniem

Jest to projekt tworzony aktualnie tylko dla własnego użytku, zawiera wiele nie dokończonych funkcji, wiadomo wczesna wersja

Jeśli ktoś ma jakieś pomysły, prosze dodawać na Issues

Nie jestem profesjonalnym programistą, jest to dla mnie hobby w którym chce zrobić coś sensownego

Tworze ten projekt, dlatego że chce zobaczyć jak wygląda tworzenie tak podstawowych elementów, z czego napewno wezme doświadczenie do tworzenia innych projektów

:) mam zaczęty projekt gry, narazie go nie upubliczniam

Example code:

	#include <iostream>
	#include "SFML/Audio.hpp"
	#include "InfernumGUISystem/Button.h"

/// main<br/>

	// inicjalizacja
	IGUIS::IGUISElement::SetWindow(&Window);
		
	sf::Texture ButtonTexture;
	ButtonTexture.loadFromFile("Button.png");
	IGUIS::Button Button(&ButtonTexture, IGUIS::Origin::Middle, 0.0f, 0.0f, 1 / 16.0f, 1 / 9.0f, true);
		
///

/// audio initialization

	sf::SoundBuffer Hovered;
	sf::SoundBuffer Unhovered;
	sf::SoundBuffer Clicked;

	Hovered.loadFromFile("Audio/52.wav");
	Unhovered.loadFromFile("Audio/522.wav");
	Clicked.loadFromFile("Audio/122.wav");
	
	IGUIS::IGUISElement::SetSounds(&Hovered, &Unhovered, &Clicked);
	IGUIS::IGUISElement::SetVolume(10);

///

/// main program loop<br/>

	Button.Update();
	if (Button.State == 4)
	{
		std::cout << "Button clicked" << std::endl;
	}
	
	Button.Draw();

///

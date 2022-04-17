#include "IGUISElement.h"

sf::Sound IGUIS::IGUISElement::SpeakerHovered = sf::Sound();
sf::Sound IGUIS::IGUISElement::SpeakerUnhovered = sf::Sound();
sf::Sound IGUIS::IGUISElement::SpeakerClicked = sf::Sound();
sf::RenderWindow* IGUIS::IGUISElement::Window;
const std::string IGUIS::IGUISElement::VersionOfIGUIS = "PreAlpha";

sf::Vector2f IGUIS::IGUISElement::GetPositionOnScreenInPxUsingPencentageAndOrigin(IGUIS::Origin Origin, sf::Vector2f Position, sf::Vector2f Size)
{
    switch (Origin)
    {
    case IGUIS::Origin::Middle:
        return sf::Vector2f(IGUIS::IGUISElement::Window->getView().getCenter() + sf::Vector2f(Position.x * IGUIS::IGUISElement::Window->getView().getSize().x, Position.y * IGUIS::IGUISElement::Window->getView().getSize().y));
        break;
    case IGUIS::Origin::Bottom:
        return sf::Vector2f(IGUIS::IGUISElement::Window->getView().getCenter() + sf::Vector2f(Position.x * IGUIS::IGUISElement::Window->getView().getSize().x, Position.y * IGUIS::IGUISElement::Window->getView().getSize().y) + sf::Vector2f(0, IGUIS::IGUISElement::Window->getView().getSize().y / 2 - Size.y / 2 * IGUIS::IGUISElement::Window->getView().getSize().y));
        break;
    case IGUIS::Origin::Top:
        return sf::Vector2f(IGUIS::IGUISElement::Window->getView().getCenter() + sf::Vector2f(Position.x * IGUIS::IGUISElement::Window->getView().getSize().x, Position.y * IGUIS::IGUISElement::Window->getView().getSize().y) + sf::Vector2f(0, -IGUIS::IGUISElement::Window->getView().getSize().y / 2 + Size.y / 2 * IGUIS::IGUISElement::Window->getView().getSize().y));
        break;
    case IGUIS::Origin::LeftTop:
        return sf::Vector2f(IGUIS::IGUISElement::Window->getView().getCenter() + sf::Vector2f(Position.x * IGUIS::IGUISElement::Window->getView().getSize().x, Position.y * IGUIS::IGUISElement::Window->getView().getSize().y) + sf::Vector2f(-IGUIS::IGUISElement::Window->getView().getSize().x / 2 + Size.x / 2 * IGUIS::IGUISElement::Window->getView().getSize().x, -IGUIS::IGUISElement::Window->getView().getSize().y / 2 + Size.y / 2 * IGUIS::IGUISElement::Window->getView().getSize().y));
        break;
    case IGUIS::Origin::LeftMiddle:
        return sf::Vector2f(IGUIS::IGUISElement::Window->getView().getCenter() + sf::Vector2f(Position.x * IGUIS::IGUISElement::Window->getView().getSize().x, Position.y * IGUIS::IGUISElement::Window->getView().getSize().y) + sf::Vector2f(-IGUIS::IGUISElement::Window->getView().getSize().x / 2 + Size.x / 2 * IGUIS::IGUISElement::Window->getView().getSize().x, 0));
        break;
    case IGUIS::Origin::LeftBotton:
        return sf::Vector2f(IGUIS::IGUISElement::Window->getView().getCenter() + sf::Vector2f(Position.x * IGUIS::IGUISElement::Window->getView().getSize().x, Position.y * IGUIS::IGUISElement::Window->getView().getSize().y) + sf::Vector2f(-IGUIS::IGUISElement::Window->getView().getSize().x / 2 + Size.x / 2 * IGUIS::IGUISElement::Window->getView().getSize().x, IGUIS::IGUISElement::Window->getView().getSize().y / 2 - Size.y / 2 * IGUIS::IGUISElement::Window->getView().getSize().y));
        break;
    case IGUIS::Origin::RightTop:
        return sf::Vector2f(IGUIS::IGUISElement::Window->getView().getCenter() + sf::Vector2f(Position.x * IGUIS::IGUISElement::Window->getView().getSize().x, Position.y * IGUIS::IGUISElement::Window->getView().getSize().y) + sf::Vector2f(IGUIS::IGUISElement::Window->getView().getSize().x / 2 - Size.x / 2 * IGUIS::IGUISElement::Window->getView().getSize().x, -IGUIS::IGUISElement::Window->getView().getSize().y / 2 + Size.y / 2 * IGUIS::IGUISElement::Window->getView().getSize().y));
        break;
    case IGUIS::Origin::RightMiddle:
        return sf::Vector2f(IGUIS::IGUISElement::Window->getView().getCenter() + sf::Vector2f(Position.x * IGUIS::IGUISElement::Window->getView().getSize().x, Position.y * IGUIS::IGUISElement::Window->getView().getSize().y) + sf::Vector2f(IGUIS::IGUISElement::Window->getView().getSize().x / 2 - Size.x / 2 * IGUIS::IGUISElement::Window->getView().getSize().x, 0));
        break;
    case IGUIS::Origin::RightBotton:
        return sf::Vector2f(IGUIS::IGUISElement::Window->getView().getCenter() + sf::Vector2f(Position.x * IGUIS::IGUISElement::Window->getView().getSize().x, Position.y * IGUIS::IGUISElement::Window->getView().getSize().y) + sf::Vector2f(IGUIS::IGUISElement::Window->getView().getSize().x / 2 - Size.x / 2 * IGUIS::IGUISElement::Window->getView().getSize().x, IGUIS::IGUISElement::Window->getView().getSize().y / 2 - Size.y / 2 * IGUIS::IGUISElement::Window->getView().getSize().y));
        break;
    default:
        break;
    }
}

sf::Vector2f IGUIS::IGUISElement::GetPositionOnScreenInPxUsingPencentageAndOrigin(IGUIS::Origin Origin, sf::Vector2f Position)
{
    switch (Origin)
    {
    case IGUIS::Origin::Middle:
        return sf::Vector2f(IGUIS::IGUISElement::Window->getView().getCenter() + sf::Vector2f(Position.x * IGUIS::IGUISElement::Window->getView().getSize().x, Position.y * IGUIS::IGUISElement::Window->getView().getSize().y));
        break;
    case IGUIS::Origin::Bottom:
        return sf::Vector2f(IGUIS::IGUISElement::Window->getView().getCenter() + sf::Vector2f(Position.x * IGUIS::IGUISElement::Window->getView().getSize().x, Position.y * IGUIS::IGUISElement::Window->getView().getSize().y) + sf::Vector2f(0, IGUIS::IGUISElement::Window->getView().getSize().y / 2));
        break;
    case IGUIS::Origin::Top:
        return sf::Vector2f(IGUIS::IGUISElement::Window->getView().getCenter() + sf::Vector2f(Position.x * IGUIS::IGUISElement::Window->getView().getSize().x, Position.y * IGUIS::IGUISElement::Window->getView().getSize().y) + sf::Vector2f(0, -IGUIS::IGUISElement::Window->getView().getSize().y / 2));
        break;
    case IGUIS::Origin::LeftTop:
        return sf::Vector2f(IGUIS::IGUISElement::Window->getView().getCenter() + sf::Vector2f(Position.x * IGUIS::IGUISElement::Window->getView().getSize().x, Position.y * IGUIS::IGUISElement::Window->getView().getSize().y) + sf::Vector2f(-IGUIS::IGUISElement::Window->getView().getSize().x / 2, -IGUIS::IGUISElement::Window->getView().getSize().y / 2));
        break;
    case IGUIS::Origin::LeftMiddle:
        return sf::Vector2f(IGUIS::IGUISElement::Window->getView().getCenter() + sf::Vector2f(Position.x * IGUIS::IGUISElement::Window->getView().getSize().x, Position.y * IGUIS::IGUISElement::Window->getView().getSize().y) + sf::Vector2f(-IGUIS::IGUISElement::Window->getView().getSize().x / 2, 0));
        break;
    case IGUIS::Origin::LeftBotton:
        return sf::Vector2f(IGUIS::IGUISElement::Window->getView().getCenter() + sf::Vector2f(Position.x * IGUIS::IGUISElement::Window->getView().getSize().x, Position.y * IGUIS::IGUISElement::Window->getView().getSize().y) + sf::Vector2f(-IGUIS::IGUISElement::Window->getView().getSize().x / 2, IGUIS::IGUISElement::Window->getView().getSize().y / 2));
        break;
    case IGUIS::Origin::RightTop:
        return sf::Vector2f(IGUIS::IGUISElement::Window->getView().getCenter() + sf::Vector2f(Position.x * IGUIS::IGUISElement::Window->getView().getSize().x, Position.y * IGUIS::IGUISElement::Window->getView().getSize().y) + sf::Vector2f(IGUIS::IGUISElement::Window->getView().getSize().x / 2, -IGUIS::IGUISElement::Window->getView().getSize().y / 2));
        break;
    case IGUIS::Origin::RightMiddle:
        return sf::Vector2f(IGUIS::IGUISElement::Window->getView().getCenter() + sf::Vector2f(Position.x * IGUIS::IGUISElement::Window->getView().getSize().x, Position.y * IGUIS::IGUISElement::Window->getView().getSize().y) + sf::Vector2f(IGUIS::IGUISElement::Window->getView().getSize().x / 2, 0));
        break;
    case IGUIS::Origin::RightBotton:
        return sf::Vector2f(IGUIS::IGUISElement::Window->getView().getCenter() + sf::Vector2f(Position.x * IGUIS::IGUISElement::Window->getView().getSize().x, Position.y * IGUIS::IGUISElement::Window->getView().getSize().y) + sf::Vector2f(IGUIS::IGUISElement::Window->getView().getSize().x / 2, IGUIS::IGUISElement::Window->getView().getSize().y / 2));
        break;
    default:
        break;
    }
}

void IGUIS::IGUISElement::SetWindow(sf::RenderWindow* Window)
{
    IGUIS::IGUISElement::Window = Window;
}

sf::RenderWindow* IGUIS::IGUISElement::GetWindow()
{
    return IGUIS::IGUISElement::Window;
}

void IGUIS::IGUISElement::SetVolume(float Volume)
{
	IGUIS::IGUISElement::SpeakerHovered.setVolume(Volume);
	IGUIS::IGUISElement::SpeakerUnhovered.setVolume(Volume);
	IGUIS::IGUISElement::SpeakerClicked.setVolume(Volume);
}

void IGUIS::IGUISElement::SetSounds(sf::SoundBuffer* Hovered, sf::SoundBuffer* Unhovered, sf::SoundBuffer* Clicked)
{
	IGUIS::IGUISElement::SpeakerHovered.setBuffer(*Hovered);
	IGUIS::IGUISElement::SpeakerUnhovered.setBuffer(*Unhovered);
	IGUIS::IGUISElement::SpeakerClicked.setBuffer(*Clicked);
}

void IGUIS::IGUISElement::SetSoundWhenHovered(sf::SoundBuffer* Hovered)
{
	IGUIS::IGUISElement::SpeakerHovered.setBuffer(*Hovered);
}

void IGUIS::IGUISElement::SetSoundWhenUnhovered(sf::SoundBuffer* Unhovered)
{
	IGUIS::IGUISElement::SpeakerUnhovered.setBuffer(*Unhovered);
}

void IGUIS::IGUISElement::SetSoundWhenClicked(sf::SoundBuffer* Clicked)
{
	IGUIS::IGUISElement::SpeakerClicked.setBuffer(*Clicked);
}
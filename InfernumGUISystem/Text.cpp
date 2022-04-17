#include "Text.h"

IGUIS::Text::Text()
{

}

IGUIS::Text::Text(std::wstring String, sf::Font* Font, IGUIS::Origin OriginOfObject, unsigned int Quality, sf::Color FillColor, sf::Color OutlineColor, float OutlineThickness, float PositionX, float PositionY, float SizeX, float SizeY, bool IsPositionRelativeToScreen)
{
    IGUIS::Text::TextVar.setString(String);
    IGUIS::Text::TextVar.setFont(*Font);
    IGUIS::Text::Origin = OriginOfObject;
    IGUIS::Text::TextVar.setCharacterSize(Quality);
    IGUIS::Text::TextVar.setFillColor(FillColor);
    IGUIS::Text::TextVar.setOutlineColor(OutlineColor);
    IGUIS::Text::TextVar.setOutlineThickness(OutlineThickness);
    IGUIS::Text::Position = sf::Vector2f(PositionX, PositionY);
    IGUIS::Text::Size = sf::Vector2f(SizeX, SizeY);
    IGUIS::Text::PositionRelativeToScreen = IsPositionRelativeToScreen;
}

IGUIS::Text::Text(std::wstring String, sf::Font* Font, IGUIS::Origin OriginOfObject, unsigned int Quality, sf::Color FillColor, float PositionX, float PositionY, float SizeX, float SizeY, bool IsPositionRelativeToScreen)
{
    IGUIS::Text::TextVar.setFont(*Font);
    IGUIS::Text::TextVar.setString(String);
    IGUIS::Text::Origin = OriginOfObject;
    IGUIS::Text::TextVar.setCharacterSize(Quality);
    IGUIS::Text::TextVar.setFillColor(FillColor);
    IGUIS::Text::Position = sf::Vector2f(PositionX, PositionY);
    IGUIS::Text::Size = sf::Vector2f(SizeX, SizeY);
    IGUIS::Text::PositionRelativeToScreen = IsPositionRelativeToScreen;
}

void IGUIS::Text::SetQuality(unsigned int Quality)
{
    TextVar.setCharacterSize(Quality);
}

unsigned int IGUIS::Text::GetQuality()
{
    return TextVar.getCharacterSize();
}

void IGUIS::Text::SetFont(sf::Font Font)
{
    TextVar.setFont(Font);
}

const sf::Font* IGUIS::Text::GetFont()
{
    return TextVar.getFont();
}

void IGUIS::Text::SetFillColor(sf::Color FillColor)
{
    TextVar.setFillColor(FillColor);
}

const sf::Color IGUIS::Text::GetFillColor()
{
    return TextVar.getFillColor();
}

void IGUIS::Text::SetOutlineColor(sf::Color OutlineColor)
{
    TextVar.setOutlineColor(OutlineColor);
}

const sf::Color IGUIS::Text::GetOutlineColor()
{
    return TextVar.getOutlineColor();
}

void IGUIS::Text::SetOutlineThickness(float OutlineThickness)
{
    TextVar.setOutlineThickness(OutlineThickness);
}

const float IGUIS::Text::GetOutlineThickness()
{
    return TextVar.getOutlineThickness();
}

void IGUIS::Text::SetString(std::wstring String)
{
    TextVar.setString(String);
}

std::wstring IGUIS::Text::GetString()
{
    return TextVar.getString();
}

bool IGUIS::Text::ContainPoint(sf::Vector2f Point)
{
    return TextVar.getGlobalBounds().contains(Point);
}

void IGUIS::Text::SetPosition(sf::Vector2f Position)
{
    IGUIS::IGUISElement::Position = Position;
}

void IGUIS::Text::SetPosition(float X, float Y)
{
    IGUIS::IGUISElement::Position = sf::Vector2f(X, Y);
}

sf::Vector2f IGUIS::Text::GetPosition()
{
    return IGUIS::IGUISElement::Position;
}

void IGUIS::Text::SetSize(sf::Vector2f Size)
{
    IGUIS::IGUISElement::Size = Size;
}

void IGUIS::Text::SetSize(float X, float Y)
{
    IGUIS::IGUISElement::Size = sf::Vector2f(X, Y);
}

sf::Vector2f IGUIS::Text::GetSize()
{
    return IGUIS::IGUISElement::Size;
}

void IGUIS::Text::Update()
{
    if (IGUIS::IGUISElement::PositionRelativeToScreen) // if position must be relative to screen
    {
        IGUIS::Text::TextVar.setPosition(IGUIS::IGUISElement::GetPositionOnScreenInPxUsingPencentageAndOrigin(IGUIS::IGUISElement::Origin, IGUIS::IGUISElement::Position, IGUIS::IGUISElement::Size));
    }
    else // if position must be relative to screen
    {
        IGUIS::Text::TextVar.setPosition(IGUIS::IGUISElement::Position);
    }
    //TextVar.setCharacterSize(TextVar.getLocalBounds().height); // nie mo¿na tego ustawiaæ ci¹gle bo lagi w ... du¿o
    IGUIS::Text::TextVar.setOrigin(IGUIS::Text::TextVar.getLocalBounds().width / 2, IGUIS::Text::TextVar.getLocalBounds().height / 2);
    IGUIS::Text::TextVar.setScale(IGUIS::IGUISElement::Size.x * IGUIS::IGUISElement::Window->getView().getSize().x / IGUIS::Text::TextVar.getLocalBounds().width, IGUIS::IGUISElement::Size.y * IGUIS::IGUISElement::Window->getView().getSize().y / IGUIS::Text::TextVar.getLocalBounds().height);
    IGUIS::Text::TextVar.setOrigin(IGUIS::Text::TextVar.getLocalBounds().width / 2, IGUIS::Text::TextVar.getLocalBounds().height / 2);
}

void IGUIS::Text::Draw()
{
    IGUIS::IGUISElement::Window->draw(IGUIS::Text::TextVar);
}
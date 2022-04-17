#include "Slider.h"

IGUIS::Slider::Slider()
{

}

IGUIS::Slider::Slider(sf::Color BackgroundFillColor, sf::Color BackgroundOutlineColor, sf::Color FillShapeFillColor, sf::Color FillShapeOutlineColor, IGUIS::Origin OriginOfObject, float PositionX, float PositionY, float SizeX, float SizeY, bool IsPositionRelativeToScreen)
{
    IGUIS::Slider::ShapeBackground.setFillColor(BackgroundFillColor);
    IGUIS::Slider::ShapeBackground.setOutlineColor(BackgroundOutlineColor);
    IGUIS::Slider::ShapeProgress.setFillColor(FillShapeFillColor);
    IGUIS::Slider::ShapeProgress.setOutlineColor(FillShapeOutlineColor);
    IGUIS::Slider::Origin = OriginOfObject;
    IGUIS::Slider::Position = sf::Vector2f(PositionX, PositionY);
    IGUIS::Slider::Size = sf::Vector2f(SizeX, SizeY);
    IGUIS::Slider::PositionRelativeToScreen = IsPositionRelativeToScreen;
}

void IGUIS::Slider::SetFillSize(float FillSize)
{
    IGUIS::Slider::FillSize = FillSize;
}

float IGUIS::Slider::GetFillSize()
{
    return FillSize;
}

void IGUIS::Slider::SetPosition(sf::Vector2f Position)
{
    IGUIS::IGUISElement::Position = Position;
}

void IGUIS::Slider::SetPosition(float X, float Y)
{
    IGUIS::IGUISElement::Position = sf::Vector2f(X, Y);
}

sf::Vector2f IGUIS::Slider::GetPosition()
{
    return IGUIS::IGUISElement::Position;
}

void IGUIS::Slider::SetSize(sf::Vector2f Size)
{
    IGUIS::IGUISElement::Size = Size;
}

void IGUIS::Slider::SetSize(float X, float Y)
{
    IGUIS::IGUISElement::Size = sf::Vector2f(X, Y);
}

sf::Vector2f IGUIS::Slider::GetSize()
{
    return IGUIS::IGUISElement::Size;
}

void IGUIS::Slider::Update()
{
    if (IGUIS::IGUISElement::PositionRelativeToScreen) // if position must be relative to screen
    {
        IGUIS::Slider::ShapeBackground.setPosition(IGUIS::IGUISElement::GetPositionOnScreenInPxUsingPencentageAndOrigin(IGUIS::IGUISElement::Origin, IGUIS::IGUISElement::Position, IGUIS::IGUISElement::Size));
    }
    else // if position must be relative to screen
    {
        ShapeBackground.setPosition(Position);
    }
    IGUIS::Slider::ShapeBackground.setSize(sf::Vector2f(IGUIS::IGUISElement::Size.x * IGUIS::IGUISElement::Window->getView().getSize().x, IGUIS::IGUISElement::Size.y * IGUIS::IGUISElement::Window->getView().getSize().y));
    IGUIS::Slider::ShapeBackground.setOrigin(IGUIS::Slider::ShapeBackground.getSize().x / 2, IGUIS::Slider::ShapeBackground.getSize().y / 2);

    IGUIS::Slider::ShapeProgress.setSize(sf::Vector2f(IGUIS::Slider::ShapeBackground.getSize().x * IGUIS::Slider::FillSize, IGUIS::Slider::ShapeBackground.getSize().y));
    IGUIS::Slider::ShapeProgress.setPosition(sf::Vector2f(IGUIS::Slider::ShapeBackground.getPosition().x - IGUIS::Slider::ShapeBackground.getSize().x / 2, IGUIS::Slider::ShapeBackground.getPosition().y - IGUIS::Slider::ShapeBackground.getSize().y / 2));
}

void IGUIS::Slider::Draw()
{
    IGUIS::IGUISElement::Window->draw(IGUIS::Slider::ShapeBackground);
    IGUIS::IGUISElement::Window->draw(IGUIS::Slider::ShapeProgress);
    if (IGUIS::Slider::DrawHandle)
    {
        IGUIS::IGUISElement::Window->draw(IGUIS::Slider::ShapeHandle);
    }
}
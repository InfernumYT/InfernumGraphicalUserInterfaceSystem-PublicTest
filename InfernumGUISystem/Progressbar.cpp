#include "Progressbar.h"

IGUIS::Progressbar::Progressbar()
{

}

IGUIS::Progressbar::Progressbar(sf::Color BackgroundFillColor, sf::Color BackgroundOutlineColor, sf::Color FillShapeFillColor, sf::Color FillShapeOutlineColor, IGUIS::Origin OriginOfObject, float PositionX, float PositionY, float SizeX, float SizeY, bool IsPositionRelativeToScreen)
{
    IGUIS::Progressbar::ShapeBackground.setFillColor(BackgroundFillColor);
    IGUIS::Progressbar::ShapeBackground.setOutlineColor(BackgroundOutlineColor);
    IGUIS::Progressbar::FillShape.setFillColor(FillShapeFillColor);
    IGUIS::Progressbar::FillShape.setOutlineColor(FillShapeOutlineColor);
    IGUIS::Progressbar::Origin = OriginOfObject;
    IGUIS::Progressbar::Position = sf::Vector2f(PositionX, PositionY);
    IGUIS::Progressbar::Size = sf::Vector2f(SizeX, SizeY);
    IGUIS::Progressbar::PositionRelativeToScreen = IsPositionRelativeToScreen;
}

void IGUIS::Progressbar::SetBackgroundFillColor(sf::Color FillColor)
{
    ShapeBackground.setFillColor(FillColor);
}

const sf::Color IGUIS::Progressbar::GetBackgroundFillColor()
{
    return ShapeBackground.getFillColor();
}

void IGUIS::Progressbar::SetBackgroundOutlineColor(sf::Color OutlineColor)
{
    ShapeBackground.setOutlineColor(OutlineColor);
}

const sf::Color IGUIS::Progressbar::GetBackgroundOutlineColor()
{
    return ShapeBackground.getOutlineColor();
}

void IGUIS::Progressbar::SetFillShapeFillColor(sf::Color FillColor)
{
    FillShape.setFillColor(FillColor);
}

const sf::Color IGUIS::Progressbar::GetFillShapeFillColor()
{
    return FillShape.getFillColor();
}

void IGUIS::Progressbar::SetFillShapeOutlineColor(sf::Color OutlineColor)
{
    FillShape.setOutlineColor(OutlineColor);
}

const sf::Color IGUIS::Progressbar::GetFillShapeOutlineColor()
{
    return FillShape.getOutlineColor();
}

void IGUIS::Progressbar::SetFillSize(float FillSize)
{
    IGUIS::Progressbar::FillSize = FillSize;
}

float IGUIS::Progressbar::GetFillSize()
{
    return FillSize;
}

bool IGUIS::Progressbar::ContainPoint(sf::Vector2f Point)
{
    return ShapeBackground.getGlobalBounds().contains(Point);
}

void IGUIS::Progressbar::SetPosition(sf::Vector2f Position)
{
    IGUIS::IGUISElement::Position = Position;
}

void IGUIS::Progressbar::SetPosition(float X, float Y)
{
    IGUIS::IGUISElement::Position = sf::Vector2f(X, Y);
}

sf::Vector2f IGUIS::Progressbar::GetPosition()
{
    return IGUIS::IGUISElement::Position;
}

void IGUIS::Progressbar::SetSize(sf::Vector2f Size)
{
    IGUIS::IGUISElement::Size = Size;
}

void IGUIS::Progressbar::SetSize(float X, float Y)
{
    IGUIS::IGUISElement::Size = sf::Vector2f(X, Y);
}

sf::Vector2f IGUIS::Progressbar::GetSize()
{
    return IGUIS::IGUISElement::Size;
}

void IGUIS::Progressbar::Update()
{
    if (IGUIS::IGUISElement::PositionRelativeToScreen) // if position must be relative to screen
    {
        IGUIS::Progressbar::ShapeBackground.setPosition(IGUIS::IGUISElement::GetPositionOnScreenInPxUsingPencentageAndOrigin(IGUIS::IGUISElement::Origin, IGUIS::IGUISElement::Position, IGUIS::IGUISElement::Size));
    }
    else // if position must be relative to screen
    {
        IGUIS::Progressbar::ShapeBackground.setPosition(IGUIS::IGUISElement::Position);
    }
    IGUIS::Progressbar::ShapeBackground.setSize(sf::Vector2f(IGUIS::IGUISElement::Size.x * IGUIS::IGUISElement::Window->getView().getSize().x, IGUIS::IGUISElement::Size.y * IGUIS::IGUISElement::Window->getView().getSize().y));
    IGUIS::Progressbar::ShapeBackground.setOrigin(IGUIS::Progressbar::ShapeBackground.getSize().x / 2, IGUIS::Progressbar::ShapeBackground.getSize().y / 2);

    IGUIS::Progressbar::FillShape.setSize(sf::Vector2f(IGUIS::Progressbar::ShapeBackground.getSize().x * IGUIS::Progressbar::FillSize, IGUIS::Progressbar::ShapeBackground.getSize().y));
    IGUIS::Progressbar::FillShape.setPosition(sf::Vector2f(IGUIS::Progressbar::ShapeBackground.getPosition().x - IGUIS::Progressbar::ShapeBackground.getSize().x / 2, IGUIS::Progressbar::ShapeBackground.getPosition().y - IGUIS::Progressbar::ShapeBackground.getSize().y / 2));
}

void IGUIS::Progressbar::Draw()
{
    IGUIS::IGUISElement::Window->draw(IGUIS::Progressbar::ShapeBackground);
    IGUIS::IGUISElement::Window->draw(IGUIS::Progressbar::FillShape);
}
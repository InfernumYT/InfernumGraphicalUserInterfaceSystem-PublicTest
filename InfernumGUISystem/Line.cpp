#include "Line.h"

IGUIS::Line::Line()
{

}

IGUIS::Line::Line(IGUIS::Origin OriginOfObject, sf::Color FillColor, sf::Color OutlineColor, float Thickness, float OutlineThickness, float Position1X, float Position1Y, float Position2X, float Position2Y, bool IsPositionRelativeToScreen)
{
    IGUIS::Line::Origin = OriginOfObject;
    IGUIS::Line::Shape.setFillColor(FillColor);
    IGUIS::Line::Shape.setOutlineColor(OutlineColor);
    IGUIS::Line::Thickness = Thickness;
    IGUIS::Line::Shape.setOutlineThickness(OutlineThickness);
    IGUIS::Line::Position = sf::Vector2f(Position1X, Position1Y);
    IGUIS::Line::Size = sf::Vector2f(Position2X, Position2Y);
    IGUIS::Line::PositionRelativeToScreen = IsPositionRelativeToScreen;
}

IGUIS::Line::Line(IGUIS::Origin OriginOfObject, sf::Color FillColor, float Thickness, float Position1X, float Position1Y, float Position2X, float Position2Y, bool IsPositionRelativeToScreen)
{
    IGUIS::Line::Origin = OriginOfObject;
    IGUIS::Line::Shape.setFillColor(FillColor);
    IGUIS::Line::Thickness = Thickness;
    IGUIS::Line::Position = sf::Vector2f(Position1X, Position1Y);
    IGUIS::Line::Size = sf::Vector2f(Position2X, Position2Y);
    IGUIS::Line::PositionRelativeToScreen = IsPositionRelativeToScreen;
}

bool IGUIS::Line::ContainPoint(sf::Vector2f Point)
{
    return IGUIS::Line::Shape.getGlobalBounds().contains(Point);
}

void IGUIS::Line::SetPositionA(sf::Vector2f Position)
{
    IGUIS::IGUISElement::Position = Position;
}

void IGUIS::Line::SetPositionA(float X, float Y)
{
    IGUIS::IGUISElement::Position = sf::Vector2f(X, Y);
}

sf::Vector2f IGUIS::Line::GetPositionA()
{
    return IGUIS::IGUISElement::Position;
}

void IGUIS::Line::SetPositionB(sf::Vector2f Size)// TODO: Podmieniæ na PositionB
{
    IGUIS::IGUISElement::Size = Size;
}

void IGUIS::Line::SetPositionB(float X, float Y)
{
    IGUIS::IGUISElement::Size = sf::Vector2f(X, Y);
}

sf::Vector2f IGUIS::Line::GetPositionB()
{
    return IGUIS::IGUISElement::Size;
}

void IGUIS::Line::Update()
{
    if (IGUIS::IGUISElement::PositionRelativeToScreen) // if position must be relative to screen
    {
        IGUIS::Line::Shape.setPosition(IGUIS::IGUISElement::GetPositionOnScreenInPxUsingPencentageAndOrigin(IGUIS::IGUISElement::Origin, IGUIS::IGUISElement::Position));
        IGUIS::Line::Shape.setSize(sf::Vector2f(sqrt(pow(IGUIS::Line::Position.x * IGUIS::IGUISElement::Window->getView().getSize().x - IGUIS::IGUISElement::Size.x * IGUIS::IGUISElement::Window->getView().getSize().x, 2) + pow(IGUIS::IGUISElement::Position.y * IGUIS::IGUISElement::Window->getView().getSize().y - IGUIS::IGUISElement::Size.y * IGUIS::IGUISElement::Window->getView().getSize().y, 2)), IGUIS::Line::Thickness));
        IGUIS::Line::Shape.setRotation(atan2(IGUIS::Line::Size.y * IGUIS::IGUISElement::Window->getView().getSize().y - IGUIS::Line::Position.y * IGUIS::IGUISElement::Window->getView().getSize().y, IGUIS::IGUISElement::Size.x * IGUIS::IGUISElement::Window->getView().getSize().x - IGUIS::IGUISElement::Position.x * IGUIS::IGUISElement::Window->getView().getSize().x) * 180 / 3.14159265358979323846);
    }
    else // if position must be relative to screen
    {
        IGUIS::Line::Shape.setPosition(IGUIS::IGUISElement::Position);
        IGUIS::Line::Shape.setSize(sf::Vector2f(sqrt(pow(IGUIS::IGUISElement::Position.x - IGUIS::IGUISElement::Size.x, 2) + pow(IGUIS::IGUISElement::Position.y - IGUIS::IGUISElement::Size.y, 2)), IGUIS::Line::Thickness));
        IGUIS::Line::Shape.setRotation(atan2(IGUIS::IGUISElement::Size.y - IGUIS::IGUISElement::Position.y, IGUIS::IGUISElement::Size.x - IGUIS::IGUISElement::Position.x) * 180 / 3.14159265358979323846);
    }
    IGUIS::Line::Shape.setOrigin(0, IGUIS::Line::Shape.getSize().y / 2);
}

void IGUIS::Line::Draw()
{
    IGUIS::IGUISElement::Window->draw(IGUIS::Line::Shape);
}
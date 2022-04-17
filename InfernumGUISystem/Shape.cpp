#include "Shape.h"

IGUIS::Shape::Shape()
{
    
}

IGUIS::Shape::Shape(const sf::Texture* Texture, sf::Color Color, IGUIS::Origin OriginOfObject, float PositionX, float PositionY, float SizeX, float SizeY, bool IsPositionRelativeToScreen)
{
    IGUIS::Shape::ShapeVar.setTexture(Texture);
    if (Texture != nullptr)
    {
        IGUIS::Shape::ShapeVar.setTextureRect(sf::IntRect(0, 0, Texture->getSize().x, Texture->getSize().y));
    }
    IGUIS::Shape::ShapeVar.setFillColor(Color);
    IGUIS::Shape::Origin = OriginOfObject;
    IGUIS::Shape::Position = sf::Vector2f(PositionX, PositionY);
    IGUIS::Shape::Size = sf::Vector2f(SizeX, SizeY);
    IGUIS::Shape::PositionRelativeToScreen = IsPositionRelativeToScreen;
}

IGUIS::Shape::Shape(const sf::Texture* Texture, IGUIS::Origin OriginOfObject, float PositionX, float PositionY, float SizeX, float SizeY, bool IsPositionRelativeToScreen)
{
    IGUIS::Shape::ShapeVar.setTexture(Texture);
    if (Texture != nullptr)
    {
        IGUIS::Shape::ShapeVar.setTextureRect(sf::IntRect(0, 0, Texture->getSize().x, Texture->getSize().y));
    }
    IGUIS::Shape::Origin = OriginOfObject;
    IGUIS::Shape::Position = sf::Vector2f(PositionX, PositionY);
    IGUIS::Shape::Size = sf::Vector2f(SizeX, SizeY);
    IGUIS::Shape::PositionRelativeToScreen = IsPositionRelativeToScreen;
}

IGUIS::Shape::Shape(sf::Color Color, IGUIS::Origin OriginOfObject, float PositionX, float PositionY, float SizeX, float SizeY, bool IsPositionRelativeToScreen)
{
    IGUIS::Shape::ShapeVar.setFillColor(Color);
    IGUIS::Shape::Origin = OriginOfObject;
    IGUIS::Shape::Position = sf::Vector2f(PositionX, PositionY);
    IGUIS::Shape::Size = sf::Vector2f(SizeX, SizeY);
    IGUIS::Shape::PositionRelativeToScreen = IsPositionRelativeToScreen;
}

void IGUIS::Shape::SetFillColor(sf::Color FillColor)
{
    IGUIS::Shape::ShapeVar.setFillColor(FillColor);
}

const sf::Color IGUIS::Shape::GetFillColor()
{
    return IGUIS::Shape::ShapeVar.getFillColor();
}

void IGUIS::Shape::SetOutlineColor(sf::Color OutlineColor)
{
    IGUIS::Shape::ShapeVar.setOutlineColor(OutlineColor);
}

const sf::Color IGUIS::Shape::GetOutlineColor()
{
    return IGUIS::Shape::ShapeVar.getOutlineColor();
}

void IGUIS::Shape::SetOutlineThickness(float OutlineThickness)//TODO: ¿eby obs³ugiwaæ thickness potrzeba dodaæ tu voida co by zmienia³ go na mniejszego kiedy zoom wiêkszy itp
{
    IGUIS::Shape::ShapeVar.setOutlineThickness(OutlineThickness);
}

const float IGUIS::Shape::GetOutlineThickness()
{
    return IGUIS::Shape::ShapeVar.getOutlineThickness();
}

void IGUIS::Shape::SetTexture(const sf::Texture* Texture)
{
    IGUIS::Shape::ShapeVar.setTexture(Texture);
    if (Texture != nullptr)
    {
        IGUIS::Shape::ShapeVar.setTextureRect(sf::IntRect(0, 0, Texture->getSize().x, Texture->getSize().y));
    }
}

const sf::Texture* IGUIS::Shape::GetTexture()
{
    return IGUIS::Shape::ShapeVar.getTexture();
}

bool IGUIS::Shape::ContainPoint(sf::Vector2f Point)
{
    return IGUIS::Shape::ShapeVar.getGlobalBounds().contains(Point);
}

void IGUIS::Shape::SetPosition(sf::Vector2f Position)
{
    IGUIS::IGUISElement::Position = Position;
}

void IGUIS::Shape::SetPosition(float X, float Y)
{
    IGUIS::IGUISElement::Position = sf::Vector2f(X, Y);
}

sf::Vector2f IGUIS::Shape::GetPosition()
{
    return IGUIS::IGUISElement::Position;
}

void IGUIS::Shape::SetSize(sf::Vector2f Size)
{
    IGUIS::IGUISElement::Size = Size;
}

void IGUIS::Shape::SetSize(float X, float Y)
{
    IGUIS::IGUISElement::Size = sf::Vector2f(X, Y);
}

sf::Vector2f IGUIS::Shape::GetSize()
{
    return IGUIS::IGUISElement::Size;
}

void IGUIS::Shape::Update()
{
    if (IGUIS::IGUISElement::PositionRelativeToScreen) // if position must be relative to screen
    {
        IGUIS::Shape::ShapeVar.setPosition(IGUIS::IGUISElement::GetPositionOnScreenInPxUsingPencentageAndOrigin(IGUIS::IGUISElement::Origin, IGUIS::IGUISElement::Position, IGUIS::IGUISElement::Size));
    }
    else // if position must be relative to screen
    {
        IGUIS::Shape::ShapeVar.setPosition(IGUIS::IGUISElement::Position);
    }
    IGUIS::Shape::ShapeVar.setSize(sf::Vector2f(IGUIS::IGUISElement::Size.x * IGUIS::IGUISElement::Window->getView().getSize().x, IGUIS::IGUISElement::Size.y * IGUIS::IGUISElement::Window->getView().getSize().y));
    IGUIS::Shape::ShapeVar.setOrigin(IGUIS::Shape::ShapeVar.getSize().x / 2, IGUIS::Shape::ShapeVar.getSize().y / 2);
}

void IGUIS::Shape::Draw()
{
    IGUIS::IGUISElement::Window->draw(IGUIS::Shape::ShapeVar);
}
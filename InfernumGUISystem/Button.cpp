#include "Button.h"

IGUIS::Button::Button()
{

}

IGUIS::Button::Button(const sf::Texture *Texture, sf::Color ColourUnhovered, sf::Color ColourHovered, sf::Color ColourClicked, sf::Color ColourDeactivated, IGUIS::Origin OriginOfObject, float PositionX, float PositionY, float SizeX, float SizeY, bool IsPositionRelativeToScreen)
{
    IGUIS::Button::Shape.setTexture(Texture);
    if (Texture != nullptr)
    {
        IGUIS::Button::Shape.setTextureRect(sf::IntRect(0, 0, Texture->getSize().x, Texture->getSize().y));
    }
    IGUIS::Button::ShapeColourUnhovered = ColourUnhovered;
    IGUIS::Button::ShapeColourHovered = ColourHovered;
    IGUIS::Button::ShapeColourClicked = ColourClicked;
    IGUIS::Button::ShapeColourDeactivated = ColourDeactivated;
    IGUIS::IGUISElement::Origin = OriginOfObject;
    IGUIS::IGUISElement::Position = sf::Vector2f(PositionX, PositionY);
    IGUIS::IGUISElement::Size = sf::Vector2f(SizeX, SizeY);
    IGUIS::IGUISElement::PositionRelativeToScreen = IsPositionRelativeToScreen;
}

IGUIS::Button::Button(const sf::Texture *Texture, IGUIS::Origin OriginOfObject, float PositionX, float PositionY, float SizeX, float SizeY, bool IsPositionRelativeToScreen)
{
    IGUIS::Button::Shape.setTexture(Texture);
    if (Texture != nullptr)
    {
        IGUIS::Button::Shape.setTextureRect(sf::IntRect(0, 0, Texture->getSize().x, Texture->getSize().y));
    }
    IGUIS::IGUISElement::Origin = OriginOfObject;
    IGUIS::IGUISElement::Position = sf::Vector2f(PositionX, PositionY);
    IGUIS::IGUISElement::Size = sf::Vector2f(SizeX, SizeY);
    IGUIS::IGUISElement::PositionRelativeToScreen = IsPositionRelativeToScreen;
}

void IGUIS::Button::SetTexture(const sf::Texture* Texture)
{
    IGUIS::Button::Shape.setTexture(Texture);
    if (Texture != nullptr)
    {
        IGUIS::Button::Shape.setTextureRect(sf::IntRect(0, 0, Texture->getSize().x, Texture->getSize().y));
    }
}

const sf::Texture* IGUIS::Button::GetTexture()
{
    return IGUIS::Button::Shape.getTexture();
}

bool IGUIS::Button::ContainPoint(sf::Vector2f Point)
{
    return IGUIS::Button::Shape.getGlobalBounds().contains(Point);
}

void IGUIS::Button::SetPosition(sf::Vector2f Position)
{
    IGUIS::IGUISElement::Position = Position;
}

void IGUIS::Button::SetPosition(float X, float Y)
{
    IGUIS::IGUISElement::Position = sf::Vector2f(X, Y);
}

sf::Vector2f IGUIS::Button::GetPosition()
{
    return IGUIS::IGUISElement::Position;
}

void IGUIS::Button::SetSize(sf::Vector2f Size)
{
    IGUIS::IGUISElement::Size = Size;
}

void IGUIS::Button::SetSize(float X, float Y)
{
    IGUIS::IGUISElement::Size = sf::Vector2f(X, Y);
}

sf::Vector2f IGUIS::Button::GetSize()
{
    return IGUIS::IGUISElement::Size;
}

void IGUIS::Button::Update(sf::Event *Event)
{
    if (IGUIS::IGUISElement::PositionRelativeToScreen) // if position must be relative to screen
    {
        IGUIS::Button::Shape.setPosition(IGUIS::IGUISElement::GetPositionOnScreenInPxUsingPencentageAndOrigin(IGUIS::IGUISElement::Origin, IGUIS::IGUISElement::Position, IGUIS::IGUISElement::Size));
    }
    else // if position must be relative to screen
    {
        IGUIS::Button::Shape.setPosition(IGUIS::Button::Position);
    }
    IGUIS::Button::Shape.setSize(sf::Vector2f(IGUIS::IGUISElement::Size.x * IGUIS::IGUISElement::Window->getView().getSize().x, IGUIS::IGUISElement::Size.y * IGUIS::IGUISElement::Window->getView().getSize().y));
    IGUIS::Button::Shape.setOrigin(IGUIS::Button::Shape.getSize().x / 2, IGUIS::Button::Shape.getSize().y / 2);

    if (IGUIS::Button::IsActive)
    {
        IGUIS::Button::ShapeRect = static_cast<sf::FloatRect>(IGUIS::Button::Shape.getGlobalBounds());

        IGUIS::Button::MouseOnButton = IGUIS::Button::ShapeRect.contains(IGUIS::IGUISElement::Window->mapPixelToCoords(sf::Mouse::getPosition(*IGUIS::IGUISElement::Window)));

        #pragma region get state
        if (IGUIS::Button::State == 6) // if state is "unclicked once"
        {
            if (IGUIS::Button::MouseOnButton) // if mouse is on button
            {
                IGUIS::Button::State = 3; //set state to hovered
            }
            else // if mouse is on button
            {
                IGUIS::Button::State = 2; //set state to unhovered once
            }
        }

        if (Event->type == sf::Event::MouseMoved) // if mouse moved
        {
            if (IGUIS::Button::MouseOnButton) // if mouse is on button
            {
                if (IGUIS::Button::State != 4 && IGUIS::Button::State != 5) // if state isn't "clicked once" and "clicked"
                {
                    if (IGUIS::Button::State != 2 && IGUIS::Button::State != 3) // if state isn't "hovered once" and "hovered"
                    {
                        IGUIS::Button::State = 2; // set state to hovered once
                    }
                    else // if state isn't "hovered once" and "hovered"
                    {
                        IGUIS::Button::State = 3; // set state to hovered
                    }
                }
            }
            else // if mouse is on button
            {
                if (IGUIS::Button::State != 0 && IGUIS::Button::State != 1) // if state isn't "unhovered once" and "unhovered"
                {
                    IGUIS::Button::State = 0; // set state to unhovered once
                }
                else // if state isn't "unhovered once" and "unhovered"
                {
                    IGUIS::Button::State = 1; // set state to unhovered
                }
            }
        }

        if (Event->type == sf::Event::MouseButtonPressed && Event->mouseButton.button == sf::Mouse::Left) // if mouse button is pressed and left mouse button
        {
            if (IGUIS::Button::MouseOnButton) // if mouse is on button
            {
                if (IGUIS::Button::State != 4 && IGUIS::Button::State != 5) // if state isn't "clicked once" and "clicked"
                {
                    IGUIS::Button::State = 4; // set state to clicked once
                }
                else // if state isn't "clicked once" and "clicked"
                {
                    IGUIS::Button::State = 5; // set state to clicked
                }
            }
            else // if mouse is on button
            {
                if (IGUIS::Button::State != 0 && IGUIS::Button::State != 1) // if state isn't "unhovered once" and "unhovered"
                {
                    IGUIS::Button::State = 0; // set state to unhovered once
                }
                else // if state isn't "unhovered once" and "unhovered"
                {
                    IGUIS::Button::State = 1; // set state to unhovered
                }
            }
        }

        if (Event->type == sf::Event::MouseButtonReleased && Event->mouseButton.button == sf::Mouse::Left) // if mouse button is released and left mouse button
        {
            if (IGUIS::Button::State == 4 || IGUIS::Button::State == 5) // if state is "clicked once" or "clicked"
            {
                IGUIS::Button::State = 6; // set state to unclicked once
            }
            else if (IGUIS::Button::MouseOnButton) // if state isn't "clicked once" or "clicked" and mouse is on button
            {
                IGUIS::Button::State = 3; // set state to hovered
            }
        }
        #pragma endregion


        switch (IGUIS::Button::State)
        {
        case 0:// state == unhovered once
            IGUIS::Button::Shape.setFillColor(IGUIS::Button::ShapeColourUnhovered);
            IGUIS::IGUISElement::SpeakerUnhovered.play();
            break;

        case 1:// state == unhovered
            IGUIS::Button::Shape.setFillColor(IGUIS::Button::ShapeColourUnhovered);
            break;

        case 2:// state == hovered once
            IGUIS::Button::Shape.setFillColor(IGUIS::Button::ShapeColourHovered);
            IGUIS::IGUISElement::SpeakerHovered.play();
            break;

        case 3:// state == hovered
            IGUIS::Button::Shape.setFillColor(IGUIS::Button::ShapeColourHovered);
            break;

        case 4:// state == clicked once
            IGUIS::Button::Shape.setFillColor(IGUIS::Button::ShapeColourClicked);
            IGUIS::IGUISElement::SpeakerClicked.play();
            break;

        case 5:// state == clicked
            IGUIS::Button::Shape.setFillColor(IGUIS::Button::ShapeColourClicked);
            break;

        case 6:// state == unclicked once
            IGUIS::Button::Shape.setFillColor(IGUIS::Button::ShapeColourHovered);
            break;
        }
    }
    else
    {
        IGUIS::Button::State = 7;
        IGUIS::Button::Shape.setFillColor(IGUIS::Button::ShapeColourDeactivated);
    }
}

void IGUIS::Button::Draw()
{
    IGUIS::IGUISElement::Window->draw(IGUIS::Button::Shape);
}
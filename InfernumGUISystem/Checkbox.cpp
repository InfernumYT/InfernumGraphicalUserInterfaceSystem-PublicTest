#include "Checkbox.h"

IGUIS::Checkbox::Checkbox()
{
    
}

IGUIS::Checkbox::Checkbox(const sf::Texture* TextureIfTurnedOff, const sf::Texture* TextureIfTurnedOn, sf::Color ColourUnhovered, sf::Color ColourHovered, sf::Color ColourClicked, sf::Color ColourDeactivated, IGUIS::Origin OriginOfObject, float PositionX, float PositionY, float SizeX, float SizeY, bool IsPositionRelativeToScreen)
{
    IGUIS::Checkbox::ShapeTextureIfTurnedOff = TextureIfTurnedOff;
    IGUIS::Checkbox::ShapeTextureIfTurnedOn = TextureIfTurnedOn;
    if (IsTurnedOn)
    {
        IGUIS::Checkbox::Shape.setTexture(ShapeTextureIfTurnedOn);
        if (ShapeTextureIfTurnedOn != nullptr)
        {
            IGUIS::Checkbox::Shape.setTextureRect(sf::IntRect(0, 0, ShapeTextureIfTurnedOn->getSize().x, ShapeTextureIfTurnedOn->getSize().y));
        }
    }
    else
    {
        IGUIS::Checkbox::Shape.setTexture(ShapeTextureIfTurnedOff);
        if (ShapeTextureIfTurnedOff != nullptr)
        {
            IGUIS::Checkbox::Shape.setTextureRect(sf::IntRect(0, 0, ShapeTextureIfTurnedOff->getSize().x, ShapeTextureIfTurnedOff->getSize().y));
        }
    }
    IGUIS::Checkbox::ShapeColourUnhovered = ColourUnhovered;
    IGUIS::Checkbox::ShapeColourHovered = ColourHovered;
    IGUIS::Checkbox::ShapeColourClicked = ColourClicked;
    IGUIS::Checkbox::ShapeColourDeactivated = ColourDeactivated;
    IGUIS::IGUISElement::Origin = OriginOfObject;
    IGUIS::IGUISElement::Position = sf::Vector2f(PositionX, PositionY);
    IGUIS::IGUISElement::Size = sf::Vector2f(SizeX, SizeY);
    IGUIS::IGUISElement::PositionRelativeToScreen = IsPositionRelativeToScreen;
}

IGUIS::Checkbox::Checkbox(const sf::Texture* TextureIfTurnedOff, const sf::Texture* TextureIfTurnedOn, IGUIS::Origin OriginOfObject, float PositionX, float PositionY, float SizeX, float SizeY, bool IsPositionRelativeToScreen)
{
    IGUIS::Checkbox::ShapeTextureIfTurnedOff = TextureIfTurnedOff;
    IGUIS::Checkbox::ShapeTextureIfTurnedOn = TextureIfTurnedOn;
    if (IGUIS::Checkbox::IsTurnedOn)
    {
        IGUIS::Checkbox::Shape.setTexture(IGUIS::Checkbox::ShapeTextureIfTurnedOn);
        if (IGUIS::Checkbox::ShapeTextureIfTurnedOn != nullptr)
        {
            IGUIS::Checkbox::Shape.setTextureRect(sf::IntRect(0, 0, IGUIS::Checkbox::ShapeTextureIfTurnedOn->getSize().x, IGUIS::Checkbox::ShapeTextureIfTurnedOn->getSize().y));
        }
    }
    else
    {
        IGUIS::Checkbox::Shape.setTexture(IGUIS::Checkbox::ShapeTextureIfTurnedOff);
        if (IGUIS::Checkbox::ShapeTextureIfTurnedOff != nullptr)
        {
            IGUIS::Checkbox::Shape.setTextureRect(sf::IntRect(0, 0, IGUIS::Checkbox::ShapeTextureIfTurnedOff->getSize().x, IGUIS::Checkbox::ShapeTextureIfTurnedOff->getSize().y));
        }
    }
    IGUIS::IGUISElement::Origin = OriginOfObject;
    IGUIS::IGUISElement::Position = sf::Vector2f(PositionX, PositionY);
    IGUIS::IGUISElement::Size = sf::Vector2f(SizeX, SizeY);
    IGUIS::IGUISElement::PositionRelativeToScreen = IsPositionRelativeToScreen;
}

bool IGUIS::Checkbox::ContainPoint(sf::Vector2f Point)
{
    return IGUIS::Checkbox::Shape.getGlobalBounds().contains(Point);
}

void IGUIS::Checkbox::SetPosition(sf::Vector2f Position)
{
    IGUIS::IGUISElement::Position = Position;
}

void IGUIS::Checkbox::SetPosition(float X, float Y)
{
    IGUIS::IGUISElement::Position = sf::Vector2f(X, Y);
}

sf::Vector2f IGUIS::Checkbox::GetPosition()
{
    return IGUIS::IGUISElement::Position;
}

void IGUIS::Checkbox::SetSize(sf::Vector2f Size)
{
    IGUIS::IGUISElement::Size = Size;
}

void IGUIS::Checkbox::SetSize(float X, float Y)
{
    IGUIS::IGUISElement::Size = sf::Vector2f(X, Y);
}

sf::Vector2f IGUIS::Checkbox::GetSize()
{
    return IGUIS::IGUISElement::Size;
}

void IGUIS::Checkbox::Update(sf::Event* Event)
{
    if (IGUIS::IGUISElement::PositionRelativeToScreen) // if position must be relative to screen
    {
        IGUIS::Checkbox::Shape.setPosition(IGUIS::IGUISElement::GetPositionOnScreenInPxUsingPencentageAndOrigin(IGUIS::IGUISElement::Origin, IGUIS::IGUISElement::Position, IGUIS::IGUISElement::Size));
    }
    else // if position must be relative to screen
    {
        IGUIS::Checkbox::Shape.setPosition(IGUIS::Checkbox::Position);
    }
    IGUIS::Checkbox::Shape.setSize(sf::Vector2f(IGUIS::Checkbox::Size.x * IGUIS::IGUISElement::Window->getView().getSize().x, IGUIS::Checkbox::Size.y * IGUIS::IGUISElement::Window->getView().getSize().y));
    IGUIS::Checkbox::Shape.setOrigin(IGUIS::Checkbox::Shape.getSize().x / 2, IGUIS::Checkbox::Shape.getSize().y / 2);
    if (IGUIS::Checkbox::IsTurnedOn)
    {
        IGUIS::Checkbox::Shape.setTexture(IGUIS::Checkbox::ShapeTextureIfTurnedOn);
        if (IGUIS::Checkbox::ShapeTextureIfTurnedOn != nullptr)
        {
            IGUIS::Checkbox::Shape.setTextureRect(sf::IntRect(0, 0, IGUIS::Checkbox::ShapeTextureIfTurnedOn->getSize().x, IGUIS::Checkbox::ShapeTextureIfTurnedOn->getSize().y));
        }
    }
    else
    {
        IGUIS::Checkbox::Shape.setTexture(IGUIS::Checkbox::ShapeTextureIfTurnedOff);
        if (IGUIS::Checkbox::ShapeTextureIfTurnedOff != nullptr)
        {
            IGUIS::Checkbox::Shape.setTextureRect(sf::IntRect(0, 0, IGUIS::Checkbox::ShapeTextureIfTurnedOff->getSize().x, IGUIS::Checkbox::ShapeTextureIfTurnedOff->getSize().y));
        }
    }

    if (IGUIS::Checkbox::IsActive)
    {
        IGUIS::Checkbox::ShapeRect = static_cast<sf::FloatRect>(IGUIS::Checkbox::Shape.getGlobalBounds());

        IGUIS::Checkbox::MouseOnButton = IGUIS::Checkbox::ShapeRect.contains(IGUIS::IGUISElement::Window->mapPixelToCoords(sf::Mouse::getPosition(*IGUIS::IGUISElement::Window)));

        #pragma region get state
        if (IGUIS::Checkbox::State == 6) // if state is "unclicked once"
        {
            if (IGUIS::Checkbox::MouseOnButton) // if mouse is on button
            {
                IGUIS::Checkbox::State = 3; //set state to hovered
            }
            else // if mouse is on button
            {
                IGUIS::Checkbox::State = 2; //set state to unhovered once
            }
        }

        if (Event->type == sf::Event::MouseMoved) // if mouse moved
        {
            if (IGUIS::Checkbox::MouseOnButton) // if mouse is on button
            {
                if (IGUIS::Checkbox::State != 4 && IGUIS::Checkbox::State != 5) // if state isn't "clicked once" and "clicked"
                {
                    if (IGUIS::Checkbox::State != 2 && IGUIS::Checkbox::State != 3) // if state isn't "hovered once" and "hovered"
                    {
                        IGUIS::Checkbox::State = 2; // set state to hovered once
                    }
                    else // if state isn't "hovered once" and "hovered"
                    {
                        IGUIS::Checkbox::State = 3; // set state to hovered
                    }
                }
            }
            else // if mouse is on button
            {
                if (IGUIS::Checkbox::State != 0 && IGUIS::Checkbox::State != 1) // if state isn't "unhovered once" and "unhovered"
                {
                    IGUIS::Checkbox::State = 0; // set state to unhovered once
                }
                else // if state isn't "unhovered once" and "unhovered"
                {
                    IGUIS::Checkbox::State = 1; // set state to unhovered
                }
            }
        }

        if (Event->type == sf::Event::MouseButtonPressed && Event->mouseButton.button == sf::Mouse::Left) // if mouse button is pressed and left mouse button
        {
            if (IGUIS::Checkbox::MouseOnButton) // if mouse is on button
            {
                if (IGUIS::Checkbox::State != 4 && IGUIS::Checkbox::State != 5) // if state isn't "clicked once" and "clicked"
                {
                    IGUIS::Checkbox::State = 4; // set state to clicked once
                }
                else // if state isn't "clicked once" and "clicked"
                {
                    IGUIS::Checkbox::State = 5; // set state to clicked
                }
            }
            else // if mouse is on button
            {
                if (IGUIS::Checkbox::State != 0 && IGUIS::Checkbox::State != 1) // if state isn't "unhovered once" and "unhovered"
                {
                    IGUIS::Checkbox::State = 0; // set state to unhovered once
                }
                else // if state isn't "unhovered once" and "unhovered"
                {
                    IGUIS::Checkbox::State = 1; // set state to unhovered
                }
            }
        }

        if (Event->type == sf::Event::MouseButtonReleased && Event->mouseButton.button == sf::Mouse::Left) // if mouse button is released and left mouse button
        {
            if (IGUIS::Checkbox::State == 4 || IGUIS::Checkbox::State == 5) // if state is "clicked once" or "clicked"
            {
                IGUIS::Checkbox::State = 6; // set state to unclicked once
                if (IGUIS::Checkbox::IsTurnedOn)
                {
                    IGUIS::Checkbox::IsTurnedOn = false;
                    IGUIS::Checkbox::Shape.setTexture(IGUIS::Checkbox::ShapeTextureIfTurnedOff);
                }
                else
                {
                    IGUIS::Checkbox::IsTurnedOn = true;
                    IGUIS::Checkbox::Shape.setTexture(IGUIS::Checkbox::ShapeTextureIfTurnedOn);
                }
            }
            else if (IGUIS::Checkbox::MouseOnButton) // if state isn't "clicked once" or "clicked" and mouse is on button
            {
                IGUIS::Checkbox::State = 3; // set state to hovered
            }
        }
        #pragma endregion
        
        switch (IGUIS::Checkbox::State)
        {
        case 0:// state == unhovered once
            IGUIS::Checkbox::Shape.setFillColor(IGUIS::Checkbox::ShapeColourUnhovered);
            IGUIS::IGUISElement::SpeakerUnhovered.play();
            break;

        case 1:// state == unhovered
            IGUIS::Checkbox::Shape.setFillColor(IGUIS::Checkbox::ShapeColourUnhovered);
            break;

        case 2:// state == hovered once
            IGUIS::Checkbox::Shape.setFillColor(IGUIS::Checkbox::ShapeColourHovered);
            IGUIS::IGUISElement::SpeakerHovered.play();
            break;

        case 3:// state == hovered
            IGUIS::Checkbox::Shape.setFillColor(IGUIS::Checkbox::ShapeColourHovered);
            break;

        case 4:// state == clicked once
            IGUIS::Checkbox::Shape.setFillColor(IGUIS::Checkbox::ShapeColourClicked);
            IGUIS::IGUISElement::SpeakerClicked.play();
            break;

        case 5:// state == clicked
            IGUIS::Checkbox::Shape.setFillColor(IGUIS::Checkbox::ShapeColourClicked);
            break;

        case 6:// state == unclicked once
            IGUIS::Checkbox::Shape.setFillColor(IGUIS::Checkbox::ShapeColourHovered);
            break;
        }
    }
    else
    {
        IGUIS::Checkbox::State = 1;
        IGUIS::Checkbox::Shape.setFillColor(IGUIS::Checkbox::ShapeColourDeactivated);
    }
}

void IGUIS::Checkbox::Draw()
{
    IGUIS::IGUISElement::Window->draw(IGUIS::Checkbox::Shape);
}
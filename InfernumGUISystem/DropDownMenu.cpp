#include "DropDownMenu.h"

IGUIS::DropDownMenu::DropDownMenu()
{

}

IGUIS::DropDownMenu::DropDownMenu(sf::Font* Font, sf::Color ColourUnhovered, sf::Color ColourHovered, sf::Color ColourClicked, sf::Color ColourDeactivated, IGUIS::Origin OriginOfObject, float PositionX, float PositionY, float SizeX, float SizeY, bool IsPositionRelativeToScreen)
{
    IGUIS::DropDownMenu::ShapeColourUnhovered = ColourUnhovered;
    IGUIS::DropDownMenu::ShapeColourHovered = ColourHovered;
    IGUIS::DropDownMenu::ShapeColourClicked = ColourClicked;
    IGUIS::DropDownMenu::ShapeColourDeactivated = ColourDeactivated;
    IGUIS::DropDownMenu::Origin = OriginOfObject;
    IGUIS::DropDownMenu::Position = sf::Vector2f(PositionX, PositionY);
    IGUIS::DropDownMenu::Size = sf::Vector2f(SizeX, SizeY);
    IGUIS::DropDownMenu::PositionRelativeToScreen = IsPositionRelativeToScreen;

    IGUIS::DropDownMenu::xBackground.setFillColor(ColourUnhovered);
    IGUIS::DropDownMenu::Text.setFont(*Font);
    IGUIS::DropDownMenu::xText.setFont(*Font);
}

IGUIS::DropDownMenu::DropDownMenu(sf::Font* Font, IGUIS::Origin OriginOfObject, float PositionX, float PositionY, float SizeX, float SizeY, bool IsPositionRelativeToScreen)
{
    IGUIS::DropDownMenu::Origin = OriginOfObject;
    IGUIS::DropDownMenu::Position = sf::Vector2f(PositionX, PositionY);
    IGUIS::DropDownMenu::Size = sf::Vector2f(SizeX, SizeY);
    IGUIS::DropDownMenu::PositionRelativeToScreen = IsPositionRelativeToScreen;

    IGUIS::DropDownMenu::xBackground.setFillColor(IGUIS::DropDownMenu::ShapeColourUnhovered);
    IGUIS::DropDownMenu::Text.setFont(*Font);
    IGUIS::DropDownMenu::xText.setFont(*Font);
}

void IGUIS::DropDownMenu::AddOption(std::string String)
{
    Options.push_back(String);
}

std::string IGUIS::DropDownMenu::GetSellectedOption()
{
    return Text.getString();
}

bool IGUIS::DropDownMenu::ContainPoint(sf::Vector2f Point)
{
    return Background.getGlobalBounds().contains(Point);
}

void IGUIS::DropDownMenu::SetPosition(sf::Vector2f Position)
{
    IGUIS::IGUISElement::Position = Position;
}

void IGUIS::DropDownMenu::SetPosition(float X, float Y)
{
    IGUIS::IGUISElement::Position = sf::Vector2f(X, Y);
}

sf::Vector2f IGUIS::DropDownMenu::GetPosition()
{
    return IGUIS::IGUISElement::Position;
}

void IGUIS::DropDownMenu::SetSize(sf::Vector2f Size)
{
    IGUIS::IGUISElement::Size = Size;
}

void IGUIS::DropDownMenu::SetSize(float X, float Y)
{
    IGUIS::IGUISElement::Size = sf::Vector2f(X, Y);
}

sf::Vector2f IGUIS::DropDownMenu::GetSize()
{
    return IGUIS::IGUISElement::Size;
}

void IGUIS::DropDownMenu::Update(sf::Event *Event)
{
    if (PositionRelativeToScreen) // if position must be relative to screen
    {
        IGUIS::DropDownMenu::Background.setPosition(IGUIS::IGUISElement::GetPositionOnScreenInPxUsingPencentageAndOrigin(IGUIS::DropDownMenu::Origin, IGUIS::DropDownMenu::Position, IGUIS::DropDownMenu::Size));
    }
    else // if position must be relative to screen
    {
        Background.setPosition(Position);
    }
    Background.setSize(sf::Vector2f(Size.x * IGUIS::IGUISElement::Window->getView().getSize().x, Size.y * IGUIS::IGUISElement::Window->getView().getSize().y));
    Background.setOrigin(Background.getSize().x / 2, Background.getSize().y / 2);

    if (IsActive)
    {
        ShapeRect = static_cast<sf::FloatRect>(Background.getGlobalBounds());

        MouseOnButton = ShapeRect.contains(IGUIS::IGUISElement::Window->mapPixelToCoords(sf::Mouse::getPosition(*IGUIS::IGUISElement::Window)));

        // tests area
        if (IsOpen && Event->mouseButton.button == sf::Mouse::Left)// jeœli niema na dole miejsca to do góry niech robi
        {
            for (uint8_t i = 0; i < Options.size(); i++)
            {
                xBackground.setPosition(Background.getPosition() + sf::Vector2f(0, Background.getSize().y + Background.getSize().y * i));
                xBackground.setSize(Background.getSize());
                xBackground.setOrigin(xBackground.getSize().x / 2, xBackground.getSize().y / 2);
                if (xBackground.getGlobalBounds().contains(IGUIS::IGUISElement::Window->mapPixelToCoords(sf::Mouse::getPosition(*IGUIS::IGUISElement::Window))))
                {
                    Text.setString(Options[i]);
                    IsOpen = false;
                }
            }
        }
        // !tests area

        #pragma region get state
        if (IGUIS::DropDownMenu::State == 6) // if state is "unclicked once"
        {
            if (IGUIS::DropDownMenu::MouseOnButton) // if mouse is on button
            {
                IGUIS::DropDownMenu::State = 3; //set state to hovered
            }
            else // if mouse is on button
            {
                IGUIS::DropDownMenu::State = 2; //set state to unhovered once
            }
        }

        if (Event->type == sf::Event::MouseMoved) // if mouse moved
        {
            if (IGUIS::DropDownMenu::MouseOnButton) // if mouse is on button
            {
                if (IGUIS::DropDownMenu::State != 4 && IGUIS::DropDownMenu::State != 5) // if state isn't "clicked once" and "clicked"
                {
                    if (IGUIS::DropDownMenu::State != 2 && IGUIS::DropDownMenu::State != 3) // if state isn't "hovered once" and "hovered"
                    {
                        IGUIS::DropDownMenu::State = 2; // set state to hovered once
                    }
                    else // if state isn't "hovered once" and "hovered"
                    {
                        IGUIS::DropDownMenu::State = 3; // set state to hovered
                    }
                }
            }
            else // if mouse is on button
            {
                if (IGUIS::DropDownMenu::State != 0 && IGUIS::DropDownMenu::State != 1) // if state isn't "unhovered once" and "unhovered"
                {
                    IGUIS::DropDownMenu::State = 0; // set state to unhovered once
                }
                else // if state isn't "unhovered once" and "unhovered"
                {
                    IGUIS::DropDownMenu::State = 1; // set state to unhovered
                }
            }
        }

        if (Event->type == sf::Event::MouseButtonPressed && Event->mouseButton.button == sf::Mouse::Left) // if mouse button is pressed and left mouse button
        {
            if (IGUIS::DropDownMenu::MouseOnButton) // if mouse is on button
            {
                if (IGUIS::DropDownMenu::State != 4 && IGUIS::DropDownMenu::State != 5) // if state isn't "clicked once" and "clicked"
                {
                    IGUIS::DropDownMenu::State = 4; // set state to clicked once
                }
                else // if state isn't "clicked once" and "clicked"
                {
                    IGUIS::DropDownMenu::State = 5; // set state to clicked
                }
            }
            else // if mouse is on button
            {
                if (IGUIS::DropDownMenu::State != 0 && IGUIS::DropDownMenu::State != 1) // if state isn't "unhovered once" and "unhovered"
                {
                    IGUIS::DropDownMenu::State = 0; // set state to unhovered once
                }
                else // if state isn't "unhovered once" and "unhovered"
                {
                    IGUIS::DropDownMenu::State = 1; // set state to unhovered
                }
            }
        }

        if (Event->type == sf::Event::MouseButtonReleased && Event->mouseButton.button == sf::Mouse::Left) // if mouse button is released and left mouse button
        {
            if (IGUIS::DropDownMenu::State == 4 || IGUIS::DropDownMenu::State == 5) // if state is "clicked once" or "clicked"
            {
                IGUIS::DropDownMenu::State = 6; // set state to unclicked once
            }
            else if (IGUIS::DropDownMenu::MouseOnButton) // if state isn't "clicked once" or "clicked" and mouse is on button
            {
                IGUIS::DropDownMenu::State = 3; // set state to hovered
            }
        }
        #pragma endregion

        switch (IGUIS::DropDownMenu::State)
        {
        case 0:// state == unhovered once
            IGUIS::DropDownMenu::Background.setFillColor(IGUIS::DropDownMenu::ShapeColourUnhovered);
            IGUIS::IGUISElement::SpeakerUnhovered.play();
            break;

        case 1:// state == unhovered
            IGUIS::DropDownMenu::Background.setFillColor(IGUIS::DropDownMenu::ShapeColourUnhovered);
            break;

        case 2:// state == hovered once
            IGUIS::DropDownMenu::Background.setFillColor(IGUIS::DropDownMenu::ShapeColourHovered);
            IGUIS::IGUISElement::SpeakerHovered.play();
            break;

        case 3:// state == hovered
            IGUIS::DropDownMenu::Background.setFillColor(IGUIS::DropDownMenu::ShapeColourHovered);
            break;

        case 4:// state == clicked once
            IGUIS::DropDownMenu::Background.setFillColor(IGUIS::DropDownMenu::ShapeColourClicked);
            IGUIS::IGUISElement::SpeakerClicked.play();
            if (IGUIS::DropDownMenu::IsOpen)
            {
                IGUIS::DropDownMenu::IsOpen = false;
            }
            else
            {
                IGUIS::DropDownMenu::IsOpen = true;
            }
            break;

        case 5:// state == clicked
            IGUIS::DropDownMenu::Background.setFillColor(IGUIS::DropDownMenu::ShapeColourClicked);
            break;

        case 6:// state == unclicked once
            IGUIS::DropDownMenu::Background.setFillColor(IGUIS::DropDownMenu::ShapeColourHovered);
            break;
        }
    }
    else
    {
        IGUIS::DropDownMenu::State = 1;
        IGUIS::DropDownMenu::Background.setFillColor(IGUIS::DropDownMenu::ShapeColourDeactivated);
    }
}

void IGUIS::DropDownMenu::Draw()
{
    IGUIS::IGUISElement::Window->draw(Background);
    //Text.setScale(sf::Vector2f(Size.x * Window->getView().getSize().x / Text.getCharacterSize(), Size.y * Window->getView().getSize().y / Text.getCharacterSize()));
    Text.setPosition(Background.getPosition());
    Text.setOrigin(Text.getLocalBounds().width / 2, Text.getLocalBounds().height / 2);
    IGUIS::IGUISElement::Window->draw(Text);
    if (IsOpen)// jeœli niema na dole miejsca to do góry niech robi
    {
        for (uint8_t i = 0; i < Options.size(); i++)
        {
            xBackground.setPosition(Background.getPosition() + sf::Vector2f(0, Background.getSize().y + Background.getSize().y * i));
            xBackground.setSize(Background.getSize());
            xBackground.setOrigin(xBackground.getSize().x / 2, xBackground.getSize().y / 2);
            //xText.setScale(sf::Vector2f(Size.x * Window->getView().getSize().x / xText.getCharacterSize(), Size.y * Window->getView().getSize().y / xText.getCharacterSize()));
            xText.setPosition(xBackground.getPosition());
            xText.setString(Options[i]);
            xText.setOrigin(xText.getLocalBounds().width / 2, xText.getLocalBounds().height / 2);
            IGUIS::IGUISElement::Window->draw(xBackground);
            IGUIS::IGUISElement::Window->draw(xText);
        }
    }
}
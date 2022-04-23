#include "DragAndDropConnection.h"

IGUIS::DragAndDropConnection::DragAndDropConnection()
{
    
}

IGUIS::DragAndDropConnection::DragAndDropConnection(sf::Color ColourUnhovered, sf::Color ColourHovered, sf::Color ColourClicked, sf::Color ColourDeactivated, IGUIS::Origin Origin, char MaxOutGoingLineCount, float PositionX, float PositionY, float SizeX, float SizeY, bool IsPositionRelativeToScreen)
{
    IGUIS::DragAndDropConnection::Origin = Origin;
    IGUIS::DragAndDropConnection::ShapeColourUnhovered = ColourUnhovered;
    IGUIS::DragAndDropConnection::ShapeColourHovered = ColourHovered;
    IGUIS::DragAndDropConnection::ShapeColourClicked = ColourClicked;
    IGUIS::DragAndDropConnection::ShapeColourDeactivated = ColourDeactivated;
    IGUIS::DragAndDropConnection::MaxOutGoingLineCount = MaxOutGoingLineCount;
    IGUIS::DragAndDropConnection::Position = sf::Vector2f(PositionX, PositionY);
    IGUIS::DragAndDropConnection::Size = sf::Vector2f(SizeX, SizeY);
    IGUIS::DragAndDropConnection::PositionRelativeToScreen = PositionRelativeToScreen;
}

IGUIS::DragAndDropConnection::DragAndDropConnection(IGUIS::Origin Origin, char MaxOutGoingLineCount, float PositionX, float PositionY, float SizeX, float SizeY, bool IsPositionRelativeToScreen)
{
    IGUIS::DragAndDropConnection::Origin = Origin;
    IGUIS::DragAndDropConnection::MaxOutGoingLineCount = MaxOutGoingLineCount;
    IGUIS::DragAndDropConnection::Position = sf::Vector2f(PositionX, PositionY);
    IGUIS::DragAndDropConnection::Size = sf::Vector2f(SizeX, SizeY);
    IGUIS::DragAndDropConnection::PositionRelativeToScreen = PositionRelativeToScreen;
}

bool IGUIS::DragAndDropConnection::ContainPoint(sf::Vector2f Point)
{
    return IGUIS::DragAndDropConnection::Shape.getGlobalBounds().contains(Point);
}

void IGUIS::DragAndDropConnection::SetPosition(sf::Vector2f Position)
{
    IGUIS::IGUISElement::Position = Position;
}

void IGUIS::DragAndDropConnection::SetPosition(float X, float Y)
{
    IGUIS::IGUISElement::Position = sf::Vector2f(X, Y);
}

sf::Vector2f IGUIS::DragAndDropConnection::GetPosition()
{
    return IGUIS::IGUISElement::Position;
}

void IGUIS::DragAndDropConnection::Update(sf::Event* Event)
{
    if (Event->type == sf::Event::MouseButtonPressed)
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && IGUIS::DragAndDropConnection::Shape.getGlobalBounds().contains(IGUIS::IGUISElement::Window->mapPixelToCoords(sf::Mouse::getPosition(*IGUIS::IGUISElement::Window))))
        {
            IGUIS::DragAndDropConnection::Dragging = true;
            if (IGUIS::DragAndDropConnection::MaxOutGoingLineCount != IGUIS::DragAndDropConnection::Line.size())
            {
                IGUIS::DragAndDropConnection::Line.push_back(IGUIS::Line(Origin, ShapeColourUnhovered, 0.5f, 0, 0, 0, 0, PositionRelativeToScreen));
                IGUIS::DragAndDropConnection::ActuallyUsedLine = IGUIS::DragAndDropConnection::Line.size() - 1;
                IGUIS::DragAndDropConnection::Line[IGUIS::DragAndDropConnection::ActuallyUsedLine].SetPositionA(IGUIS::DragAndDropConnection::Shape.getPosition());
            }
        }
    }
    else if (Event->type == Event->MouseButtonReleased && Event->mouseButton.button == sf::Mouse::Left)
    {
        if (IGUIS::DragAndDropConnection::Dragging)
        {
            IGUIS::DragAndDropConnection::Dragging = false;
            for (unsigned short i = 0; i < IGUIS::DragAndDropConnection::CanBeConnectedTo.size(); i++)
            {
                if (IGUIS::DragAndDropConnection::CanBeConnectedTo[i]->ContainPoint(Window->mapPixelToCoords(sf::Mouse::getPosition(*Window))))
                {
                    IGUIS::DragAndDropConnection::Line[IGUIS::DragAndDropConnection::ActuallyUsedLine].SetPositionB(IGUIS::DragAndDropConnection::CanBeConnectedTo[i]->GetPosition());
                    ConnectedTo.push_back(IGUIS::DragAndDropConnection::CanBeConnectedTo[i]);
                    goto DroppedOnSomething; // that goes down
                }
            }
            IGUIS::DragAndDropConnection::Line.erase(IGUIS::DragAndDropConnection::Line.begin() + IGUIS::DragAndDropConnection::Line.size() - 1);
            DroppedOnSomething:;
        }
    }

    /*if (Dragging)
    {
        sf::Vector2f px = sf::Vector2f(sf::Mouse::getPosition(Window));
        px = sf::Vector2f(px.x / Camera.getSize().x, px.y / Camera.getSize().y);
        px += sf::Vector2f(-0.5f, -0.5f);
        DragAndDropLine.SetPositionB(px); // pamiêtaæ ¿e jak jedno jest po³¹czone do drógiego to drógie nie mo¿e sie po³¹czyæ z pierwszym
    }*/

    /*if (Dragging)
    {
        sf::Vector2f px = sf::Vector2f(sf::Mouse::getPosition(Window));
        px = sf::Vector2f(px.x / Camera.getSize().x, px.y / Camera.getSize().y);
        px += sf::Vector2f(-0.5f, -0.5f);
        IGUIS::DragAndDropConnection::Line[ActuallyUsedLine].SetPositionB(px);// TODO: niech bêd¹ !relativetoscreen i podaæ to w px
    }*/

    if (IGUIS::IGUISElement::PositionRelativeToScreen) // if position must be relative to screen
    {
        IGUIS::DragAndDropConnection::Shape.setPosition(IGUIS::IGUISElement::GetPositionOnScreenInPxUsingPencentageAndOrigin(IGUIS::IGUISElement::Origin, IGUIS::IGUISElement::Position, IGUIS::IGUISElement::Size));
    }
    else // if position must be relative to screen
    {
        IGUIS::DragAndDropConnection::Shape.setPosition(IGUIS::DragAndDropConnection::Position);
    }
    IGUIS::DragAndDropConnection::Shape.setSize(sf::Vector2f(IGUIS::IGUISElement::Size.x * IGUIS::IGUISElement::Window->getView().getSize().x, IGUIS::IGUISElement::Size.y * IGUIS::IGUISElement::Window->getView().getSize().y));
    IGUIS::DragAndDropConnection::Shape.setOrigin(IGUIS::DragAndDropConnection::Shape.getSize().x / 2, IGUIS::DragAndDropConnection::Shape.getSize().y / 2);
    
    if (IGUIS::DragAndDropConnection::IsActive)
    {
        IGUIS::DragAndDropConnection::ShapeRect = static_cast<sf::FloatRect>(IGUIS::DragAndDropConnection::Shape.getGlobalBounds());

        IGUIS::DragAndDropConnection::MouseOnButton = IGUIS::DragAndDropConnection::ShapeRect.contains(IGUIS::IGUISElement::Window->mapPixelToCoords(sf::Mouse::getPosition(*IGUIS::IGUISElement::Window)));

        #pragma region get state
        if (IGUIS::DragAndDropConnection::State == 6) // if state is "unclicked once"
        {
            if (IGUIS::DragAndDropConnection::MouseOnButton) // if mouse is on button
            {
                IGUIS::DragAndDropConnection::State = 3; //set state to hovered
            }
            else // if mouse is on button
            {
                IGUIS::DragAndDropConnection::State = 2; //set state to unhovered once
            }
        }

        if (Event->type == sf::Event::MouseMoved) // if mouse moved
        {
            if (IGUIS::DragAndDropConnection::MouseOnButton) // if mouse is on button
            {
                if (IGUIS::DragAndDropConnection::State != 4 && IGUIS::DragAndDropConnection::State != 5) // if state isn't "clicked once" and "clicked"
                {
                    if (IGUIS::DragAndDropConnection::State != 2 && IGUIS::DragAndDropConnection::State != 3) // if state isn't "hovered once" and "hovered"
                    {
                        IGUIS::DragAndDropConnection::State = 2; // set state to hovered once
                    }
                    else // if state isn't "hovered once" and "hovered"
                    {
                        IGUIS::DragAndDropConnection::State = 3; // set state to hovered
                    }
                }
            }
            else // if mouse is on button
            {
                if (IGUIS::DragAndDropConnection::State != 0 && IGUIS::DragAndDropConnection::State != 1) // if state isn't "unhovered once" and "unhovered"
                {
                    IGUIS::DragAndDropConnection::State = 0; // set state to unhovered once
                }
                else // if state isn't "unhovered once" and "unhovered"
                {
                    IGUIS::DragAndDropConnection::State = 1; // set state to unhovered
                }
            }
        }

        if (Event->type == sf::Event::MouseButtonPressed && Event->mouseButton.button == sf::Mouse::Left) // if mouse button is pressed and left mouse button
        {
            if (IGUIS::DragAndDropConnection::MouseOnButton) // if mouse is on button
            {
                if (IGUIS::DragAndDropConnection::State != 4 && IGUIS::DragAndDropConnection::State != 5) // if state isn't "clicked once" and "clicked"
                {
                    IGUIS::DragAndDropConnection::State = 4; // set state to clicked once
                }
                else // if state isn't "clicked once" and "clicked"
                {
                    IGUIS::DragAndDropConnection::State = 5; // set state to clicked
                }
            }
            else // if mouse is on button
            {
                if (IGUIS::DragAndDropConnection::State != 0 && IGUIS::DragAndDropConnection::State != 1) // if state isn't "unhovered once" and "unhovered"
                {
                    IGUIS::DragAndDropConnection::State = 0; // set state to unhovered once
                }
                else // if state isn't "unhovered once" and "unhovered"
                {
                    IGUIS::DragAndDropConnection::State = 1; // set state to unhovered
                }
            }
        }

        if (Event->type == sf::Event::MouseButtonReleased && Event->mouseButton.button == sf::Mouse::Left) // if mouse button is released and left mouse button
        {
            if (IGUIS::DragAndDropConnection::State == 4 || IGUIS::DragAndDropConnection::State == 5) // if state is "clicked once" or "clicked"
            {
                IGUIS::DragAndDropConnection::State = 6; // set state to unclicked once
            }
            else if (IGUIS::DragAndDropConnection::MouseOnButton) // if state isn't "clicked once" or "clicked" and mouse is on button
            {
                IGUIS::DragAndDropConnection::State = 3; // set state to hovered
            }
        }
        #pragma endregion


        switch (IGUIS::DragAndDropConnection::State)
        {
        case 0:// state == unhovered once
            IGUIS::DragAndDropConnection::Shape.setFillColor(IGUIS::DragAndDropConnection::ShapeColourUnhovered);
            IGUIS::IGUISElement::SpeakerUnhovered.play();
            break;

        case 1:// state == unhovered
            IGUIS::DragAndDropConnection::Shape.setFillColor(IGUIS::DragAndDropConnection::ShapeColourUnhovered);
            break;

        case 2:// state == hovered once
            IGUIS::DragAndDropConnection::Shape.setFillColor(IGUIS::DragAndDropConnection::ShapeColourHovered);
            IGUIS::IGUISElement::SpeakerHovered.play();
            break;

        case 3:// state == hovered
            IGUIS::DragAndDropConnection::Shape.setFillColor(IGUIS::DragAndDropConnection::ShapeColourHovered);
            break;

        case 4:// state == clicked once
            IGUIS::DragAndDropConnection::Shape.setFillColor(IGUIS::DragAndDropConnection::ShapeColourClicked);
            IGUIS::IGUISElement::SpeakerClicked.play();
            break;

        case 5:// state == clicked
            IGUIS::DragAndDropConnection::Shape.setFillColor(IGUIS::DragAndDropConnection::ShapeColourClicked);
            break;

        case 6:// state == unclicked once
            IGUIS::DragAndDropConnection::Shape.setFillColor(IGUIS::DragAndDropConnection::ShapeColourHovered);
            break;
        }
    }
    else
    {
        IGUIS::DragAndDropConnection::State = 7;
        IGUIS::DragAndDropConnection::Shape.setFillColor(IGUIS::DragAndDropConnection::ShapeColourDeactivated);
    }

    for (char i = 0; i < IGUIS::DragAndDropConnection::Line.size(); i++)
    {
        IGUIS::DragAndDropConnection::Line[i].Update();
    }
}

void IGUIS::DragAndDropConnection::Draw()
{
    IGUIS::IGUISElement::Window->draw(IGUIS::DragAndDropConnection::Shape);
    for (char i = 0; i < IGUIS::DragAndDropConnection::Line.size(); i++)
    {
        IGUIS::DragAndDropConnection::Line[i].Draw();
    }
}
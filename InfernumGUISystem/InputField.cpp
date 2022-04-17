#include "InputField.h"

IGUIS::InputField::InputField()
{

}

IGUIS::InputField::InputField(std::wstring String, sf::Font* Font, IGUIS::Origin OriginOfObject, float PositionX, float PositionY, float SizeX, float SizeY, bool IsPositionRelativeToScreen)
{
    IGUIS::InputField::TextVar.setString(String);
    IGUIS::InputField::TextVar.setFont(*Font);
    IGUIS::InputField::Origin = OriginOfObject;
    IGUIS::InputField::Position = sf::Vector2f(PositionX, PositionY);
    IGUIS::InputField::Size = sf::Vector2f(SizeX, SizeY);
    IGUIS::InputField::PositionRelativeToScreen = IsPositionRelativeToScreen;
}

IGUIS::InputField::InputField(sf::Font* Font, IGUIS::Origin OriginOfObject, float PositionX, float PositionY, float SizeX, float SizeY, bool IsPositionRelativeToScreen)
{
    IGUIS::InputField::TextVar.setFont(*Font);
    IGUIS::InputField::Origin = OriginOfObject;
    IGUIS::InputField::Position = sf::Vector2f(PositionX, PositionY);
    IGUIS::InputField::Size = sf::Vector2f(SizeX, SizeY);
    IGUIS::InputField::PositionRelativeToScreen = IsPositionRelativeToScreen;
}

void IGUIS::InputField::SetQuality(uint8_t ID, unsigned int Quality)
{
    TextVar.setCharacterSize(Quality);
}

unsigned int IGUIS::InputField::GetQuality(uint8_t ID)
{
    return TextVar.getCharacterSize();
}

void IGUIS::InputField::SetFont(uint8_t ID, sf::Font Font)
{
    TextVar.setFont(Font);
}

const sf::Font* IGUIS::InputField::GetFont(uint8_t ID)
{
    return TextVar.getFont();
}

void IGUIS::InputField::SetFillColor(uint8_t ID, sf::Color FillColor)
{
    TextVar.setFillColor(FillColor);
}

const sf::Color IGUIS::InputField::GetFillColor(uint8_t ID)
{
    return TextVar.getFillColor();
}

void IGUIS::InputField::SetOutlineColor(uint8_t ID, sf::Color OutlineColor)
{
    TextVar.setOutlineColor(OutlineColor);
}

const sf::Color IGUIS::InputField::GetOutlineColor(uint8_t ID)
{
    return TextVar.getOutlineColor();
}

void IGUIS::InputField::SetString(uint8_t ID, std::wstring String)
{
    TextVar.setString(String);
}

std::wstring IGUIS::InputField::GetString(uint8_t ID)
{
    return TextVar.getString();
}

void IGUIS::InputField::TextEntred(sf::Uint32 Key)
{
    if (Typing)
    {
        if (Key > 31 && Key < 127 || Key > 160)
        {
            TextVar.setString(TextVar.getString() + Key);
        }
        else if (Key == 8 && !TextVar.getString().isEmpty())//backspace
        {
            TextVar.setString(TextVar.getString().toAnsiString().erase(TextVar.getString().getSize() - 1));
        }
    }
}

bool IGUIS::InputField::ContainPoint(sf::Vector2f Point)
{
    return TextVar.getGlobalBounds().contains(Point);
}

void IGUIS::InputField::SetPosition(sf::Vector2f Position)
{
    IGUIS::IGUISElement::Position = Position;
}

void IGUIS::InputField::SetPosition(float X, float Y)
{
    IGUIS::IGUISElement::Position = sf::Vector2f(X, Y);
}

sf::Vector2f IGUIS::InputField::GetPosition()
{
    return IGUIS::IGUISElement::Position;
}

void IGUIS::InputField::SetSize(sf::Vector2f Size)
{
    IGUIS::IGUISElement::Size = Size;
}

void IGUIS::InputField::SetSize(float X, float Y)
{
    IGUIS::IGUISElement::Size = sf::Vector2f(X, Y);
}

sf::Vector2f IGUIS::InputField::GetSize()
{
    return IGUIS::IGUISElement::Size;
}

void IGUIS::InputField::Update(sf::Event* Event)
{
    if (IGUIS::IGUISElement::PositionRelativeToScreen) // if position must be relative to screen
    {
        IGUIS::InputField::TextVar.setPosition(IGUIS::IGUISElement::GetPositionOnScreenInPxUsingPencentageAndOrigin(IGUIS::IGUISElement::Origin, IGUIS::IGUISElement::Position, IGUIS::IGUISElement::Size));
    }
    else // if position must be relative to screen
    {
        IGUIS::InputField::TextVar.setPosition(IGUIS::IGUISElement::Position);
    }

    // pobrano z Text.cpp
    IGUIS::InputField::TextVar.setOrigin(TextVar.getLocalBounds().width / 2, TextVar.getLocalBounds().height / 2);
    IGUIS::InputField::TextVar.setScale(Size.x * IGUIS::IGUISElement::Window->getView().getSize().x / TextVar.getLocalBounds().width, Size.y * IGUIS::IGUISElement::Window->getView().getSize().y / TextVar.getLocalBounds().height);
    IGUIS::InputField::TextVar.setOrigin(TextVar.getLocalBounds().width / 2, TextVar.getLocalBounds().height / 2);

    // test area

    if (TextVar.getGlobalBounds().contains(IGUIS::IGUISElement::Window->mapPixelToCoords(sf::Mouse::getPosition(*IGUIS::IGUISElement::Window))) && Event->type == sf::Event::MouseButtonPressed && Event->mouseButton.button == sf::Mouse::Left)
    {
        IGUIS::InputField::Typing = true;
    }
    else if (!TextVar.getGlobalBounds().contains(IGUIS::IGUISElement::Window->mapPixelToCoords(sf::Mouse::getPosition(*IGUIS::IGUISElement::Window))) && Event->type == sf::Event::MouseButtonPressed && Event->mouseButton.button == sf::Mouse::Left)
    {
        IGUIS::InputField::Typing = false;
    }
    
    /*if (Typing && Event->type == sf::Event::TextEntered)
    {
        if (Event->text.unicode > 31 && Event->text.unicode < 127 || Event->text.unicode > 160)
        {
            TextVar.setString(TextVar.getString() + Event->text.unicode);
        }
    }*/

    // !test area
}

void IGUIS::InputField::Draw()
{
    IGUIS::IGUISElement::Window->draw(IGUIS::InputField::Background);
    IGUIS::IGUISElement::Window->draw(IGUIS::InputField::TextVar);
}
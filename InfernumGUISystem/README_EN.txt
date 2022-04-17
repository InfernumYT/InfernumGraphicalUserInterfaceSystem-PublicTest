┌────┐
│ EN ╞► Welcome to InfernumGUISystem
└────┘


►InfernumGUISystem/GUIElement (Important, every class in InfernumGUISystem inherits from this class)

- GUI::Origin Origin = Origin::Middle
Used to set where is 0, 0 position for that object

- bool PositionRelativeToScreen = true;
if false, origin is not used, and position is in px

- virtual void SetPosition(sf::Vector2f Position);
Position on screen in %, 1% == 0.1f

- virtual sf::Vector2f GetPosition();
Position on screen in %, 1% == 0.1f

- virtual void SetSize(sf::Vector2f Size);
Size on screen in %, 1% == 0.1f

- virtual sf::Vector2f GetSize();
Size on screen in %, 1% == 0.1f

- static void SetVolume(float Volume)
Used to set static volume of sounds in GUI
Scale from 0 to 100

- static void SetSounds(sf::SoundBuffer* Hovered, sf::SoundBuffer* Unhovered, sf::SoundBuffer* Clicked)
Used to set static sounds in GUI

-static void SetSoundWhenHovered(sf::SoundBuffer* Hovered);
Used to set static sound in GUI

-static void SetSoundWhenUnhovered(sf::SoundBuffer* Unhovered);
Used to set static sound in GUI

-static void SetSoundWhenClicked(sf::SoundBuffer* Clicked);
Used to set static sound in GUI

────────────────────────────────────────────────────────────────────────────────────────────────────

►InfernumGUISystem/Button

- uint8_t State = 1;
Possible output:
0 - unhovered once
1 - unhovered
2 - hovered once
3 - hovered
4 - clicked once
5 - clicked

- sf::Color ShapeColourUnhovered = sf::Color();

- sf::Color ShapeColourHovered = sf::Color();

- sf::Color ShapeColourClicked = sf::Color();

- sf::Color ShapeColourDeactivated = sf::Color();

- bool IsActive = true;
Can be clicked?

- Button();

- Button(const sf::Texture* Texture, sf::Color ColourUnhovered, sf::Color ColourHovered, sf::Color ColourClicked, sf::Color ColourDeactivated, IGUIS::Origin OriginOfObject, float PositionX, float PositionY, float SizeX, float SizeY);
SizeX set (1 / 16.0f * x) to make square :)
SizeY set (1 / 9.0f * x) to make square :)

- void SetTexture(const sf::Texture* Texture);

- const sf::Texture* GetTexture();

- bool ContainPoint(sf::Vector2f Point);

- void Update(sf::Event *Event, sf::RenderWindow *Window);

- void Draw(sf::RenderWindow *Window);

────────────────────────────────────────────────────────────────────────────────────────────────────

►InfernumGUISystem/Checkbox

- uint8_t State = 1;
Possible output:
0 - unhovered once
1 - unhovered
2 - hovered once
3 - hovered
4 - clicked once
5 - clicked

- const sf::Texture* ShapeTextureIfTurnedOff;

- const sf::Texture* ShapeTextureIfTurnedOn;

- sf::Color ShapeColourUnhovered = sf::Color();

- sf::Color ShapeColourHovered = sf::Color();

- sf::Color ShapeColourClicked = sf::Color();

- sf::Color ShapeColourDeactivated = sf::Color();

- bool IsActive = true;
Can be clicked?

- bool IsTurnedOn = false;
Used for read on/off, or setting on/off

- Checkbox();

- Checkbox(const sf::Texture* TextureIfTurnedOff, const sf::Texture* TextureIfTurnedOn, sf::Color ColourUnhovered, sf::Color ColourHovered, sf::Color ColourClicked, sf::Color ColourDeactivated, IGUIS::Origin OriginOfObject, float PositionX, float PositionY, float SizeX, float SizeY);
SizeX set (1 / 16.0f * x) to make square :)
SizeY set (1 / 9.0f * x) to make square :)

- bool ContainPoint(sf::Vector2f Point);

- void Update(sf::Event* Event, sf::RenderWindow* Window);

- void Draw(sf::RenderWindow* Window);

────────────────────────────────────────────────────────────────────────────────────────────────────

►InfernumGUISystem/Shape
- Shape();

- Shape(const sf::Texture* Texture, IGUIS::Origin OriginOfObject, float PositionX, float PositionY, float SizeX, float SizeY);
SizeX set (1 / 16.0f * x) to make square :)
SizeY set (1 / 9.0f * x) to make square :)

- void SetFillColor(sf::Color Color);

- const sf::Color GetFillColor();

- void SetOutlineColor(sf::Color OutlineColor);

- const sf::Color GetOutlineColor();

- void SetOutlineThickness(float OutlineThickness);

- const float GetOutlineThickness();

- void SetTexture(const sf::Texture* Texture);

- const sf::Texture* GetTexture();

- bool ContainPoint(sf::Vector2f Point);

- void Draw(sf::RenderWindow* Window);

────────────────────────────────────────────────────────────────────────────────────────────────────

►InfernumGUISystem/Text
- Text();

- Text(std::wstring String, sf::Font* Font, IGUIS::Origin OriginOfObject, unsigned int Quality, sf::Color FillColor, sf::Color OutlineColor, float PositionX, float PositionY, float SizeX, float SizeY);
Quality - default is 30
FillColor - default is white
OutlineColor - default is transparent

- void SetQuality(unsigned int Quality);

- unsigned int GetQuality();

- void SetFont(sf::Font Font);

- const sf::Font* GetFont();

- void SetFillColor(sf::Color Color);

- const sf::Color GetFillColor();

- void SetOutlineColor(sf::Color OutlineColor);

- const sf::Color GetOutlineColor();

-void SetOutlineThickness(float OutlineThickness);

-const float GetOutlineThickness();

- void SetString(std::wstring String);

- std::wstring GetString();

- bool ContainPoint(sf::Vector2f Point);

- void Update(sf::RenderWindow* Window);

- void Draw(sf::RenderWindow* Window);

────────────────────────────────────────────────────────────────────────────────────────────────────

►InfernumGUISystem/Progressbar
- Progressbar();

- Progressbar(sf::Color BackgroundFillColor, sf::Color BackgroundOutlineColor, sf::Color FillShapeFillColor, sf::Color FillShapeOutlineColor, IGUIS::Origin OriginOfObject, float PositionX, float PositionY, float SizeX, float SizeY);
set (1 / 16.0f * x) to make square :)
set (1 / 9.0f * x) to make square :)

- void SetBackgroundFillColor(sf::Color Color);

- const sf::Color GetBackgroundFillColor();

- void SetBackgroundOutlineColor(sf::Color OutlineColor);

- const sf::Color GetBackgroundOutlineColor();

- void SetFillShapeFillColor(sf::Color Color);

- const sf::Color GetFillShapeFillColor();

- void SetFillShapeOutlineColor(sf::Color OutlineColor);

- const sf::Color GetFillShapeOutlineColor();

- bool ContainPoint(sf::Vector2f Point);

- void SetFillSize(float FillSize);

- float GetFillSize();

- void Draw(sf::RenderWindow* Window);

────────────────────────────────────────────────────────────────────────────────────────────────────

►InfernumGUISystem/Slider
-Work in progress

────────────────────────────────────────────────────────────────────────────────────────────────────

►InfernumGUISystem/InputField
-Work in progress
┌────┐
│ PL ╞► Witaj w InfernumGUISystem
└────┘


►InfernumGUISystem/GUIElement (Ważne, wszystkie klasy w InfernumGUISystem dziedziczą z tej klasy)

- static const std::string VersionOfIGUIS;

- static void SetWindow(sf::RenderWindow* Window);
Używane do ustawienia statycznego Window* w IGUIS

- static sf::RenderWindow* GetWindow();
Używane do pobrania statycznego Window* z IGUIS

- GUI::Origin Origin = Origin::Middle
Używane do ustawienia gdzie jest pozycja 0, 0 dla tego obiektu

- bool PositionRelativeToScreen = true;
Jeśli false, origin jest nie używany i pozycja jest w px

-static void SetVolume(float Volume)
Używane do ustawiania statycznej głośności dźwięków GUI
Scale from 0 to 100

-static void SetSounds(sf::SoundBuffer* Hovered, sf::SoundBuffer* Unhovered, sf::SoundBuffer* Clicked)
Używane do ustawiania statycznych dźwięków w GUI

-static void SetSoundWhenHovered(sf::SoundBuffer* Hovered);
Używane do ustawiania statycznego dźwięku w GUI

-static void SetSoundWhenUnhovered(sf::SoundBuffer* Unhovered);
Używane do ustawiania statycznego dźwięku w GUI

-static void SetSoundWhenClicked(sf::SoundBuffer* Clicked);
Używane do ustawiania statycznego dźwięku w GUI

────────────────────────────────────────────────────────────────────────────────────────────────────

►InfernumGUISystem/Button

- uint8_t State = 7;
Possible output:
0 - unhovered once
1 - unhovered
2 - hovered once
3 - hovered
4 - clicked once
5 - clicked
6 - unclicked once
7 - unactive

- sf::Color ShapeColourUnhovered = sf::Color();
Domyślnie 255, 255, 255

- sf::Color ShapeColourHovered = sf::Color();
Domyślnie 235, 235, 235

- sf::Color ShapeColourClicked = sf::Color();
Domyślnie 215, 215, 215

- sf::Color ShapeColourDeactivated = sf::Color();
Domyślnie 195, 195, 195

- bool IsActive = true;
Może być kliknięty?

- Button();

- Button(const sf::Texture* Texture, sf::Color ColourUnhovered, sf::Color ColourHovered, sf::Color ColourClicked, sf::Color ColourDeactivated, IGUIS::Origin OriginOfObject, float PositionX, float PositionY, float SizeX, float SizeY, bool IsPositionRelativeToScreen);
SizeX ustaw (1 / 16.0f * x) by zrobić kwadrat :)
SizeY ustaw (1 / 9.0f * x) by zrobić kwadrat :)

- Button(const sf::Texture* Texture, IGUIS::Origin OriginOfObject, float PositionX, float PositionY, float SizeX, float SizeY, bool IsPositionRelativeToScreen);

- void SetTexture(const sf::Texture* Texture);

- const sf::Texture* GetTexture();

- bool ContainPoint(sf::Vector2f Point);

- void SetPosition(sf::Vector2f Position);
Pozycja na ekranie w %, 1% == 0.1f

- void SetPosition(float X, float Y);
Pozycja na ekranie w %, 1% == 0.1f

- sf::Vector2f GetPosition();
Pozycja na ekranie w %, 1% == 0.1f

- void SetSize(sf::Vector2f Size);
Rozmiar na ekranie w %, 1% == 0.1f

- void SetSize(float X, float Y);
Rozmiar na ekranie w %, 1% == 0.1f

- sf::Vector2f GetSize();
Rozmiar na ekranie w %, 1% == 0.1f

- void Update(sf::Event *Event, sf::RenderWindow *Window);

- void Draw(sf::RenderWindow *Window);

────────────────────────────────────────────────────────────────────────────────────────────────────

►InfernumGUISystem/Checkbox

- uint8_t State = 7;
Possible output:
0 - unhovered once
1 - unhovered
2 - hovered once
3 - hovered
4 - clicked once
5 - clicked
6 - unclicked once
7 - unactive

- const sf::Texture* ShapeTextureIfTurnedOff;

- const sf::Texture* ShapeTextureIfTurnedOn;

- sf::Color ShapeColourUnhovered = sf::Color();
Domyślnie 255, 255, 255

- sf::Color ShapeColourHovered = sf::Color();
Domyślnie 235, 235, 235

- sf::Color ShapeColourClicked = sf::Color();
Domyślnie 215, 215, 215

- sf::Color ShapeColourDeactivated = sf::Color();
Domyślnie 195, 195, 195

- bool IsActive = true;
Może być kliknięty?

- bool IsTurnedOn = false;
Używane do odczytu on/off, lub ustawiania on/off

- Checkbox();

- Checkbox(const sf::Texture* TextureIfTurnedOff, const sf::Texture* TextureIfTurnedOn, sf::Color ColourUnhovered, sf::Color ColourHovered, sf::Color ColourClicked, sf::Color ColourDeactivated, IGUIS::Origin OriginOfObject, float PositionX, float PositionY, float SizeX, float SizeY, bool IsPositionRelativeToScreen);
SizeX ustaw (1 / 16.0f * x) żeby zrobić kwadrat :)
SizeY ustaw (1 / 9.0f * x) żeby zrobić kwadrat :)

- Checkbox(const sf::Texture* TextureIfTurnedOff, const sf::Texture* TextureIfTurnedOn, IGUIS::Origin OriginOfObject, float PositionX, float PositionY, float SizeX, float SizeY, bool IsPositionRelativeToScreen)

- bool ContainPoint(sf::Vector2f Point);

- void SetPosition(sf::Vector2f Position);
Pozycja na ekranie w %, 1% == 0.1f

- void SetPosition(float X, float Y);
Pozycja na ekranie w %, 1% == 0.1f

- sf::Vector2f GetPosition();
Pozycja na ekranie w %, 1% == 0.1f

- void SetSize(sf::Vector2f Size);
Rozmiar na ekranie w %, 1% == 0.1f

- void SetSize(float X, float Y);
Rozmiar na ekranie w %, 1% == 0.1f

- sf::Vector2f GetSize();
Rozmiar na ekranie w %, 1% == 0.1f

- void Update(sf::Event* Event);

- void Draw();

────────────────────────────────────────────────────────────────────────────────────────────────────

►InfernumGUISystem/Line
- Line();

- Line(IGUIS::Origin OriginOfObject, sf::Color FillColor, sf::Color OutlineColor, float Thickness, float OutlineThickness, float Position1X, float Position1Y, float Position2X, float Position2Y, bool IsPositionRelativeToScreen);
- Line(IGUIS::Origin OriginOfObject, sf::Color FillColor, float Thickness, float Position1X, float Position1Y, float Position2X, float Position2Y, bool IsPositionRelativeToScreen);

- bool ContainPoint(sf::Vector2f Point);

- void SetPositionA(sf::Vector2f Position);
Pozycja na ekranie w %, 1% == 0.1f

- void SetPositionA(float X, float Y);
Pozycja na ekranie w %, 1% == 0.1f

- sf::Vector2f GetPositionA();
Pozycja na ekranie w %, 1% == 0.1f

- void SetPositionB(sf::Vector2f Size);
Rozmiar na ekranie w %, 1% == 0.1f

- void SetPositionB(float X, float Y);
Rozmiar na ekranie w %, 1% == 0.1f

- sf::Vector2f GetPositionB();
Rozmiar na ekranie w %, 1% == 0.1f

- void Update();

- void Draw();

────────────────────────────────────────────────────────────────────────────────────────────────────

►InfernumGUISystem/Shape
- Shape();

- Shape(const sf::Texture* Texture, sf::Color Color, IGUIS::Origin OriginOfObject, float PositionX, float PositionY, float SizeX, float SizeY, bool IsPositionRelativeToScreen);
SizeX ustaw (1 / 16.0f * x) by zrobić kwadrat :)
SizeY ustaw (1 / 9.0f * x) by zrobić kwadrat :)

- void SetFillColor(sf::Color Color);

- const sf::Color GetFillColor();

- void SetOutlineColor(sf::Color OutlineColor);

- const sf::Color GetOutlineColor();

- void SetOutlineThickness(float OutlineThickness);

- const float GetOutlineThickness();

- void SetTexture(const sf::Texture* Texture);

- const sf::Texture* GetTexture();

- bool ContainPoint(sf::Vector2f Point);

- void SetPosition(sf::Vector2f Position);
Pozycja na ekranie w %, 1% == 0.1f

- void SetPosition(float X, float Y);
Pozycja na ekranie w %, 1% == 0.1f

- sf::Vector2f GetPosition();
Pozycja na ekranie w %, 1% == 0.1f

- void SetSize(sf::Vector2f Size);
Rozmiar na ekranie w %, 1% == 0.1f

- void SetSize(float X, float Y);
Rozmiar na ekranie w %, 1% == 0.1f

- sf::Vector2f GetSize();
Rozmiar na ekranie w %, 1% == 0.1f

- void Update();

- void Draw();

────────────────────────────────────────────────────────────────────────────────────────────────────

►InfernumGUISystem/Text
- Text();

- Text(std::wstring String, sf::Font* Font, IGUIS::Origin OriginOfObject, unsigned int Quality, sf::Color FillColor, sf::Color OutlineColor, float PositionX, float PositionY, float SizeX, float SizeY);
Quality - domyślnie jest 30
FillColor - domyślnie jest biały
OutlineColor - domyślnie jest transparentny

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

- void Update();

- void Draw();

────────────────────────────────────────────────────────────────────────────────────────────────────

►InfernumGUISystem/Progressbar
- Progressbar();

- Progressbar(sf::Color BackgroundFillColor, sf::Color BackgroundOutlineColor, sf::Color FillShapeFillColor, sf::Color FillShapeOutlineColor, IGUIS::Origin OriginOfObject, float PositionX, float PositionY, float SizeX, float SizeY);
SizeX ustaw (1 / 16.0f * x) żeby zrobić kwadrat :)
SizeY ustaw (1 / 9.0f * x) żeby zrobić kwadrat :)

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

- void Draw();

────────────────────────────────────────────────────────────────────────────────────────────────────

►InfernumGUISystem/Slider
-Praca w toku

────────────────────────────────────────────────────────────────────────────────────────────────────

►InfernumGUISystem/InputField
-Praca w toku

────────────────────────────────────────────────────────────────────────────────────────────────────

►InfernumGUISystem/DragAndDropConnection
-Praca w toku
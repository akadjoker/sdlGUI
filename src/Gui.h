#pragma once
#include "pch.h"
#include "Math.h"

class RenderBatch;
class Texture;
class Font;
class Widget;
class Window;
class Slider;
class Label;
class Button;
class CheckBox;
class RadioButton;
class RadioGroup;
class ListBox;


enum GUI_COLOR
{
    BUTTON_TEXT,		
    BUTTON_FACE,	
    BUTTON_DOWN,
    LABEL,
    LABEL_BACKGROUND,
    SCROLLBAR,	
    SCROLLBAR_NOB,	
    SCROLLBAR_FILL,
    CHECKBOX,
    CHECKBOX_TEXT,
    CHECKBOX_DOWN,
    CHECKBOX_CHECK,
    CHECKBOX_OVER,

    RADIO,
    RADIO_DOWN,
    RADIO_TEXT,
    RADIO_CHECK,
    RADIO_OVER,

    RADIO_GROUP,
    RADIO_GROUP_ITEM,
    RADIO_GROUP_ITEM_OVER,
    RADIO_GROUP_TEXT,
    RADIO_GROUP_DOWN,
    RADIO_GROUP_CHECK,
    RADIO_GROUP_OVER,

    LISTBOX_TEXT,
    LISTBOX_FACE,
    LISTBOX_SELECTED,
    LISTBOX_SELECTED_TEXT,
    LISTBOX_ITEM_OVER,
    WINDOW_BODY,
    WINDOW_TOP_BAR,		
    WINDOW_TITLE,
    WINDOW,			
    COLORS_COUNT
};


class Skin
{
    public:
        Skin();
        ~Skin();

        Color GetColor(GUI_COLOR color) const { return m_colors[color]; }
        Font *GetFont() const { return m_font; }
        void SetColor(GUI_COLOR color, const Color& value) { m_colors[color] = value; }
        void SetColor(GUI_COLOR color, float r, float g, float b, float a) { m_colors[color].r = r; m_colors[color].g = g; m_colors[color].b = b; m_colors[color].a = a; }

    private:
        Color m_colors[COLORS_COUNT];
        Font *m_font;
};


class GUI 
{   
    public:


    GUI();
    ~GUI();
    void Clear();

    void SetSkin(Skin* skin);
    Skin* GetSkin() const { return m_skin; }

    Window *CreateWindow(const std::string& title, float x, float y, float width, float height);

    void SetScissor(int x, int y, int w, int h);
    void SetViewSize(float width, float height) { m_width = width; m_height = height; }
    
    void Update(float delta);
    void Render(RenderBatch* batch);
    void OnMouseMove(int x, int y);
    void OnMouseDown(int x, int y, int button);
    void OnMouseUp(int x, int y, int button);
    void OnMouseWheel(int delta);
    void OnKeyDown(Uint32 key);
    void OnKeyUp(Uint32 key);

    

    private:
        Skin* m_skin;
        std::vector<Widget*> m_widgets;
            float m_height;
    float m_width;

};


class Widget
{
    friend class GUI;
public:
    Widget();
    virtual ~Widget();

    void Render(RenderBatch* batch);
    void Add(Widget* widget);
    void Remove(Widget* widget);
    void RemoveAll();

    void SetVisible(bool visible) { m_visible = visible; }
    bool IsVisible() const { return m_visible; }

    void SetParent(Widget* parent) { m_parent = parent; }

    Widget* GetParent() const { return m_parent; }

    void SetPosition(const Vector2& position) { m_position = position; }

    bool IsInside(int x, int y) ;


    float GetX()  { return m_position.x; }
    float GetY()  { return m_position.y; }

    float GetRealX() ;
    float GetRealY() ;

    
    void MouseMove(int x, int y);
    void MouseDown(int x, int y, int button);
    void MouseUp(int x, int y, int button);
    void MouseWheel(int delta);
    void KeyDown(Uint32 key);
    void KeyUp(Uint32 key);
    void Update(float delta);

    bool getKey();
    void SetkeyMap(bool use, Uint32 key);


    


protected:
    virtual void OnUpdate(float delta);
    virtual void OnDraw(RenderBatch* batch) = 0;
    virtual void OnMouseMove(int x, int y);
    virtual void OnMouseDown(int x, int y, int button);
    virtual void OnMouseUp(int x, int y, int button);
    virtual void OnMouseWheel(int delta);
    virtual void OnReset();
    virtual void OnKeyDown(Uint32 key);
    virtual void OnKeyUp(Uint32 key);

    GUI* m_gui;
    bool m_visible;
    bool m_focus;
    Widget* m_parent;
    Vector2 m_position;
    Vector2 m_size;
    Rectangle m_bounds;

    bool iskeyMappped;
    Uint32 m_key;
   
private:
    std::vector<Widget*> m_children;
    

};

class Window : public Widget
{
public:
    Window(const std::string& title, float x, float y, float width, float height);
    void SetTitle(const std::string& title) { m_title = title; }
    const std::string& GetTitle() const { return m_title; }

    Slider *CreateSlider(bool vertical, float x, float y, float width, float height, float min, float max, float value);
    Label  *CreateLabel(const std::string& text, float x, float y);
    Button *CreateButton(const std::string& text, float x, float y, float width, float height);
    CheckBox *CreateCheckBox(const std::string& text, bool state, float x, float y, float width, float height);
    RadioButton *CreateRadioButton(const std::string& text, bool state, float x, float y, float width, float height);
    RadioGroup *CreateRadioGroup(float x, float y, float width, float height, bool vertical = false);
    ListBox *CreateListBox(float x, float y, float width, float height);

protected:
    void OnDraw(RenderBatch* batch) override;
    void OnUpdate(float delta) override;

    void OnMouseMove(int x, int y) override;
    void OnMouseDown(int x, int y, int button) override;
    void OnMouseUp(int x, int y, int button) override;

private:
    std::string m_title;
    bool    m_dragging;
    Vector2 m_dragOffset;
    Rectangle m_bounds_bar;
    Rectangle m_bounds_hide;

};

class Label : public Widget
{
        friend class Window;
public:
    Label(const std::string& text, float x, float y);
    void SetText(const std::string& text) { m_text = text; }
    const std::string& GetText() const { return m_text; }

    void SetColor(const Color& color) { m_color = color; m_set_color = true; }

    void SetBackgroundColor(const Color& color) { m_colorBack = color;  }

    void SetDrawBackground(bool draw) { m_draw_background = draw; }


protected:
    void OnDraw(RenderBatch* batch) override;
    
    

private:
    std::string m_text;
    Color m_color;
    Color m_colorBack;

    bool m_draw_background;
    bool m_set_color;

};


class Button : public Widget
{
    friend class Window;
public:
    Button(const std::string& text, float x, float y, float width, float height);
    void SetText(const std::string& text) { m_text = text; }
    const std::string& GetText() const { return m_text; }

    std::function<void()> OnClick;
    std::function<void()> OnDown;

protected:
    void OnDraw(RenderBatch* batch) override;
    void OnUpdate(float delta) override;
    void OnMouseMove(int x, int y) override;
    void OnMouseDown(int x, int y, int button) override;
    void OnMouseUp(int x, int y, int button) override;
    void OnKeyDown(Uint32 key) override;
    void OnKeyUp(Uint32 key) override;
    



private:
    std::string m_text;
    bool    m_hover;
    bool    m_down;
    float text_width;
    float text_height;
    
    Rectangle m_bounds;
};

class CheckBox : public Widget
{
    friend class Window;
public:
    CheckBox(const std::string& text, bool state, float x, float y, float width, float height);

    void SetText(const std::string& text) { m_text = text; }
    const std::string& GetText() const { return m_text; }

    bool GetChecked() const { return m_checked; }

    std::function<void()> OnClick;
    std::function<void()> OnDown;
private:
    void OnDraw(RenderBatch* batch) override;
    void OnUpdate(float delta) override;
    void OnMouseMove(int x, int y) override;
    void OnMouseDown(int x, int y, int button) override;
    void OnMouseUp(int x, int y, int button) override;
    void OnKeyDown(Uint32 key) override;
    void OnKeyUp(Uint32 key) override;

    std::string m_text;
    bool   m_checked;
    bool    m_hover;
    bool    m_down;

};            


class Slider : public Widget
{
    friend class Window;
public:
    Slider(bool vertical ,float x, float y, float width, float height, float min, float max, float value);
    void SetValue(float value) ;
    float GetValue() const { return m_value; }

    std::function<void(float)> OnValueChanged;

 
protected:
    void OnDraw(RenderBatch* batch) override;
    void OnUpdate(float delta) override;
    void OnMouseMove(int x, int y) override;
    void OnMouseDown(int x, int y, int button) override;
    void OnMouseUp(int x, int y, int button) override;
    void OnMouseWheel(int delta) override;

private:
    float m_min;
    float m_max;
    float m_value;
    float m_grow;
    bool    m_vertical;
    bool    m_dragging;
    
    
    Rectangle m_bounds_nob;
    
};


class RadioButton : public Widget
{
    friend class Window;

public:
    RadioButton(const std::string& text, bool state, float x, float y, float width, float height);

    void SetText(const std::string& text) { m_text = text; }
    const std::string& GetText() const { return m_text; }

    bool GetChecked() const { return m_checked; }

    std::function<void()> OnClick;
    std::function<void()> OnDown;

private:

    void OnDraw(RenderBatch* batch) override;
    void OnUpdate(float delta) override;
    void OnMouseMove(int x, int y) override;
    void OnMouseDown(int x, int y, int button) override;
    void OnMouseUp(int x, int y, int button) override;
    void OnKeyDown(Uint32 key) override;
    void OnKeyUp(Uint32 key) override;

    std::string m_text;
    bool    m_checked;
    bool    m_hover;
    bool    m_down;

};


class RadioGroup: public Widget
{
     friend class Window;
public:
    RadioGroup(float x, float y, float width, float height,bool vertical = false);
    ~RadioGroup();

    



    int Add(const std::string& text,bool state=false);

    int GetTotal() const { return m_radios.size(); }

    void SetColumn(int columns) { m_columns = columns; }





private:
    void OnDraw(RenderBatch* batch) override;
    void OnUpdate(float delta) override;
    void OnMouseMove(int x, int y) override;
    void OnMouseDown(int x, int y, int button) override;
    void OnMouseUp(int x, int y, int button) override;
    void OnKeyDown(Uint32 key) override;
    void OnKeyUp(Uint32 key) override;


    struct Radio
    {
      std::string text;
      float x;
      float y;
      Rectangle bound;
      bool checked;
    };
    std::vector<Radio*> m_radios;
    int m_selectedIndex;
    
    float m_item_width;
    float m_item_height;
    int     m_columns;
    bool    m_checked;
    bool    m_hover;
    bool    m_down;
    bool    m_vertical;
    int     m_over_index;

};




class ListBox : public Widget
{
    friend class Window;
public:
    ListBox(float x, float y, float width, float height);
    void AddItem(const std::string& text);
    void RemoveItem(const std::string& text);
    void RemoveItem(int index);
    void Clear();

    int                GetItemCount() const { return m_items.size(); }
    const std::string& GetItem(int index) const { return m_items[index]; }
    int                GetSelectedIndex() const { return m_selectedIndex; }
    const std::string& GetSelectedItem() const { return m_items[m_selectedIndex]; }

    void SetSelectedIndex(int index);
    void SetSelectedItem(const std::string& text);

    std::function<void(int)> OnSelectionChanged;
    std::function<void(int)> OnItemSelected;
    std::function<void()> OnClick;
    std::function<void()> OnDown;


protected:
    void OnDraw(RenderBatch* batch) override;
    void OnUpdate(float delta) override;
    void OnMouseWheel(int delta) override;
    void OnMouseMove(int x, int y) override;
    void OnMouseDown(int x, int y, int button) override;
    void OnMouseUp(int x, int y, int button) override;
    void OnKeyDown(Uint32 key) override;
    void OnKeyUp(Uint32 key) override;

private:
    std::vector<std::string> m_items;
    int m_selectedIndex;
    int m_focusIndex;
    int m_scrollOffset;
    int m_min_scrollOffset;
    int m_max_scrollOffset;
    int m_scroll_size;
    bool m_can_scroll;
    Rectangle m_bounds;
    bool m_down;

 
};
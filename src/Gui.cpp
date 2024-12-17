#include "Gui.h"
#include "Batch.h"
#include "Texture.h"
#include "Font.h"

Skin::Skin()
{
    m_colors[BUTTON_TEXT] = Color(0.1f, 0.1f, 0.1f, 1.0f);
    m_colors[BUTTON_FACE] = Color(0.8f, 0.8f, 0.8f, 1.0f);
    m_colors[BUTTON_DOWN] = Color(0.6f, 0.6f, 0.6f, 1.0f);
    m_colors[SCROLLBAR] = Color(0.3f, 0.3f, 0.3f, 1.0f);
    m_colors[SCROLLBAR_NOB] = Color(0.2f, 0.2f, 0.7f);
    m_colors[SCROLLBAR_FILL] = Color(0.7f, 0.7f, 0.7f, 1.0f);
    m_colors[WINDOW] = Color(0.5f, 0.5f, 0.5f, 1.0f);
    m_colors[WINDOW_TOP_BAR] = Color(0.2f, 0.2f, 0.6f, 1.0f);
    m_colors[WINDOW_TITLE] = Color(1.0f, 1.0f, 1.0f, 1.0f);

    m_colors[LABEL] = Color(1.0f, 1.0f, 1.0f, 1.0f);
    m_colors[LABEL_BACKGROUND] = Color(0.2f, 0.2f, 0.2f, 1.0f);

    m_colors[CHECKBOX_TEXT] = Color(0.1f, 0.1f, 0.1f, 1.0f);
    m_colors[CHECKBOX] = Color(0.8f, 0.8f, 0.8f, 1.0f);
    m_colors[CHECKBOX_DOWN] = Color(0.6f, 0.6f, 0.6f, 1.0f);
    m_colors[CHECKBOX_CHECK] = Color(0.2f, 0.2f, 0.2f, 1.0f);
    m_colors[CHECKBOX_OVER] = Color(0.2f, 0.2f, 0.2f, 1.0f);

    m_colors[RADIO_TEXT] = Color(0.1f, 0.1f, 0.1f, 1.0f);
    m_colors[RADIO] = Color(0.8f, 0.8f, 0.8f, 1.0f);
    m_colors[RADIO_DOWN] = Color(0.6f, 0.6f, 0.6f, 1.0f);
    m_colors[RADIO_CHECK] = Color(0.2f, 0.2f, 0.2f, 1.0f);
    m_colors[RADIO_OVER] = Color(0.2f, 0.2f, 0.2f);

    m_colors[RADIO_GROUP_TEXT] = Color(0.1f, 0.1f, 0.1f, 1.0f);
    m_colors[RADIO_GROUP] = Color(0.8f, 0.8f, 0.8f, 1.0f);
    m_colors[RADIO_GROUP_ITEM] = Color(1.0f, 1.0f, 1.0f, 1.0f);
    m_colors[RADIO_GROUP_DOWN] = Color(0.6f, 0.6f, 0.6f, 1.0f);
    m_colors[RADIO_GROUP_CHECK] = Color(0.2f, 0.2f, 0.2f, 1.0f);
    m_colors[RADIO_GROUP_OVER] = Color(0.2f, 0.2f, 0.2f);
    m_colors[RADIO_GROUP_ITEM_OVER] = Color(0.2f, 0.2f, 0.2f);

    m_colors[LISTBOX_TEXT] = Color(0.1f, 0.1f, 0.1f, 1.0f);
    m_colors[LISTBOX_FACE] = Color(0.2f, 0.2f, 0.2f, 1.0f);
    m_colors[LISTBOX_SELECTED] = Color(0.6f, 0.6f, 0.6f, 1.0f);
    m_colors[LISTBOX_SELECTED_TEXT] = Color(1.0f, 1.0f, 1.0f, 1.0f);
    m_colors[LISTBOX_ITEM_OVER] = Color(0.4f, 0.4f, 0.4f, 1.0f);

    m_colors[TEXTBOX_TEXT] = Color(0.0f, 0.0f, 0.0f, 1.0f);
    m_colors[TEXTBOX_BACKGROUND] = Color(1.0f, 1.0f, 1.0f, 1.0f);
    m_colors[TEXTBOX_BORDER] = Color(0.4f, 0.4f, 0.4f, 1.0f);
    m_colors[TEXTBOX_SELECTION] = Color(0.2f, 0.4f, 0.9f, 0.5f);
    m_colors[TEXTBOX_CURSOR] = Color(0.0f, 0.0f, 0.0f, 1.0f);

    m_colors[PROGRESSBAR_BACKGROUND] = Color(0.8f, 0.8f, 0.8f, 1.0f);
    m_colors[PROGRESSBAR_FILL] = Color(0.2f, 0.7f, 0.2f, 1.0f);
    m_colors[PROGRESSBAR_BORDER] = Color(0.4f, 0.4f, 0.4f, 1.0f);

    m_colors[DROPDOWN_TEXT] = Color(0.0f, 0.0f, 0.0f, 1.0f);
    m_colors[DROPDOWN_BACKGROUND] = Color(1.0f, 1.0f, 1.0f, 1.0f);
    m_colors[DROPDOWN_BORDER] = Color(0.4f, 0.4f, 0.4f, 1.0f);
    m_colors[DROPDOWN_ARROW] = Color(0.2f, 0.2f, 0.2f, 1.0f);
    m_colors[DROPDOWN_ITEM_HOVER] = Color(0.8f, 0.9f, 1.0f, 1.0f);

    m_colors[TOOLTIP_TEXT] = Color(1.0f, 1.0f, 1.0f, 1.0f);
    m_colors[TOOLTIP_BACKGROUND] = Color(0.1f, 0.1f, 0.1f, 0.9f);
    m_colors[TOOLTIP_BORDER] = Color(0.3f, 0.3f, 0.3f, 1.0f);

    m_font = new Font();
}

Skin::~Skin()
{
    delete m_font;
}

GUI::GUI()
{
    m_skin = new Skin();
}

GUI::~GUI()
{
    Clear();
    delete m_skin;
}

void GUI::Clear()
{
    for (unsigned int i = 0; i < m_widgets.size(); i++)
    {
        delete m_widgets[i];
    }
    m_widgets.clear();
}

void GUI::SetSkin(Skin *skin)
{
    if (m_skin != nullptr)
    {
        delete m_skin;
        m_skin = skin;
    }
}

Window *GUI::CreateWindow(const std::string &title, float x, float y, float width, float height)
{
    Window *window = new Window(title, x, y, width, height);
    window->m_gui = this;
    m_widgets.push_back(window);
    return window;
}

void GUI::Update(float delta)
{

    for (unsigned int i = 0; i < m_widgets.size(); i++)
    {
        m_widgets[i]->Update(delta);
    }
}

// Apply scissor/clipping rectangle (Y is inverted in OpenGL)

void GUI::SetScissor(int x, int y, int w, int h)
{
    // Convert scissor coordinates from top-left to bottom-left
    y = m_height - (y + h);

    glScissor(x, y, w, h);
}

void GUI::Render(RenderBatch *batch)
{
    //enbale scissor test

    GLint last_scissor_box[4];
    glGetIntegerv(GL_SCISSOR_BOX, last_scissor_box);

    glEnable(GL_SCISSOR_TEST);

  
    for (unsigned int i = 0; i < m_widgets.size(); i++)
    {
      //  SetScissor((int)m_widgets[i]->GetRealX(), (int)m_widgets[i]->GetRealY(), (int)m_widgets[i]->GetWidth(), (int)m_widgets[i]->GetHeight());
        m_widgets[i]->Render(batch);
    }

    glDisable(GL_SCISSOR_TEST);

    glScissor(last_scissor_box[0], last_scissor_box[1], last_scissor_box[2], last_scissor_box[3]);
}

void GUI::OnMouseMove(int x, int y)
{
    // for (unsigned int i = 0; i < m_widgets.size(); i++)
    // {
    //     m_widgets[i]->MouseMove(x, y);
    // }
    for (Widget *widget : m_widgets)
    {
        if (!widget->IsVisible())
            continue;
        if (widget->m_type == WIDGET_WINDOW)
        {
            Window *window = dynamic_cast<Window *>(widget);
            window->MouseMove(x, y);
            if (window && window->IsResizable())
            {
                int handle;
                if (window->IsOverResizeHandle(x, y, handle))
                {
                    switch (handle)
                    {
                    case 0:
                    case 3: // Top-left, Bottom-right
                        SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_SIZENWSE));
                        break;
                    case 1:
                    case 2: // Top-right, Bottom-left
                        SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_SIZENESW));
                        break;
                    case 4:
                    case 5: // Top, Bottom
                        SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_SIZENS));
                        break;
                    case 6:
                    case 7: // Left, Right
                        SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_SIZEWE));
                        break;
                    }
                    return;
                }
              }
        } else 
        {
            widget->MouseMove(x, y);
        }
    }
    SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW));
}

void GUI::OnMouseDown(int x, int y, int button)
{
    for (unsigned int i = 0; i < m_widgets.size(); i++)
    {

        m_widgets[i]->MouseDown(x, y, button);
    }
}

void GUI::OnMouseUp(int x, int y, int button)
{
    for (unsigned int i = 0; i < m_widgets.size(); i++)
    {

        m_widgets[i]->MouseUp(x, y, button);
        m_widgets[i]->OnReset();
    }
}

void GUI::OnMouseWheel(int delta)
{
    for (unsigned int i = 0; i < m_widgets.size(); i++)
    {
        m_widgets[i]->MouseWheel(delta);
    }
}

void GUI::OnKeyDown(Uint32 key)
{
    for (unsigned int i = 0; i < m_widgets.size(); i++)
    {
        m_widgets[i]->KeyDown(key);
    }
}

void GUI::OnKeyUp(Uint32 key)
{

    for (unsigned int i = 0; i < m_widgets.size(); i++)
    {
        m_widgets[i]->KeyUp(key);
    }
}

Widget::Widget()
{
    m_parent = NULL;
    m_visible = true;
    m_gui = nullptr;
    m_focus = false;
    iskeyMappped = false;
    m_key = 0;
     m_type = WIDGET_BASE;
}

Widget::~Widget()
{
    m_gui = nullptr;
    RemoveAll();
}

void Widget::Render(RenderBatch *batch)
{

    OnDraw(batch);
    if (m_visible)
    {
        for (unsigned int i = 0; i < m_children.size(); i++)
        {
            m_children[i]->Render(batch);
        }
    }
}

void Widget::Add(Widget *widget)
{
    if (widget->GetParent() != nullptr)
        widget->GetParent()->Remove(widget);
    m_children.push_back(widget);
    widget->SetParent(this);
}

void Widget::Remove(Widget *widget)
{
    for (unsigned int i = 0; i < m_children.size(); i++)
    {
        if (m_children[i] == widget)
        {
            m_children.erase(m_children.begin() + i);
            return;
        }
    }
}

void Widget::RemoveAll()
{

    for (unsigned int i = 0; i < m_children.size(); i++)
    {
        if (m_children[i]->GetParent() == this)
            delete m_children[i];
    }

    m_children.clear();
}

bool Widget::IsInside(int x, int y)
{
    return m_bounds.Contains(x, y);
}

float Widget::GetRealX()
{
    if (m_parent == NULL)
        return m_position.x;
    else
        return m_parent->GetRealX() + m_position.x;
}

float Widget::GetRealY()
{
    if (m_parent == NULL)
        return m_position.y;
    else
        return m_parent->GetRealY() + m_position.y;
}

void Widget::Update(float delta)
{
    OnUpdate(delta);
    for (unsigned int i = 0; i < m_children.size(); i++)
    {
        m_children[i]->Update(delta);
    }
}
void Widget::SetkeyMap(bool use, Uint32 key)
{
    iskeyMappped = use;
    m_key = key;
}

void Widget::OnUpdate(float delta)
{
    (void)delta;
}

void Widget::MouseMove(int x, int y)
{
    OnMouseMove(x, y);
    for (unsigned int i = 0; i < m_children.size(); i++)
    {
        m_children[i]->MouseMove(x, y);
    }
}

void Widget::MouseDown(int x, int y, int button)
{
    OnMouseDown(x, y, button);
    for (unsigned int i = 0; i < m_children.size(); i++)
    {
        m_children[i]->MouseDown(x, y, button);
    }
}

void Widget::MouseUp(int x, int y, int button)
{
    OnMouseUp(x, y, button);
    for (unsigned int i = 0; i < m_children.size(); i++)
    {
        m_children[i]->MouseUp(x, y, button);
    }
}

void Widget::MouseWheel(int delta)
{
    OnMouseWheel(delta);
    for (unsigned int i = 0; i < m_children.size(); i++)
    {
        m_children[i]->MouseWheel(delta);
    }
}

void Widget::KeyDown(Uint32 key)
{
    OnKeyDown(key);
    for (unsigned int i = 0; i < m_children.size(); i++)
    {
        m_children[i]->KeyDown(key);
    }
}

void Widget::KeyUp(Uint32 key)
{
    OnKeyUp(key);
    for (unsigned int i = 0; i < m_children.size(); i++)
    {
        m_children[i]->KeyUp(key);
    }
}

void Widget::OnMouseMove(int x, int y)
{
    (void)x;
    (void)y;
}

void Widget::OnMouseDown(int x, int y, int button)
{
    (void)x;
    (void)y;
    (void)button;
}

void Widget::OnMouseUp(int x, int y, int button)
{
    (void)x;
    (void)y;
    (void)button;
}

void Widget::OnMouseWheel(int delta)
{
    (void)delta;
}

void Widget::OnReset()
{
    for (unsigned int i = 0; i < m_children.size(); i++)
    {
        m_children[i]->OnReset();
    }
}

void Widget::OnKeyDown(Uint32 key)
{
    (void)key;
}

void Widget::OnKeyUp(Uint32 key)
{
    (void)key;
}

Window::Window(const std::string &title, float x, float y, float width, float height) : Widget()
{
    m_title = title;
    m_position.x = x;
    m_position.y = y;
    m_size.x = width;
    m_size.y = height;
    m_dragging = false;
    m_dragOffset = Vector2(0.0f, 0.0f);
     m_type = WIDGET_WINDOW;
    m_resizable = true;
    m_resizing = false;
    m_activeHandle = -1;
    m_minSize = Vector2(100, 100);         // tamanho mínimo padrão
    m_maxSize = Vector2(FLT_MAX, FLT_MAX); // sem limite máximo
    UpdateResizeHandles();
}

Window::~Window()
{
   

}

void Window::UpdateResizeHandles()
{
    const float handleSize = 6.0f;
    const float halfHandle = handleSize / 2.0f;
    float x = GetRealX();
    float y = GetRealY();
    float w = m_size.x;
    float h = m_size.y;

    // Cantos
    m_resizeHandles[0] = Rectangle(x - halfHandle, y - halfHandle, handleSize, handleSize);         // Top-left
    m_resizeHandles[1] = Rectangle(x + w - halfHandle, y - halfHandle, handleSize, handleSize);     // Top-right
    m_resizeHandles[2] = Rectangle(x - halfHandle, y + h - halfHandle, handleSize, handleSize);     // Bottom-left
    m_resizeHandles[3] = Rectangle(x + w - halfHandle, y + h - halfHandle, handleSize, handleSize); // Bottom-right

    // Bordas
    m_resizeHandles[4] = Rectangle(x + w / 2 - halfHandle, y - halfHandle, handleSize, handleSize);     // Top
    m_resizeHandles[5] = Rectangle(x + w / 2 - halfHandle, y + h - halfHandle, handleSize, handleSize); // Bottom
    m_resizeHandles[6] = Rectangle(x - halfHandle, y + h / 2 - halfHandle, handleSize, handleSize);     // Left
    m_resizeHandles[7] = Rectangle(x + w - halfHandle, y + h / 2 - halfHandle, handleSize, handleSize); // Right
}

bool Window::IsOverResizeHandle(int x, int y, int &handleIndex)
{
    if (!m_resizable)
        return false;

    for (int i = 0; i < 8; i++)
    {
        if (m_resizeHandles[i].Contains(x, y))
        {
            handleIndex = i;
            return true;
        }
    }
    return false;
}

void Window::OnDraw(RenderBatch *batch)
{
    Skin *skin = m_gui->GetSkin();
    Font *font = skin->GetFont();


//m_gui->SetScissor((int)GetRealX(), (int)GetRealY() - 20, (int)m_size.x, (int)m_size.y);


    // m_gui->SetScissor((int)GetRealX(), (int)GetRealY()-20, (int)m_size.x, (int)m_size.y);

    batch->DrawRectangle((int)GetRealX(), (int)GetRealY() - 20, (int)m_size.x, (int)20, skin->GetColor(WINDOW_TOP_BAR), true);
    if (m_visible)
        batch->DrawRectangle((int)GetRealX(), (int)GetRealY(), (int)m_size.x, (int)m_size.y, skin->GetColor(WINDOW), true);

    if (m_visible)
        batch->DrawCircle((int)GetRealX() + (m_size.x - 10), (int)GetRealY() - 10, 4, Color(0, 1, 0, 0.8), true);
    else
        batch->DrawCircle((int)GetRealX() + (m_size.x - 10), (int)GetRealY() - 10, 4, Color(1, 0, 0, 0.8), true);

    // batch->DrawRectangle(m_bounds_bar, Color(1,0,0),false);
    // batch->DrawRectangle(m_bounds_hide, Color(1,0,0),false);

    font->DrawText(batch, m_title.c_str(), Vector2(GetRealX() + 10, GetRealY() - 17), skin->GetColor(WINDOW_TITLE));

    if (m_resizable && m_visible)
    {
        Color handleColor = m_focus ? Color(0.4f, 0.4f, 0.4f, 1.0f) : Color(0.3f, 0.3f, 0.3f, 1.0f);
        for (const Rectangle &handle : m_resizeHandles)
        {
            batch->DrawRectangle((int)handle.x, (int)handle.y,
                                 (int)handle.width, (int)handle.height,
                                 handleColor, true);
        }
    }


    batch->Render();
}

void Window::OnUpdate(float delta)
{
    (void)delta;
    m_bounds = Rectangle(m_position.x, m_position.y - 20, m_size.x, m_size.y);
    m_bounds_bar = Rectangle(GetRealX(), GetRealY() - 20, m_size.x, 20);
    m_bounds_hide = Rectangle(GetRealX() + m_size.x - 16, GetRealY() - 16, 12, 12);

    if (m_resizable)
    {
        UpdateResizeHandles();
    }
    for (Widget *child : m_children)
        {
            Layout *layout = dynamic_cast<Layout *>(child);
            if (layout)
            {
                layout->m_size.x = m_size.x - 20; 
                layout->m_size.y = m_size.y - 30; 
                layout->UpdateLayout();
            }
        }
}

void Window::OnMouseMove(int x, int y)
{
    m_focus = m_bounds.Contains(x, y);

    if (m_dragging)
    {
        m_position.x = x - m_dragOffset.x;
        m_position.y = y - m_dragOffset.y;
    }
    else if (m_resizing)
    {
        float newWidth = m_size.x;
        float newHeight = m_size.y;
        float newX = m_position.x;
        float newY = m_position.y;

        switch (m_activeHandle)
        {
        case 0: // Top-left
            newWidth = m_size.x - (x - GetRealX());
            newHeight = m_size.y - (y - GetRealY());
            newX = x;
            newY = y;
            break;
        case 1: // Top-right
            newWidth = x - GetRealX();
            newHeight = m_size.y - (y - GetRealY());
            newY = y;
            break;
        case 2: // Bottom-left
            newWidth = m_size.x - (x - GetRealX());
            newHeight = y - GetRealY();
            newX = x;
            break;
        case 3: // Bottom-right
            newWidth = x - GetRealX();
            newHeight = y - GetRealY();
            break;
        case 4: // Top
            newHeight = m_size.y - (y - GetRealY());
            newY = y;
            break;
        case 5: // Bottom
            newHeight = y - GetRealY();
            break;
        case 6: // Left
            newWidth = m_size.x - (x - GetRealX());
            newX = x;
            break;
        case 7: // Right
            newWidth = x - GetRealX();
            break;
        }

        newWidth = std::max(m_minSize.x, std::min(m_maxSize.x, newWidth));
        newHeight = std::max(m_minSize.y, std::min(m_maxSize.y, newHeight));

        m_size.x = newWidth;
        m_size.y = newHeight;
        m_position.x = newX;
        m_position.y = newY;

        for (Widget *child : m_children)
        {
            Layout *layout = dynamic_cast<Layout *>(child);
            if (layout)
            {
                layout->m_size.x = m_size.x - 20; 
                layout->m_size.y = m_size.y - 30; 
                layout->UpdateLayout();
            }
        }
    }
}

void Window::OnMouseDown(int x, int y, int button)
{
    if (button == 1)
    {
        if (m_bounds_bar.Contains(x, y))
        {
            m_dragging = true;
            m_dragOffset.x = x - GetRealX();
            m_dragOffset.y = y - GetRealY();
        }
        else if (m_resizable)
        {
            int handle;
            if (IsOverResizeHandle(x, y, handle))
            {
                m_resizing = true;
                m_activeHandle = handle;
            }
        }
    }
}

void Window::OnMouseUp(int x, int y, int button)
{
    if (m_bounds_hide.Contains(x, y) && button == 1)
    {
        m_visible = !m_visible;
    }
    m_dragging = false;
    m_resizing = false;
    m_activeHandle = -1;
}

Slider *Window::CreateSlider(bool vertical, float x, float y, float width, float height, float min, float max, float value)
{
    Slider *slider = new Slider(vertical, x, y, width, height, min, max, value);
    slider->m_gui = this->m_gui;
    Add(slider);
    return slider;
}

Label *Window::CreateLabel(const std::string &text, float x, float y)
{

    Label *label = new Label(text, x, y);
    label->m_gui = this->m_gui;
    Add(label);
    return label;
}

Button *Window::CreateButton(const std::string &text, float x, float y, float width, float height)
{

    Button *button = new Button(text, x, y, width, height);
    button->m_gui = this->m_gui;
    Add(button);
    return button;
}

CheckBox *Window::CreateCheckBox(const std::string &text, bool state, float x, float y, float width, float height)
{

    CheckBox *checkbox = new CheckBox(text, state, x, y, width, height);
    checkbox->m_gui = this->m_gui;
    Add(checkbox);
    return checkbox;
}

RadioButton *Window::CreateRadioButton(const std::string &text, bool state, float x, float y, float width, float height)
{

    RadioButton *radiobutton = new RadioButton(text, state, x, y, width, height);
    radiobutton->m_gui = this->m_gui;
    Add(radiobutton);
    return radiobutton;
}

RadioGroup *Window::CreateRadioGroup(float x, float y, float width, float height, bool vertical)
{
    RadioGroup *radiogroup = new RadioGroup(x, y, width, height, vertical);
    radiogroup->m_gui = this->m_gui;
    Add(radiogroup);
    return radiogroup;
}

ListBox *Window::CreateListBox(float x, float y, float width, float height)
{
    ListBox *listbox = new ListBox(x, y, width, height);
    listbox->m_gui = this->m_gui;
    Add(listbox);
    return listbox;
}

TextBox *Window::CreateTextBox(float x, float y, float width, float height)
{
    TextBox *textbox = new TextBox(x, y, width, height);
    textbox->m_gui = this->m_gui;
    Add(textbox);
    return textbox;
}

VBox* Window::CreateVBox(float x, float y, float width, float height)
{
    VBox* vbox = new VBox(x, y, width, height);
    vbox->m_gui = this->m_gui;
    Add(vbox);
    return vbox;
}

HBox* Window::CreateHBox(float x, float y, float width, float height)
{
    HBox* hbox = new HBox(x, y, width, height);
    hbox->m_gui = this->m_gui;
    Add(hbox);
    return hbox;
}

ProgressBar* Window::CreateProgressBar(float x, float y, float width, float height)
{
    ProgressBar* progressbar = new ProgressBar(x, y, width, height);
    progressbar->m_gui = this->m_gui;
    Add(progressbar);
    return progressbar;
}

DropDown* Window::CreateDropDown(float x, float y, float width, float height)
{
    DropDown* dropdown = new DropDown(x, y, width, height);
    dropdown->m_gui = this->m_gui;
    Add(dropdown);
    return dropdown;
}

Tooltip* Window::CreateTooltip(const std::string& text)
{
    Tooltip* tooltip = new Tooltip(text);
    tooltip->m_gui = this->m_gui;
    Add(tooltip);
    return tooltip;
}

Slider::Slider(bool vertical, float x, float y, float width, float height, float min, float max, float value) : Widget()
{
    m_vertical = vertical;
    m_position.x = x;
    m_position.y = y;
    m_size.x = width;
    m_size.y = height;
    m_min = min;
    m_max = max;
    m_value = value;
    m_dragging = false;
    m_grow = 0;
     m_type = WIDGET_SLIDER;
}

void Slider::SetValue(float value)
{
    m_value = value;
    if (OnValueChanged)
        OnValueChanged(m_value);
}

void Slider::OnDraw(RenderBatch *batch)
{
    Skin *skin = m_gui->GetSkin();
    Font *font = skin->GetFont();

    batch->DrawRectangle((int)GetRealX(), (int)GetRealY(), (int)m_size.x, (int)m_size.y, skin->GetColor(SCROLLBAR), true);
    if (m_vertical)
    {

        batch->DrawRectangle((int)GetRealX(), (int)GetRealY(), (int)m_size.x, (int)m_grow, skin->GetColor(SCROLLBAR_FILL), true);
        batch->DrawRectangle((int)GetRealX(), (int)GetRealY() + (int)m_grow, (int)m_size.x, 5, skin->GetColor(SCROLLBAR_NOB), true);
        font->DrawText(batch, m_bounds.x + m_bounds.width, m_bounds.y + (m_bounds.height / 2), false, true, Color(1, 1, 1), "%03.f", m_value);
    }
    else
    {
        batch->DrawRectangle((int)GetRealX(), (int)GetRealY(), (int)m_grow, (int)m_size.y, skin->GetColor(SCROLLBAR_FILL), true);
        batch->DrawRectangle((int)GetRealX() + (int)m_grow, (int)GetRealY(), 5, (int)m_size.y, skin->GetColor(SCROLLBAR_NOB), true);
        font->DrawText(batch, m_bounds.x + m_bounds.width, m_bounds.y + (m_bounds.height / 2), false, true, Color(1, 1, 1), "%03.f", m_value);
    }
    if (m_focus)
    {
        batch->DrawRectangle((int)GetRealX(), (int)GetRealY(), (int)m_size.x, (int)m_size.y, Color(0.2f, 0.2f, 0.2f), false);
    }
}

void Slider::OnUpdate(float delta)
{
    (void)delta;
    m_bounds = Rectangle(GetRealX(), GetRealY(), m_size.x + 1, m_size.y + 1);

    if (m_vertical)
    {
        m_grow = (m_value - m_min) / (m_max - m_min) * m_size.y;
    }
    else
    {
        m_grow = (m_value - m_min) / (m_max - m_min) * m_size.x;
    }
}

void Slider::OnMouseMove(int x, int y)
{

    m_focus = m_bounds.Contains(x, y);

    if (m_dragging)
    {
        if (m_vertical)
        {
            if (m_bounds.Contains(x, y))
            {
                float pos = y - GetRealY();
                m_value = m_min + (m_max - m_min) * (pos) / m_size.y;
            }
        }
        else
        {

            if (m_bounds.Contains(x, y))
            {
                float pos = x - GetRealX();
                m_value = m_min + (m_max - m_min) * (pos) / m_size.x;
            }
        }
        if (OnValueChanged)
            OnValueChanged(m_value);
    }
}

void Slider::OnMouseDown(int x, int y, int button)
{
    if (button == 1 )
    {
        m_dragging = true;
        if (m_vertical)
        {
            if (m_bounds.Contains(x, y))
            {
                float pos = y - GetRealY();
                m_value = m_min + (m_max - m_min) * (pos) / m_size.y;
            }
        }
        else
        {

            if (m_bounds.Contains(x, y))
            {
                float pos = x - GetRealX();
                m_value = m_min + (m_max - m_min) * (pos) / m_size.x;
            }
        }
        if (OnValueChanged)
            OnValueChanged(m_value);
    }
}

void Slider::OnMouseUp(int x, int y, int button)
{
    (void)x;
    (void)y;
    (void)button;

    m_dragging = false;
}

void Slider::OnMouseWheel(int delta)
{
    if (!m_focus)
        return;
    m_value += delta;
    if (m_value < m_min)
        m_value = m_min;
    if (m_value > m_max)
        m_value = m_max;
}

Label::Label(const std::string &text, float x, float y) : Widget()
{
    m_text = text;
    m_position.x = x;
    m_position.y = y;
    m_color = Color::WHITE;
    m_set_color = false;
    m_draw_background = false;
     m_type = WIDGET_LABEL;
}

void Label::OnDraw(RenderBatch *batch)
{
    Skin *skin = m_gui->GetSkin();
    Font *font = skin->GetFont();
    float w = font->GetWidth(m_text.c_str());
    float h = font->GetHeight();
    m_bounds = Rectangle(GetRealX(), GetRealY(), w + 1, h + 1);
    if (!m_set_color)
    {
        m_color = skin->GetColor(LABEL);
        m_set_color = true;
    }
    if (m_draw_background)
    {
        batch->DrawRectangle((int)GetRealX(), (int)GetRealY(), (int)w, (int)h, skin->GetColor(LABEL_BACKGROUND), true);
    }

    font->DrawText(batch, m_text.c_str(), Vector2(GetRealX(), GetRealY()), m_color);
}

Button::Button(const std::string &text, float x, float y, float width, float height) : Widget()
{
    m_text = text;
    m_position.x = x;
    m_position.y = y;
    m_size.x = width;
    m_size.y = height;
    m_down = false;
    m_focus = false;
    m_hover = false;
    m_type = WIDGET_BUTTON;
    text_width = 0;
    text_height = 0;
}

void Button::OnDraw(RenderBatch *batch)
{
    Skin *skin = m_gui->GetSkin();
    Font *font = skin->GetFont();

    if (m_down)
        batch->DrawRectangle((int)GetRealX(), (int)GetRealY(), (int)m_size.x, (int)m_size.y, skin->GetColor(BUTTON_DOWN), true);
    else
        batch->DrawRectangle((int)GetRealX(), (int)GetRealY(), (int)m_size.x, (int)m_size.y, skin->GetColor(BUTTON_FACE), true);
    if (m_hover)
        batch->DrawRectangle((int)GetRealX(), (int)GetRealY(), (int)m_size.x, (int)m_size.y, Color(0.2f, 0.2f, 0.2f), false);

    int w = font->GetWidth(m_text.c_str());
    float h = font->GetHeight();

    // Log(2, "w %f h %f", w, h);

    font->DrawText(batch, m_text.c_str(), Vector2(GetRealX() + (m_size.x / 2) - (w / 2), GetRealY() + (m_size.y / 2) - (h / 2)), skin->GetColor(BUTTON_TEXT));
}

void Button::OnUpdate(float delta)
{
    (void)delta;
    if (text_width == 0 || text_height == 0)
    {
        Skin *skin = m_gui->GetSkin();
        Font *font = skin->GetFont();
        text_width = font->GetWidth(m_text.c_str());
        text_height = font->GetHeight();
    }

    m_bounds = Rectangle(GetRealX(), GetRealY(), m_size.x + 1, m_size.y + 1);
}

void Button::OnMouseMove(int x, int y)
{
    m_focus = m_bounds.Contains(x, y);
    m_hover = m_focus;
}

void Button::OnMouseDown(int x, int y, int button)
{
    if (button == 1)
        if (m_bounds.Contains(x, y))
        {
            m_down = true;
        }
}

void Button::OnMouseUp(int x, int y, int button)
{
    if (button == 1)
        if (m_bounds.Contains(x, y))
        {
            m_down = false;
            if (OnClick)
                OnClick();
        }
}

void Button::OnKeyDown(Uint32 key)
{
    if (iskeyMappped && m_gui != nullptr)
        if (key == m_key && !m_down)
        {
            m_down = true;
            if (OnDown)
                OnDown();
        }
}

void Button::OnKeyUp(Uint32 key)
{
    if (iskeyMappped && m_gui != nullptr)
        if (key == m_key && m_down)
        {
            m_down = false;
            if (OnClick)
                OnClick();
        }
}

CheckBox::CheckBox(const std::string &text, bool state, float x, float y, float width, float height) : Widget()
{
    m_text = text;
    m_position.x = x;
    m_position.y = y;
    m_size.x = width;
    m_size.y = height;
    m_checked = state;
    m_down = false;
    m_focus = false;
    m_hover = false;
    m_type = WIDGET_CHECKBOX;
}

void CheckBox::OnDraw(RenderBatch *batch)
{
    Skin *skin = m_gui->GetSkin();
    Font *font = skin->GetFont();

    batch->DrawRectangle((int)GetRealX(), (int)GetRealY(), (int)m_size.x, (int)m_size.y, skin->GetColor(CHECKBOX), true);
    if (m_hover)
        batch->DrawRectangle((int)GetRealX(), (int)GetRealY(), (int)m_size.x, (int)m_size.y, skin->GetColor(CHECKBOX_OVER), false);

    if (m_checked)
    {
        batch->DrawRectangle((int)GetRealX() + 4, (int)GetRealY() + 4, m_size.x - 8, m_size.y - 8, skin->GetColor(CHECKBOX_CHECK), true);
    }
    float h = font->GetHeight();
    font->DrawText(batch, m_text.c_str(), Vector2(GetRealX() + (m_size.x + 1), GetRealY() + (m_size.y / 2) - (h / 2)), skin->GetColor(CHECKBOX_TEXT));
}

void CheckBox::OnUpdate(float delta)
{
    (void)delta;

    m_bounds = Rectangle(GetRealX(), GetRealY(), m_size.x + 1, m_size.y + 1);
}

void CheckBox::OnMouseMove(int x, int y)
{
    m_focus = m_bounds.Contains(x, y);
    m_hover = m_focus;
}

void CheckBox::OnMouseDown(int x, int y, int button)
{
    if (button == 1)
        if (m_bounds.Contains(x, y))
        {
            m_down = true;
        }
}

void CheckBox::OnMouseUp(int x, int y, int button)
{
    if (button == 1)
        if (m_bounds.Contains(x, y))
        {
            m_checked = !m_checked;
            m_down = false;
            if (OnClick)
                OnClick();
        }
}

void CheckBox::OnKeyDown(Uint32 key)
{
    if (iskeyMappped && m_gui != nullptr)
        if (key == m_key && !m_down)
        {
            m_down = true;
            if (OnDown)
                OnDown();
        }
}

void CheckBox::OnKeyUp(Uint32 key)
{
    if (iskeyMappped && m_gui != nullptr)
        if (key == m_key && m_down)
        {
            m_down = false;
            if (OnClick)
                OnClick();
        }
}

ListBox::ListBox(float x, float y, float width, float height) : Widget()
{
    m_position.x = x;
    m_position.y = y;
    m_size.x = width;
    m_size.y = height;
    m_type = WIDGET_LISTBOX;
    m_scrollOffset = 12;
    m_selectedIndex = -1;
    m_scroll_size = 12;
    m_focusIndex = -1;
}

void ListBox::AddItem(const std::string &text)
{
    m_items.push_back(text);
}

void ListBox::RemoveItem(int index)
{
    m_items.erase(m_items.begin() + index);
}

void ListBox::RemoveItem(const std::string &text)
{
    for (unsigned int i = 0; i < m_items.size(); i++)
    {
        if (m_items[i] == text)
        {
            m_items.erase(m_items.begin() + i);
            return;
        }
    }
}

void ListBox::Clear()
{
    m_items.clear();
}

void ListBox::OnDraw(RenderBatch *batch)
{
    Skin *skin = m_gui->GetSkin();
    Font *font = skin->GetFont();

    batch->DrawRectangle((int)GetRealX(), (int)GetRealY(), (int)m_size.x, (int)m_size.y, skin->GetColor(BUTTON_FACE), true);
    batch->DrawRectangle((int)GetRealX(), (int)GetRealY(), (int)m_size.x, (int)m_size.y, Color(0.2f, 0.2f, 0.2f), false);

    float h = font->GetHeight();
    int y = -(m_scrollOffset) + GetRealY() + h;
    int x = GetRealX() + 2;
    m_scroll_size = h;

    // float max_height  =   (m_size.y / h) ;

    m_can_scroll = m_items.size() * h > m_size.y;
    m_min_scrollOffset = h;

    if (!m_can_scroll)
    {
        m_max_scrollOffset = h;
    }
    else
    {
        m_max_scrollOffset = m_items.size() * h - m_size.y;
    }

    for (unsigned int i = 0; i < m_items.size(); i++)
    {
        if (y + h > GetRealY() + m_size.y)
            break;
        if (y < GetRealY())
        {
            y += h;
            continue;
        }

        if ((int)i == m_selectedIndex)
        {
            batch->DrawRectangle((int)GetRealX(), (int)y, (int)m_size.x, (int)h, skin->GetColor(LISTBOX_FACE), true);
            font->DrawText(batch, m_items[i].c_str(), Vector2(x, y), skin->GetColor(LISTBOX_SELECTED_TEXT));
        }
        else
        {
            font->DrawText(batch, m_items[i].c_str(), Vector2(x, y), skin->GetColor(LISTBOX_TEXT));
        }

        if (m_focusIndex == (int)i)
        {
            batch->DrawRectangle((int)GetRealX(), (int)y, (int)m_size.x, (int)h, skin->GetColor(LISTBOX_ITEM_OVER), false);
        }

        y += h;
    }
}

void ListBox::OnUpdate(float delta)
{
    (void)delta;
    m_bounds = Rectangle(GetRealX(), GetRealY(), m_size.x + 1, m_size.y + 1);
}

void ListBox::OnMouseWheel(int delta)
{
    if (!m_focus)
        return;
    m_scrollOffset += delta;
    if (m_scrollOffset < m_min_scrollOffset)
        m_scrollOffset = m_min_scrollOffset;
    if (m_scrollOffset > m_max_scrollOffset)
        m_scrollOffset = m_max_scrollOffset;
}

void ListBox::OnMouseMove(int mx, int my)
{
    m_focus = m_bounds.Contains(mx, my);

    if (m_bounds.Contains(mx, my))
    {
        m_down = true;
        int h = m_gui->GetSkin()->GetFont()->GetHeight();
        int y = -(m_scrollOffset) + GetRealY() + h;

        for (unsigned int i = 0; i < m_items.size(); i++)
        {
            if (y + h > GetRealY() + m_size.y)
                break;
            Rectangle item_bounds((int)GetRealX(), y, m_size.x, h);
            if (item_bounds.Contains(mx, my))
            {
                m_focusIndex = i;
                break;
            }
            y += h;
        }
    }
}

void ListBox::OnMouseDown(int mx, int my, int button)
{
    if (button == 1)
        if (m_bounds.Contains(mx, my))
        {
            m_down = true;
            int h = m_gui->GetSkin()->GetFont()->GetHeight();
            int y = -(m_scrollOffset) + GetRealY() + h;

            for (unsigned int i = 0; i < m_items.size(); i++)
            {

                if (y + h > GetRealY() + m_size.y)
                    break;

                Rectangle item_bounds((int)GetRealX(), y, m_size.x, h);

                if (item_bounds.Contains(mx, my))
                {
                    m_selectedIndex = i;

                    if (OnItemSelected)
                        OnItemSelected(m_selectedIndex);
                    break;
                }

                y += h;
            }
        }
}

void ListBox::OnMouseUp(int x, int y, int button)
{
    if (button == 1)
        if (m_bounds.Contains(x, y))
        {
            m_down = false;
        }
}

void ListBox::OnKeyDown(Uint32 key)
{
    if (iskeyMappped && m_gui != nullptr)
        if (key == m_key && !m_down)
        {
            m_down = true;
            if (OnDown)
                OnDown();
        }

    if (m_can_scroll)
    {

        if (key == SDLK_UP)
        {
            m_scrollOffset -= m_scroll_size;
            if (m_scrollOffset < m_min_scrollOffset)
                m_scrollOffset = m_min_scrollOffset;
        }

        if (key == SDLK_DOWN)
        {

            m_scrollOffset += m_scroll_size;
            if (m_scrollOffset > m_max_scrollOffset)
                m_scrollOffset = m_max_scrollOffset;
        }
    }

    Log(0, "m_scrollOffset %d", m_scrollOffset);
}

void ListBox::OnKeyUp(Uint32 key)
{
    if (iskeyMappped && m_gui != nullptr)
        if (key == m_key && m_down)
        {
            m_down = false;
            if (OnClick)
                OnClick();
        }
}

RadioButton::RadioButton(const std::string &text, bool state, float x, float y, float width, float height) : Widget()
{
    m_text = text;
    m_position.x = x;
    m_position.y = y;
    m_size.x = width;
    m_size.y = height;
    m_checked = state;
    m_down = false;
    m_focus = false;
    m_hover = false;
     m_type = WIDGET_RADIOBUTTON;
}

void RadioButton::OnDraw(RenderBatch *batch)
{
    Skin *skin = m_gui->GetSkin();
    Font *font = skin->GetFont();

    batch->DrawRectangle((int)GetRealX(), (int)GetRealY(), (int)m_size.x, (int)m_size.y, skin->GetColor(RADIO), true);
    if (m_hover)
        batch->DrawRectangle((int)GetRealX(), (int)GetRealY(), (int)m_size.x, (int)m_size.y, skin->GetColor(RADIO_OVER), false);

    if (m_checked)
    {
        batch->DrawCircle((int)GetRealX() + (m_size.x / 2), (int)GetRealY() + (m_size.y / 2), 4, skin->GetColor(RADIO_CHECK), true);
    }

    float h = font->GetHeight();

    font->DrawText(batch, m_text.c_str(), Vector2(GetRealX() + (m_size.x + 1), GetRealY() + (m_size.y / 2) - (h / 2)), skin->GetColor(RADIO_TEXT));
}

void RadioButton::OnUpdate(float delta)
{
    (void)delta;
    m_bounds = Rectangle(GetRealX(), GetRealY(), m_size.x + 1, m_size.y + 1);
}

void RadioButton::OnMouseMove(int x, int y)
{
    m_focus = m_bounds.Contains(x, y);
    m_hover = m_focus;
}

void RadioButton::OnMouseDown(int x, int y, int button)
{
    if (button == 1)
        if (m_bounds.Contains(x, y))
        {
            m_down = true;
        }
}

void RadioButton::OnMouseUp(int x, int y, int button)
{
    if (button == 1)
        if (m_bounds.Contains(x, y))
        {
            m_checked = !m_checked;
            m_down = false;
            if (OnClick)
                OnClick();
        }
}

void RadioButton::OnKeyDown(Uint32 key)
{
    if (iskeyMappped && m_gui != nullptr)
        if (key == m_key && !m_down)
        {
            m_down = true;
            if (OnDown)
                OnDown();
        }
}

void RadioButton::OnKeyUp(Uint32 key)
{
    if (iskeyMappped && m_gui != nullptr)
        if (key == m_key && m_down)
        {
            m_down = false;
            if (OnClick)
                OnClick();
        }
}

RadioGroup::RadioGroup(float x, float y, float width, float height, bool vertical) : Widget()
{
    m_position.x = x;
    m_position.y = y;
    m_size.x = width;
    m_size.y = height;
    m_vertical = vertical;
    m_selectedIndex = -1;
    m_hover = false;
    m_focus = false;
    m_item_width = 20;
    m_item_height = 20;
    m_over_index = -1;
    m_columns = 2;
    m_type = WIDGET_RADIOGROUP;
}

RadioGroup::~RadioGroup()
{
    for (unsigned int i = 0; i < m_radios.size(); i++)
    {
        delete m_radios[i];
    }
    m_radios.clear();
}

int RadioGroup::Add(const std::string &text, bool state)
{
    Radio *radio = new Radio();
    radio->text = text;
    radio->checked = state;
    if (state)
        for (unsigned int i = 0; i < m_radios.size(); i++)
        {
            m_radios[i]->checked = false;
        }

    m_radios.push_back(radio);
    return m_radios.size() - 1;
}

void RadioGroup::OnDraw(RenderBatch *batch)
{

    Skin *skin = m_gui->GetSkin();
    Font *font = skin->GetFont();

    batch->DrawRectangle((int)GetRealX(), (int)GetRealY(), (int)m_size.x, (int)m_size.y, skin->GetColor(RADIO_GROUP), true);
    if (m_hover)
        batch->DrawRectangle((int)GetRealX(), (int)GetRealY(), (int)m_size.x, (int)m_size.y, skin->GetColor(RADIO_GROUP_OVER), false);

    int h = font->GetHeight() * 0.5f;

    int count = m_radios.size();

    if (m_vertical)
    {
        m_item_height = (m_size.y / count);
        m_item_width = m_size.x;
        // float ratio = ((float)m_size.y+(m_item_height * 0.5f)) / (float)count -2;
        float offSetY = 0;
        for (int i = 0; i < count; i++)
        {
            Radio *radio = m_radios[i];
            radio->x = 12 + GetRealX();

            float b_y = GetRealY() + offSetY;

            radio->y = (m_item_height * 0.5f) + b_y; // 3 + (m_item_height/2) +  GetRealY() + (i * ratio);

            bool ischecked = radio->checked;

            // radio->bound.set(GetRealX(), radio->y-(m_item_height*0.5f)-3, m_size.x, m_item_height+6);

            radio->bound.set(GetRealX(), b_y, m_size.x, m_item_height);

            batch->DrawCircle((int)radio->x, (int)radio->y, 7, skin->GetColor(RADIO_GROUP_ITEM), true);
            if (ischecked)
                batch->DrawCircle((int)radio->x, (int)radio->y, 4, skin->GetColor(RADIO_CHECK), true);

            font->DrawText(batch, radio->text.c_str(), radio->x + 12, radio->y - h, skin->GetColor(RADIO_GROUP_TEXT));
            if (m_over_index == i)
                batch->DrawRectangle(radio->bound.x, radio->bound.y, radio->bound.width, radio->bound.height, skin->GetColor(RADIO_GROUP_ITEM_OVER), false);

            offSetY += m_item_height;
        }
    }
    else
    {

        int colunas = static_cast<int>(std::ceil(static_cast<float>(count) / m_columns));

        m_item_width = (m_size.x / m_columns);
        m_item_height = (m_size.y / colunas);

        // Log(1, "m_columns %d colunas %d", m_columns , colunas);
        float offSetX = 0;
        float offSetY = 0;

        for (int i = 0; i < count; i++)
        {
            Radio *radio = m_radios[i];

            if (i % m_columns == 0)
            {
                offSetX = 0;
            }
            else
            {
                offSetX += m_item_width;
            }

            if (i % colunas == 0)
            {
                offSetY = 0;
            }
            else
            {
                offSetY += m_item_height;
            }

            radio->x = GetRealX() + offSetX + 12;
            radio->y = GetRealY() + offSetY + (m_item_height / 2);

            float b_x = GetRealX() + offSetX;
            float b_y = GetRealY() + offSetY;

            bool ischecked = radio->checked;

            radio->bound.set(b_x, b_y, m_item_width, m_item_height);

            batch->DrawCircle((int)radio->x, (int)radio->y, 7, skin->GetColor(RADIO_GROUP_ITEM), true);
            if (ischecked)
                batch->DrawCircle((int)radio->x, (int)radio->y, 4, skin->GetColor(RADIO_CHECK), true);

            //  batch->DrawRectangle(radio->bound.x,radio->bound.y, radio->bound.width, radio->bound.height, Color::RED,false);

            font->DrawText(batch, radio->text.c_str(), radio->x + 12, radio->y - h, skin->GetColor(RADIO_GROUP_TEXT));

            if (m_over_index == i)
                batch->DrawRectangle(radio->bound.x, radio->bound.y, radio->bound.width, radio->bound.height, skin->GetColor(RADIO_GROUP_ITEM_OVER), false);
        }
    }
}

void RadioGroup::OnUpdate(float delta)
{
    (void)delta;
    m_bounds = Rectangle(GetRealX(), GetRealY(), m_size.x + 1, m_size.y + 1);
}

void RadioGroup::OnMouseMove(int x, int y)
{
    m_focus = m_bounds.Contains(x, y);
    m_hover = m_focus;

    if (m_focus)
    {
        for (unsigned int i = 0; i < m_radios.size(); i++)
        {
            Radio *radio = m_radios[i];
            if (radio->bound.Contains(x, y))
            {
                m_over_index = i;
                break;
            }
        }
    }
}

void RadioGroup::OnMouseDown(int x, int y, int button)
{
    if (button == 1)
        if (m_bounds.Contains(x, y))
        {
            int lastSelect = -1;
            for (unsigned int i = 0; i < m_radios.size(); i++)
            {
                Radio *radio = m_radios[i];
                if (radio->bound.Contains(x, y))
                {
                    radio->checked = true;
                    lastSelect = i;
                    break;
                }
            }

            if (lastSelect != -1)
            {
                for (unsigned int i = 0; i < m_radios.size(); i++)
                {
                    if (i != (unsigned int)lastSelect)
                    {
                        m_radios[i]->checked = false;
                    }
                }
            }
        }
}

void RadioGroup::OnMouseUp(int x, int y, int button)
{
    (void)x;
    (void)y;
    (void)button;
}

void RadioGroup::OnKeyDown(Uint32 key)
{
    (void)key;
}

void RadioGroup::OnKeyUp(Uint32 key)
{
    (void)key;
}

// TextBox Implementation
TextBox::TextBox(float x, float y, float width, float height) : Widget()
{
    m_position.x = x;
    m_position.y = y;
    m_size.x = width;
    m_size.y = height;
    m_maxLength = 256;
    m_passwordMode = false;
    m_selected = false;
    m_cursorTimer = 0;
    m_cursorPos = 0;
    m_type = WIDGET_TEXTBOX;
}

void TextBox::OnDraw(RenderBatch *batch)
{
    Skin *skin = m_gui->GetSkin();
    Font *font = skin->GetFont();

    // Background
    batch->DrawRectangle((int)GetRealX(), (int)GetRealY(),
                         (int)m_size.x, (int)m_size.y,
                         skin->GetColor(TEXTBOX_BACKGROUND), true);

    // Border
    Color borderColor = m_selected ? skin->GetColor(TEXTBOX_BORDER) : Color(0.5f, 0.5f, 0.5f, 1.0f);
    batch->DrawRectangle((int)GetRealX(), (int)GetRealY(),
                         (int)m_size.x, (int)m_size.y,
                         borderColor, false);

    // Text
    std::string displayText = m_passwordMode ? std::string(m_text.length(), '*') : m_text;

    float textY = GetRealY() + (m_size.y - font->GetHeight()) / 2;
    font->DrawText(batch, displayText.c_str(),
                   Vector2(GetRealX() + 5, textY),
                   skin->GetColor(TEXTBOX_TEXT));

    // Cursor
    // int count = (int)displayText.length();
    if (m_selected)
    {
        // float cursorX =( GetRealX()  + font->GetWidth(displayText.substr(0, m_cursorPos).c_str())) * font->MaxWidth();
        float cursorX = (GetRealX() + m_cursorPos) * 5;

        if ((int)(m_cursorTimer * 2) % 2 == 0)
        {
            // float cursorX = GetRealX() +( m_cursorPos   * font->MaxWidth());
            batch->DrawRectangle((int)cursorX, (int)GetRealY() + 4, 1, (int)m_size.y - 8, skin->GetColor(TEXTBOX_CURSOR), true);
        }
    }
}

void TextBox::OnMouseMove(int x, int y)
{
    m_focus = m_bounds.Contains(x, y);
    if (!m_focus && m_selected)
    {
        m_selected = false;
    }
}

void TextBox::OnUpdate(float delta)
{
    m_cursorTimer += delta;
    m_bounds = Rectangle(GetRealX(), GetRealY(), m_size.x + 1, m_size.y + 1);
}

void TextBox::OnMouseDown(int x, int y, int button)
{
    if (m_bounds.Contains(x, y))
    {
        m_selected = true;
    }
}

void TextBox::OnMouseUp(int x, int y, int button)
{
    (void)x;
    (void)y;
    (void)button;
}

void TextBox::OnKeyDown(Uint32 key)
{
    if (!m_selected)
        return;

    std::string oldText = m_text;

    switch (key)
    {
    case SDLK_BACKSPACE:
        if (!m_text.empty() && m_cursorPos > 0)
        {
            m_text.erase(m_cursorPos - 1, 1);
            m_cursorPos--;
        }
        break;

    case SDLK_DELETE:
        if (!m_text.empty() && m_cursorPos < (int)m_text.length())
        {
            m_text.erase(m_cursorPos, 1);
        }
        break;

    case SDLK_LEFT:
        if (m_cursorPos > 0)
            m_cursorPos--;
        break;

    case SDLK_RIGHT:
        if (m_cursorPos < (int)m_text.length())
            m_cursorPos++;
        break;

    case SDLK_HOME:
        m_cursorPos = 0;
        break;

    case SDLK_END:
        m_cursorPos = m_text.length();
        break;

    default:
        if (key >= 32 && key <= 126) // ASCII printable characters
        {
            if (m_text.length() < m_maxLength)
            {
                m_text.insert(m_cursorPos, 1, (char)key);
                m_cursorPos++;
            }
        }
        break;
    }

    if (oldText != m_text && OnTextChanged)
    {
        OnTextChanged(m_text);
    }
}

void TextBox::OnKeyUp(Uint32 key)
{
    (void)key;
}


ProgressBar::ProgressBar(float x, float y, float width, float height) : Widget()
{
    m_position.x = x;
    m_position.y = y;
    m_size.x = width;
    m_size.y = height;
    m_progress = 0.0f;
    m_showText = true;
}

void ProgressBar::OnDraw(RenderBatch* batch)
{
    Skin* skin = m_gui->GetSkin();
    Font* font = skin->GetFont();

    // Background
    batch->DrawRectangle((int)GetRealX(), (int)GetRealY(),
                        (int)m_size.x, (int)m_size.y,
                        skin->GetColor(PROGRESSBAR_BACKGROUND), true);

    // Progress fill
    float fillWidth = m_size.x * m_progress;
    if (fillWidth > 0)
    {
        batch->DrawRectangle((int)GetRealX(), (int)GetRealY(),
                            (int)fillWidth, (int)m_size.y,
                            skin->GetColor(PROGRESSBAR_FILL), true);
    }

    // Border
    batch->DrawRectangle((int)GetRealX(), (int)GetRealY(),
                        (int)m_size.x, (int)m_size.y,
                        skin->GetColor(PROGRESSBAR_BORDER), false);

    if (m_showText)
    {
        char text[32];
        snprintf(text, sizeof(text), "%.0f%%", m_progress * 100);

        float textWidth = font->GetWidth(text);
        float textX = GetRealX() + (m_size.x - textWidth) / 2;
        float textY = GetRealY() + (m_size.y - font->GetHeight()) / 2;

        font->DrawText(batch, text, Vector2(textX, textY), Color::WHITE);
    }
}

DropDown::DropDown(float x, float y, float width, float height) : Widget()
{
    m_position.x = x;
    m_position.y = y;
    m_size.x = width;
    m_size.y = height;
    m_selectedIndex = -1;
    m_isOpen = false;
    m_hoverIndex = -1;
}


void DropDown::AddItem(const std::string& item)
{
    m_items.push_back(item);
    if (m_selectedIndex == -1)
    {
        m_selectedIndex = 0;
        if (OnSelectionChanged)
            OnSelectionChanged(m_selectedIndex);
    }
}

void DropDown::RemoveItem(const std::string& item)
{
    auto it = std::find(m_items.begin(), m_items.end(), item);
    if (it != m_items.end())
    {
        int index = std::distance(m_items.begin(), it);
        m_items.erase(it);

        if (m_selectedIndex == index)
        {
            m_selectedIndex = m_items.empty() ? -1 : 0;
            if (OnSelectionChanged)
                OnSelectionChanged(m_selectedIndex);
        }
        else if (m_selectedIndex > index)
        {
            m_selectedIndex--;
        }
    }
}

const std::string& DropDown::GetSelectedItem() const
{
    static std::string empty;
    if (m_selectedIndex >= 0 && m_selectedIndex < (int)m_items.size())
        return m_items[m_selectedIndex];
    return empty;
}

void DropDown::SetSelectedIndex(int index)
{
    if (index >= -1 && index < (int)m_items.size() && index != m_selectedIndex)
    {
        m_selectedIndex = index;
        if (OnSelectionChanged)
            OnSelectionChanged(m_selectedIndex);
    }
}


void DropDown::OnDraw(RenderBatch* batch)
{
    Skin* skin = m_gui->GetSkin();
    Font* font = skin->GetFont();

    // Main button
    batch->DrawRectangle((int)GetRealX(), (int)GetRealY(),
                        (int)m_size.x, (int)m_size.y,
                        skin->GetColor(DROPDOWN_BACKGROUND), true);

    batch->DrawRectangle((int)GetRealX(), (int)GetRealY(),
                        (int)m_size.x, (int)m_size.y,
                        skin->GetColor(DROPDOWN_BORDER), false);

    // Selected text
    if (m_selectedIndex >= 0 && m_selectedIndex < (int)m_items.size())
    {
        float textY = GetRealY() + (m_size.y - font->GetHeight()) / 2;
        font->DrawText(batch, m_items[m_selectedIndex].c_str(),
                      Vector2(GetRealX() + 5, textY),
                      skin->GetColor(DROPDOWN_TEXT));
    }

    // Arrow
    float arrowSize = m_size.y * 0.3f;
    float arrowX = GetRealX() + m_size.x - arrowSize - 5;
    float arrowY = GetRealY() + (m_size.y - arrowSize) / 2;

    Vector2 p1(arrowX, arrowY);
    Vector2 p2(arrowX + arrowSize, arrowY);
    Vector2 p3(arrowX + arrowSize/2, arrowY + arrowSize);

    batch->Mode(TRIANGLES);
    batch->Color4f(0.2f, 0.2f, 0.2f, 1.0f);
    batch->Vertex2f(p1.x, p1.y);
    batch->Vertex2f(p2.x, p2.y);
    batch->Vertex2f(p3.x, p3.y);

    // Dropdown list when open
    if (m_isOpen)
    {
        float itemHeight = font->GetHeight() + 10;
        float listHeight = itemHeight * m_items.size();

        m_dropDownBounds = Rectangle(GetRealX(), GetRealY() + m_size.y,
                                   m_size.x, listHeight);

        batch->DrawRectangle(m_dropDownBounds.x, m_dropDownBounds.y,
                            m_dropDownBounds.width, m_dropDownBounds.height,
                            skin->GetColor(DROPDOWN_BACKGROUND), true);

        batch->DrawRectangle(m_dropDownBounds.x, m_dropDownBounds.y,
                            m_dropDownBounds.width, m_dropDownBounds.height,
                            skin->GetColor(DROPDOWN_BORDER), false);

        float itemY = GetRealY() + m_size.y;
        for (size_t i = 0; i < m_items.size(); i++)
        {
            if (m_hoverIndex == (int)i)
            {
                batch->DrawRectangle((int)GetRealX(), (int)itemY,
                                   (int)m_size.x, (int)itemHeight,
                                   skin->GetColor(DROPDOWN_ITEM_HOVER), true);
            }

           

            font->DrawText(batch, m_items[i].c_str(),
                          Vector2(GetRealX() + 5, itemY + 5),
                          skin->GetColor(DROPDOWN_TEXT));

            itemY += itemHeight;
        }
    }
}

void DropDown::OnMouseDown(int x, int y, int button)
{
    if (button != 1) return;

    if (m_bounds.Contains(x, y))
    {
        m_isOpen = !m_isOpen;
        return;
    }

    if (m_isOpen && m_dropDownBounds.Contains(x, y))
    {
        float itemHeight = 18;
      //  m_gui->GetSkin()->GetFont()->GetHeight() + 10;
        int index = (y - m_dropDownBounds.y) / itemHeight;

        if (index >= 0 && index < (int)m_items.size())
        {
            if (m_selectedIndex != index)
            {
                m_selectedIndex = index;
                if (OnSelectionChanged) OnSelectionChanged(m_selectedIndex);
            }
        }
        m_isOpen = false;
    }
    else
    {
        m_isOpen = false;
    }
}

void DropDown::OnMouseUp(int x, int y, int button)
{
}

void DropDown::OnUpdate(float delta)
{
    m_bounds = Rectangle(GetRealX(), GetRealY(), m_size.x, m_size.y);

    if (m_isOpen)
    {
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);

        if (m_dropDownBounds.Contains(mouseX, mouseY))
        {
           // float itemHeight = m_gui->GetSkin()->GetFont()->GetHeight() + 10;
            //m_hoverIndex = (mouseY - m_dropDownBounds.y) / itemHeight;
        }
        else
        {
            m_hoverIndex = -1;
        }
    }
}


Tooltip::Tooltip(const std::string& text) : Widget()
{
    m_text = text;
    m_showDelay = 0.5f;
    m_currentDelay = 0.0f;
    m_visible = false;
    m_size.x = 200; // Default width
    m_size.y = 30;  // Default height
}

void Tooltip::OnDraw(RenderBatch* batch)
{
    if (!m_visible) return;

    if (m_parent == nullptr) return;
    if (m_parent->m_type != WIDGET_WINDOW)
        return;

    Window* window = (Window*)m_parent;
    Skin* skin = m_gui->GetSkin();
    Font* font = skin->GetFont();

    // Adjust size based on text
    float textWidth = font->GetWidth(m_text.c_str());
    float textHeight = font->GetHeight();
    m_size.x = textWidth + 20;
    m_size.y = textHeight + 10;

    // Get mouse position for positioning
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);

    // Position tooltip near mouse
    m_position.x = mouseX + 15;
    m_position.y = mouseY - m_size.y - 5;

    // Keep tooltip on screen
    if (m_position.x + m_size.x > window->GetWidth())
        m_position.x = window->GetWidth() - m_size.x;
    if (m_position.y < 0)
        m_position.y = mouseY + 15;

    // Draw background
    batch->DrawRectangle((int)GetRealX(), (int)GetRealY(),
                        (int)m_size.x, (int)m_size.y,
                        skin->GetColor(TOOLTIP_BACKGROUND), true);

    // Draw border
    batch->DrawRectangle((int)GetRealX(), (int)GetRealY(),
                        (int)m_size.x, (int)m_size.y,
                        skin->GetColor(TOOLTIP_BORDER), false);

    // Draw text
    float textX = GetRealX() + (m_size.x - textWidth) / 2;
    float textY = GetRealY() + (m_size.y - textHeight) / 2;
    font->DrawText(batch, m_text.c_str(),
                  Vector2(textX, textY),
                  skin->GetColor(TOOLTIP_TEXT));
}

void Tooltip::OnUpdate(float delta)
{
    if (m_parent == nullptr) return;
    if (m_parent->m_type == WIDGET_WINDOW)
    {
        Window* window = (Window*)m_parent;
        m_focus = window->m_focus;
    }
    if (m_focus)
    {
        m_currentDelay += delta;
        if (m_currentDelay >= m_showDelay)
        {
            m_visible = true;
        }
    }
    else
    {
        m_currentDelay = 0.0f;
        m_visible = false;
    }
}

Layout::Layout() : Widget()
{
    m_spacing = 5.0f;  //  entre widgets
    m_padding = 10.0f; //  nas bordas
    m_alignment = ALIGN_START;
    m_type = WIDGET_LAYOUT;
}

void Layout::OnDraw(RenderBatch *batch)
{
    //  borda ou fundo do layout
    // batch->DrawRectangle(GetRealX(), GetRealY(), m_size.x, m_size.y, Color(0.2f, 0.2f, 0.2f, 0.1f), false);
}

void Layout::OnUpdate(float delta)
{
    UpdateLayout();
    Widget::OnUpdate(delta);
}

VBox::VBox(float x, float y, float width, float height) : Layout()
{
    m_position.x = x;
    m_position.y = y;
    m_size.x = width;
    m_size.y = height;
    m_type = WIDGET_VBOX; 
}

void VBox::UpdateLayout()
{
    if (m_children.empty())
        return;

    float currentY = m_padding;
    float availableWidth = m_size.x - (m_padding * 2);

    // Primeiro, calcular altura total necessária
    float totalContentHeight = 0;
    for (Widget *widget : m_children)
    {
        if (!widget->IsVisible())
            continue;
        totalContentHeight += widget->m_size.y;
    }

    // Adicionar espaçamento entre widgets
    totalContentHeight += m_spacing * (m_children.size() - 1);

    // Posicionar cada widget
    for (Widget *widget : m_children)
    {
        if (!widget->IsVisible())
            continue;

        float widgetX = m_padding;
        switch (m_alignment)
        {
        case ALIGN_CENTER:
            widgetX = m_padding + (availableWidth - widget->m_size.x) / 2;
            break;
        case ALIGN_END:
            widgetX = m_size.x - m_padding - widget->m_size.x;
            break;
        case ALIGN_STRETCH:
            widget->m_size.x = availableWidth;
            break;
        default: // ALIGN_START
            break;
        }

        widget->m_position.x = widgetX;
        widget->m_position.y = currentY;
        currentY += widget->m_size.y + m_spacing;
    }
}

HBox::HBox(float x, float y, float width, float height) : Layout()
{
    m_position.x = x;
    m_position.y = y;
    m_size.x = width;
    m_size.y = height;
     m_type = WIDGET_HBOX;
}

void HBox::UpdateLayout()
{
    if (m_children.empty())
        return;

    float currentX = m_padding;
    float availableHeight = m_size.y - (m_padding * 2);

    // Primeiro, calcular largura total necessária
    float totalContentWidth = 0;
    for (Widget *widget : m_children)
    {
        if (!widget->IsVisible())
            continue;
        totalContentWidth += widget->m_size.x;
    }

    // Adicionar espaçamento entre widgets
    totalContentWidth += m_spacing * (m_children.size() - 1);

    // Posicionar cada widget
    for (Widget *widget : m_children)
    {
        if (!widget->IsVisible())
            continue;

        float widgetY = m_padding;
        switch (m_alignment)
        {
        case ALIGN_CENTER:
            widgetY = m_padding + (availableHeight - widget->m_size.y) / 2;
            break;
        case ALIGN_END:
            widgetY = m_size.y - m_padding - widget->m_size.y;
            break;
        case ALIGN_STRETCH:
            widget->m_size.y = availableHeight;
            break;
        default: // ALIGN_START
            break;
        }

        widget->m_position.x = currentX;
        widget->m_position.y = widgetY;
        currentX += widget->m_size.x + m_spacing;
    }
}
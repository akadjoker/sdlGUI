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
    m_colors[SCROLLBAR_NOB] = Color(0.2f,0.2f,0.7f);
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
    m_colors[CHECKBOX_OVER]  = Color(0.2f, 0.2f, 0.2f, 1.0f);

    m_colors[RADIO_TEXT] = Color(0.1f, 0.1f, 0.1f, 1.0f);
    m_colors[RADIO] = Color(0.8f, 0.8f, 0.8f, 1.0f);
    m_colors[RADIO_DOWN] = Color(0.6f, 0.6f, 0.6f, 1.0f);
    m_colors[RADIO_CHECK] = Color(0.2f, 0.2f, 0.2f, 1.0f);
    m_colors[RADIO_OVER]  = Color(0.2f, 0.2f, 0.2f);

    m_colors[RADIO_GROUP_TEXT] = Color(0.1f, 0.1f, 0.1f, 1.0f);
    m_colors[RADIO_GROUP] = Color(0.8f, 0.8f, 0.8f, 1.0f);
    m_colors[RADIO_GROUP_ITEM] = Color(1.0f, 1.0f, 1.0f, 1.0f);
    m_colors[RADIO_GROUP_DOWN] = Color(0.6f, 0.6f, 0.6f, 1.0f);
    m_colors[RADIO_GROUP_CHECK] = Color(0.2f, 0.2f, 0.2f, 1.0f);
    m_colors[RADIO_GROUP_OVER]  = Color(0.2f, 0.2f, 0.2f);
    m_colors[RADIO_GROUP_ITEM_OVER]  = Color(0.2f, 0.2f, 0.2f);



    m_colors[LISTBOX_TEXT] = Color(0.1f, 0.1f, 0.1f, 1.0f);
    m_colors[LISTBOX_FACE] = Color(0.2f, 0.2f, 0.2f, 1.0f);
    m_colors[LISTBOX_SELECTED] = Color(0.6f, 0.6f, 0.6f, 1.0f);
    m_colors[LISTBOX_SELECTED_TEXT] = Color(1.0f, 1.0f, 1.0f, 1.0f);
    m_colors[LISTBOX_ITEM_OVER] = Color(0.4f, 0.4f, 0.4f, 1.0f);



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
    if  (m_skin != nullptr)
    {
        delete m_skin;
        m_skin = skin;
    }
}

Window *GUI::CreateWindow(const std::string &title, float x, float y, float width, float height)
{
    Window *window = new Window(title, x, y, width, height);
    window->m_gui=this;
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

   
    // GLint last_scissor_box[4]; 
    // glGetIntegerv(GL_SCISSOR_BOX, last_scissor_box);

    // glEnable(GL_SCISSOR_TEST);

    // SetScissor(0,0,m_width,m_height);
 


    for (unsigned int i = 0; i < m_widgets.size(); i++)
    {
        m_widgets[i]->Render(batch);
    }


 
//     glDisable(GL_SCISSOR_TEST);
 
 
 
//    glScissor(last_scissor_box[0], last_scissor_box[1], last_scissor_box[2], last_scissor_box[3]);
  
}

void GUI::OnMouseMove(int x, int y)
{
    for (unsigned int i = 0; i < m_widgets.size(); i++)
    {
            m_widgets[i]->MouseMove(x, y);
    }
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

}

Widget::~Widget()
{
    m_gui= nullptr;
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

Window::Window(const std::string &title, float x, float y, float width, float height): Widget()
{
    m_title = title;
    m_position.x = x;
    m_position.y = y;
    m_size.x = width;
    m_size.y = height;
    m_dragging = false;
    m_dragOffset= Vector2(0.0f, 0.0f);
}

void Window::OnDraw(RenderBatch *batch)
{
    Skin * skin = m_gui->GetSkin();
    Font * font = skin->GetFont();

   // m_gui->SetScissor((int)GetRealX(), (int)GetRealY()-20, (int)m_size.x, (int)m_size.y);
    
    

    batch->DrawRectangle((int)GetRealX(),(int) GetRealY()-20, (int)m_size.x,(int) 20, skin->GetColor(WINDOW_TOP_BAR),true);
    if (m_visible)
        batch->DrawRectangle((int)GetRealX(),(int) GetRealY(), (int)m_size.x,(int) m_size.y, skin->GetColor(WINDOW),true);

    if (m_visible)
        batch->DrawCircle((int)GetRealX()+ (m_size.x-10),(int) GetRealY()-10, 4,  Color(0, 1, 0, 0.8),true);
    else 
        batch->DrawCircle((int)GetRealX()+ (m_size.x-10),(int) GetRealY()-10, 4,  Color(1, 0, 0, 0.8),true);

    // batch->DrawRectangle(m_bounds_bar, Color(1,0,0),false);
    // batch->DrawRectangle(m_bounds_hide, Color(1,0,0),false);
    
    font->DrawText(batch, m_title.c_str(), Vector2(GetRealX()+10, GetRealY()-17), skin->GetColor(WINDOW_TITLE));
    
    batch->Render();
}

void Window::OnUpdate(float delta)
{
    (void)delta;
    m_bounds = Rectangle(m_position.x,m_position.y-20, m_size.x, m_size.y);
    m_bounds_bar = Rectangle(GetRealX(), GetRealY()-20, m_size.x, 20);
    m_bounds_hide = Rectangle(GetRealX()+m_size.x-16, GetRealY()-16, 12, 12);

}

void Window::OnMouseMove(int x, int y)
{
    m_focus = m_bounds.Contains(x, y);
    if (m_dragging)
    {
        m_position.x = x - m_dragOffset.x;
        m_position.y = y - m_dragOffset.y;
    }
    
}

void Window::OnMouseDown(int x, int y, int button)
{
    (void)button;
    if (m_bounds_bar.Contains(x, y))
    {
        m_dragging = true;
        m_dragOffset.x = x - GetRealX();
        m_dragOffset.y = y - GetRealY();
    }
    

}

void Window::OnMouseUp(int x, int y, int button)
{
    if (m_bounds_hide.Contains(x, y) && button == 1 )
    {
        m_visible = !m_visible;
    }
    m_dragging = false;
} 

Slider *Window::CreateSlider(bool vertical, float x, float y, float width, float height, float min, float max, float value)
{
    Slider *slider = new Slider(vertical, x, y, width, height, min, max, value);
    slider->m_gui  = this->m_gui;
    Add(slider);
    return slider;
}

Label *Window::CreateLabel(const std::string &text, float x, float y)
{
    
    Label *label = new Label(text, x, y);
    label->m_gui  = this->m_gui;
    Add(label);
    return label;

}

Button *Window::CreateButton(const std::string &text, float x, float y, float width, float height)
{

    Button *button = new Button(text, x, y, width, height);
    button->m_gui  = this->m_gui;
    Add(button);
    return button;

}

CheckBox *Window::CreateCheckBox(const std::string &text, bool state, float x, float y, float width, float height)
{
    
        CheckBox *checkbox = new CheckBox(text, state, x, y, width, height);
        checkbox->m_gui  = this->m_gui;
        Add(checkbox);
        return checkbox;
 
}

RadioButton *Window::CreateRadioButton(const std::string &text, bool state, float x, float y, float width, float height)
{
   
    RadioButton *radiobutton = new RadioButton(text, state, x, y, width, height);
    radiobutton->m_gui  = this->m_gui;
    Add(radiobutton);
    return radiobutton;
}

RadioGroup *Window::CreateRadioGroup(float x, float y, float width, float height, bool vertical)
{
    RadioGroup *radiogroup = new RadioGroup(x, y, width, height, vertical);
    radiogroup->m_gui  = this->m_gui;
    Add(radiogroup);
    return radiogroup;
}

ListBox *Window::CreateListBox(float x, float y, float width, float height)
{
    ListBox *listbox = new ListBox(x, y, width, height);
    listbox->m_gui  = this->m_gui;
    Add(listbox);
    return listbox;
}

Slider::Slider(bool vertical, float x, float y, float width, float height, float min, float max, float value): Widget()
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

}

void Slider::SetValue(float value)
{
    m_value = value;
    if (OnValueChanged)
        OnValueChanged(m_value);
}

void Slider::OnDraw(RenderBatch *batch)
{
    Skin * skin = m_gui->GetSkin();
    Font * font = skin->GetFont();
  
    batch->DrawRectangle((int)GetRealX(),(int) GetRealY(), (int)m_size.x,(int) m_size.y, skin->GetColor(SCROLLBAR),true);
    if (m_vertical)
    {
        
        batch->DrawRectangle((int)GetRealX(),(int) GetRealY(), (int)m_size.x,(int) m_grow, skin->GetColor(SCROLLBAR_FILL),true);
        batch->DrawRectangle((int)GetRealX(),(int) GetRealY()+(int)m_grow, (int)m_size.x, 5, skin->GetColor(SCROLLBAR_NOB),true);
        font->DrawText(batch,m_bounds.x + m_bounds.width,m_bounds.y+(m_bounds.height/2),false,true, Color(1, 1, 1),"%03.f",m_value);
    }
    else
    {
        batch->DrawRectangle((int)GetRealX(),(int) GetRealY(), (int)m_grow,(int) m_size.y, skin->GetColor(SCROLLBAR_FILL),true);
        batch->DrawRectangle((int)GetRealX()+(int)m_grow, (int) GetRealY(), 5,(int) m_size.y, skin->GetColor(SCROLLBAR_NOB),true);
        font->DrawText(batch,m_bounds.x + m_bounds.width,m_bounds.y+(m_bounds.height/2),false,true, Color(1, 1, 1),"%03.f",m_value);

    }
    if (m_focus)
    {
        batch->DrawRectangle((int)GetRealX(),(int) GetRealY(), (int)m_size.x,(int) m_size.y, Color(0.2f, 0.2f, 0.2f),false);
    }


}

void Slider::OnUpdate(float delta)
{
    (void)delta;
    m_bounds = Rectangle(GetRealX(),GetRealY(), m_size.x+1, m_size.y+1);

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
                    float pos = y -  GetRealY(); 
                    m_value   =m_min + (m_max - m_min) * (pos) / m_size.y;
                }
            }
            else
            {
                
                if (m_bounds.Contains(x, y))
                {
                    float pos = x -  GetRealX(); 
                    m_value   =m_min + (m_max - m_min) * (pos) / m_size.x;
                }
            }
            if (OnValueChanged)
                OnValueChanged(m_value);
     }

}

void Slider::OnMouseDown(int x, int y, int button)
{
    
   
    if (button==1 && m_focus)
    {
            m_dragging = true;
            if (m_vertical)
            {
                if (m_bounds.Contains(x, y))
                {
                    float pos = y -  GetRealY(); 
                    m_value   =m_min + (m_max - m_min) * (pos) / m_size.y;
                }
            }
            else
            { 
                
                if (m_bounds.Contains(x, y))
                {
                    float pos = x -  GetRealX(); 
                    m_value   =m_min + (m_max - m_min) * (pos) / m_size.x;
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
    if (!m_focus)         return;
    m_value += delta;
    if (m_value < m_min)
        m_value = m_min;
    if (m_value > m_max)
        m_value = m_max;
}

Label::Label(const std::string &text, float x, float y): Widget()
{
    m_text = text;
    m_position.x = x;
    m_position.y = y;
    m_color = Color::WHITE;
    m_set_color = false;
    m_draw_background=false;
    
}

void Label::OnDraw(RenderBatch *batch)
{
    Skin * skin = m_gui->GetSkin();
    Font * font = skin->GetFont();
    float w = font->GetWidth(m_text.c_str());
    float h = font->GetHeight();
    m_bounds = Rectangle(GetRealX(),GetRealY(), w+1, h+1);
    if (!m_set_color)
    {
        m_color = skin->GetColor(LABEL);
        m_set_color = true;
    }
    if (m_draw_background)
    {
        batch->DrawRectangle((int)GetRealX(),(int) GetRealY(), (int)w,(int) h, skin->GetColor(LABEL_BACKGROUND),true);
    }
    
    font->DrawText(batch, m_text.c_str(), Vector2(GetRealX() , GetRealY()) ,m_color);
}

Button::Button(const std::string &text, float x, float y, float width, float height): Widget()
{
    m_text = text;
    m_position.x = x;
    m_position.y = y;
    m_size.x = width;
    m_size.y = height;
    m_down = false;
    m_focus = false;
    m_hover = false;

    text_width  = 0;
    text_height = 0;
}

void Button::OnDraw(RenderBatch *batch)
{
    Skin * skin = m_gui->GetSkin();
    Font * font = skin->GetFont();
    
    if (m_down)
        batch->DrawRectangle((int)GetRealX(),(int) GetRealY(), (int)m_size.x,(int) m_size.y, skin->GetColor(BUTTON_DOWN),true);
    else
        batch->DrawRectangle((int)GetRealX(),(int) GetRealY(), (int)m_size.x,(int) m_size.y, skin->GetColor(BUTTON_FACE),true);
    if (m_hover)
        batch->DrawRectangle((int)GetRealX(),(int) GetRealY(), (int)m_size.x,(int) m_size.y, Color(0.2f, 0.2f, 0.2f),false);

    int w  = font->GetWidth(m_text.c_str());
    float h = font->GetHeight();

    //Log(2, "w %f h %f", w, h);

    font->DrawText(batch, m_text.c_str(), Vector2(GetRealX() + (m_size.x / 2) - (w / 2), GetRealY() + (m_size.y / 2) - (h/2)), skin->GetColor(BUTTON_TEXT));
}

void Button::OnUpdate(float delta)
{
    (void)delta;
    if (text_width == 0 || text_height == 0)
    {
        Skin * skin = m_gui->GetSkin();
        Font * font = skin->GetFont();
        text_width = font->GetWidth(m_text.c_str());
        text_height = font->GetHeight();
    }
   

      m_bounds = Rectangle(GetRealX(),GetRealY(), m_size.x+1, m_size.y+1);

      
  
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
        if (iskeyMappped && m_gui!=nullptr)  
        if (key == m_key && !m_down)
        {
            m_down = true;
            if (OnDown)
                OnDown();
        }

}

void Button::OnKeyUp(Uint32 key)
{
        if (iskeyMappped && m_gui!=nullptr)  
        if (key == m_key && m_down)
        {
            m_down = false;
            if (OnClick)
                OnClick();
        }
}

CheckBox::CheckBox(const std::string &text, bool state, float x, float y, float width, float height): Widget()
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

}

void CheckBox::OnDraw(RenderBatch *batch)
{
    Skin * skin = m_gui->GetSkin();
    Font * font = skin->GetFont();
    
    batch->DrawRectangle((int)GetRealX(),(int) GetRealY(), (int)m_size.x,(int) m_size.y, skin->GetColor(CHECKBOX),true);
    if (m_hover)
        batch->DrawRectangle((int)GetRealX(),(int) GetRealY(), (int)m_size.x,(int) m_size.y, skin->GetColor(CHECKBOX_OVER),false);


    if (m_checked)
    {
       batch->DrawRectangle((int)GetRealX()+4,(int) GetRealY()+4, m_size.x-8,m_size.y-8,skin->GetColor(CHECKBOX_CHECK) ,true);
    }
    float h = font->GetHeight();
    font->DrawText(batch, m_text.c_str(), Vector2(GetRealX() + (m_size.x + 1), GetRealY() + (m_size.y / 2) - (h/2)), skin->GetColor(CHECKBOX_TEXT));
}

void CheckBox::OnUpdate(float delta)
{
    (void)delta;
  

      m_bounds = Rectangle(GetRealX(),GetRealY(), m_size.x+1, m_size.y+1);

      
  
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
        if (iskeyMappped && m_gui!=nullptr)  
        if (key == m_key && !m_down)
        {
            m_down = true;
            if (OnDown)
                OnDown();
        }

}

void CheckBox::OnKeyUp(Uint32 key)
{
        if (iskeyMappped && m_gui!=nullptr)  
        if (key == m_key && m_down)
        {
            m_down = false;
            if (OnClick)
                OnClick();
        }
}

ListBox::ListBox(float x, float y, float width, float height):Widget()
{
    m_position.x = x;
    m_position.y = y;
    m_size.x = width;
    m_size.y = height;

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
    Skin * skin = m_gui->GetSkin();
    Font * font = skin->GetFont();
    
    batch->DrawRectangle((int)GetRealX(),(int) GetRealY(), (int)m_size.x,(int) m_size.y, skin->GetColor(BUTTON_FACE),true);
    batch->DrawRectangle((int)GetRealX(),(int) GetRealY(), (int)m_size.x,(int) m_size.y, Color(0.2f, 0.2f, 0.2f),false);

    float h = font->GetHeight() ;
    int y = - (m_scrollOffset) + GetRealY() + h;
    int x = GetRealX() + 2;
    m_scroll_size = h;

    float max_height  =   (m_size.y / h) ;



    m_can_scroll = m_items.size() * h > m_size.y;
    m_min_scrollOffset = h;

    if (!m_can_scroll)
    {
        m_max_scrollOffset = h;
    } else 
    {
      m_max_scrollOffset = m_items.size() * h - m_size.y;
    }
    
    

    for (unsigned int i = 0; i < m_items.size(); i++)
     {
        if (y + h > GetRealY() + m_size.y)
             break;
        if (y   < GetRealY())
        {
            y += h;
            continue;
        }

        if ((int)i == m_selectedIndex)
        {
            batch->DrawRectangle((int)GetRealX(),(int) y, (int)m_size.x,(int) h, skin->GetColor(LISTBOX_FACE),true);
            font->DrawText(batch, m_items[i].c_str(), Vector2(x, y), skin->GetColor(LISTBOX_SELECTED_TEXT));
        }
        else
        {
            font->DrawText(batch, m_items[i].c_str(), Vector2(x, y), skin->GetColor(LISTBOX_TEXT));
        }

        if (m_focusIndex == (int)i)
        {
            batch->DrawRectangle((int)GetRealX(),(int) y, (int)m_size.x,(int) h, skin->GetColor(LISTBOX_ITEM_OVER),false);
        }
    
        y += h;
    }
}

void ListBox::OnUpdate(float delta)
{
    (void)delta;
    m_bounds = Rectangle(GetRealX(),GetRealY(), m_size.x+1, m_size.y+1);

  

}

void ListBox::OnMouseWheel(int delta)
{
    if (!m_focus)         return;
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
        int y =-(m_scrollOffset) +  GetRealY() + h ;
        
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
        int y =-(m_scrollOffset) +  GetRealY() + h ;
        

      

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
        if (iskeyMappped && m_gui!=nullptr)  
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
                m_scrollOffset-=m_scroll_size;
                if (m_scrollOffset < m_min_scrollOffset)
                    m_scrollOffset = m_min_scrollOffset;
                }

            if (key == SDLK_DOWN)
            {

                m_scrollOffset+=m_scroll_size;
                if (m_scrollOffset > m_max_scrollOffset)
                    m_scrollOffset = m_max_scrollOffset;

            }
            
        }

        Log(0, "m_scrollOffset %d", m_scrollOffset);



}

void ListBox::OnKeyUp(Uint32 key)
{
        if (iskeyMappped && m_gui!=nullptr)  
        if (key == m_key && m_down)
        {
            m_down = false;
            if (OnClick)
                OnClick();
        }
}

RadioButton::RadioButton(const std::string &text, bool state, float x, float y, float width, float height): Widget()
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

}

void RadioButton::OnDraw(RenderBatch *batch)
{
    Skin * skin = m_gui->GetSkin();
    Font * font = skin->GetFont();
    
    batch->DrawRectangle((int)GetRealX(),(int) GetRealY(), (int)m_size.x,(int) m_size.y, skin->GetColor(RADIO),true);
    if (m_hover)
        batch->DrawRectangle((int)GetRealX(),(int) GetRealY(), (int)m_size.x,(int) m_size.y, skin->GetColor(RADIO_OVER),false);

    if (m_checked)
    {
        batch->DrawCircle((int)GetRealX()+(m_size.x/2),(int) GetRealY()+(m_size.y/2), 4,  skin->GetColor(RADIO_CHECK),true);
    }
        
    float h = font->GetHeight();

     font->DrawText(batch, m_text.c_str(), Vector2(GetRealX() + (m_size.x + 1), GetRealY() + (m_size.y / 2) - (h/2)), skin->GetColor(RADIO_TEXT));
}

void RadioButton::OnUpdate(float delta)
{
    (void)delta;
    m_bounds = Rectangle(GetRealX(),GetRealY(), m_size.x+1, m_size.y+1);  
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
        if (iskeyMappped && m_gui!=nullptr)  
        if (key == m_key && !m_down)
        {
            m_down = true;
            if (OnDown)
                OnDown();
        }

}


void RadioButton::OnKeyUp(Uint32 key)
{
        if (iskeyMappped && m_gui!=nullptr)  
        if (key == m_key && m_down)
        {
            m_down = false;
            if (OnClick)
                OnClick();
        }
}

RadioGroup::RadioGroup(float x, float y, float width, float height, bool vertical): Widget()
{
    m_position.x = x;
    m_position.y = y;
    m_size.x = width;
    m_size.y = height;
    m_vertical = vertical;
    m_selectedIndex = -1;
    m_hover = false;
    m_focus = false;
    m_item_width=20;
    m_item_height=20;
    m_over_index = -1;
    m_columns=2;
}

RadioGroup::~RadioGroup()
{
    for (unsigned int i = 0; i < m_radios.size(); i++)
    {
        delete m_radios[i];
    }
    m_radios.clear();
}

int RadioGroup::Add(const std::string &text,bool state)
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

    

    Skin * skin = m_gui->GetSkin();
    Font * font = skin->GetFont();


    
    batch->DrawRectangle((int)GetRealX(),(int) GetRealY(), (int)m_size.x,(int) m_size.y, skin->GetColor(RADIO_GROUP),true);
    if (m_hover)
        batch->DrawRectangle((int)GetRealX(),(int) GetRealY(), (int)m_size.x,(int) m_size.y, skin->GetColor(RADIO_GROUP_OVER),false);

    int h = font->GetHeight() * 0.5f;

    int count = m_radios.size();

     
    

    if (m_vertical)
    {
        m_item_height = (m_size.y / count) ;
        m_item_width  = m_size.x;
       // float ratio = ((float)m_size.y+(m_item_height * 0.5f)) / (float)count -2;
        float offSetY = 0;  
        for (int i = 0; i < count; i++)
        {
            Radio *radio = m_radios[i];
            radio->x = 12 +   GetRealX() ;


            float b_y = GetRealY() + offSetY ;

            radio->y =(m_item_height*0.5f) + b_y;     //3 + (m_item_height/2) +  GetRealY() + (i * ratio);

             

            bool ischecked = radio->checked;
     
            //radio->bound.set(GetRealX(), radio->y-(m_item_height*0.5f)-3, m_size.x, m_item_height+6);

            radio->bound.set(GetRealX(), b_y, m_size.x, m_item_height);



            batch->DrawCircle((int)radio->x,(int) radio->y, 7,  skin->GetColor(RADIO_GROUP_ITEM),true);
            if (ischecked)
                batch->DrawCircle((int)radio->x,(int) radio->y, 4,  skin->GetColor(RADIO_CHECK),true);
            
            font->DrawText(batch, radio->text.c_str(), radio->x + 12, radio->y - h   , skin->GetColor(RADIO_GROUP_TEXT));
            if (m_over_index == i)
                batch->DrawRectangle(radio->bound.x,radio->bound.y,radio->bound.width,radio->bound.height, skin->GetColor(RADIO_GROUP_ITEM_OVER),false);

            offSetY += m_item_height;
        }
    }
    else
    {
       

        
        int colunas = static_cast<int>(std::ceil(static_cast<float>(count ) / m_columns));
        
        m_item_width  = (m_size.x / m_columns) ;
        m_item_height = (m_size.y / colunas) ;



       
        //Log(1, "m_columns %d colunas %d", m_columns , colunas);
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

            radio->x =   GetRealX() + offSetX + 12;
            radio->y =   GetRealY() + offSetY + (m_item_height/2);

            float b_x = GetRealX() + offSetX ;
            float b_y = GetRealY() + offSetY ;


            bool ischecked = radio->checked;

           
            radio->bound.set(b_x, b_y, m_item_width, m_item_height);

            batch->DrawCircle((int)radio->x,(int) radio->y, 7,  skin->GetColor(RADIO_GROUP_ITEM),true);
            if (ischecked)
                batch->DrawCircle((int)radio->x,(int) radio->y, 4,  skin->GetColor(RADIO_CHECK),true);
         

          //  batch->DrawRectangle(radio->bound.x,radio->bound.y, radio->bound.width, radio->bound.height, Color::RED,false);


            font->DrawText(batch, radio->text.c_str(), radio->x + 12, radio->y - h   , skin->GetColor(RADIO_GROUP_TEXT));

             if (m_over_index == i)
                batch->DrawRectangle(radio->bound.x,radio->bound.y,radio->bound.width,radio->bound.height, skin->GetColor(RADIO_GROUP_ITEM_OVER),false);



           
        }
    }
    

}

void RadioGroup::OnUpdate(float delta)
{
    (void)delta;
    m_bounds = Rectangle(GetRealX(),GetRealY(), m_size.x+1, m_size.y+1);

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
        int lastSelect=-1;
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

        if (lastSelect!=-1)
        {
            for (unsigned int i = 0; i < m_radios.size(); i++)
            {
                if (i!=lastSelect)
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



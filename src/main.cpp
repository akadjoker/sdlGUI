
#include "Utils.h"
#include "Batch.h"
#include "Font.h"
#include "Gui.h"
#include "Math.h"

#include "pch.h"


extern "C" const char* __lsan_default_suppressions() {
    return "leak:libSDL2\n"
           "leak:SDL_DBus\n";
}


 int SCREEN_WIDTH = 1024;
 int SCREEN_HEIGHT = 720;

int main()
{


    if (SDL_Init(SDL_INIT_VIDEO) < 0) 
    {
        Log(2, "Erro ao inicializar a SDL %s ", SDL_GetError() );
        return -1;
    }
        // SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        // SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
        // SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

        // SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
        // SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
        // SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

            // SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    // SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    // SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
        

        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
        SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

    

    SDL_Window* window = SDL_CreateWindow("scop", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT,  SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (!window) 
    {
        Log(2, "Error creating window%s " , SDL_GetError() );
        SDL_Quit();
        return -1;
    }


    SDL_GLContext glContext = SDL_GL_CreateContext(window);
    if (!glContext) 
    {
        Log(2,  "Erro creating  OpenGL  context %s ",SDL_GetError() );
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    Log(0,"Vendor  :  %s",glGetString(GL_VENDOR));
    Log(0,"Renderer:  %s",glGetString(GL_RENDERER));
    Log(0,"Version :  %s",glGetString(GL_VERSION));

    RenderBatch batch2D;
   

    batch2D.Init(12,2840*8);
     

    Matrix projection2D;
    projection2D.Ortho(0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, 1000);
    batch2D.SetMatrix(projection2D);

    Font font;

    GUI widgets;
    widgets.SetViewSize(SCREEN_WIDTH,SCREEN_HEIGHT);

    Window *window1 = widgets.CreateWindow("Mesh Transform", 10, SCREEN_HEIGHT- 360, 300, 350);

    window1->CreateLabel("yaw",   10, 30);
    window1->CreateLabel("pitch", 10, 74);
    window1->CreateLabel("roll",  10, 114);

    Slider *sliderYaw   = window1->CreateSlider(false, 10, 50, 200, 20, 0, 360, 0);
    Slider *sliderPitch = window1->CreateSlider(false, 10, 90, 200, 20, 0, 360, 0);
    Slider *sliderRoll  = window1->CreateSlider(false, 10, 130, 200, 20, 0, 360, 0);

    Slider *colorLerp = window1->CreateSlider(false, 10, 300, 160, 20, 0, 1, 0.5);
    Button *buttonLerp = window1->CreateButton("Swicth", 200, 300, 80, 20);

    Button *moveLeft = window1->CreateButton("move - x", 10, 170, 100, 20);

    Button *moveRight = window1->CreateButton("move + x", 120, 170, 100, 20);

    
    Button *moveUp = window1->CreateButton("move - y", 10, 200, 100, 20);

    Button *moveDown = window1->CreateButton("move + y", 120, 200, 100, 20);


    Button *moveFront = window1->CreateButton("move - z", 10, 230, 100, 20);

    Button *moveBack = window1->CreateButton("move + z", 120, 230, 100, 20);


    Button *reset = window1->CreateButton("reset", 50, 260, 100, 20);
    
    Window *window2 = widgets.CreateWindow("Mesh Tool", SCREEN_WIDTH-460, 24, 400, 600);

    Button *buttonUv= window2->CreateButton("Uv", 10, 50, 100, 20);
    Slider *sliderUv = window2->CreateSlider(false, 10, 20, 100, 20, 0.01f, 5.0f, 1.0f);

    Button *buttonCenter= window2->CreateButton("Center Mesh", 10, 100, 100, 20);
    Button *buttonShades= window2->CreateButton("Shades/Gray", 10, 130, 100, 20);
    CheckBox *backFaces = window2->CreateCheckBox("Back Faces", true, 10, 160, 20, 20);
    RadioButton *radioButton1 = window2->CreateRadioButton("Wireframe", true, 200, 160, 20, 20);

    RadioGroup *radioGroup = window2->CreateRadioGroup(120, 190, 100, 160,true);
    radioGroup->Add("Wireframe");
    radioGroup->Add("Solid");
    radioGroup->Add("Shadow",true);
    radioGroup->Add("Texture");
    radioGroup->Add("Normal");

     RadioGroup *radioGroup2 = window2->CreateRadioGroup(5, 400, 390, 100,false);
    radioGroup2->SetColumn(3);
    radioGroup2->Add("Wireframe");
    radioGroup2->Add("Solid");
    radioGroup2->Add("Shadow",true);
    radioGroup2->Add("Texture");
    radioGroup2->Add("Normal");
    radioGroup2->Add("None");
    radioGroup2->Add("Wireframe");
    radioGroup2->Add("Solid");
    radioGroup2->Add("Shadow",true);
    radioGroup2->Add("Texture");
    radioGroup2->Add("Normal");
    radioGroup2->Add("None");
    



    ListBox *listBox = window2->CreateListBox(10, 200, 100, 160);
    listBox->AddItem("Cube");
    listBox->AddItem("Cone");
    listBox->AddItem("Cylinder");
    listBox->AddItem("Sphere");
    listBox->AddItem("Torus");
    listBox->AddItem("Teapot");
    listBox->AddItem("Monkey");
    listBox->AddItem("Bunny");
    listBox->AddItem("Dragon");
    listBox->AddItem("Suzanne");
    listBox->AddItem("F-16");
    listBox->AddItem("Buddha");
    listBox->AddItem("Bunny2");
    listBox->AddItem("Bunny3");
    listBox->AddItem("Bunny4");
    listBox->AddItem("Bunny5");

    Label *labelSelect = window2->CreateLabel("select ", 20, 370);
    labelSelect->SetColor(Color(1,0,0,1));


    listBox->OnItemSelected= [&](int index)
    {
        labelSelect->SetText("select "+listBox->GetItem(index));
    };



  {
    Window* window = widgets.CreateWindow("Test Window", 100, 100, 350, 320);
    window->SetResizable(true);
     window->SetMinSize(350, 320); 
  //   window->SetMaxSize(800, 600);

//     VBox* vbox = window->CreateVBox(10, 10, 400, 280);
//     vbox->SetAlignment(ALIGN_CENTER);
//     vbox->SetSpacing(2);
//     vbox->SetPadding(5);

  
//     Button* btn1 = window->CreateButton("Button 1", 0, 0, 100, 30);
//     Button* btn2 = window->CreateButton("Button 2", 0, 0, 100, 30);
//     TextBox* txt = window->CreateTextBox(0, 0, 200, 25);

//     vbox->Add(btn1);
//     vbox->Add(btn2);
//     vbox->Add(txt);

// {
//     HBox* hbox = window->CreateHBox(0, 0, 360, 40);
//     hbox->SetAlignment(ALIGN_CENTER);
//     hbox->SetSpacing(5);
//     hbox->Add(window->CreateButton("Button", 0, 0, 80, 30));
//     hbox->Add(window->CreateButton("Button", 0, 0, 80, 30));
//     hbox->Add(window->CreateButton("Button", 0, 0, 80, 30));
//     hbox->Add(window->CreateButton("Button", 0, 0, 80, 30));
 

//      vbox->Add(hbox);
// }
// {
//     VBox* hbox = window->CreateVBox(0, 0, 90, 30*4);
//     hbox->SetAlignment(ALIGN_STRETCH);
//     hbox->SetSpacing(5);
//     hbox->Add(window->CreateButton("Button", 0, 0, 80, 30));
//     hbox->Add(window->CreateButton("Button", 0, 0, 80, 30));
//     hbox->Add(window->CreateButton("Button", 0, 0, 80, 30));

 

//      vbox->Add(hbox);
// }
// {
//     HBox* hbox = window->CreateHBox(0, 0, 360, 40);
//     hbox->SetAlignment(ALIGN_CENTER);
//     hbox->SetSpacing(5);
//     hbox->Add(window->CreateButton("Button", 0, 0, 80, 30));
//     hbox->Add(window->CreateButton("Button", 0, 0, 80, 30));
//     hbox->Add(window->CreateButton("Button", 0, 0, 80, 30));
//     hbox->Add(window->CreateButton("Button", 0, 0, 80, 30));
 

//      vbox->Add(hbox);
// }

    TextBox* textbox = window->CreateTextBox(20, 20, 200, 25);
    textbox->SetText("Texto");
    textbox->OnTextChanged = [](const std::string& text) 
    {
         Log(0, " Text: %s\n", text.c_str());
    };

    ProgressBar* progressbar = window->CreateProgressBar(20, 60, 200, 20);
    progressbar->SetProgress(0.75f);
    progressbar->SetShowText(true);


    DropDown* dropdown = window->CreateDropDown(20, 100, 200, 25);
    dropdown->AddItem("Option 1");
    dropdown->AddItem("Option 2");
    dropdown->AddItem("Opotin 3");
    dropdown->OnSelectionChanged = [&](int index) 
    {
        Log(0,"Value: %d \n", index);
    };


    // Button* button = window->CreateButton("Hover me", 20, 140, 100, 25);
    Tooltip* tooltip = window->CreateTooltip("Ola  exemplo");
     tooltip->SetDelay(0.5f); // Mostra tooltip após 0.5 segundos
}

    

    double lastTime = GetTime();
    int frameCount = 0;
    double fps = 0.0;
    Uint32 lastFrameTime = GetTicks(); 


    bool quit = false;
    while (!quit) 
    {
        Uint32 currentFrameTime = GetTicks(); 
        Uint32 deltaTimeUint32 = currentFrameTime - lastFrameTime; 
        float deltaTime = deltaTimeUint32 / 1000.0f; 

      
        


        SDL_Event event;
        while (SDL_PollEvent(&event)) 
        {
            switch (event.type)
            {

                case SDL_QUIT:
                {
                     quit = true;
                    break;    
                }
               
                case SDL_WINDOWEVENT:
                {
                    if (event.window.event == SDL_WINDOWEVENT_RESIZED)
                    {
                        int w = event.window.data1;
                        int h = event.window.data2;
                        SCREEN_WIDTH = w;
                        SCREEN_HEIGHT = h;
                        glViewport(0, 0, w, h);
                        projection2D.Ortho(0, w, h, 0, 0, 1000);
                        batch2D.SetMatrix(projection2D);
                        widgets.SetViewSize(SCREEN_WIDTH,SCREEN_HEIGHT);

     

                    }
                    break;  
                }    
                case SDL_MOUSEMOTION:
                {
                               
                    widgets.OnMouseMove(event.motion.x,event.motion.y);
                    break;
                }
                case SDL_MOUSEBUTTONDOWN:
                {
                               widgets.OnMouseDown(event.button.x,event.button.y,event.button.button);
                    break;
                }
                case SDL_MOUSEBUTTONUP:
                {
        
                    widgets.OnMouseUp(event.button.x,event.button.y,event.button.button);
                    
                    break;
                }
                case SDL_MOUSEWHEEL:
                {   
                        widgets.OnMouseWheel(event.wheel.y);
                       break;
                }

                
                case SDL_KEYUP:
                {
                    widgets.OnKeyUp(event.key.keysym.sym);    
                    break;
                }
            
                case SDL_KEYDOWN:
                {
                    widgets.OnKeyDown(event.key.keysym.sym);
                    if (event.key.keysym.sym == SDLK_ESCAPE)      quit = true;
                    
                    break;  
                }

            }

        }


               
              
            glClearColor(0.1f, 0.1f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        
        


            batch2D.DrawRectangle(20,18,210,20,Color(0.0,0.0,0.0,1),true);
            batch2D.DrawRectangle(20,18,210,20,Color(1,1,1,1),false);
            font.DrawText(&batch2D, 20,20, Color(1, 1, 1, 1), "Fps:%f DeltaTime:%f",fps,deltaTime);


                widgets.Update(deltaTime);
                widgets.Render(&batch2D);
            
                batch2D.Set2D();
                batch2D.Render();

            SDL_GL_SwapWindow(window);


        
    

        double currentTime = GetTime();
        frameCount++;
        if (currentTime - lastTime >= 1.0)
         {
            fps = frameCount / (currentTime - lastTime);
            std::string title = "scop by lrosa-do  [" + std::to_string(static_cast<int>(fps)) + ", "+std::to_string(deltaTime)+"ms]" ;
         
            SDL_SetWindowTitle(window, title.c_str()    );
            frameCount = 0;
            lastTime = currentTime;
        }
        lastFrameTime = currentFrameTime;


    }

    widgets.Clear();
   
    batch2D.Release();
 
    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(window);
    SDL_Quit();
    Log(0,"By! By!  ");

    return 0;
}


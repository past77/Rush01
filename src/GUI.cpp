#include "GUI.hpp"


GUI::GUI(/* args */): clearColor(0.45f, 0.55f, 0.60f, 1.00f), running(true)
{
	// Setup SDL
    // (Some versions of SDL before <2.0.10 appears to have performance/stalling issues on a minority of Windows systems, 
    // depending on whether SDL_INIT_GAMECONTROLLER is enabled or disabled.. updating to latest version of SDL is recommended!)
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER) != 0)
    {
        printf("Error: %s\n", SDL_GetError());
        return ;
    }

    // Decide GL+GLSL versions
#if __APPLE__
    // GL 3.2 Core + GLSL 150
    const char* glsl_version = "#version 150";
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG); // Always required on Mac
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
#else
    // GL 3.0 + GLSL 130
    const char* glsl_version = "#version 130";
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
#endif

    // Create window with graphics context
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
    SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
    this->window = SDL_CreateWindow("GKrellM", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, window_flags);
    SDL_GLContext gl_context = SDL_GL_CreateContext(window);
    SDL_GL_MakeCurrent(window, gl_context);
    SDL_GL_SetSwapInterval(1); // Enable vsync

    // Initialize OpenGL loader
#if defined(IMGUI_IMPL_OPENGL_LOADER_GL3W)
    bool err = gl3wInit() != 0;
#elif defined(IMGUI_IMPL_OPENGL_LOADER_GLEW)
    bool err = glewInit() !=
    bool err = gladLoadGL() == 0; GLEW_OK;
#elif defined(IMGUI_IMPL_OPENGL_LOADER_GLAD)
#else
    bool err = false; // If you use IMGUI_IMPL_OPENGL_LOADER_CUSTOM, your loader is likely to requires some form of initialization.
#endif
    if (err)
    {
        fprintf(stderr, "Failed to initialize OpenGL loader!\n");
        return ;
    }

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    // ImGui::StyleColorsDark();
    ImGui::StyleColorsClassic();

    // Setup Platform/Renderer bindings
    ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
    ImGui_ImplOpenGL3_Init(glsl_version);
    flagSkin = false;
    flagUsername = true;
	flagOS = false;
	flagTime = false;
	flagCPU = false;
	flagRAM = false;
	flagNetwork = false;
}

GUI::~GUI()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(window);
    SDL_Quit();
}


void    GUI::mainloop()
{
    while (running)
    {
        events();
        update();
		render();
    }
}

void    GUI::events()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        ImGui_ImplSDL2_ProcessEvent(&event);
        if (event.type == SDL_QUIT)
            running = false;
        if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE && event.window.windowID == SDL_GetWindowID(window))
            running = false;
    }
}

void	GUI::update()
{
    ImGuiStyle& style = ImGui::GetStyle();
    static ImGuiStyle ref_saved_style;
	std::string		str_data;
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplSDL2_NewFrame(window);
	ImGui::NewFrame();

	ImGui::Begin("GKrellM", NULL);
    if (flagSkin)
    {
        if (ImGui::ShowStyleSelector("Styles Selector"))
            ref_saved_style = style;
        ImGui::ColorEdit3("Skin", (float*)&clearColor);
    }
    if (ImGui::CollapsingHeader("Configuration"))
    {
        ImGui::Checkbox("Hostname/username module", &flagUsername);
        ImGui::Checkbox("OS info module", &flagOS);
        ImGui::Checkbox("Date/time module", &flagTime);
        ImGui::Checkbox("CPU module", &flagCPU);
        ImGui::Checkbox("RAM module", &flagRAM);
        ImGui::Checkbox("Network throughput module", &flagNetwork);
		ImGui::Checkbox("Skin", &flagSkin);
    }
	if (flagUsername)
    {
		str_data = getModuleStringData(usernameMod.getData());
		ImGui::Text("%s", str_data.c_str());
		str_data = getModuleStringData(hostNameMod.getData());
	    ImGui::Text("%s", str_data.c_str());
    }
    if (flagOS)
    {
        str_data = getModuleStringData(OSMod.getData());
        ImGui::Text("%s", str_data.c_str());
    }
    if (flagTime)
    {
        str_data = getModuleStringData(timeMod.getData());
        ImGui::Text("%s", str_data.c_str());
    }
    if (flagRAM)
    {
        str_data = getModuleStringData(RAMMod.getData());
        ImGui::Text("%s", str_data.c_str());
    }
    if (flagCPU)
    {
        static float arr[3];
        str_data = getModuleStringData(CPUMod.getData());
        ImGui::Text("%s", str_data.c_str());
		
		str_data = getModuleStringData(usageCPUMod.getData());
		usageCPUMod.gatherUsage(arr);
		ImGui::PlotHistogram("CPU Usage", arr, 3, 0, NULL, 0, 100, ImVec2(300, 80));
		ImGui::Text("%s", str_data.c_str());

    }
    if (flagNetwork)
    {
        str_data = getModuleStringData(networkMod.getData());
        ImGui::Text("%s", str_data.c_str());
    }
	ImGui::End();

}

void	GUI::render()
{
	ImGui::Render();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
	glClearColor(clearColor.x, clearColor.y, clearColor.z, clearColor.w);
	glClear(GL_COLOR_BUFFER_BIT);
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	SDL_GL_SwapWindow(window);
}

std::string		GUI::getModuleStringData(Data *d)
{
	std::string info = std::string(d->name + ": " + d->data);
	return (info);
}


SDL_Window *GUI::getWindow() { return (this->window); }
SDL_GLContext	GUI::getGLContext() { return (this->glContext); }
ImVec4			GUI::getClearColor() { return (this->clearColor); }


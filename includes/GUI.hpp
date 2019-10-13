#ifndef GUI_HPP
# define GUI_HPP

#include "imgui.h"
#include "imgui_impl_sdl.h"
#include "imgui_impl_opengl3.h"
#include <stdio.h>
#include <SDL.h>


#include "IMonitorModule.hpp"
#include "HostnameModule.hpp"
#include "UsernameModule.hpp"
#include "OSVersionModule.hpp"
#include "DateTimeModule.hpp"

#if defined(IMGUI_IMPL_OPENGL_LOADER_GL3W)
#include <GL/gl3w.h>    // Initialize with gl3wInit()
#elif defined(IMGUI_IMPL_OPENGL_LOADER_GLEW)
#include <GL/glew.h>    // Initialize with glewInit()
#elif defined(IMGUI_IMPL_OPENGL_LOADER_GLAD)
#include <glad/glad.h>  // Initialize with gladLoadGL()
#else
#include IMGUI_IMPL_OPENGL_LOADER_CUSTOM
#endif

class GUI
{
private:
	SDL_Window		*window;
	SDL_GLContext	gl_context;
	ImVec4 			clearColor;
	UsernameModule 	imd;
	OSVersionModule osv;
	HostnameModule 	htm;
	DateTimeModule 	dtm;
public:
	GUI();
	~GUI();
	SDL_Window		*getWindow();
	SDL_GLContext	getGLContext();
	ImVec4			getClearColor();
	void			drawInterface();
	void			renderInterface();

};



#endif

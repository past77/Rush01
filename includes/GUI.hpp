#ifndef GUI_HPP
# define GUI_HPP

#include "imgui.h"
#include "imgui_impl_sdl.h"
#include "imgui_impl_opengl3.h"
#include <stdio.h>
#include <SDL.h>


#include "IMonitorModule.hpp"
#include "IMonitorDisplay.hpp"
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

class GUI: public IMonitorDisplay
{
private:
	SDL_Window		*window;
	SDL_GLContext	glContext;
	ImVec4 			clearColor;
	bool			running;

	UsernameModule 	imd;
	OSVersionModule osv;
	HostnameModule 	htm;
	DateTimeModule 	dtm;
public:
	GUI();
	~GUI();
	GUI(GUI const &);
	GUI &operator =(GUI const &);

	SDL_Window		*getWindow();
	SDL_GLContext	getGLContext();
	ImVec4			getClearColor();
	void			drawInterface();
	void			renderInterface();
	void			mainloop();
	void			events();
	void			update();
	void			render();
};

#endif

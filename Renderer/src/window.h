#pragma once
#include "glfw/include/GLFW/glfw3.h"


static int m_glfwinit;


namespace Vulkan_R
{ 
	struct WinData
	{
		uint32_t Width, Height;
		WinData(uint32_t width =720, uint32_t height=720)
			:Width(width), Height(height){}
	};

class Window
{
public:
	Window(const WinData& Settings);
	void init(const WinData& Settings);
	void OnEvent();
	void ShutdownWin();
	void OnUpdate();
private:
	GLFWwindow* m_Window;


 };
}
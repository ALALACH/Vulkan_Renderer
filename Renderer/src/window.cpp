#include "window.h"
#include "log.h"


namespace Vulkan_R
{
	Window::Window(const WinData& Settings)
	{
		init(Settings);
	}
	void Window::init(const WinData& Settings)
	{
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		m_glfwinit = glfwInit();
		SE_ASSERT(m_glfwinit, "Window not Initiated");
		m_Window =glfwCreateWindow(Settings.Width, Settings.Height, "VulkanWindow", nullptr, nullptr);
	}
	void Window::OnUpdate()
	{
		while (!glfwWindowShouldClose(m_Window))
		{
			glfwPollEvents();
		}
	}
	void Window::ShutdownWin()
	{
		glfwDestroyWindow(m_Window);
		glfwTerminate();
	}

}
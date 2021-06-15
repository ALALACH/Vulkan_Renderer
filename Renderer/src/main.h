#pragma once
#include "Core.h"
#include <iostream>

#include "window.h"

#include "glm/glm/mat4x4.hpp"
#include "glm/glm/vec4.hpp"

#include <glfw/include/GLFW/glfw3.h>
#include <VulkanSDK/1.2.170.0/Include/vulkan/vulkan.h>
#define GLFW_INCLUDE_VULKAN

#ifdef vulkan_windows

int main(int argc, char** argv)
{
	bool m_Running = true;
	Vulkan_R::Window* VulkanWindow = new Vulkan_R:: Window({ 1270,720 });
	while (m_Running)
	{ 
		VulkanWindow->OnUpdate();
	}
	VulkanWindow->ShutdownWin();

	return 0;
}
#endif
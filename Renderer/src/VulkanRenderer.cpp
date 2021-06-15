#include "VulkanRenderer.h"
#include "glfw/include/GLFW/glfw3.h"
#include <vector>
#include <iostream>

namespace Vulkan_R
{

	void VulkanRenderer::InitVulkan()
	{
		CreateInstance();
	}

	void VulkanRenderer::CreateInstance()
	{
		//app info
		VkApplicationInfo appinfo{};
		appinfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		appinfo.pApplicationName = "Renderer";
		appinfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
		appinfo.pEngineName = "vulkan_renderer";
		appinfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
		appinfo.apiVersion = VK_API_VERSION_1_0;

		//instance info
		VkInstanceCreateInfo createinfo{};
		createinfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		createinfo.pApplicationInfo = &appinfo;

		//Glfw Extention
		uint32_t glfwExtensionCount = 0;
		const char** glfwExtensions;
		glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
		SE_ASSERT(glfwExtensions, "failed to get extension")
		createinfo.enabledExtensionCount = glfwExtensionCount;
		createinfo.ppEnabledExtensionNames = glfwExtensions;
		
		//global validation Layer
		createinfo.enabledLayerCount = 0;

		//createinstance
		VkResult result = vkCreateInstance(&createinfo, nullptr, &m_instance);
		SE_ASSERT(result, "failed to create instance");

		//going through extentions
		uint32_t extensionCount = 0;
		std::vector<VkExtensionProperties> extensions(extensionCount);
		vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());

#ifdef SE_DEBUG
		std::cout << "available extensions:\n";
		
			 for (const auto& extension : extensions) 
			 {
			 std::cout << '\t' << extension.extensionName << '\n';
			 }
#endif


	}
 }
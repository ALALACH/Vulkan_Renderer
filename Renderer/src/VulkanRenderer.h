#pragma once
#include "VulkanSDK/1.2.170.0/Include/vulkan/vulkan.h"
#include "Core.h"

namespace Vulkan_R
{
	class VulkanRenderer
	{
	public:
		void InitVulkan();
		void CreateInstance();



	private:
		VkInstance m_instance;

	};
}
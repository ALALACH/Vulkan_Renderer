workspace "Vulkan-Redenderer"
	architecture "x64"
	targetdir "build"
	startproject "App"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

--includeDir init
IncludeDir = {}
IncludeDir["glfw"] = "Renderer/Dependency/glfw"
IncludeDir["imgui"] = "Renderer/Dependency/imgui"
IncludeDir["spdlog"] = "Renderer/Dependency/spdlog"
IncludeDir["glm"]= 	"Renderer/Dependency/glm" 
IncludeDir["VulkanSDK"]  = "Renderer/Dependency/VulkanSDK"          


group "Dependency"
include "Renderer/Dependency/glfw"
include "Renderer/Dependency/imgui"
--include "Renderer/Dependency/glm"            --requires premake file

group "Source"
project "Renderer"
	location "Renderer"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	--pchheader "PCH.h"
	--pchsource "Renderer/src/PCH.cpp"

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/Dependency",
		"%{IncludeDir.glfw}",
		"%{IncludeDir.imgui}",
		"%{IncludeDir.spdlog}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.VulkanSDK}"
	}

	files 
	{ 
		"%{prj.name}/src/**.h", 
		"%{prj.name}/src/**.c", 
		"%{prj.name}/src/**.hpp", 
		"%{prj.name}/src/**.cpp"
	}

	links 
	{ 
		"glfw",
		"imgui"
	}

	filter "system:windows"
	systemversion "latest"
	
	defines 
	{ 
		"vulkan_windows",
		"_CRT_SECURE_NO_WARNINGS"
	}

	filter "configurations:Debug"
		defines "SE_DEBUG"
		symbols "On"
				
	filter "configurations:Release"
		defines "SE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SE_DIST"
		optimize "On"





group "Client"
project "App"
	location "App"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	links 
	{ 
		"Renderer"
	}
	
	includedirs
	{
		"%{prj.name}/src",
		"Renderer/src",
		"Renderer/Dependency"
	}
	
	files 
	{ 
		"%{prj.name}/src/**.h", 
		"%{prj.name}/src/**.c", 
		"%{prj.name}/src/**.hpp", 
		"%{prj.name}/src/**.cpp" 
	}

	filter "system:windows"
		systemversion "latest"
				
		defines 
		{ 
			"vulkan_windows",
		"_CRT_SECURE_NO_WARNINGS"
		}
	
	filter "configurations:Debug"
		defines "SE_DEBUG"
		symbols "on"

	filter "configurations:Release"
		defines "SE_RELEASE"
		optimize "on"

	filter "configurations:Dist"
		defines "SE_DIST"
		optimize "on"
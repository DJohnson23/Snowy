workspace "Snowy"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Snowy/vendor/GLFW/include"
IncludeDir["Glad"] = "Snowy/vendor/Glad/include"
IncludeDir["ImGui"] = "Snowy/vendor/imgui"
IncludeDir["glm"] = "Snowy/vendor/glm"


include "Snowy/vendor/GLFW"
include "Snowy/vendor/Glad"
include "Snowy/vendor/imgui"


project "Snowy"
	location "Snowy"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "snpch.h"
	pchsource "Snowy/src/snpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"SN_PLATFORM_WINDOWS",
			"SN_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "SN_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "SN_RELEASE"
		runtime "Release"
		optimize "On"


	filter "configurations:Dist"
		defines "SN_DIST"
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"Snowy/vendor/spdlog/include",
		"Snowy/src",
		"Snowy/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Snowy"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"SN_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "SN_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "SN_RELEASE"
		runtime "Release"
		optimize "On"


	filter "configurations:Dist"
		defines "SN_DIST"
		runtime "Release"
		optimize "On"

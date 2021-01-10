workspace "Snowy"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Snowy"
	location "Snowy"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "snpch.h"
	pchsource "Snowy/src/snpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"SN_PLATFORM_WINDOWS",
			"SN_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "SN_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SN_RELEASE"
		optimize "On"


	filter "configurations:Dist"
		defines "SN_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

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
		"Snowy/src"
	}

	links
	{
		"Snowy"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"SN_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "SN_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SN_RELEASE"
		optimize "On"


	filter "configurations:Dist"
		defines "SN_DIST"
		optimize "On"
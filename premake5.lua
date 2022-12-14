workspace "Gravity"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	startproject "Sandbox-Application"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Gravity"
	location "Gravity"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Gravity/3rdParty/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"GVT_PLATFORM_WINDOWS",
			"GVT_BUILD_DLL"
		}

	filter "configurations:Debug"
		defines "GVT_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "GVT_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "GVT_DIST"
		symbols "On"



 project "Sandbox-Application"
	location "Sandbox-Application"
	kind "ConsoleApp"
	language "C++"

	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Gravity/3rdParty/spdlog/include",
		"Gravity/src"
	}

	links
	{
		"Gravity"
	}

	postbuildcommands
	{
		("{COPY} ../bin/" .. outputdir .. "/Gravity/Gravity.dll ../bin/" .. outputdir .. "/Sandbox-Application")
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"GVT_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "GVT_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "GVT_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "GVT_DIST"
		symbols "On"

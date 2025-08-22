workspace "Saffran"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Saffran"
	location "Saffran"
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
		"%{prj.name}/vendor/spdlog/include"
	}

	
	buildoptions 
	{
		"/utf-8"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0"

		defines
		{
			"SF_PLATFORM_WINDOWS",
			"SF_BUILD_DLL"
		}

	filter "configurations:Debug"
		defines "SF_DEBUG"
		symbols "On"

	filter "configurations:Debug"
		defines "SF_RELEASE"
		optimize "On"

	filter "configurations:Debug"
		defines "SF_DIST"
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
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Saffran/vendor/spdlog/include",
		"Saffran/src"
	}

	links
	{
		"Saffran"
	}

	prebuildcommands
	{
		("{COPY} ../bin/" .. outputdir .. "/Saffran/Saffran.dll %{cfg.targetdir}")
	}

	buildoptions 
	{
		"/utf-8"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0"

		defines
		{
			"SF_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "SF_DEBUG"
		symbols "On"

	filter "configurations:Debug"
		defines "SF_RELEASE"
		optimize "On"

	filter "configurations:Debug"
		defines "SF_DIST"
		optimize "On"
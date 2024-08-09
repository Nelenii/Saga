workspace "Saga"

	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Distribution"
	}



outputDirectory = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Saga"

	location "Saga"
	kind "SharedLib"
	language "C++"
	targetdir ("binaries/" .. outputDirectory .. "/%{prj.name}")
	objdir ("intermediate/" .. outputDirectory .. "/%{prj.name}")

	files
	{
		"%{prj.name}/source/**.h",
		"%{prj.name}/source/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/source",
		"%{prj.name}/thirdparty/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"SAGA_PLATFORM_WINDOWS",
			"SAGA_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../binaries/" .. outputDirectory .. "/GameTemplate")
		}

	filter "configurations:Debug"
		symbols "On"

		defines 
		{
			"SAGA_DEBUG"
		}

	filter "configurations:Release"
		optimize "On"

		defines 
		{
			"SAGA_RELEASE"
		}

	filter "configurations:Distribution"
		optimize "On"

		defines 
		{
			"SAGA_DISTRIBUTION"
		}



project "GameTemplate"

	location "GameTemplate"
	kind "ConsoleApp"
	language "C++"
	targetdir ("binaries/" .. outputDirectory .. "/%{prj.name}")
	objdir ("intermediate/" .. outputDirectory .. "/%{prj.name}")

	files
	{
		"%{prj.name}/source/**.h",
		"%{prj.name}/source/**.cpp"
	}

	includedirs
	{
		"Saga/thirdparty/spdlog/include",
		"Saga/source"
	}

	links
	{
		"Saga"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"SAGA_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		symbols "On"

		defines 
		{
			"SAGA_DEBUG"
		}

	filter "configurations:Release"
		optimize "On"

		defines 
		{
			"SAGA_RELEASE"
		}

	filter "configurations:Distribution"
		optimize "On"

		defines 
		{
			"SAGA_DISTRIBUTION"
		}

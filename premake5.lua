-- Some global constants for common folder locations
local WORKSPACE_DIR = "./workspaces/" -- path to IDE projects
local BUILD_DIR = "./build/" -- path where all artifacts are sent to

workspace "CrystallineBox"
    location (WORKSPACE_DIR .. _ACTION) -- one directory per IDE
    configurations { "Debug", "FastDebug", "Live++", "Release", "Retail" }
    platforms { "x64" }

project "CrystallineBox"
    targetname "CrystallineBox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++11"
    systemversion "latest" -- to use latest windows SDK (VS17 defaulted to 8.1 SDK in my case)
    entrypoint "mainCRTStartup"
    targetdir(BUILD_DIR .. "/crystalline_box/%{cfg.buildcfg}")
    debugdir("./")

---------------------------
-- Compiler/Linker settings
---------------------------
    flags "FatalWarnings" -- All warnings on.

    filter "platforms:x64"
        architecture "x64"

    filter { "configurations:Debug" }
        defines { "DEBUG" }
        symbols "Full"
        optimize "Off"
		
    filter { "configurations:FastDebug" }
        defines { "DEBUG" }
        symbols "Full"
        optimize "On"

    filter "configurations:Release"
        defines { "RELEASE", "NDEBUG" }
        symbols "Full"
        optimize "Full"

    filter "configurations:Retail"
        defines { "RETAIL", "NDEBUG" }
        symbols "Off"
        optimize "Full"

    filter {}

-----------------------------
-- Add sourcetree to project
-----------------------------

local SRC_DIR = "./src/" -- path to all source files
local LIB_DIR = "./libs/" -- path to all external dependencies

files
{
    SRC_DIR .. "**.h",
    SRC_DIR .. "**.hpp",
    SRC_DIR .. "**.cpp"
}

local VULKAN_SDK_DIR = os.getenv("VULKAN_SDK_DIR") -- path to the LunarG Vulkan SDK

if VULKAN_SDK_DIR ~= nil then
	includedirs { VULKAN_SDK_DIR .. "Include\\" }
	libdirs { VULKAN_SDK_DIR .. "Lib\\" }
	links { "vulkan-1" }
else
	error("Could not find the path to the vulkan sdk - please check if the VULKAN_SDK_DIR environment variable is set to the correct path!")
end

local LPP_DIR = os.getenv("LPP_DIR") -- path to the folder where Live++ lives (if this is set we create a new build configuration for a LPP enabled debug build)

if LPP_DIR ~= nil then
	---------------------------------------
	-- Live++ only in debug builds for now
	---------------------------------------
    filter { "configurations:Live++" }
        defines { "DEBUG", "LPP" }
        symbols "Full"
        optimize "Off"
		includedirs { LPP_DIR }
		
		functionlevellinking  "On" -- Enable function level linking (wraps functions in own COMDATs and simplifies COMDAT folding)
		buildoptions { "/Zi /Gw" } -- Enable the creation of .pdb's (not for MSVC's edit and continue) and enable 'Global data optimization' (also own COMDATs for the data) 
		linkoptions { "/FUNCTIONPADMIN", "/OPT:NOREF", "/OPT:NOICF" }
		-- /FUNCTIONPADMIN (hotpatchable-image) -> describes how much padding is added in front of functions (x64: 6 byte default)
		-- /OPT:NOREF -> keep COMDAT's (function and data) which are never referenced (LivePP requ.)
		-- /OPT:NOICF -> disable similar COMDAT folding for MSVC (LivePP requ.)
		
	filter {}
else
	error("Could not find the path to the lpp dir!")
end

includedirs
{
    LIB_DIR .. "**/includes",
}

libdirs
{
    LIB_DIR .. "**/%{cfg.platform}",
    LIB_DIR .. "**/%{cfg.buildcfg}",
    LIB_DIR .. "**/%{cfg.buildcfg}/%{cfg.platform}",
    LIB_DIR .. "**/%{cfg.platform}/%{cfg.buildcfg}",
}

-- Create a custom clean action
newaction {
    trigger = "clean",
    description = "clean the workspace folder",
    execute     = function () 
        print "Remove build artifacts and ./workspaces/*"
        os.rmdir "./workspaces"
        os.rmdir "./build"
        print "Finished cleanup!"
    end
}
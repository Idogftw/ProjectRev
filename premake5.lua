DIR = path.getabsolute("./")

GAME_DIR = path.getabsolute("./Rev/")
GAME_SRC = path.join(GAME_DIR, "main/")
GAME_OUTPUT = path.join(GAME_DIR, "bin/")

ENGINE_DIR = path.getabsolute("./Gateway/")
ENGINE_SRC = path.join(ENGINE_DIR, "main/")
ENGINE_OUTPUT = path.join(ENGINE_DIR, "bin/")

BINARY_DIR = path.join(ENGINE_DIR, "binary/")

workspace "ProjectRev-SLN"
    -- SLN Data --
    location(DIR)
    configurations { "Debug", "Release" }
    platforms "x64"
    language "C++"

    cppdialect "C++17"

    startproject "Rev"

    -- Implement other APIs and add if for defines --
    defines {
        "_CRT_SECURE_NO_WARNINGS"
    }
    
    if os.target() == "windows" then
        defines "win32"
    end

    if os.target() == "linux" then
        defines "linux"
    end

    if os.target() == "macosx" then
        defines "macos"
    end

    configuration "Debug"
        defines "GW_DEBUG"
        symbols "On"
        warnings "Extra"

    configuration "Release"
        defines "GW_RELEASE"
        optimize "On"

    project "Gateway"
        location (ENGINE_SRC)
        kind "StaticLib"
        language "C++"

        debugdir (path.join(GAME_OUTPUT, "dev/Debug"))

        -- Multi Use libs --
        
        libdirs {
            path.join(BINARY_DIR, "DevIL/lib/x64/Release")
        }

        links {
            "DevIL",
            "ILU",
            "ILUT",
            "libfbxsdk",
            "opengl32.lib"
        }

        -- Project Files --

        includedirs {
            path.join(ENGINE_SRC, "include/"),
            -- Dependencies --
            path.join(BINARY_DIR, "glad/include/"),
            path.join(BINARY_DIR, "nlohmann/"),
            path.join(BINARY_DIR, "DevIL/include/"),
            path.join(BINARY_DIR, "fbx/include/")
        }


        files {
            path.join(ENGINE_SRC, "src/**.cpp"),
            path.join(ENGINE_SRC, "include/**.hpp"),
            path.join(ENGINE_SRC, "include/**.h"),
            -- Dependencies --
            path.join(BINARY_DIR, "glad/**"),
            path.join(BINARY_DIR, "nlohmann/*.hpp")
        }

        configuration {"Debug", "x64"}
            targetdir(path.join(ENGINE_OUTPUT, "lib/Debug"))
            objdir(path.join(ENGINE_OUTPUT, "obj/Debug"))
            libdirs {
                path.join(BINARY_DIR, "fbx/lib/debug")
            }
        
        configuration {"Release", "x64"}
            targetdir(path.join(ENGINE_OUTPUT, "lib/Release"))
            objdir(path.join(ENGINE_OUTPUT, "obj/Release"))            
            libdirs {
                path.join(BINARY_DIR, "fbx/lib/release")
            }

    project "Rev"
        location (GAME_SRC)
        kind "WindowedApp"
        language "C++"

        links("Gateway")

        includedirs {
            path.join(GAME_SRC, "include/"),
            path.join(ENGINE_SRC, "include/"),
            -- Dependencies --
            path.join(BINARY_DIR, "glad/include/"),
            path.join(BINARY_DIR, "nlohmann/"),
            path.join(BINARY_DIR, "DevIL/include/")
        }
        
        files {
            path.join(GAME_SRC, "src/**.cpp"),
            path.join(GAME_SRC, "include/**.hpp"),
            path.join(GAME_SRC, "include/**.h")
        }

        configuration {"Debug", "x64"}
            targetdir(path.join(GAME_OUTPUT, "dev/Debug"))
            objdir(path.join(GAME_OUTPUT, "obj/Debug"))

            libdirs(path.join(ENGINE_OUTPUT, "lib/Debug"))

        configuration {"Release", "x64"} 
            targetdir(path.join(GAME_OUTPUT, "dev/Release"))
            objdir(path.join(GAME_OUTPUT, "obj/Release"))

            libdirs(path.join(ENGINE_OUTPUT, "lib/Release"))

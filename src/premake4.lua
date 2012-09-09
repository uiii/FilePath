project "FilePath"
    kind "StaticLib"
    language "C++"

    targetdir "../lib"

    includedirs { "./" }
    includedirs { "../include/FilePath" }

    --links {
    --}

    --require_pkg_config()
    --require_pkg(...)

    configuration { "linux or bsd or solaris" }
        files {
            "SystemPath_unix.cpp"
        }

    --configuration { "windows" }

    files {
        "FilePath.cpp",
        "Environment.cpp"
    }

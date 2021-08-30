#!/usr/bin/env python
import os
import sys

# Try to detect the host platform automatically.
# This is used if no `platform` argument is passed
if sys.platform.startswith("linux"):
    host_platform = "linux"
elif sys.platform == "darwin":
    host_platform = "macos"
elif sys.platform == 'win32' or sys.platform == 'msys':
    host_platform = 'windows'
else:
    raise ValueError("Could not detect platform automatically, please specify with " "platform=<platform>")

env = Environment(ENV=os.environ)

opts = Variables([], ARGUMENTS)

# Define our options
opts.Add(EnumVariable("target", "Compilation target", "debug", ["d", "debug", "r", "release"]))
opts.Add(EnumVariable("platform", "Compilation platform", host_platform, ["", "linux", "macos", "windows"]))
opts.Add(
    EnumVariable("p", "Compilation target, alias for 'platform'", host_platform, ["", "linux", "macos", "windows"])
)
opts.Add(EnumVariable("arch", "Target platform architecture", "x86_64", ("aarch64", "x86_64")))
opts.Add(BoolVariable(
    'use_mingw',
    'Use the MinGW compiler instead of MSVC - only effective on Windows',
    False
))

# Local dependency paths, adapt them to your setup
godot_headers_path = "/Users/bruv/Projects/godot-cpp/godot-headers/"
cpp_bindings_path = "/Users/bruv/Projects/godot-cpp/"
cpp_library = "libgodot-cpp"
target_name = "ts_test"

# Updates the environment with the option variables.
opts.Update(env)
# Generates help for the -h scons option.
Help(opts.GenerateHelpText(env))

# Process some arguments
if env["p"] != "":
    env["platform"] = env["p"]

if env["platform"] == "":
    print("No valid target platform selected.")
    quit()

if env["target"] == "debug":
    env.Append(CPPDEFINES=["DEBUG_ENABLED", "DEBUG_METHODS_ENABLED"])

# Check our platform specifics
if env["platform"] == "macos":
    cpp_library += ".osx"
    env.Append(CCFLAGS=["-arch", "arm64"])
    env.Append(CXXFLAGS=["-std=c++17"])
    env.Append(LINKFLAGS=["-arch", "arm64"])
    if env["target"] in ("debug", "d"):
        env.Append(CCFLAGS=["-g", "-O2"])
    else:
        env.Append(CCFLAGS=["-g", "-O3"])
    target_name = "ts_test.framework/Versions/A/ts_test"
    env['SHLIBPREFIX'] = ''
    env['SHLIBSUFFIX'] = ''

elif env["platform"] == "linux":
    cpp_library += ".linux"
    env.Append(CCFLAGS=["-fPIC", "-arch", env["arch"]])
    env.Append(CXXFLAGS=["-std=c++17"])
    env.Append(LINKFLAGS=["-arch", env["arch"]])
    if env["target"] in ("debug", "d"):
        env.Append(CCFLAGS=["-g3", "-Og"])
    else:
        env.Append(CCFLAGS=["-g", "-O3"])
    target_name = "ts_test." + env["arch"]

elif env['platform'] == 'windows':
    if host_platform == 'windows' and not env['use_mingw']:
        # MSVC
        env.Append(LINKFLAGS=['/WX'])
        if env['target'] == 'debug':
            env.Append(CCFLAGS=['/Z7', '/Od', '/EHsc', '/D_DEBUG', '/MDd'])
        elif env['target'] == 'release':
            env.Append(CCFLAGS=['/O2', '/EHsc', '/DNDEBUG', '/MD'])

    elif host_platform == 'linux' or host_platform == 'freebsd' or host_platform == 'osx':
        # Cross-compilation using MinGW
        env['CXX'] = 'x86_64-w64-mingw32-g++'
        env['AR'] = "x86_64-w64-mingw32-ar"
        env['RANLIB'] = "x86_64-w64-mingw32-ranlib"
        env['LINK'] = "x86_64-w64-mingw32-g++"

    # Native or cross-compilation using MinGW
    if env['use_mingw']:
        # These options are for a release build even using target=debug
        env.Append(CCFLAGS=['-O3', '-std=c++14', '-Wwrite-strings'])
        env.Append(LINKFLAGS=[
            '--static',
            '-Wl,--no-undefined',
            '-static-libgcc',
            '-static-libstdc++',
        ])
    target_name = "ts_test.x86_64"

if env["target"] in ("debug", "d"):
    cpp_library += ".debug"
else:
    cpp_library += ".release"

cpp_library += ".64"

# make sure our binding library is properly includes
env.Append(CPPPATH=["src", godot_headers_path, cpp_bindings_path + "include/", cpp_bindings_path + "gen/include/", "thirdparty/freetype/include/", "thirdparty/harfbuzz/src/", "thirdparty/icu4c/common/"])
env.Append(LIBPATH=[cpp_bindings_path + "bin/"])
env.Append(LIBS=[cpp_library])

sources = Glob("src/*.cpp")

library = env.SharedLibrary(target="demo/addons/ts_test/bin/" + target_name, source=sources)

Default(library)

@echo off
cls
del *.obj *.ilk *.pdb *.exe

REM IMGUI
rem cl /nologo /Zi /MDd /EHs /W4 /DSFML_STATIC /c -I ../include -I ../deps/sfml/x86/include -I ../deps/imgui -I ../deps/imgui-SFML ../deps/imgui/imgui.cpp
rem cl /nologo /Zi /MDd /EHs /W4 /DSFML_STATIC /c -I ../include -I ../deps/sfml/x86/include -I ../deps/imgui -I ../deps/imgui-SFML ../deps/imgui/imgui_demo.cpp
rem cl /nologo /Zi /MDd /EHs /W4 /DSFML_STATIC /c -I ../include -I ../deps/sfml/x86/include -I ../deps/imgui -I ../deps/imgui-SFML ../deps/imgui/imgui_draw.cpp
rem cl /nologo /Zi /MDd /EHs /W4 /DSFML_STATIC /c -I ../include -I ../deps/sfml/x86/include -I ../deps/imgui -I ../deps/imgui-SFML ../deps/imgui/imgui_tables.cpp
rem cl /nologo /Zi /MDd /EHs /W4 /DSFML_STATIC /c -I ../include -I ../deps/sfml/x86/include -I ../deps/imgui -I ../deps/imgui-SFML ../deps/imgui/imgui_widgets.cpp

REM IMGUI-SFML
rem cl /nologo /Zi /MDd /EHs /W4 /DSFML_STATIC /c -I ../include -I ../deps/sfml/x86/include -I ../deps/imgui -I ../deps/imgui-SFML ../deps/imgui-SFML/imgui-SFML.cpp

cl /nologo /Zi /MDd /EHs /W4 /DSFML_STATIC /c -I ../include -I ../deps/sfml/x86/include -I ../deps/imgui -I ../deps/imgui-SFML ../src/*.cc

cl /nologo /Zi /MDd /EHs /W4 /Fe: ..\bin\main.exe *.obj ../deps/sfml/x86/lib/sfml-system-s-d.lib ../deps/sfml/x86/lib/sfml-window-s-d.lib ../deps/sfml/x86/lib/sfml-graphics-s-d.lib ../deps/sfml/x86/lib/freetype.lib winmm.lib opengl32.lib shell32.lib gdi32.lib user32.lib advapi32.lib

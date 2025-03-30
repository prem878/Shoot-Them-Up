@echo off
echo Building project...

gcc src\main.c -o main.exe -Iinclude -Llib -lSDL2main -lSDL2

if errorlevel 1 (
    echo Compilation failed.
    pause
    exit /b 1
) else (
	echo Compilation Successful.
    echo Copying SDL2.dll...
    copy lib\SDL2.dll .  >nul 2>&1
    echo Running main.exe...
    main.exe
)

pause
exit /b 0

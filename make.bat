taskkill /f /im MineSweeperTetris.exe
del *.exe
del .\sdk\tools\ContentBuilder\builder\dumps\*.dmp
rmdir release /s /q
for /f "tokens=2 delims==" %%G in ('wmic os get localdatetime /value') do set datetime=%%G
set version=%datetime:~0,8%
echo const char* version = "%version%"; > version.h
copy icon.rc icon_.rc
powershell -Command "(Get-Content icon_.rc).replace('xxxxxxxx', '%version%') | Set-Content icon_.rc"
mingw32\bin\windres -F pe-i386 -i icon_.rc -O coff -o icon32.res
mingw64\bin\windres -F pe-x86-64 -i icon_.rc -O coff -o icon64.res
:again
cls
mingw32\bin\g++ -Wall -static -Os -s main.cpp icon32.res -o MineSweeperTetris_32.exe -lwinmm -lgdiplus -lgdi32 -lmsimg32 -lsteam_api -mwindows
mingw64\bin\g++ -Wall -static -Os -s main.cpp icon64.res -o MineSweeperTetris_64.exe -lwinmm -lgdiplus -lgdi32 -lmsimg32 -lsteam_api -mwindows
mingw32\bin\g++ -Wall -static -Os -g main.cpp icon32.res -o MineSweeperTetris_debug_32.exe -lwinmm -lgdiplus -lgdi32 -lmsimg32 -lsteam_api -mwindows
mingw64\bin\g++ -Wall -static -Os -g main.cpp icon64.res -o MineSweeperTetris_debug_64.exe -lwinmm -lgdiplus -lgdi32 -lmsimg32 -lsteam_api -mwindows
if not exist MineSweeperTetris_32.exe goto fail
mkdir release32
mkdir release64
copy MineSweeperTetris_32.exe release32\MineSweeperTetris.exe
copy MineSweeperTetris_64.exe release64\MineSweeperTetris.exe
copy steam_api.dll release32\steam_api.dll
copy steam_api64.dll release64\steam_api64.dll
xcopy png\* release32\png\ /y /r /s
xcopy png\* release64\png\ /y /r /s
xcopy wav\* release32\wav\ /y /r /s
xcopy wav\* release64\wav\ /y /r /s
xcopy mid\* release32\mid\ /y /r /s
xcopy mid\* release64\mid\ /y /r /s
xcopy lan\* release32\lan\ /y /r /s
xcopy lan\* release64\lan\ /y /r /s
rmdir sdk\tools\ContentBuilder\content /s /q
mkdir sdk\tools\ContentBuilder\content
xcopy release32\* sdk\tools\ContentBuilder\content\ /y /r /e
sdk\tools\ContentBuilder\content\MineSweeperTetris.exe
goto end
:fail
pause
goto :again
:end
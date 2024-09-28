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
mingw32\bin\g++ -Wall -static -Os -s main.cpp icon32.res -o MineSweeperTetris_32.exe -lwinmm -lgdiplus -lgdi32 -lmsimg32 -lsteam_api -mwindows
mingw64\bin\g++ -Wall -static -Os -s main.cpp icon64.res -o MineSweeperTetris_64.exe -lwinmm -lgdiplus -lgdi32 -lmsimg32 -lsteam_api -mwindows
mingw32\bin\g++ -Wall -static -Os -g main.cpp icon32.res -o MineSweeperTetris_debug_32.exe -lwinmm -lgdiplus -lgdi32 -lmsimg32 -lsteam_api -mwindows
mingw64\bin\g++ -Wall -static -Os -g main.cpp icon64.res -o MineSweeperTetris_debug_64.exe -lwinmm -lgdiplus -lgdi32 -lmsimg32 -lsteam_api -mwindows
copy MineSweeperTetris_32.exe MineSweeperTetris.exe
if not exist MineSweeperTetris.exe goto fail
mkdir release
copy MineSweeperTetris.exe release\MineSweeperTetris.exe
copy steam_api.dll release\steam_api.dll
::copy steam_appid.txt release\steam_appid.txt
::copy disp.dll release\disp.dll
::copy MineSweeperTetris.ico release\MineSweeperTetris.ico
xcopy png\* release\png\ /y /r /s
xcopy wav\* release\wav\ /y /r /s
xcopy mid\* release\mid\ /y /r /s
xcopy lan\* release\lan\ /y /r /s
rmdir sdk\tools\ContentBuilder\content /s /q
mkdir sdk\tools\ContentBuilder\content
xcopy release\* sdk\tools\ContentBuilder\content\ /y /r /e
release\MineSweeperTetris.exe
goto end
:fail
pause
:end
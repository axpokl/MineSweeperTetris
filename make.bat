taskkill /f /im MineSweeperRush.exe
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
mingw32\bin\g++ -Wall -static -Os -s -flto=auto -fno-exceptions -save-temps main.cpp icon32.res -o MineSweeperRush_32.exe -lwinmm -lgdiplus -lgdi32 -lmsimg32 -lsteam_api -lsetupapi -mwindows
mingw64\bin\g++ -Wall -static -Os -s -flto=auto -fno-exceptions -save-temps main.cpp icon64.res -o MineSweeperRush_64.exe -lwinmm -lgdiplus -lgdi32 -lmsimg32 -lsteam_api -lsetupapi -mwindows
::mingw32\bin\g++ -Wall -static -Os -g -flto=auto -fno-exceptions -save-temps main.cpp icon32.res -o MineSweeperRush_debug_32.exe -lwinmm -lgdiplus -lgdi32 -lmsimg32 -lsteam_api -lsetupapi -mwindows
::mingw64\bin\g++ -Wall -static -Os -g -flto=auto -fno-exceptions -save-temps main.cpp icon64.res -o MineSweeperRush_debug_64.exe -lwinmm -lgdiplus -lgdi32 -lmsimg32 -lsteam_api -lsetupapi -mwindows
del *.o
del *.s
del *.out
del *.ii
del *args*
del main.res
del *_64.res
if not exist MineSweeperRush_32.exe goto fail
rmdir release32 /s /q
rmdir release64 /s /q
mkdir release32
mkdir release64
copy MineSweeperRush_32.exe release32\MineSweeperRush.exe
copy MineSweeperRush_64.exe release64\MineSweeperRush.exe
del MineSweeperRush_32.exe
del MineSweeperRush_64.exe
copy steam_api.dll release32\steam_api.dll
copy steam_api64.dll release64\steam_api64.dll
copy data.cab release32\data.cab
copy data.cab release64\data.cab
rmdir sdk\tools\ContentBuilder\content /s /q
mkdir sdk\tools\ContentBuilder\content
xcopy release32\* sdk\tools\ContentBuilder\content\ /y /r /e
rmdir test /s /q
mkdir test
xcopy release32\* test /y /r /e
copy steam_appid.txt test\steam_appid.txt
cd test
MineSweeperRush.exe
goto end
:fail
pause
goto :again
:end
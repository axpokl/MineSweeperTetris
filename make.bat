taskkill /f /im MineSweeperTetris.exe
del *.exe
del .\sdk\tools\ContentBuilder\builder\dumps\*.dmp
rmdir release /s /q
for /f "tokens=2 delims==" %%G in ('wmic os get localdatetime /value') do set datetime=%%G
set version=%datetime:~0,8%
echo const char* version = "%version%"; > version.h
copy icon.rc icon_.rc
powershell -Command "(Get-Content icon_.rc).replace('xxxxxxxx', '%version%') | Set-Content icon_.rc"
windres -i icon_.rc -O coff -o icon.res
::g++ -static -Os -s main.cpp steam_api.lib disp.dll icon.res -o MineSweeperTetris.exe 
::g++ -static -Os -s main.cpp steam_api.lib disp.dll icon.res -o MineSweeperTetris.exe -mwindows
::g++ -static -Os -s main.cpp steam_api.lib disp.dll icon.res -o MineSweeperTetris.exe -lwinmm -lgdiplus
::g++ -static -Os -s main.cpp steam_api.lib disp.dll icon.res -o MineSweeperTetris.exe -mwindows -lwinmm -lgdiplus
g++ -static -Os -s main.cpp icon.res -o MineSweeperTetris.exe -lwinmm -lgdiplus -lgdi32 -lmsimg32 -lsteam_api -mwindows
if not exist MineSweeperTetris.exe goto fail
mkdir release
copy MineSweeperTetris.exe release\MineSweeperTetris.exe
::copy steam_appid.txt release\steam_appid.txt
copy steam_api.dll release\steam_api.dll
::copy disp.dll release\disp.dll
::copy MineSweeperTetris.ico release\MineSweeperTetris.ico
xcopy png\* release\png\ /y /r /s
xcopy wav\* release\wav\ /y /r /s
xcopy mid\* release\mid\ /y /r /s
xcopy lan\* release\lan\ /y /r /s
start release\MineSweeperTetris.exe
rmdir sdk\tools\ContentBuilder\content /s /q
mkdir sdk\tools\ContentBuilder\content
xcopy release\* sdk\tools\ContentBuilder\content\ /y /r /e
goto end
:fail
pause
:end
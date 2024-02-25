del *.exe
del .\sdk\tools\ContentBuilder\builder\dumps\*.dmp
rmdir release /s /q
windres -i icon.rc -O coff -o icon.res
::g++ -static -Os -s main.cpp steam_api.lib disp.dll icon.res -o MineSweeperTetris.exe 
g++ -static -Os -s main.cpp steam_api.lib disp.dll icon.res -o MineSweeperTetris.exe -mwindows
mkdir release
copy MineSweeperTetris.exe release\MineSweeperTetris.exe
::copy steam_appid.txt release\steam_appid.txt
copy steam_api.dll release\steam_api.dll
copy disp.dll release\disp.dll
::copy MineSweeperTetris.ico release\MineSweeperTetris.ico
xcopy png\* release\png\ /y /r /s
xcopy wav\* release\wav\ /y /r /s
xcopy mid\* release\mid\ /y /r /s
xcopy lan\* release\lan\ /y /r /s
start release\MineSweeperTetris.exe
rmdir sdk\tools\ContentBuilder\content /s /q
mkdir sdk\tools\ContentBuilder\content
xcopy release\* sdk\tools\ContentBuilder\content\ /y /r /e
pause

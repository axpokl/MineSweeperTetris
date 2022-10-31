del *.exe
rmdir release /s /q
windres -i icon.rc -O coff -o icon.res
g++ -static -Os main.cpp steam_api.lib disp.dll icon.res -o MineSweeperTetris.exe
:: -mwindows
mkdir release
copy MineSweeperTetris.exe release\MineSweeperTetris.exe
copy steam_appid.txt release\steam_appid.txt
copy steam_api.dll release\steam_api.dll
copy disp.dll release\disp.dll
xcopy bmp\* release\bmp\ /y /r
xcopy wav\* release\wav\ /y /r
start release\MineSweeperTetris.exe
rmdir sdk\tools\ContentBuilder\content /s /q
mkdir sdk\tools\ContentBuilder\content
xcopy release\* sdk\tools\ContentBuilder\content\ /y /r /e
pause

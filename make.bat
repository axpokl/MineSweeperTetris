del *.exe
rmdir release /s /q
windres -i icon.rc -O coff -o icon.res
g++ -static -Os main.cpp disp.dll icon.res -o MineSweeperTetris.exe -mwindows
::g++ -static -Os main.cpp disp.dll icon.res -o MineSweeperTetris.exe
mkdir release
copy MineSweeperTetris.exe release\MineSweeperTetris.exe
copy disp.dll release\disp.dll
xcopy bmp\* release\bmp\ /y /r
xcopy wav\* release\wav\ /y /r
start release\MineSweeperTetris.exe
rmdir sdk\tools\ContentBuilder\content /s /q
mkdir sdk\tools\ContentBuilder\content
xcopy release\* sdk\tools\ContentBuilder\content\ /y /r /e
pause

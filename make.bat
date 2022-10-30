del *.exe
rmdir release /s /q
g++ -static -Os main.cpp disp.dll -o MineSweeperTetris.exe -mwindows
mkdir release
copy MineSweeperTetris.exe release\MineSweeperTetris.exe
copy disp.dll release\disp.dll
xcopy bmp\* release\bmp\ /y /r
xcopy wav\* release\wav\ /y /r
rmdir sdk\tools\ContentBuilder\content /s /q
mkdir sdk\tools\ContentBuilder\content
xcopy release\* sdk\tools\ContentBuilder\content\ /y /r /e
start release\MineSweeperTetris.exe
pause

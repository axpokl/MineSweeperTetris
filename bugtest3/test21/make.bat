del bin\*.cpp.exe
for %%f in ("*.cpp") do g++ -o "%%~nf.cpp.exe" "%%f" disp.dll -static -Os -mwindows
pause
#include "disp.h"
pbitmap img;
int main(){
createwin(800,600);
img=loadbmp("title.png");
drawbmp(img,(getwidth()-img->width)/2,(getheight()-img->height)/2);
freshwin();
msgbox("Draw BMP Complete");
return 0;}

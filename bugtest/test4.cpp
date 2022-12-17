#include "disp.h"
pbitmap img;
int main(){
createwin();
img=loadbmp("title.png");
msgbox(i2s(img->width)+" "+i2s(img->height));
return 0;}

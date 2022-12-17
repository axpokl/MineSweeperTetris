#include "disp.h"
unsigned long n=0x1000;
int main(){
createwin();
line(10,10,100,100,red);
bar(110,10,100,100,blue);
circle(60,160,50,green);
ellipse(185,160,25,50,pink);
while(n>0)
{
setpixel(random(getwidth()),random(getheight()),random(0xffffff));
n=n-1;
}
freshwin();
msgbox("Draw Shape complete");
return 0;}

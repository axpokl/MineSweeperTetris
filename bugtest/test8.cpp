#include "disp.h"
int main(){
createwin();
do{
settitle(i2s(getmouseposx())+" "+i2s(getmouseposy()));
waitnextmsg();
if(iskey())msgbox(i2s(getkey()));
if(ismouse())msgbox(i2s(getmouse()));
if(ismousewheel())msgbox(i2s(getmousewheel()));
if(isdropfile())msgbox(getdropfile());
}while(!( !(iswin())||(iskey(27))));
return 0;}

#include "disp.h"
int main(){
createwin(320,240);
do{
isnextmsg();
clear();
drawtextxy("",0,0);
drawtextln(i2s(getmouseposx())+" "+i2s(getmouseposy()));
drawtextln(i2s(getmousewinx())+" "+i2s(getmousewiny()));
drawtextln(i2s(getmouseabsx())+" "+i2s(getmouseabsy()));
freshwin();
delay();
}while(!( !(iswin())||iskey()));
return 0;}

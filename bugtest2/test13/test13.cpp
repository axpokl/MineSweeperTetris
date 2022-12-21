#include "disp.h"
int main(){
createwin();
do{
if(isnextmsg())settitle(i2s(getnextmsg()));
else delay();
}while(!( !(iswin())||(iskey(27))));
return 0;}

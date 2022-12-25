#include "disp.h"
#include "stdio.h"


int main(){
bool b;
long d;
createwin();
do{
printf("@",b);
b = isnextmsg();
printf("#%d",b);
if(b)
{
printf("!");
d=getnextmsg();
printf("&%d\n",d);
settitle(i2s(d));
printf("$");
}
else
{
delay();
}
}while(!( !(iswin())||(iskey(27))));
return 0;}

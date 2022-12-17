#include "disp.h"
int main(){
if(iswin())msgbox("yes");else msgbox("no");
createwin();
if(iswin())msgbox("yes");else msgbox("no");
closewin();
if(iswin())msgbox("yes");else msgbox("no");
createwin();
if(iswin())msgbox("yes");else msgbox("no");
closewin();
if(iswin())msgbox("yes");else msgbox("no");
return 0;}

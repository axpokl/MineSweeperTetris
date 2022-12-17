#include "disp.h"
int main(){
createwin();
drawtextln("ax_pokl output text.");
drawtextw("ax_pokl""s text is tight");
drawtextxy("ax_pokl output text anywhere",50,50);
drawtextxy("",0,80);
drawtext("and it""s colorful ",orange);
drawtext("with backgroud color",red,blue);
freshwin();
msgbox("Draw Text Complete");
return 0;}

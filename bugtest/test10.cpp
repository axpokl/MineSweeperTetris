#include "disp.h"//使用Display单元库
const unsigned long w=10;//场地宽
const unsigned long h=20;//场地高
unsigned long sz=30;//方块大小
double frame=120.0;//帧率
double frametime=0.0;//当前帧时间
double downtime=0.0;//下落时间
char i,j;//场地行列计数
char x,y,r,k;//当前方块状态
char bd[w-1+1][h-1+1];//场地方块
const unsigned long bdc[7+1]=
{0x1f1f1f,0x7f7f7f,0x7f7fff,0x7fff7f,0xff7f7f,0x7fffff,0xffff7f,0xff7fff};//方块颜色
const unsigned long bdk[7+1][3+1][3+1][3+1]=
{
{
{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},
{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},
{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},
{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}}
},
{
{{0,0,0,0},{0,1,1,0},{0,1,1,0},{0,0,0,0}},
{{0,0,0,0},{0,1,1,0},{0,1,1,0},{0,0,0,0}},
{{0,0,0,0},{0,1,1,0},{0,1,1,0},{0,0,0,0}},
{{0,0,0,0},{0,1,1,0},{0,1,1,0},{0,0,0,0}}
},
{
{{0,0,0,0},{2,2,2,2},{0,0,0,0},{0,0,0,0}},
{{0,0,2,0},{0,0,2,0},{0,0,2,0},{0,0,2,0}},
{{0,0,0,0},{2,2,2,2},{0,0,0,0},{0,0,0,0}},
{{0,0,2,0},{0,0,2,0},{0,0,2,0},{0,0,2,0}}
},
{
{{0,0,0,0},{0,0,3,3},{0,3,3,0},{0,0,0,0}},
{{0,0,3,0},{0,0,3,3},{0,0,0,3},{0,0,0,0}},
{{0,0,0,0},{0,0,3,3},{0,3,3,0},{0,0,0,0}},
{{0,0,3,0},{0,0,3,3},{0,0,0,3},{0,0,0,0}}
},
{
{{0,0,0,0},{0,4,4,0},{0,0,4,4},{0,0,0,0}},
{{0,0,0,4},{0,0,4,4},{0,0,4,0},{0,0,0,0}},
{{0,0,0,0},{0,4,4,0},{0,0,4,4},{0,0,0,0}},
{{0,0,0,4},{0,0,4,4},{0,0,4,0},{0,0,0,0}}
},
{
{{0,0,0,0},{0,5,5,5},{0,5,0,0},{0,0,0,0}},
{{0,0,5,0},{0,0,5,0},{0,0,5,5},{0,0,0,0}},
{{0,0,0,5},{0,5,5,5},{0,0,0,0},{0,0,0,0}},
{{0,5,5,0},{0,0,5,0},{0,0,5,0},{0,0,0,0}}
},
{
{{0,0,0,0},{0,6,6,6},{0,0,0,6},{0,0,0,0}},
{{0,0,6,6},{0,0,6,0},{0,0,6,0},{0,0,0,0}},
{{0,6,0,0},{0,6,6,6},{0,0,0,0},{0,0,0,0}},
{{0,0,6,0},{0,0,6,0},{0,6,6,0},{0,0,0,0}}
},
{
{{0,0,0,0},{0,7,7,7},{0,0,7,0},{0,0,0,0}},
{{0,0,7,0},{0,0,7,7},{0,0,7,0},{0,0,0,0}},
{{0,0,7,0},{0,7,7,7},{0,0,0,0},{0,0,0,0}},
{{0,0,7,0},{0,7,7,0},{0,0,7,0},{0,0,0,0}}
}
};//方块类型

void drawblock(char i,char j,char k)//画方块
{ bar(i*sz,(h-j-1)*sz,sz,sz,bdc[k]);}

void newblock();//新方块

void restart()//重新开始
{
for(i=0;i<=w-1;i++)for(j=0;j<=h-1;j++)bd[i][j]=0;//清空场地
newblock();//新方块
}

bool eraseline()//消行
{bool eraseline_r;
for(j=0;j<=h-1;j++)//从最底行开始
{
eraseline_r=true;//是满行
for(i=0;i<=w-1;i++)if(bd[i][j]==0)eraseline_r=false;//如果有洞则不是
if(eraseline_r)break;//如果是满行则跳出
}
if(eraseline_r)//如果是满行（消行）
while(j<(h-1))//从此行开始（往上）
{
for(i=0;i<=w-1;i++)//遍历该行
bd[i][j]=bd[i][j+1];//上方方块掉落
j=j+1;//继续上一行
}
return eraseline_r;}

void fixblock()//固定方块（落底）
{
for(i=0;i<=3;i++)for(j=0;j<=3;j++)//遍历方块行列
if(bdk[k][r][j][i]>0)bd[i+x][j+y]=k;newblock();//如果是格子非空则画到场地
while(eraseline());//消行
}

bool overlay()//判断重叠
{bool overlay_r;
overlay_r=false;//设非重叠
for(i=0;i<=3;i++)for(j=0;j<=3;j++)//遍历方块行列
if((bdk[k][r][j][i]>0))//如果格子非空
if((i+x<0)||(i+x>=w)||(j+y<0)||(j+y>=h))overlay_r=true;//如果超出场地则重叠
else if((bd[i+x][j+y]>0))overlay_r=true;//如果没超出场地但场地非空也重叠
return overlay_r;}

void newblock()//新方块
{
x=3;//新方块行
y=16;//新方块列
r=0;//新方块旋转
k=random(7)+1;//新方块类型
if(overlay())restart();//如果重叠则重来
}

bool rotate(char d)//旋转
{bool rotate_r;
r=r+1;if(r>3)r=0;rotate_r=!(overlay());//尝试旋转
if(!(rotate_r))r=r-1;if(r<0)r=3;//如果不能旋转则转回来
return rotate_r;}

bool move(char dx,char dy)//移动
{bool move_r;
x=x+dx;y=y+dy;move_r=!(overlay());//尝试移动
if(!(move_r)){x=x-dx;y=y-dy;};//如果不能移动则移回来
if(!(move_r)&&(dy<0))fixblock();//如果不能移动且下落则固定
if(dy<0)downtime=gettimer();//如果下落则重置下落时间
return move_r;}

int main(){//主程序
randomize();//初始化随机种子
createwin(w*sz,h*sz);//建立窗口
settitle("俄罗斯方块");//设定标题
restart();//重新开始
do{//开始消息循环
if(isnextmsg())//如果有新消息
{
if(iskey(37))move(-1,0);//如果按左则左移
if(iskey(39))move(+1,0);//如果按右则右移
if(iskey(40))move(0,-1);//如果按下则下落
if(iskey(38))rotate(1);//如果按上则旋转
if(iskey(32))while(move(0,-1));//如果按空格则下底
}
if(gettimer()>downtime+1)move(0,-1);//如果超过1秒则下落
if(gettimer()>frametime+1/frame)//如果当前时间已超过一帧时间
{
while(gettimer()>frametime+1/frame)frametime=frametime+1/frame;//增加帧数（包括跳帧）
clear();
for(i=0;i<=w-1;i++)for(j=0;j<=h-1;j++)drawblock(i,j,bd[i][j]);//画场地
for(i=0;i<=3;i++)for(j=0;j<=3;j++)if(bdk[k][r][j][i]>0)drawblock(i+x,j+y,k);//画当前方块
freshwin();//刷新窗口
}
delay();//延迟1毫秒
}while(!( !(iswin())||(iskey(27))));//直到关闭窗口或按ESC键
return 0;}

#include "disp.h"//使用Display单元库
unsigned long w=600;//窗口宽
unsigned long h=100;//窗口高
double frame=120.0;//帧率
double frametime=0.0;//当前帧时间
unsigned long audio;//音频句柄
unsigned long pos;//音频窗口位置
bool play=false;//音频播放状态
int main(){
createwin(w,h,blue);//建立蓝色窗口
settitle("display.mp3");//设定标题
audio=loadaudio("display.mp3");//读取音频
playaudio(audio);//播放音频
do{//开始消息循环
if(isnextmsg())//如果有新消息
{
if(isdropfile())//如果有拖拽文件
{
settitle(getdropfile());//设定标题为拖拽文件名
stopaudio(audio);//停止正在播放的音频
audio=loadaudio(getdropfile());//读取音频
playaudio(audio);//播放音频
play=true;//设定音频状态
}
if(iskey(37))//如果按左
setaudiopos(audio,max(getaudiopos(audio)-1000,0));//倒退1秒
if(iskey(39))//如果按右
setaudiopos(audio,min(getaudiopos(audio)+1000,getaudiolen(audio)));//前进1秒
if(iskey(40))//如果按下
setaudiovol(audio,max(getaudiovol(audio)-100,0));//减小100音量
if(iskey(38))//如果按上
setaudiovol(audio,min(getaudiovol(audio)+100,1000));//增大100音量
if(ismouseleft())//如果鼠标左键
setaudiopos(audio,round(getmouseposx()/double(w)*getaudiolen(audio)));//跳转音频
if(ismouseright()||iskey(32))//如果鼠标右键或按空格
{
if(play)pauseaudio(audio);//如果正在播放则暂停
else resumeaudio(audio);//否则继续播放
play=!(play);//更改音频状态
}
}
if(getaudiopos(audio)==getaudiolen(audio))//如果已播放完毕
setaudiopos(audio,0);//重头播放
if(gettimer()>frametime+1/frame)//如果当前时间已超过一帧时间
{
while(gettimer()>frametime+1/frame)frametime=frametime+1/frame;//增加帧数（包括跳帧）
if(getaudiolen(audio)==0)pos=0;//如果音频长度为0（没有音频）则设音频窗口位置为0
else pos=round(double(w)*getaudiopos(audio)/getaudiolen(audio));//否则设定音频窗口位置
clear();bar(pbitmap(0),0,0,pos,100,transparent,yellow);//绘制状态
drawtextlnxy(i2s(getaudiopos(audio))+" / "+i2s(getaudiolen(audio)),0,0,yellow,blue);//输出状态
freshwin();//刷新窗口
}
delay();//延迟1毫秒
}while(!( !(iswin())||(iskey(27))));//直到关闭窗口或按ESC
return 0;}

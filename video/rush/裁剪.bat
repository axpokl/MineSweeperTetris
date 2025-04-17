ffmpeg -y -i ori.mp4 -itsoffset 0.1 -i ori.mp4 -map 1:v -map 0:a -c copy ofst.mp4

ffmpeg -y -i ofst.mp4 -ss 15.4 -t 20 -c:v libx264 -c:a aac out1.mp4
ffmpeg -y -i ofst.mp4 -ss 108 -t 9 -c:v libx264 -c:a aac out2.mp4
ffmpeg -y -i ofst.mp4 -ss 123.5 -t 11 -c:v libx264 -c:a aac out3.mp4
ffmpeg -y -i ofst.mp4 -ss 219 -t 40 -c:v libx264 -c:a aac out4.mp4


ffmpeg -y -vsync 0 -i out1.mp4 -i out2.mp4 -i out3.mp4 -i out4.mp4 -filter_complex "[0]settb=AVTB[0:v];[1]settb=AVTB[1:v];[2]settb=AVTB[2:v];[3]settb=AVTB[3:v];[0]atrim=0:20[0:a];[1]atrim=0:9[1:a];[2]atrim=0:11[2:a];[3]atrim=0:40[3:a];[0:v][1:v]xfade=transition=fade:duration=1:offset=19[v1];[v1][2:v]xfade=transition=fade:duration=1:offset=27[v2];[v2][3:v]xfade=transition=fade:duration=1:offset=37,format=yuv420p[video];[0:a][1:a]acrossfade=d=1:c1=tri:c2=tri[a1];[a1][2:a]acrossfade=d=1:c1=tri:c2=tri[a2];[a2][3:a]acrossfade=d=1:c1=tri:c2=tri[audio]" -map "[audio]" -map "[video]" out.mp4


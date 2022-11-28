ffmpeg -i ori.mp4 -itsoffset 0.24 -i ori.mp4 -map 1:v -map 0:a -c copy del.mp4

ffmpeg -i del.mp4 -ss 9.5 -t 13 -c:v libx264 -c:a aac cut1.mp4

ffmpeg -i del.mp4 -ss 59 -t 6 -c:v libx264 -c:a aac cut2.mp4

ffmpeg -i del.mp4 -ss 94 -t 9 -c:v libx264 -c:a aac cut3.mp4

ffmpeg -i del.mp4 -ss 141.5 -t 7 -c:v libx264 -c:a aac cut4.mp4

ffmpeg -i del.mp4 -ss 179.5 -t 17 -c:v libx264 -c:a aac cut5.mp4

ffmpeg -i del.mp4 -ss 205 -t 9 -c:v libx264 -c:a aac cut6.mp4

ffmpeg -vsync 0 -i cut1.mp4 -i cut2.mp4 -i cut3.mp4 -i cut4.mp4 -i cut5.mp4 -i cut6.mp4 -filter_complex "[0]settb=AVTB[0:v];[1]settb=AVTB[1:v];[2]settb=AVTB[2:v];[3]settb=AVTB[3:v];[4]settb=AVTB[4:v];[5]settb=AVTB[5:v];[0]atrim=0:13[0:a];[1]atrim=0:6[1:a];[2]atrim=0:9[2:a];[3]atrim=0:7[3:a];[4]atrim=0:17[4:a];[5]atrim=0:9[5:a];[0:v][1:v]xfade=transition=fade:duration=1:offset=12[v1];[v1][2:v]xfade=transition=fade:duration=1:offset=17[v2];[v2][3:v]xfade=transition=fade:duration=1:offset=25[v3];[v3][4:v]xfade=transition=fade:duration=1:offset=31[v4];[v4][5:v]xfade=transition=fade:duration=1:offset=47,format=yuv420p[video];[0:a][1:a]acrossfade=d=1:c1=tri:c2=tri[a1];[a1][2:a]acrossfade=d=1:c1=tri:c2=tri[a2];[a2][3:a]acrossfade=d=1:c1=tri:c2=tri[a3];[a3][4:a]acrossfade=d=1:c1=tri:c2=tri[a4];[a4][5:a]acrossfade=d=1:c1=tri:c2=tri[audio]" -b:v 10M -map "[audio]" -map "[video]" out.mp4

ffmpeg -i out.mp4 -strict -2 -vf crop=1280:720:740:370 movie.mp4

ffmpeg -i out.mp4 -strict -2 -vf crop=1024:576:868:442 movie2.mp4


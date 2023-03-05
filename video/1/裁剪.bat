2576	1408
600	337
1920	1080

1356	521	1100	521
1549	915	1804	917
193	394	704	396

1324	489	1042	489
1581	947	1862	949
257	458	820	460

1195	425	929	425
1709	1011	1974	1013
514	586	1045	588

ffmpeg -i ori.mp4 -itsoffset 0.2 -i ori.mp4 -map 1:v -map 0:a -c copy del.mp4
ffmpeg -i ori2.mp4 -itsoffset 0.2 -i ori2.mp4 -map 1:v -map 0:a -c copy del2.mp4

ffmpeg -i del.mp4 -ss 4.5 -t 10.5 -c:v libx264 -c:a aac cut1.mp4
ffmpeg -i del.mp4 -ss 20 -t 11.5 -c:v libx264 -c:a aac cut2.mp4
ffmpeg -i del.mp4 -ss 41.5 -t 12 -c:v libx264 -c:a aac cut3.mp4
ffmpeg -i del2.mp4 -ss 22 -t 12 -c:v libx264 -c:a aac cut4.mp4
ffmpeg -i del2.mp4 -ss 70 -t 12 -c:v libx264 -c:a aac cut5.mp4
ffmpeg -i del2.mp4 -ss 200 -t 18 -c:v libx264 -c:a aac cut6.mp4

ffmpeg -i cut1.mp4 -strict -2 -vf crop=704:396:1100:521,scale=1920:1080 out1.mp4
ffmpeg -i cut2.mp4 -strict -2 -vf crop=704:396:1100:521,scale=1920:1080 out2.mp4
ffmpeg -i cut3.mp4 -strict -2 -vf crop=704:396:1100:521,scale=1920:1080 out3.mp4
ffmpeg -i cut4.mp4 -strict -2 -vf crop=820:460:1042:489,scale=1920:1080 out4.mp4
ffmpeg -i cut5.mp4 -strict -2 -vf crop=1045:588:929:425,scale=1920:1080 out5.mp4
ffmpeg -i cut6.mp4 -strict -2 -vf crop=1045:588:929:425,scale=1920:1080 out6.mp4


ffmpeg -vsync 0 -i out1.mp4 -i out2.mp4 -i out3.mp4 -i out4.mp4 -i out5.mp4 -i out6.mp4 -filter_complex "[0]settb=AVTB[0:v];[1]settb=AVTB[1:v];[2]settb=AVTB[2:v];[3]settb=AVTB[3:v];[4]settb=AVTB[4:v];[5]settb=AVTB[5:v];[0]atrim=0:10.5[0:a];[1]atrim=0:11.5[1:a];[2]atrim=0:12[2:a];[3]atrim=0:12[3:a];[4]atrim=0:12[4:a];[5]atrim=0:18[5:a];[0:v][1:v]xfade=transition=fade:duration=1:offset=9.5[v1];[v1][2:v]xfade=transition=fade:duration=1:offset=20[v2];[v2][3:v]xfade=transition=fade:duration=1:offset=31[v3];[v3][4:v]xfade=transition=fade:duration=1:offset=42[v4];[v4][5:v]xfade=transition=fade:duration=1:offset=53,format=yuv420p[video];[0:a][1:a]acrossfade=d=1:c1=tri:c2=tri[a1];[a1][2:a]acrossfade=d=1:c1=tri:c2=tri[a2];[a2][3:a]acrossfade=d=1:c1=tri:c2=tri[a3];[a3][4:a]acrossfade=d=1:c1=tri:c2=tri[a4];[a4][5:a]acrossfade=d=1:c1=tri:c2=tri[audio]" -b:v 10M -map "[audio]" -map "[video]" out.mp4




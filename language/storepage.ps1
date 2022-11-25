function translate($lan, $text)
{
$uri = "https://translate.googleapis.com/translate_a/single?client=gtx&sl=auto&tl=$($lan)&dt=t&q=$text"
$res = irm -uri $uri -Method Get
$tns = $res[0].SyncRoot | foreach { $_[0] }
return $tns
}

cd "C:\Users\pc\Desktop\MineSweeperTetris\language"
$lan_short = cat ".\list_short.txt"
$lan_long = cat ".\list_long.txt"
rd "storage" -force -recurse
md "storage"
$i=0
foreach ($lan in $lan_short)
{
$text = cat ".\storepage.txt"
$out = '{"language":"'+$lan_long[$i]+'","itemid":"509254","app[content][legal]":"","app[content][earlyaccess_description]":"","app[content][about]":"'
$out = $out +'[h2]'+(translate $lan $text[0])+'[\/h2]\r\n\r\n\r\n'
$out = $out +(translate $lan $text[1])+'\r\n\r\n'
$out = $out +(translate $lan $text[2])+'\r\n\r\n'
$out = $out +(translate $lan $text[3])+'\r\n\r\n'
$out = $out +(translate $lan $text[4])+'\r\n\r\n'
$out = $out +(translate $lan $text[5])+'\r\n\r\n'
$out = $out +'\r\n[h2]'+(translate $lan $text[6])+'[\/h2]\r\n\r\n\r\n'
$out = $out +(translate $lan $text[7])+'\r\n\r\n'
$out = $out +(translate $lan $text[8])+'\r\n\r\n'
$out = $out +(translate $lan $text[9])+'\r\n\r\n'
$out = $out +'\r\n[h2]'+(translate $lan $text[10])+'[\/h2]\r\n\r\n\r\n'
$out = $out +(translate $lan $text[11])+'\r\n\r\n'
$out = $out +(translate $lan $text[12])+'\r\n\r\n'
$out = $out +(translate $lan $text[13])
$out = $out +'","app[content][short_description]":"'
$out = $out +(translate $lan $text[14])
$out = $out +'","app[content][sysreqs][mac][min][osversion]":"","app[content][sysreqs][mac][min][processor]":"","app[content][sysreqs][mac][min][graphics]":"","app[content][sysreqs][mac][min][soundcard]":"","app[content][sysreqs][mac][min][notes]":"","app[content][sysreqs][mac][req][osversion]":"","app[content][sysreqs][mac][req][processor]":"","app[content][sysreqs][mac][req][graphics]":"","app[content][sysreqs][mac][req][soundcard]":"","app[content][sysreqs][mac][req][notes]":"","app[content][sysreqs][windows][min][osversion]":"Windows 7","app[content][sysreqs][windows][min][processor]":"Intel Celeron G1620","app[content][sysreqs][windows][min][graphics]":"NVIDIA GeForce GT 630","app[content][sysreqs][windows][min][soundcard]":"Realtek ALC 655","app[content][sysreqs][windows][min][notes]":"","app[content][sysreqs][windows][req][osversion]":"Windows 10","app[content][sysreqs][windows][req][processor]":"Intel Pentium G2120","app[content][sysreqs][windows][req][graphics]":"Nvidia GeForce GTX 950","app[content][sysreqs][windows][req][soundcard]":"Realtek ALC 3861","app[content][sysreqs][windows][req][notes]":"","app[content][sysreqs][linux][min][osversion]":"","app[content][sysreqs][linux][min][processor]":"","app[content][sysreqs][linux][min][graphics]":"","app[content][sysreqs][linux][min][soundcard]":"","app[content][sysreqs][linux][min][notes]":"","app[content][sysreqs][linux][req][osversion]":"","app[content][sysreqs][linux][req][processor]":"","app[content][sysreqs][linux][req][graphics]":"","app[content][sysreqs][linux][req][soundcard]":"","app[content][sysreqs][linux][req][notes]":""}'
echo $out > ("storage\"+$lan+".json")
$i=$i+1
}
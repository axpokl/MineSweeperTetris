function translate($lan, $text)
{
$uri = "https://translate.googleapis.com/translate_a/single?client=gtx&sl=auto&tl=$($lan)&dt=t&q=$text"
$res = irm -uri $uri -Method Get
$tns = $res[0].SyncRoot | foreach { $_[0] }
return $tns
}

cd "C:\Users\pc\Desktop\MineSweeperTetris\language"
$text = "MineSweeper Tetris"
$lan_short = cat ".\list_short.txt"
$lan_long = cat ".\list_long.txt"
rd "appname" -force -recurse
md "appname"
$i=0
foreach ($lan in $lan_short)
{
$tns = translate $lan $text
$out = '{"language":"'+$lan_long[$i]+'","appid":2204230,"name":"'+$tns+'"}'
echo $out > ("appname\"+$lan+".json")
$i=$i+1
}
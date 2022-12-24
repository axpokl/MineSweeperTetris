function translate($lan, $text)
{
$uri = "https://translate.googleapis.com/translate_a/single?client=gtx&sl=auto&tl=$($lan)&dt=t&q=$text"
$res = irm -uri $uri -Method Get
$tns = $res[0].SyncRoot | foreach { $_[0] }
return $tns
}

cd "T:\!temp\MineSweeperTetris\language"
$text = "MineSweeper Tetris"
$lan_short = cat ".\list_short.txt"
$lan_long = cat ".\list_long.txt"
rd "lan" -force -recurse
md "lan"
$i=0
$text = cat ".\english.txt"
foreach ($lan in $lan_short)
{
foreach ($line in $text)
{
$tns = translate $lan $line
echo $tns >> ("lan\"+$lan_long[$i]+".txt")
sleep(1);
}
$i=$i+1
}
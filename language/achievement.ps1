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
rd "achievement" -force -recurse
md "achievement"
$i=0
foreach ($lan in $lan_short)
{
$text = cat ".\achievement.txt"
$k = 0;
$out = @"
"lang"
{
	"Language"	"
"@
$out +=  $lan_long[$i]
$out+=@"
"
	"Tokens"
	{

"@
for ($j=0; $j -lt 26; $j++)
{
$out = $out +"`t`t"+'"NEW_ACHIEVEMENT_6_'+$j+'_NAME"'+"`t"+'"'+(translate $lan $text[$k])+'"'+"`n"
$k++
$out = $out +"`t`t"+'"NEW_ACHIEVEMENT_6_'+$j+'_DESC"'+"`t"+'"'+(translate $lan $text[$k])+'"'+"`n"
$k++
}
$out += @"
	}
}
"@
echo $out > ("achievement\"+$lan+".json")
$i=$i+1
}
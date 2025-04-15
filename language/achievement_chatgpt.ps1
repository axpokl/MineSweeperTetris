cd "C:\Github_ax\MineSweeperTetris\language"
$lan_short = cat ".\list_short.txt"
$lan_long = cat ".\list_long.txt"
rd "achievement_chatgpt_" -force -recurse
md "achievement_chatgpt_"
$i=0
foreach ($lan in $lan_short)
{
$text = cat (".\achievement_chatgpt\"+$lan+".json")
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
$out = $out +"`t`t"+'"NEW_ACHIEVEMENT_20_'+$j+'_NAME"'+"`t"+'"'+($text[$k])+'"'+"`n"
$k++
$out = $out +"`t`t"+'"NEW_ACHIEVEMENT_20_'+$j+'_DESC"'+"`t"+'"'+($text[$k])+'"'+"`n"
$k++
}
$out += @"
	}
}
"@
echo $out > ("achievement_chatgpt_\"+$lan+".json")
$i=$i+1
}
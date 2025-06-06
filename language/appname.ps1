$translations = @{
    "arabic"     = "كاسحة الألغام راش"
    "bulgarian"  = "Минно поле Rush"
    "czech"      = "Hledač min Rush"
    "danish"     = "Minestryger Rush"
    "german"     = "Minenräumer Rush"
    "greek"      = "Ναρκαλιευτής Rush"
    "english"    = "MineSweeper Rush"
    "spanish"    = "Buscaminas Rush"
    "latam"      = "Buscaminas Rush"
    "finnish"    = "Miinanraivaaja Rush"
    "french"     = "Démineur Rush"
    "hungarian"  = "Aknakereső Rush"
    "indonesian" = "Penyapu Ranjau Rush"
    "italian"    = "Campo Minato Rush"
    "japanese"   = "マインスイーパーラッシュ"
    "koreana"    = "지뢰 찾기 러시"
    "dutch"      = "Mijnenveger Rush"
    "norwegian"  = "Minesveiper Rush"
    "polish"     = "Saper Rush"
    "portuguese" = "Campo Minado Rush"
    "brazilian"  = "Campo Minado Rush"
    "romanian"   = "Dezamorsator Rush"
    "russian"    = "Сапёр Раш"
    "swedish"    = "Minsvepare Rush"
    "thai"       = "กวาดทุ่นระเบิด รัช"
    "turkish"    = "Mayın Tarlası Rush"
    "ukrainian"  = "Мінер Раш"
    "vietnamese" = "Gỡ Mìn Rush"
    "schinese"   = "扫雷Rush"
    "tchinese"   = "掃雷Rush"
}
cd "G:\!temp\MineSweeperTetris\language"
$lan_short = Get-Content ".\list_short.txt"
$lan_long = Get-Content ".\list_long.txt"
if (Test-Path "appname") { Remove-Item "appname" -Recurse -Force }
New-Item "appname" -ItemType Directory | Out-Null
for ($i = 0; $i -lt $lan_short.Count; $i++) {
    $lan = $lan_short[$i]
    $long = $lan_long[$i]
    $tns = $translations[$long]
    $json = '{"language":"'+$long+'","appid":3665840,"name":"'+$tns+'"}'
    $json | Out-File ("appname\" + $lan + ".json") -Encoding unicode
}

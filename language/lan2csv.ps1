# 设置输入文件夹的路径
$languageFolderPath = ".\lan"

# 读取所有文本文件
$textFiles = Get-ChildItem -Path $languageFolderPath -Filter *.txt

# 创建一个哈希表来存储每个语言的所有行
$languageLines = @{}

# 记录最大的行数
$maxLines = 0

# 遍历所有文件，读取内容并更新最大行数
foreach ($file in $textFiles) {
    # 从文件名中提取语言名称
    $languageName = $file.BaseName

    # 读取文件内容
    $lines = Get-Content -Path $file.FullName
    $languageLines[$languageName] = $lines

    # 更新最大行数
    if ($lines.Count -gt $maxLines) {
        $maxLines = $lines.Count
    }
}

# 获取所有语言名称并按字母顺序排序
$sortedLanguageNames = $languageLines.Keys | Sort-Object

# 第一部分：每种语言作为列
$csvObjectsRow = New-Object System.Collections.Generic.List[Object]
for ($lineNum = 0; $lineNum -lt $maxLines; $lineNum++) {
    $lineObject = New-Object PSObject
    foreach ($languageName in $sortedLanguageNames) {
        $lineText = $languageLines[$languageName][$lineNum]
        if ($null -eq $lineText) { $lineText = "" }
        $lineObject | Add-Member -Type NoteProperty -Name $languageName -Value $lineText
    }
    $csvObjectsRow.Add($lineObject)
}
$outputCsvPathRow = ".\lan2row.csv"
$csvObjectsRow | Export-Csv -Path $outputCsvPathRow -NoTypeInformation -Encoding UTF8
Write-Host "所有语言的文本内容（每种语言为列）已合并到 '$outputCsvPathRow'"

# 第二部分：每种语言作为行
$csvObjectsCol = New-Object System.Collections.Generic.List[Object]
foreach ($languageName in $sortedLanguageNames) {
    $languageObject = New-Object PSObject
    $languageObject | Add-Member -Type NoteProperty -Name "Language" -Value $languageName
    for ($lineNum = 0; $lineNum -lt $maxLines; $lineNum++) {
        $lineText = $languageLines[$languageName][$lineNum]
        if ($null -eq $lineText) { $lineText = "" }
        $columnName = "Text" + ($lineNum + 1).ToString()
        $languageObject | Add-Member -Type NoteProperty -Name $columnName -Value $lineText
    }
    $csvObjectsCol.Add($languageObject)
}
$outputCsvPathCol = ".\lan2col.csv"
$csvObjectsCol | Export-Csv -Path $outputCsvPathCol -NoTypeInformation -Encoding UTF8
Write-Host "所有语言的文本内容（每种语言为行）已合并到 '$outputCsvPathCol'"

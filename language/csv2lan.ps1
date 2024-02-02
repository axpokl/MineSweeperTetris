# 设置CSV文件路径和输出文件夹路径
$csvFilePath = ".\lan2col.csv"
$outputFolderPath = ".\lan"

# 读取CSV文件
$csvContent = Import-Csv -Path $csvFilePath

# 遍历CSV中的每一行（每一种语言）
foreach ($row in $csvContent) {
    # 获取语言名称
    $languageName = $row.Language

    # 创建输出文件的路径
    $outputFilePath = Join-Path -Path $outputFolderPath -ChildPath ("$languageName.txt")

    # 初始化文本内容数组
    $textContent = @()

    # 遍历每一列（每一条翻译文本）
    foreach ($column in $csvContent[0].PSObject.Properties.Name) {
        if ($column -ne "Language") {
            # 将文本行添加到数组
            $textContent += $row.$column
        }
    }

    # 将文本内容数组写入文件，使用UTF-16LE编码和BOM
    $textContent | Out-File -FilePath $outputFilePath -Encoding Unicode
}

Write-Host "CSV文件已转换并写入到各个语言文件中。"

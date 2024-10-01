function Compress-FolderToCab {
    param ([string]$folderPath)

    if (-not (Test-Path $folderPath)) {
        Write-Host "文件夹不存在：$folderPath"
        return
    }

    $subfolders = Get-ChildItem -Directory -Path $folderPath

    if ($subfolders.Count -eq 0) {
        $folderName = Split-Path $folderPath -Leaf
        $parentFolder = Split-Path $folderPath -Parent
        $ddfFile = Join-Path $parentFolder "$folderName.ddf"
        $cabFile = Join-Path $parentFolder "$folderName.cab"
        $files = Get-ChildItem -File -Path $folderPath

        if ($files.Count -eq 0) {
            Write-Host "文件夹中没有文件：$folderPath"
            return
        }

        $ddfContent = @"
.OPTION EXPLICIT
.Set CabinetNameTemplate=$cabFile
.Set DiskDirectoryTemplate=
.Set CompressionType=MSZIP
.Set MaxDiskSize=CDROM

"@

        foreach ($file in $files) {
            $ddfContent += "`"$($file.FullName)`"`r`n"
        }

        $ddfContent | Set-Content -Path $ddfFile -Encoding ASCII

        Write-Host "正在创建 CAB 文件：$cabFile"
        $makecabCommand = "makecab /F `"$ddfFile`""
        Invoke-Expression $makecabCommand

        Remove-Item $ddfFile -Force
        Remove-Item $files.FullName -Force
        Remove-Item $folderPath -Force
    } else {
        Write-Host "文件夹包含子文件夹，不进行压缩：$folderPath"
    }
}

function Compress-AllSubfoldersToCab {
    param ([string]$rootFolder)

    if (-not (Test-Path $rootFolder)) {
        Write-Host "文件夹不存在：$rootFolder"
        return
    }

    $subfolders = Get-ChildItem -Recurse -Directory -Path $rootFolder

    foreach ($subfolder in $subfolders) {
        Write-Host "正在处理子文件夹：$($subfolder.FullName)"
        Compress-FolderToCab -folderPath $subfolder.FullName
    }

    Write-Host "所有子文件夹已处理完毕。"
}

function CompressUntilSubfoldersNotEmpty {
    param (
        [string]$folderPath
    )

    while ((Test-Path $folderPath) -and ((Get-ChildItem $folderPath -Directory | Measure-Object).Count -gt 0)) {
        Compress-AllSubfoldersToCab -rootFolder $folderPath
    }
}

$dstpath = "G:\!temp\MineSweeperTetris\gencab\cabfile"
$srcpath = "G:\!temp\MineSweeperTetris"
Copy-Item -Path "$srcpath\data" -Destination "$dstpath\data" -Recurse -Force
CompressUntilSubfoldersNotEmpty -folderPath $dstpath
Remove-Item setup.*
Copy-Item "$dstpath\data.cab" "$srcpath" -Force

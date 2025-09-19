#include "cab.h"

void CombinePath(char* dest, const char* path1, const char* path2)
{
    lstrcpyA(dest, path1);
    lstrcatA(dest, "/");
    lstrcatA(dest, path2);
}

UINT CALLBACK CabExtractCallback(PVOID context, UINT notification, uintptr_t param1, uintptr_t param2)
{
    if (notification == SPFILENOTIFY_FILEINCABINET)
    {
        FILE_IN_CABINET_INFO_A* fileInfo = (FILE_IN_CABINET_INFO_A*)param1;
        char* destDir = (char*)context;
        CombinePath(fileInfo->FullTargetName, destDir, fileInfo->NameInCabinet);
        return FILEOP_DOIT;
    }
    return NO_ERROR;
}

void RemoveExtension(char* filePath)
{
    char* lastDot = strrchr(filePath, '.');
    if (lastDot != NULL)
    {
        *lastDot = '\0';
    }
}

BOOL ProcessCabFile(const char* cabFilePath)
{
    char destFolder[MAX_PATH];
    char searchPath[MAX_PATH];
    WIN32_FIND_DATAA findData;
    HANDLE hFind;
    lstrcpyA(destFolder, cabFilePath);
    RemoveExtension(destFolder);
    CreateDirectoryA(destFolder, NULL);
    if (SetupIterateCabinetA(cabFilePath, 0, CabExtractCallback, destFolder) == 0)
    {
        DWORD errorCode = GetLastError();
        char errorMessage[MAX_PATH + 100];
        wsprintfA(errorMessage, "Failed to extract CAB file: %s. Error code: %lu", cabFilePath, errorCode);
        MessageBoxA(NULL, errorMessage, "Error", MB_ICONERROR);
        return FALSE;
    }
    if (strstr(cabFilePath, "data.cab") == NULL)
    {
        DeleteFileA(cabFilePath);
    }
    CombinePath(searchPath, destFolder, "*.cab");
    hFind = FindFirstFileA(searchPath, &findData);
    if (hFind != INVALID_HANDLE_VALUE)
    {
        do
        {
            char nestedCabPath[MAX_PATH];
            CombinePath(nestedCabPath, destFolder, findData.cFileName);
            ProcessCabFile(nestedCabPath);
        }
        while (FindNextFileA(hFind, &findData));
        FindClose(hFind);
    }
    return TRUE;
}

void DeleteFolderRecursively(const char* folderPath)
{
    char searchPath[MAX_PATH];
    char filePath[MAX_PATH];
    WIN32_FIND_DATAA findData;
    HANDLE hFind;

    CombinePath(searchPath, folderPath, "*");
    hFind = FindFirstFileA(searchPath, &findData);
    if (hFind != INVALID_HANDLE_VALUE)
    {
        do
        {
            CombinePath(filePath, folderPath, findData.cFileName);
            if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            {
                if (lstrcmpA(findData.cFileName, ".") != 0 && lstrcmpA(findData.cFileName, "..") != 0)
                {
                    DeleteFolderRecursively(filePath);
                }
            }
            else
            {
                DeleteFileA(filePath);
            }
        }
        while (FindNextFileA(hFind, &findData));
        FindClose(hFind);
    }
    RemoveDirectoryA(folderPath);
}

void CheckAndProcessCabFile()
{
    char versionFilePath[MAX_PATH];
    CombinePath(versionFilePath, "./data", version);
    if (GetFileAttributesA(versionFilePath) == INVALID_FILE_ATTRIBUTES)
    {
        DeleteFolderRecursively("./data");
        if (GetFileAttributesA("./data.cab") != INVALID_FILE_ATTRIBUTES)
        {
            if (ProcessCabFile("./data.cab"))
            {
                HANDLE hMarker = CreateFileA(versionFilePath, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
                if (hMarker != INVALID_HANDLE_VALUE)
                {
                    CloseHandle(hMarker);
                }
            }
        }
    }
}

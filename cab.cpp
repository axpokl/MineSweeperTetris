#include <setupapi.h>

UINT CALLBACK CabExtractCallback(PVOID context, UINT notification, uintptr_t param1, uintptr_t param2)
{
    if (notification == SPFILENOTIFY_FILEINCABINET)
    {
        FILE_IN_CABINET_INFO_A* fileInfo = (FILE_IN_CABINET_INFO_A*)param1;
        char* destDir = (char*)context;
        char destFilePath[MAX_PATH];
        lstrcpyA(destFilePath, destDir);
        lstrcatA(destFilePath, "/");
        lstrcatA(destFilePath, fileInfo->NameInCabinet);
        lstrcpyA(fileInfo->FullTargetName, destFilePath);
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
    lstrcpyA(searchPath, destFolder);
    lstrcatA(searchPath, "/*.cab");
    hFind = FindFirstFileA(searchPath, &findData);
    if (hFind != INVALID_HANDLE_VALUE)
    {
        do
        {
            char nestedCabPath[MAX_PATH];
            lstrcpyA(nestedCabPath, destFolder);
            lstrcatA(nestedCabPath, "/");
            lstrcatA(nestedCabPath, findData.cFileName);
            ProcessCabFile(nestedCabPath);
        }
        while (FindNextFileA(hFind, &findData));
        FindClose(hFind);
    }
    return TRUE;
}

void CheckAndProcessCabFile()
{
    if (GetFileAttributesA("./data/done") == INVALID_FILE_ATTRIBUTES)
    {
        if (GetFileAttributesA("./data.cab") != INVALID_FILE_ATTRIBUTES)
        {
            if (ProcessCabFile("./data.cab"))
            {
                HANDLE hMarker = CreateFileA("data/done", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
                if (hMarker != INVALID_HANDLE_VALUE)
                {
                    CloseHandle(hMarker);
                }
            }
        }
    }
}
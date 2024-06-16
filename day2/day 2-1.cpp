#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    HANDLE hMapFile;
    char* pBuf;

    hMapFile = CreateFileMapping(
        INVALID_HANDLE_VALUE,    // use paging file
        NULL,                    // default security
        PAGE_READWRITE,          // read/write access
        0,                       // maximum object size (high-order DWORD)
        1024,                    // maximum object size (low-order DWORD)
        "MyFileMapping");        // name of mapping object

    if (hMapFile == NULL)
    {
        printf("Could not create file mapping object (%d).\n", GetLastError());
        return 1;
    }

    pBuf = (char*)MapViewOfFile(hMapFile,   // handle to map object
        FILE_MAP_ALL_ACCESS, // read/write permission
        0,
        0,
        1024);

    if (pBuf == NULL)
    {
        printf("Could not map view of file (%d).\n", GetLastError());
        CloseHandle(hMapFile);
        return 1;
    }

    printf("Enter some data to write to shared memory\n");
    fgets(pBuf, 100, stdin);
    printf("You wrote : %s\n", pBuf);

    UnmapViewOfFile(pBuf);
    CloseHandle(hMapFile);
    return 0;
}

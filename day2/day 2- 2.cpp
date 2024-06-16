#include <windows.h>
#include <stdio.h>
#include <string.h>

#define MAX 100

int main()
{
    HANDLE hReadPipe, hWritePipe;
    char buffer[MAX];

    // Create a pipe for reading and writing
    CreatePipe(&hReadPipe, &hWritePipe, NULL, 0);

    printf("Write Data : ");
    fgets(buffer, MAX, stdin);
    DWORD bytesWritten;
    WriteFile(hWritePipe, buffer, strlen(buffer), &bytesWritten, NULL);

    char readBuffer[MAX];
    DWORD bytesRead;
    ReadFile(hReadPipe, readBuffer, MAX, &bytesRead, NULL);
    printf("Data read is : %s \n", readBuffer);

    CloseHandle(hReadPipe);
    CloseHandle(hWritePipe);
    return 0;
}


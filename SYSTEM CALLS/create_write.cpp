#include <windows.h>
#include <iostream>

int main() {
    HANDLE hFile = CreateFile(
        "example.txt",              // File name
        GENERIC_WRITE,              // Write access
        0,                          // No sharing
        NULL,                       // Default security
        CREATE_ALWAYS,              // Overwrite if exists
        FILE_ATTRIBUTE_NORMAL,      // Normal file
        NULL                        // No template
    );

    if (hFile == INVALID_HANDLE_VALUE) {
        std::cout << "File creation failed. Error: " << GetLastError() << std::endl;
        return 1;
    }

    const char* data = "Hello! This is a test file.\n";
    DWORD bytesWritten;
    WriteFile(hFile, data, strlen(data), &bytesWritten, NULL);

    std::cout << "File created and written successfully.\n";

    CloseHandle(hFile);
    return 0;
}

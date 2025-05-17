#include <windows.h>
#include <iostream>

int main() {
    BOOL copied = CopyFile(
        "example.txt",      // Source
        "copy_example.txt", // Destination
        FALSE               // Overwrite if exists
    );

    if (copied) {
        std::cout << "File copied successfully.\n";
    } else {
        std::cout << "Copy failed. Error: " << GetLastError() << std::endl;
    }

    return 0;
}

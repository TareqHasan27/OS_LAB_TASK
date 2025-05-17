#include <windows.h>
#include <iostream>

int main() {
    BOOL moved = MoveFile(
        "copy_example.txt",   // Old name
        "moved_example.txt"   // New name or new path
    );

    if (moved) {
        std::cout << "File moved or renamed successfully.\n";
    } else {
        std::cout << "Move failed. Error: " << GetLastError() << std::endl;
    }

    return 0;
}

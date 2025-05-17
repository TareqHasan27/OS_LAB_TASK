#include <windows.h>
#include <iostream>

int main() {
    BOOL deleted = DeleteFile("copy_example.txt");

    if (deleted) {
        std::cout << "File deleted successfully.\n";
    } else {
        std::cout << "File deletion failed. Error: " << GetLastError() << std::endl;
    }

    return 0;
}

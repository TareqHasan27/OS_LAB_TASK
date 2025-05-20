#include <stdio.h>
#include<unistd.h>

int main() {
    if (rename("copy.txt", "newname.txt") < 0) {
        printf("Erorr move\n");
        return 1;
    }
    printf("File renamed/moved successfully\n");
    return 0;
}

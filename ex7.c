#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
//viết 1 chương trình, lấy tham số đầu vào là shell command, nếu ls thì ls, cd thì cd, pwd thì pwd
int main (int argc, char *argv[]) {
    if(strcmp(argv[1], "pwd") == 0){
        return execl ("/bin/pwd", "pwd", NULL);
    }else if(strcmp(argv[1], "ls") == 0){
        return execl ("/bin/ls", "ls", NULL);
    }else if(strcmp(argv[1], "nano") == 0){
        return execl ("/bin/nano", "nano ex2.c", NULL);    
    }
    return 0;
}

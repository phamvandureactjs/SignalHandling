#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(){
    int fd = open("./text.txt", O_RDWR, S_IRUSR | S_IWUSR);
    struct stat sb;
    if(fstat(fd, &sb) == -1){
        perror("Cant get file size\n");
    }
    // printf("File size is %ld\n", sb.st_size);
    char *file_in_memory = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    for(int i = 0; i < sb.st_size; i++){
        printf("%c", file_in_memory[i]);
    }
    return 0;
}
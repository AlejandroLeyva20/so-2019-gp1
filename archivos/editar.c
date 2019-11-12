#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

void toWrite(int fdAux, char *pal){
    write(fdAux, pal, strlen(pal));
    write(fdAux, " ", 1);
}

int main(int argc, char **argv){
    char *fileName = argv[1];
    char word[100];
    char c;
    char *pwd = getcwd(NULL, 0);
    char path2[strlen("tmp.txt")+strlen(pwd)+2];
    char path1[strlen(fileName)+strlen(pwd)+2];
    sprintf(path1, "%s/%s",pwd,fileName);
    sprintf(path2, "%s/%s",pwd,"tmp.txt");
    int fd = open(path1, O_RDONLY);
    int fd2 = open(path2, O_WRONLY|O_CREAT, 0666);
    int i = 0;
    while(read(fd, &c, 1)){
        if(c != ' '){
            word[i++] = c;
        } else {
            word[i] = '\0';
            if(!strcmp(word, argv[2])){
                toWrite(fd2, argv[3]);
            }else{
                toWrite(fd2, word);
            }
            i = 0;
        }
    }
    word[i] = '\0';
    if(!strcmp(word, argv[2])){
        toWrite(fd2, argv[3]);
    }else{
        toWrite(fd2, word);
    }
    close(fd);
    close(fd2);
    unlink(path1);
    link(path2, path1);
    unlink(path2);
    return 0;
}
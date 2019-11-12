#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
    char *file1 = argv[1];
    char *file2 = argv[2];
    char *pwd = getcwd(NULL, 0);
    char path1[strlen(file1)+strlen(pwd)+2];
    char path2[strlen(file2)+strlen(pwd)+2];
    sprintf(path1, "%s/%s",pwd,file1);
    sprintf(path2, "%s/%s",pwd,file2);

    if(!link(path1, path2)){
        unlink(path1);
        printf("renombrado exitoso\n");
    } else {
        printf("No pudo ser renombrado\n");
    }
}
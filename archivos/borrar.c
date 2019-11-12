#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
    char *file1 = argv[1];
    char *pwd = getcwd(NULL, 0);
    char path1[strlen(file1)+strlen(pwd)+2];
    sprintf(path1, "%s/%s",pwd,file1);
    if(!unlink(path1)){
        printf("borrado exitoso\n");
    } else {
        printf("El archivo no pudo ser borrado\n");
    }
}
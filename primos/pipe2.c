#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int p = 0,n = 0;
    scanf("%d\n",&p);
    fprintf(stderr, "%d\n", p);
    while(1){
        scanf("%d\n",&n);
        if(n == -1){
            fprintf(stdout,"%d\n", n);
            break;
        }
        if(n % p != 0){
            fprintf(stdout,"%d\n", n);
        }
    }
}
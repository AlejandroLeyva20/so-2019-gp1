#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

int forever = 1;

void signalHandler(int sgn){
    forever = 0;
    printf("Received signal: %d\n",sgn);
}

int main(){
    int pid;
    signal(10,signalHandler);
    pid = fork();
    if(pid == 0){
        // Soy el hijo
        printf("Soy el proceso hijo\n");
        // Codigo que quiero que haga el hijo
        while(forever){}
        printf("terminó el ciclo infinito\n");
    } else {
        printf("Soy el proceso padre y mi hijo es: %d\n",pid);
        sleep(5);
        kill(pid,10);
        // Codigo del padre
        for(;;){}
    }
}
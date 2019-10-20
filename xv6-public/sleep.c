#include "types.h"
#include "user.h"
#include "stat.h"

int main(int argc, char *argv[]) {
	int sec;
	if (argc < 2){
		printf(2, "Error: Se necesitan los segundos\n");
		exit();
	}
	sec = atoi(argv[1]);
	if (sec > 0){
		sleep(sec);
	} else {
		printf(2, "Intervalo inválido %s\n", argv[1]);
	}
	exit();
}
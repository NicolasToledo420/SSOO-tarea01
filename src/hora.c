#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

//Creo la funcion para hacer la llamada de la señal SIGUSR1 con el proceso correspondiente
//Si esta funcion es invocada, se obtiene la hora del sistema y la imprime.
//Antes de imprimir la hora y la fecha, hace un clear a la consola
//Ya que el main se va repitiendo cada 10 segundos y la consola se ve desordenada.
void llamada (int sig){
	system("clear");
	//Creo las variables para obtener el sysdate
	time_t current_time;
	char* c_time_string;
	current_time = time(NULL);
	c_time_string=ctime(&current_time);
	//Se imprime la fecha
	printf("Señal SIGUSR1 Recibida: %s", c_time_string);
}
//En esta funcion main, se hace un while(1) para que se ejecute siempre
//hasta que se reciba la señal con parametro SIGUSR1 que tenga el valor del proceso.
//Una vez que se llame a la señal con SIGUSR1, se invoca a la funcion llamada.
int main(){
	while(1){
		printf("Programa hora ejecutandose. PID= %d\n", getpid());
		printf("Listo para recibir la señal SIGUSR1.\n");
		//Se recibe la señal con atributo SIGUSR1 para invocar a la funcion llamada.
		//Dependiendo de lo que reciba con el SIGUSR1, como por ejemplo el comando kill -s SIGUSR1 pid
		//NO se va a matar el proceso, sino que se invocará a la funcion llamada para devolver la fecha y hora.
		signal(SIGUSR1, llamada);
		sleep(10);
	}
}

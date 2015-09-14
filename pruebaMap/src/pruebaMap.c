/*
 ============================================================================
 Name        : pruebaMap.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include </home/utnso/workspace/tp-2015-2c-lara-rules/Paquetes/funcionesPaquetes.h>
#include </home/utnso/workspace/tp-2015-2c-lara-rules/Socket/socket.h>
/*
//Esto comentado es solo para probarlo
void escribirBoludecesEnArchivo(FILE *archivo)
{
	fprintf (archivo, "boludeces1\nboludeces2\nsalir\n");

}

int llamada_al_programa_redireccionando_stdin_out_ordenando(char *pathPrograma,char *pathArchivoSalida,void (*escribirArchivoEntrada) (void*))
{
	FILE *entradaARedirigir = NULL;

	char *comandoEntero=malloc(strlen(pathPrograma)+11+strlen(pathArchivoSalida));

	sprintf(comandoEntero,"%s | sort > %s",pathPrograma,pathArchivoSalida);	//Ordena las cadenas entrantes

	entradaARedirigir = popen (comandoEntero,"w");

	if (entradaARedirigir != NULL)
	{
		escribirArchivoEntrada(entradaARedirigir);

		pclose (entradaARedirigir);

		free(comandoEntero);
	}
	else
	{
		printf("No se pudo ejecutar el programa!");
		return -1;
	}


	return 0;
}


int main(void) {
	puts("Hola Soy un programa que redirecciona el stdin y el stdout para un cierto programa!!!\n");

	llamada_al_programa_redireccionando_stdin_out_ordenando("/home/utnso/mapper.sh","salida.txt",(void *) escribirBoludecesEnArchivo);

	return EXIT_SUCCESS;
}*/

int main(){

	int fdMemoria = socket_conectarCliente("127.0.0.1",5000);

	/* D_STRUCT_INICIAR_PROCESO
	t_struct_iniciar_proceso * prueba = malloc(sizeof(t_struct_iniciar_proceso));

	prueba->paginasDeDatos = 5;

	t_struct_pcb * pcb = malloc(sizeof(t_struct_pcb));

	pcb->PID=1;
	pcb->estado = Listo;
	pcb->instrucciones_totales = 10;
	pcb->instruction_pointer = 12;
	pcb->path = "/home/utnso/workspace";

	t_struct_planificador planificador;// = malloc(sizeof(t_struct_planificador));

	planificador.algoritmo = FIFO;
	planificador.quantum = 3;
	pcb->planificador = planificador;

	prueba->PCB = pcb;
	*/

	/*D_STRUCT_LEER_PAGINA
	t_struct_leer_pagina * prueba = malloc(sizeof(t_struct_leer_pagina));
	prueba->paginaLeer = 5;

	t_struct_pcb * pcb = malloc(sizeof(t_struct_pcb));

	pcb->PID=1;
	pcb->estado = Listo;
	pcb->instrucciones_totales = 10;
	pcb->instruction_pointer = 12;
	pcb->path = "/home/utnso/workspace";

	t_struct_planificador planificador;// = malloc(sizeof(t_struct_planificador));

	planificador.algoritmo = FIFO;
	planificador.quantum = 3;
	pcb->planificador = planificador;

	prueba->PCB = pcb;*/

	/*D_STRUCT_FINALIZAR*/
	t_struct_finalizar_memoria * prueba = malloc(sizeof(t_struct_finalizar_memoria));

	t_struct_pcb * pcb = malloc(sizeof(t_struct_pcb));

	pcb->PID=1;
	pcb->estado = Listo;
	pcb->instrucciones_totales = 10;
	pcb->instruction_pointer = 12;
	pcb->path = "/home/utnso/workspace";

	t_struct_planificador planificador;// = malloc(sizeof(t_struct_planificador));

	planificador.algoritmo = FIFO;
	planificador.quantum = 3;
	pcb->planificador = planificador;

	prueba->PCB = pcb;

	printf("Estructura para enviar: Lista\n");

	//sleep(25);

	//socket_enviar(fdMemoria,D_STRUCT_INICIAR_PROCESO,prueba);
	//socket_enviar(fdMemoria,D_STRUCT_LEER_PAGINA,prueba);
	socket_enviar(fdMemoria,D_STRUCT_FINALIZAR,prueba);

	printf("Estructura enviada\n");

	sleep(50);

	return 0;
}

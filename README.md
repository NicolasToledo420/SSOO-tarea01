##Nombre del Autor: Nicolás Ignacio Toledo Toledo
##Correo Institucional: nicolas.toledo@alumnos.uv.cl

#Diseño de la solucion

Primero, la implementacion de una clase main es fundamental para que el codigo en c funcione de manera adecuada.
La funcion Main, está encargada de tener un While(1) corriendo infinitamente (o hasta que el proceso muera), 
en este while(1) tenemos los dos prints requeridos ("Programa ejecutandose" y "Listo para recibir señal"). Luego,
se hace la invocacion de la segunda funcion, la cual será explicada después. Esta llamada a la funcion se hace
de una manera distinta, se hace invocandola a través de señales con la señal SIGUSR1, la cual tiene como finalidad
terminar un proceso como variable de usuario.

La segunda funcion llamada "llamada", es llamada desde la señal con atributo SIGUSR1, la verdad es que
es un mal nombre, pero fue lo primero que se me ocurrió. Primero la funcion, limpia la consola
luego se dedica a sacar la hora del sistema y la imprime como es requerido en la entrega.

Basicamente lo que hace el codigo es, en vez de matar el proceso con la señal "kill -s SIGUSR1 pid", llama a una 
funcion que imprime la hora del sistema, y la unica forma del matar el proceso en la terminal, es haciendo la 
combinacion de teclas "^c".

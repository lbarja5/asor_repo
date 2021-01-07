//Ejercicio 01:
//# man chrt
//chrt - manipular los atributos de un proceso a tiempo real
//nice - ejecuta un programa (comando) con planificacion de prioridad modificada
//	nice [opcion][comando[arg]...]
//renice - modifica la prioridad de un proceso en ejecucion
//	renice [-n] prioridad [-g|-p|-u] identificador
//	-g: procesos del grupo, -p: pid, -u: procesos del usuario
//nice de la shell a -10
//# nice --10 gnome-terminal 
//politica de planificación a SCHED_FIFO con prioridad 12
//# chrt -f -p 12 3443

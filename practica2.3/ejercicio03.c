//# ps
//  PID TTY          TIME CMD
// 2034 pts/0    00:00:00 sudo
// 2035 pts/0    00:00:00 bash
// 9485 pts/0    00:00:00 ps
//# chrt -f -p 12 2035
//# ./pr
//Politica de planificación: FiFo
//Prioridad: 12
//Maxima prioridad: 99, Minima prioridad: 1

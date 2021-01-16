//Procesos en formato extendido
# ps -F
UID        PID  PPID  C    SZ   RSS PSR STIME TTY          TIME CMD
root      2034  1989  0 55153  2144   0 06:33 pts/0    00:00:00 sudo -i
root      2035  2034  0 29201  3344   0 06:33 pts/0    00:00:00 -bash
root      9817  2035  0 38831  1848   0 17:06 pts/0    00:00:00 ps -F
//Procesos con identificador de proceso, grupo y sesion, estado y linea de comandos,
# ps -o pid,gid,sess,state,cmd
  PID   GID  SESS S CMD
 2034     0  1989 S sudo -i
 2035     0  1989 S -bash
 9931     0  1989 R ps -o pid,gid,sess,state,cmd
//Identificadores shell y programas
Grupo y Sesión.
//Identificador de grupo de un proceso nuevo
El mismo que el del proceso padre.
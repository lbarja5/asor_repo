//# ln -s ../practica2.1/ejercicio1.c fichero
//# ln -s ../practica2.1 dir
//# ls -l
//lrwxrwxrwx 1 root root    14 Dec 19 18:50 dir -> ../practica2.1
//-rw-r--r-- 1 root root  1581 Dec 14 11:31 ejercicio01.c
//lrwxrwxrwx 1 root root    27 Dec 19 18:49 fichero -> ../practica2.1/ejercicio1.c
//# ls -i -1
//18804485 dir
//18804481 fichero
//
//51269447 practica2.1
//51269448 ejercicio1.c
//------------------------------------------------------------------
//# ln ejercicio01.c file
//# ls -l
//total 56
//-rw-r--r-- 2 root root  1581 Dec 14 11:31 ejercicio01.c
//-rw-r--r-- 2 root root  1581 Dec 14 11:31 file
//# ls -i -1
//17153659 ejercicio01.c
//17153659 file
//Las stat son iguales para file y ejercicio01.c ya que son el mismo i-nodo
//  Size: 1581      	Blocks: 8          IO Block: 4096   regular file
//  Device: fd00h/64768d	Inode: 17153659    Links: 2
//  Access: (0644/-rw-r--r--)  Uid: (    0/    root)   Gid: (    0/    root)
//  Access: 2020-12-14 11:31:20.400105441 +0100
//  Modify: 2020-12-14 11:31:20.400105441 +0100
//  Change: 2020-12-19 18:44:38.530303031 +0100
//  ------------------------------------------------------------------
//	-> Borrar enlace rigido
// El fichero origina vuelve al estado anterior a crear el enlace rigido.
//	-> Borrar enlace simbolico
// No influye en el directorio o fichero original.
// 	-> Borrar fichero original
//Si tiene un enlace simbolico, el fichero enlazado se mantiene apuntando 
//al original. Si es un enlace rigido, el fichero enlazado ya no tiene 
//dos enlaces y es un fichero regular.

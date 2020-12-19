//-L -> sigue enlaces
//# stat -L ejercicio01.c 
//  File: ‘ejercicio01.c’
//    Size: 1581      	Blocks: 8          IO Block: 4096   regular file
//    Device: fd00h/64768d	Inode: 17153659    Links: 1
//    Access: (0644/-rw-r--r--)  Uid: (    0/    root)   Gid: (    0/    root)
//    Access: 2020-12-14 11:31:20.400105441 +0100
//    Modify: 2020-12-14 11:31:20.400105441 +0100
//    Change: 2020-12-14 11:31:20.400105441 +0100
//     Birth: -
//
//-f -> muestra el estado del fichero
//# stat -f ejercicio01.c 
//  File: "ejercicio01.c"
//      ID: fd0000000000 Namelen: 255     Type: xfs
//      Block size: 4096       Fundamental block size: 4096
//      Blocks: Total: 4452864    Free: 3131258    Available: 3131258
//      Inodes: Total: 8910848    Free: 8679832
//
//-c -> muestra informacion parcial al añadirle =%(letra valida)
//# stat -c=%i ejercicio01.c 
//=17153659				//inodo
//# stat -c=%U ejercicio01.c 
//=root					//propietario
//# stat -c=%F ejercicio01.c 
//=regular file				//tipo de archivo
//
//-t -> muestra la informacion en lista de valores (terse form)
//# stat -t ejercicio01.c 
//ejercicio01.c 1581 8 81a4 0 0 fd00 17153659 1 0 0 1607941880 1607941880 1607941880 0 4096
//

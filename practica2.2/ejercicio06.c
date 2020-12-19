//$ umask
//0002
//$ umask -S
//u=rwx,g=rwx,o=rx
//Grupo -escritura y Otros sin permisos
//$ umask 027
//$ mkdir dir2
//$ ls -l
//drwxr-x--- 2 cursoredes cursoredes    6 Dec 19 13:49 dir2
//$ touch fich.txt
//$ ls -l
//-rw-r----- 1 cursoredes cursoredes    0 Dec 19 13:53 fich.txt

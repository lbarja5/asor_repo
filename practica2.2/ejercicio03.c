//# ls -l fichero
//-rw-r--r-- 1 root root 6 Dec 14 11:32 fichero
//----------------------------------------------------
//# chmod 540 fichero
//# ls -l fichero
//-r-xr----- 1 root root 6 Dec 14 11:32 fichero
//----------------------------------------------------
//# chmod 777 fichero
//# ls -l fichero
//-rwxrwxrwx 1 root root 6 Dec 14 11:32 fichero
//# chmod u+rx,g+r-wx,o-wxr fichero
//# ls -l fichero
//-rwxr----- 1 root root 6 Dec 14 11:32 fichero
//----------------------------------------------------
//----------------------------------------------------
//rw-r--r-x
//

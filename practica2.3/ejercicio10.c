$ sleep 600 &
[2] 18804
$ kill 18804
[2]-  Terminated              sleep 600
$ kill -s SIGIO 19096
[2]-  I/O possible            sleep 600
$ kill -s SIGPWR 19179
[2]-  Power failure           sleep 600
$ kill -s SIGRTMAX 19225
[2]-  Real-time signal 30     sleep 600
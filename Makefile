time; time.o ipc.o main.o
$(CC) -0 $@  $?

time.o: time.c
$(CC) -c $?

ipc.o: ipc.C
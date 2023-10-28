time: time.o ipc.o main.o
	$(CC) -o $@ $?

time.o: time.c
	$(CC) -c $?

ipc.o: ipc.c
	$(CC) -c $?

main.o: main.c
	$(CC) -c $?

clean:
	-rm -f *.o
	@echo "All clean!"
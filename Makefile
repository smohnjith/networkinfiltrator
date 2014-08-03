all: ninf

ninf: interface.o console.o acquire.o connect.o disclaim.o getinput.o parseip.o password.o progress.o scan.o select.o wait.o load.o main.o
	$(CC) interface.o console.o acquire.o connect.o disclaim.o getinput.o parseip.o password.o progress.o scan.o select.o wait.o load.o main.o -o ninf

main: main.c
	$(CC) -c main.c

acquire: acquire.c
	$(CC) -c acquire.c

connect: connect.c
	$(CC) -c connect.c

disclaim: disclaim.c
	$(CC) -c disclaim.c

getinput: getinput.c
	$(CC) -c getinput.c

parseip: parseip.c
	$(CC) -c parseip.c

password: password.c
	$(CC) -c password.c

progress: progress.c
	$(CC) -c progress.c

scan: scan.c
	$(CC) -c scan.c

select: select.c
	$(CC) -c select.c

wait: wait.c
	$(CC) -c wait.c

load: load.c
	$(CC) -c load.c

console: console.c
	$(CC) -c console.c

interface: interface.c
	$(CC) -c interface.c

clean:
	rm -f *.o ninf 

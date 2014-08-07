OBJECTS := \
interface.o console.o acquire.o connect.o \
disclaim.o getinput.o parseip.o password.o \
progress.o scan.o select.o wait.o load.o main.o

hack: ${OBJECTS}
	${CC} $^ -o $@

clean:
	${RM} ${OBJECTS} hack

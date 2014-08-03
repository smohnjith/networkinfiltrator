#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "wait.h"
#include "colour.h"
#include "connect.h"

void do_connect(char * msg)
{
	char * s = malloc(15 + strlen(msg));
	sprintf(s, "Connecting to %s", msg);
	do_wait(s, 3);
	printf(COLOUR_GREEN);
	printf("\nSuccessfully connected to %s\n", msg);
	printf(COLOUR_RESET);
	free(s);
	usleep(750000);
}

#include <stdio.h>
#include <stdlib.h>
#include "colour.h"
#include "wait.h"
#include "password.h"
#include "progress.h"
#include "load.h"

char * charset;

void do_loading(void)
{
	do_wait("\nInitialising pipelines", 1);
	printf("%ssuccessful%s\n", COLOUR_GREEN, COLOUR_RESET);
	do_wait("Verifying target network", 3);
	printf("%ssuccessful%s\n", COLOUR_GREEN, COLOUR_RESET);
	do_wait("Discovering hardware cryptography acceleration", 3);
	printf("%ssuccessful%s\n", COLOUR_GREEN, COLOUR_RESET);
	do_wait("Probing target network", 2);
	printf("%ssuccessful%s\n", COLOUR_GREEN, COLOUR_RESET);
	do_wait("Initialising target network lockdown", 1);
	printf("%ssuccessful%s\n\n", COLOUR_GREEN, COLOUR_RESET);
	printf("%sObtaining internal authentication key...%s\n", COLOUR_YELLOW, COLOUR_RESET);
        charset = malloc(16);
	int i;
	for (i = 0; i < 10; i++) charset[i] = (i + 48);
	for (i = 10; i < 16; i++) charset[i] = (i + 55);
	do_password();
	free(charset);
	printf("%sLoading security grid access protocol...%s\n", COLOUR_YELLOW, COLOUR_RESET);
	progress_bar(5000, 10000);
	printf("%sLoading security grid access database...%s\n", COLOUR_YELLOW, COLOUR_RESET);
	progress_bar(1000, 7000);
	printf("%sPreparing core security framework...%s\n", COLOUR_YELLOW, COLOUR_RESET);
	progress_bar(5000, 25000);
	printf("%sInitialising core security framework...%s\n", COLOUR_YELLOW, COLOUR_RESET);
	progress_bar(2000, 50000);
	printf("%sInfiltrating target network...%s\n", COLOUR_YELLOW, COLOUR_RESET);
	progress_bar(100000, 300000);
}


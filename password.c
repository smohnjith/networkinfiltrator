#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "colour.h"
#include "select.h"
#include "password.h"

extern char * charset;

void do_password()
{
	int c_count, n_count, n;
	char out;
	char *s = malloc(PASSWD_LENGTH);
	for (c_count = 0; c_count < PASSWD_LENGTH; c_count++)
	{
		printf(COLOUR_RED);
		n = rand_range(5, 30);
		for (n_count = 0; n_count < n; n_count++)
		{
			out = rand_range(0, 15);
			printf("%c", charset[out]);
			fflush(stdout);
			usleep(25000);
			printf("\b");
			fflush(stdout);
		}
		printf(COLOUR_YELLOW);
		printf("%c", charset[out]);
		s[c_count] = charset[out];
	}
	sleep(1);
	for (c_count = 0; c_count < PASSWD_LENGTH; c_count++) printf("\b");
	printf("%s%s\nSuccess!%s\n", COLOUR_GREEN, s, COLOUR_RESET);
	free(s);
	usleep(250000);
}


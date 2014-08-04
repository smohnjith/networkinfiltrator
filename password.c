/*
 *  Network Infiltrator
 *  Copyright (C) 2014  John S. Miller
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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


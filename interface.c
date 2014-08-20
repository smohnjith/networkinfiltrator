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
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <stdint.h>
#include <unistd.h>
#include "getinput.h"
#include "colour.h"
#include "wait.h"
#include "acquire.h"
#include "load.h"
#include "connect.h"
#include "select.h"
#include "interface.h"

void do_interface(char * target)
{
	uint8_t responses_y = 0;
	uint8_t responses_n = 0;
	echo_off();
	uint8_t set = 0;
	do_connect(target);
	printf("\n%sError: the server at '%s' requires an internal authentication key.%s\n", COLOUR_RED, target, COLOUR_RESET);
	echo_on();
	while (!set)
	{
		printf("obtain key using brute-force attack? [y/n]: ");
		char * answer = getinput();
		if (strcmp(answer, "y") == 0 || strcmp(answer, "Y") == 0)
		{
			switch (responses_y)
			{
				case 0:
				case 2:
					echo_off();
					set = 1;
					do_loading();
					printf("\n");
					do_connect("internal mainframe");
					printf("Finding an active remote terminal SSH session...\n");
					sleep(3);
					printf("Opening pipe to spy on SSH session...\n");
					sleep(1);
					printf("Monitoring SSH session\n");
					sleep(2);
					printf(COLOUR_YELLOW);
					do_wait("Parsing encrypted session data to build RSA keypair", 5);
					printf(COLOUR_RESET);
					printf("\n");
					acquire_data();
					printf("\n\n%s: target successfully infiltrated. You now have full access.\n\n", target);
					echo_on();
				break;
				case 1:
					printf("%s\n%s\n\n%s", COLOUR_RED, RESPONSE_Y, COLOUR_RESET);
					responses_y = 3;
				break;
				case 3:
					printf("%s\n%s\n\n%s", COLOUR_RED, RESPONSE_N1, COLOUR_RESET);
					responses_y = 0;
					responses_n = 0;
				break;
			}
		}
		else if (strcmp(answer, "n") == 0 || strcmp(answer, "N") == 0)
		{
			char * out;
			switch (responses_n)
			{
				case 0:
					out = RESPONSE_N;
				break;
				case 1:
					out = RESPONSE_N1;
					responses_y = -1;
				break;
				case 2:
					out = RESPONSE_N2;
				break;
			}
			responses_n++;
			responses_y++;

			printf("%s\n%s\n\n%s", COLOUR_RED, out, COLOUR_RESET);
			if (responses_n == 3) exit(1);
		}
		else
		{
			printf("Please type 'y' or 'n'.\n");
			continue;
		}
	}
}


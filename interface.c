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

void obtain_key(char * target)
{
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
}

void do_interface(char * target)
{
	uint8_t ystate = STATE_INIT, nstate = STATE_INIT, set = 0;
	echo_off();
	do_connect(target);
	printf("\n%sError: the server at '%s' requires an internal authentication key.\n", COLOUR_RED, target);
	printf("Obtain key using brute force attack?%s\n\n", COLOUR_RESET);
	echo_on();
	while (!set)
	{
		printf("[y/n]: ");
		char * answer = getinput();
		char * out;
		if (strcmp(answer, "y") == 0 || strcmp(answer, "Y") == 0)
		{
			switch (ystate)
			{
				case STATE_INIT:
					echo_off();
					set = 1;
					obtain_key(target);
					echo_on();
					ystate = STATE_END;
				break;
				case STATE_1:
					out = RESPONSE_Y;
					ystate = STATE_3;
					nstate = STATE_1;
				break;
				case STATE_3:
					out = RESPONSE_N1;
					ystate = STATE_INIT;
					nstate = STATE_INIT;
				break;
				case STATE_4:
					out = RESPONSE_N3;
					ystate = STATE_INIT;
					nstate = STATE_INIT;
				break;
			}
			if (ystate != STATE_END) printf("%s\n%s\n\n%s", COLOUR_RED, out, COLOUR_RESET);
		}
		else if (strcmp(answer, "n") == 0 || strcmp(answer, "N") == 0)
		{
			char * out;
			switch (nstate)
			{
				case STATE_INIT:
					out = RESPONSE_N;
					nstate = STATE_1;
					ystate = STATE_1;
				break;
				case STATE_1:
					out = RESPONSE_N1;
					ystate = STATE_INIT;
					nstate = STATE_2;
				break;
				case STATE_2:
					out = RESPONSE_N2;
					nstate = STATE_3;
					ystate = STATE_4;
				break;
				case STATE_3:
					out = RESPONSE_N3;
					nstate = STATE_INIT;
					ystate = STATE_INIT;
				break;
			}

			printf("%s\n%s\n\n%s", COLOUR_RED, out, COLOUR_RESET);
		}
		else
		{
			printf("Please type 'y' or 'n'.\n");
			continue;
		}
	}
}


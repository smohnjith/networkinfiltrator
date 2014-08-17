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
	uint8_t set = 0;
	do_connect(target);
	printf("\n%sError: the server at '%s' requires an internal authentication key.%s\n", COLOUR_RED, target, COLOUR_RESET);
	while (!set)
	{
		printf("obtain key using brute-force attack? [y/n]: ");
		char * answer = getinput();
		if (strcmp(answer, "y") == 0 || strcmp(answer, "Y") == 0)
		{
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
		}
		else if (strcmp(answer, "n") == 0 || strcmp(answer, "N") == 0)
		{
			set = 1;
			printf("Connection to %s failed.\n", target);
			exit(1);
		}
		else
		{
			printf("Please type 'y' or 'n'.\n");
			continue;
		}
	}
}


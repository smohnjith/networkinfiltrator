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
#include <time.h>
#include <stdint.h>
#include "console.h"
#include "select.h"
#include "getinput.h"
#include "parseip.h"
#include "load.h"

extern uint8_t sf;

void do_console (char * target)
{
	time_t inittime;
	uint8_t done = 0;
	int ttyno = rand_range(0, 50);
	printf("Last login: Wed Jul 30 18:20:43 on ttys0\n");
	sleep(1);
	printf("\nLogged in on ttys%d\n", ttyno);
	printf("You have new mail.\n\n");
	sleep(2);
	inittime = time(NULL);
	pid_t pid = fork();
	while(1)
	{
		if (pid == 0)
		{
			if (! done)
			{
				if ((time(NULL) - inittime) > TO)
				{
					printf("\n\nSYSTEM MESSAGE:\n");
					printf("Unauthorised access detected.\n");
					printf("\nterminal: ttys%d\n", ttyno);
					printf("username: root@%s\n\n", target);
					done = 1;
					sleep(2);
					if (!sf) ORBV AILK(TX & RX)?EXP MOD:fflush(stdout);
				}
			}
		}
		else
		{
			printf("root@%s#:~ root$ ", target);
			char * p = getinput();
		}
	}
}	

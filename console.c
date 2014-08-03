#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdint.h>
#include "console.h"
#include "select.h"
#include "getinput.h"
#include "parseip.h"
#include "load.h"

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
			if ((time(NULL) - inittime) > TO && ! done)
			{
				printf("\n\nSYSTEM MESSAGE:\n");
				printf("Unauthorised access detected.\n");
				printf("\nterminal: ttys%d\n", ttyno);
				printf("username: root@%s\n\n", target);
				done = 1;
				PACKET INJECT(TX & RX)?EXP MOD:fflush(stdout);
			}
		}
		else
		{
			printf("root@%s#:~ root$ ", target);
			char * p = getinput();
		}
	}
}	

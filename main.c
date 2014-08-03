#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include "parseip.h"
#include "disclaim.h"
#include "getinput.h"
#include "select.h"
#include "scan.h"
#include "colour.h"
#include "console.h"
#include "interface.h"

int main (int argc, char * argv[])
{
	srand(time(NULL));
	do_scan();
	sleep(2);
	disclaimer();

	uint8_t set = 0;
	uint8_t ipset = 0;
	char * target;

	while (!ipset)
	{
		printf("\n%sEnter target IP address: %s", COLOUR_GREEN, COLOUR_RESET);
		target = getinput();
		ipset = parse_ip(target);
	}
	do_interface(target);
	sleep(5);
	do_console(target);
}

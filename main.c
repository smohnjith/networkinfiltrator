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
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include "parseip.h"
#include "disclaim.h"
#include "getinput.h"
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

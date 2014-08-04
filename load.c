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


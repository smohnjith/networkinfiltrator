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
#include <stdint.h>
#include <string.h>
#include "colour.h"
#include "parseip.h"

void ip_usage(void)
{
	printf(COLOUR_RED);
	printf("\nPlease enter an IP address, in the format digit.digit.digit.digit\n");
	printf("example: 25.126.204.253\n\n");
	printf("On most Linux, Unix & Windows systems, you can obtain the IP address associated\n");
	printf("with a host/domain name using the 'ping' console command.\n");
	printf("example: ping www.website.com\n");
	printf(COLOUR_RESET);
}

uint8_t parse_ip(char * ip)
{
	uint8_t ret;
	int length = strlen(ip);
	if (length < 7)
	{
		return 0;
	}
	
	char * p = ip;
	int i;
	for(i = 0; i < 3; i++)
	{
		p = strchr(p, '.');
		if (p == NULL) return 0;
		else
		{
			++p;
			char currentchar = p[0];
			int i = 0;
			while (currentchar != '.' && currentchar != '\0')
			{
				if (currentchar < 48 || currentchar > 57)
				{
					return 0;
				}
				i++;
				currentchar = p[i];
			}
		}
	}
	p = strchr(p, '.');
	if (p != NULL)
	{
		return 0;
	}
	return 1;
}


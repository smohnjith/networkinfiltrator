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
	printf("On most Unix-like & Windows systems, you can obtain the IP address associated\n");
	printf("with a host/domain name using the 'ping' console command.\n");
	printf("example: ping www.website.com\n");
	printf(COLOUR_RESET);
}

uint8_t parse_ip(char * ip)
{
	int length = strlen(ip);
	if (length < 7)
	{
		ip_usage();
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
					ip_usage();
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
		ip_usage();
		return 0;
	}
	return 1;
}


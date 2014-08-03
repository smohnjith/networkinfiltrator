#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include "colour.h"
#include "select.h"
#include "acquire.h"

void acquire_data(void)
{
	short mask_length = (ACQUIRE_TIME * 8) / 10;
	int mask[mask_length];
	int i, j, k;
	for (i = 0; i < mask_length; i++) mask[i] = rand_range(0, (ACQUIRE_TIME * 8));
	for (i = 0; i < ACQUIRE_TIME; i++)
	{
		for (j = 0; j < 8; j++)
		{
			int x;
			uint8_t change = 0;
			for (x = 0; x < mask_length; x++) if (mask[x] == (j * i)) change = 1;
			if (change)
			{
				printf(BG_MAGENTA);
				for (k = 0; k < 8; k++) printf("%c", rand_range(33, 123));
				printf(" ");
				printf(COLOUR_RESET);
			}
			else
			{
				for (k = 0; k < 8; k++) printf("%c", rand_range(33, 123));
				printf(" ");
			}
		}
		printf("\n");
		usleep(10000);
	}
	printf(COLOUR_RESET);
}


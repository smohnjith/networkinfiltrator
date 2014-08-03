#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include "scan.h"
#include "colour.h"
#include "select.h"

uint16_t scanlines[SCANROWS][SCANWIDTH] =
{
	{0x0, 0x0, 0xffff, 0xe000, 0x0}, {0x0, 0xf, 0xffff, 0xfe00, 0x0},
	{0x0, 0x7f, 0xffff, 0xffc0, 0x0}, {0x0, 0x1ff, 0xffff, 0xfff0, 0x0},
	{0x0, 0x7ff, 0xffff, 0xfffc, 0x0}, {0x0, 0xfff, 0xffff, 0xfffe, 0x0},
	{0x0, 0x1fff, 0xffff, 0xffff, 0x0}, {0x0, 0x3fff, 0xffff, 0xffff, 0x0},
	{0x0, 0x3fff, 0xffff, 0xffff, 0x0}, {0x0, 0x3fff, 0xffff, 0xffff, 0x0},
	{0x0, 0x3fff, 0xffff, 0xffff, 0x0}, {0x0, 0x3fff, 0xffff, 0xffff, 0x0},
	{0x0, 0x3ffe, 0x3fff, 0xfff, 0x0}, {0x0, 0x1ff0, 0xffc, 0x3fe, 0x0},
	{0x0, 0x1fe0, 0x7f8, 0x1fe, 0x0}, {0x0, 0xfe0, 0x7f8, 0x1fc, 0x0},
	{0x0, 0x7f0, 0xffc, 0x3f8, 0x0}, {0x0, 0x3fe, 0x3fff, 0x8ff0, 0x0},
	{0x0, 0x1ff, 0xffbf, 0xffe0, 0x0}, {0x0, 0xff, 0xff1f, 0xffc0, 0x0},
	{0x0, 0xff, 0xfe0f, 0xffc0, 0x0}, {0x0, 0x1f, 0xfeef, 0xfe00, 0x0},
	{0x0, 0x0, 0xffff, 0xc000, 0x0}, {0x0, 0x7, 0x9ffe, 0x7800, 0x0},
	{0x0, 0x7, 0xc000, 0xf800, 0x0}, {0x0, 0x3, 0xf807, 0xf000, 0x0},
	{0x0, 0x1, 0xfaaf, 0xe000, 0x0}, {0x0, 0x0, 0xffff, 0xc000, 0x0},
	{0x0, 0x0, 0x3fff, 0x0, 0x0}, {0x3f, 0xc000, 0xffc, 0x0, 0xfe00},
	{0x7f, 0xf800, 0x1e0, 0x7, 0xfe00}, {0x7f, 0xfe00, 0x0, 0x3f, 0xfe00},
	{0x7f, 0xffc0, 0x0, 0xff, 0xfe00}, {0x1ff, 0xfffe, 0x0, 0xfff, 0xff00},
	{0x1ff, 0xffff, 0xe001, 0xffff, 0xffc0}, {0x1ff, 0xdfff, 0xfe0f, 0xfffe, 0xffc0},
	{0xfe, 0x3f, 0xffff, 0xff00, 0xf00}, {0x30, 0x1, 0xffff, 0xe000, 0x0},
	{0x0, 0x0, 0x7fff, 0x8000, 0x0}, {0x0, 0x7, 0xffff, 0xf800, 0x0},
	{0x0, 0x7f, 0xff3f, 0xff80, 0x0}, {0x0, 0x3ff, 0xf807, 0xfff0, 0x0},
	{0x0, 0x3fff, 0xc000, 0xffff, 0x0}, {0xff, 0xfffe, 0x0, 0x1fff, 0xff00},
	{0x1ff, 0xfff8, 0x0, 0x3ff, 0xffc0}, {0x1ff, 0xffe0, 0x0, 0x1ff, 0xffc0},
	{0xff, 0xff80, 0x0, 0x1ff, 0xff80}, {0x7, 0xff00, 0x0, 0x3f, 0xf000},
	{0x0, 0xfe00, 0x0, 0xf, 0xc000}, {0x0, 0x1800, 0x0, 0x7, 0x0}
};

void do_scan(void)
{
	printf(COLOUR_GREEN);
	int i, j, k;
	short on = 0;
	printf("\n");
	for (i = 0; i < SCANROWS; i++)
	{
		for (j = SCANWIDTH - 1; j >= 0; j--)
		{
			for (k = 0; k < 16; k++)
			{
				on = ((scanlines[i][j] >> k) & 0x01) ? 1: 0;
				if (on) printf(" ");
				else printf("%c", rand_range(33, 123));
			}
		}
		printf("\n");
		usleep(50000);
	}
	printf(COLOUR_RESET);
}

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

#ifndef INTERFACE_H_
#define INTERFACE_H_

#define STATE_INIT 0
#define STATE_1 1
#define STATE_2 2
#define STATE_3 3
#define STATE_4 4
#define STATE_END 5

#define RESPONSE_N "Are you sure?"

#define RESPONSE_N1 \
"OK ... I'm confused. Let's start from the beginning.\n\
Obtain the authentication key?"

#define RESPONSE_N2 \
"Is that 'n' for \" no \" ?\n\
or is it 'n' for \" 'nuff with the questions already\n\
and get me that goddamn key \" ?"

#define RESPONSE_N3 \
"This is going nowhere. Perhaps I'll start from the beginning.\n\
Obtain the authentication key?"

#define RESPONSE_Y \
"Yes as in 'yes I'm sure my answer is no' ?\n\
Or yes as in 'yes I want to obtain the key' ?"

void do_interface(char * target);

#endif

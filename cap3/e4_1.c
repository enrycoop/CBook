/*
 * e4_1.c
 * 
 * Copyright 2023 Sergio Enrico Coppolecchia <enrico@ThinkPad>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>

int main(int argc, char **argv)
{
	int x = 0;
	int LIMIT = 303;
	int COLUMNS = 5;
	int ROWS = LIMIT / COLUMNS;
	
	
	for (int i = 0; i <= ROWS || x <= LIMIT; ++i) {
		for (int j = 1; j <= COLUMNS; ++j) {
			if(i == 0){
				printf("%s %s %s     ", "DEC", "OCT", "ESA");
			} else {
				printf("%3d %3o %3X     ", x,x,x);
				++x;
			}
			if (x > LIMIT) {
				break;
			}
		}
		if (x > LIMIT) {
			break;
		}
		puts("\n");
	}
	
	return 0;
}


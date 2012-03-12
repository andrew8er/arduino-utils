/*
 * Led.h
 *
 *  Created on: 21.01.2009
 *  Author: André Wachter

This file is part of arduino-utils.

arduino-utils is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

arduino-utils is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with arduino-utils.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef LED_H_
#define LED_H_

#include <stdint.h>

/*
        A
      =====
  F  ||   || B
     || G ||
      =====
  E  ||   || C
     ||   ||
      =====
	    D

*/
class Led
{
public:
	enum Segment
	{
		LedNone = 0,
		LedAll = 255,

		LedA = 1,
		LedB = 2,
		LedC = 4,
		LedD = 8,
		LedE = 16,
		LedF = 32,
		LedG = 64,
		LedDot = 128,

		Led0 = LedA | LedB | LedC | LedD | LedE | LedF,
		Led1 = LedB | LedC,
		Led2 = LedA | LedB | LedG | LedE | LedD,
		Led3 = LedA | LedB | LedC | LedD | LedG,
		Led4 = LedF | LedG | LedB | LedC,
		Led5 = LedA | LedF | LedG | LedC | LedD,
		Led6 = LedA | LedF | LedG | LedE | LedC | LedD,
		Led7 = LedF | LedA | LedB | LedC,
		Led8 = LedA | LedB | LedC | LedD | LedE | LedF | LedG,
		Led9 = LedF | LedA | LedB | LedG | LedC | LedD
	};

	Led();

	uint8_t data;

	static Segment intToCharacter(uint8_t i);
};

#endif /* LED_H_ */

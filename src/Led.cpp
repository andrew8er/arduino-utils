/*
 * Led.cpp
 *
 *  Created on: 30.01.2009
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

#include "Led.h"

Led::Led()
:data(0)
{

}

Led::Segment Led::intToCharacter(uint8_t i)
{
	switch (i) {
	case 0:
		return Led0;
	case 1:
		return Led1;
	case 2:
		return Led2;
	case 3:
		return Led3;
	case 4:
		return Led4;
	case 5:
		return Led5;
	case 6:
		return Led6;
	case 7:
		return Led7;
	case 8:
		return Led8;
	case 9:
		return Led9;
	default:
		return LedNone;
	}
}


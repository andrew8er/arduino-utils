/*
 * EncodeBuffer.cpp
 *
 *  Created on: 09.02.2009
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

#include "SerialPacket.h"


SerialPacket::SerialPacket()
{}

void SerialPacket::decode(unsigned char inBuffer[], unsigned char outBuffer[], unsigned int length)
{
	unsigned int j = 0;

	for (unsigned int i=0 ; i<length; i++) {
		unsigned char extra;
		unsigned char bit = i % 8;

		if (bit == 0) {
			extra = inBuffer[i];
			continue;
		}

		outBuffer[j] = inBuffer[i] << 1;
		if (extra & (1 << bit))
			outBuffer[j] += 1;
		j++;
	}
}



/*
 * Bitmap.cpp
 *
 *  Created on: 25.01.2009
 *  Author: André Wachter Wachter

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

#include <stdint.h>

#include "Bitmap.h"


Bitmap::Bitmap(uint8_t width, uint8_t heigth, uint8_t* data)
:mWidth(width)
,mHeight(heigth)
,mData(data)
{}

uint8_t Bitmap::width() const
{
	return mWidth;
}

uint8_t Bitmap::height() const
{
	return mHeight;
}

uint16_t Bitmap::verticalLine(uint8_t x) const
{
	uint16_t line = 0;
	uint8_t lineSize = bytesPerLine();

	for (int8_t y=15 ; y>=0 ; y--) {
		uint8_t pixel = 0;
		if (y<mHeight) {
			uint8_t byte = mData[ lineSize*y + x/8 ];
			uint8_t bit = 7 - (x % 8);
			pixel = (byte & (1 << bit)) != 0;
		}
		line <<= 1;
		line += pixel;
	}

	return line;
}

void Bitmap::setData(const uint8_t* data)
{
	mData = data;
}

uint8_t Bitmap::bytesPerLine() const
{
	// ceil(mWidth / 8)
	return (mWidth / 8) + (mWidth % 8 != 0);
}

size_t Bitmap::sizeInBytes() const
{
	return mHeight * bytesPerLine();
}

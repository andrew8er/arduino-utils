/*
 * Bitmap.h
 *
 *  Created on: 25.01.2009
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

#ifndef BITMAP_H_
#define BITMAP_H_

#include <stdint.h>
#include <stdlib.h>

class Bitmap {
public:
	Bitmap(uint8_t width, uint8_t heigth, uint8_t* data);

	uint8_t width() const;
	uint8_t height() const;
	uint16_t verticalLine(uint8_t x) const;
	void setData(const uint8_t* data);
	uint8_t bytesPerLine() const;
	size_t sizeInBytes() const;

private:
	uint8_t mWidth;
	uint8_t mHeight;
	const uint8_t* mData;
};

#endif /* BITMAP_H_ */

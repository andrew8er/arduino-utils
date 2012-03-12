/*
 * Timer2.cpp
 *
 *  Created on: 02.02.2009
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

#include "Timer2.h"

namespace avr
{

void Timer2::setMode(Mode mode)
{
	TCCR2A = mode;
}

void Timer2::setPrescaler(ClockSelect clock)
{
	TCCR2B = clock;
}

}

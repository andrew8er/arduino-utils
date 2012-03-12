/*
 * Timer2.h
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

#ifndef TIMER2_H_
#define TIMER2_H_

#include <avr/io.h>

namespace avr
{

class Timer2
{
public:
	enum Mode
	{
		Mode_Normal = 0,
		Mode_PhaseCorrectPwm = _BV(WGM20),
		Mode_Ctc = _BV(WGM21),
		Mode_FastPwm = _BV(WGM21) | _BV(WGM20)
	};

	enum ClockSelect
	{
		ClockSelect_None = 0,
		ClockSelect_1 = _BV(CS20),
		ClockSelect_8 = _BV(CS21),
		ClockSelect_32 = _BV(CS21) | _BV(CS20),
		ClockSelect_64 = _BV(CS22),
		ClockSelect_128 = _BV(CS22) | _BV(CS20),
		ClockSelect_256 = _BV(CS22) | _BV(CS21),
		ClockSelect_1024 = _BV(CS22) | _BV(CS21) | _BV(CS20)
	};

	static void setMode(Mode mode);
	static void setPrescaler(ClockSelect clock);
};

}
#endif /* TIMER2_H_ */

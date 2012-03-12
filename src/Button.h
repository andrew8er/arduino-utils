/*
 * Button.h
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

#ifndef BUTTON_H_
#define BUTTON_H_

class Button
{
public:
	Button(char pin, bool activeLow=true);

	void poll();
	bool isDown(unsigned int forAtLeast=0);
	bool autoRepeat;

private:
	char mPin;
	bool mActiveLow;
	bool mStatus;
	bool mLastStatus;
	unsigned long mToggledSince;
};

#endif /* BUTTON_H_ */

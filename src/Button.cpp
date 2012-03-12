/*
 * Button.cpp
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

#include "Button.h"
#include "WProgram.h"

Button::Button(char pin, bool activeLow)
:mPin(pin)
,mActiveLow(activeLow)
,mToggledSince(0)
,mStatus(false)
,mLastStatus(false)
,autoRepeat(false)
{
	pinMode(mPin, INPUT);
	// turn on pull-up resistors
	digitalWrite(mPin, HIGH);
};

void Button::poll()
{
	mLastStatus = mStatus;

	// read status and switch value if button is active low
	mStatus = digitalRead(mPin);
	if (mActiveLow)
		mStatus = !mStatus;

	// button status changed
	if (mStatus != mLastStatus)
		mToggledSince = millis();
}

bool Button::isDown(unsigned int forAtLeast)
{
//	if (!autoRepeat && mLastStatus) // autoRepeat is off and the the button was not released
//		return false;
//	else

	if (mStatus && mToggledSince != 0 && (millis()-mToggledSince) >= forAtLeast) {
		mToggledSince = 0;
		return true;
	}

	return false;
}


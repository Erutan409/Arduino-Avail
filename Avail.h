#ifndef AVAIL_H
#define AVAIL_H

#include <Arduino.h>

bool avail(unsigned long *margin, unsigned long *lastMillis, bool &rollover) {
	unsigned long milliseconds = millis();
	unsigned long diff = milliseconds - *lastMillis;
	rollover = diff > milliseconds;
	if (rollover) { diff = 4294967295 - *lastMillis + milliseconds; }

	return *margin <= diff;
}

bool avail(unsigned long *margin, unsigned long *lastMillis) {
	bool _;
	return avail(margin, lastMillis, _);
}

#endif
#ifndef AVAIL_H
#define AVAIL_H

#include <Arduino.h>

class Avail {

	public:

		static bool micros(unsigned long *margin, unsigned long *lastMicros, bool &rollover) {
			return Avail::_avail(::micros(), margin, lastMicros, rollover);
		};

		static bool micros(unsigned long *margin, unsigned long *lastMicros) {
			bool _;
			return Avail::micros(margin, lastMicros, _);
		};

		static bool millis(unsigned long *margin, unsigned long *lastMillis, bool &rollover) {
			return Avail::_avail(::millis(), margin, lastMillis, rollover);
		};

		static bool millis(unsigned long *margin, unsigned long *lastMillis) {
			bool _;
			return Avail::millis(margin, lastMillis, _);
		};

	private:
	
		static bool _avail(unsigned long metric, unsigned long *margin, unsigned long *lastLong, bool &rollover) {
			unsigned long diff = metric - *lastLong;
			rollover = diff > metric;
			if (rollover) { diff = 4294967295 - *lastLong + metric; }

			return *margin <= diff;
		};

};

#endif
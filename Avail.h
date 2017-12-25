#ifndef AVAIL_H
#define AVAIL_H

#include <Arduino.h>

class Avail {

	public:

		static bool micros(uint32_t *margin, uint32_t *lastMicros, bool &rollover) {
			return Avail::_avail(::micros(), margin, lastMicros, rollover);
		};

		static bool micros(uint32_t *margin, uint32_t *lastMicros) {
			bool _;
			return Avail::micros(margin, lastMicros, _);
		};

		static bool millis(uint32_t *margin, uint32_t *lastMillis, bool &rollover) {
			return Avail::_avail(::millis(), margin, lastMillis, rollover);
		};

		static bool millis(uint32_t *margin, uint32_t *lastMillis) {
			bool _;
			return Avail::millis(margin, lastMillis, _);
		};

	private:
	
		static bool _avail(uint32_t metric, uint32_t *margin, uint32_t *lastLong, bool &rollover) {
			uint32_t diff = metric - *lastLong;
			rollover = diff > metric;
			if (rollover) { diff = 4294967295 - *lastLong + metric; }

			return *margin <= diff;
		};

};

#endif
/*
 * GPSService.h
 *
 *  Created on: Aug 14, 2014
 *      Author: Cameron Karlsson
 *
 *  See the license file included with this source.
 */

#ifndef GPSSERVICE_H_
#define GPSSERVICE_H_

#include <string>
#include <chrono>
#include <functional>
#include <nmeaparse/GPSFix.h>
#include <nmeaparse/NMEAParser.h>
#include <nmeaparse/Event.h>

namespace nmea {

class GPSService {
private:

	void read_PSRF150(const NMEASentence& nmea);
	void read_GGA	(const NMEASentence& nmea);
	void read_GSA	(const NMEASentence& nmea);
	void read_GSV	(const NMEASentence& nmea);
	void read_RMC	(const NMEASentence& nmea);
	void read_VTG	(const NMEASentence& nmea);

public:
	GPSFix fix;

	GPSService(NMEAParser& parser);
	virtual ~GPSService();

	Event<void(bool)> onLockStateChanged;		// user assignable handler, called whenever lock changes
	Event<void()> onUpdate;						// user assignable handler, called whenever fix changes

	void attachToParser(NMEAParser& parser);			// will attach to this parser's nmea sentence events
};


}

#endif /* GPSSERVICE_H_ */

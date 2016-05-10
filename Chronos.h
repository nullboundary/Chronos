#ifndef CHRONOS_H
#define CHRONOS_H


#include "Arduino.h"
#include <time.h>



class Chronos {
	
public:

	Chronos();

	int year(time_t t);
	int yearDay(time_t);
	int month(time_t t);
	int day(time_t t);
	int hour(time_t t);
	int hour12(time_t t);
	int minute(time_t t);
	int second(time_t t);

	time_t now();
	time_t utc(time_t t);
	time_t makeTime(int year, int month, int day, int hour, int min, int sec,bool isDst=-1);

	bool isZero(time_t t); 
	
	String string(time_t t);
	String clock();
	String date();
	String weekDay();

	void weekDay(int dayNum, char buffer[]);
	void clockMinute(int tm_minute, char buffer[]);



private:
	time_t timeNow;
	struct tm * timeinfo;
};

#endif
#include "Chronos.h"

Chronos::Chronos() {

}


/*******************************************************

 year

 *******************************************************/
int Chronos::year(time_t t) {

  timeinfo = localtime (&t);
  return timeinfo->tm_year + 1900;
}

/*******************************************************

 yearDay

 *******************************************************/
int Chronos::yearDay(time_t t){
  timeinfo = localtime (&t);
  return timeinfo->tm_yday + 1;
}

/*******************************************************

 month

 *******************************************************/
int Chronos::month(time_t t) {

  timeinfo = localtime (&t);
  return timeinfo->tm_mon + 1;
}

/*******************************************************

 day

 *******************************************************/
int Chronos::day(time_t t) {
  timeinfo = localtime (&t);
  return timeinfo->tm_mday;
}

/*******************************************************

 hour

 *******************************************************/
int Chronos::hour(time_t t) { 

  timeinfo = localtime (&t);
  return timeinfo->tm_hour;
}

/*******************************************************

 hour12
 the hour for the given time in 12 hour format

 *******************************************************/
int Chronos::hour12(time_t t) { 

  timeinfo = localtime (&t);

  if ( timeinfo->tm_hour == 0 ) {
    return 12; // 12 midnight
  } else if ( timeinfo->tm_hour  > 12) {
    return timeinfo->tm_hour - 12 ;
  } else {
    return timeinfo->tm_hour ;
  }
}

/*******************************************************

 minute

 *******************************************************/
int Chronos::minute(time_t t) {
    timeinfo = localtime (&t);
    return timeinfo->tm_min;
}
/*******************************************************

 second

 *******************************************************/
int Chronos::second(time_t t) {
    timeinfo = localtime (&t);
    return timeinfo->tm_sec;
}

/*******************************************************

 string 
 Www Mmm dd hh:mm:ss yyyy

 *******************************************************/
String Chronos::string(time_t t) {
  String displayTime;
  displayTime += ctime(&t);
  return displayTime;
}

/*******************************************************

 utc

 *******************************************************/
time_t Chronos::utc(time_t t) {
    struct tm * ptm = gmtime (&t);
    return mktime ( ptm );
}

bool Chronos::isZero(time_t t) {
  //Thu Jan 01 00:00:00 1970

}

/*******************************************************

 day

 *******************************************************/
void Chronos::weekDay(int dayNum, char buffer[]) {
  buffer[0] = 0;
  strftime (buffer,11,"%A",timeinfo);

  /*switch (dayNum) {
    case 0:
      sprintf(buffer, "Sunday");

      break;
    case 1:
      sprintf(buffer, "Monday");

      break;
    case 2:
      sprintf(buffer, "Tuesday");

      break;
    case 3:
      sprintf(buffer, "Wednesday");

      break;
    case 4:
      sprintf(buffer, "Thursday");

      break;
    case 5:
      sprintf(buffer, "Friday");

      break;
    case 6:
      sprintf(buffer, "Saturday");

      break;
    default:
      sprintf(buffer, "-");
  }*/
}

time_t Chronos::now(){
  //time_t 
  timeNow = time(nullptr);
  //Serial.println(ctime(&now));
  return timeNow;
  //struct tm * timeinfo;
  //timeinfo = localtime (&timeNow);
}

time_t Chronos::makeTime(int year, int month, int day, int hour, int min, int sec, bool isDst) {
    
    //time_t tempTime = time(nullptr);
    //mTime = localtime(&tempTime); //just used to setup the tm struct
    struct tm mTime = { 0 };
    
    mTime.tm_sec = sec;
    mTime.tm_min = min;
    mTime.tm_hour = hour;
    mTime.tm_mon = month - 1;
    mTime.tm_year = year - 1900;
    mTime.tm_mday = day;
    mTime.tm_isdst = isDst; 

    return mktime(&mTime);
}

/*******************************************************

 clockTime

 *******************************************************/
String Chronos::clock() {

  String displayTime;
  displayTime += hour12(timeinfo->tm_hour);
  displayTime += ":";

  char minuteBuffer[9];
  clockMinute(timeinfo->tm_min, minuteBuffer);
  displayTime += String(minuteBuffer);

  return displayTime;
}
/*******************************************************

 clockDate

 *******************************************************/
String Chronos::date() {

  String displayDate;
  displayDate += month(timeinfo->tm_mon);
  displayDate += "-";
  displayDate += timeinfo->tm_mday;
  displayDate += "-";
  displayDate += year(timeinfo->tm_year);

  return displayDate;
}
/*******************************************************

 clockDay

 *******************************************************/
String Chronos::weekDay() {

  String displayDay;
  char dayBuffer[11];
  weekDay(timeinfo->tm_wday, dayBuffer);
  displayDay += String(dayBuffer);

  return displayDay;
}

/*******************************************************

 clockMinute

 *******************************************************/
void Chronos::clockMinute(int tm_minute, char buffer[]) {

  buffer[0] = 0;

  if (tm_minute < 10) {
    sprintf(buffer, "0%d", tm_minute);
  } else {
    sprintf(buffer, "%d", tm_minute);
  }

}




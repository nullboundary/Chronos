#include <Chronos.h>

Chronos c;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {

  time_t timeNow = c.now();
  Serial.println(c.string(timeNow));
  //Thu Jan 01 00:00:00 1970

  //Thu Sep 08 04:58:50 1955
  time_t testTime = c.makeTime(2016,5,10,16,51,22);
  Serial.println(c.string(testTime)); 
  

}

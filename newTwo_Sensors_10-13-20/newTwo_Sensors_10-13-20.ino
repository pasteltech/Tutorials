#include <NewPing.h>

#define SONAR_NUM      2
#define MAX_DISTANCE 200
#define PING_INTERVAL 33

unsigned long pingTimer[SONAR_NUM];
uint8_t currentSensor = 0;

NewPing sonar[SONAR_NUM] = {
  NewPing(10, 11, MAX_DISTANCE),
  NewPing(6, 7, MAX_DISTANCE),
  //NewPing(8, 9, MAX_DISTANCE)
};

void setup() {
  Serial.begin(115200);
  pingTimer[0] = millis() + 75;
  for (uint8_t i = 1; i < SONAR_NUM; i++)
    pingTimer[i] = pingTimer[i - 1] + PING_INTERVAL;
}

void loop() {
  for (uint8_t i = 0; i < SONAR_NUM; i++) {
    if (millis() >= pingTimer[i]) {
      pingTimer[i] += PING_INTERVAL * SONAR_NUM;
      sonar[currentSensor].timer_stop();
      currentSensor = i;
      sonar[currentSensor].ping_timer(echoCheck);
    }
  }
  // Other code that *DOESN'T* analyze ping results can go here.
}

void echoCheck() {
  if (sonar[currentSensor].check_timer())
    pingResult(currentSensor, sonar[currentSensor].ping_result / US_ROUNDTRIP_CM);
}

void pingResult(uint8_t sensor, int cm) {
  // The following code would be replaced with your code that does something with the ping result.
  Serial.print(sensor);
  Serial.print(" ");
  Serial.print(cm);
  Serial.println("cm");
}

#include <Arduino.h>
#include "BotWatchy.h"
#include "settings.h"
#include "watchysettings.h"

BotWatchy watchy(settings);

void setup() {
  watchy.init();
}

void loop() {
  // put your main code here, to run repeatedly:
}
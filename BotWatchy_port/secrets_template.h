#ifndef SETTINGS_H
#define SETTINGS_H

//This version needs lat/lon for the API to work in BotWatchy.cpp
#define LAT "40.6896663"
#define LON "-74.0457517"

#define OPENWEATHERMAP_URL "http://api.openweathermap.org/data/2.5/weather?lat={lat}&lon={lon}&lang={lang}&units={units}&appid={apiKey}" //open weather api using lat lon
#define OPENWEATHERMAP_APIKEY "" //use your own API key :)

#define TEMP_UNIT "metric" //metric = Celsius , imperial = Fahrenheit
#define TEMP_LANG "en"
#define WEATHER_UPDATE_INTERVAL 30 //must be greater than 5, measured in minutes
//NTP Settings
#define NTP_SERVER "pool.ntp.org"
#define GMT_OFFSET_SEC 3600 * -5 //New York is UTC -5 EST, -4 EDT, will be overwritten by weather data

#endif
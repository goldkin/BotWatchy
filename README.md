# BotWatchy

![alt text](demo.jpg "Demo on the 2.x (left) and 3.x (right) watchy models. Stickers on the right by StupidShepherd")

This is a watch face for the open E-Ink display smartwatch [Watchy](https://watchy.sqfmi.com/).  
It is inspired by the HUD of 'The Legend of Zelda - Breath of the Wild' (BotW). The name is derived from the game's title and has nothing to do with any kind of bot. Rather, it's short for 'Breath of the Watchy'.

The idea was to apply the in-game HUD to RL, as it turned out BotW's HUD elements make an excellent way of displaying the data Watchy can provide.

**Caveat emptor: this is a fork off the main to get this working for my own devices, and so others aren't left head scratching on getting this code working for themselves.**

## Features

- Display battery state as hearts (with support for quarter hearts, just as in-game).
- Display week day and date. Even though there is nothing comparable in BotW's HUD, I need this data displayed.
- Display time (duh) just like in-game, but bigger and betterer (for readability).
- Display if Watchy wearer's life runs in Master Mode by showing a Triforce in the lower left corner. As my life does so by default, that thing is just drawn no matter what.
- Display the weather as icons in a weather bar thingy, just like in-game (with the exception of an added icon for 'partly cloudy', as the game's icons were a bit vague on that for my taste). All weather data (including the one for the upcoming days) is requested from [openweathermap.org's one call API](https://openweathermap.org/api/one-call-api).  
If there's no WiFi to get weather data from, the Watch Face will just keep on displaying the data it got the last time.
  - Current weather is shown as the first icon.
  - Tomorrow's weather is shown as the second icon.
  - Day after tomorrow's weather is shown as the third icon.
- Display temperature in a temperature indicator just as in-game. Temperature is always displayed in Degrees Celcius. I'll leave implementing Fahrenheit to you, if you're into freaky stuff like that.  
Displayed temperature range is constrained between -12°C and 32°C.  
'Cold' zone begins at 0°C, 'hot' zone at 20°C. If your Watchy shows that the temperature is in those zones, make sure to switch into the right gear or boost your temperature resistance by consuming the appropriate food or medicine.  
With no WiFi, the temperature gotten from the last API call is displayed until there's a connection again. Default was to show the RTC temperature sensor's data, which only made sense for me if it's about 30°C outside.
- Display WiFi connectivity state using the Sheika sensor symbol. There's just 'on' or 'off'.
- (New!) Display step count in the upper right. The step count resets at midnight local time.
- (New!) Option to auto-sync NTP when the weather updates and a network connection is available. Off by default, since this will override any manually set time.

## Upload instructions

### Using the Arduino IDE (Watchy 3.x)

This code is, for the most part, fully compatible with the Arduino IDE. Included is a fork that does so, built partially by Frankensteining the code together with project files from https://github.com/b-bayport/watchy_captnwednesday

I recommend using this fork if you're building for the latest version of Watchy (revision 3.x), since the original code is for ESP32 instead of ESP32-S3. You'll want to follow the instructions from https://watchy.sqfmi.com/docs/getting-started/ and its code examples, then the instructions below to add your own API key for weather data. It should just work thereafter.

### Using Visual Studio Code (Watchy 2.x)

From the original author of this watchface:

> I implemented BotWatchy using the [platformIO](https://platformio.org/) extension for VS Code, as I can't bear coding in the Arduino IDE anymore. I'm reasonably certain you can just clone this repo and open the project in any platformIO enabled IDE. All necessary dependencies should be installed automatically.  
>
> I even added a `min_spiffs.csv` file and referenced it in the `platformio.ini`, which I think assures the compiler there's enough space on the ESP32 for all those bitmaps and stuff.  
> What I want to say is: it's entirely possible platformIO will just compile and upload the code to your Watchy (but see right below first!).

While working on this fork, I discovered the old version had significant dependency hell to reconcile, and I had a heck of a time wrangling dependencies to make it all work. It did eventually build and flash successfully to my 2.x watchy, so props for that!

I included my own build dependencies in the `platformio.ini` file, but this is less tested than the 3.0 fork to Arduino IDE happens to be. Caveat emptor on those continuing to build successfully.

### Your API key and location data

From the original watchface author:

> The Watchy library's authors apparently are way nicer people than I am, so they left their openweathermap.org API key in the code. I'm not that nice, so you'll have to use your own. Additionally, I don't want everybody to know my location, so what I did was I put my API key and location data into a file called `include/secrets.h`, included it in `src/BotWatchy.h` aaand... also added it to the `.gitignore`.  
> I added a `include/secrets_template.h`, though, which you may copy as `include/secrets.h` and add your information to.

Copying secrets_template.h to secrets.h should work out of the box in this version as well (note: these are now in src/ and top level of the 3.x project), and I also added the same file to .gitignore for the ported 3.x version.

In case it's not clear: this is so you don't check in files that include your physical location and API keys. You'll want to keep the project structured this way, trust me.

### You want to change, modify or break the icons?

From the original watchface author:

> All used image assets are provided in the `assets` folder. Modify them to your heart's content and then use [image2cpp tool](http://javl.github.io/image2cpp/) to convert them. Make sure you tick 'Invert image colors', as I made the colors the wrong way around.  
> I commented out the code related to the 'Array of all bitmaps for convenience' in the output code, as it was causing me inconvenience.
>
> The UI font's original files are not included. See [here](https://www.reddit.com/r/zelda/comments/5txuba/breath_of_the_wild_ui_font/) for source. I let some online tool convert it to .ttf and then used [truetype2gfx](https://rop.nl/truetype2gfx/) to convert to C code.

## Thanks and contributions (from the original author)

### Zelda BOTW UI Kit by Hunter Paramore

From the original watchface author:
> Although I added some stuff on my own, I heavily relied on this amazing Zelda BotW UI Kit done in Figma. I was really happy I didn't have to create all the graphics I used from scratch. So thanks to some internet person apparently named 'Hunter Paramore'. Here's a link to their [Figma profile](https://www.figma.com/@hparamore).

### Calamity Sans

From the original watchface author:
> For the UI font, I was able to use #'Calamity Sans' by reddit user [75thTrombone](https://www.reddit.com/user/75thTrombone/). I'd love to credit them in some way, but all I know of is this [reddit post](https://www.reddit.com/r/zelda/comments/5txuba/breath_of_the_wild_ui_font/).

## Thanks and contributions (added)
### mehtmehtsen

For providing a high quality watchface that this fork is based off of. I just wanted to get it working for my own personal use, and figured it made sense to share the fixes back to the community so more folks can use this. <3

/* Dodow Arduino Clone.  Sleep Meditation machine 
Feel Free to share or improve this code ;-)

8 Min Loop Structure
Min 1 = 11 breaths per minute - 0.18 breaths pm
Min 2 = 10 breaths per minute - 0.16 breaths pm
Min 3 = 9 breaths per minute - 0.16 breaths pm
Min 4 = 8 - 0.15 breaths pm
Min 5 = 7 - 0.13 breaths pm
Min 6 = 6 - 0.11 breaths pm
Min 7 = 6 breaths per minute - 0.1 breaths pm - once every 10 seconds
Min 8 = 6 breaths per minute - "

20 Min Code Structure
Min 1 = 11 times per minute(0.18). TimeRepeater set to 31 for 3 min
Min 2 = 11
Min 3 = 11
Min 4 = 10 (0.16) TimeRepeater set to 30 for 3 min
Min 5 = 10
Min 6 = 10
Min 7 = 9 (0.16) TimeRepeater set to 27 for 3 min
Min 8 = 9
Min 9 = 9
Min 10 = 8 (0.15) TimeRepeater set to 22 for 3 min
Min 11 = 8
Min 12 = 8
Min 13 = 7 (0.13) TimeRepeater set to 20 for 3 min
Min 14 = 7
Min 15 = 7
Min 16 = 6.11 (0.11) TimeRepeater set to 13 for 2 min
Min 17 = 6.11
Min 18 = 6 (0.10) TimeRepeater set to 18 for 3 min
Min 19 = 6
Min 20 = 6
*/

#include <avr/sleep.h>

int led1 = 9;          // LED is attached to pwm pin 9
int led2 = 10;         // LED is attached to pwm pin 10
int led3 = 11;         // LED is attached to pwm pin 11
int brightness = 0;    // Set the starting brightness

// the setup routine runs once powered on or when you press reset:
void setup() {
    // declare pin 9, 10, 11 to be an output:
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    // configure pin2 as an input switch
    pinMode(2, INPUT_PULLUP);
    // read the switch position value into a variable
    int sensorVal = digitalRead(2);

    //If the switch is set to High, run this portion of code
    if (selected8MinLoop(sensorVal)) {

        //Start of 8 minute loop

        // This code below lasts 5.5 seconds per flash for 1 min / 10.9 times per min (0.091 each breath)
        doCycle(11, new int[7] {5, 6, 7, 9, 13, 17, 23}, new int[7] {3, 4, 6, 9, 13, 17, 23});

        // This code below lasts for 6 seconds & 1 min / 10 times per min (0.10 each breath)
        doCycle(10, new int[7] {6, 7, 8, 10, 14, 18, 24}, new int[7] {4, 5, 7, 10, 14, 18, 24});

        // Start of 7 sec code / 8.57 times per min (0.11 each breath)
        doCycle(9, new int[7] {8, 9, 10, 12, 16, 20, 26}, new int[7] {6, 7, 9, 12, 16, 20, 26});

        // Start of 8 sec code / 1 min loop / 7.5 times per min (0.13 each breath)
        doCycle(8, new int[7] {10, 11, 12, 14, 18, 22, 28}, new int[7] {8, 9, 11, 14, 18, 22, 28});

        // Start of 9 second code 1 min loop / 6.66 times per min (0.15 each breath)
        doCycle(7, new int[7] {12, 13, 14, 16, 20, 24, 30}, new int[7] {10, 11, 13, 16, 20, 24, 30});

        //Start of 10 sec code / 1 min loop / 6 times per min (0.16 each breath)
        doCycle(6, new int[7] {14, 15, 16, 18, 22, 26, 32}, new int[7] {12, 13, 15, 18, 22, 26, 32});

        // Start of 11 sec code / 1 min loop / 5.45 times per min (0.18 each breath)
        doCycle(12, new int[7] {16, 17, 18, 20, 24, 28, 34}, new int[7] {14, 15, 17, 20, 24, 28, 34});

        set_sleep_mode(SLEEP_MODE_PWR_DOWN);
        sleep_enable();
        sleep_cpu();

        // End of 8 min loop

    } else {
        //Start of 20 minute loop
        //This code below lasts for 5.5 seconds & 1 min / 10.9 times per min (0.091 each breath)
        doCycle(31, new int[7] {5, 6, 7, 9, 13, 17, 23}, new int[7] {3, 4, 6, 9, 13, 17, 23});

        //  This code below lasts for 6 seconds & 3 min / 10 times per min (0.10 each breath)
        doCycle(30, new int[7] {6, 7, 8, 10, 14, 18, 24}, new int[7] {4, 5, 7, 10, 14, 18, 24});

        // Start of 7 sec code / 8.57 times per min (0.11 each breath)
        doCycle(27, new int[7] {8, 9, 10, 12, 16, 20, 26}, new int[7] {6, 7, 9, 12, 16, 20, 26});

        // Start of 8 sec code / 1 min loop / 7.5 times per min (0.13 each breath)
        doCycle(22, new int[7] {10, 11, 12, 14, 18, 22, 28}, new int[7] {8, 9, 11, 14, 18, 22, 28});

        // Start of 9 second code 1 min loop / 6.66 times per min (0.15 each breath)
        doCycle(20, new int[7] {12, 13, 14, 16, 20, 24, 30}, new int[7] {10, 11, 13, 16, 20, 24, 30});

        //Start of 10 sec code / 1 min loop / 6 times per min (0.16 each breath)
        doCycle(12, new int[7] {14, 15, 16, 18, 22, 26, 32}, new int[7] {12, 13, 15, 18, 22, 26, 32});

        // Start of 11 sec code / 1 min loop / 5.45 times per min (0.18 each breath)
        doCycle(18, new int[7] {16, 17, 18, 20, 24, 28, 34}, new int[7] {14, 15, 17, 20, 24, 28, 34});

        set_sleep_mode(SLEEP_MODE_PWR_DOWN);
        sleep_enable();
        sleep_cpu();

        // End of 20 min loop
    }
}

// Helper function to easily identify the conditional case with which we are dealing with
bool selected8MinLoop(int sensorVal) { return sensorVal == HIGH; }

// A cycle is the lighting and diming of the LED to create that "LED breathing" effect
void doCycle(int times, int lightCycleDelays[7], int dimCycleDelays[7]) {
    for (int cycle = 0; cycle < times; cycle++) {
        for (brightness = 0; brightness <= 255; brightness += 1) {
            setLEDsBrightness(brightness);

            delayBasedOnBrightness(brightness, lightCycleDelays);
        }
        for (brightness = 255; brightness >= 0; brightness -= 1) {
            setLEDsBrightness(brightness);

            delayBasedOnBrightness(brightness, dimCycleDelays);
        }
        delay(970);
    }
}

// Writes to the defined pins the passed brightness value
void setLEDsBrightness(int brightness) {
    analogWrite(led1, brightness);
    analogWrite(led2, brightness);
    analogWrite(led3, brightness);
}

// Depending on the brightness a certain delay will be applied
void delayBasedOnBrightness(int brightness, int delays[7]) {
    if (brightness > 150) {
        delay(delays[0]);
    } else if ((brightness > 125) && (brightness < 151)) {
        delay(delays[1]);
    } else if ((brightness > 100) && (brightness < 126)) {
        delay(delays[2]);
    } else if ((brightness > 75) && (brightness < 101)) {
        delay(delays[3]);
    } else if ((brightness > 50) && (brightness < 76)) {
        delay(delays[4]);
    } else if ((brightness > 25) && (brightness < 51)) {
        delay(delays[5]);
    } else if ((brightness > 1) && (brightness < 26)) {
        delay(delays[6]);
    }
}

void loop() {
    // this code will never be reached (the logic happens all in the setup function)
}

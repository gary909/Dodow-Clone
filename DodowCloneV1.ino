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
    if (sensorVal == HIGH) {

        //Start of 8 minute loop
        //This code below lasts 5.5 seconds per flash for 1 min / 10.9 times per min (0.091 each breath)
        for (int timeReapeter = 0; timeReapeter < 11; timeReapeter++) {
            for (brightness = 0; brightness <= 255; brightness += 1) {
               setLEDsBrightness(brightness);
                if (brightness > 150) {
                    delay(5);
                } else if ((brightness > 125) && (brightness < 151)) {
                    delay(6);
                } else if ((brightness > 100) && (brightness < 126)) {
                    delay(7);
                } else if ((brightness > 75) && (brightness < 101)) {
                    delay(9);
                } else if ((brightness > 50) && (brightness < 76)) {
                    delay(13);
                } else if ((brightness > 25) && (brightness < 51)) {
                    delay(17);
                } else if ((brightness > 1) && (brightness < 26)) {
                    delay(23);
                }
            }
            for (brightness = 255; brightness >= 0; brightness -= 1) {
               setLEDsBrightness(brightness);
                if (brightness > 150) {
                    delay(3);
                } else if ((brightness > 125) && (brightness < 151)) {
                    delay(4);
                } else if ((brightness > 100) && (brightness < 126)) {
                    delay(6);
                } else if ((brightness > 75) && (brightness < 101)) {
                    delay(9);
                } else if ((brightness > 50) && (brightness < 76)) {
                    delay(13);
                } else if ((brightness > 25) && (brightness < 51)) {
                    delay(17);
                } else if ((brightness > 1) && (brightness < 26)) {
                    delay(23);
                }
            }
            delay(970);
        }

        //  This code below lasts for 6 seconds & 1 min / 10 times per min (0.10 each breath)
        for (int timeReapeter = 0; timeReapeter < 10; timeReapeter++) {
            for (brightness = 0; brightness <= 255; brightness += 1) {
               setLEDsBrightness(brightness);
                if (brightness > 150) {
                    delay(6);
                } else if ((brightness > 125) && (brightness < 151)) {
                    delay(7);
                } else if ((brightness > 100) && (brightness < 126)) {
                    delay(8);
                } else if ((brightness > 75) && (brightness < 101)) {
                    delay(10);
                } else if ((brightness > 50) && (brightness < 76)) {
                    delay(14);
                } else if ((brightness > 25) && (brightness < 51)) {
                    delay(18);
                } else if ((brightness > 1) && (brightness < 26)) {
                    delay(24);
                }
            }
            for (brightness = 255; brightness >= 0; brightness -= 1) {
               setLEDsBrightness(brightness);
                if (brightness > 150) {
                    delay(4);
                } else if ((brightness > 125) && (brightness < 151)) {
                    delay(5);
                } else if ((brightness > 100) && (brightness < 126)) {
                    delay(7);
                } else if ((brightness > 75) && (brightness < 101)) {
                    delay(10);
                } else if ((brightness > 50) && (brightness < 76)) {
                    delay(14);
                } else if ((brightness > 25) && (brightness < 51)) {
                    delay(18);
                } else if ((brightness > 1) && (brightness < 26)) {
                    delay(24);
                }
            }
            delay(970);
        }

        // Start of 7 sec code / 8.57 times per min (0.11 each breath)
        for (int timeReapeter = 0; timeReapeter < 9; timeReapeter++) {
            for (brightness = 0; brightness <= 255; brightness += 1) {
               setLEDsBrightness(brightness);
                if (brightness > 150) {
                    delay(8);
                } else if ((brightness > 125) && (brightness < 151)) {
                    delay(9);
                } else if ((brightness > 100) && (brightness < 126)) {
                    delay(10);
                } else if ((brightness > 75) && (brightness < 101)) {
                    delay(12);
                } else if ((brightness > 50) && (brightness < 76)) {
                    delay(16);
                } else if ((brightness > 25) && (brightness < 51)) {
                    delay(20);
                } else if ((brightness > 1) && (brightness < 26)) {
                    delay(26);
                }
            }
            for (brightness = 255; brightness >= 0; brightness -= 1) {
               setLEDsBrightness(brightness);
                if (brightness > 150) {
                    delay(6);
                } else if ((brightness > 125) && (brightness < 151)) {
                    delay(7);
                } else if ((brightness > 100) && (brightness < 126)) {
                    delay(9);
                } else if ((brightness > 75) && (brightness < 101)) {
                    delay(12);
                } else if ((brightness > 50) && (brightness < 76)) {
                    delay(16);
                } else if ((brightness > 25) && (brightness < 51)) {
                    delay(20);
                } else if ((brightness > 1) && (brightness < 26)) {
                    delay(26);
                }
            }
            delay(970);
        }

        // Start of 8 sec code / 1 min loop / 7.5 times per min (0.13 each breath)
        for (int timeReapeter = 0; timeReapeter < 8; timeReapeter++) {
            for (brightness = 0; brightness <= 255; brightness += 1) {
               setLEDsBrightness(brightness);
                if (brightness > 150) {
                    delay(10);
                } else if ((brightness > 125) && (brightness < 151)) {
                    delay(11);
                } else if ((brightness > 100) && (brightness < 126)) {
                    delay(12);
                } else if ((brightness > 75) && (brightness < 101)) {
                    delay(14);
                } else if ((brightness > 50) && (brightness < 76)) {
                    delay(18);
                } else if ((brightness > 25) && (brightness < 51)) {
                    delay(22);
                } else if ((brightness > 1) && (brightness < 26)) {
                    delay(28);
                }
            }
            for (brightness = 255; brightness >= 0; brightness -= 1) {
               setLEDsBrightness(brightness);
                if (brightness > 150) {
                    delay(8);
                } else if ((brightness > 125) && (brightness < 151)) {
                    delay(9);
                } else if ((brightness > 100) && (brightness < 126)) {
                    delay(11);
                } else if ((brightness > 75) && (brightness < 101)) {
                    delay(14);
                } else if ((brightness > 50) && (brightness < 76)) {
                    delay(18);
                } else if ((brightness > 25) && (brightness < 51)) {
                    delay(22);
                } else if ((brightness > 1) && (brightness < 26)) {
                    delay(28);
                }
            }
            delay(970);
        }

        // Start of 9 second code 1 min loop / 6.66 times per min (0.15 each breath)
        for (int timeReapeter = 0; timeReapeter < 7; timeReapeter++) {
            for (brightness = 0; brightness <= 255; brightness += 1) {
               setLEDsBrightness(brightness);
                if (brightness > 150) {
                    delay(12);
                } else if ((brightness > 125) && (brightness < 151)) {
                    delay(13);
                } else if ((brightness > 100) && (brightness < 126)) {
                    delay(14);
                } else if ((brightness > 75) && (brightness < 101)) {
                    delay(16);
                } else if ((brightness > 50) && (brightness < 76)) {
                    delay(20);
                } else if ((brightness > 25) && (brightness < 51)) {
                    delay(24);
                } else if ((brightness > 1) && (brightness < 26)) {
                    delay(30);
                }
            }
            for (brightness = 255; brightness >= 0; brightness -= 1) {
               setLEDsBrightness(brightness);
                if (brightness > 150) {
                    delay(10);
                } else if ((brightness > 125) && (brightness < 151)) {
                    delay(11);
                } else if ((brightness > 100) && (brightness < 126)) {
                    delay(13);
                } else if ((brightness > 75) && (brightness < 101)) {
                    delay(16);
                } else if ((brightness > 50) && (brightness < 76)) {
                    delay(20);
                } else if ((brightness > 25) && (brightness < 51)) {
                    delay(24);
                } else if ((brightness > 1) && (brightness < 26)) {
                    delay(30);
                }
            }
            delay(970);
        }

        //Start of 10 sec code / 1 min loop / 6 times per min (0.16 each breath)
        for (int timeReapeter = 0; timeReapeter < 6; timeReapeter++) {
            for (brightness = 0; brightness <= 255; brightness += 1) {
               setLEDsBrightness(brightness);
                if (brightness > 150) {
                    delay(14);
                } else if ((brightness > 125) && (brightness < 151)) {
                    delay(15);
                } else if ((brightness > 100) && (brightness < 126)) {
                    delay(16);
                } else if ((brightness > 75) && (brightness < 101)) {
                    delay(18);
                } else if ((brightness > 50) && (brightness < 76)) {
                    delay(22);
                } else if ((brightness > 25) && (brightness < 51)) {
                    delay(26);
                } else if ((brightness > 1) && (brightness < 26)) {
                    delay(32);
                }
            }
            for (brightness = 255; brightness >= 0; brightness -= 1) {
               setLEDsBrightness(brightness);
                if (brightness > 150) {
                    delay(12);
                } else if ((brightness > 125) && (brightness < 151)) {
                    delay(13);
                } else if ((brightness > 100) && (brightness < 126)) {
                    delay(15);
                } else if ((brightness > 75) && (brightness < 101)) {
                    delay(18);
                } else if ((brightness > 50) && (brightness < 76)) {
                    delay(22);
                } else if ((brightness > 25) && (brightness < 51)) {
                    delay(26);
                } else if ((brightness > 1) && (brightness < 26)) {
                    delay(32);
                }
            }
            delay(970);
        }

        // Start of 11 sec code / 1 min loop / 5.45 times per min (0.18 each breath)
        for (int timeReapeter = 0; timeReapeter < 12; timeReapeter++) {
            for (brightness = 0; brightness <= 255; brightness += 1) {
               setLEDsBrightness(brightness);
                if (brightness > 150) {
                    delay(16);
                } else if ((brightness > 125) && (brightness < 151)) {
                    delay(17);
                } else if ((brightness > 100) && (brightness < 126)) {
                    delay(18);
                } else if ((brightness > 75) && (brightness < 101)) {
                    delay(20);
                } else if ((brightness > 50) && (brightness < 76)) {
                    delay(24);
                } else if ((brightness > 25) && (brightness < 51)) {
                    delay(28);
                } else if ((brightness > 1) && (brightness < 26)) {
                    delay(34);
                }
            }
            for (brightness = 255; brightness >= 0; brightness -= 1) {
               setLEDsBrightness(brightness);
                if (brightness > 150) {
                    delay(14);
                } else if ((brightness > 125) && (brightness < 151)) {
                    delay(15);
                } else if ((brightness > 100) && (brightness < 126)) {
                    delay(17);
                } else if ((brightness > 75) && (brightness < 101)) {
                    delay(20);
                } else if ((brightness > 50) && (brightness < 76)) {
                    delay(24);
                } else if ((brightness > 25) && (brightness < 51)) {
                    delay(28);
                } else if ((brightness > 1) && (brightness < 26)) {
                    delay(34);
                }
            }
            delay(970);
            set_sleep_mode(SLEEP_MODE_PWR_DOWN);
            sleep_enable();
            sleep_cpu();
        }
        // End of 8 min loop

    } else {
        //Start of 20 minute loop
        //This code below lasts for 5.5 seconds & 1 min / 10.9 times per min (0.091 each breath)
        for (int timeReapeter = 0; timeReapeter < 31; timeReapeter++) {
            for (brightness = 0; brightness <= 255; brightness += 1) {
               setLEDsBrightness(brightness);
                if (brightness > 150) {
                    delay(5);
                } else if ((brightness > 125) && (brightness < 151)) {
                    delay(6);
                } else if ((brightness > 100) && (brightness < 126)) {
                    delay(7);
                } else if ((brightness > 75) && (brightness < 101)) {
                    delay(9);
                } else if ((brightness > 50) && (brightness < 76)) {
                    delay(13);
                } else if ((brightness > 25) && (brightness < 51)) {
                    delay(17);
                } else if ((brightness > 1) && (brightness < 26)) {
                    delay(23);
                }
            }
            for (brightness = 255; brightness >= 0; brightness -= 1) {
               setLEDsBrightness(brightness);
                if (brightness > 150) {
                    delay(3);
                } else if ((brightness > 125) && (brightness < 151)) {
                    delay(4);
                } else if ((brightness > 100) && (brightness < 126)) {
                    delay(6);
                } else if ((brightness > 75) && (brightness < 101)) {
                    delay(9);
                } else if ((brightness > 50) && (brightness < 76)) {
                    delay(13);
                } else if ((brightness > 25) && (brightness < 51)) {
                    delay(17);
                } else if ((brightness > 1) && (brightness < 26)) {
                    delay(23);
                }
            }
            delay(970);
        }

        //  This code below lasts for 6 seconds & 3 min / 10 times per min (0.10 each breath)
        for (int timeReapeter = 0; timeReapeter < 30; timeReapeter++) {
            for (brightness = 0; brightness <= 255; brightness += 1) {
               setLEDsBrightness(brightness);
                if (brightness > 150) {
                    delay(6);
                } else if ((brightness > 125) && (brightness < 151)) {
                    delay(7);
                } else if ((brightness > 100) && (brightness < 126)) {
                    delay(8);
                } else if ((brightness > 75) && (brightness < 101)) {
                    delay(10);
                } else if ((brightness > 50) && (brightness < 76)) {
                    delay(14);
                } else if ((brightness > 25) && (brightness < 51)) {
                    delay(18);
                } else if ((brightness > 1) && (brightness < 26)) {
                    delay(24);
                }
            }
            for (brightness = 255; brightness >= 0; brightness -= 1) {
               setLEDsBrightness(brightness);
                if (brightness > 150) {
                    delay(4);
                } else if ((brightness > 125) && (brightness < 151)) {
                    delay(5);
                } else if ((brightness > 100) && (brightness < 126)) {
                    delay(7);
                } else if ((brightness > 75) && (brightness < 101)) {
                    delay(10);
                } else if ((brightness > 50) && (brightness < 76)) {
                    delay(14);
                } else if ((brightness > 25) && (brightness < 51)) {
                    delay(18);
                } else if ((brightness > 1) && (brightness < 26)) {
                    delay(24);
                }
            }
            delay(970);
        }

        // Start of 7 sec code / 8.57 times per min (0.11 each breath)
        for (int timeReapeter = 0; timeReapeter < 27; timeReapeter++) {
            for (brightness = 0; brightness <= 255; brightness += 1) {
               setLEDsBrightness(brightness);
                if (brightness > 150) {
                    delay(8);
                } else if ((brightness > 125) && (brightness < 151)) {
                    delay(9);
                } else if ((brightness > 100) && (brightness < 126)) {
                    delay(10);
                } else if ((brightness > 75) && (brightness < 101)) {
                    delay(12);
                } else if ((brightness > 50) && (brightness < 76)) {
                    delay(16);
                } else if ((brightness > 25) && (brightness < 51)) {
                    delay(20);
                } else if ((brightness > 1) && (brightness < 26)) {
                    delay(26);
                }
            }
            for (brightness = 255; brightness >= 0; brightness -= 1) {
               setLEDsBrightness(brightness);
                if (brightness > 150) {
                    delay(6);
                } else if ((brightness > 125) && (brightness < 151)) {
                    delay(7);
                } else if ((brightness > 100) && (brightness < 126)) {
                    delay(9);
                } else if ((brightness > 75) && (brightness < 101)) {
                    delay(12);
                } else if ((brightness > 50) && (brightness < 76)) {
                    delay(16);
                } else if ((brightness > 25) && (brightness < 51)) {
                    delay(20);
                } else if ((brightness > 1) && (brightness < 26)) {
                    delay(26);
                }
            }
            delay(970);
        }

        // Start of 8 sec code / 1 min loop / 7.5 times per min (0.13 each breath)
        for (int timeReapeter = 0; timeReapeter < 22; timeReapeter++) {
            for (brightness = 0; brightness <= 255; brightness += 1) {
               setLEDsBrightness(brightness);
                if (brightness > 150) {
                    delay(10);
                } else if ((brightness > 125) && (brightness < 151)) {
                    delay(11);
                } else if ((brightness > 100) && (brightness < 126)) {
                    delay(12);
                } else if ((brightness > 75) && (brightness < 101)) {
                    delay(14);
                } else if ((brightness > 50) && (brightness < 76)) {
                    delay(18);
                } else if ((brightness > 25) && (brightness < 51)) {
                    delay(22);
                } else if ((brightness > 1) && (brightness < 26)) {
                    delay(28);
                }
            }
            for (brightness = 255; brightness >= 0; brightness -= 1) {
               setLEDsBrightness(brightness);
                if (brightness > 150) {
                    delay(8);
                } else if ((brightness > 125) && (brightness < 151)) {
                    delay(9);
                } else if ((brightness > 100) && (brightness < 126)) {
                    delay(11);
                } else if ((brightness > 75) && (brightness < 101)) {
                    delay(14);
                } else if ((brightness > 50) && (brightness < 76)) {
                    delay(18);
                } else if ((brightness > 25) && (brightness < 51)) {
                    delay(22);
                } else if ((brightness > 1) && (brightness < 26)) {
                    delay(28);
                }
            }
            delay(970);
        }

        // Start of 9 second code 1 min loop / 6.66 times per min (0.15 each breath)
        for (int timeReapeter = 0; timeReapeter < 20; timeReapeter++) {
            for (brightness = 0; brightness <= 255; brightness += 1) {
               setLEDsBrightness(brightness);
                if (brightness > 150) {
                    delay(12);
                } else if ((brightness > 125) && (brightness < 151)) {
                    delay(13);
                } else if ((brightness > 100) && (brightness < 126)) {
                    delay(14);
                } else if ((brightness > 75) && (brightness < 101)) {
                    delay(16);
                } else if ((brightness > 50) && (brightness < 76)) {
                    delay(20);
                } else if ((brightness > 25) && (brightness < 51)) {
                    delay(24);
                } else if ((brightness > 1) && (brightness < 26)) {
                    delay(30);
                }
            }
            for (brightness = 255; brightness >= 0; brightness -= 1) {
               setLEDsBrightness(brightness);
                if (brightness > 150) {
                    delay(10);
                } else if ((brightness > 125) && (brightness < 151)) {
                    delay(11);
                } else if ((brightness > 100) && (brightness < 126)) {
                    delay(13);
                } else if ((brightness > 75) && (brightness < 101)) {
                    delay(16);
                } else if ((brightness > 50) && (brightness < 76)) {
                    delay(20);
                } else if ((brightness > 25) && (brightness < 51)) {
                    delay(24);
                } else if ((brightness > 1) && (brightness < 26)) {
                    delay(30);
                }
            }
            delay(970);
        }

        //Start of 10 sec code / 1 min loop / 6 times per min (0.16 each breath)
        for (int timeReapeter = 0; timeReapeter < 12; timeReapeter++) {
            for (brightness = 0; brightness <= 255; brightness += 1) {
               setLEDsBrightness(brightness);
                if (brightness > 150) {
                    delay(14);
                } else if ((brightness > 125) && (brightness < 151)) {
                    delay(15);
                } else if ((brightness > 100) && (brightness < 126)) {
                    delay(16);
                } else if ((brightness > 75) && (brightness < 101)) {
                    delay(18);
                } else if ((brightness > 50) && (brightness < 76)) {
                    delay(22);
                } else if ((brightness > 25) && (brightness < 51)) {
                    delay(26);
                } else if ((brightness > 1) && (brightness < 26)) {
                    delay(32);
                }
            }
            for (brightness = 255; brightness >= 0; brightness -= 1) {
               setLEDsBrightness(brightness);
                if (brightness > 150) {
                    delay(12);
                } else if ((brightness > 125) && (brightness < 151)) {
                    delay(13);
                } else if ((brightness > 100) && (brightness < 126)) {
                    delay(15);
                } else if ((brightness > 75) && (brightness < 101)) {
                    delay(18);
                } else if ((brightness > 50) && (brightness < 76)) {
                    delay(22);
                } else if ((brightness > 25) && (brightness < 51)) {
                    delay(26);
                } else if ((brightness > 1) && (brightness < 26)) {
                    delay(32);
                }
            }
            delay(970);
        }

        // Start of 11 sec code / 1 min loop / 5.45 times per min (0.18 each breath)
        for (int timeReapeter = 0; timeReapeter < 18; timeReapeter++) {
            for (brightness = 0; brightness <= 255; brightness += 1) {
               setLEDsBrightness(brightness);
                if (brightness > 150) {
                    delay(16);
                } else if ((brightness > 125) && (brightness < 151)) {
                    delay(17);
                } else if ((brightness > 100) && (brightness < 126)) {
                    delay(18);
                } else if ((brightness > 75) && (brightness < 101)) {
                    delay(20);
                } else if ((brightness > 50) && (brightness < 76)) {
                    delay(24);
                } else if ((brightness > 25) && (brightness < 51)) {
                    delay(28);
                } else if ((brightness > 1) && (brightness < 26)) {
                    delay(34);
                }
            }
            for (brightness = 255; brightness >= 0; brightness -= 1) {
               setLEDsBrightness(brightness);
                if (brightness > 150) {
                    delay(14);
                } else if ((brightness > 125) && (brightness < 151)) {
                    delay(15);
                } else if ((brightness > 100) && (brightness < 126)) {
                    delay(17);
                } else if ((brightness > 75) && (brightness < 101)) {
                    delay(20);
                } else if ((brightness > 50) && (brightness < 76)) {
                    delay(24);
                } else if ((brightness > 25) && (brightness < 51)) {
                    delay(28);
                } else if ((brightness > 1) && (brightness < 26)) {
                    delay(34);
                }
            }
            delay(970);
            set_sleep_mode(SLEEP_MODE_PWR_DOWN);
            sleep_enable();
            sleep_cpu();
        }
        // End of 20 min loop
    }
}

// Writes to the defined pins the passed brightness value
void setLEDsBrightness(int brightness) {
    analogWrite(led1, brightness);
    analogWrite(led2, brightness);
    analogWrite(led3, brightness);
}

void loop() {
    // this code will never be reached (the logic happens all in the setup function)
}

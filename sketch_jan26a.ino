// Define pin numbers
const int buttonPin = 8;    // Button connected to pin 8
const int ledPin = 13;      // LED connected to pin 13 (built-in LED)

// Variables to store button state
int buttonState = 0;
int lastButtonState = 0;
bool ledState = false;  // Track the state of the LED (ON/OFF)

void setup() {
  // Set button pin as input
  pinMode(buttonPin, INPUT);
  // Set LED pin as output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Read the current state of the button
  buttonState = digitalRead(buttonPin);
  
  // Check if the button was pressed (i.e., a state change from LOW to HIGH)
  if (buttonState == HIGH && lastButtonState == LOW) {
    // Toggle the LED state
    ledState = !ledState;
    // Update LED based on the new state
    digitalWrite(ledPin, ledState ? HIGH : LOW);
    
    // Small delay to debounce the button press
    delay(200);  // Adjust the delay if needed
  }
  
  // Save the current button state for the next loop iteration
  lastButtonState = buttonState;
}

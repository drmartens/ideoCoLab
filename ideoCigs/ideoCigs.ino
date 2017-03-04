int Photo = 0; // will be used for analog 0.
int PhotoVal = 0; // value of output
int PhotoMax;
int PhotoMin;
const int ledPinRed = 9;
const int ledPinBlue = 8;
const int ledPinGreen = 7;
unsigned char Num;

void setup() {
Serial.begin(9600); //start serial Monitor
pinMode(ledPinRed, OUTPUT);
pinMode(ledPinBlue, OUTPUT);
pinMode(ledPinGreen, OUTPUT);
Serial.println("Wait 5 seconds for calibration please.");
 
 // calibrate during the first five seconds 
 while (millis() < 5000) {
   PhotoVal = analogRead(Photo);

   // record the maximum sensor value
   if (PhotoVal > PhotoMax) {
     PhotoMax = PhotoVal;
   }

   // record the minimum sensor value
   if (PhotoVal < PhotoMin) {
     PhotoMin = PhotoVal;
   }
 }
Serial.println("Calibration ended, beginning program");
}

void loop() {
  digitalWrite(ledPinGreen, LOW);
  digitalWrite(ledPinBlue, LOW);
  digitalWrite(ledPinRed, LOW);
PhotoVal = analogRead(Photo);
PhotoVal = map(PhotoVal, PhotoMin, PhotoMax, 0, 1000);

// One Light Lit (Only a little light)
if (PhotoVal <= 450) {
  digitalWrite(ledPinGreen, HIGH);
  digitalWrite(ledPinBlue, HIGH);
   digitalWrite(ledPinRed, HIGH);
}

else if (PhotoVal >= 450) {
  digitalWrite(ledPinGreen, LOW);
  digitalWrite(ledPinBlue, LOW);
   digitalWrite(ledPinRed, LOW);
}


Serial.println(PhotoVal); //prints photoresistor value
}


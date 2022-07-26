// C++ code
//
#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04
#define LED 8

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
int prev_distance = 0; //

void setup() {
	pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
	pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
	pinMode(LED,OUTPUT); // Sets the LED as an OUTPUT
	Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
	Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
	Serial.println("with Arduino UNO R3");
}
void loop() {
	checkDistance();
	if (distance <= 20 && distance != prev_distance){
		Serial.println("Distance less than 20cm turning LED on");
		digitalWrite(LED,HIGH);
	}else if(distance > 20 && distance != prev_distance){
		Serial.println("Distance more than 20cm turning LED off");
		digitalWrite(LED,LOW);
	}else{
		// Nothing
	}
	prev_distance = distance;
}

void checkDistance()
{
	// Clears the trigPin condition
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);
	// Sets the trigPin HIGH (ACTIVE) for 10 microseconds
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);
	// Reads the echoPin, returns the sound wave travel time in microseconds
	duration = pulseIn(echoPin, HIGH);
	// Calculating the distance
	distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
	// Displays the distance on the Serial Monitor
	Serial.print("Distance: ");
	Serial.print(distance);
	Serial.println("");
}
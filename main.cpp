// Define pins connected to LEDs
#define led_1 8
#define led_2 9
#define led_3 10
#define led_4 11
#define led_5 12
#define led_6 13

// Define Ultrasonic pins
#define ultrasonic_echo 2
#define ultrasonic_trig 3

void setup() {
  // Set appropriate PIN modes
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  pinMode(led_4, OUTPUT);
  pinMode(led_5, OUTPUT);
  pinMode(led_6, OUTPUT);

  pinMode(ultrasonic_echo, INPUT);
  pinMode(ultrasonic_trig, OUTPUT);

  // Begin Serial Monitor 9600
  Serial.begin(9600);
}

void loop() {
  // Trigger Ultrasonic sensor for 10ms
  digitalWrite(ultrasonic_trig, LOW);
  delay(2);
  digitalWrite(ultrasonic_trig, HIGH);
  delay(10);
  digitalWrite(ultrasonic_trig, LOW);

  // Output Ultrasonic's distance output
  long duration = pulseIn(ultrasonic_echo, HIGH);
  long inch =  (duration/2) / 29.1;

  // Determine
  digitalWrite(led_1, (inch >= 35) ? HIGH : LOW);
  digitalWrite(led_2, (inch >= 50) ? HIGH : LOW);
  digitalWrite(led_3, (inch >= 150) ? HIGH : LOW);
  digitalWrite(led_4, (inch >= 200) ? HIGH : LOW);
  digitalWrite(led_5, (inch >= 250) ? HIGH : LOW);
  digitalWrite(led_6, (inch >= 300) ? HIGH : LOW);
  
  // Output computed inches
  Serial.println(inch);
}
#define led_pin 11
#define led_pin2 13
#define duration_1 500
void setup() {
  // put your setup code here, to run once:
pinMode(led_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(led_pin,HIGH); //turn the LED on(High is the voltage level
delay(duration_1); //wait for a second
digitalWrite(led_pin,LOW); //turn the LED off by making the voltage low
delay(duration_1);//wait for a second

digitalWrite(led_pin2,HIGH); //turn the LED on(High is the voltage level
delay(duration_1); //wait for a second
digitalWrite(led_pin2,LOW); //turn the LED off by making the voltage low
delay(duration_1);//wait for a second
}
#JG

#define Buton 8

#define LED0 2
#define LED1 3
#define LED2 4
#define LED3 5
#define LED4 6
#define LEDS 5

#define LEDS_DELAY_MS 400
#define LEDS_STARTUP_DELAY 500

#define SEC_UNIT_MS 1000

#define POMODORO_25 true
#define POMODORO_5 false


int leds[] = { LED0,LED1,LED2,LED3,LED4 };
bool state=false;
void MinDelay(int minutes);
void pomodoro_ready(int _leds[], int _delay);
void first_open(int leds[]);
void start_leds_open(int Leds[], int _delay);
void start_leds_close(int Leds[], int _delay);
void all_leds_open(int leds[]);

void setup() {
	pinMode(Buton, INPUT);
	for (int i = 0; i<LEDS; i++) {
		pinMode(leds[i], OUTPUT);
	}
}

void loop()
{

	if (digitalRead(Buton) == 1) {
		first_open(leds);
		delay(LEDS_DELAY_MS);
		pomodoro_ready(leds, LEDS_STARTUP_DELAY);
		delay(LEDS_DELAY_MS);

		while (digitalRead(Buton) != 0);
		digitalWrite(LED4, LOW);
		if (state == POMODORO_25)
		{
			for (size_t i = 0; i < 5; i++)
			{
				MinDelay(5);
				digitalWrite(leds[4 - i], LOW);
			}
			while (digitalRead(Buton) == 0);
			state = POMODORO_5;
			//pomodoro25
		}
		else if (state == POMODORO_5)
		{
			for (size_t i = 0; i < 5; i++)
			{
				MinDelay(1);
				digitalWrite(leds[4 - i], LOW);
			}
			state = POMODORO_25;
			//pomodoro5
		}

}
	void first_open(int leds[]) {
	
	}



void start_leds_open(int leds[], int _delay) {
	for (int i = 0; i<LEDS; i++) {
		digitalWrite(leds[i], HIGH);
		delay(_delay);
	}
}
void start_leds_close(int _leds[], int _delay) {
	for (int i = 0; i < LEDS; i++) {
		digitalWrite(leds[i], LOW);
		delay(_delay);
	}
}

void pomodoro_ready(int _leds[], int _delay) {
	start_leds_open(_leds, _delay);
	delay(LEDS_DELAY_MS);
	start_leds_close(_leds, _delay);
}
void MinDelay(int minutes) {
	for (int sec = 0; sec<minutes; sec++) {
		for (int ms = 0; ms<60; ms++) {
			delay(SEC_UNIT_MS);
		}
	}
}
void all_leds_open(int leds[]) {
	for (int i=0; i < LEDS; i++) {
		digitalWrite(leds[i], HIGH);
	}
	for (int i=0; i < LEDS; i++) {
		digitalWrite(leds[i], LOW);
		MinDelay(0);
	}
}

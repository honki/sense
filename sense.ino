/********************************
Smoker & Air Control Program

Author:
  Honki, Joe

Version:
  v0.1: 2019 May 28th

********************************/
/*Const Define*/
#define smokebutton_1 7
#define smokebutton_2 8
#define smokebutton_3 9
#define smokebutton_4 10

#define airbutton_1 11
#define airbutton_2 12
#define airbutton_3 13
#define airbutton_4 14

#define smokemachine_pin 5
#define aircompresor_pin 6

#define button1Pin 1
#define button2Pin 2
#define button3Pin 3
#define button4Pin 4

#define BUTTON_TRIGGER HIGH
#define BUTTON_RELEASE LOW

#define SMOKER_ON LOW
#define SMOKER_OFF HIGH

#define SMOKE_VALVE_ON HIGH
#define SMOKE_VALVE_OFF LOW

#define AIR_ON LOW
#define AIR_OFF HIGH

#define AIR_VALVE_ON HIGH
#define AIR_VALVE_OFF LOW

/*mili-sec*/
#define smoke_time 5000
#define air_time 8000
#define button_wait_time 800

/*Global*/

/*Input Pin State*/
int button1State = 0;         // variable for reading the pushbutton status
int button2State = 0;         // variable for reading the pushbutton status
int button3State = 0;         // variable for reading the pushbutton status
int button4State = 0;         // variable for reading the pushbutton status

/*Output Pin State*/

int smokebutton1 = 0; 
int smokebutton2 = 0; 
int smokebutton3 = 0; 
int smokebutton4 = 0; 

int airbutton1 = 0;
int airbutton2 = 0;
int airbutton3 = 0;
int airbutton4 = 0;


int button_detection (void) {

  /*wait a while for the press of multi-button*/
  delay(button_wait_time);

  if(digitalRead(button1Pin) == BUTTON_TRIGGER) {
    button1State = true;
  }else{
    button1State = false;
  }

  if(digitalRead(button2Pin) == BUTTON_TRIGGER) {
    button2State = true;
  }else{
    button2State = false;
  }

  if(digitalRead(button3Pin) == BUTTON_TRIGGER) {
    button3State = true;
  }else{
    button3State = false;
  }

  if(digitalRead(button4Pin) == BUTTON_TRIGGER) {
    button4State = true;
  }else{
    button4State = false;
  }
}

void smoke_on (int smokebutton) {
  digitalWrite(smokebutton, SMOKE_VALVE_ON);
  digitalWrite(smokemachine_pin, SMOKER_ON); 
}

void smoke_off (int smokebutton) {
  digitalWrite(smokebutton, SMOKE_VALVE_OFF);
  digitalWrite(smokemachine_pin, SMOKER_OFF);
}

void air_on (int airbutton) {
  digitalWrite(airbutton, AIR_VALVE_ON);
  digitalWrite(aircompresor_pin, AIR_ON);
}

void air_off (int airbutton) {
  digitalWrite(airbutton, AIR_VALVE_OFF);
  digitalWrite(aircompresor_pin, AIR_OFF);  
}


void reaction (void) {

  /*smoke on*/
  if (button1State == true) {
    smoke_on(smokebutton_1);
  }
  if (button2State == true) {
    smoke_on(smokebutton_2);
  }
  if (button3State == true) {
    smoke_on(smokebutton_3);
  }
  if (button4State == true) {
    smoke_on(smokebutton_4);
  }
  /*delay a while to let smoke go into to the jar*/
  if (button1State || button2State || button3State || button4State) {
    delay(smoke_time);
  }

  /*smoke off*/
  smoke_off(smokebutton_1);
  smoke_off(smokebutton_2);
  smoke_off(smokebutton_3);
  smoke_off(smokebutton_4);

  /*air on*/
  if (button1State == true) {
    air_on(airbutton_1);
  }
  if (button2State == true) {
    air_on(airbutton_2);
  }
  if (button3State == true) {
    air_on(airbutton_3);
  }
  if (button4State == true) {
    air_on(airbutton_4);
  }

  /*delay a while to let air go through the jar*/
  if (button1State || button2State || button3State || button4State) {
    delay(air_time);
  }

  /*air off*/
  air_off(airbutton_1);
  air_off(airbutton_2);
  air_off(airbutton_3);
  air_off(airbutton_4);
}

void setup() {
 // initialize the relay pin as an output:
  pinMode(smokebutton_1, OUTPUT);
  pinMode(smokebutton_2, OUTPUT);
  pinMode(smokebutton_3, OUTPUT);
  pinMode(smokebutton_4, OUTPUT);
  pinMode(airbutton_1, OUTPUT);
  pinMode(airbutton_2, OUTPUT);
  pinMode(airbutton_3, OUTPUT);
  pinMode(airbutton_4, OUTPUT);
  pinMode(smokemachine_pin, OUTPUT);
  pinMode(aircompresor_pin, OUTPUT);
  digitalWrite(smokemachine_pin, SMOKER_OFF);
  digitalWrite(aircompresor_pin, AIR_OFF);
  
  // initialize the pushbutton pin as an input:
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(button3Pin, INPUT);
  pinMode(button4Pin, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  button_detection();
  reaction();
}

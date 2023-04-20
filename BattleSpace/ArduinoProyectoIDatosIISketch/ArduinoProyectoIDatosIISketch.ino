const int buttonUPpin = 11;
const int buttonDOWNpin = 12;
const int BuzzerPin = 10;
const int potPin = A0;
const int displayPins[]={2,3,4,5,6,7,8,9};//arduino pin array
int wave = 1;
int potVal = 0;
bool firstrun = false;
void setup() {
  pinMode(buttonUPpin, INPUT);
  pinMode(buttonDOWNpin, INPUT);
  pinMode(BuzzerPin,OUTPUT);
  for (byte a=0; a<8; a++){
    pinMode(displayPins[a],OUTPUT);
    }
  Serial.begin(9600 );
}
void displayNum(int num) {
  const int digits[10][8] = { // the pins to light up for each digit
   
  {0, 0, 0, 0, 0, 0, 0, 1},//0
  {1, 1, 0, 0, 0, 1, 1, 1},//1
  {0, 0, 1, 0, 0, 0, 1, 0},//2
  {1, 0, 0, 0, 0, 0, 1, 0},//3
  {1, 1, 0, 0, 0, 1, 0, 0},//4
  {1, 0, 0, 0, 1, 0, 0, 0},//5
  {0, 0, 0, 0, 1, 0, 0, 0},//6
  {1, 1, 0, 0, 0, 0, 0, 1},//7
  {0, 0, 0, 0, 0, 0, 0, 0},//8
  {1, 1, 0, 0, 0, 0, 0, 0},//9
  };
  for (int i = 0; i < 10; i++) {
    digitalWrite(displayPins[i], digits[num][i]); // set the pin values according to the digit
  }
}
void loop() {

  
  int command = Serial.parseInt();
  if (firstrun == false){
    displayNum(wave);
    firstrun = true;
    }
  if (command == 420){
    if(wave==5){
      wave = 1;
      }
    else{wave ++;}
    displayNum(wave);
    }
  
  
  if (command == 69){
    digitalWrite(BuzzerPin, HIGH);
    delay(100);
    digitalWrite(BuzzerPin, LOW);
    }
  
  

  digitalWrite(BuzzerPin,LOW);
  potVal= analogRead(potPin);
  Serial.print(digitalRead(buttonUPpin));
  Serial.print(digitalRead(buttonDOWNpin));
  Serial.print(potVal);
  Serial.print("\n");
 
} 

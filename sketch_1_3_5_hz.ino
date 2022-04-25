int count = 0; 
const int blue = 2;   //pin for blue LED
const int white = 8;  //pin for white LED
const int red = 13;   //pin for red LED
boolean blueFlag;       //determines onOffB outcome
boolean whiteFlag;      //determines onOffW outcome
boolean redFlag;        //determines onOffR outcome

void setup()
{
  Serial.begin(9600);     //set data rate for serial transmission
  pinMode(blue, OUTPUT);  //2 (blue) pin as output
  pinMode(white, OUTPUT); //8 (white) pin as output
  pinMode(red, OUTPUT);   //13 (red) pin as output
  blueFlag = false;;      //initialized to false
  whiteFlag = false;      //initialized to false
  redFlag = false;        //initialized to false
}

void loop()
{
  if(count%3 == 0 ){  //if 100 milliseconds have passed since last time this conditon used
    onOffB();       //toggle blue LED
  }
  if(count%5 == 0 ){  //if 166 milliseconds have passed since last time this conditon used
    onOffW();       //toggle white LED    
  }
  if(count%15 == 0 ){ //if 500 milliseconds have passed since last time this conditon used
    onOffR();       //toggle red LED
  }
  delay(33);        //delay 33 milliseconds
  count++;            //increment count by one
}

/*
 * onOffB function
 * if blue LED is on, it will turn off with function call
 * if blue LED is off, it will turn on with function call
 * prints current milliseconds passed when called
 */
void onOffB()
{
  Serial.print("blue delay: ");
  Serial.println(millis());

  if(blueFlag){
    digitalWrite(blue, LOW);
    blueFlag = false;
  }
  else{
    digitalWrite(blue, HIGH); 
    blueFlag = true;
  }
}
/*
 * onOffW function
 * if white LED is on, it will turn off with function call
 * if white LED is off, it will turn on with function call
 * prints current milliseconds passed when called
 */
void onOffW()
{
  Serial.print("white delay: ");
  Serial.println(millis());

  if(whiteFlag){
    digitalWrite(white, LOW);
    whiteFlag = false;
  }
  else{
    digitalWrite(white, HIGH); 
    whiteFlag = true;
  }
}
/*
 * onOffR function
 * if red LED is on, it will turn off with function call
 * if red LED is off, it will turn on with function call
 * prints current milliseconds passed when called
 */
void onOffR()
{
  Serial.print("red delay: ");
  Serial.println(millis());
  
  if(redFlag){
    digitalWrite(red, LOW);
    redFlag = false;
  }
  else{
    digitalWrite(red, HIGH); 
    redFlag = true;
  }
}

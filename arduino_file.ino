/**int right_pin = 6; //left motor
int left_pin = 7; // left motor rev
int forward_pin = 10; //right motor rev
int reverse_pin = 9; //right motor

//rev, right
//for, lef
This is a file for two motor setup you may have to change this a bit if you have 4 motor setup
**/

// duration for output
int time = 50;
// initial command
int command = 0;

void setup() {
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT); // right motor
  pinMode(6,OUTPUT); //left motor
  pinMode(5,OUTPUT); //left motor
  Serial.begin(115200);
}

void loop() {
  //receive command
  if (Serial.available() > 0){
    command = Serial.read();
  }
  else{
    reset();
  }
   send_command(command,time);
}

void right(int time){
  analogWrite(9,0);
  analogWrite(10,0);
  analogWrite(5,0);
  analogWrite(6,200);
  delay(time);
}

void left(int time){
  analogWrite(9,0);
  analogWrite(10,200);
  analogWrite(5,0);
  analogWrite(6,0);
  delay(time);
}   

void forward(int time){
  analogWrite(9,0);
  analogWrite(10,200);
  analogWrite(5,0);
  analogWrite(6,200);
  delay(time);
}

void reverse(int time){
  analogWrite(9,200);
  analogWrite(10,0);
  analogWrite(5,200);
  analogWrite(6,0);
  delay(time);
}

void forward_right(int time){
  analogWrite(9,0);
  analogWrite(10,100);
  analogWrite(5,0);
  analogWrite(6,200);
  delay(time);
}

void reverse_right(int time){
  analogWrite(9,200);
  analogWrite(10,0);
  analogWrite(5,200);
  analogWrite(6,0);
  delay(time);
}

void forward_left(int time){
  analogWrite(9,0);
  analogWrite(10,200);
  analogWrite(5,0);
  analogWrite(6,100);
  delay(time);
}

void reverse_left(int time){
  analogWrite(9,200);
  analogWrite(10,0);
  analogWrite(5,200);
  analogWrite(6,0);
  delay(time);
}
void reset(){
  analogWrite(9,0);
  analogWrite(10,0);
  analogWrite(5,0);
  analogWrite(6,0);
}

void send_command(int command, int time){
  switch (command){

     //reset command
     case 0: reset(); break;

     // single command
     case 1: forward(time); break;
     case 2: reverse(time); break;
     case 3: right(time); break;
     case 4: left(time); break;

     //combination command
     case 6: forward_right(time); break;
     case 7: forward_left(time); break;
     case 8: reverse_right(time); break;
     case 9: reverse_left(time); break;

     default: Serial.print("Invalid Command\n");
    }
}

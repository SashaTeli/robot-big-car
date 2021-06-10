//Выключятель сзади
//0 вперед, 1 назад
#define MOTOR_LEFT_FRONT_DIR 2
#define MOTOR_LEFT_FRONT_EN 3
#define MOTOR_LEFT_REAR_DIR 8
#define MOTOR_LEFT_REAR_EN 9
#define MOTOR_RIGHT_FRONT_DIR 12
#define MOTOR_RIGHT_FRONT_EN 13
#define MOTOR_RIGHT_REAR_DIR 10
#define MOTOR_RIGHT_REAR_EN 11

#define DIR_FORWARD 0
#define DIR_BACKWARD 1

char BluetoothData; // Приходящие данные с 

int pad_y; //Значение скорости
int pad_x; //Напровление и скорость поворота

void setup() {
 Serial.begin(9600); 
  
  pinMode (MOTOR_LEFT_FRONT_DIR, OUTPUT);
  pinMode (MOTOR_LEFT_FRONT_EN, OUTPUT);
  pinMode (MOTOR_LEFT_REAR_DIR, OUTPUT);
  pinMode (MOTOR_LEFT_REAR_EN, OUTPUT);
  pinMode (MOTOR_RIGHT_FRONT_DIR, OUTPUT);
  pinMode (MOTOR_RIGHT_FRONT_EN, OUTPUT);
  pinMode (MOTOR_RIGHT_REAR_DIR, OUTPUT);
  pinMode (MOTOR_RIGHT_REAR_EN, OUTPUT);

  analogWrite (MOTOR_LEFT_FRONT_EN, 0);
  analogWrite (MOTOR_LEFT_REAR_EN, 0);
  analogWrite (MOTOR_RIGHT_FRONT_EN, 0);
  analogWrite (MOTOR_RIGHT_REAR_EN, 0);
}
void loop() {
  if (Serial.available()){
    BluetoothData=Serial.read();

     if(BluetoothData='y'){
        pad_x=Serial.parseInt();
        
        if(pad_x > 0){
         analogWrite (MOTOR_LEFT_FRONT_EN, pad_y);
         analogWrite (MOTOR_LEFT_REAR_EN, pad_y);
         analogWrite (MOTOR_RIGHT_FRONT_EN, pad_y);
         analogWrite (MOTOR_RIGHT_REAR_EN, pad_y);
 
         digitalWrite(MOTOR_LEFT_FRONT_DIR, DIR_FORWARD);
         digitalWrite(MOTOR_LEFT_REAR_DIR, DIR_FORWARD);
         digitalWrite(MOTOR_RIGHT_FRONT_DIR, DIR_FORWARD);
         digitalWrite(MOTOR_RIGHT_REAR_DIR, DIR_FORWARD);
        }
        else{
         analogWrite (MOTOR_LEFT_FRONT_EN, -pad_y);
         analogWrite (MOTOR_LEFT_REAR_EN, -pad_y);
         analogWrite (MOTOR_RIGHT_FRONT_EN, -pad_y);
         analogWrite (MOTOR_RIGHT_REAR_EN, -pad_y);
 
         digitalWrite(MOTOR_LEFT_FRONT_DIR, DIR_BACKWARD);
         digitalWrite(MOTOR_LEFT_REAR_DIR, DIR_BACKWARD);
         digitalWrite(MOTOR_RIGHT_FRONT_DIR, DIR_BACKWARD);
         digitalWrite(MOTOR_RIGHT_REAR_DIR, DIR_BACKWARD);
        }
     }
     if(BluetoothData='Y'){
      pad_y=Serial.parseInt();
      
      if(pad_y > 0){
         analogWrite (MOTOR_LEFT_FRONT_EN, pad_y);
         analogWrite (MOTOR_LEFT_REAR_EN, pad_y);
         analogWrite (MOTOR_RIGHT_FRONT_EN, pad_y-pad_x);
         analogWrite (MOTOR_RIGHT_REAR_EN, pad_y-pad_x);
      }
      else{
         analogWrite (MOTOR_LEFT_FRONT_EN, pad_y-pad_x);
         analogWrite (MOTOR_LEFT_REAR_EN, pad_y-pad_x);
         analogWrite (MOTOR_RIGHT_FRONT_EN, pad_y);
         analogWrite (MOTOR_RIGHT_REAR_EN, pad_y);
      }
     } 
 }   
}


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

char BluetoothData; // the Bluetooth data received

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

       if(BluetoothData=='D'){ //кнопка назад нажата
        //едем назад
        analogWrite (MOTOR_LEFT_FRONT_EN, 255);
        analogWrite (MOTOR_LEFT_REAR_EN, 255);
        analogWrite (MOTOR_RIGHT_FRONT_EN, 255);
        analogWrite (MOTOR_RIGHT_REAR_EN, 255);
 
        digitalWrite(MOTOR_LEFT_FRONT_DIR, DIR_BACKWARD);
        digitalWrite(MOTOR_LEFT_REAR_DIR, DIR_BACKWARD);
        digitalWrite(MOTOR_RIGHT_FRONT_DIR, DIR_BACKWARD);
        digitalWrite(MOTOR_RIGHT_REAR_DIR, DIR_BACKWARD);
       }
       if(BluetoothData=='U'){ //кнопка вперед нажата
        //едем вперед
        analogWrite (MOTOR_LEFT_FRONT_EN, 255);
        analogWrite (MOTOR_LEFT_REAR_EN, 255);
        analogWrite (MOTOR_RIGHT_FRONT_EN, 255);
        analogWrite (MOTOR_RIGHT_REAR_EN, 255);
 
        digitalWrite(MOTOR_LEFT_FRONT_DIR, DIR_FORWARD);
        digitalWrite(MOTOR_LEFT_REAR_DIR, DIR_FORWARD);
        digitalWrite(MOTOR_RIGHT_FRONT_DIR, DIR_FORWARD);
        digitalWrite(MOTOR_RIGHT_REAR_DIR, DIR_FORWARD);
       }
       if(BluetoothData=='R'){
        analogWrite (MOTOR_LEFT_FRONT_EN, 255);
        analogWrite (MOTOR_LEFT_REAR_EN, 255);
        analogWrite (MOTOR_RIGHT_FRONT_EN, 255);
        analogWrite (MOTOR_RIGHT_REAR_EN, 255);
 
        digitalWrite(MOTOR_LEFT_FRONT_DIR, DIR_FORWARD);
        digitalWrite(MOTOR_LEFT_REAR_DIR, DIR_FORWARD);
        digitalWrite(MOTOR_RIGHT_FRONT_DIR, DIR_BACKWARD);
        digitalWrite(MOTOR_RIGHT_REAR_DIR, DIR_BACKWARD);
       }
       if(BluetoothData=='L'){
        analogWrite (MOTOR_LEFT_FRONT_EN, 255);
        analogWrite (MOTOR_LEFT_REAR_EN, 255);
        analogWrite (MOTOR_RIGHT_FRONT_EN, 255);
        analogWrite (MOTOR_RIGHT_REAR_EN, 255);

        digitalWrite(MOTOR_LEFT_FRONT_DIR, DIR_BACKWARD);
        digitalWrite(MOTOR_LEFT_REAR_DIR, DIR_BACKWARD);
        digitalWrite(MOTOR_RIGHT_FRONT_DIR, DIR_FORWARD);
        digitalWrite(MOTOR_RIGHT_REAR_DIR, DIR_FORWARD);
       }
       if(BluetoothData=='u'||BluetoothData=='d'||BluetoothData=='r'||BluetoothData=='l'){
        analogWrite (MOTOR_LEFT_FRONT_EN, 0);
        analogWrite (MOTOR_LEFT_REAR_EN, 0);
        analogWrite (MOTOR_RIGHT_FRONT_EN, 0);
        analogWrite (MOTOR_RIGHT_REAR_EN, 0);
       }
  }
  delay(10);
}

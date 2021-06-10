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
int Bluetooth_spead=0;

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

  analogWrite (MOTOR_LEFT_FRONT_EN, Bluetooth_spead);
  analogWrite (MOTOR_LEFT_REAR_EN, Bluetooth_spead);
  analogWrite (MOTOR_RIGHT_FRONT_EN, Bluetooth_spead);
  analogWrite (MOTOR_RIGHT_REAR_EN, Bluetooth_spead);
  
  digitalWrite(MOTOR_LEFT_FRONT_DIR, DIR_FORWARD);
  digitalWrite(MOTOR_LEFT_REAR_DIR, DIR_FORWARD);
  digitalWrite(MOTOR_RIGHT_FRONT_DIR, DIR_FORWARD);
  digitalWrite(MOTOR_RIGHT_REAR_DIR, DIR_FORWARD);
}

void loop() {
 if (Serial.available()){
    BluetoothData=Serial.read();
       if(BluetoothData=='A'){ //задаём скорость 
        Bluetooth_spead=Serial.parseInt();
        analogWrite (MOTOR_LEFT_FRONT_EN, Bluetooth_spead);
        analogWrite (MOTOR_LEFT_REAR_EN, Bluetooth_spead);
        analogWrite (MOTOR_RIGHT_FRONT_EN, Bluetooth_spead);
        analogWrite (MOTOR_RIGHT_REAR_EN, Bluetooth_spead);
  } 
   if(BluetoothData=='R'){
        analogWrite (MOTOR_LEFT_FRONT_EN, Bluetooth_spead);
        analogWrite (MOTOR_LEFT_REAR_EN, Bluetooth_spead);
        analogWrite (MOTOR_RIGHT_FRONT_EN, Bluetooth_spead/5);
        analogWrite (MOTOR_RIGHT_REAR_EN, Bluetooth_spead/5);
   }
   if(BluetoothData=='L'){
        analogWrite (MOTOR_LEFT_FRONT_EN, Bluetooth_spead/5);
        analogWrite (MOTOR_LEFT_REAR_EN, Bluetooth_spead/5);
        analogWrite (MOTOR_RIGHT_FRONT_EN, Bluetooth_spead);
        analogWrite (MOTOR_RIGHT_REAR_EN, Bluetooth_spead);
   }
 }
}

/*
Projeto: MyoRoboticArm
Autor: Vinícius Oliveira Gonçalves
*/
 
#include <MyoBridge.h>
#include <SoftwareSerial.h>
#include <Servo.h>

//Fio Vermelho
Servo motor1;
//Fio Amarelo
Servo motor2;
//Fio Verde
Servo motor3;

int LED_CON = 11;
int LED_SINC = 12;
String Controle;
//SoftwareSerial connection to MyoBridge
SoftwareSerial bridgeSerial(2,3);

//initialize MyoBridge object with software serial connection
MyoBridge bridge(bridgeSerial);

//declare a function to handle pose data
void handlePoseData(MyoPoseData& data) {
  
  //convert pose data to MyoPose
  MyoPose pose;
  pose = (MyoPose)data.pose;

  //print the pose
  Serial.println(bridge.poseToString(pose));
  digitalWrite(LED_SINC,HIGH);
    
    
  Controle = bridge.poseToString(pose);
  if (Controle == "MYO_POSE_FIST")
  {
      PEDRA();
    
  }

    if (Controle == "MYO_POSE_FINGERS_SPREAD")
  {
     PAPEL();
    
  }

  if (Controle == "MYO_POSE_WAVE_OUT")
  {
      TESOURA();
    
  }
  
}

void setup() {
  //initialize both serial connections
  Serial.begin(115200);
  bridgeSerial.begin(115200);
  motor1.attach(6);
  motor2.attach(9);
  motor3.attach(10);
   pinMode(LED_CON, OUTPUT);
   pinMode(LED_SINC, OUTPUT);
   PEDRA();
  //wait until MyoBridge has found Myo and is connected. Make sure Myo is not connected to anything else and not in standby!
  Serial.println("Searching for Myo...");
  bridge.begin();
  Serial.println("connected!");
  digitalWrite(LED_CON,HIGH);

  //set the function that handles pose events
  bridge.setPoseEventCallBack(handlePoseData);
  //tell the Myo we want Pose data
  bridge.enablePoseData();
  //make sure Myo is unlocked
  bridge.unlockMyo();
  
  //You have to perform the sync gesture to receive Pose data!
}

void loop() {
  //update the connection to MyoBridge
  bridge.update();

}

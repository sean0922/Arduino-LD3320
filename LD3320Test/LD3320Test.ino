#include <ld3320.h>

VoiceRecognition Voice;                         
#define Led 8                                   
void setup()

{
    Serial.begin(9600);
    pinMode(Led,OUTPUT);                        //初始化LED
    digitalWrite(Led,LOW);                      
    Voice.init();                               
    Voice.addCommand("kai deng",0);             
    Voice.addCommand("guan deng",1);            
    Voice.start();//开始识别
}
void loop() {
  switch(Voice.read())                          
  {
    case 0:                                     
    digitalWrite(Led,HIGH);                 
    Serial.print("0");
        break;
    case 1:                                     //若是指令“guan deng”
    digitalWrite(Led,LOW);//熄灭LED
    Serial.print("1");
        break;  
    default:
    Serial.print("default");
        break;
  }
}

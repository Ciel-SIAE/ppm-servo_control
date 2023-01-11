#include <Servo.h>

#define rev_power 50   //-500~600

#define ppmPin 2
#define laltPin 3
#define lflapPin 4
#define rflapPin 6
#define raltPin 7
#define elePin 8
#define rudPin 9
#define mthPin 5
#define cothPin 10
#define revPin 11 
#define asPin A0 


int data[10];
// double num[4]={0,0,0,0};
// double kp=1;
// double ki=1;
// double kd=1;
 
unsigned long rc_PulseStartTicks;
volatile int rc_val;


Servo lalt;
Servo lflap;
Servo ralt;
Servo rflap;
Servo rud;
Servo ele;
Servo mth;
Servo coth;
Servo rev;

int lalt_data;
int lflap_data;
int ralt_data;
int rflap_data;
int rud_data;
int ele_data;
int mth_data;
int coth_data;
int rev_data;


void setup() {
    pinMode(ppmPin,INPUT);
  pinMode(asPin,INPUT);
  for(int i=3;i<=11;i++){
    pinMode (i,OUTPUT);
  }
 //Serial.begin(9600);
attachInterrupt(0, rc, RISING); 

//舵机端口
lalt.attach(laltPin);
ralt.attach(raltPin);
lflap.attach(lflapPin);
rflap.attach(rflapPin);
ele.attach(elePin);
rud.attach(rudPin);
mth.attach(mthPin);
coth.attach(cothPin);
rev.attach(revPin);
}
 
void loop() {
lalt_data=data[1]+(data[5]/6);
ralt_data=data[1]+(data[5]/6);
lflap_data=data[5]+(data[1]/4);
rflap_data=data[5]+(data[1]/4);
rud_data=data[4]+(data[1]/5);
ele_data=data[2];
mth_data=data[3];

if(data[3]<=-550){
    coth_data=rev_power;
    mth_data=-500;
    rev_data=600;
}else{
    rev_data=-500;
    coth_data=-500;
}
if(data[3]>=300){
    coth_data=map(data[3],300,600,-500,600);
}
if(data[3]>=-500&&data[3]<300){
    coth_data=-500;
}

if(lalt_data<=-600){
    lalt_data=-600;
}else if(lalt_data>=600){
    lalt_data=600;
}
if(ralt_data<=-600){
    ralt_data=-600;
}else if(ralt_data>=600){
    ralt_data=600;
}
if(lflap_data<=-600){
    lflap_data=-600;
}else if(lflap_data>=600){
    lflap_data=600;
}
if(rflap_data<=-600){
    rflap_data=-600;
}else if(rflap_data>=600){
    rflap_data=600;
}
if(ele_data<=-600){
    ele_data=-600;
}else if(ele_data>=600){
    ele_data=600;
}
if(rud_data<=-600){
    rud_data=-600;
}else if(rud_data>=600){
    rud_data=600;
}
if(mth_data<=-500){
    mth_data=-500;
}else if(mth_data>=600){
    mth_data=600;
}
if(coth_data<=-500){
    coth_data=-500;
}else if(coth_data>=600){
    coth_data=600;
}
if(rev_data<=-500){
    rev_data=-500;
}else if(rev_data>=600){
    rev_data=600;
}


lalt.write(map(lalt_data,-600,600,10,170));
ralt.write(map(ralt_data,-600,600,10,170));
lflap.write(map(lalt_data,-600,600,10,170));
rflap.write(map(lalt_data,-600,600,10,170));
ele.write(map(ele_data,-600,600,10,170));
rud.write(map(rud_data,-600,600,10,170));
mth.write(map(mth_data,-500,600,5,180));
coth.write(map(mth_data,-500,600,5,180));
rev.write(map(rev_data,-500,600,5,180));
 }
 


void rc()
{
    static int m=0;
    static int time_tr[12];
     rc_val = micros() - rc_PulseStartTicks; 
     rc_PulseStartTicks = micros();    // store the current micros() value 
     if(rc_val>400&&rc_val<3000){
     time_tr[m]=rc_val; 
     m++;
     }
     else if(rc_val>=3000){
      for(int i=0;i<=m;i++){
        data[9-m+i]=time_tr[i]-1500;          
      }
      m=0;
     }
}

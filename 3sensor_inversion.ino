#define left_m1 5
#define left_m2 7
#define left_th 6


#define right_m1 4
#define right_m2 2
#define right_th 3


#define center_s A0
#define left_s  A2
#define right_s A1
#define front_s   A3
#define back_s  A4
#define t 0.8 //0.75  at 11.3 tested 0.65 at full
#define LED 13
bool left, center, right, front, back, inversion = false;

void setup() {
  // put your setup code here, to run once:
// place the sensor apart


  pinMode(left_m1, OUTPUT);
  pinMode(left_m2, OUTPUT);
  pinMode(left_th, OUTPUT);


  pinMode(right_m1, OUTPUT);
  pinMode(right_m2, OUTPUT);
  pinMode(right_th, OUTPUT);


  pinMode(center_s, INPUT);
  pinMode(left_s, INPUT);
  pinMode(right_s, INPUT);
  pinMode(front_s, INPUT);
  pinMode(back_s, INPUT);

  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:


center = digitalRead(center_s);
left=digitalRead(left_s);
right = digitalRead(right_s);
front   = digitalRead(front_s);
back    = digitalRead(back_s);

inversion = (front && left) || (front && back) ||(back && left); 
digitalWrite(LED, inversion);

 if((center==1 && left == 0 && inversion == 0) ||(center== 0 && left == 1 && inversion == 1))
  {
while((center==1 && left == 0 && inversion == 0) ||(center== 0  && left == 1 && inversion == 1))
{
      analogWrite(right_th, 255*t);
      digitalWrite(right_m2, LOW);
      digitalWrite(right_m1, HIGH);
      digitalWrite(left_th, LOW);
       
      center = digitalRead(center_s);
      left=digitalRead(left_s);

      front   = digitalRead(front_s);
      back    = digitalRead(back_s);

      inversion = (front && left) || (front && back) ||(back && left); 
      digitalWrite(LED, inversion);
}
}

if((center==0&&left==0 && right == 1 && inversion == 0 ) ||(center == 1 &&left== 1 && right == 0 && inversion == 1 ))
  {
while((center==0&&left==0&& right == 1 && inversion == 0) || (center== 1&&left== 1&& right == 0 && inversion == 1))
{
     analogWrite(left_th, 255*t);
      digitalWrite(left_m2, LOW);
      digitalWrite(left_m1, HIGH);
      digitalWrite(right_th, LOW); 
      center = digitalRead(center_s);
      right  = digitalRead(right_s);
      left=digitalRead(left_s);

      front   = digitalRead(front_s);
      back    = digitalRead(back_s);

      inversion = (front && left) || (front && back) ||(back && left); 
      digitalWrite(LED, inversion);
}
   }

if((left==1 && inversion == 0) || (left == 0 && inversion == 1))
  {
    while((!(center== 1 && left== 0 ) && inversion == 0) || (!(center== 0 && left== 1 ) && inversion == 1))
    {
      analogWrite(left_th, 200);
      digitalWrite(left_m2, HIGH);
      digitalWrite(left_m1, LOW);

      analogWrite(right_th, 200);
      digitalWrite(right_m2, LOW);
      digitalWrite(right_m1, HIGH); 
      

      
      center = digitalRead(center_s);
      left=digitalRead(left_s);
      front   = digitalRead(front_s);
      back    = digitalRead(back_s);

      inversion = (front && left) || (front && back) ||(back && left); 
      digitalWrite(LED, inversion);
    }
    
  }
if((left== 0 && right == 0 && center == 0 && inversion == 0) || (left== 1 && right == 1 && center == 1 && inversion == 1) )
  {
    while((center==0&&left==0 && inversion == 0) || (center== 1 && left== 1 && inversion == 1))
{
     analogWrite(left_th, 200*t);
      digitalWrite(left_m2, LOW);
      digitalWrite(left_m1, HIGH);

      analogWrite(right_th, 100*t);
      digitalWrite(right_m2, HIGH);
      digitalWrite(right_m1, LOW);
      
      center = digitalRead(center_s);
      right  = digitalRead(right_s);
      left=digitalRead(left_s);

       front   = digitalRead(front_s);
       back    = digitalRead(back_s);

      inversion = (front && left) || (front && back) ||(back && left); 
      digitalWrite(LED, inversion);
}
    
  }



}

int income;
void setup()
{
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  Serial.begin(9600);
  digitalWrite(4,LOW);
  delay(10);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  delay(10);
  digitalWrite(4,HIGH);
  delay(10);
  
 }


void loop()
{

  if(Serial.available()>0)
  {
    income=Serial.read();

    digitalWrite(4,LOW);
    delay(10);
    if(income=='0')
    {
       digitalWrite(5,LOW);
       digitalWrite(6,LOW);
       digitalWrite(2,LOW);
       digitalWrite(3,LOW);
    }
    if(income=='1')
    {
       digitalWrite(5,HIGH);
       digitalWrite(6,LOW);
       digitalWrite(2,LOW);
       digitalWrite(3,LOW);
    }
    if(income=='2')
    {
       digitalWrite(5,LOW);
       digitalWrite(6,HIGH);
       digitalWrite(2,LOW);
       digitalWrite(3,LOW);
    }
    if(income=='3')
    {
       digitalWrite(5,HIGH);
       digitalWrite(6,HIGH);
       digitalWrite(2,LOW);
       digitalWrite(3,LOW);
    }
    if(income=='4')
    {
       digitalWrite(5,LOW);
       digitalWrite(6,LOW);
       digitalWrite(2,HIGH);
       digitalWrite(3,LOW);
    }
    if(income=='5')
    {
       digitalWrite(5,HIGH);
       digitalWrite(6,LOW);
       digitalWrite(2,HIGH);
       digitalWrite(3,LOW);
    }
    if(income=='6')
    {
       digitalWrite(5,LOW);
       digitalWrite(6,HIGH);
       digitalWrite(2,HIGH);
       digitalWrite(3,LOW);
    }
    if(income=='7')
    {
       digitalWrite(5,HIGH);
       digitalWrite(6,HIGH);
       digitalWrite(2,HIGH);
       digitalWrite(3,LOW);
    }
    if(income=='8')
    {
       digitalWrite(5,LOW);
       digitalWrite(6,LOW);
       digitalWrite(2,LOW);
       digitalWrite(3,HIGH);
    }
    if(income=='9')
    {
       digitalWrite(5,HIGH);
       digitalWrite(6,LOW);
       digitalWrite(2,LOW);
       digitalWrite(3,HIGH);
    }
     
    
    delay(1000);
    digitalWrite(4,HIGH);
 
  }
 
}   

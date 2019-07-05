# ***Hello, it is a summary from me -姚磊***
## **DAY1(7.2)**
  . 老师分享了经验
  
  . 下载三个软件
  
      Arduino
   
      Processing
   
      Fritzing
   
  . 注册了github的账号（the best part）
## **DAY2(7.3)**
  ### *run  the morse code* 
       . 学习用morse电码表示输入进来的字母。
```       
#include <Morse.h>
String str=""; 
String st="";  
void change(int n) //转化函数，根据读取的ASCII码转化为Morse电码表示
{
  switch(n)//26个字母加上空格回车的Morse电码
  {
    case 97:str="*-  ";break;//a
    case 98:str="-***";break;//b
    case 99:str="-*-*";break;//c
    case 100:str="-** ";break;//d
    case 101:str="*   ";break;//e
    case 102:str="**-*";break;//f
    case 103:str="--* ";break;//g
    case 104:str="****";break;//h
    case 105:str="**  ";break;//i
    case 106:str="*---";break;//j
    case 107:str="-*- ";break;//k
    case 108:str="*-**";break;//l
    case 109:str="--  ";break;//m
    case 110:str="-*  ";break;//n
    case 111:str="--- ";break;//o
    case 112:str="*--*";break;//p
    case 113:str="--*-";break;//q
    case 114:str="*-* ";break;//r
    case 115:str="*** ";break;//s
    case 116:str="-   ";break;//t
    case 117:str="**- ";break;//u
    case 118:str="***-";break;//v
    case 119:str="*-- ";break;//w
    case 120:str="-**-";break;//x
    case 121:str="-*--";break;//y
    case 122:str="--**";break;//z
    case 32:str="*-*-";break;// 
    case 10:str="----";break;// /n
    default:break;
  }
}
Morse morse(13);
void setup() {
  
  Serial.begin(9600);//设置波特率为9600
}

void loop() {
  while(Serial.available()>0)
  {
    change(Serial.read());  
    st+=str;
    st+=' ';
    str="";
  }
  
    int i=0,k=0;
    k=st.length();
    for(i=0;i<k;i++)
    {
      if(st[i]=='*')
      morse.dot();       //.
      if(st[i]=='-')
      morse.dash();      //-
      delay(100);         //Morse电码之间的间隔
    }
    delay(400);          //字符与字符之间间隔
    str="";              
  }
  ```
## **DAY3(7.4)**
  ### *run and stimulate the car code and the light code*
       . 学习用代码驱动电机和LED灯，来模拟小车前进后退转向
       . 学习用代码控制七段数码管，用七段数码管显示输入的数字
       . 在tinkercad上在线模拟以上的两个代码
 ```
 void setup()
{
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(3,OUTPUT);  //右下
  pinMode(4,OUTPUT);  //左下
  pinMode(11,OUTPUT);  //右上
  pinMode(12,OUTPUT);//左上
  Serial.begin(9600);  
}


int income=0;
void loop()
{
  if(Serial.available()>0)
  {
    income=Serial.read();
    switch(income)
    {
      case 'f':forward();break;
      case 'b':backward();break;
      case 'r':right();break;
      case 'l':left();break;
      case 's':stop();break;
      default:break;
    }
  }  
}

void forward()
{
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
}

void backward()
{
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
}
void right()
{
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(11,HIGH);
  digitalWrite(12,LOW);
}
void left()
{
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(11,LOW);
  digitalWrite(12,HIGH);
}
void stop()
{
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
}
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
```


## **DAY4(7.5)**
  ### *stimulate my morse code*
        . 在7.3的基础上将代码在tinkercad上模拟
        . 做总结
## 感想
  从小学开始的学习几乎都是纯理论的学习，直到大一下学期我们学习了微处理器原理，我觉得这是第一门相对实践的课程，而这门课--开源硬件实战，才真正让我感受到理论和实践结合的巨大不同。如果说理论是一层基础，那么实践就是高楼大厦，空有理论是完全不够的，而对于我们这个专业来说，更多的需要的就是实践，实践是检验真理的唯一标准。这几天下来，几乎每天上课都会遇到听不懂的情况，深深感受到自身知识储备的不足，而到了下课做作业的时候再慢慢摸索，往往会经历一个过程，从开始的非常懵逼，然后再回想一下上课讲了什么，再动手试试写代码以及连接电路（虽然还么学过数电模电），跟同学在交流一下看法，（这一点我认为很重要，学习的过程中交流是一个必不可少的环节，每个人对于知识的理解不一样，所以会产生不同的效应）。总之，这几天收获颇丰！！

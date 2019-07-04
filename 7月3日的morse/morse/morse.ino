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

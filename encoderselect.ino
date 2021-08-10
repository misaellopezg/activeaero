int enclk = 7, endt = 6, enbttn = 8;
int prevclkstate, clkstate, dtstate;
int mainmenuptr, submenuptr; 
long curtime,prevtime; 
void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(enclk, INPUT);
  pinMode(endt, INPUT);
  pinMode(enbttn,INPUT_PULLUP);
  prevclkstate = digitalRead(enclk);
  mainmenuptr = 0;
  prevtime = millis(); 
}

void loop() 
{
  curtime = millis();
  menuselect();
  mainmenu();
  //Serial.println(curtime - prevtime);
  prevtime = curtime;
}

void menuselect()
{
  clkstate = digitalRead(enclk);
  if(clkstate != prevclkstate && clkstate)
  {
    dtstate = digitalRead(endt);
    if(clkstate != dtstate)
    {
      mainmenuptr++;
      if(mainmenuptr > 6)
      {
       mainmenuptr = 6;  
      }
    }
    else
    {
      mainmenuptr--;
      if(mainmenuptr < 0)
      {
         mainmenuptr = 0;  
      }
    }
    //*/
  }
  prevclkstate = clkstate;
}

void mainmenu()
{
  switch(mainmenuptr)
  {
     case 0:
      Serial.println("Auto");
     break;
     case 1:
      Serial.println("Manual");
     break;
     case 2:
      Serial.println("Calibration");
     break;
     case 3:
      Serial.println("George");
     break;
     case 4:
      Serial.println("Misa");
     break;
     case 5:
      Serial.println("Yoshio");
     break;
     case 6:
      Serial.println("Yip");
     break;
     default:
      Serial.println("Hi");
  }
}

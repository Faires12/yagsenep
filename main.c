#include <Adafruit_GFX.h>
#include <Arduino_ST7789_Fast.h>

#define TFT_DC    7
#define TFT_RST   8 
#define SCR_WD   240
#define SCR_HT   240   

Arduino_ST7789 lcd = Arduino_ST7789(TFT_DC, TFT_RST);

int menuCtrl = 0;
char GameName[]="EggRace";

struct Object{
  int x;
  int y;
  int width;
  int height;
};

void setup()
{
  Serial.begin(9600);
  lcd.init(SCR_WD, SCR_HT);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  Menu(menuCtrl);
 }

void loop()
{
       lcd.fillScreen(BLACK);
        lcd.fillRect(0, 0, 48, 240, GREY);
        lcd.fillRect(192, 0, 48, 240, GREY);
        Jogar();
    if(digitalRead(2) == LOW){
      if(menuCtrl < 3){
        menuCtrl++;
        Menu(menuCtrl);
      }  
    } else if(digitalRead(3) == LOW){
      if(menuCtrl > 0){
        menuCtrl--;
        Menu(menuCtrl);
      }  
    } else if(digitalRead(5) == LOW){
      if(menuCtrl == 0){
        lcd.fillScreen(BLACK);
        lcd.fillRect(0, 0, 48, 240, GREY);
        lcd.fillRect(192, 0, 48, 240, GREY);
        Jogar();
      }    
  }
  
  Serial.println(menuCtrl);
  delay(20);
}

void Menu(int opc){
  lcd.fillScreen(BLACK);
  for(int i=0;i<21;i++){
    lcd.fillRect(i*20, 0, 10, 2, YELLOW);
    lcd.fillRect(i*20, 50, 10, 2, YELLOW);
  }
  Escrever(GameName, 60, 15, 3, WHITE, 1);
  Escrever("Jogar", 60, 80, 3, WHITE, 0-opc);
  Escrever("Ranking", 60, 110, 3, WHITE, 1-opc);
  Escrever("Creditos", 60, 140, 3, WHITE, 2-opc);
  Escrever("Historia", 60 , 170, 3, WHITE, 3-opc);

  lcd.fillRect(40, 80+30*opc+10, 5, 5, RED);
}

void Escrever(char *text, int X, int Y, int FontSize, char FontColor, int selected){
  lcd.setCursor(X, Y);
  lcd.setTextColor(FontColor);
  lcd.setTextSize(FontSize);
  if(!selected)
    lcd.setTextColor(YELLOW);
  lcd.println(text);
}

void Jogar(){
  Object objetos[5];
  Object player;
  int genCount = 0;
  int genCd = 60;
  int objsCount = 0;

  player.x = 102;
  player.y = 190;
  player.width = 25;
  player.height = 45;
  
  int xAnterior = player.x;
  bool run = true;  
  while(run){
      drawBG();
      drawObjects(objetos, objsCount, player);
      moveObjects(objetos, objsCount);
      
      xAnterior = player.x;
      player.x = map(analogRead(A0), 0, 1023, 167, 48);

      if(objsCount < 5){
          if(genCount == 0){
            objetos[objsCount].x = random(48, 144);
            objetos[objsCount].y = 3;
            objetos[objsCount].width = 25;
            objetos[objsCount].height = 45;
            genCount = 1;
            objsCount++;
          } else{
            if(genCount >= genCd){
              genCount = 0;
            } else{
              genCount++;
            }
        }
      }      
      delay(100);
      clearObjects(objetos, objsCount, xAnterior);
      checkColisions(objetos, objsCount, player);
      Serial.println(random(48, 144), random(48, 144));
  }
}

void drawBG(){
    for(int i = 1; i < 5; i++){
      lcd.fillRect(72, (19*i)+((i-1)*48), 1, 48, YELLOW);
      lcd.fillRect(120, (19*i)+((i-1)*48), 1, 48, YELLOW);
      lcd.fillRect(168, (19*i)+((i-1)*48), 1, 48, YELLOW);
    }
}

void drawObjects(Object objs[], int lenght, Object player){
  for(int i = 0; i < lenght; i++){
    lcd.fillRect(objs[i].x, objs[i].y, objs[i].width, objs[i].height, RED);
  }
  lcd.fillRect(player.x, player.y, player.width, player.height, BLUE);
}

void moveObjects(Object objs[], int lenght){
  for(int i = 0; i < lenght; i++){
    objs[i].y += 12;
    if(objs[i].y > 250){
      objs[i].x = random(48, 144);
      objs[i].y = -50;
    }
  }
}

void clearObjects(Object objs[], int lenght, int xAnterior){
  for(int i = 0; i < lenght; i++){
    lcd.fillRect(objs[i].x, objs[i].y-12, objs[i].width, objs[i].height, BLACK);
  }
  lcd.fillRect(xAnterior, 190, 25, 45, BLACK);
}

void checkColisions(Object object[], int lenght, Object player){
  for(int i = 0; i < lenght; i++){
    if(player.x < object[i].x + object[i].width && player.x + player.width > object[i].x &&
    player.y < object[i].y + object[i].height && player.y + player.height > object[i].y){
      Serial.println("Col");
    }
  }
}

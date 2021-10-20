#define BLACK 0x0000
#define BLUE 0x001F
#define RED 0xF800
#define GREEN 0x07E0
#define CYAN 0x07FF
#define MAGENTA 0xF81F
#define YELLOW 0xFFE0
#define WHITE 0xFFFF

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>             // Arduino SPI library

// ST7789 TFT module connections
#define TFT_CS    10  // define chip select pin
#define TFT_DC     9  // define data/command pin
#define TFT_RST    8  // define reset pin, or set to -1 and connect to Arduino RESET pin

// Initialize Adafruit ST7789 TFT library
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);



int x = 30;
int y = 30;
int dim = 30;
int velX = 1;
int velY = 1;

void setup(void) {
  Serial.begin(9600);
  Serial.print(F("Hello! ST77xx TFT Test"));

  // if the display has CS pin try with SPI_MODE0
  tft.init(240, 240, SPI_MODE2);    // Init ST7789 display 240x240 pixel

  // if the screen is flipped, remove this command
  tft.setRotation(2);

  Serial.println(F("Initialized"));

  tft.fillScreen(BLACK);
  tft.drawRect(30, 30, 30, 30, RED);
  
}

void loop() {
  draw();
  AtualizarPosicao();
}

void AtualizarPosicao(){
    x += velX;
    y += velY;
    if(x <= 0 || x + dim >= tft.width()){
        velX *= -1;  
    }
    if(y <= 0 || y + dim >= tft.height()){
        velY *= -1;  
    }
}

void draw(){
    tft.fillScreen(BLACK);
    tft.drawRect(x, y, dim, dim, RED);
}


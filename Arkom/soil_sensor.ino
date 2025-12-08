#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Pin sensor & buzzer
#define SOIL_PIN     34
#define BUZZER_PIN   26 // Buzzer LOW ACTIVE

// Pin LED indikator
#define LED_KERING   32   // Merah
#define LED_IDEAL    33  // Hijau  
#define LED_BASAH    25   // Biru (atau putih)

// Kalibrasi capacitive (sesuaikan sekali)
const int Value_Kering = 2900;   // di udara
const int Value_Basah  = 1200;   // terendam air

void setup() {
  Serial.begin(115200);

  // LED sebagai output
  pinMode(LED_KERING, OUTPUT);
  pinMode(LED_IDEAL,  OUTPUT);
  pinMode(LED_BASAH,  OUTPUT);
  digitalWrite(LED_KERING, LOW);
  digitalWrite(LED_IDEAL,  LOW);
  digitalWrite(LED_BASAH,  LOW);

  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, HIGH); 

  Wire.begin(14, 27);  // SDA = 14, SCL = 27
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED gagal!");
    while (1);
  }

  // Tampilan awal
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(15, 20);
  display.println("SIAP!");
  display.display();
  delay(2000);
}

void loop() {
  int raw = analogRead(SOIL_PIN);
  int persen = map(constrain(raw, Value_Basah, Value_Kering), 
                   Value_Basah, Value_Kering, 100, 0);

  // Matikan semua LED dan buzzer dulu
  digitalWrite(LED_KERING, LOW);
  digitalWrite(LED_IDEAL,  LOW);
  digitalWrite(LED_BASAH,  LOW);
  digitalWrite(BUZZER_PIN, HIGH); 

  // Tentukan status & nyalakan LED + buzzer
  if (persen >= 70) {              // TERLALU BASAH (Wajib Kuras)
    digitalWrite(LED_BASAH, HIGH);
    digitalWrite(BUZZER_PIN, LOW); 
  }
  else if (persen <= 40) {         // TERLALU KERING (Wajib Siram)
    digitalWrite(LED_KERING, HIGH);
    digitalWrite(BUZZER_PIN, LOW); 
  }
  else {                           // IDEAL 41–69%
    digitalWrite(LED_IDEAL, HIGH);
  }

  // ==== Update OLED Display ====
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("KELEMBAPAN TANAH");
  display.drawLine(0, 10, 127, 10, WHITE);

  display.setTextSize(3);
  display.setCursor(20, 20);
  display.print(persen);
  display.print("%");

  display.setTextSize(1);
  display.setCursor(5, 50);
  if (persen >= 70)      display.println(">> TERLALU BASAH <<");
  else if (persen <= 40) display.println(">> TERLALU KERING <<");
  else                   display.println(">> KONDISI IDEAL   <<");

  display.display();

  // ==== Output Serial Debugging ====
  Serial.printf("Raw: %d | %d%% | Status: ", raw, persen);
  if (persen >= 70) Serial.println("BASAH (Biru + Buzzer ON)");
  else if (persen <= 40) Serial.println("KERING (Merah + Buzzer ON)");
  else Serial.println("IDEAL (Hijau + Buzzer OFF)");
  
  delay(500);
}

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Pin sensor & buzzer
#define SOIL_PIN     34
#define BUZZER_PIN   26  // Buzzer LOW ACTIVE (ON saat LOW)

// Pin LED indikator
#define LED_KERING   32  // Merah
#define LED_IDEAL    33  // Hijau  
#define LED_BASAH    25  // Biru

// Kalibrasi capacitive
const int Value_Kering = 2900;   // di udara
const int Value_Basah  = 1200;   // terendam air

// Variabel untuk non-blocking buzzer
unsigned long buzzerStartTime = 0;
int beepCount = 0;
int beepState = 0;
bool buzzerActive = false;

// Variabel status tanah
enum SoilStatus { KERING, IDEAL, BASAH };
SoilStatus currentStatus = IDEAL;
SoilStatus lastStatus = IDEAL;

void setup() {
  Serial.begin(115200);

  // LED sebagai output
  pinMode(LED_KERING, OUTPUT);
  pinMode(LED_IDEAL, OUTPUT);
  pinMode(LED_BASAH, OUTPUT);
  digitalWrite(LED_KERING, LOW);
  digitalWrite(LED_IDEAL, LOW);
  digitalWrite(LED_BASAH, LOW);

  // Buzzer sebagai output (LOW ACTIVE)
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, HIGH); // Matikan buzzer (HIGH untuk LOW ACTIVE)

  // Inisialisasi OLED
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

// Fungsi untuk mengontrol buzzer dengan pola beep
void controlBuzzerPattern(SoilStatus status) {
  unsigned long currentMillis = millis();
  
  // Jika status berubah, reset pola buzzer
  if (status != lastStatus) {
    buzzerActive = false;
    digitalWrite(BUZZER_PIN, HIGH); // Matikan buzzer
    lastStatus = status;
  }
  
  // Atur pola beep berdasarkan status
  if (!buzzerActive) {
    buzzerActive = true;
    buzzerStartTime = currentMillis;
    beepCount = 0;
    beepState = 0;
  }
  
  // Logika pola beep non-blocking
  switch (status) {
    case BASAH:  // 1 beep panjang setiap 3 detik
      if (currentMillis - buzzerStartTime >= 3000) {
        buzzerStartTime = currentMillis;
        beepCount = 0;
      }
      if (currentMillis - buzzerStartTime < 500) {
        digitalWrite(BUZZER_PIN, LOW);  // ON
      } else {
        digitalWrite(BUZZER_PIN, HIGH); // OFF
      }
      break;
      
    case KERING: // 2 beep pendek setiap 2 detik
      if (currentMillis - buzzerStartTime >= 2000) {
        buzzerStartTime = currentMillis;
        beepCount = 0;
      }
      
      if (beepCount < 2) {
        unsigned long beepStart = buzzerStartTime + (beepCount * 600);
        if (currentMillis - beepStart < 200) {
          digitalWrite(BUZZER_PIN, LOW);  // ON
        } else if (currentMillis - beepStart < 400) {
          digitalWrite(BUZZER_PIN, HIGH); // OFF
        } else {
          beepCount++;
        }
      } else {
        digitalWrite(BUZZER_PIN, HIGH); // OFF
      }
      break;
      
    case IDEAL: // Buzzer mati total
      digitalWrite(BUZZER_PIN, HIGH); // OFF
      buzzerActive = false;
      break;
  }
}

void updateDisplay(int persen, SoilStatus status) {
  display.clearDisplay();
  
  // Header
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("KELEMBAPAN TANAH");
  display.drawLine(0, 10, 127, 10, WHITE);
  
  // Persentase besar
  display.setTextSize(3);
  display.setCursor(20, 20);
  display.print(persen);
  display.print("%");
  
  // Status
  display.setTextSize(1);
  display.setCursor(5, 50);
  switch (status) {
    case BASAH:
      display.println(">> TERLALU BASAH <<");
      break;
    case KERING:
      display.println(">> TERLALU KERING <<");
      break;
    case IDEAL:
      display.println(">> KONDISI IDEAL  <<");
      break;
  }
  
  display.display();
}

void loop() {
  // Baca sensor
  int raw = analogRead(SOIL_PIN);
  int persen = map(constrain(raw, Value_Basah, Value_Kering), 
                   Value_Basah, Value_Kering, 100, 0);
  
  // Tentukan status
  if (persen >= 70) {
    currentStatus = BASAH;
  } else if (persen <= 40) {
    currentStatus = KERING;
  } else {
    currentStatus = IDEAL;
  }
  
  // Update LED berdasarkan status
  digitalWrite(LED_KERING, (currentStatus == KERING) ? HIGH : LOW);
  digitalWrite(LED_IDEAL, (currentStatus == IDEAL) ? HIGH : LOW);
  digitalWrite(LED_BASAH, (currentStatus == BASAH) ? HIGH : LOW);
  
  // Kontrol buzzer dengan pola non-blocking
  controlBuzzerPattern(currentStatus);
  
  // Update display
  updateDisplay(persen, currentStatus);
  
  // Debug serial
  Serial.printf("Raw: %d | %d%% | Status: ", raw, persen);
  switch (currentStatus) {
    case BASAH:
      Serial.println("BASAH (Biru + Buzzer 1x)");
      break;
    case KERING:
      Serial.println("KERING (Merah + Buzzer 2x)");
      break;
    case IDEAL:
      Serial.println("IDEAL (Hijau + Buzzer OFF)");
      break;
  }
  
  delay(100); // Delay pendek untuk stabilitas
}

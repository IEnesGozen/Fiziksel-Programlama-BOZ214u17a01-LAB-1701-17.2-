/* 
 * Bölüm 17.2: RAM Takip ve Tüketme Deneyi 
 * Bu kod, belleğin (SRAM) nasıl tükendiğini simüle eder.
 */

extern int _brkval; // Heap üzerindeki son adresi tutan değişken
extern int __malloc_heap_start; // Heap başlangıç adresi

String bellekCanavari = ""; // Belleği tüketecek olan dinamik değişken

void setup() {
  Serial.begin(9600);
  Serial.println("--- Bellek Analizi Basliyor ---");
  Serial.print("Baslangictaki Bos RAM: ");
  Serial.println(memoryFree());
  Serial.println("-------------------------------");
}

void loop() {
  // Her döngüde String'e yeni veri ekleyerek belleği tüketiyoruz
  bellekCanavari += "Bu metin her saniye RAM bellegini biraz daha dolduracak... "; 
  
  Serial.print("Kalan Bos RAM (Bayt): ");
  Serial.println(memoryFree());
  
  delay(1000); 
}

// Boş RAM hesaplama fonksiyonu
int memoryFree() {
  int freeValue; 
  if ((int)_brkval == 0) {
    // Heap boşsa başlangıç adresini kullan
    freeValue = ((int)&freeValue) - ((int)&__malloc_heap_start);
  } else {
    // Heap doluysa güncel heap adresini kullan
    freeValue = ((int)&freeValue) - ((int)_brkval);
  }
  return freeValue;
}

 
// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = "RnpkQsXWxCekSi5IDNKaNAICh9-n-FtL";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Verizon-SM-G955U-2E03";
char pass[] = "1234567890";

void setup()
{
  // Debug console
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass,"blynk-cloud.com",8080);
}

void loop()
{
  Blynk.run();
}

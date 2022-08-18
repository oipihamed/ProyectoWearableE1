
#include <FirebaseESP32.h>
#include <WiFi.h>
#include <Tone32.hpp>
#include "DHT.h"
#include <ESP_Mail_Client.h>

#define DHTPIN 15
#define DHTTYPE DHT11
//Inicio Correo
#define SMTP_HOST "smtp.gmail.com"
#define SMTP_PORT 465

/* The sign in credentials */
#define AUTHOR_EMAIL "icidomar15@gmail.com"
#define AUTHOR_PASSWORD "bpynjkksjvaovgmu"

/* Recipient's email*/
#define RECIPIENT_EMAIL "alexsoriamqz@gmail.com"


struct Button {
    const uint8_t PIN;
    uint32_t numberKeyPresses;
    bool pressed;
};
//Salida grafica sensor pulso

SMTPSession smtp;

/* Callback function to get the Email sending status */
void smtpCallback(SMTP_Status status);

Button button1 = {12, 0, false};

//variables to keep track of the timing of recent interrupts
unsigned long button_time = 0;  
unsigned long last_button_time = 0; 

void IRAM_ATTR isr() {
    button_time = millis();
if (button_time - last_button_time > 250)
{
        button1.numberKeyPresses++;
        button1.pressed = true;
       last_button_time = button_time;
}
}
//Fin correo
//create an instance of DHT sensor
DHT dht(DHTPIN, DHTTYPE);

#define FIREBASE_HOST "llaveroint-default-rtdb.firebaseio.com/" // Do not include https:// in FIREBASE_HOST
#define FIREBASE_AUTH "8f3iDKM9eWeXuUi4hYCmQliUpjtZYzS47U6oVnBa"

//#define WIFI_SSID "Ubee28B4-2.4G"
//#define WIFI_PASSWORD "B5D7FA28B4"

#define WIFI_SSID "SGN9"
#define WIFI_PASSWORD "123456789"

//#define WIFI_SSID "HUAWEI-061RW2_Wi-Fi5"
//#define WIFI_PASSWORD "Sh4rpsh00t3r#2"

#define NOTE_B0 31
#define NOTE_C1 33
#define NOTE_CS1 35
#define NOTE_D1 37
#define NOTE_DS1 39
#define NOTE_E1 41
#define NOTE_F1 44
#define NOTE_FS1 46
#define NOTE_G1 49
#define NOTE_GS1 52
#define NOTE_A1 55
#define NOTE_AS1 58
#define NOTE_B1 62
#define NOTE_C2 65
#define NOTE_CS2 69
#define NOTE_D2 73
#define NOTE_DS2 78
#define NOTE_E2 82
#define NOTE_F2 87
#define NOTE_FS2 93
#define NOTE_G2 98
#define NOTE_GS2 104
#define NOTE_A2 110
#define NOTE_AS2 117
#define NOTE_B2 123
#define NOTE_C3 131
#define NOTE_CS3 139
#define NOTE_D3 147
#define NOTE_DS3 156
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_FS3 185
#define NOTE_G3 196
#define NOTE_GS3 208
#define NOTE_A3 220
#define NOTE_AS3 233
#define NOTE_B3 247
#define NOTE_C4 262
#define NOTE_CS4 277
#define NOTE_D4 294
#define NOTE_DS4 311
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_FS4 370
#define NOTE_G4 392
#define NOTE_GS4 415
#define NOTE_A4 440
#define NOTE_AS4 466
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_DS5 622
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_FS5 740
#define NOTE_G5 784
#define NOTE_GS5 831
#define NOTE_A5 880
#define NOTE_AS5 932
#define NOTE_B5 988
#define NOTE_C6 1047
#define NOTE_CS6 1109
#define NOTE_D6 1175
#define NOTE_DS6 1245
#define NOTE_E6 1319
#define NOTE_F6 1397
#define NOTE_FS6 1480
#define NOTE_G6 1568
#define NOTE_GS6 1661
#define NOTE_A6 1760
#define NOTE_AS6 1865
#define NOTE_B6 1976
#define NOTE_C7 2093
#define NOTE_CS7 2217
#define NOTE_D7 2349
#define NOTE_DS7 2489
#define NOTE_E7 2637
#define NOTE_F7 2794
#define NOTE_FS7 2960
#define NOTE_G7 3136
#define NOTE_GS7 3322
#define NOTE_A7 3520
#define NOTE_AS7 3729
#define NOTE_B7 3951
#define NOTE_C8 4186
#define NOTE_CS8 4435
#define NOTE_D8 4699
#define NOTE_DS8 4978
#define REST 0

int tempo = 160;

int melody1[] = {

  // Game of Thrones
  // Score available at https://musescore.com/user/8407786/scores/2156716

  NOTE_G4,8, NOTE_C4,8, NOTE_DS4,16, NOTE_F4,16, NOTE_G4,8, NOTE_C4,8, NOTE_DS4,16, NOTE_F4,16, //1
  NOTE_G4,8, NOTE_C4,8, NOTE_DS4,16, NOTE_F4,16, NOTE_G4,8, NOTE_C4,8, NOTE_DS4,16, NOTE_F4,16,
  NOTE_G4,8, NOTE_C4,8, NOTE_E4,16, NOTE_F4,16, NOTE_G4,8, NOTE_C4,8, NOTE_E4,16, NOTE_F4,16,
  NOTE_G4,8, NOTE_C4,8, NOTE_E4,16, NOTE_F4,16, NOTE_G4,8, NOTE_C4,8, NOTE_E4,16, NOTE_F4,16,
  NOTE_G4,-4, NOTE_C4,-4,//5

  NOTE_DS4,16, NOTE_F4,16, NOTE_G4,4, NOTE_C4,4, NOTE_DS4,16, NOTE_F4,16, //6
  NOTE_D4,-1, //7 and 8
  NOTE_F4,-4, NOTE_AS3,-4,
  NOTE_DS4,16, NOTE_D4,16, NOTE_F4,4, NOTE_AS3,-4,
  NOTE_DS4,16, NOTE_D4,16, NOTE_C4,-1, //11 and 12

  //repeats from 5
  NOTE_G4,-4, NOTE_C4,-4,//5

  NOTE_DS4,16, NOTE_F4,16, NOTE_G4,4, NOTE_C4,4, NOTE_DS4,16, NOTE_F4,16, //6
  NOTE_D4,-1, //7 and 8
  NOTE_F4,-4, NOTE_AS3,-4,
  NOTE_DS4,16, NOTE_D4,16, NOTE_F4,4, NOTE_AS3,-4,
  NOTE_DS4,16, NOTE_D4,16, NOTE_C4,-1, //11 and 12
  NOTE_G4,-4, NOTE_C4,-4,
  NOTE_DS4,16, NOTE_F4,16, NOTE_G4,4,  NOTE_C4,4, NOTE_DS4,16, NOTE_F4,16,

  NOTE_D4,-2,//15
  NOTE_F4,-4, NOTE_AS3,-4,
  NOTE_D4,-8, NOTE_DS4,-8, NOTE_D4,-8, NOTE_AS3,-8,
  NOTE_C4,-1,
  NOTE_C5,-2,
  NOTE_AS4,-2,
  NOTE_C4,-2,
  NOTE_G4,-2,
  NOTE_DS4,-2,
  NOTE_DS4,-4, NOTE_F4,-4, 
  NOTE_G4,-1,
  
  NOTE_C5,-2,//28
  NOTE_AS4,-2,
  NOTE_C4,-2,
  NOTE_G4,-2, 
  NOTE_DS4,-2,
  NOTE_DS4,-4, NOTE_D4,-4,
  NOTE_C5,8, NOTE_G4,8, NOTE_GS4,16, NOTE_AS4,16, NOTE_C5,8, NOTE_G4,8, NOTE_GS4,16, NOTE_AS4,16,
  NOTE_C5,8, NOTE_G4,8, NOTE_GS4,16, NOTE_AS4,16, NOTE_C5,8, NOTE_G4,8, NOTE_GS4,16, NOTE_AS4,16,
  
  REST,4, NOTE_GS5,16, NOTE_AS5,16, NOTE_C6,8, NOTE_G5,8, NOTE_GS5,16, NOTE_AS5,16,
  NOTE_C6,8, NOTE_G5,16, NOTE_GS5,16, NOTE_AS5,16, NOTE_C6,8, NOTE_G5,8, NOTE_GS5,16, NOTE_AS5,16,  
};

const int TONE_PWM_CHANNEL = 0;

// Define Firebase Data Object
FirebaseData firebaseData;

// Root Path para Leds
String pathDB = "/ledStatus";

// Root Path para Sensor de Temperatura
//String path2 = "/sensorTH";

// Variables to save database paths
String tempPath = "/vTemp";
String humPath = "/vHum";

// Timer variables (send new readings every three minutes)
unsigned long sendDataPrevMillis = 0;
unsigned long timerDelay = 180000;

const int TONE_OUTPUT_PIN = 13;

// Play each note for 500 ms
const int PLAY_NOTE_DURATION_MS = 500;

// The ESP32 has a 12-bit ADC, so our max analog value is 4095
const int MAX_ANALOG_VAL = 4095;

// Create our Tone32 object
Tone32 _tone32(TONE_OUTPUT_PIN, TONE_PWM_CHANNEL);

int notes1 = sizeof(melody1) / sizeof(melody1[0]) / 2;

// this calculates the duration of a whole note in ms (60s/tempo)*4 beats
int wholenote = (60000 * 4) / tempo;

int divider = 0, noteDuration = 0;


void setup()
{

    Serial.begin(115200);
    dht.begin();
   pinMode(button1.PIN, INPUT_PULLUP);
    attachInterrupt(button1.PIN, isr, FALLING);
    
  
    // pinMode(ledPin, OUTPUT);
    //  Set outputs to LOW
    // digitalWrite(ledPin, LOW);

    // ledcAttachPin(uint8_t pin, uint8_t channel);
    // ledcAttachPin(ledPin, TONE_PWM_CHANNEL);

    Serial.print("Connecting to ");
    Serial.println(WIFI_SSID);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(5000);
        Serial.print(".");
    }
    // Print local IP address and start web server
    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
    Firebase.reconnectWiFi(true);

    // Set database read timeout to 1 minute (max 15 minutes)
    Firebase.setReadTimeout(firebaseData, 1000 * 60);
    // tiny, small, medium, large and unlimited.
    // Size and its write timeout e.g. tiny (1s), small (10s), medium (30s) and large (60s).
    Firebase.setwriteSizeLimit(firebaseData, "tiny");
}


void sendFloat(String path, float value){
  if (Firebase.setFloat(firebaseData, "/sensorTH" + path, value)) {
    Serial.println("PASSED");
        Serial.println("PATH: " + firebaseData.dataPath());
        Serial.println("TYPE: " + firebaseData.dataType());
        Serial.println("ETag: " + firebaseData.ETag());
        Serial.print("VALUE: ");
        //    printResult(firebaseData);
        Serial.println("------------------------------------");
        Serial.println();
  }
  else {
    Serial.println("FAILED");
    Serial.println("REASON: " + firebaseData.errorReason());
    Serial.println("------------------------------------PATH" + path);
    Serial.println();
  }
}


//Segunda Opcion por si falla por las librerias
/* void sendFloat(String path, float value){
  if (Firebase.RTDB.setFloat(firebaseData, "/sensorTH" + path, value)) {
    Serial.println("PASSED");
        Serial.println("PATH: " + firebaseData.dataPath());
        Serial.println("TYPE: " + firebaseData.dataType());
        Serial.println("ETag: " + firebaseData.ETag());
        Serial.print("VALUE: ");
        //    printResult(firebaseData);
        Serial.println("------------------------------------");
        Serial.println();
  }
  else {
    Serial.println("FAILED");
    Serial.println("REASON: " + fbdo.errorReason());
  }
} */


void loop()
{
  
  //Para mandar la señaal a firebase y prender el LED
    if (Firebase.getDouble(firebaseData, pathDB + "/ledOn"))
    {
        Serial.println("PASSED");
        Serial.println("PATH: " + firebaseData.dataPath());
        Serial.println("TYPE: " + firebaseData.dataType());
        Serial.println("ETag: " + firebaseData.ETag());
        Serial.print("VALUE: ");
        // printResult(firebaseData);
        Serial.println("------------------------------------");
        Serial.println();

        if (firebaseData.intData() == 1)
        {
            for (int thisNote = 0; thisNote < notes1 * 2; thisNote = thisNote + 2)
            {
              Serial.println("dentro de cancion");

                // calculates the duration of each note
                divider = melody1[thisNote + 1];
                if (divider > 0)
                {
                    // regular note, just proceed
                    noteDuration = (wholenote) / divider;
                }
                else if (divider < 0)
                {
                    // dotted notes are represented with negative durations!!
                    noteDuration = (wholenote) / abs(divider);
                    noteDuration *= 1.5; // increases the duration in half for dotted notes
                }

                // we only play the note for 90% of the duration, leaving 10% as a pause
                // tone(buzzer, melody[thisNote], noteDuration*0.9);
                _tone32.playTone(melody1[thisNote], noteDuration * 0.9);
                // Wait for the specief duration before playing the next note.
                _tone32.update();
                delay(noteDuration);
            }
            _tone32.stopPlaying(); // stop playing
            // stop the waveform generation before the next note.

            // ledcWriteTone(TONE_PWM_CHANNEL, 800);

            Serial.println("led on");
        }

        else
        {
            Serial.println("led off");
        }
    }
  
  
  //Para mandar la señal a firebase y apagar el LED
    if (Firebase.getDouble(firebaseData, pathDB + "/ledOff"))
    {
        Serial.println("PASSED");
        Serial.println("PATH: " + firebaseData.dataPath());
        Serial.println("TYPE: " + firebaseData.dataType());
        Serial.println("ETag: " + firebaseData.ETag());
        Serial.print("VALUE: ");
        //    printResult(firebaseData);
        Serial.println("------------------------------------");
        Serial.println();

        if (firebaseData.intData() == 1)
        {
            //_tone32.stopPlaying(); // stop playing
            //DigitalWrite(ledPin, LOW);
            Serial.println("led off");
            
        }
        else
        {
            Serial.println("led on");
        }
    }else{
        Serial.println("FAILED");
        Serial.println("REASON: " + firebaseData.errorReason());
        Serial.println("------------------------------------PATH" + pathDB);
        Serial.println();
    }


  //Para mandar a firebase la temperatura y la humedad
//  if (Firebase.ready() && (millis() - sendDataPrevMillis > timerDelay || sendDataPrevMillis == 0)){
//    sendDataPrevMillis = millis();

  // Get latest sensor readings
  float h = dht.readHumidity();
  float t = dht.readTemperature();
    
  // Check if any reads failed and exit early (to try again).
    if (isnan(h) || isnan(t)) {
  Serial.println("Failed to read from DHT sensor!");
  return;
    }

    // Send readings to database:
    sendFloat(tempPath, t);
    sendFloat(humPath, h);

    // print the result to Terminal
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C ");
  
  //we delay a little bit for next read
  delay(2000);

  //}
  
    //Inicio de correo 
     if (button1.pressed) {
        Serial.printf("Button has been pressed %u times\n", button1.numberKeyPresses);
        button1.pressed = false;
         /* Connect to server with the session config */
    /** Enable the debug via Serial port
   * none debug or 0
   * basic debug or 1
  */
  smtp.debug(1);

  /* Set the callback function to get the sending results */
  smtp.callback(smtpCallback);

  /* Declare the session config data */
  ESP_Mail_Session session;

  /* Set the session config */
  session.server.host_name = SMTP_HOST;
  session.server.port = SMTP_PORT;
  session.login.email = AUTHOR_EMAIL;
  session.login.password = AUTHOR_PASSWORD;
  session.login.user_domain = "mydomain.net";

  /* Declare the message class */
  SMTP_Message message;

  /* Enable the chunked data transfer with pipelining for large message if server supported */
  message.enable.chunking = true;

  /* Set the message headers */
  message.sender.name = "ESP Mail";
  message.sender.email = AUTHOR_EMAIL;

  message.subject = "AYUDAAAAAAAAAAAAAAA!!!!!!!!!!!";
  message.addRecipient("Sara", RECIPIENT_EMAIL);

  /** Two alternative content versions are sending in this example e.g. plain text and html */
  String htmlMsg = "Estoy en problemas llama a emergencia.";
  message.html.content = htmlMsg.c_str();
  message.html.charSet = "utf-8";
  message.html.transfer_encoding = Content_Transfer_Encoding::enc_qp;

  message.priority = esp_mail_smtp_priority::esp_mail_smtp_priority_normal;
  message.response.notify = esp_mail_smtp_notify_success | esp_mail_smtp_notify_failure | esp_mail_smtp_notify_delay;

  /* The attachment data item */
  SMTP_Attachment att;

  /** Set the attachment info e.g. 
   * file name, MIME type, file path, file storage type,
   * transfer encoding and content encoding
  */
  //att.descr.filename = "image.png";
  //att.descr.mime = "image/png"; //binary data
  //att.file.path = "/image.png";
  //att.file.storage_type = esp_mail_file_storage_type_flash;
  //att.descr.transfer_encoding = Content_Transfer_Encoding::enc_base64;

  /* Add attachment to the message 
  message.addAttachment(att);

 att.descr.filename = "text_file.txt";
  att.descr.mime = "text/plain";
  att.file.path = "/text_file.txt"; message.resetAttachItem(att);
  
  att.file.storage_type = esp_mail_file_storage_type_flash;
  att.descr.transfer_encoding = Content_Transfer_Encoding::enc_base64;
*/
  /* Add attachment to the message */
//message.addAttachment(att);
if (!smtp.connect(&session))
    return;

 

  /* Start sending the Email and close the session */
  if (!MailClient.sendMail(&smtp, &message, true))
    Serial.println("Error sending Email, " + smtp.errorReason());
    }
    
    //Fin correo
}


void printResult(FirebaseData &data)
{

    if (data.dataType() == "int")
        Serial.println(data.intData());
    else if (data.dataType() == "float")
        Serial.println(data.floatData(), 5);
    else if (data.dataType() == "double")
        printf("%.9lf\n", data.doubleData());
    else if (data.dataType() == "boolean")
        Serial.println(data.boolData() == 1 ? "true" : "false");
    else if (data.dataType() == "string")
        Serial.println(data.stringData());
    else if (data.dataType() == "json")
    {
        Serial.println();
        FirebaseJson &json = data.jsonObject();
        // Print all object data
        Serial.println("Pretty printed JSON data:");
        String jsonStr;
        json.toString(jsonStr, true);
        Serial.println(jsonStr);
        Serial.println();
        Serial.println("Iterate JSON data:");
        Serial.println();
        size_t len = json.iteratorBegin();
        String key, value = "";
        int type = 0;
        for (size_t i = 0; i < len; i++)
        {
            json.iteratorGet(i, type, key, value);
            Serial.print(i);
            Serial.print(", ");
            Serial.print("Type: ");
            Serial.print(type == FirebaseJson::JSON_OBJECT ? "object" : "array");
            if (type == FirebaseJson::JSON_OBJECT)
            {
                Serial.print(", Key: ");
                Serial.print(key);
            }
            Serial.print(", Value: ");
            Serial.println(value);
        }
        json.iteratorEnd();
    }
    else
    {
        Serial.println(data.payload());
    }

  
}

/* Callback function to get the Email sending status */
void smtpCallback(SMTP_Status status){
  /* Print the current status */
  Serial.println(status.info());

  /* Print the sending result */
  if (status.success()){
    Serial.println("----------------");
    ESP_MAIL_PRINTF("Message sent success: %d\n", status.completedCount());
    ESP_MAIL_PRINTF("Message sent failled: %d\n", status.failedCount());
    Serial.println("----------------\n");
    struct tm dt;

    for (size_t i = 0; i < smtp.sendingResult.size(); i++){
      /* Get the result item */
      SMTP_Result result = smtp.sendingResult.getItem(i);
      time_t ts = (time_t)result.timestamp;
      localtime_r(&ts, &dt);

      ESP_MAIL_PRINTF("Message No: %d\n", i + 1);
      ESP_MAIL_PRINTF("Status: %s\n", result.completed ? "success" : "failed");
      ESP_MAIL_PRINTF("Date/Time: %d/%d/%d %d:%d:%d\n", dt.tm_year + 1900, dt.tm_mon + 1, dt.tm_mday, dt.tm_hour, dt.tm_min, dt.tm_sec);
      ESP_MAIL_PRINTF("Recipient: %s\n", result.recipients);
      ESP_MAIL_PRINTF("Subject: %s\n", result.subject);
    }
    Serial.println("----------------\n");
  }
}

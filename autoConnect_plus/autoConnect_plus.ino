#include <WiFi.h> // Replace with WiFi.h for ESP32
#include <WebServer.h>
#include <AutoConnect.h>

WebServer Server;
AutoConnect Portal(Server);

// Assign input variables to GPIO pins
//const int analogPin1 = 34;
// const int analogPin2 = 35;
// const int analogPin3 = 32;
// const int analogPin4 = 33;

// Asign integer variables for ADC pin reading
//int valuePin1;

// Asign float variables for ADC value conversion
//float analogValue1;
/*
// Set your Static IP address
IPAddress local_IP(192, 168, 18, 132);
// Set your Gateway IP address
IPAddress gateway(192, 168, 18, 148);

IPAddress subnet(255, 255, 0, 0);
*/
void rootPage() {
  //readData();
  Server.send(200, "text/html", SendHTML());
}

void setup() {
  delay(1000);
  Serial.begin(115200);
  Serial.println();

  Server.on("/", rootPage);
  if (Portal.begin()) {
    Serial.println("WiFi connected: " + WiFi.localIP().toString());    
  }
}

void loop() {
  Portal.handleClient();
  Portal.handleRequest();
}

/*
void readData(){
  valuePin1 = analogRead(analogPin1);
  analogValue1 = (float) valuePin1 / 4096 *3.3;
}
*/
String SendHTML(void){
  String ptr = "<!DOCTYPE html><html>\n";
  ptr += "<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"><meta http-equiv=\"refresh\" content=\"2\"\n";
  
  // CSS to style
  ptr += "<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; background-color: black; color: white}\n";
  ptr += "h1 { text-align: center}\n";
  ptr += "th { text-align: left}\n";
  ptr += "td { padding: 10px}\n";
  ptr += ".noBat { color: #FF0000}\n";
  ptr += ".charging { color: #FFFF00}\n";
  ptr += ".full { color: #00FF00}\n";
  ptr += "</style></head>\n";
                
  // Web Page Heading
  ptr += "<body><h1>Status <i>Charging Station</i></h1>\n";
  ptr += "<table><tr><th>Baris Pertama</th>\n";
  
  //if (analogValue1 > 2.2) {
    ptr += "<td> <span class= \"charging\">Status: Mengisi daya</span></td>\n";
  //}
  //else if (analogValue1 > 1.1) {
    ptr += "<td> <span class= \"full\">Status: Penuh</span></td>\n";
  //}
  //else {
    ptr += "<td> <span class= \"noBat\">Status: Tidak ada baterai</span></td>\n";
  //}
  
  ptr += "</tr>\n";
  
  ptr += "</table></body></html>\n";

  return ptr;
}

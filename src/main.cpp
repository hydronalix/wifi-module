


#include <SPI.h>
#include <WiFiNINA.h>



char ssid[] = "WifiCharlie"; 
char pass[] = "SawConvention2023"; 
int keyIndex = 0;            

int status = WL_IDLE_STATUS;

WiFiServer server(80);


void printWiFiStatus();
void voltageRead(int sensorPin,WiFiClient client);

void setup() {
  Serial.begin(9600);

    while (!Serial) {

    ; // wait for serial port to connect. Needed for native USB port only

  }
  Serial.println("Access Point Web Server");


  if (WiFi.status() == WL_NO_MODULE) {

    Serial.println("Communication with WiFi module failed!");

    // don't continue

    while (true);

  }

  String fv = WiFi.firmwareVersion();

  if (fv < WIFI_FIRMWARE_LATEST_VERSION) {

    Serial.println("Please upgrade the firmware");

  }

  // by default the local IP address of will be 192.168.4.1

  // you can override it with the following:

  // WiFi.config(IPAddress(10, 0, 0, 1));

  // print the network name (SSID);

  Serial.print("Creating access point named: ");

  Serial.println(ssid);

  // Create open network. Change this line if you want to create an WEP network:

  status = WiFi.beginAP(ssid, pass);

  if (status != WL_AP_LISTENING) {

    Serial.println("Creating access point failed");

    // don't continue

    while (true);

  }

  // wait 10 seconds for connection:

  delay(10000);

  // start the web server on port 80

  server.begin();

  printWiFiStatus();

}

void loop() {
  
  if (status != WiFi.status()) {

    // it has changed update the variable

    status = WiFi.status();

    if (status == WL_AP_CONNECTED) {

      // a device has connected to the AP

      Serial.println("Device connected to AP");

    } else {

      // a device has disconnected from the AP, and we are back in listening mode

      Serial.println("Device disconnected from AP");

    }

  }

  WiFiClient client = server.available();
  if (client) {
    
      WiFiClient client = server.available();
      String currentLine = "";

      while (client.connected()){
        if (client.available()){

          char c = client.read();             // read a byte, then

          Serial.write(c); 

          if ( c == '\n'){
            
          // if the current line is blank, you got two newline characters in a row.

          // that's the end of the client HTTP request, so send a response:

            if (currentLine.length() == 0){
              // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
  
              // and a content-type so the client knows what's coming, then a blank line:
              //Header:
              client.println("HTTP/1.1 200 OK");
  
              client.println("Content-type:text/html");
  
              client.println();
  
              //Content:
                //anything to be printed to the console goes here
               for (int analogChannel = 0; analogChannel < 6; analogChannel++) {
                  int sensorReading = analogRead(analogChannel);
                  client.print("analog input ");
                  client.print(analogChannel);
                  client.print(" is ");
                  client.print(sensorReading);
                  client.println("<br />");
                }
              client.println("</html>");
              break;
            }
            else {
              currentLine = "";
            }
          
          }
          else if (c != '\r') {    // if you got anything else but a carriage return character,

          currentLine += c;      // add it to the end of the currentLine

        }

          
        }
      }
      client.stop();

      Serial.println("client disconnected");
  }
}


void printWiFiStatus() {

  // print the SSID of the network you're attached to:

  Serial.print("SSID: ");

  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:

  IPAddress ip = WiFi.localIP();

  Serial.print("IP Address: ");

  Serial.println(ip);

  // print where to go in a browser:

  Serial.print("To see this page in action, open a browser to http://");

  Serial.println(ip);

}










#define ENA   14          // ENAble/speedcar motors Right        GPIO14(D5)
#define ENB   12          // ENAble/speedcar motors Left         GPIO12(D6)
#define IN_1  15          // L298N IN_1 motors Right           GPIO15(D8)
#define IN_2  13          // L298N IN_2 motors Right           GPIO13(D7)
#define IN_3  2           // L298N IN_3 motors Left            GPIO2(D4)
#define IN_4  0           // L298N IN_4 motors Left            GPIO0(D3)

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

String command;             // String to store app command state.
int speedcarCar = 1000;         // 400 - 1023.
int speedcar_Coeff = 3;

// Set your custom SSID and password here
const char* ssid = "Humobot";  // Your custom SSID
const char* password = "Humobot1234";  // Your custom password

ESP8266WebServer server(80);

void setup() {
  // Set motor control pins as OUTPUT
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);  
  pinMode(IN_1, OUTPUT);
  pinMode(IN_2, OUTPUT);
  pinMode(IN_3, OUTPUT);
  pinMode(IN_4, OUTPUT); 
  
  Serial.begin(9600);
  
  // Connect to WiFi Access Point
  WiFi.mode(WIFI_AP);  // Set the ESP8266 as an Access Point
  WiFi.softAP(ssid, password);  // Start the Access Point with SSID and password
  
  IPAddress myIP = WiFi.softAPIP();  // Get the IP address of the Access Point
  Serial.print("AP IP address: ");
  Serial.println(myIP);
 
  // Starting WEB-server
  server.on("/", HTTP_handleRoot);
  server.onNotFound(HTTP_handleRoot);
  server.begin();    
}

void goAhead() { 
  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, HIGH);
  analogWrite(ENA, speedcarCar);

  digitalWrite(IN_3, LOW);
  digitalWrite(IN_4, HIGH);
  analogWrite(ENB, speedcarCar);
}

void goBack() { 
  digitalWrite(IN_1, HIGH);
  digitalWrite(IN_2, LOW);
  analogWrite(ENA, speedcarCar);

  digitalWrite(IN_3, HIGH);
  digitalWrite(IN_4, LOW);
  analogWrite(ENB, speedcarCar);
}

void goRight() { 
  digitalWrite(IN_1, HIGH);
  digitalWrite(IN_2, LOW);
  analogWrite(ENA, speedcarCar);

  digitalWrite(IN_3, LOW);
  digitalWrite(IN_4, HIGH);
  analogWrite(ENB, speedcarCar);
}

void goLeft() {
  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, HIGH);
  analogWrite(ENA, speedcarCar);

  digitalWrite(IN_3, HIGH);
  digitalWrite(IN_4, LOW);
  analogWrite(ENB, speedcarCar);
}

void stopRobot() {  
  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, LOW);
  analogWrite(ENA, 0);  // Stop motor by setting PWM to 0

  digitalWrite(IN_3, LOW);
  digitalWrite(IN_4, LOW);
  analogWrite(ENB, 0);  // Stop motor by setting PWM to 0
}




void loop() {
  server.handleClient();
  
  command = server.arg("State");
  if (command == "F") goAhead();
  else if (command == "B") goBack();
  else if (command == "L") goLeft();
  else if (command == "R") goRight();
  else if (command == "S") stopRobot();


  // speedcar control logic


  if (command == "0") speedcarCar = 400;
  else if (command == "1") speedcarCar = 470;
  else if (command == "2") speedcarCar = 540;
  else if (command == "3") speedcarCar = 610;
  else if (command == "4") speedcarCar = 680;
  else if (command == "5") speedcarCar = 750;
  else if (command == "6") speedcarCar = 800;
  else if (command == "7") speedcarCar = 890;
  else if (command == "8") speedcarCar = 960;
  else if (command == "9") speedcarCar = 1023;
}

void HTTP_handleRoot(void) {
  String html = "<html><body>";
  html += "<h1>Control Your Car</h1>";

  // Control Buttons for movement
  html += "<button onclick=\"location.href='/State=F'\">Forward</button><br><br>";
  html += "<button onclick=\"location.href='/State=B'\">Backward</button><br><br>";
  html += "<button onclick=\"location.href='/State=L'\">Left</button><br><br>";
  html += "<button onclick=\"location.href='/State=R'\">Right</button><br><br>";
  html += "<button onclick=\"location.href='/State=S'\">Stop</button><br><br>";

  // speedcar control
  html += "<h3>speedcar Control:</h3>";
  for (int i = 0; i <= 9; i++) {
    html += "<button onclick=\"location.href='/State=" + String(i) + "'\">" + String(i) + "</button>";
  }

  html += "</body></html>";
  
  // Send the HTML content to the client
  server.send(200, "text/html", html);
}

/////////////////////////////////
// Generated with a lot of love//
// with TUNIOT FOR ESP8266     //
// Website: Easycoding.tn      //
/////////////////////////////////
#include <ESP8266WiFi.h>

String  i;
WiFiServer server(80);

void setup()
{
i = "";
Serial.begin(9600);
pinMode(4, OUTPUT);
  WiFi.disconnect();
  delay(3000);
   WiFi.begin("Realme 2 Pro","realme2pro123");
  Serial.println("Connecting to WiFi");
  while ((!(WiFi.status() == WL_CONNECTED)))
  {
    delay(300);
    Serial.print(".");
  }
  Serial.println("Wifi is Connected");
  Serial.println((WiFi.localIP().toString()));
  server.begin();

}


void loop()
{
    
    WiFiClient client = server.available();
    if (!client) { return; }
    while(!client.available()){  delay(1); }
    i = (client.readStringUntil('\r'));
    //Serial.println(i);
    i.remove(0, 5);
    i.remove(i.length()-9,9);
    //Serial.println(i);
    if (i == "ON") {
      //Serial.println("Turning ON");
      digitalWrite(4,HIGH);
      Serial.println("ON instruction is send");
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("LED IS TURNED ON");
      client.println("</html>");
      delay(1);
      }
    if (i == "OFF") {
      //Serial.println("Turning Off");
      digitalWrite(4,LOW);
      Serial.println("Off instruction is send");
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("LED IS TURNED OFF");
      client.println("</html>");
      delay(1);
    }
}

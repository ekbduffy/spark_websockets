#include "Spark-Websockets/Spark-Websockets.h"


WebSocketClient client;


void onMessage(WebSocketClient client, char* message) {
  Serial.print("Received: ");
  Serial.println(message);
}


/* This function is called once at start up ----------------------------------*/
void setup()
{
	Serial.begin(9600);
	while(!Serial.available()); // Wait here until the user presses ENTER in the Serial Terminal
	
	client.onMessage(onMessage);
	client.connect("echo.websocket.org");
}

void loop()
{
  client.monitor();
	delay(3000);
	client.send("Hello World!");
}

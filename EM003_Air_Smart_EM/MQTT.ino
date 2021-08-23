void connect_server() {
  const char* broker = "111.68.96.113";
  client.setServer(broker, 1883);
  client.setCallback(callback);

  if (!client.connected()) {
    delay(100);
    Serial.print("\nConnected to ");
    TelnetStream.print("\nConnected to ");
    Serial.print(broker);
    TelnetStream.println(broker);
    if (client.connect("koikoikoi", brokerUser, brokerPass)) {
      Serial.print("\nConnected to ");
      Serial.print(broker);
      client.subscribe(inTopic);
      BSent = true;
    }
    else {
      Serial.print("\nTrying connect again");
      BSent = false;
      delay(5000);
    }
  }
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Recieved messages: ");
  Serial.println(topic);
  TelnetStream.println("Recieved messages: ");
  TelnetStream.println(topic);
  for (int i = 0; i < length; i++) {
    timeStamp = timeStamp + ((char) payload[i]);
  }
  Serial.print("Time Stamp : ");
  Serial.println(timeStamp);
}

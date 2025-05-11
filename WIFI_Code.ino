//=================================================Methods to get data from EEPROM========================================//
String getServerPass()
{
  String data;
  for (int i = 10; i < 20; i++)
    data += (char)EEPROM.read(i);
  data.trim();
  return data;
}

//============================================WiFi Congifuration Methods=======================================//
void configWifi()
{
  //Setting wifi SSID
  String S = "Smart-Glasses";
  String P = "12345678";
  char tempS[S.length() + 1];
  S.toCharArray(tempS, sizeof(tempS));
  char tempP[P.length() + 1];
  P.toCharArray(tempP, sizeof(tempP));
  WiFi.softAP(tempS, tempP, 1, 0, 1);

  server.on("/notification", HTTP_POST, notification);
  server.on("/cServerPass", HTTP_POST, changeServerPass);

  server.begin();
}

//===================================Method to get Json request data==================================//

bool getJsonData()
{
  requestData = server.arg("plain");
  //Making buffer to store json request data
  //  StaticJsonDocument<300> doc;
  DynamicJsonDocument doc(600);
  // Deserialize the JSON document
  DeserializationError error = deserializeJson(doc, requestData);
  // Test if parsing succeeds.
  if (error)
  {
    server.send(400, dataType, "Bad request");
    return false;
  }
  // Get the root object in the document
  root = doc.as<JsonObject>();
  return true;
}

//===================================API Methods==================================//

void changeServerPass()
{
  if (!getJsonData())
    return;

  String pass = root["Pass"];
  pass.trim();

  if (pass == "" | pass == "null" | pass.length() < 8 | pass.length() > 10)
  {
    server.send(200, dataType, "Password is either too short or too long");
    return;
  }

  for (int i = 10; i < 20; i++)
  {
    if (pass.length() > i - 9 || pass.length() == i - 9)
      EEPROM.write(i, pass[i - 10]);
    else
      EEPROM.write(i, 32);
  }
  EEPROM.commit();
  server.send(200, dataType, "OK");
  delay(100);
  ESP.restart();
}

void notification()
{
  if (!getJsonData())
    return;

  String d = root["data"];

  //Converting string message to char array because "strtok" method didn't accept String
  char line[d.length()];
  d.toCharArray(line, sizeof(line));
  //Spliting operation
  type = (String)strtok(line, ",");
  data = (String)strtok(NULL, ",");

  server.send(200, dataType, "OK");
}

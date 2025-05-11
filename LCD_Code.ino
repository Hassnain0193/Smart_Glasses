//Method to print splash screen
void splash()
{
  // display a line of text
  lcd.clearDisplay();
  lcd.setTextSize(2);
  lcd.setTextColor(WHITE);
  lcd.setCursor(38, 0);
  lcd.print("SMART");
  lcd.setTextSize(2);
  lcd.setCursor(25, 20);
  lcd.print("GLASSES");
  lcd.display();
  lcd.setTextSize(1);
  lcd.setCursor(45, 40);
  lcd.print("Ready...");
  lcd.display();
}

//Method to print calling
void printCalling()
{
  // display a line of text
  lcd.clearDisplay();
  lcd.setTextSize(2);
  lcd.setTextColor(WHITE);

  lcd.setCursor(x, 0);

  char message[data.length() + 1];
  data.toCharArray(message, sizeof(message));
  minX = -12 * strlen(message);

  lcd.print(message);
  lcd.setCursor(50, 20);
  lcd.print("IS");

  lcd.setCursor(0, 40);
  lcd.print("CALLING...");
  lcd.display();

  x = x - 4;
  if (x < minX) x = lcd.width();
}

//Method to print messages count
void printMsgCount()
{
  lcd.clearDisplay();
  lcd.setTextSize(2);
  lcd.setTextColor(WHITE);

  lcd.setCursor(50, 0);
  lcd.print(data);

  lcd.setCursor(28, 20);
  lcd.print("UNREAD");

  lcd.setCursor(15, 40);
  lcd.print("MESSAGES");

  lcd.display();
}

//Method to print Multimeter data
void printValue()
{
  lcd.clearDisplay();
  lcd.setTextSize(2);
  lcd.setTextColor(WHITE);

  lcd.setCursor(10, 0);
  lcd.print("Multimeter");

  lcd.setCursor(10, 20);
  lcd.print("Connected");

  lcd.setCursor(35, 40);
  lcd.print(mData);

  lcd.display();
}

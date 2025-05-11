void ReadMeter()
{
  if (Serial.available())
  {
    int x = Serial.read();
    y += String(x);
    y += ',';

    if (x == 25 || x == 99 || x == 75 || x == 74 || x == 163 || x == 225 || x == 32 || x == 145 || x == 209 || x == 154 || x == 218 || x == 217 || x == 227 || x == 226 || x == 162 || x == 98 || x == 97 || x == 96 || x == 89 || x == 35 || x == 34 || x == 33 || x == 55 || x == 167 || x == 231 || x == 39 || x == 47 || x == 208 || x == 144 || x == 153)
      count = 1;
    else
      count++;

    if (count > 6 || count == 6)
    {
      //      Converting string message to char array because "strtok" method didn't accept String
      char line[y.length()];
      y.toCharArray(line, sizeof(line));

      //Spliting operation
      //Getting identifier int
      int x = ((String)strtok(line, ",")).toInt();

      //Getting data
      for (int i = 1; i < 5; i++)
        mData = ((String)strtok(NULL, ",")).toInt();

      switch (x) {
        //============For Dc Volt===============
        case 35:
          //DC v 0.000
          mData = mData / 1000;
          printValue();
          break;
        case 34:
          //DC v 00.00
          mData = mData / 100;
          printValue();
          break;
        case 33:
          //DC v and ohm 000.0
          mData = mData / 10;
          printValue();
          break;
        case 32:
          //DC v and temperature 0000
          printValue();
          break;
        case 25:
          //DC mv 000.0
          mData = mData / 10;
          printValue();
          break;
        //============For Ac Volt===============
        case 99:
          //AC v 0.000
          mData = mData / 1000;
          printValue();
          break;
        case 98:
          //AC v 00.00
          mData = mData / 100;
          printValue();
          break;
        case 97:
          //AC v 000.0
          mData = mData / 10;
          printValue();
          break;
        case 96:
          //AC v 0000
          printValue();
          break;
        case 89:
          //AC mv 000.0
          mData = mData / 10;
          printValue();
          break;
        //============For Capacitance===============
        case 74:
          //Capacitance 00.00
          mData = mData / 100;
          printValue();
          break;
        //============For Hz===============
        case 163:
          //Hz and DC m amp 0.000
          mData = mData / 1000;
          printValue();
          break;
        //============For %===============
        case 225:
          //% 000.0
          printValue();
          break;
        //============For DC u amp===============
        case 145:
          //DC u amp 000.0
          mData = mData / 10;
          printValue();
          break;
        case 144:
          //DC u amp 0000
          printValue();
          break;
        //============For AC u amp===============
        case 209:
          //AC u amp 000.0
          printValue();
          mData = mData / 10;
          break;
        case 208:
          //AC u amp 000.0
          printValue();
          break;
        //============For DC m amp===============
        case 154:
          //DC m amp 00.00
          mData = mData / 100;
          printValue();
          break;
        case 153:
          //DC m amp 000.0
          mData = mData / 10;
          printValue();
          break;
        //============For AC m amp===============
        case 218:
          //AC m amp 00.00
          mData = mData / 100;
          printValue();
          break;
        case 217:
          //AC m amp 000.0
          mData = mData / 100;
          printValue();
          break;
        //============For DC amp===============
        case 162:
          //DC m amp 00.00
          mData = mData / 100;
          printValue();
          break;
        //============For AC amp===============
        case 227:
          //AC m amp 0.000
          mData = mData / 1000;
          printValue();
          break;
        case 226:
          //DC m amp 00.00
          mData = mData / 100;
          printValue();
          break;
      }
      y = "";
    }
  }
  else
  {
    elapsedMillis timeElapsed;
    unsigned int interval = 6000;
    while (timeElapsed < interval)
    {
      if (Serial.available())
        break;
    }
    if (timeElapsed > interval || timeElapsed == interval)
      splash();
  }
}

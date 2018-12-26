int unit = 50;
int messageNotSent = 1;
int incomingByte = 0;
String Str = "";

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
}

void loop() {
  if (Serial.available() > 0){
     Str = Serial.readString();
     delay(6000);
     String ditDah = "";
      if (messageNotSent == 1){
      for (int a = 0; a < Str.length(); a++){
        if (Str[a] != ' ' && Str[a] != '.'){
          String morseTranslation = translateToMorse(Str[a]);
          ditDah += morseTranslation;
        }
        else if (Str[a] == ' ')
          ditDah += "_";
        else if (Str[a] == '.')
          ditDah += ".";
      }
      Serial.println(ditDah);
      lightShow(ditDah);
      messageNotSent = 0;
    }
  }
  delay(1000);
}

void lightShow(String morse){
  for (int a = 0; a < morse.length(); a++){
    Serial.print(morse[a]);
    if (morse[a] == '0'){
      digitalWrite(2, HIGH);
      delay(unit);
      digitalWrite(2, LOW);
      delay(unit);
    }
    else if (morse[a] == '1') {
      digitalWrite(2, HIGH);
      delay(3*unit);
      digitalWrite(2, LOW);
      delay(unit);
    }
    else if (morse[a] == ' ')
      delay(2*unit);
    else if (morse[a] == '_')
      delay(5*unit);
    else if (morse[a] == '.')
      delay(19 * unit);
  }
}

String translateToMorse(char letter){
  switch(letter){
   case 'A' : return " 01";
   case 'B' : return " 1000";
   case 'C' : return " 1010";
   case 'D' : return " 100";
   case 'E' : return " 0";
   case 'F' : return " 0010";
   case 'G' : return " 110";
   case 'H' : return " 0000";
   case 'I' : return " 00";
   case 'J' : return " 0111";
   case 'K' : return " 101";
   case 'L' : return " 0100";
   case 'M' : return " 11";
   case 'N' : return " 10";
   case 'O' : return " 111";
   case 'P' : return " 0110";
   case 'Q' : return " 1101";
   case 'R' : return " 010";
   case 'S' : return " 000";
   case 'T' : return " 1";
   case 'U' : return " 001";
   case 'V' : return " 0001";
   case 'W' : return " 011";
   case 'X' : return " 1001";
   case 'Y' : return " 1011";
   case 'Z' : return " 1101";
  }
}

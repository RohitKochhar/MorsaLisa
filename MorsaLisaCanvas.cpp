const int photoResistor = A0;
const int threshold = 75;
String morseString = "";
int terminateCount = 0;
int isTerminated = 0;
String b2ms = "";
int unit = 50;
int first1 = 0;



void setup() {
  Serial.begin(9600);
}

void loop() {
  if (isTerminated == 0){
    if (analogRead(photoResistor) > threshold){
      if (first1 == 1)
        morseString += '0';
      Serial.print(0);
      terminateCount++;
      if (terminateCount == 20 && first1 == 1){
        Serial.println("String is terminated!");
        isTerminated = 1;
      }
    }
    else{
      morseString += '1';
      first1 = 1;
      Serial.print(1);
      terminateCount = 0;
    }
    delay(unit);
  if (isTerminated == 1)
    binToMorse(morseString);
  }
}

void binToMorse(String s){
  Serial.print("Parsing '");
  Serial.print(s);
  Serial.println("'");
  int z_count = 0;
  int o_count = 0;
  for (int a = 0; a < s.length(); a++){
    if (s[a] == '0'){
      z_count++;
      if (o_count == 3){
        b2ms += "-";
      }
      else if (o_count == 1){
        b2ms += ".";
      }
      o_count = 0;
    }
    else if (s[a] == '1'){
      o_count++;
      if (z_count == 3){
        b2ms += " ";
      }
      if (z_count == 8)
        b2ms += "_";
      else if (z_count == 1){
        b2ms += "";
      }
      z_count = 0;
    }
  }
  b2ms += "_";
  morseToEnglish(b2ms);
}

void morseToEnglish(String s){
  String morseLetter = "";
  String morseWord = "";
  String morseSentance = "";
  for (int a = 0; a <= s.length(); a++){
    if (s[a] != ' ' && s[a] != '_')
      morseLetter += s[a];
    else if (s[a] == ' '){
      morseSentance += getLetter(morseLetter);
      morseLetter = "";
    }
    else if (s[a] == '_'){
      morseSentance += getLetter(morseLetter);
      morseSentance += " ";
      morseLetter = "";
    }
    else {
      morseSentance += getLetter(morseLetter);
      morseSentance += ".";
      morseLetter = "";
    }
  }
  Serial.println("");
  Serial.print("Decoded message: ");
  Serial.println(morseSentance);
}
String getLetter(String m){
  Serial.print(m);
  Serial.print(" ");
   if (m == "  ") return "0";
   else if ( m == ".-"   ) return "A";
   else if ( m == "-..." ) return "B";
   else if ( m == "-.-." ) return "C";
   else if ( m == "-.."  ) return "D";
   else if ( m == "."    ) return "E";
   else if ( m == "..-." ) return "F";
   else if ( m == "--."  ) return "G";
   else if ( m == "...." ) return "H";
   else if ( m == ".."   ) return "I";
   else if ( m == ".---" ) return "J";
   else if ( m == "-.-"  ) return "K";
   else if ( m == ".-.." ) return "L";
   else if ( m == "--"   ) return "M";
   else if ( m == "-."   ) return "N";
   else if ( m == "---"  ) return "O";
   else if ( m == ".--." ) return "P";
   else if ( m == "--.-" ) return "Q";
   else if ( m == ".-."  ) return "R";
   else if ( m == "..."  ) return "S";
   else if ( m == "-"    ) return "T";
   else if ( m == "..-"  ) return "U";
   else if ( m == "...-" ) return "V";
   else if ( m == ".--"  ) return "W";
   else if ( m == "-..-" ) return "X";
   else if ( m == "-.--" ) return "Y";
   else if ( m == "--.-" ) return "Z";
}

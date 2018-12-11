int MAX = 1023;
int upper = MAX*0.8; //at least 80 % performance
int lower = MAX*0.3; //at most 30 % performance
int downs;
int ups;
int rep;
unsigned long previousMillis;

void setup() {
  Serial.begin(9600);
  downs = 0;
  ups = 0;
  previousMillis = 0;
  rep = 0;
}

void loop() {
  unsigned long currentMillis = millis(); //find current time
  int current = analogRead(A0); //find output of sEMG
  if(currentMillis - previousMillis >= 7000) {  
    previousMillis = currentMillis;
    rep = 2;
    Serial.println(rep);
  }   
  if(current >= upper) { // peaks
    ups++;     
  }else if(current <= lower) { // valleys
    downs++;    
    if(ups != 0) { 
      downs = 0; 
      ups = 0;
      previousMillis = currentMillis;
      rep = 1;
      Serial.println(rep);
    }
  }
  Serial.flush();
}

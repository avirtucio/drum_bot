// Hardware Pins
const int bassPin = 8;
const int snarePin = 9;
const int cymbalPin = 10;

// Pulse Length to Servo Angle Definitions
// const int pulseMin = 700; //microseconds, 0 degress
// const int pulseMax = 850; //microseconds, a little over 15 degrees
// const int pulseNeutral = 700;

// Groove Definitions
int verseBass[16] = {1,0,1,0, 0,0,0,0, 1,0,1,0, 0,0,0,0};
int verseSnare[16] = {0,0,0,0, 1,0,0,0, 0,0,0,0, 1,0,0,0};
int verseCymbal[16] = {1,0,1,0, 1,0,1,0, 1,0,1,0, 1,0,1,0};

int chorusBass[16] = {1,0,0,1, 0,0,0,0, 1,0,1,1, 0,0,1,0};
int chorusSnare[16] = {0,0,0,0, 1,0,0,1, 0,1,0,0, 1,0,0,0};
int chorusCymbal[16] = {1,0,0,0, 1,0,0,0, 1,0,0,0, 1,0,0,0};

int prechorusBass[16] = {1,0,1,0, 1,0,1,0, 1,0,0,1, 0,0,1,0};
int prechorusSnare[16] = {1,1,1,1, 1,1,1,1, 1,1,1,0, 1,0,0,0};
int prechorusCymbal[16] = {1,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};

int introBass[16] = {0,1,0,1, 0,1,0,1, 0,1,0,1, 0,0,1,0};
int introSnare[16] = {1,0,0,0, 1,0,0,0, 1,0,0,0, 1,0,0,0};
int introCymbal[16] = {0,0,1,0, 0,0,1,0, 0,0,1,0, 0,0,1,0};

// post intro same as postchorus4

int postchorus1Bass[16] = {1,0,1,0, 0,0,1,0, 0,0,1,0, 0,0,0,0};
int postchorus1Snare[16] = {0,0,0,0, 1,0,0,0, 1,0,0,0, 0,0,0,0};
int postchorus1Cymbal[16] = {1,0,0,0, 1,0,0,0, 1,0,0,0, 1,0,0,0};

int postchorus2Bass[16] = {1,0,1,0, 0,0,0,1, 0,1,0,1, 0,1,0,1};
int postchorus2Snare[16] = {0,0,0,0, 1,0,0,0, 1,0,0,0, 0,0,0,0};
int postchorus2Cymbal[16] = {1,0,0,0, 1,0,0,0, 0,0,1,0, 0,0,1,0};

int postchorus4Bass[16] = {1,0,1,0, 0,0,1,0, 1,0,0,0, 0,1,0,1};
int postchorus4Snare[16] = {0,0,0,0, 1,0,0,0, 1,0,1,1, 1,1,1,1};
int postchorus4Cymbal[16] = {1,0,0,0, 1,0,0,0, 1,0,0,0, 1,0,0,0};

int outroBass[16] = {1,0,0,1, 0,0,0,1, 0,1,0,1, 0,0,1,0};
int outroSnare[16] = {0,0,0,0, 1,0,0,0, 1,0,0,0, 1,0,0,0};
int outroCymbal[16] = {1,0,1,0, 1,0,1,0, 1,0,1,0, 1,0,0,0};

int countdownBass[16] = {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
int countdownSnare[16] = {1,0,0,0, 1,0,0,0, 1,0,0,0, 1,0,0,0};
int countdownCymbal[16] = {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};

int restBass[16] = {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
int restSnare[16] = {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
int restCymbal[16] = {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};

// Pointers to Current Song Groove
int* currentBassPattern = introBass; //set to intro but immediately changes to countdown when code starts
int* currentSnarePattern = introSnare; 
int* currentCymbalPattern = introCymbal;

// Timing
const int bpm = 300; //actual song is at 113, but the sticks are delayed or smtg and 300bpm works
const int stepTime = 60000 / bpm / 4; // milliseconds per 16th note but like not really

void setup() {
  pinMode(bassPin, OUTPUT);
  pinMode(snarePin, OUTPUT);
  pinMode(cymbalPin, OUTPUT);
}

void loop() {
  // 141 measures in song
  for (int measure=0; measure<142; measure++){
    if (measure==-0){
      currentBassPattern = countdownBass;
      currentSnarePattern = countdownSnare; 
      currentCymbalPattern = countdownCymbal;
    } else if (measure==1){
      currentBassPattern = restBass;
      currentSnarePattern = restSnare; 
      currentCymbalPattern = restCymbal;
    } else if (measure==4){
      currentBassPattern = introBass;
      currentSnarePattern = introSnare; 
      currentCymbalPattern = introCymbal;
    } else if (measure==5 || measure==33 || measure==69 || measure==85 || measure==121){
      currentBassPattern = chorusBass;
      currentSnarePattern = chorusSnare; 
      currentCymbalPattern = chorusCymbal;
    } else if (measure==12 || measure==48 || measure==84 || measure==100){
      currentBassPattern = postchorus4Bass;
      currentSnarePattern = postchorus4Snare; 
      currentCymbalPattern = postchorus4Cymbal;
    } else if (measure==13 || measure==49 || measure==101){
      currentBassPattern = verseBass;
      currentSnarePattern = verseSnare; 
      currentCymbalPattern = verseCymbal;
    } else if (measure==32 || measure==68 || measure==120){
      currentBassPattern = prechorusBass;
      currentSnarePattern = prechorusSnare; 
      currentCymbalPattern = prechorusCymbal;
    } else if (measure==45 || measure==47 || measure==81 || measure==83){
      currentBassPattern = postchorus1Bass;
      currentSnarePattern = postchorus1Snare; 
      currentCymbalPattern = postchorus1Cymbal;
    } else if (measure==46 || measure==82){
      currentBassPattern = postchorus2Bass;
      currentSnarePattern = postchorus2Snare; 
      currentCymbalPattern = postchorus2Cymbal;
    } else if (measure==133){
      currentBassPattern = outroBass;
      currentSnarePattern = outroSnare; 
      currentCymbalPattern = outroCymbal;
    }

    for (int step=0; step<16; step++){
      if (currentBassPattern[step]) {
      digitalWrite(bassPin, HIGH);
      }
      if (currentSnarePattern[step]) {
        digitalWrite(snarePin, HIGH);
      }
      if (currentCymbalPattern[step]) {
        digitalWrite(cymbalPin, HIGH);
      }

      // Hold the pulse for corresponding angle
      delayMicroseconds(850);  

      // Reset servos LOW at the same time
      digitalWrite(bassPin, LOW);
      digitalWrite(snarePin, LOW);
      digitalWrite(cymbalPin, LOW);
      
      delay(80); //wait for servos to actually move

      digitalWrite(bassPin, HIGH); //bring all of them back up all at the same time
      digitalWrite(snarePin, HIGH);
      digitalWrite(cymbalPin, HIGH);

      delayMicroseconds(700);

      digitalWrite(bassPin, LOW);
      digitalWrite(snarePin, LOW);
      digitalWrite(cymbalPin, LOW);
      
      delay(stepTime); // Wait for the rest of the beat
    }
  }

    // if (currentBassPattern[step]) hitDrum(bassPin);
    // if (currentSnarePattern[step]) hitDrum(snarePin);
    // if (currentCymbalPattern[step]) hitDrum(cymbalPin);
    // delay(stepTime);
  // digitalWrite(snarePin, HIGH);
  // delayMicroseconds(500); //turning servo for this long will turn it the corresponding amnt of degrees 500 - 1700 microseconds, 0-180 degrees
  // digitalWrite(snarePin, LOW);
  // delay(2000);
  // digitalWrite(snarePin, HIGH);
  // delayMicroseconds(1150); //turning servo for this long will turn it the corresponding amnt of degrees 500 - 1700 microseconds, 0-180 degrees
  // digitalWrite(snarePin, LOW);
  // delay(80);

}

// void hitDrum(int pin){
//   sendServoPulse(pin, pulseMax);
//   delay(80); //wait for servo to complete swing before actually telling it to move back

//   sendServoPulse(pin, pulseNeutral);
//   delay(20);
// }

// void sendServoPulse(int pin, int durationMicroseconds){
//   digitalWrite(pin, HIGH);
//   delayMicroseconds(durationMicroseconds); //turning servo for this long will turn it the corresponding amnt of degrees
//   digitalWrite(pin, LOW);
//   delay(20);
// }

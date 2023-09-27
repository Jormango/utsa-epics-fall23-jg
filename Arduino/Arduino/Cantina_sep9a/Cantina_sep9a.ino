/*INSTRUCTION: Hook up Pin 10 to the positive side of a buzzer or a microphone, hook up 
 any resistor to the negative side of a buzzer.
 
 */


const int buzzer = 13;

// Change to 0.5 for a slower version of the song, 1.25 for a faster version
const float songSpeed = 0.85;


#define NOTE_B4 493
#define NOTE_A4 440
#define NOTE_E5 659
#define NOTE_A5 466
#define NOTE_G5 415
#define NOTE_G4 390
#define NOTE_E4 330
#define NOTE_C5 523
#define NOTE_D5 587
#define NOTE_F5 689
#define NOTE_D4 294
#define NOTE_CS 277
#define NOTE_C4 262

int notes[] = {
 
  NOTE_B4, 0, NOTE_E5, 0, NOTE_B4, 0, NOTE_E5, 0,
  NOTE_B4, NOTE_E5, NOTE_B4, 0, NOTE_A5, NOTE_B4, 0,
  NOTE_B4, NOTE_A5, NOTE_B4, NOTE_A4, 0, NOTE_G5, NOTE_A4, NOTE_G4,
  NOTE_E4, 0,
 
  NOTE_B4, 0, NOTE_E5, 0, NOTE_B4, 0, NOTE_E5, 0,
  NOTE_B4, NOTE_E5, NOTE_B4, 0, NOTE_A5, NOTE_B4, 0,
  NOTE_A4, 0, NOTE_A4, NOTE_G5, NOTE_A4,
  NOTE_D5, NOTE_C5, NOTE_B4, NOTE_A4,
  
  NOTE_B4, 0, NOTE_E5, 0, NOTE_B4, 0, NOTE_E5, 0,
  NOTE_B4, NOTE_E5, NOTE_B4, 0, NOTE_A5, NOTE_B4, 0,
  NOTE_B4, NOTE_A5, NOTE_B4, NOTE_A4, 0, NOTE_G5, NOTE_A4, NOTE_G4,
  NOTE_E4, 0,
 
  NOTE_E4, NOTE_G4,
  NOTE_B4, NOTE_D5, 0,
  NOTE_F5, NOTE_E5, NOTE_A5, NOTE_B4, NOTE_G4, 0,
  
  0, NOTE_B4, NOTE_G4, NOTE_B4, 0, 0,
  0, NOTE_B4, NOTE_G4, NOTE_B4, 0, 0,
  0, NOTE_B4, NOTE_G4, NOTE_A5, NOTE_B4,
  NOTE_G4, NOTE_E4, 0,

  0, NOTE_B4, NOTE_G4, NOTE_B4, 0, 0,
  0, NOTE_B4, NOTE_G4, NOTE_B4, 0, 0,
  0, NOTE_B4, NOTE_G4, NOTE_A5, NOTE_B4,
  NOTE_A4, NOTE_D4, 0,

  0, NOTE_B4, NOTE_G4, NOTE_B4, 0, 0,
  0, NOTE_B4, NOTE_G4, NOTE_B4, 0, 0,
  0, NOTE_B4, NOTE_G4, NOTE_A5, NOTE_B4,
  NOTE_G4, NOTE_E4, 0,
  
  NOTE_C4, NOTE_E4, NOTE_G4, NOTE_CS, NOTE_E4, NOTE_G4,
  NOTE_A5, NOTE_B4, NOTE_E4,
  NOTE_E4, NOTE_G4, NOTE_C5, NOTE_E5, NOTE_A5, NOTE_B4,
  NOTE_G4, 0,
  
  NOTE_G4, 0, NOTE_A5, NOTE_G4, NOTE_A4,
  0, NOTE_G4, NOTE_A5, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_B4, NOTE_E4,
  NOTE_G4, 0, NOTE_A5, NOTE_G4, NOTE_A4,
  0, NOTE_G4, NOTE_A5, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_B4, NOTE_E4,
  NOTE_G4, 0, NOTE_A5, NOTE_G4, NOTE_A4,
  0, NOTE_G4, NOTE_A5, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_B4, NOTE_E4,
  NOTE_G4, NOTE_G4, NOTE_A5, NOTE_G4, NOTE_B4, NOTE_B4, NOTE_G5, 0,
  
  //Repeat for Second Half
  
  NOTE_B4, 0, NOTE_E5, 0, NOTE_B4, 0, NOTE_E5, 0,
  NOTE_B4, NOTE_E5, NOTE_B4, 0, NOTE_A5, NOTE_B4, 0,
  NOTE_B4, NOTE_A5, NOTE_B4, NOTE_A4, 0, NOTE_G5, NOTE_A4, NOTE_G4,
  NOTE_E4, 0,
 
  NOTE_B4, 0, NOTE_E5, 0, NOTE_B4, 0, NOTE_E5, 0,
  NOTE_B4, NOTE_E5, NOTE_B4, 0, NOTE_A5, NOTE_B4, 0,
  NOTE_A4, 0, NOTE_A4, NOTE_G5, NOTE_A4,
  NOTE_D5, NOTE_C5, NOTE_B4, NOTE_A4,
  
  NOTE_B4, 0, NOTE_E5, 0, NOTE_B4, 0, NOTE_E5, 0,
  NOTE_B4, NOTE_E5, NOTE_B4, 0, NOTE_A5, NOTE_B4, 0,
  NOTE_B4, NOTE_A5, NOTE_B4, NOTE_A4, 0, NOTE_G5, NOTE_A4, NOTE_G4,
  NOTE_E4, 0,
 
  NOTE_E4, NOTE_G4,
  NOTE_B4, NOTE_D5, 0,
  NOTE_F5, NOTE_E5, NOTE_A5, NOTE_B4, NOTE_G4, 0,
  
  };

int durations[] = {

125, 125, 125, 125, 125, 125, 125, 125,
125, 250, 125, 125, 125, 125, 125,
125, 125, 125, 125, 125, 125, 125, 400,
500, 125,

125, 125, 125, 125, 125, 125, 125, 125,
125, 250, 125, 125, 125, 125, 125,
125, 100, 350, 150, 220,
125, 220, 220, 330,

125, 125, 125, 125, 125, 125, 125, 125,
125, 250, 125, 125, 125, 125, 125,
125, 125, 125, 125, 125, 125, 125, 400,
500, 125,

500, 500, 500, 500, 50,
250, 250, 150, 250, 150, 800,

200, 250, 125, 125, 125, 250,
125, 250, 125, 125, 125, 250,
125, 250, 125, 125, 100,
450, 500, 10, 

200, 250, 125, 125, 125, 250,
125, 250, 125, 125, 125, 250,
125, 250, 125, 125, 100, 
450, 425, 10,

200, 250, 125, 125, 125, 250,
125, 250, 125, 125, 125, 250,
125, 250, 125, 125, 100,
400, 500, 300, 

125, 125, 250, 125, 125, 250,
125, 250, 425,
125, 125, 125, 125, 125, 250,
450, 250,

250, 125, 250, 125, 250,
125, 125, 125, 125, 125, 125, 125, 125,
250, 125, 250, 125, 250,
125, 125, 125, 125, 125, 125, 125, 125,
250, 125, 250, 125, 250,
125, 125, 125, 125, 125, 125, 125, 125,
125, 125, 125, 125, 125, 250, 450, 250,

125, 125, 125, 125, 125, 125, 125, 125,
125, 250, 125, 125, 125, 125, 125,
125, 125, 125, 125, 125, 125, 125, 400,
500, 400,

125, 125, 125, 125, 125, 125, 125, 125,
125, 250, 125, 125, 125, 125, 125,
125, 100, 350, 150, 220,
125, 220, 220, 330,

125, 125, 125, 125, 125, 125, 125, 125,
125, 250, 125, 125, 125, 125, 125,
125, 125, 125, 125, 125, 125, 125, 400,
500, 125,

500, 500, 500, 500, 50,
250, 250, 150, 250, 300, 800,
};

void setup() 
{
    const int totalNotes = sizeof(notes) / sizeof(int);
  // Loop through each note
  for (int i = 0; i < totalNotes; i++)
  {
    const int currentNote = notes[i];
    float wait = durations[i] / songSpeed;
    // Play tone if currentNote is not 0 frequency, otherwise pause (noTone)
    if (currentNote != 0)
    {
      tone(buzzer, notes[i], wait); // tone(pin, frequency, duration)
    }
    else
    {
      noTone(buzzer);
    }
    // delay is used to wait for tone to finish playing before moving to next loop
    delay(wait);
  }

}

void loop() {


}

int matrix_width = 8;

int analog_pins [] = {A0,A1,A2,A3,A4,A5,10,11};

int letters [5][8][8] = {
    {
      
      {1, 1, 1, 1, 0, 0, 0, 0},
      {1, 0, 0, 0, 1, 0, 0, 0},
      {1, 0, 0, 0, 0, 1, 0, 0},
      {1, 0, 0, 0, 0, 0, 1, 0},
      {1, 0, 0, 0, 0, 0, 1, 0},
      {1, 0, 0, 0, 0, 1, 0, 0},
      {1, 0, 0, 0, 1, 0, 0, 0},
      {1, 1, 1, 1, 0, 0, 0, 0}
        
    },
    {
      {0, 0, 1, 1, 1, 1, 0, 0},
      {0, 0, 0, 1, 1, 0, 0, 0},
      {0, 0, 0, 1, 1, 0, 0, 0},
      {0, 0, 0, 1, 1, 0, 0, 0},
      {0, 0, 0, 1, 1, 0, 0, 0},
      {0, 0, 0, 1, 1, 0, 0, 0},
      {0, 0, 0, 1, 1, 0, 0, 0},
      {0, 0, 1, 1, 1, 1, 0, 0},
    },
    {
      {0, 0, 0, 1, 1, 0, 0, 0},
      {0, 0, 1, 0, 0, 1, 0, 0},
      {0, 1, 0, 0, 0, 0, 1, 0},
      {0, 1, 1, 1, 1, 1, 1, 0},
      {0, 1, 0, 0, 0, 0, 1, 0},
      {0, 1, 0, 0, 0, 0, 1, 0},
      {0, 1, 0, 0, 0, 0, 1, 0},
      {0, 1, 0, 0, 0, 0, 1, 0}
    },

    {
      {0, 1, 0, 0, 0, 0, 1, 0},
      {0, 1, 0, 0, 0, 0, 1, 0},
      {0, 1, 1, 0, 0, 0, 1, 0},
      {0, 1, 1, 1, 0, 0, 1, 0},
      {0, 1, 0, 1, 1, 0, 1, 0},
      {0, 1, 0, 0, 1, 0, 1, 0},
      {0, 1, 0, 0, 0, 1, 1, 0},
      {0, 1, 0, 0, 0, 0, 1, 0},
    },
    {
      {0, 0, 0, 1, 1, 0, 0, 0},
      {0, 0, 1, 0, 0, 1, 0, 0},
      {0, 1, 0, 0, 0, 0, 1, 0},
      {0, 1, 1, 1, 1, 1, 1, 0},
      {0, 1, 0, 0, 0, 0, 1, 0},
      {0, 1, 0, 0, 0, 0, 1, 0},
      {0, 1, 0, 0, 0, 0, 1, 0},
      {0, 1, 0, 0, 0, 0, 1, 0}
    }
  };

int frames_to_print = 50;
int printed_frames = 0;
int letter = 0;
int total_leters = 5;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  for(int i = 0; i < matrix_width; i++){
    pinMode(analog_pins[i],OUTPUT);
    pinMode(i+2,OUTPUT);
  }

}

void loop() {

  if(printed_frames == frames_to_print){
    printed_frames = 0;
    if(letter + 1 == total_leters){
      letter = 0;
    }
    else{
      letter++;  
    }
  }
  

  
    for(int row = 0; row < matrix_width; row++){

      digitalWrite(row+2,0);
      for(int col = 0; col < matrix_width; col++){
        //Serial.print("Actual value: ");
        //Serial.println(letters[letter][row][col]);
        if(letters[letter][row][col] == 1){
          //Serial.println("Encendiendo LED");
          digitalWrite(analog_pins[col],1);
          
        }
        else{
          digitalWrite(analog_pins[col],0);
        }
        //delayMicroseconds(1200);
      }
      digitalWrite(row+2,1);
      //Serial.print("Ya se ha impreso una fila");
      delay(1);
      turnOffAll();
      digitalWrite(row+2,0);
    }
    //Serial.println("Esto ha terminado");
    //delay(2000);
  printed_frames++;
}


void turnOffAll(){
  for(int col = 0; col < matrix_width; col++){
    digitalWrite(analog_pins[col],0);
  }
}

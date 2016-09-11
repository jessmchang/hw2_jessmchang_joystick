#if defined(ARDUINO) 
SYSTEM_MODE(MANUAL); 
#endif

int button1 = D0;    // the number of the pushbutton pin
int button2 = D1;
int button3 = D2;
int button4 = D3;
int button5 = D4;
int button6 = D5;
int but_enter = D8;

int button1state = 0;
int button2state = 0;
int button3state = 0;
int button4state = 0;
int button5state = 0;
int button6state = 0;
int button7state = 0;

//char *letters[]; 

void setup() {
  Serial.begin(9600);
  pinMode(button1, INPUT_PULLDOWN);
  pinMode(button2, INPUT_PULLDOWN);
  pinMode(button3, INPUT_PULLDOWN);
  pinMode(button4, INPUT_PULLDOWN);
  pinMode(button5, INPUT_PULLDOWN);
  pinMode(button6, INPUT_PULLDOWN);
  pinMode(but_enter, INPUT_PULLDOWN);
  
}

int letter_mode = 0;  //1 if on, 0 if off
int curr_group = 0;
int curr_letter = 0;

char group_one[5] = {'Q', 'W', 'E', 'R', 'T'};
char group_two[5] = {'Y', 'U', 'I', 'O', 'P'};
char group_three[4] = {'H', 'J', 'K', 'L'};
char group_four[3] = {'B', 'N', 'M'};
char group_five[4] = {'Z', 'X', 'C', 'V'};
char group_six[5] = {'A', 'S', 'D', 'F', 'G'};
int group_one_length = 5;
int group_two_length = 5;
int group_three_length = 4;
int group_four_length = 3;
int group_five_length = 4;
int group_six_length = 5;


void loop() {
  button1state = digitalRead(button1);
  button2state = digitalRead(button2);
  button3state = digitalRead(button3);
  button4state = digitalRead(button4);
  button5state = digitalRead(button5);
  button6state = digitalRead(button6);
  button7state = digitalRead(but_enter);
  //letter mode on?

       if (letter_mode){
           delay(625);

           if(curr_group == 1){
              if(button3state == HIGH){ //right
//                  Serial.println("right");
                  curr_letter = curr_letter + 1;
                
                  
                  if(curr_letter = group_one_length){
                    curr_letter = curr_letter - 1;
                  }
                  delay(625);
               } else if (button6state == HIGH){  //left
                 Serial.println("left");
                  curr_letter = curr_letter - 1;
                  if(curr_letter < 0){
                    curr_letter = 0;
                  }
                  delay(625);
               } else if (button7state == HIGH){
                   Serial.println(group_one[curr_letter]);
                   delay(625);
                    letter_mode = 0;
               }
            } else if (curr_group == 2){
              if(button3state == HIGH){ //right
                  curr_letter = curr_letter + 1;
                  if(curr_letter = group_two_length){
                    curr_letter = curr_letter - 1;
                  }
                  delay(625);
               } else if (button6state == HIGH){  //left
                  curr_letter = curr_letter - 1;
                  if(curr_letter < 0){
                    curr_letter = 0;
                  }
                  delay(625);
               } else if (button7state == HIGH){
                   Serial.println(group_two[curr_letter]);
                   delay(625);
                    letter_mode = 0;
               }
           } else if (curr_group == 3){
              if(button3state == HIGH){ //right
                  curr_letter = curr_letter + 1;
                  if(curr_letter = group_three_length){
                    curr_letter = curr_letter - 1;
                  }
                  delay(625);
               } else if (button6state == HIGH){  //left
                  curr_letter = curr_letter - 1;
                  if(curr_letter < 0){
                    curr_letter = 0;
                  }
                  delay(625);
               } else if (button7state == HIGH){
                   Serial.println(group_three[curr_letter]);
                   delay(625);
                    letter_mode = 0;
               }
           } else if (curr_group == 4){
            if(button3state == HIGH){ //right
                  curr_letter = curr_letter + 1;
                  if(curr_letter = group_four_length){
                    curr_letter = curr_letter - 1;
                  }
                  delay(625);
               } else if (button6state == HIGH){  //left
                  curr_letter = curr_letter - 1;
                  if(curr_letter < 0){
                    curr_letter = 0;
                  }
                  delay(625);
               } else if (button7state == HIGH){
                   Serial.println(group_four[curr_letter]);
                   delay(625);
                    letter_mode = 0;
               }
           } else if (curr_group == 5){
             if(button3state == HIGH){ //right
                  curr_letter = curr_letter + 1;
                  if(curr_letter = group_five_length){
                    curr_letter = curr_letter - 1;
                  }
                  delay(625);
               } else if (button6state == HIGH){  //left
                  curr_letter = curr_letter - 1;
                  if(curr_letter < 0){
                    curr_letter = 0;
                  }
                  delay(625);
               } else if (button7state == HIGH){
                   Serial.println(group_five[curr_letter]);
                   delay(625);
                    letter_mode = 0;
               }
           } else if (curr_group == 6){
               if(button3state == HIGH){ //right
                  curr_letter = curr_letter + 1;
                  if(curr_letter = group_six_length){
                    curr_letter = curr_letter - 1;
                  }
                  delay(625);
               } else if (button6state == HIGH){  //left
                  curr_letter = curr_letter - 1;
                  if(curr_letter < 0){
                    curr_letter = 0;
                  }
                  delay(625);
               } else if (button7state == HIGH){
                   Serial.println(group_six[curr_letter]);
                   delay(625);
                    letter_mode = 0;
               }
           }
           
          
       }
       


      if (button1state == HIGH && !letter_mode){
      Serial.println("NORTHWEST");
        curr_letter = 0;
        letter_mode = 1;
        curr_group = 1;
      delay(625);
    }
    else if (button2state == HIGH && !letter_mode){
      curr_letter = 0;
       letter_mode = 1;
      Serial.println("NORTHEAST");
      curr_group = 2;
       delay(625);
    }
    else if (button3state == HIGH && !letter_mode){
      curr_letter = 0;
       letter_mode = 1;
      Serial.println("EAST");
      curr_group = 3;
       delay(625);
    }
    else if (button4state == HIGH && !letter_mode){
      curr_letter = 0;
       letter_mode = 1;
      Serial.println("SOUTHEAST");
      curr_group = 4;
       delay(625);
    }
    else if (button5state == HIGH && !letter_mode){
      curr_letter = 0;
       letter_mode = 1;
      Serial.println("SOUTHWEST");
      curr_group = 5;
       delay(625);
    }
    else if (button6state == HIGH && !letter_mode){
      curr_letter = 0;
       letter_mode = 1;
      Serial.println("WEST");
      curr_group = 6;
       delay(625);
    }  else if (button7state == HIGH && !letter_mode){
//      Serial.print("SPACE: "); Serial.println(" ");
       delay(625);
    }
  
  
}



int old_button = 0;
int button;
int pressed_button;
int z;

void setup () {
  Serial.begin(9600);
  pinMode(A5, INPUT);
}

void loop () {
  z = analogRead(5);
  if (z > 1021) button = 0;                                           
  else if (z > 511 && z < 514) button = 1;                     
  else if (z > 680 && z < 684) button = 2;                
  else if (z > 766 && z < 770) button = 3;                
  else if (z > 817 && z < 822) button = 4;             
  else if (z > 851 && z < 856) button = 5; 
  //else if (z > 875 && z < 880) button = 6;
  else button = 6;                                                      
  
  if (old_button == button) {                                           
    old_button = button;                                              
    pressed_button = 0;                                               
  }  

  else {                                                                
    old_button = button;                                             
    pressed_button = button;                                        
  }
  Serial.print("Button pushed = ");
  Serial.println(z);
; 
  delay(500);
}

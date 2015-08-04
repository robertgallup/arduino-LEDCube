////////////////////////////////////////////////////////////////////////////////////////
//
// Shows a specific animation
//
////////////////////////////////////////////////////////////////////////////////////////

void showAnimation(int theAnimation) {
  
  for(int frame=theAnimation*16; frame<((theAnimation+1)*16); frame++) {
    
    // Times to repeat each frame (shift to retreive 2nd byte from the right)
    unsigned int repeat = pgm_read_word_near(&(animation[frame][3])) >> 8;

    for(int r=0; r<repeat; r++) {
      
      // Number of times to cycle through all of the layers
      for(int c=0; c<21; c++) {
        
        // Switch pins for each LED in the layer
        unsigned int LEDVector =  pgm_read_word_near(&(animation[frame][c%3]));        
        
        digitalWrite ( 2, LEDVector & 0x001);
        digitalWrite ( 4, LEDVector & 0x002);
        digitalWrite ( 7, LEDVector & 0x004);
        
        digitalWrite ( 8, LEDVector & 0x008);
        digitalWrite ( 9, LEDVector & 0x010);
        digitalWrite (10, LEDVector & 0x020);
        
        digitalWrite (11, LEDVector & 0x040);
        digitalWrite (12, LEDVector & 0x080);
        digitalWrite (13, (LEDVector & 0x100) >> 1);

        // Activate the appropriate layer
        unsigned int data = 0xFF - pgm_read_word_near(&(animation[frame][3])) & 0xFF;        
        switch (c % 3) {
          case 0:
            analogWrite(3, data);  
            break;
            
          case 1:
            analogWrite(5, data);        
            break;
            
          case 2:
            analogWrite(6, data);
            break;
        }
          
        // Delay for 2 milliseconds and switch all layers off
        delay(2); 
        digitalWrite(3,1); 
        digitalWrite(5,1);
        digitalWrite(6,1);         
      }
      delay(1);        
    }  
  }}

/*
  estiPC
  A DOS PC.

 */


//Variable Stuff
int ver = 1.0;
int build = 0004
String inBuffer = "";

//Very importent array
String commands[] = {"ver", };

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }

  // prints title with ending line break
  Serial.println("Starting estiDOS...");
  Serial.print("Version: "); Serial.println(ver);
  extern int __heap_start, *__brkval; 
  int v; 
  int fr = (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval); 
  Serial.print(fr);
  Serial.println(" bytes OK ");
  Serial.print(">");
}

//Variable Stuff
void loop() {

        // send data only when you receive data:
        if (Serial.available() > 0) {
                // read the incoming data:
                inBuffer = Serial.readString();
                //remove any newline stuff
                inBuffer.replace("\n","");
                Serial.println(inBuffer);

                //Place to check what was inputed.
                if(inBuffer == "ver"){
                  Serial.println("estiDOS version 1");
                }else{
                  Serial.print("Unknown Command: ");
                  Serial.println(inBuffer);
                }

                Serial.print(">");
        }
}

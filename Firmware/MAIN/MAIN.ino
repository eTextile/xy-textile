////////////////// déclarations des variables
#define Y1_PIN         10                   // Define I/O pin 10
#define Y2_PIN         9                    // Define I/O pin 9
#define X1_PIN         11                   // Define I/O pin 11
#define X2_PIN         12                   // Define I/O pin 12
#define ADC_PIN_0      A1                   // Define the analog input pin 0
#define ADC_PIN_1      A0                   // Define the analog input pin 1
#define BAUD_RATE      230400               // Define USB baud rate
#define DEL            2                    // Define delay

uint16_t raw_X = 0;                         // Variables for sensor1 data
uint16_t raw_Y = 0;                         // Variables for sensor1 data
uint16_t Xmsb, Xlsb, Ymsb, Ylsb;

////////////////// initialisation
void setup() {
  Serial.begin(BAUD_RATE);
}

////////////////// boucle principale
void loop() {
  // FIRST TIME : GET X VALUE
  pinMode(X1_PIN, INPUT);                  // Set pin in high impedance state (+infinite) 
  pinMode(X2_PIN, INPUT);                  // Set pin in high impedance state (+infinite)
  pinMode(Y1_PIN, OUTPUT);                 // Set Pin as an OUTPUT
  pinMode(Y2_PIN, OUTPUT);                 // Set Pin as an OUTPUT
  digitalWrite(Y1_PIN, LOW);               // Turn OFF the pin 10
  digitalWrite(Y2_PIN, HIGH);              // Turn ON the pin 9
  //delay(DEL);

  raw_X = analogRead(ADC_PIN_0);
  transmit_X(raw_X);

  // SECOND TIME : GET Y VALUE 
  pinMode(X1_PIN, OUTPUT);                 // declare the Pin as an OUTPUT
  pinMode(X2_PIN, OUTPUT);                 // declare the Pin as an OUTPUT
  pinMode(Y1_PIN, INPUT);                  // put pin in high impedance (+infinite)
  pinMode(Y2_PIN, INPUT);                  // put pin in high impedance (+infinite;)
  digitalWrite(X1_PIN, HIGH);              // turn on the Pin 11
  digitalWrite(X2_PIN, LOW);               // turn off the Pin 12
  //delay(DEL);

  raw_Y = analogRead(ADC_PIN_1);
  transmit_Y(raw_Y);
}

////////////////// fonctions de communication série (Arduino -> PC)
void transmit_X(int Xdata){
  // Octet 1 for X ; MSB for X (More Signifiant Bits)
  // 00000xxx  Value (after being shifted 5 times)
  // ||
  // ||--------> MSB
  // |---------> X
  Xmsb = Xdata >> 5 ;                  // Division by 32, save the 5 MSB bits
  Serial.write(Xmsb);                  // Send X MSB

  // octet 0 for X ; LSB for X (Less Signifiant Bits)
  // xxxxxxxx     value
  // 00011111     & mask (31)
  // 01000000     + flag
  // 010xxxxx     = result for
  // 01000000     + 64 for LSB flag
  // 00000000     first bit is 0 for X flag
  Xlsb = Xdata & 31 ;                  // Save the 5 LSB bits
  Xlsb = Xlsb + 64 ;                   // Set second bit to 1 for LSB marker
  Serial.write(Xlsb);                  // Send X LSB
}

void transmit_Y(int Ydata){
  // Octet 1 for Y ; MSB for Y (More Significant Bits)
  // 10000xxx  Value (after being shifted 5 times)
  // ||
  // ||--------> MSB
  // |---------> 1=>Y
  Ymsb = Ydata >> 5 ;                  // Division by 32, save the 5 Msb bits
  Ymsb = Ymsb + 128 ;                  // Add a bit for Y
  Serial.write(Ymsb);                  // Send Y MSB

  // octet 0 for Y ; LSB for Y (Less Significant Bits)
  // xxxxxxxx     value
  // 00011111     & mask
  // 000xxxxx     = result
  // 01000000     + 64  for LSB flag
  // 10000000     first bit is 1 for Y flag
  Ylsb = Ydata & 31 ;                  // Save the 5 lsb bits
  Ylsb = Ylsb + 64 ;                   // Set second bit to 1 for lsb marker
  Ylsb = Ylsb + 128 ;                  // Add a bit for Y
  Serial.write(Ylsb);                  // Send Y LSB
}

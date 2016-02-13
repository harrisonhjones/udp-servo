/*
    Demo to receive servo psoition over UDP
    Harrison Jones (harrison@hhj.me)
    Feb 13, 2016
*/

unsigned int localPort = 8888;
unsigned char buff[100];
unsigned char counter = 0;

Servo myservo;  

UDP Udp;

void setup() {
  // start the UDP
  Udp.begin(localPort);

  // Print your device IP Address via serial
  Serial.begin(9600);
  
  // Attach the servo object to D0. Wire your servo to D0, GND, and VIN
  myservo.attach(D0);
}

void loop() {

  // Uncomment to find your device's IP address
  // Serial.println(WiFi.localIP());

  // Check if data has been received
  if (Udp.parsePacket() > 0) {

    // While we have characters to read read them
    while(Udp.available() > 0)
    {
      buff[counter++] = Udp.read();
    }

    // Null terminate (needed for atoi)
    buff[counter] = '\0';

    // Parse the position from the string buff
    int pos = atoi((const char*)buff);

    // Send out the position over serial (for debugg)
    Serial.println(pos, DEC);

    // Send out the position to the servo
    myservo.write(pos);

    // Ignore other chars
    Udp.flush();

    // Reset out buffer
    counter = 0;
  }
}
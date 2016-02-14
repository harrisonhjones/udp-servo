# udp-servo
A Photon-powered Servo controlled over UDP

## Video

You can find a demo video [here](https://www.youtube.com/watch?v=2BNiVtI8kQo)

## Setup

You'll need:

- Python 2.7
- A [Particle Photon](https://particle.io)
- A servo motor + some wire

## Running

### Locally

1. Run server.py
2. Edit client.py and comment in the second `host` declaration 
3. Run client.py and press "enter"
4. You should see the position data being sent to the server from the client

### Remotely

1. Flash your Photon with the provided firmware (`application.info`)
2. Connect your servo to D0, VIN, and GND
3. If you ran the client locally remember to edit it again and comment out the second `host` declaration
4. Run client.py & press "enter"
5. You should see the servo's position start changing

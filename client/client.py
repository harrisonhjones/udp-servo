'''
    Demo to send servo psoition over UDP
    Harrison Jones (harrison@hhj.me)
    Feb 13, 2016
'''
 
import socket   #for sockets
import sys      #for exit
import time     #for pausing between sending positions

# Create the UDP socket connection
try:
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
except socket.error:
    print 'Failed to create socket'
    sys.exit()

# The host/ip of your Photon
host = '192.168.1.148';
host = 'localhost' ## Uncomment and run server.py to test
port = 8888;

# Default position and direction
position = 90;
direction = 1;

msg = raw_input('Press enter when ready')

# Continue forever
while(1) :
    try :
        # Increment the position in the current direction
        position += direction;

        # Apply endstops
        if(position > 120):
            direction = -1
            position = 120

        if(position < 60 ):
            direction = 1
            position = 60

        # Debug
        print 'Now sending position = '
        print position

        # Actually send out the UDP packet
        s.sendto(str(position), (host, port))

        # Sleep
        time.sleep(.1)
     
    except socket.error, msg:
        print 'Error Code : ' + str(msg[0]) + ' Message ' + msg[1]
        sys.exit()
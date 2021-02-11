import socket
import subprocess
import sys
from datetime import datetime

# Input
remoteServer = input("Enter a remote host to scan: ")
remoteServerIP = socket.gethostbyname(remoteServer)

# Print message
print("-" * 60)
print("Please wait, scanning IP address ", remoteServerIP)
print("-" * 60)

#Time
t1 = datetime.now()

try:
    for port in range(1,9999):  
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        result = sock.connect_ex((remoteServerIP, port))
    if result == 0:
        print("Port {}: 	 Open".format(port))
        sock.close()

except KeyboardInterrupt:
    print("You pressed Ctrl+C")
    sys.exit()

except socket.gaierror:
    print("Hostname could not be resolved. Exiting")
    sys.exit()

except socket.error:
    print("Couldn't connect to server")
    sys.exit()

t2 = datetime.now()

# Calculates the difference of time, to see how long it took to run the script
total =  t2 - t1

# Prints time taken
print("Scanning Completed in: ", total)
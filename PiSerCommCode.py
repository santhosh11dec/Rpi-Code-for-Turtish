import serial
ser = serial.Serial('/dev/ttyACM0', 9600) # the /dev/ttyACM0 text should match the Serial Port that the Arduino IDE shows
ser.write('0')

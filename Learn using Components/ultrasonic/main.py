import serial
import winsound
import time

arduino = serial.Serial('COM6', 9600)
time.sleep(2)

while True:
    data = arduino.readline().decode().strip()
    print(data)

    if data.isdigit():
        distance = int(data)

        if distance <= 30:
            # Map distance to delay (closer = faster)
            delay = max(0.05, distance / 100)

            winsound.Beep(1000, 100)
            time.sleep(delay)

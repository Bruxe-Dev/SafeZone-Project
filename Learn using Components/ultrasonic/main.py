import serial
import winsound

arduino = serial.Serial('COM6', 9600)

while True:
    data = arduino.readline().decode().strip()
    print(data)

    if data == "ALERT":
        winsound.Beep(1000, 300)  # frequency, duration

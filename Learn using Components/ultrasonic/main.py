import serial
import winsound

# change COM port if needed
arduino = serial.Serial('COM6', 9600)

while True:
    data = arduino.readline().decode().strip()
    print(data)

    if data == "ALERT1":
        # Fire + no person: normal alert
        winsound.Beep(1400, 500)  # frequency 1400Hz, duration 500ms

    elif data == "ALERT2":
        # Fire + person nearby: higher alert
        winsound.Beep(2000, 500)  # frequency 2000Hz, duration 500ms

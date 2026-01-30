import serial
import winsound
import time

arduino = serial.Serial('COM6', 9600)

while True:
    data = arduino.readline().decode().strip()
    print(data)

    if data == "ALERT1":
        frequency = 1700  # Hz
        duration = 500    # ms
        winsound.Beep(frequency, duration)
        time.sleep(0.1)  

    elif data == "ALERT2":
        frequency = 1700  
        duration = 250   
        for _ in range(40):
            winsound.Beep(frequency, duration)
            time.sleep(0.05)  # very short pause between beeps

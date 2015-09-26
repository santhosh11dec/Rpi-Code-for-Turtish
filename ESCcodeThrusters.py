from Tkinter import * 
import RPi.GPIO as GPIO 
import time

GPIO.setmode(GPIO.BCM) 
GPIO.setup(14, GPIO.OUT) 
pwm = GPIO.PWM(14, 100) #100Hz - 0.01s or 10 ms signals
pwm.start(15)
time.sleep(2)

class App: 
    def __init__(self, master): 
        frame = Frame(master) 
        frame.pack()
        scale = Scale(frame, from_=1100, to=1900, orient=HORIZONTAL, command=self.update) 
        scale.grid(row=0) 
        angle = 1500 #1500us pulse in signal represents a stop signal
    def update(self, angle): 
        duty = (((float(angle)/1000)/10)*100) #conversion to duty cycle - 1.5ms pulse in 10ms signals
        pwm.ChangeDutyCycle(duty) 
        print duty
    
root = Tk()
root.wm_title('Servo Control')
app = App(root)
root.geometry("200x50+0+0")
root.mainloop()

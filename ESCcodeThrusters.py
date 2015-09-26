from Tkinter import * 
#import RPi.GPIO as GPIO 
import time

GPIO.setmode(GPIO.BCM) 
GPIO.setup(18, GPIO.OUT) 
pwm = GPIO.PWM(18, 100)
pwm.start(5)
time.sleep(2)

class App: 
    def __init__(self, master): 
        frame = Frame(master) 
        frame.pack()
        scale = Scale(frame, from_=1100, to=1900, orient=HORIZONTAL, command=self.update, resolution = 100) 
        scale.grid(row=0) 
        angle = 1500
    def update(self, angle): 
        duty = (((float(angle)/1000)/10)*100)
        pwm.ChangeDutyCycle(duty) 
        print duty
        
root = Tk()
root.wm_title('Servo Control')
app = App(root)
root.geometry("200x50+0+0")
root.mainloop()

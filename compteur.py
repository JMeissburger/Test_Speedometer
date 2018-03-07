#!/usr/bin/python3

import time
import sys

class Meter:
    def __init__(self, max_val, min_val):
        self.max_value = max_val
        self.min_value = min_val
        self.cur_value = self.min_value
        
    def increase_val(self, step):
        if (self.cur_value + step) > self.max_value:
             self.cur_value = self.max_value
        else:
            self.cur_value += step
    
    def decrease_val(self, step):
        if (self.cur_value - step) < self.min_value:
            self.cur_value = self.min_value
        else:
            self.cur_value -= step
            

class Speedometer(Meter):
    def __init__(self, max_val, min_val):
        Meter.__init__(self, max_val, min_val)
        self.accel_step = 3
        self.decel_step = 1
        self.brake_step = 8
        
    def accel(self):
        self.increase_val(self.accel_step)
    
    def decel(self):
        self.decrease_val(self.decel_step)
    
    def brake(self):
        self.decrease_val(self.brake_step)

def Trace(message, value, max_value):
    digits = len(str(max_value -1))
    delete = "" *(digits+len(message))
    print("{0}{3}{1:{2}}".format(delete, value, digits, message), end="")
    sys.stdout.flush()
        

speedometer = Speedometer(240, 0)

message = ""
while speedometer.cur_value < 240:
        speedometer.accel()
        Trace(message, speedometer.cur_value, speedometer.max_value)
        time.sleep(0.1)

while speedometer.cur_value > 220:
        speedometer.decel()
        Trace(message, speedometer.cur_value, speedometer.max_value)
        time.sleep(0.1)

while speedometer.cur_value > 0:
        speedometer.brake()
        Trace(message, speedometer.cur_value, speedometer.max_value)
        time.sleep(0.1)

print("\n")

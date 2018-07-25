
import argparse
import sys
import string
from multiprocessing import Process
from threading import (
	Thread,
	activeCount,
	Event,
	enumerate,
)
import ctypes
import rospy
from std_msgs.msg import (
    UInt16,
    Bool,
)
import baxter_interface as baxter
import pyttsx
import speech_recognition as sr
from positionControl import *
from mobileTaskFunctions import *
from std_msgs.msg import String
from baxter_core_msgs.msg import CollisionDetectionState
from sensor_msgs.msg import Image
import time
import cv2
import cv_bridge

rawCommand = ""
collisionState = False

def collisionDetection(data):
	global collisionState
	global rawCommand
	collisionState = data.collision_state
	if collisionState:
		rawCommand = ""

def terminate_thread(thread):
    """Terminates a python thread from another thread.

    :param thread: a threading.Thread instance
    """
    if not thread.isAlive():
        return

    exc = ctypes.py_object(KeyboardInterrupt)
    res = ctypes.pythonapi.PyThreadState_SetAsyncExc(
        ctypes.c_long(thread.ident), exc)
    if res == 0:
        raise ValueError("nonexistent thread id")
    elif res > 1:
        # """if it returns a number greater than one, you're in trouble,
        # and you should call it again with exc=NULL to revert the effect"""
        ctypes.pythonapi.PyThreadState_SetAsyncExc(thread.ident, None)
        raise SystemError("PyThreadState_SetAsyncExc failed")
rospy.init_node('Test')
baxter_enabler = baxter.RobotEnable(versioned=True)
baxter_enabler.enable()

# Set up subscriber for collision detection
collisionSubs = rospy.Subscriber(name='/robot/limb/left/collision_detection_state', 
								 data_class=CollisionDetectionState, callback=collisionDetection, 
								 buff_size=100)

# Baxter elements 
lLimb = baxter.Limb('left')
rLimb = baxter.Limb('right')
lGripper = baxter.Gripper('left')
rGripper = baxter.Gripper('right')

# calibrating gripper
if not lGripper.calibrate():
	print("left gripper did not calibrate")
	sys.exit()

# amp up gripper holding force
lGripper.set_holding_force(100)
lGripper.set_moving_force(100)

rGripper.set_holding_force(100)
rGripper.set_moving_force(100)

lLimb.set_joint_position_speed(.5)
lLimb.set_command_timeout(2)
strtPose = lLimb.endpoint_pose()


slow = .02 # m/s
fast = .2 # m/s

command = ""
newCommand = ""
lastCommand = ""

# Event for pausing the current task
pause_event = Event()
#Move to Zero position()

def openFridge():
    global lLimb, rLimb, pause_event
    playPositionFile('openFridgeMobile.wp', lLimb, rLimb, pause_event)

def closeFridge():
    global lLimb, rLimb, pause_event
    playPositionFile('closeFridgeMobile.wp', lLimb, rLimb, pause_event)

def getBottleOpenFridge():
    global lLimb, rLimb, pause_event, lGripper
    print("Getting bottle open fridge part 1")
    playPositionFile('getBottleOpenFridgeMobileP1.wp', lLimb, rLimb, pause_event)
    moveOnAxis(lLimb, 'y', .08, .06, pause_event)
    time.sleep(1)
    waitForNotPause(pause_event)
    lGripper.close()
    time.sleep(1)
    print("Getting bottle open fridge part 2")
    playPositionFile('getBottleOpenFridgeMobileP2.wp', lLimb, rLimb, pause_event)

def moveToTableAfterRetrieve():
    global lLimb, rLimb, pause_event, lGripper
    print("moving bottle to table p1")
    playPositionFile('moveToTableAfterRetrieveMobileP1.wp', lLimb, rLimb, pause_event)
    moveOnAxis(lLimb, 'y', -.1, .04, pause_event)
    moveOnAxis(lLimb, 'z', -.1, .08, pause_event)
    time.sleep(1)
    waitForNotPause(pause_event)
    lGripper.open()
    time.sleep(1)
    moveOnAxis(lLimb, 'z', .08, .04, pause_event)
    moveOnAxis(lLimb, 'x', -0.5, .06, pause_event)
    playPositionFile('moveToTableAfterRetrieveP2.wp', lLimb, rLimb, pause_event)


def openMicrowave():
	global lLimb, rLimb, pause_event, lGripper
	playPositionFile('openMicrowaveMobile.wp', lLimb, rLimb, pause_event)

def closeMicrowave():
	global lLimb, rLimb, pause_event, lGripper
	playPositionFile('closeMicrowaveMobile.wp', lLimb, rLimb, pause_event)

def getFoodContainer():
	global lLimb, rLimb, lGripper, pause_event
	playPositionFile('getFoodFromFridgeP1.wp', lLimb, rLimb, pause_event)
	#moveOnAxis(lLimb, 'z', -.015, .03, pause_event)
	moveOnAxis(lLimb, 'y', .07, .03, pause_event)
	time.sleep(.5)
	waitForNotPause(pause_event)
	lGripper.close()
	time.sleep(.5)
	#moveOnAxis(lLimb, 'z', .03, .04, pause_event)
	moveOnAxis(lLimb, 'y', -.1, .03, pause_event)
	playPositionFile('getFoodFromFridgeP2.wp', lLimb, rLimb, pause_event)

print("Moving to mobile downward position")
moveToDownward(lLimb, rLimb, pause_event)

'''
print("Opening the fridge")
openFridge()

print("Getting bottle in hand")
getBottleOpenFridge()

moveToTableAfterRetrieve()
closeFridge()
'''

#openMicrowave()
#closeMicrowave()

openFridge()
getFoodContainer()


'''
task = Thread(target=tester, args=(lLimb, rLimb, lGripper, pause_event), name="testCommand")
print(task.name)
task.daemon = True
task.start()
'''


#!/usr/bin/python

from openni import *

ctx = Context()
ctx.init()

gest = GestureGenerator()
gest.create(ctx)

gest.add_gesture("Wave")

# Create the hands generator
hands = HandsGenerator()
hands.create(ctx)

depth = DepthGenerator()
depth.create(ctx)
depth.set_resolution_preset(RES_VGA)
depth.fps = 30

# Register callbacks
def gesture_detected(src, gesture, id, endPoint):
    print "Detected gesture:", gesture
    hands.start_tracking(endPoint)
    return

def gesture_progress(src, gesture, point, progress): pass

gest.register_gesture_cb(gesture_detected, gesture_progress)

# Declare the callbacks
def create(src, id, pos, time):
    projective_pos = depth.to_projective([pos])
    print id, projective_pos, time
# create

def update(src, id, pos, time):
    projective_pos = depth.to_projective([pos])
    print id, projective_pos, time
# update

def destroy(src, id, time):
    print id, time
# destroy

hands.register_hand_cb(create, update, destroy)

# Start generating
ctx.start_generating_all()

while True:
	# Update to next frame
	ctx.wait_and_update_all()
# while
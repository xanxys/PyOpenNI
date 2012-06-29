#!/usr/bin/python

from openni import *
import pygame
import numpy
import cv

context = Context()
context.init()

depth_generator = DepthGenerator()
depth_generator.create(context)
depth_generator.set_resolution_preset(RES_VGA)
depth_generator.fps = 30

image_generator = ImageGenerator()
image_generator.create(context)
image_generator.set_resolution_preset(RES_VGA)
image_generator.fps = 30

gesture_generator = GestureGenerator()
gesture_generator.create(context)
gesture_generator.add_gesture('Wave')

hands_generator = HandsGenerator()
hands_generator.create(context)

# pygame
pygame.init()
screen = pygame.display.set_mode((640, 480))
pygame.display.set_caption('Hand Tracking')

rect_pos = None

# Declare the callbacks
# gesture
def gesture_detected(src, gesture, id, end_point):
    print "Detected gesture:", gesture
    hands_generator.start_tracking(end_point)
# gesture_detected

def gesture_progress(src, gesture, point, progress): pass
# gesture_progress

def create(src, id, pos, time): pass
# create

def update(src, id, pos, time):
    projective_pos = depth_generator.to_projective([pos])[0]
    global rect_pos
    rect_pos = projective_pos
# update

def destroy(src, id, time): pass
# destroy

# Register the callbacks
gesture_generator.register_gesture_cb(gesture_detected, gesture_progress)
hands_generator.register_hand_cb(create, update, destroy)

# Start generating
context.start_generating_all()

print 'Make a Wave to start tracking...'

while True:
    rgb_frame = numpy.fromstring(image_generator.get_raw_image_map_bgr(), dtype=numpy.uint8).reshape(480, 640, 3)

    n_ret_val = context.wait_one_update_all(image_generator)
    cv.WaitKey(10)

    image = cv.fromarray(rgb_frame)
    cv.CvtColor(cv.fromarray(rgb_frame), image, cv.CV_BGR2RGB)
    pyimage = pygame.image.frombuffer(image.tostring(), cv.GetSize(image), 'RGB')
    screen.blit(pyimage, (0, 0))

    global rect_pos
    if rect_pos:
        pygame.draw.rect(screen, (0, 255, 0), (rect_pos[0], rect_pos[1], 100, 100))
        print rect_pos

    pygame.display.flip()
# while
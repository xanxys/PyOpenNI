#!/usr/bin/python

from openni import *

ctx = Context()
ctx.init()

# Create the user generator
hands = HandsGenerator()
hands.create(ctx)

# Declare the callbacks
def create(src, id, pos, time):
    print 'create'
    print src, id, pos, time
# create

def update(src, id, pos, time):
    print 'update'
    print src, id, pos, time
# update

def destroy(src, id, time):
    print 'destroy'
    print src, id, pos
# destroy

hands.register_hand_cb(create, update, destroy)

print hands

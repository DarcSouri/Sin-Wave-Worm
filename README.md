# Sine-Wave Worm Robot

A biomimetic robot that moves using a sine-wave motion, inspired by worm locomotion — built from a 
self-designed chain of body links, driven by a motor-actuated wire, with stabilization wheels, obstacle 
sensing, and an onboard camera module.

## Concept

The core idea: a chain of body links is threaded with a wire that has been bent around a 2cm-diameter 
pipe, giving it a natural sine-wave curvature. One end of the wire is turned by a motor, which propagates 
that wave shape through the whole chain of links — making the body move like a real worm. This mechanism 
was inspired by a video I watched, and I extended it with my own additions below.

## Current prototype status

This is a work in progress. Here's what's built and working, and what isn't yet:

- ✅ Body: a chain of self-designed links, currently prototyped with popsicle stick wood, connected with 
  thumbtacks (held in place with hot glue)
- ✅ Sine-wave drive: a single motor turns the internal wire, producing the wave motion through the links
- ✅ Stabilization wheels: two additional smaller motors, each driving one wheel, added for stability and 
  turning. Right now, the wheels are what's actually driving the worm forward — the sine-wave mechanism 
  itself isn't yet strong enough on its own. The end goal is for the sine-wave motion to be the primary 
  driver, with the wheels used only for turning.
- ✅ Obstacle detection: an ultrasonic sensor detects objects ahead so the worm can turn to avoid them
- ⚠️ Camera: an ESP32-CAM module is mounted and wired in, but there isn't currently enough power available 
  to run a live video stream to a computer
- ⚠️ Power: the whole system runs off a 5V LiPo battery, which is currently too heavy to mount on the 
  worm itself — it's being held externally during test runs rather than carried onboard

## Hardware layout

- A yellow DC motor drives the internal sine-wave wire through the body links
- Two smaller motors (one per wheel) are mounted just behind the main motor, in line with the start of 
  the link chain, for stabilization and turning
- On top of the main motor sit two platforms:
  - One (facing away from the links) holds the ultrasonic sensor and the ESP32-CAM side by side
  - The other (facing toward the links) holds the soldered circuit board
- Powered by a 5V LiPo battery (currently off-board due to weight)

## What's next

- Get the sine-wave mechanism strong enough to be the primary means of locomotion, reducing reliance on 
  the wheels
- Solve the power/weight problem to mount the battery onboard
- Get enough power headroom to run the ESP32-CAM live stream

## Notes

Code is still rough/early-stage and included as-is. This repo currently documents the mechanical and 
electrical design more than the software.

#!/bin/bash

# Bash script for testing Major's udp socket

MAJOR_HOST=localhost
MAJOR_PORT=3746
CPTN1='C$1-Resources$3-Confidance$6'
CPTN2='C$2-Resources$4-Confidance$9'

echo "Sending first captain's message: $CPTN1"
echo -n $CPTN1 | nc -4u -w1 $MAJOR_HOST $MAJOR_PORT

echo "Sleeping for 4 seconds"
sleep 4

echo "Sending second captain's message: $CPTN2"
echo -n $CPTN2 | nc -4u -w1 $MAJOR_HOST $MAJOR_PORT

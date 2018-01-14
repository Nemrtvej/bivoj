# Communication protocol


Code is listening on serial line (baud 9600).
Every line contains a command.
Command consists of two numbers separated by dash (-).
First number is number of millis of how long the servo should be rotating.
Second number is passed directly to servo and represents, how it should rotate.

- 90 - full stop
- 45 - full counterclockwise
- 135 - full clockwise
- 80 - slow counterclockwise
- 100 - slow clockwise

Servo control pin is connected to PIN 9
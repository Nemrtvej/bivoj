# Communication protocol

- Code is listening on serial line (baud 9600).
- Every line contains a command.
- Line is terminated by `\n`.
- Command consists of two numbers separated by dash (-).
- If line does not contain following bytes, the command is flushed and system is waiting for another one. List of whitelisted bytes: `0-9`, `-`, `\n`.
- First number is number of millis of how long the servo should be rotating.
- Second number is passed directly to servo and represents, how it should rotate:

	- 90 - full stop
	- 45 - full counterclockwise
	- 135 - full clockwise
	- 80 - slow counterclockwise
	- 100 - slow clockwise

- Servo control pin is connected to PIN 9.


# Examples

## Rotate 1 second clockwise (and dispense food)

`1000-135`

## Rotate 9 seconds counterclockwise

`9000-45`

70000+62000+83000+77000+73000+74000+ 8300+53000
from flask import Flask
from flask import jsonify
from threading import Timer
import time
import serial

########
# SIMPLE SERVER FOR OPENING DOORS
# Endpoints:
#    - / -- simple hello world
#    - /lock/knock - opens door and closes them after OPEN_DURATION time
#######

app = Flask(__name__)


def send_command(time, servo):
    ser = serial.Serial('/dev/ttyUSB0')
    ser.write("%s-%s\n" % (time, servo))
    ser.close()

def run_feeder():
    send_command(300, 135)
    send_command(200, 45)
    send_command(500, 135)
    send_command(200, 45)
    send_command(300, 135)

@app.route('/feed')
def feed(): 
    run_feeder()
    return jsonify(result='OK')


@app.route('/')
def hello_world():
    return jsonify(result='Hello World')

#@app.route('/feed')
def feed():
    return jsonify(result='OK')

if __name__ == '__main__':
    try:
        app.run(debug=True, host="0.0.0.0")
    except IOError, e:
        print e
    except KeyboardInterrupt:
        print "End"
    finally:
        GPIO.cleanup()

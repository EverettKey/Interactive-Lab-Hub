import serial
import time
# import threading
import paho.mqtt.client as mqtt
# import paho.mqtt.publish as publish

from flask import Flask, render_template
from flask_socketio import SocketIO, emit
from threading import Thread

broker="mqtt.eclipse.org"

# The callback for when the client receives a CONNACK response from the server.
def on_connect(client, userdata, flags, rc):
	print("Connected with result code "+str(rc))
	# Subscribing in on_connect() means that if we lose the connection and
	# reconnect then subscriptions will be renewed.
	client.subscribe("ixe/")

def on_message(client, userdata, msg):
	receivedMessage = str(msg.payload.decode("utf-8"))
	print("received message = "+receivedMessage)
	ser.write(receivedMessage.encode())

client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message

client.connect(broker, 1883, 60)

client.loop_start()

# Arduino communication
ser = serial.Serial('/dev/ttyUSB0', 9600)
ser.flushInput()

def read_from_port(ser):
	while True:
		reading = ser.readline().decode().strip()
		print(reading)
		client.publish("ixe/", reading)
		ser.flushInput()
		time.sleep(1)

thread = Thread(target=read_from_port, args=[ser])
thread.start()

# Flask Webserver
app = Flask(__name__)
app.config['SECRET_KEY'] = 'secret!'
socketio = SocketIO(app)

@app.route('/')
def index():
    return render_template('index.html')

@socketio.on('connect')
def test_connect():
    print('Client connected')
    emit('my response', {'data': 'Connected'})

@socketio.on('disconnect')
def test_disconnect():
    print('Client disconnected')

def main():
	try:
		while True:
			reading = ser.readline().decode().strip()
			print(reading)
			client.publish("there/", reading)
			ser.flushInput()
			time.sleep(1)
	except KeyboardInterrupt:
		ser.close()
		client.disconnect()
		client.loop_stop()
		print ("done")

# Handle the LED messages
@socketio.on('red')
def led_R():
    print("Turn the LED RED!")
    ser.write(b'red') 

@socketio.on('green')
def led_G():
    print("Turn the LED GREEN!")
    ser.write(b'green')

@socketio.on('blue')
def led_B():
    print("Turn the LED BLUE!")
    ser.write(b'blue')


if __name__ == '__main__':
	app.run(host='0.0.0.0', threaded=True)
	socketio.run(app)
	main()

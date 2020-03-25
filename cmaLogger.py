import serial
import json


with serial.Serial(
		port='COM4',
		baudrate=9600,
		parity=serial.PARITY_ODD,
		stopbits=serial.STOPBITS_TWO,
		bytesize=serial.SEVENBITS
	) as ser:
		status = {}
		status["1"] = "INIT_SUPER_STATE"
		status["2"] = "WAITING_POLL"
		status["3"] = "WAITING_END_TX_ANSWER"
		status["4"] = "WAITING_END_RX_ANSWER"
		status["5"] = "WAITING_END_TX_POLL"
		status["6"] = "WAITING_CONF_TX_FINAL"
		status["7"] = "WAITING_END_RX_ANSWER_OR_FINAL"
		
		try:
			while(True):
					x = ser.readline()
					print(x)

					if( x[0:2].decode("utf-8") == '7E'):
						s=x[3:len(x)-4].decode("utf-8");
						stat = x.decode("utf-8")[-3];
						s2 = status[stat];
						s += "_" + s2
						print(s +'\n')
						with open("megamart.log", "a") as log:
							log.writelines(s)
							log.write("\n")
		except (KeyboardInterrupt, SystemExit):
			raise
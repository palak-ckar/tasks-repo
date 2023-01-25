
<h1 align="center" style="font-weight: 1500;">	
	Self Test
</h1>

# 📝Pre-requisites 📝
* There should be no device connected to board (like Foot Switch, Laser Beam).
* TX and RX pins should be shorted beforing connecting.
* Serial Port baud rate must be set to 115200.
* All the previous data of the board must be killed.
* 

# :bulb: Overview :bulb:
This is Self Test for the POC which gives the overview of states of all the devices connected to the board i.e the driver settings of I2C bus.

- It consists I2C bus or  I²C bus which has the details of devices' name, its chip address, register's address, value, delay, register size and data size.
- At start there are 3 uart states that are considered, uart state (0x1), uart state (0x2) and uart state (0x4). 
- Then after the devices with its initial detatils are entered manualy (as the added namely, HDMI ADV7513(U4), HDMI ADV7513(U5), Temperature Sensor (MCP9800A1), Camera Bridge and LED driver. It also takes initial FPGA configuration and the required I2C configuration.
- Now the devices' states are checked and uart states are assigned to the devices accordingly. 
- For both the HDMI ADV7513, it assigns uart state 0x1 and 0x2 respectively.
	- Initially the I2C Bus assigned to 0x70 so that it selects HDMI encoder 
	- Then it points the value to 0x1 and 0x2 in MUX respectively, later it checks if the the address of data and the expected is same or not and shows "Pass" or "Fail" correspondingly. 
- For Temperature Sensor, Camera Bridge and LED Driver, the uart states assigned is 0x4. 
- For Temperature Sensor, it reads the value and assigns new value to Temperature Sensor by checking if register size is more than 1, if yes, it  and checks if the value is neither 0x00 nor 0xFF, it declares it as "Pass" otherwise "Fail". 
- After the present state of all the devices are recorded, uart initializes USBs' address in the board and baud rate 115200, then it checks for existence, if it exists, it shows "Pass" and proceeds to check if the message sent and received is same, it is considered as loopback "Pass" and if its not, it is considered as "Fail", and if the file is not found, existence and loopback both are displayed as "Fail".

And all of the data is stored in a file named "TestResult.log".


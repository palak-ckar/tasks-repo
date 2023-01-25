
<h1 align="center" style="font-weight: 500;">	
	Self Test
</h1>

# :bulb: Overview :bulb:
This is Self Test for the POC which gives the overview of states of all the devices connected to the board i.e the driver settings of I2C bus.

It consists I2C bus or  I²C bus which has the details of devices' name, its chip address, register's address, value, delay, register size and data size. At start there are 3 uart states that are considered, uart state (0x1), uart state (0x2) and uart state (0x4). Then after the devices with its initial detatils are entered manualy (as the ade namely, HDMI ADV7513(U4), HDMI ADV7513(U5), Temperature Sensor (MCP9800A1), Camera Bridge and LED driver. It also takes initial FPGA configuration and the required settings.

Now the devices' states are checked and uart states are assigned to the devices accordingly. For both the HDMI ADV7513, it assigns uart state 0x1 and 0x2 respectively also the initially the I2C Bus assigned to 0x70 so that it selects HDMI encoder and then it points the value to 0x1 and 0x2 of MUX respectively, later it checkes if the the address of data and the expected is same or not and shows "Pass" or "Fail" correspondingly. For Temperature Sensor, Camera Bridge and LED Driver, the uart states assigned is 0x4. For Temperature Sensor, it reads the value and assigns new value to Temperature Sensor and checks if the value is neither 0x00 nor 0xFF, it declares it as "Pass" otherwise "Fail". 

After the present state of all the devices are recorded, uart initializes USBs' address in the board and baud rate 115200, then it checks for existence, if it exists, it shows "Pass" and proceeds to check if the message sent and received is same, it is considered as loopback "Pass" and if its not, it is considered as "Fail", and if the file is not found, existence and loopback both are displayed as "Fail".

And all of the data is stored in a file named "TestResult.log".

# 🔍Annotation:mag:

## I2C bus or  I²C bus
Philips created the I2C bus in the early 1980s to make it simple for components that are housed on the same circuit board to communicate with one another. In 2006, Philips Semiconductors switched to NXP. I2C, the name, stands for "Inter IC."

I2C is used to connect components that are connected via cable in addition to being used on single boards. This bus is appealing to many applications because to its simplicity and adaptability.

The most important characteristics are:

• There are only two bus lines required.
	
• There are no strict baud rate specifications, and the master creates a bus clock.

• All elements have basic master/slave interactions. Software addresses each device connected to the bus with a different address.

• I2C is a genuine multi-master bus that offers collision avoidance and arbitration.

### I²C Terminology
>Transmitter: the device the bus receives data from. A transmitter can be a device that uploads data to the bus on its own (referred to as a "master-transmitter") or one that receives data requests from other devices (referred to as a "slave-transmitter").
>Receiver: the device that receives data from the bus.
>Master: The component that starts a transfer, creates the clock signal, and terminates the transfer. A master can function as both a transmitter and a receiver.
>Slave: the device addressed by the master. A slave can be either receiver or transmitter
>Multi-master: the capacity for multiple masters to share the bus at once without crashing or losing data.
>Arbitration: the predetermined procedure that only permits one master to take control of the bus at a time.
>Synchronization: the predetermined process used to synchronise the clock signals produced by two or more masters.
>SDA: data signal line (Serial DAta)
>SCL: clock signal line (Serial CLock)
### I²C Working
<1> gctdytdy

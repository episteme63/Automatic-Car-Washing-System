# Automatic Car-washing System
## Abstract

The project aims at building an automatic car washing system. Based on the user’s choice, one of the three types of car wash is selected and the car is washed accordingly as it is slowly steered towards the exit.

The three car wash options are as follows:
* Water only
* Water + Soap
* Water + Soap + Wax

It’s up to the user to either steer manually or to use the automated system.

The system comprises of four different booths/stations for different purposes:
* __Water Booth:__ Cleans the car using water only
* __Soap Booth:__ Cleans the car using soap
* __Soap+Wax Booth:__ Cleans the car using soap. Wax is used to add a final shine to the car.
* __Drying Booth:__ To dry the car using air jets.

The car wash system uses a main switch which can be turned OFF at any time (even in the middle of a wash, if there’s an emergency).

The project uses LEDs to demonstrate the workflow of the system.




## Components Used

* Arduino Uno &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;: 1
* RGB LEDs &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;: 2
* Red LED &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;: 1
* Resistors	&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;: 7
* Sliding Switch &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;: 1
* Ultrasonic Proximity Sensors &nbsp;: 4
* Potentiometer &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;: 1
* Connecting Wires 
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;: As per the circuit requirements

## Implementation

The project uses a sliding switch as the ON/OFF switch for the main power supply. Turning OFF the switch will disable the entire system immediately. The system continuously polls in a loop to keep track of the status of the sliding button. As soon as it finds out that the sliding button is in the OFF state, it disables the system. Turning ON the sliding switch starts the system from its initial state.

Suitable delays have been provided in the system to enable the user to enter his/her choice of car-wash, to steer the car towards the desired booth and to steer the car away from the booth. Ultrasonic proximity sensors have been used to detect the presence of a car at a particular booth. As soon as the car reaches in the two meter proximity of the sensor, the booth starts with its functionality. This has been demonstrated by the use of LEDs.

When the car exits, the car wash system begins a new cycle of washing for the cars standing in the queue. The system can be turned OFF using the sliding switch in case no other cars are present in the queue.


## Team Experience

The project provided the team with a chance to work in collaboration with
students. There was a sense of being separated by boundaries but being connected by common interests including the keenness to learn and explore diverse technologies. It was the first time our team worked with Arduino. The experience was fun, but challenging at times. Overcoming the obstacles together is what made the project even more enjoyable.

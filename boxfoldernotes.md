Components



Button\_Start



Button\_Home



Status\_LED



Ball Screw 1

&#x09;BS1\_Sen\_Home

&#x09;BS1\_Sen\_Engage



Ball Screw 2

&#x09;BS2\_Sen\_Home

&#x09;BS2\_Sen\_Engage



Ball Screw 3

&#x09;BS3\_Sen\_Home

&#x09;BS3\_Sen\_Engage



Actuator Right

&#x09;ActR\_Engage

&#x09;

Actuator Left 

&#x09;ActL\_Engage



Sensors





**Sequence** 



Button\_Start Pressed

&#x09;|

Status\_LED = Red

Ball\_Screw\_1 = Foward

&#x09;|	

BS1\_Sen\_Engage = HIGH

&#x09;Ball\_Screw\_1 = Stop

&#x09;Ball Screw 3 = Forward

&#x09;|

BS3\_Sen\_Engage = HIGH

&#x09;Ball Screw 3 = Stop

&#x09;Ball Screw 2 = Foward

&#x09;|

BS3\_Sen\_Engage = HIGH

&#x09;Ball Screw 3 = Backwards

&#x09;|

BS3\_Sen\_Home = HIGH

&#x09;Actuator Right = Foward

&#x09;Actuator Left  = Foward

&#x09;|

ActR\_Engage \&\& ActL\_Engage = HIGH

&#x09;Actuator Right = Backwards

&#x09;Actuator Left  = Backwards

&#x09;|

Ball Screw 3 = Forward

&#x09;|

BS3\_Sen\_Engage = HIGH

&#x09;Ball\_Screw\_2 \& Ball\_Screw\_3 = Backwards

&#x09;|

BS2\_Sen\_Home \&\& BS3\_Sen\_Home = HIGH

&#x09;Ball Screw 1 = Backwards

&#x09;|

BS1\_Sen\_Home = HIGH

&#x09;Status\_LED = Green





&#x09;



&#x09;



&#x09;		

&#x09;	

&#x09;	



&#x09;














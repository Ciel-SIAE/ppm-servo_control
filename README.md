# ppm-servo_control
使用arduino外部中断读取ppm脉位调制信号，只能将ppm信号接至外部中断引脚
使用宏定义确定舵机信号线引脚，程序中使用了左右副翼、襟翼，升降舵，方向舵，主推力，副推力，反推。
反推与副推力协同工作
襟翼受副翼混控，副翼受襟翼混控，方向舵受副翼混控，混控比例可以调整
使用这个程序的时候可能需要调整舵机反向
当然也可以指使用ppm信号读取部分

The ppm pulse position modulation signal is read using the arduino external interrupt, and only the ppm signal can be connected to the external interrupt pin
The macro definition is used to determine the servo signal line pin. the left and right ailerons, flaps, elevator, rudder, main thrust, secondary thrust, and reverse are used in the program.
Reverse works together with secondary thrust
The flap is controlled by mixed ailerons, ailerons is controlled by mixed flaps, rudder is controlled by mixed ailerons, and the mixed control ratio can be adjusted
When using this program, you may need to adjust the servo in reverse
Of course, it can also refer to using the ppm signal reading part

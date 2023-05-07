# Sumobots-2023

This repository stores and displays the embedded arduino code that operated our autonomous sumo-robot which competed in the McMaster Sumobots competition in 2023. In our first year of competing, our team placed **top 5** out of all teams in the competition.

The major electrical components used in this project were:
- Arduino Nano (The microcontroller that was programmed with the code in this repository)
- DC Motors (2)
- Motor Driver
- Ultrasonic Sensor (Was disabled via software in the final iteration of the design)
- IR Sensors (2)
- 9V Battery

The sumobot operated by moving forward at a user defined Speed until one of the IR sensors detect a change in colour, which indicates the edge of the arena. The sumobot then revereses and rotates depending on which IR sensor detected the change in colour, before moving forward once again. Although this is a basic design, our team learned a lot about what we can improve for future competitions.

Potential improvements:
- Using more battery power - this can allow us to generate more speed and torque from our motors as well as using more motors.
- Implementing the ultrasonic sensor - can use this sensor to detect other robots and react accordingly.
- Using system clocks instead of delays - this simple change can achieve the same effect as delays while allowing the microcontroller to continue other tasks.
- Implementing a better mechanical design - a design that can better house components as well as creating a better ramming surface would be beneficial.

You can take a look at how our robot functioned here --> https://drive.google.com/file/d/1FDjNSM1phUqJT1vYH096QxPDVLP13Tb5/view?usp=share_link

---

Pictures of our design process and final product:

![image](https://user-images.githubusercontent.com/48258080/236705929-75d8ce9d-b75e-4421-9612-5a21aa0d25ac.png)

![image](https://user-images.githubusercontent.com/48258080/236705950-33718229-eaea-46e6-89f8-4293f383647d.png)

![image](https://user-images.githubusercontent.com/48258080/236705965-aaba7377-5201-437a-9427-8cc9f6736411.png)

![image](https://user-images.githubusercontent.com/48258080/236705973-9d8ac097-cdc1-4f60-8a15-ee07691c2fb4.png)

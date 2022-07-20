# **Traffic Light System**

> Using TivaC tm4c123gh6pm as the micro-controller, IAR as the debugging tool.

<hr>
<br>

## **1.0 Components Needed**

1. Green LEDs x4
2. Yellow LEDs x2
3. Red LEDs x4  

<br>

### **1.1 Connection and wirings**

| Component | Port |  Traffic North-South  | Traffic East-West |
|:----------|:----:|:---------------------:|------------------:|
| Ped Button| **GPIO Port F** | Pin 0 | Pin 4 |
| Ped Red   | **GPIO Port C** | Pin 5 | Pin 7 |
| Ped Green | **GPIO Port C** | Pin 4 | Pin 6 |
| Car Red   | **GPIO Port A** | Pin 4 | Pin 7 |
| Car Yellow| **GPIO Port A** | Pin 3 | Pin 6 |
| Car Green | **GPIO Port A** | Pin 2 | Pin 5 |

<br>

## **2.0 Timers Roles and Configuration**

| Timer | Function |
|:----------|------------------:|
| Timer 1 | Car Traffic Timer |
| Timer 2 | Pedestrian Timer  |

<br>

### **2.1 Timers Configuration**

| Timer | Configuration |  Priority  | Interrupt |
|:----------|:----:|:---------------------:|------------------:|
| Timer 1 | Periodic | 0x30 | Timeout |
| Timer 2 | Periodic | 0x10 | Timeout |

<br>

## **3.0 System Flowchart**

<br>

![Logic Flowchart](EmbeddedSystemFlowchart.png)

<br>

## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License

[MIT](https://choosealicense.com/licenses/mit/)

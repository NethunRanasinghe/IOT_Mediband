# IOT_Mediband

# User guide
• This IOT medical band compromises of several sensors and this Medi band should be worn by the elders 
on their wrist.
• The band contains sensors that measure users’ blood oxygen level, heart rate, temperature and detect the 
fallings.
• The medical band should be charged before use by using the charging cable.
• The band will regularly notify the vital signs and make an alert when an abnormality occurs.
• The readings taken from the medical band can be viewed using the admin panel. Measurements taken 
from Medi band of each elder is shown separately in the admin panel.
• If a fall happens the medical band would make a beep sound. if that sound occurred due to a mistake, 
click on the button on the medical band.
• When maintaining the medical band keep it clean and dry. Do not be exposed to high temperatures and 
water.
• The elder’s personal data will be secured in throughout this entire process
## Scope
The IOT Medi band is designed to monitor the heart rate, blood oxygen level and temperature of elders in elderly homes
and if the reading from the device is abnormal the healthcare providers get a quick alert. Also, if an elder falls the Medi
band detects it and a beep sound will be generated from the device so that healthcare providers can get quick actions.
The system will use wireless communication to transmit the data to a centralized server for storage and analysis. 
Also, the system will be user friendly, so that the elderly can use and wear the medical band easily and caregivers can 
view the health data that is monitored through a user- friendly interface.
Proposed System
The proposed system is a medical band that is worn in elders' wrist that monitors elders blood oxygen level, heart rate and 
temperature regularly. The readings of the Medi band get transmitted to the admin panel where the healthcare providers 
can view at real-time and if there are any abnormal readings the healthcare providers get notified.
The band will use Wi-Fi and GSM technology to communicate with a gateway device that will be connected to a 
centralized server. The server will receive, store, and analyze the data collected by the band.
(Ullah et al., 2016)

## Objectives
(Baker et al., 2017) Additionally, it aims to reduce healthcare costs by reducing the need for frequent hospital visits, 
ensure to take quick actions in saving the elders lives and maintaining their health. Below are some objectives we are 
focusing on:
● To design an IoT medical band for elderly residents living in assisted living facilities or elderly houses.
● To develop a system that can monitor vital signs in real-time and alert healthcare providers in case of 
emergencies.
● To improve the response time to emergencies and reduce the risk of complications or adverse events.
● To enhance the quality of life for elderly residents by providing continuous monitoring of their vital signs.

## Limitations
The IoT medical band is more beneficial, but the medical band also has some limitations like:
● Need a secure and stable network connection to transmit data.
● The medical band only recognizes the readings and does not provide any treatments.
● The devices should need maintenance in order to get accurate readings.
● Additionally, the device's accuracy may be affected by factors such as patient movement, environmental 
conditions, and device placement. It is also essential to ensure patient privacy and data security, given the 
sensitive nature of health data.

Project Solution
As a solution to the problem arose about elderly people, the idea is to develop a Medi band and here is the project 
solution.
The medical band created comprises of a heart rate sensor, accelerometer, and a gyroscope.(Nagpal and Chaudhary, 
2020)
The Wi-Fi capabilities of the NodeMCU are used to communicate with the firebase server and as a backup, the GSM 
module is used.
The heart rate and blood oxygen level are measured within every 10s and that is sent to the firebase. This collected 
information is shown in the admin panel of our Medi band. If those parameters are fluctuated and out of range, the user 
behind the screen will be alerted.
The MPU-6050 module which houses the accelerometer and gyroscope runs almost all the time and the data is sent 
through a fall algorithm. If a fall is detected through the algorithm, an alert will be shown in the admin panel and the Medi
band starts beeping. The buzzer module is used for this purpose. To stop the beeping sound, the user must press one of the 
two buttons on the side of the watch.
The SIM-800L GSM module acts as a backup method to connect to the server when the device is out of range of Wi-Fi. 
The other button which is built in the watch is an emergency button. This button is intended for elders use and once it’s 
pressed, an immediate alert message will be sent to the web app so that necessary action can be taken. 
Lithium battery charger module is used to charge the battery while the DC-DC step-up converter is used to deliver the 
required voltage to the system

# Hydronalix WiFi telemetry diagnostics thing

a simple way of connecting to a USV to see onboard telemetry data

## hardware overview

* arduino nano 33 IoT (includes ublox NINA-W102 onboard)  
* microSD slot connected to arduino's SPI line  
* mag switch  
* other peripherals (TODO)  

## TODO
* port ESP32 webserver (including POST/GET functionality)
* port teensy SD functionality to arduino   
* creat sysdiag (for here!) and write/port peripheral code   

## other ideas n stuffs
* ability to download logfiles from SD over WiFi  
* cloud connectivity via cellphone or some other WAN when not being used as a webserver       

# Hydronalix WiFi telemetry diagnostics thing

a simple way of connecting to a USV to see onboard telemetry data. in short, the board acts as a WiFi access point from which the user can connect to view a basic webpage that:   
* displays vehicle health and lifetime data    
* accepts client input for configuration   

and, if it's reasonable:   

* allows simple file transfer   
* connects to greater WAN networks to relay health stats to a cloud server, to track asset statuses (!!!)

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

## Current state of things (charlie: 9-30-22)
* the main.cpp is one of the example programs in the WifiNina_generic library 
* currently, the program does not work for the hardware (Nano 33 iot)
* I have attemoted to update the firmware for the arduino using the arduino IDE but was getting errors there as well
* this Forum post suggests that my problem could be with the board instead of the software: https://forum.arduino.cc/t/arduino-nano-33-iot-nina-module-not-working/702029

## Current state of things (charlie: 10-6-22)
* the main.cpp creates a web server that displays analog reads
* I have switched from the WiFiNINA_Generic library to just the WiFiNINA library
* This library works well in the arduino ide but has yet to be downloaded into this project (thus why we have errors)
* going foreward, I am looking into file transfer (the user can download a log file) and looking in to how to improve the look of the website

# Gearbox Embedded C Project Documentation

## Overview

The Gearbox Embedded C project is an educational endeavor that simulates the control of a car gearbox using an Atmega32 microcontroller and a prebuilt kit from FARES company. This project is designed to provide hands-on experience in embedded systems programming and control while emphasizing SPI and I2C communication between two kits.

## Purpose and Objectives

The main purpose of this project is twofold:

1. **Educational**: It offers an interactive learning experience in embedded systems by emulating a car's gearbox control system, using an Atmega32 microcontroller and a FARES kit as the hardware platform.

2. **Communication**: The project emphasizes the use of SPI (Serial Peripheral Interface) communication between two FARES kits—one acting as the master and the other as the slave. Additionally, the slave kit utilizes I2C communication to store readings from the master in an external EEPROM.

## Hardware Setup

The project employs a prebuilt kit from FARES company, comprising an Atmega32 microcontroller, LCD, keypad, sensors, LEDs, a buzzer, and an external EEPROM. The master and slave kits are interconnected using SPI for data exchange, while the slave kit employs I2C to store readings in the external EEPROM. Detailed connection information is documented following FARES kit instructions.

## Software Architecture

The firmware follows a structured state machine design, with modules for initialization, state handling, speed control, user interface, error handling, and robust communication protocols for SPI and I2C.

## Main Features

- **State Transitions**: The system seamlessly transitions between parking, reverse, normal, and drive modes based on user input and speed conditions.

- **Speed Control**: Users can monitor and control the virtual vehicle's speed, with the ability to set and enforce speed limits.

- **User Interface**: An LCD display, keypad, LEDs, and a buzzer provide a user-friendly interface for mode selection and feedback.

- **SPI Communication**: SPI is utilized for real-time data exchange between the master and slave kits, enabling dynamic control and synchronization.

- **I2C Data Storage**: The slave kit employs I2C to store readings from the master kit in an external EEPROM, allowing for data persistence.

## Achievements and Future Enhancements

This project successfully achieves its educational goals by providing a practical platform for learning embedded systems programming and advanced communication protocols. Future enhancements may include more realistic features like real motor and feeback, advanced control logic, and expanded user interaction.

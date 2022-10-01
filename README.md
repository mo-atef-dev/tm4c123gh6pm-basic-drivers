# About The Project
This project includes limited-functionality GPIO, Timer, System Clock, and Interrupt Control MCAL (Microcontroller Abstraction Layer) drivers for TM4C123GH6PM microcontroller.
It is a project for Udacity's Advanced Embedded Systemd Nanodegree. It's purpose is for practicing MCAL driver development.

![Udacity](https://img.shields.io/badge/Udacity-grey?style=for-the-badge&logo=udacity&logoColor=15B8E6)

## What's missing
The project includes the necessary drivers to implement a simple blinking LED. Not all timers or GPIO ports are available.

The source code itself includes many comments on improvements and changes. However, here is a list of general to-dos in the project:
* Add the remaining GPIO ports
* Add the remaining timers
* Add functionality of external interrupts in the GPIO modules
* Add more documentation for the existing code

## Built with
* Keil uVision Version 5.29.0.0
* C ARM Compiler Version 5

# License

Distributed under the CC BY license. Click [here](https://creativecommons.org/licenses/by/4.0/legalcode) for more info.

# Usage

Since this project was inteded for practice, I recommend using something else for any professional project. For example TivaWare<sup>TM</sup> for C by Texas Instruments.

However, if you would like to practive building drivers or contributing to embedded open source projects, feel free to use this project and contribute to it.

For any driver module:

1. Include the `module.h` header file where you want to use the module
2. Add the `module.c` and `module_lcfg.c` (if it exists) files to your project's files (add them to your build targets)
3. If included for the module, adjust the `module_cfg.h` and `module_lcfg.c` files to configure the usage of the module

# Contact

Mohamed Atef: mohamed.a13121998@gmail.com

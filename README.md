# ECE425 Final Project: Music Box
By Daniel Garcia Aguilar, Robert Rabenkogo Eboulia

# Introduction
The goal of this project was to make an interactive music box on the TI Tiva C Series TM4C123G LaunchPad microcontroller. Since a lab using PWM was never assigned, this project focused on exploring the uses of the PWM peripheral to make music on a piezo buzzer and continuously rotate a servo motor.

# Results and Demonstration
Demo 1: [Link](https://drive.google.com/file/d/1T5pxUfvi3W3InM9c5HguzuPJiNheqQb0/view?usp=drive_link)

Demo 2 (finished): [Link](https://drive.google.com/file/d/1nxUjzGBz65-bJfV2DZHi0vryzcIjvpkl/view?usp=drive_link)

# Background and Methodology
GPIO

The general-purpose I/O blocks provide both inputs and outputs for external hardware. One set of GPIO pins (PA2-PA5) are configured as inputs to read the PMOD button module. A separate GPIO pin (PC4) is used to drive the digital output to turn the buzzer on and off, along with generating the square-wave sounds that produce the melodies chosen.

PWM

The TM4C123GH6PM's PWM generator is used to animate the servo motor. By routing M0PWM0 to the PB6 pin and dividing the system clock, the PWM peripheral creates a constant-frequency pulse train whose duty cycle determines the position of the servo motor. By changing this value in an ISR, we can continously sweep the servo back and forth.

Timers

By setting up a periodic interrupt at 1kHz using Timer0A, the ISR can increase or decrease the servo's duty cycle up or down by a small amount each millisecond, creating a back and forth sweep that is slow and smooth, whilst not interfering with the main loop or buzzer timing.

This project was able to successfully use GPIO interrupts while simultaneously polling to detect button presses, timers to update the servo sweep, PWM to drive the servo and generate sounds, and put this all together to create an interactive music box.

# Block Diagram
![Image](https://github.com/user-attachments/assets/a32d1805-b2aa-4714-bec5-a678b6cb1afe)

# Components Used
![Screenshot 2025-05-02 at 7 30 47 PM](https://github.com/user-attachments/assets/b24c14c9-0f8e-414a-b901-ab8be7d9e706)

# Pinout
![Image](https://github.com/user-attachments/assets/8d1d2326-209b-45ec-900f-7db861d1a693)

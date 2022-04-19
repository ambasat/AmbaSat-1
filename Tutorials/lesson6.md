
![](https://i.postimg.cc/Gm7SsT69/Screenshot-2022-02-23-at-13-58-36.png)
## Introduction
Okay, you have got your Ambasat-1 board set up and also figured out how to transmit programs to the board using VSCode. Good job!

However... just running example programs is a bit boring. Let's do something more interesting; in this lesson, you will learn to use your imagination and create your very first satellite firmware.

## Requirements
 -  Ambasat-1 Satellite
 [![Ambasat-1](https://ambasat.com/wp-content/uploads/2020/06/AmbaSat-1-Assembled-350.jpg "Ambasat-1")](https://ambasat.com/wp-content/uploads/2020/06/AmbaSat-1-Assembled-350.jpg "Ambasat-1")
 - USB programmer
 ![](https://ambasat.com/howto/images/s-l640-300x300.jpg)

In case you haven't set up your coding environment yet, you can complete this tutorial using the [Arduino Online Simulator](https://wokwi.com/projects/new/arduino-unohttp:// "Arduino Online Simulator")


## What is a program?

A program is a set of instructions that a computer follows in order to perform a particular task. There are multiple languages available to developers, each one of them is suited for specific applications. In the embedded field the most common languages used are C and C++. Other languages you may have heard of are **Python**, **Java**,, or **C#**. 

An Ambasat-1 source code or also called sketch( because of the Arduino framework) is composed of two main parts: setup code and a loop code.

### Setup  
- Executed immediately after power-up or reboot.
- It is where all the initializing code must be put, e.g., variables, pin modes, or libraries.

### Loop
- Executed after the setup function.
- Executed repeatedly, that is why the name 'Loop.'
- It is where the main task of the program gets executed.

### Example
```c
#include <Arduino.h>

// put your setup code here, to run once:
void setup() {
  Serial.begin(9800); // Initialize the Serial comunication, 9800 is the baudrate
  Serial.println("Setup code"); // Print the massage through the serial line
}

// put your main code here, to run repeatedly:
void loop() {
  Serial.println("loop code");
}
```
Let's try it yourself, copy and paste this code on  https://wokwi.com/projects/new/arduino-uno. Then, click the run button to start the simulation. What is the output?

As you can see, the line "Setup code" is printed only once at the begging. On the other hand, the line "loop code" is printed several times. Be aware that both functions setup() and loop() **MUST** be included in every program you write.

You have probably  noticed that the code has differen coloring and shading. These hints makes the code more easy to read and understand. Let's have a look at the main parts of the program.

To include a library, we use the keyword: `#include` followed by `<nameofthelibrary.h>`. In the example, we wrote `#include <Arduino.h>` to import the Arduino framework. Ignore for now what a framework is. Just think of it as the underlying layer that does the dirty work for us.

Notice that there are some plain English sentences in the code; those are called comments. We use comments to describe what the code is doing so that the other developers can understand more easily our code. We use a double slash followed by the comment itself to create a comment in C/C++.

    //This is a comment!

**Setup** and **Loop** are commonly called functions. You can think of functions as a collection of statements. We use a function to group statements together so that we can dynamically refer to them without having to rewrite them every time. Picture a function as a to-do list or a list of procedures that are executed in order.

    // put your main code here, to run repeatedly:
    void loop() {
      Serial.println("loop code");
    }
This one is a bit more complicated example. It looks scary, doesn't it? A function can optionally receive input values. In this case, *mysterious_fun* requires two numbers, **x** and **y**. Can you guess what the function does with these two parameters?

    void mysterious_fun( int x, int y)
    {
    	Serial.println(x+y);
    }

Try to execute the following code, what does it print?
    #include <Arduino.h>
    
    void setup() {
      // put your setup code here, to run once:
      Serial.begin(9800); // Initialize the Serial comunication, 9800 is the baudrate
      Serial.println("Setup code"); // Print the massage through the serial line
    }
    
    void loop() {
      // put your main code here, to run repeatedly:
      Serial.println("Hello");
      sum(5,2);
    }
    
    void mysterious_fun(int x, int y)
    {
      Serial.println(x+y);
    }

At this point, you might be asking yourself, "what is void?" Well, that is a fancy way of saying **nothing**. Technically it means that the function doesn't return anything. This implies that we can write a function that returns something, but that is a lesson for another day.
### Quiz Time

It is time to test what you have learned so far! (Don't worry, you won't be graded)

#### What is this line of code:
        // put your setup code here, to run once:
1. A keyword
2. A single line comment
3. A function definition
4. A cup of tea


#### What is this line of code 2:
    void loop() {
    	Serial.println("Hello Students!");
    }
1.  A statement
2.  A single line comment
3.  A function definition
4.  A banana

## Light the board up

Ok, now that you have a better understanding of what a program is, let's experiment with something more practical. In the following example, we are going to make our first LED blink! Don't worry, you don't need anything else than your Ambasat board. However, you can always spice things up and use an external Led along with the appropriate resistor.

### About LED
A light-emitting diode is an electronic component that emits light when current flows through it. It has two pins:
- Cathode (- pin) needs to be connected to GND (0V).
- Anode (+pin) is used to control LED status.

For most LEDS we must use a resistor to protect the LED. We place a resistor between the Anode (+) and the VCC(+5V). The value of the resistor depends on the specification of the LED. To control the status of the LED we connect the anode(+) to a digital pin so that we can dynamically change the pin output.

[![](https://i.ibb.co/sRKDYrF/Screenshot-2022-02-27-at-19-48-05.png)](https://i.ibb.co/sRKDYrF/Screenshot-2022-02-27-at-19-48-05.pnghttp://)
### Write the code
First, we must decide which digital pin we are going to use. For simplicity let's stick with the Ambasat onboard status LED which is connected to digital pin 9.
```c
#define INTERNAL_LED 9
```

Secondly, we must configure the pin status. There are two possible configurations; Input in case we are interested in reading the pin voltage; Output in case we are interested in controlling the pin output voltage. Obviously, we are interested in the latter, so we configure the INTERNAL_LED as Output:
```c
pinMode(INTERNAL_LED, OUTPUT);

```
Lastly, to control the LED status we use the following command
```c
digitalWrite(INTERNAL_LED, High or Low);
```
The following is an example of the LED blinking, try it yourself!
```c
#define LED 13

// put your setup code here, to run once
void setup() {
  // initialize digital pin LED as an output.
  pinMode(LED, OUTPUT);
}

// put your main code here, to run repeatedly:
void loop() {
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED, HIGH);
  // wait for 1 second
  delay(1000);
  // turn the LED off by making the voltage LOW
  digitalWrite(LED, LOW);
  // wait for 1 second
  delay(1000);
}
```

 Now get you hands dirty, try to change the delay, what happened?
### Quiz Time 2
#### What does this line of code do:
       digitalWrite(LED, HIGH);
1. Digital write something
2. Turn the LED off
3. Reset the board 
4. Turn the LED on


#### What does this line of code do:
    delay(1000);
1.  Wait for 1000ms (1 second)
2.  Turn the LED on
3.  Write "hello" into the serial output
4.  Reset the board

### Exercise
Time to test your knowledge with some practical exercises! Try to complete as many as you can.

#### Change the example code so that the light is on for 500 milliseconds and off for 500 milliseconds. 


#### Change the example code so that the light is on for 50 milliseconds and off for 50 milliseconds. What happens?

#### Build a simple LED circuit and try to make this LED blink instead of the internal one. What line of code do you need to change?

#### Using the example code as a starting point, build a Blink SOS signal in Morse code.	
Tips:
- Morse code Alphabet is composed of just two basic signals - dots and dashes. The dot represents a quick and rapid signal. Dashes, on the other hand, represent a slow signal.
- SOS in Morse code is 3 dots - 3 dashes - 3 dots.
- How can we differentiate between dots and dashes with a LED? In a very simple way, by changing the time spent blinking.
- As general rule dashes should be three times longer than the dots.
- The timing between dots and dashes should be the length of a dot.
- To make the signal more clear, the pause between letters should be the same length as your dash blinks.
  





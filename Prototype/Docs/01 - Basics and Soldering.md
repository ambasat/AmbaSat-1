# 01 - Basics and Soldering

## Overview
The main piece that makes up the AmbaSat-1 is the printed circuit board. (PCB) This is a manufactured circuit board that routes all of the necessary connections to the different components on the board. When assembling the AmbaSat-1 board it’s import to pay attention to each component (the type and value) and make sure that it’s placed in the proper location. Each component has a dedicated place on the board, which is denoted by designators. These designators are the letters and numbers next to the pads where you need to place the component. You can reference the part and the associated designator located on the BOM. (Bill of Materials)

## Type of Solder
If you are planning to assemble the board there are few things to take into consideration. First, which type of solder is used. There are 2 main choices; leaded or lead-free solder. As one would expect, one has lead and the other doesn’t. This really matters for 2 reasons. First, solder with lead in it is considered to be toxic. So if you decide to use leaded solder make sure that you are in a well ventilated space or have vent fan. Leaded soldered components will not be [RoHS](https://en.wikipedia.org/wiki/Restriction_of_Hazardous_Substances_Directive) compliant, which only matters if you plan to sell them. Second, the melting temperature is also different and slightly lower with leaded solder. Leaded solder is (arguably) easier to work with and is more readily available. The choice is up to you and both will work for assembling the board. (Don’t forget the flux!) 

## Solder by Hand
If you are planning to solder these by hand, use a soldering iron or a hot air tool. It’s a good rule to start with the more complex components (like the MCU) that are in the middle of the board and work your way outwards. QFN packages (like the gyroscope chip) can be almost impossible to solder without a hot air tool or reflow oven. Everyone has their own strategy and you’ll need to find a method that works best for you. 

## Reflow
The other main method for assembling PCBs is to use a reflow oven, which solders all of the components at the same time. This is how all professional boards are manufactured. However, commercially available reflow ovens are pretty expensive and likely too pricey for assembling a single AmbaSat-1. There is an alternative and that is to make your own reflow oven out of a toaster oven and a temperature controller. I have done this and it works surprisingly well. The temperature controller I've used is the [Tiny Reflow Controller](https://www.rocketscream.com/blog/product/tiny-reflow-controller-v2/) by Rocket Scream. If you decide to go this route, there’s more [good info here](https://www.rocketscream.com/blog/docs-item/tiny-reflow-controller/). 

Like mentioned above, if you use a reflow oven you will need to pay attention to which solder type that you use. This is mainly for choosing the right solder profile. A solder profile is a series of steps (temperatures + length of time) that the oven needs to follow in order to have a successful reflow and not damage the PCB or any of the components. 



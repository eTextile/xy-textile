# XY-textile
#### Transforming textiles into an intuitive way to interact with computers.
#### This project is part of an electronic textiles research on HCI gesture interaction that was started in 2005.
- Credit: Maurin Donneaud <maurin@etextile.org>
- Repository: https://github.com/etextile/xy-textile
- Pictures: https://www.flickr.com/photos/maurin/albums/72057594109318453

![Picture](https://farm1.staticflickr.com/151/415702494_c5f5f388be_o_d.jpg)

## About the project
The XY-textile is a large textile interface use to compose and play electronic music. By its size, its texture, its flexibility and its transparency, this textile interface involves the whole body in the musical interpretation. Like a music score, the graphics represented on the fabric, give to the composer the ability to locate and play every sounds and sound controls. Thus, for each piece of music, a graphic partition is carried out. The idea behind this project is also to develop an opposite approach to a classical process (from graphic towards the sound). Created in collaboration with graphic designers and composers, theses multisensory interfaces enable the exploration of sound through textile.

## Hardware
This smart textile is made out of two conductive fabrics, each one containing conductive lines oriented in opposite directions.
When a pressure is apply on this structure, the two fabrics connect and the electronic sens the touch position.

![Schematic](https://farm1.staticflickr.com/176/429687135_4d1ef7704b_o_d.gif)

## Firmware
To get the XY coordinates the firmware perform a two time sensing algorithm.
Eatch sequence sens a value that cotrespond to X or Y finger position.
This principle can be illustrated by the following schematics:

![Schematic](https://github.com/etextile/xy-textile/blob/master/docs/Schematic.gif)

## Software
This project contain a PureData driver

## Copyright
Except as otherwise noted, all files in the XY-textile project folder

    Copyright (c) 2014-2018 Maurin Donneaud and others.

For information on usage and redistribution, and for a DISCLAIMER OF ALL
WARRANTIES, see LICENSE.txt

# 8 Bit R-2R Dac
This board is a simple R-2R DAC paired with an amplifier based on a LM386. The amplifier circuit is based on the 20db gain circuit found in on the LM386's [datasheet](./lm386.pdf).

# BOM
See bom [here](./BOM.csv).

# Schematic
![schematic](./8bit-r2r-dac-schematic.svg)

# PCB
![pcb](./8bit-r2r-dac-pcb.svg)

# Arduino Driver Sample Code

A very basic function generator sketch that uses a timer interupt to generate a triangle wave and port registers to output to the DAC. View [here](./TriangleWaveGenerator/TriangleWaveGenerator.ino).

# License
This project is under the MIT license. It can be found [here](./LICENSE).

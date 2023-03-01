# NanoTekSpice

Second-year Epitech project in Cpp.

## Project
NanoTekSpice is a logic simulator that builds a graph (the nodes of which will be simulated digital electronic
components, inputs or outputs) from a configuration file, and injects values into that graph to get results.
* example of a chipset: Basic AND logic gate
```txt
in_1  -1-+---\
         | &  |-3- out
in_2  -2-+---/
```
* example of a chipset: 8 Channel Data Selector (4512)
```txt
         in_3 -4-+ +-5- in_4
       in_2 -3-+ | | +-6- in_5
     in_1 -2-+ | | | | +-7- in_6
   in_0 -1-+ | | | | | | +-9- in_7
           | | | | | | | |
         +-v-v-v-v-v-v-v-v-+
         |                 |
in_a -11->                 <-10- inhibit
         |                 |
in_b -12->                 |
         |                 |
in_c -13->                 <-15- enable
         |                 |
         +-4512---v--------+
                  |
                  +-14- out_data
```

### Truth table

Here's the AND, OR, and XOR gate’s `truth table`:

| A | B | AND | OR | XOR |
| - | - |  -  |  - |  -  |
| 0 | 0 |  0  |  0 |  0  |
| 0 | 1 |  0  |  1 |  1  |
| 1 | 0 |  0  |  1 |  1  |
| 1 | 1 |  1  |  1 |  0  |

The project introduce the `Undefined` state, which is an addition to `true` or `false`, and here's the `thruth table` with the updated state:

| A | B | AND | OR | XOR |
| - | - |  -  |  - |  -  |
| 0 | 0 |  0  |  0 |  0  |
| 0 | 1 |  0  |  1 |  1  |
| 0 | U |  0  |  U |  U  |
| 1 | 0 |  0  |  1 |  1  |
| 1 | 1 |  1  |  1 |  0  |
| 1 | 1 |  1  |  1 |  0  |
| U | 0 |  0  |  U |  U  |
| U | 1 |  U  |  1 |  U  |
| U | U |  U  |  U |  U  |

### Configuration file

The program takes a configuration file, with the components (defined after the `.chipsets:` line), and the links between components (defined after `.links:` line).
The file can have commentaries at the beginning or during a line, starting with an `#` and ending at a newline.
They may look like this:
```txt
# Basic XOR logic gate
#
# in_1  -1-+---\
#          |xor |-3- out
# in_2  -2-+---/

.chipsets:  # line defining the chipsets
input in_1
input in_2
output out
xor gate

.links:
in_1:1 gate:1
in_2:1 gate:2
out:1 gate:3
```
If there's an error in the config file, the program print the error and return `84`.

### Loop
Your simulator must be able to run with a circuit file passed as parameter. The simulator also reads the
standard input for the following commands:
| Command     | Action |
| -------     | ------ |
| exit        | closes the program. |
| display     | prints the current tick and the value of all inputs and outputs the standard output, each sorted by name in ASCII order. |
| input=value | changes the value of an input. Possible value are 0, 1 and U. This also apply to clocks. |
| simulate    | simulate a tick of the circuit. |
| loop        | continuously runs the simulation (simulate, display, simulate, . . . ) without displaying a prompt, until SIGINT (CTRL+C) is received. |

Between commands, the program must display “>” as a prompt.\
When printing a value, if it is undefined, your program must display "U". (without the quotes)\
When it reaches the end of its standard input (ever heard of CTRL+D?), the program must stop with status 0.

Here's a sample execution:
```sh
∼/B-OOP-400> cat -e or_gate.nts
.chipsets:$
input a$
input b$
4071 or$
output s$
.links:$
a:1 or:1$
b:1 or:2$
or:3 s:1$
∼/B-OOP-400> ./nanotekspice or_gate.nts
> b=0
> a=1
> simulate
> display
tick: 1
input(s):
a: 1
b: 0
output(s):
s: 1
> exit
∼/B-OOP-400> echo $?
0
```

## How to build and execute project

This project is compiled using a CMakeLists.txt. To build project, you have to create a build directory to put all the files produced by cmake (cleaner):
```sh
$> mkdir build && cd build
```
and then executing the CMake, either to create a Makefile:
```sh
$> cmake .. # a Makefile is created, with the rules all clean fclean re
$> make
```
or build with `ninja` (Small build system with a focus on speed):
```sh
$> cmake .. -GNinja -DCMAKE_BUILD_TYPE=Build
$> ninja
```
Both ways will produce a `nanotekspice` executable in the build folder, which is executed with the following arguments:
```sh
$> ./nanotekspice [config_file]
```


## Authors
* [Luka Camus](https://github.com/Lukacms)
* [Louis Bassagal](https://github.com/LouisBassagal)

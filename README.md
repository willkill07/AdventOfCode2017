# Advent of Code - 2017

All implementations are written in C++, adhering to C++17 guidelines.

## Prerequisites

* clang (>= 5.0)
* libc++ (>= 5.0)
* CMake (>= 3.8)
* macOS or Linux (only two systems I've tested on)

## Compiling

* A `compile.sh` script is provided
* Just run it and it should be good to go!

## Running

* Invoke `./Advent` to execute all the days
* To run a specific day, invoke `./Advent -f <dayXX>`
* To run a specific part, invoke `./Advent -p <1,2>`
* To see more detailed help, consult `./Advent --help`

## Metrics

* Lines: Number of lines given by `wc`
* Code: `Lines` - `(# preprocessor lines)` - `(lines with no alphanumeric chars)`
* Bytes: Number of total characters
* Chars: Number of non-whitespace characters
* Time: Time in milliseconds to execute each part independently (separate runs)
* Source: link to implementation
* Headers: C++ includes used for solution

## Leaderboard Highlights:

*To be determined*

## Detailed Information

 Day | Lines | Code | Bytes | Chars | Time (ms) | Source | Headers
:---:|:-----:|:----:|:-----:|:-----:| ---------:|:------:|:-------
01|18|11|446|356|`0.2041`|[Day01.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day01.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) `vector`
02|29|16|693|501|`0.2351`|[Day02.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day02.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) `algorithm` `iterator` `sstream` `vector`
03|59|42|1470|1041|`0.0495`|[Day03.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day03.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) `array` `cmath` `unordered_map`
04|25|13|618|474|`3.0764`|[Day04.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day04.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) `algorithm` `iterator` `numeric` `set` `sstream`
05|21|12|461|364|`76.2612`|[Day05.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day05.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) `algorithm` `iterator` `vector`
06|19|11|582|488|`16.5440`|[Day06.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day06.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) `algorithm` `map` `vector`
07|99|72|2441|1926|`24.4789`|[Day07.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day07.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) `regex` `sstream` `vector` `unordered_map`
08|27|16|919|758|`1.9345`|[Day08.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day08.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) `algorithm` `unordered_map`
09|8|3|108|94|`0.0003`|[Day09.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day09.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp)
10|8|3|108|94|`0.0002`|[Day10.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day10.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp)
11|8|3|108|94|`0.0002`|[Day11.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day11.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp)
12|8|3|108|94|`0.0002`|[Day12.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day12.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp)
13|8|3|108|94|`0.0002`|[Day13.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day13.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp)
14|8|3|108|94|`0.0002`|[Day14.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day14.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp)
15|8|3|108|94|`0.0002`|[Day15.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day15.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp)
16|8|3|108|94|`0.0002`|[Day16.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day16.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp)
17|8|3|108|94|`0.0002`|[Day17.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day17.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp)
18|8|3|108|94|`0.0002`|[Day18.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day18.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp)
19|8|3|108|94|`0.0002`|[Day19.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day19.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp)
20|8|3|108|94|`0.0002`|[Day20.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day20.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp)
21|8|3|108|94|`0.0002`|[Day21.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day21.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp)
22|8|3|108|94|`0.0002`|[Day22.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day22.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp)
23|8|3|108|94|`0.0002`|[Day23.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day23.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp)
24|8|3|108|94|`0.0002`|[Day24.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day24.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp)
25|8|3|108|94|`0.0001`|[Day25.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day25.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp)
**TOTAL**|**433**|**244**|**9466**|**7506**|**122.787**| |`  Solution.hpp`&nbsp;<sup>**`25`**</sup> ` vector`&nbsp;<sup>**`5`**</sup> ` algorithm`&nbsp;<sup>**`5`**</sup> ` sstream`&nbsp;<sup>**`3`**</sup> ` unordered_map`&nbsp;<sup>**`3`**</sup> ` iterator`&nbsp;<sup>**`3`**</sup> ` set`&nbsp;<sup>**`1`**</sup> ` array`&nbsp;<sup>**`1`**</sup> ` numeric`&nbsp;<sup>**`1`**</sup> ` regex`&nbsp;<sup>**`1`**</sup> ` cmath`&nbsp;<sup>**`1`**</sup> ` map`&nbsp;<sup>**`1`**</sup> ` `

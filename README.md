# Advent of Code - 2017

All implementations are written in C++, adhering to C++17 guidelines.

## Prerequisites

* clang (>= 4.0)
* libc++ (>= 4.0)
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
01|24|14|615|471|`0.5518`|[Day01.cpp](https://github.com/willkill07/AdventOfCode2016/blob/master/src/Day01.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) `cmath` `set` `utility`

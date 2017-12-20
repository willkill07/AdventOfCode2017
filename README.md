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
01|18|11|446|356|`0.4840`|[Day01.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day01.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) `vector`
02|29|16|693|501|`0.4929`|[Day02.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day02.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) `algorithm` `iterator` `sstream` `vector`
03|59|42|1490|1059|`0.3191`|[Day03.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day03.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) `array` `cmath` `unordered_map`
04|25|13|618|474|`3.3955`|[Day04.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day04.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) `algorithm` `iterator` `numeric` `set` `sstream`
05|23|14|537|427|`82.1948`|[Day05.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day05.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) `algorithm` `iterator` `vector`
06|19|11|582|488|`16.0164`|[Day06.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day06.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) `algorithm` `map` `vector`
07|106|75|2569|2038|`21.4940`|[Day07.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day07.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) `regex` `sstream` `vector` `unordered_map`
08|27|16|919|758|`2.5809`|[Day08.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day08.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) `algorithm` `unordered_map`
09|29|20|646|449|`1.3056`|[Day09.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day09.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp)
10|57|37|1775|1467|`2.1553`|[Day10.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day10.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) `algorithm` `array` `initializer_list` `iomanip` `locale` `numeric` `vector` `utility`
11|28|19|751|514|`1.9699`|[Day11.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day11.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) `cctype` `cmath` `utility`
12|22|11|606|512|`25.3263`|[Day12.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day12.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) `algorithm` `iterator` `regex` [`util.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/util.hpp)
13|39|24|943|738|`23.5723`|[Day13.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day13.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) `iterator` `algorithm` `type_traits` `utility` `vector` [`util.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/util.hpp)
14|41|25|1058|825|`148.5121`|[Day14.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day14.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) [`util.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/util.hpp) `algorithm` `array` `sstream` `string`
15|35|24|865|681|`556.0618`|[Day15.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day15.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) `random` `regex`
16|50|31|1362|1044|`20.1594`|[Day16.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day16.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) `algorithm` `functional` `map` `numeric` `cstdio` `vector`
17|30|21|670|470|`23.4710`|[Day17.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day17.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) `iterator` `vector`
18|27|16|718|557|`52.8247`|[Day18.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day18.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) [`duet_asm.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/duet_asm.hpp) `iterator` `thread` `vector`
19|27|18|745|573|`1.6580`|[Day19.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day19.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) `tuple` `utility` `vector`
20|47|31|1616|1255|`79.1397`|[Day20.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day20.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) `algorithm` `iterator` `valarray` `vector` `utility`
21|8|3|108|94|`0.0003`|[Day21.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day21.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp)
22|8|3|108|94|`0.0002`|[Day22.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day22.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp)
23|8|3|108|94|`0.0002`|[Day23.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day23.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp)
24|8|3|108|94|`0.0002`|[Day24.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day24.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp)
25|8|3|108|94|`0.0001`|[Day25.cpp](https://github.com/willkill07/AdventOfCode2017/blob/master/src/Day25.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp)
**TOTAL**|**778**|**490**|**20149**|**15656**|**1063.13**| |`  Solution.hpp`&nbsp;<sup>**`25`**</sup> ` vector`&nbsp;<sup>**`12`**</sup> ` algorithm`&nbsp;<sup>**`11`**</sup> ` iterator`&nbsp;<sup>**`8`**</sup> ` utility`&nbsp;<sup>**`5`**</sup> ` sstream`&nbsp;<sup>**`4`**</sup> ` numeric`&nbsp;<sup>**`3`**</sup> ` regex`&nbsp;<sup>**`3`**</sup> ` array`&nbsp;<sup>**`3`**</sup> ` unordered_map`&nbsp;<sup>**`3`**</sup> ` util.hpp`&nbsp;<sup>**`3`**</sup> ` map`&nbsp;<sup>**`2`**</sup> ` cmath`&nbsp;<sup>**`2`**</sup> ` set`&nbsp;<sup>**`1`**</sup> ` duet_asm.hpp`&nbsp;<sup>**`1`**</sup> ` cstdio`&nbsp;<sup>**`1`**</sup> ` type_traits`&nbsp;<sup>**`1`**</sup> ` valarray`&nbsp;<sup>**`1`**</sup> ` iomanip`&nbsp;<sup>**`1`**</sup> ` random`&nbsp;<sup>**`1`**</sup> ` cctype`&nbsp;<sup>**`1`**</sup> ` locale`&nbsp;<sup>**`1`**</sup> ` thread`&nbsp;<sup>**`1`**</sup> ` tuple`&nbsp;<sup>**`1`**</sup> ` functional`&nbsp;<sup>**`1`**</sup> ` initializer_list`&nbsp;<sup>**`1`**</sup> ` string`&nbsp;<sup>**`1`**</sup> ` `

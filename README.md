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
01|19|12|457|366|`0.2611`|[Day01.hpp](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Day01.hpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) `vector`
02|30|17|704|511|`0.2616`|[Day02.hpp](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Day02.hpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) `algorithm` `iterator` `sstream` `vector`
03|61|43|1501|1069|`0.0631`|[Day03.hpp](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Day03.hpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) `array` `cmath` `unordered_map`
04|26|14|632|487|`2.5986`|[Day04.hpp](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Day04.hpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) `algorithm` `iterator` `numeric` `set` `sstream`
05|24|15|548|437|`83.7925`|[Day05.hpp](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Day05.hpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) `algorithm` `iterator` `vector`
06|20|12|593|498|`14.4240`|[Day06.hpp](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Day06.hpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) `algorithm` `map` `vector`
07|107|76|2580|2048|`20.6566`|[Day07.hpp](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Day07.hpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) `regex` `sstream` `vector` `unordered_map`
08|28|17|930|768|`1.7914`|[Day08.hpp](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Day08.hpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) `algorithm` `unordered_map`
09|30|21|657|459|`0.7433`|[Day09.hpp](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Day09.hpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp)
10|59|38|1787|1478|`1.9382`|[Day10.hpp](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Day10.hpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) `algorithm` `array` `initializer_list` `iomanip` `locale` `numeric` `vector` `utility`
11|30|20|763|525|`1.2970`|[Day11.hpp](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Day11.hpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) `cctype` `cmath` `utility`
12|23|12|618|523|`24.2345`|[Day12.hpp](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Day12.hpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) `algorithm` `iterator` `regex` [`util.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/util.hpp)
13|40|25|955|749|`25.5269`|[Day13.hpp](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Day13.hpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) `iterator` `algorithm` `type_traits` `utility` `vector` [`util.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/util.hpp)
14|42|26|1070|836|`146.6637`|[Day14.hpp](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Day14.hpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) [`util.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/util.hpp) `algorithm` `array` `sstream` `string`
15|36|25|877|692|`563.4783`|[Day15.hpp](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Day15.hpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) `random` `regex`
16|51|32|1374|1055|`18.9237`|[Day16.hpp](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Day16.hpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) `algorithm` `functional` `map` `numeric` `cstdio` `vector`
17|31|22|682|481|`22.3354`|[Day17.hpp](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Day17.hpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) `iterator` `vector`
18|28|17|733|571|`56.2923`|[Day18.hpp](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Day18.hpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) [`duet_asm.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/duet_asm.hpp) `iterator` `thread` `vector`
19|28|19|757|584|`0.9427`|[Day19.hpp](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Day19.hpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) `tuple` `utility` `vector`
20|48|32|1628|1266|`79.5694`|[Day20.hpp](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Day20.hpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) `algorithm` `iterator` `valarray` `vector` `utility`
21|116|73|3302|2483|`246.2430`|[Day21.hpp](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Day21.hpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) `algorithm` `initializer_list` `numeric` `unordered_map` `utility` `vector`
22|68|43|1636|1177|`829.1147`|[Day22.hpp](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Day22.hpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) `vector` `unordered_map` `utility`
23|37|29|1000|778|`4.2999`|[Day23.hpp](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Day23.hpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) `vector` [`duet_asm.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/duet_asm.hpp)
24|49|33|1229|890|`186.4934`|[Day24.hpp](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Day24.hpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) `iterator` `vector`
25|64|45|1598|1168|`391.8774`|[Day25.hpp](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Day25.hpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2017/blob/master/include/Solution.hpp) `cstdio` `unordered_map`
**TOTAL**|**1095**|**718**|**28611**|**21899**|**2723.82**| |`  Solution.hpp`&nbsp;<sup>**`25`**</sup> ` vector`&nbsp;<sup>**`16`**</sup> ` algorithm`&nbsp;<sup>**`12`**</sup> ` iterator`&nbsp;<sup>**`9`**</sup> ` utility`&nbsp;<sup>**`7`**</sup> ` unordered_map`&nbsp;<sup>**`6`**</sup> ` sstream`&nbsp;<sup>**`4`**</sup> ` numeric`&nbsp;<sup>**`4`**</sup> ` regex`&nbsp;<sup>**`3`**</sup> ` array`&nbsp;<sup>**`3`**</sup> ` util.hpp`&nbsp;<sup>**`3`**</sup> ` cstdio`&nbsp;<sup>**`2`**</sup> ` map`&nbsp;<sup>**`2`**</sup> ` duet_asm.hpp`&nbsp;<sup>**`2`**</sup> ` cmath`&nbsp;<sup>**`2`**</sup> ` initializer_list`&nbsp;<sup>**`2`**</sup> ` set`&nbsp;<sup>**`1`**</sup> ` type_traits`&nbsp;<sup>**`1`**</sup> ` valarray`&nbsp;<sup>**`1`**</sup> ` iomanip`&nbsp;<sup>**`1`**</sup> ` random`&nbsp;<sup>**`1`**</sup> ` cctype`&nbsp;<sup>**`1`**</sup> ` locale`&nbsp;<sup>**`1`**</sup> ` thread`&nbsp;<sup>**`1`**</sup> ` tuple`&nbsp;<sup>**`1`**</sup> ` functional`&nbsp;<sup>**`1`**</sup> ` string`&nbsp;<sup>**`1`**</sup> ` `

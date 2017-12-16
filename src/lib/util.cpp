#include <vector>
#include <array>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <string>
#include <functional>
#include <iomanip>

#include "util.hpp"

namespace util {

std::string
knot_hash(std::string const & str) {
  std::array<unsigned char, 256> list;
  std::iota(std::begin(list), std::end(list), 0);
  std::vector<unsigned char> lengths {std::begin(str), std::end(str)};
  lengths.insert(lengths.end(), {17, 31, 73, 47, 23});
  unsigned char skip{0}, pos {0};
  for (int _{0}; _ < 64; ++_)
    for (unsigned char length : lengths) {
      std::reverse(std::begin(list), std::begin(list) + length);
      unsigned char delta = length + skip++;
      std::rotate(std::begin(list), std::begin(list) + delta, std::end(list));
      pos += delta;
    }
  std::rotate(std::begin(list), std::end(list) - pos, std::end(list));
  std::ostringstream oss;
  oss.flags(std::ios::hex);
  oss.fill('0');
  for (auto b = std::begin(list); b != std::end(list); std::advance(b, 16))
    oss << std::setw(2) << std::accumulate(b, std::next(b, 16), 0, std::bit_xor<void>());
  return oss.str();
}

std::array<bool, 128>
hash2array(std::string const & hash) {
  std::array<bool, 128> arr;
  auto a = std::begin(arr);
  for (auto h : hash) {
    unsigned char const d = htoi(h);
    *a++ = (d >> 3) & 1;
    *a++ = (d >> 2) & 1;
    *a++ = (d >> 1) & 1;
    *a++ = d & 1;
  }
  return arr;
}

int
htoi(char c)
{
  return c - '0' + (c >= 'a') * (10 + '0' - 'a');
}

char
itoh(int v)
{
  char const digit[] = "0123456789abcdef";
  return digit[v];
}

int
fast_itoa(int i, char* b)
{
  char const digit[] = "0123456789";
  char*      p = b;
  int        shifter = i;
  do
    ++p;
  while (shifter /= 10);
  *p = '\0';
  int dist(p - b);
  do
    *--p = digit[i % 10];
  while (i /= 10);
  return dist;
}

std::vector<std::string>
split(const std::string& text, const std::string& delims)
{
  std::vector<std::string> tokens;
  std::size_t              start = text.find_first_not_of(delims), end = 0;
  while ((end = text.find_first_of(delims, start)) != std::string::npos) {
    if (end != start)
      tokens.push_back(text.substr(start, end - start));
    start = text.find_first_not_of(delims, end);
  }
  if (start != std::string::npos)
    tokens.push_back(text.substr(start));
  return tokens;
}
}

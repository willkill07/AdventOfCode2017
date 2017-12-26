#include "Solution.hpp"
#include <algorithm>
#include <initializer_list>
#include <numeric>
#include <unordered_map>
#include <utility>
#include <vector>

struct Grid {
  unsigned long N;
  std::vector<char> data;

  Grid() = default;

  Grid(unsigned long size) : N(size), data(N * N) {}

  Grid(std::initializer_list<char> il) : N(std::sqrt(il.size())), data(il) {}

  template <typename Itr>
  Grid(unsigned long size, Itr & itr) : Grid(size) {
    for (unsigned long i = 0; i < N; ++i) {
      std::copy(itr, std::next(itr, N), &this->operator()(i, 0));
      std::advance(itr, N + 1);
    }
  }

  char& operator()(unsigned long r, unsigned long c) {
    return data[r * N + c];
  }

  char operator()(unsigned long r, unsigned long c) const {
    return data[r * N + c];
  }

  bool operator==(Grid const & o) const {
    if (o.N != N)
      return false;
    return std::equal(data.begin(), data.end(), o.data.begin());
  }

  Grid& transpose() {
    for (unsigned long i = 0; i < N; ++i)
      for (unsigned long j = i; j < N; ++j)
        std::swap(this->operator()(i, j), this->operator()(j, i));
    return *this;
  }

  Grid& flip() {
    for (unsigned long i = 0; i < N; ++i)
      for (unsigned long j = 0; 2 * j < N; ++j)
        std::swap(this->operator()(i, j), this->operator()(i, N - 1 - j));
    return *this;
  }

  Grid view_of(unsigned long ViewN, int bRow, int bCol) {
    Grid v(ViewN);
    for (unsigned int r = 0; r < ViewN; ++r)
      for (unsigned int c = 0; c < ViewN; ++c)
        v(r, c) = this->operator()(bRow * ViewN + r, bCol * ViewN + c);
    return v;
  }

  template <typename Lookup>
  void evolve (Lookup const & data) {
    bool Div2 = ((N & 1) == 0);
    unsigned long SrcStride = Div2 ? 2 : 3;
    unsigned long DstStride = SrcStride + 1;
    unsigned long Next = DstStride * N / SrcStride;
    Grid next(Next);
    for (unsigned long row = 0; row < N / SrcStride; ++row) {
      for (unsigned long col = 0; col < N / SrcStride; ++col) {
        auto dst = data.at(view_of(SrcStride, row, col));
        for (unsigned long r = 0; r < DstStride; ++r)
          std::copy_n(&dst(r, 0), DstStride, &next(row * DstStride + r, col * DstStride));
      }
    }
    *this = next;
  }

  unsigned long count() const {
    return std::count(std::begin(data), std::end(data), '#');
  }

  struct Hash {
    unsigned long operator()(Grid const & g) const {
      auto to_int = [] (unsigned long acc, char c) {
        return (acc << 1) | (c == '#');
      };
      return std::accumulate(g.data.begin(), g.data.end(), 0lu, to_int);
    }
  };
};

template <>
template <bool part2>
void
Day<21>::solve(std::istream &is, std::ostream &os)
{
  std::unordered_map<Grid, Grid, Grid::Hash> data;
  for (std::string line; std::getline(is, line); ) {
    auto itr = std::begin(line);
    bool size_is_two = (*std::next(itr, 2) == '/');
    Grid g(size_is_two ? 2 : 3, itr);
    std::advance(itr, 3);
    Grid gn(size_is_two ? 3 : 4, itr);
    data[g.flip()] = data[g.transpose()] = data[g.flip()] = data[g.transpose()] =
    data[g.flip()] = data[g.transpose()] = data[g.flip()] = data[g.transpose()] = gn;
  }

  Grid grid{'.', '#', '.', '.', '.', '#', '#', '#', '#' };

  int iters = (part2 ? 18 : 5);
  while (iters--)
    grid.evolve(data);
  os << grid.count() << '\n';
}

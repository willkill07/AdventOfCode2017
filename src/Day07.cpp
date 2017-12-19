#include "Solution.hpp"
#include <regex>
#include <sstream>
#include <vector>
#include <unordered_map>

struct Node {
  std::string name;
  int weight, total;
  Node* parent;
  std::vector<std::string> children;
  std::vector<Node*> cnodes;
};

template<typename It, typename Pred>
It diff(It begin, It end, Pred p) {
  if(begin == end)
    return end;
  int seen = 1;
  auto cand = *begin;
  auto pos = end;
  for(auto it = std::next(begin); it != end; ++it)
    if(p(cand, *it))
      ++seen;
    else
      pos = it;
  return (seen == 1) ? begin : pos;
}

template<typename It>
It diff(It begin, It end) {
  return diff(begin, end, std::equal_to<void>{});
}

int calc_totals(Node* n);

Node* find_bad_node(Node* n);

std::unordered_map<std::string, Node> parse (std::istream& is);

template <>
void
solve<Day07>(bool part2, std::istream& is, std::ostream& os)
{
  auto nodes = parse(is);
  for(auto it = std::begin(nodes); it != std::end(nodes); ++it) {
    auto & [name, node] = *it;
    for(auto& child_name : node.children) {
      Node* child = &nodes[child_name];
      child->parent = &node;
      node.cnodes.push_back(child);
    }
  }
  Node* tree = &std::begin(nodes)->second;
  while(tree->parent)
    tree = tree->parent;

  if (part2) {
    calc_totals(tree);
    Node* bad_node = find_bad_node(tree);
    int bad_total = bad_node->total;
    int diff{0};
    for(auto const sib : bad_node->parent->cnodes)
      if(sib->total != bad_total)
        diff = sib->total - bad_total;
    os << bad_node->weight + diff << '\n';
  } else {
    os <<  tree->name << '\n';
  }
}


std::unordered_map<std::string, Node>
parse (std::istream& is) {
  static std::regex re{"[^a-z0-9]+", std::regex::optimize | std::regex::extended};
  std::unordered_map<std::string, Node> nodes;
  for (std::string line; std::getline(is, line); ) {
    line = std::regex_replace(line, re, " ");
    std::istringstream iss{line};
    std::string name;
    int weight;
    iss >> name >> weight;
    std::vector<std::string> children{std::istream_iterator<std::string>{iss}, {}};
    nodes[name] = Node{name, weight, 0, nullptr, children, {}};
  }
  return nodes;
}

int calc_totals(Node* n) {
  int total = n->weight;
  for(Node* ch : n->cnodes) {
    total += calc_totals(ch);
  }
  n->total = total;
  return total;
}

Node* find_bad_node(Node* n) {
  auto eq = [](Node* lhs, Node* rhs) {
    return lhs->total == rhs->total;
  };
  if(auto odd = diff(std::begin(n->cnodes), std::end(n->cnodes), eq);
     odd != std::end(n->cnodes))
    return find_bad_node(*odd);
  return n;
}

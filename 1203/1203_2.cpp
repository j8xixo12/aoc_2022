#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

int helper(std::vector<std::string> v) {
  int ret = 0;

  std::vector<std::unordered_set<char>> vs;
  vs.push_back(std::unordered_set<char>());
  for (auto c : v[0]) {
    if (!vs[0].count(c)) vs[0].insert(c);
  }
  vs.push_back(std::unordered_set<char>());
  for (auto c : v[1]) {
    if (!vs[1].count(c)) vs[1].insert(c);
  }
  vs.push_back(std::unordered_set<char>());
  for (auto c : v[2]) {
    if (!vs[2].count(c)) vs[2].insert(c);
  }

  std::unordered_map<char, int> m;

  for (auto us : vs) {
    for (auto it : us) {
      m[it]++;
      if (m[it] == 3) {
        if (std::isupper(it)) {
          ret += (it - 'A' + 27);
        } else {
          ret += (it - 'a' + 1);
        }
      }
    }
  }

  return ret;
}

int main (int argc, char *argv[]) {
  std::ifstream infile("test.txt");
  std::string line;
  int ret = 0;
  int n = 0;
  std::vector<std::string> ss;
  while (std::getline(infile, line)) {
    ss.push_back(line);
    n++;
    if (n == 3) {
      ret += helper(ss);
      n = 0;
      ss.clear();
    }
  }
  std::cout << ret << std::endl;
  return 0;
}

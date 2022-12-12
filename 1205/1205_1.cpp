#include <iostream>
#include <string>
#include <fstream>
#include <deque>
#include <vector>
#include <algorithm>

bool is_number(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(), 
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

void parsing(std::vector<std::deque<char>> &v, std::vector<std::vector<int>> &o_v)
{
  std::ifstream infile("test.txt");
  std::string line;
  
  while (std::getline(infile, line)) {
    if (line.empty()) break;
    for (int i = 0; i < line.size(); ++i) {
      if (line[i] == ']') {
        v[i / 4].push_front(line[i - 1]);
      }
    }
  }

  std::vector<int> op;
  size_t pos = 0;
  while (std::getline(infile, line)) {
    while ((pos = line.find(" ")) != std::string::npos) {
      std::string tmp = line.substr(0, pos);
      if (is_number(tmp)) {
        op.push_back(std::stoi(tmp));
      }
      line.erase(0, pos + 1);
    }
    op.push_back(std::stoi(line));
    o_v.push_back(op);
    op.clear();
  }
}

void operation(std::vector<std::deque<char>> &crates, int num, int from, int dest) {
  for (int i = 0; i < num; ++i) {
    auto tmp = crates[from - 1].back();
    crates[from - 1].pop_back();
    crates[dest - 1].push_back(tmp);
  }
}

int main (int argc, char *argv[])
{
  
  std::vector<std::deque<char>> v(9, std::deque<char>());
  std::vector<std::vector<int>> o_v;
  parsing(v, o_v);

  for (auto i : o_v) {
    operation(v, i[0], i[1], i[2]);
  }

  for (auto i : v) {
    std::cout << i.back() << std::endl;
  } 
  return 0;
}

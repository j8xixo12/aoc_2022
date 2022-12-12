#include <iostream>
#include <string>
#include <fstream>
#include <vector>

std::vector<std::string> split (std::string str, std::string delimiter) {
  std::string tmp;
  std::size_t pos = 0;
  std::vector<std::string> ret;
  while ((pos = str.find(" ")) != std::string::npos) {
    tmp = str.substr(0, pos);
    ret.push_back(tmp);
    str.erase(0, pos + delimiter.size());
  }
  ret.push_back(str);
  return ret;
}
// 1 AX石頭 2 BY布 3 CZ剪刀
int win_score(char a, char b) {
  if ((a - 'A') == (b - 'X')) return 3;
  if (a == 'C' && b == 'X') return 6;
  if (a == 'A' && b == 'Z') return 0;
  return (a - 'A') < (b - 'X') ? 6 : 0;
}

int main (int argc, char *argv[]) {
  std::ifstream infile("test.txt");
  std::string line;
  std::string tmp;

  std::vector<std::vector<std::string>> buf;
  std::size_t pos = 0;
  while (std::getline(infile, line)) {
    auto i = split(line, " ");
    buf.push_back(i);
  }

  int ret = 0;
  for (auto i : buf) {
    int score = 0;
    score += (i[1][0] - 'X' + 1);
    score += win_score(i[0][0], i[1][0]);
    ret += score;
  }
  std::cout << ret << std::endl;
  return 0;
}

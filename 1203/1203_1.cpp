#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>

int main (int argc, char *argv[]) {
  std::ifstream infile("test.txt");
  std::string line;
  int ret = 0;
  while (std::getline(infile, line)) {
    int n = line.size();
    std::unordered_set<char> s;
    for (int i = 0; i < n / 2; ++i) {
      s.insert(line[i]);
    }
    for (int i = n / 2; i < n; ++i) {
      if (s.count(line[i])) {
        if (std::isupper(line[i])) {
          ret += (line[i] - 'A' + 27);
        } else {
          ret += (line[i] - 'a' + 1);
        }
        break;
      }
    }
  }
  std::cout << ret << std::endl;
  return 0;
}

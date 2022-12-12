#include <iostream>
#include <fstream>
#include <string>
#include <deque>

bool verify(std::deque<char> &dq, char c)
{
  int num = 0;
  for (auto i : dq) {
    ++num;
    if (i == c) {
      while (num--) {
        dq.pop_front();
      }
      break;
    }
  }
  dq.push_back(c);
  return dq.size() == 14 ? true : false;
}

int main(int argc, char *argv[])
{
  std::ifstream infile("test.txt");
  std::string line;
  std::deque<char> marker_buf;

  while (std::getline(infile, line)) {
    for (int i = 0; i < line.size(); ++i) {
      if (verify(marker_buf, line[i])) {
        std::cout << i + 1 << std::endl;
        break;
      }
    }
  }
  return 0;
}

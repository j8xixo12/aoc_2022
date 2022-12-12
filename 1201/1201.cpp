#include <iostream>
#include <string>
#include <fstream>
#include <queue>

int main (int argc, char *argv[]) {

  std::ifstream infile("test.txt");
  std::string line;
  std::priority_queue<int> pq;
  int res = 0, tmp = 0;

  while (std::getline(infile, line)) {
    if (!line.empty()) {
      tmp += std::stoi(line);
    } else {
      pq.push(tmp);
      tmp = 0;
    }
  }

  for (int i = 0; i < 3; ++i) {
    res += pq.top();
    pq.pop();
  }

  std::cout << res << std::endl;
  return 0;
}

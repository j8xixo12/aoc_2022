#include <iostream>
#include <string>
#include <vector>
#include <fstream>

void parsing (std::string str, std::vector<std::string> &output) {
  std::string delimiter_1 = ",";
  std::string delimiter_2 = "-";

  size_t pos_1 = 0;
  size_t pos_2 = 0;
  std::string token;

  while ((pos_1 = str.find(delimiter_1)) != std::string::npos) {
    token = str.substr(0, pos_1);
    // std::cout << token << std::endl;
    while ((pos_2 = token.find(delimiter_2)) != std::string::npos) {
      output.push_back(token.substr(0, pos_2));
      token.erase(0, pos_2 + delimiter_2.length());
    }
    output.push_back(token);
    str.erase(0, pos_1 + delimiter_1.length());
  }

  while ((pos_2 = str.find(delimiter_2)) != std::string::npos) {
    output.push_back(str.substr(0, pos_2));
    str.erase(0, pos_2 + delimiter_2.length());
  }
  output.push_back(str);
}

int main (int argc, char *argv[]) {
  std::ifstream infile("test.txt");
  std::string line;
  std::vector<std::string> v;
  int ret = 0;
  while (std::getline(infile, line)) {
    parsing(line, v);
    if ((std::stoi(v[0]) >= std::stoi(v[2]) && std::stoi(v[3]) >= std::stoi(v[1]))
        || (std::stoi(v[0]) <= std::stoi(v[2]) && std::stoi(v[3]) <= std::stoi(v[1]))) {
      ret++;
    }
    v.clear();
  }
  std::cout << ret << std::endl;
  return 0;
}

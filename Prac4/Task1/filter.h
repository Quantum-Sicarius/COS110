#ifndef FILTER_H
#define FILTER_H

#include <string>
#include <vector>
#include <sstream>

class filter {
public:
  void split(const std::string &s, char delim, std::vector<std::string> &elems) {
          std::stringstream ss;
          ss.str(s);
          std::string item;
          while (getline(ss, item, delim)) {
                  elems.push_back(item);
          }
  }

  std::vector<std::string> split(const std::string &s, char delim) {
          std::vector<std::string> elems;
          split(s, delim, elems);
          return elems;
  }

  std::string trim(std::string& str)
  {
          size_t first = str.find_first_not_of(' ');
          size_t last = str.find_last_not_of(' ');
          return str.substr(first, (last-first+1));
  }
  virtual std::string print(std::string s) = 0;
};

#endif

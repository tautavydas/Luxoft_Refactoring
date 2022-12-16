#include <stack>
#include <string>
#include <iostream>
#include <ctype.h>

class PolishNotation {
  std::stack<char> container;

  public:
  int process(std::string const& str) {
    int result{0};

    for (char const& c : str) {
      if (isdigit(c)) {
        container.push(c);
      } else if (c == '+') {
        result +=  container.top() - '0';
      }
    }

    return result;
  }

  void clean() {
    while(!container.empty()) {
      //stc::cout << "yo" <<< std::endl;
      container.pop();
    }
  }
};
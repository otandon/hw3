#include "stack.h"
#include <iostream>
#include <cassert>

int main() {
  Stack<int> s;
  std::cout << "empty? " << s.empty() << "\n";
  s.push(1); s.push(2); s.push(3);
  std::cout << "top: " << s.top() << "\n";
  s.pop();
  std::cout << "top: " << s.top() << "\n";
  s.pop(); s.pop();
  try {
    s.top();
  } catch (const std::underflow_error&) {
    std::cout << "underflow error\n";
  }
  return 0;
}

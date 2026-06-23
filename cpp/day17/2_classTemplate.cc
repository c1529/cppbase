#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
template <class T, int kSize = 10> class Stack {
public:
  Stack() : _top(-1), _data(new T[kSize]()) { cout << "Stack()" << endl; }
  ~Stack() {
    cout << "~Stack()" << endl;
    if (_data) {
      delete[] _data;
      _data = nullptr;
    }
  }
  bool empty() const;
  bool full() const;
  void push(const T &t);
  void pop();
  T &top() const;

private:
  int _top;
  T *_data;
};
template <class T, int kSize> bool Stack<T, kSize>::empty() const {
  return _top == -1;
}
template <class T, int kSize> bool Stack<T, kSize>::full() const {
  return _top == kSize - 1;
}
template <class T, int kSize> void Stack<T, kSize>::push(const T &t) {
  if (!full()) {
    _data[++_top] = t;
  } else {
    cout << "Stack is full" << endl;
  }
}
template <class T, int kSize> void Stack<T, kSize>::pop() {
  if (empty()) {
    cout << "Stack is empty" << endl;
  } else {
    _top--;
  }
}
template <class T, int kSize> T &Stack<T, kSize>::top() const {
  return _data[_top];
}
void test0() {
  Stack<double> s1;
  cout << "s1.empty() = " << s1.empty() << endl;
  s1.push(1.1);
  s1.push(2.2);
  s1.push(3.14);
  cout << "s1.top() = " << s1.top() << endl;
  s1.pop();
  cout << "s1.top() = " << s1.top() << endl;

  cout << "Stack<String>" << endl;
  Stack<string> s2;
  cout << "s2.empty() = " << s2.empty() << endl;
  s2.push("!!!!!");
  s2.push("world");
  s2.push("hello");
  while (!s2.empty()) {
    cout << s2.top();
    s2.pop();
  }
  cout << endl;
}
int main() {
  test0();
  return 0;
}

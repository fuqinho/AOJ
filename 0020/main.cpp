#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
  string s;
  getline(cin, s);
  transform(s.begin(), s.end(), s.begin(), (int (*)(int))toupper);
  cout << s << endl;
}


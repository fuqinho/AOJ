#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    string a, b;
    cin >> a >> b;
    vector<int> va, vb;
    for (int i = a.size() - 1; i >= 0; i--) va.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--) vb.push_back(b[i] - '0');
    vector<int> vc;
    int rem = 0;
    for (int i = 0; i < va.size() || i < vb.size(); i++) {
      if (i < va.size()) rem += va[i];
      if (i < vb.size()) rem += vb[i];
      vc.push_back(rem % 10);
      rem = rem / 10;
    }
    if (rem) vc.push_back(rem);
    if (vc.size() > 80) {
      cout << "overflow" << endl;
    } else {
      for (int i = vc.size() - 1; i >= 0; i--) cout << vc[i];
      cout << endl;
    }
  }
}

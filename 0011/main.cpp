#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main() {
  int n, w; cin >> n >> w;
  vector<int> res(n);
  for (int i = 0; i < n; i++) res[i] = i + 1;
  for (int i = 0; i < w; i++) {
    int a, b;
    scanf("%d,%d", &a, &b);
    swap(res[a-1], res[b-1]);
  }
  for (int i = 0; i < n; i++) cout << res[i] << endl;
}

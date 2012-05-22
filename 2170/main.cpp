// Limit: 32768K / 8000ms
// Used :  6860K /  310ms
#include <vector>
#include <cstdio>
using namespace std;

class UnionFindTree {
public:
  UnionFindTree(int n) {
    par = vector<int>(n);
    for (int i = 0; i < n; i++) par[i] = i;
  }
  int find(int x) {
    if (x == par[x]) return x;
    else return par[x] = find(par[x]);
  }
  void unite(int x, int y) {
    int rx = find(x), ry = find(y);
    if (rx != ry) par[ry] = rx;
  }
  bool same(int x, int y) {
    return find(x) == find(y);
  }
private:
  vector<int> par;
};

int N, Q;
vector<vector<int> > G;
vector<bool> marked;
UnionFindTree tree(0);
vector<int> parent;
vector<pair<bool, int> > queries;

long long solve() {
  tree = UnionFindTree(N);
  for (int i = 0; i < N; i++) {
    if (!marked[i]) tree.unite(parent[i], i);
  }

  long long res = 0;
  for (int i = queries.size() - 1; i >= 0; i--) {
    int x = queries[i].second - 1;
    if (queries[i].first == false) {
      tree.unite(parent[x], x);
    } else {
      res += tree.find(x) + 1;
    }
  }
  return res;
}

int main() {
  while (true) {
    scanf("%d %d", &N, &Q);
    if (N == 0 && Q == 0) break;

    parent = vector<int>(N);
    G = vector<vector<int> >(N);
    for (int i = 1; i < N; i++) {
      int n; scanf("%d", &n);
      G[n-1].push_back(i);
      parent[i] = n-1;
    }

    marked = vector<bool>(N);
    marked[0] = true;
    queries = vector<pair<bool, int> >(Q);
    char buf[2];
    int qnum = 0;
    for (int i = 0; i < Q; i++) {
      int n; scanf("%s %d", buf, &n);
      if (buf[0] == 'Q') {
        queries[qnum++] = make_pair(true, n);
      } else if (!marked[n-1]) {
        marked[n-1] = true;
        queries[qnum++] = make_pair(false, n);
      }
    }
    Q = qnum;
    queries.resize(Q);
    long long ans = solve();
    printf("%lld\n", ans);
  }
}

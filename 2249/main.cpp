#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> PII;
const int INF = 10e+9;

struct Edge {
  int to, dist, cost;
  Edge(int t, int d, int c) : to(t), dist(d), cost(c) {}
};

int solve(int N, int M, vector<int>& u, vector<int>& v, vector<int>& d, vector<int>& c) {
  vector<vector<Edge> > G(N);
  for (int i = 0; i < M; i++) {
    G[u[i]-1].push_back(Edge(v[i]-1, d[i], c[i]));
    G[v[i]-1].push_back(Edge(u[i]-1, d[i], c[i]));
  }

  vector<bool> used(N, false);
  priority_queue<pair<int, PII>, vector<pair<int, PII> >, greater<pair<int, PII> > > que;

  int total_cost = 0;

  que.push(make_pair(0, make_pair(0, 0)));
  while (!que.empty()) {
    int city = que.top().second.first;
    int cost = que.top().second.second;
    int dist = que.top().first;
    que.pop();

    if (!used[city]) {
      used[city] = true;
      total_cost += cost;

      for (int i = 0; i < G[city].size(); i++) {
        Edge& e = G[city][i];
        if (!used[e.to]) {
          que.push(make_pair(dist + e.dist, make_pair(e.to, e.cost)));
        }
      }
    }
  }
  return total_cost;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  while (true) {
    int N, M; cin >> N >> M;
    if (N == 0 && M == 0) break;

    vector<int> u(M), v(M), d(M), c(M);
    for (int i = 0; i < M; i++) cin >> u[i] >> v[i] >> d[i] >> c[i];

    int ans = solve(N, M, u, v, d, c);
    cout << ans << endl;
  }
}

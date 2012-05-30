// Limit: 32768KB 8000ms
// Used :  2044KB 1620ms
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
#define ALL(a)  (a).begin(),(a).end()
#define REP(i,n) for(int i=0;i<(n);++i)
const double EPS = 1e-10;
const double PI  = acos(-1.0);
#define dump(x) cerr << "  (L" << __LINE__ << ") " << #x << " = " << (x) << endl;
#define dumpv(x) cerr << "  (L" << __LINE__ << ") " << #x << " = "; REP(q,(x).size()) cerr << (x)[q] << " "; cerr << endl;
template<typename T1, typename T2>
ostream& operator<<(ostream& s, const pair<T1, T2>& d) {return s << "(" << d.first << "," << d.second << ")";}


const int INF = 1e9;

int solve(int N, VVI& land, VVI& sea, VI& z) {
  // bellman-ford
  REP(k, N) REP(i, N) REP(j, N) {
    land[i][j] = min(land[i][j], land[i][k] + land[k][j]);
    sea[i][j] = min(sea[i][j], sea[i][k] + sea[k][j]);
  }

  // dp[i][j]: i個目の配達を終えた時に船が町jにあるときの最短時間
  VVI dp(z.size(), VI(N, INF));
  dp[0][z[0]-1] = 0;
  REP(i, z.size()-1) {
    int from = z[i]-1;
    int to = z[i+1]-1;
    REP(j, N) {
      REP(k, N) {
        // z[i]からz[i+1]までの移動中に、船をjからkまで移動させる
        if (land[from][j] != INF && sea[j][k] != INF && land[k][to] != INF) {
          dp[i+1][k] = min(dp[i+1][k], 
              dp[i][j] + land[from][j] + sea[j][k] + land[k][to]);
        }
      }
      // 陸路のみで、港に立ち寄らない場合
      dp[i+1][j] = min(dp[i+1][j], dp[i][j] + land[from][to]);
    }
  }

  return *min_element(dp[z.size()-1].begin(), dp[z.size()-1].end());
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  while (true) {
    int N, M; cin >> N >> M;
    if (N == 0 && M == 0) break;

    VVI land(N, VI(N, INF)), sea(N, VI(N, INF));
    REP(i, N) {
      land[i][i] = 0;
      sea[i][i] = 0;
    }
    REP(i, M) {
      int x, y, t; string sl;
      cin >> x >> y >> t >> sl;
      if (sl == "L") {
        land[x-1][y-1] = t;
        land[y-1][x-1] = t;
      } else {
        sea[x-1][y-1] = t;
        sea[y-1][x-1] = t;
      }
    }
    int R; cin >> R;
    vector<int> z(R);
    REP(i, R) cin >> z[i];

    int ans = solve(N, land, sea, z);
    cout << ans << endl;
  }
}


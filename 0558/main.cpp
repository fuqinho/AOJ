#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// typedef
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

//container util
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

int bfs(vector<string>& map, PII start, PII goal) {
    int res = 0;
    VVI costs(map.size(), VI(map[0].size(), -1));
    costs[start.first][start.second] = 0;
    queue<PII> q;
    q.push(start);
    int cost = 0;
    while (!q.empty()) {
        PII p = q.front(); q.pop();
        if (p == goal) {
            cost = costs[p.first][p.second];
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nr = p.first + dr[i];
            int nc = p.second + dc[i];
            if (nr >= 0 && nr < map.size() && nc >= 0 && nc < map[nr].size()
                    && map[nr][nc] != 'X' && costs[nr][nc] == -1) {
                costs[nr][nc] = costs[p.first][p.second] + 1;
                q.push(PII(nr, nc));
            }
        }
    }
    return cost;
}

int getCost(vector<string>& map, int next) {
    char from = 'S';
    if (next > 1) from = char(next - 1 + '0');
    char to = char(next + '0');

    PII start, goal;
    for (int i = 0; i < map.size(); i++) {
        for(int j = 0; j < map[i].size(); j++) {
            if (map[i][j] == from) start = PII(i, j);
            if (map[i][j] == to) goal = PII(i, j);
        }
    }
    return bfs(map, start, goal);
}

int solve(vector<string>& map, int N) {
    int cost = 0;
    for (int i = 1; i <= N; i++) {
        cost += getCost(map, i);
    }
    return cost;
}

int main() {
    int H, W, N;
    cin >> H >> W >> N;
    vector<string> map;
    for (int i = 0; i < H; i++) {
        string s; cin >> s;
        map.push_back(s);
    }
    int answer = solve(map, N);
    cout << answer << endl;
}

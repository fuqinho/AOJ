#include <iostream>
#include <vector>
using namespace std;

int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

void dfs(vector<string>& garden, int r, int c) {
    char color = garden[r][c];
    garden[r][c] = '.';
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr >= 0 && nr < garden.size() && nc >= 0 && nc < garden[nr].size()) {
            if (garden[nr][nc] == color) dfs(garden, nr, nc);
        }
    }
}

int solve(vector<string>& garden) {
    int res = 0;
    for (int i = 0; i < garden.size(); i++) {
        for (int j = 0; j < garden[i].size(); j++) {
            if (garden[i][j] != '.') {
                res ++ ;
                dfs(garden, i, j);
            }
        }
    }
    return res;
}

int main() {
    int H, W;
    while (true) {
        cin >> H >> W;
        if (H == 0 && W == 0) break;
        vector<string> garden;
        for (int i = 0; i < H; i++) {
            string s; cin >> s;
            garden.push_back(s);
        }
        int answer = solve(garden);
        cout << answer << endl;
    }
}


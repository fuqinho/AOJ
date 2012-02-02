#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

bool dfs(vector<int> que, int index, int left, int right) {
    if (index == que.size()) {
        return true;
    } else {
        bool res = false;
        if (que[index] > left) res |= dfs(que, index+1, que[index], right); 
        if (que[index] > right) res |= dfs(que, index+1, left, que[index]); 
        return res;
    }
}

int main() {
    int T; cin >> T;
    string s;
    getline(cin, s);
    for (int i = 0; i < T; i++) {
        vector<int> v;
        getline(cin, s);
        stringstream ss(s);
        int t;
        while (ss >> t) v.push_back(t);

        cout << (dfs(v, 0, 0, 0) ? "YES" : "NO") << endl;
    }
}

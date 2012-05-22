// Limit: 32768K / 8000ms
// Used :    Low /  200ms
#include <stdio.h>
#include <string.h>

#define MAX_N 100000
#define MAX_Q 100000

int N;
char marked[MAX_N];
int parent[MAX_N];

int Q;
char qtype[MAX_Q];
int qindex[MAX_Q];

int par[MAX_N];

void uf_init() {
  int i;
  for (i = 0; i < N; i++) par[i] = i;
}

int uf_find(int x) {
  if (x == par[x]) return x;
  else return par[x] = uf_find(par[x]);
}

void uf_unite(int x, int y) {
  int rx = uf_find(x), ry = uf_find(y);
  if (rx != ry) par[ry] = rx;
}

int main() {
  int i;
  for (;;) {
    scanf("%d %d", &N, &Q);
    if (N == 0 && Q == 0) break;

    for (i = 1; i < N; i++) {
      int n; scanf("%d", &n);
      parent[i] = n-1;
    }

    memset(marked, 0, sizeof(marked));
    marked[0] = 1;
    
    int qnum = 0;
    for (i = 0; i < Q; i++) {
      int n; char t[2]; scanf("%s %d", t, &n);
      if (!(t[0] == 'M' && marked[n-1] == 1)) {
        if (t[0] == 'M') marked[n-1] = 1;
        qtype[qnum] = t[0];
        qindex[qnum] = n-1;
        qnum++;
      } 
    }
    Q = qnum;

    uf_init();
    for (i = 0; i < N; i++) {
      if (marked[i] == 0) uf_unite(parent[i], i);
    }

    long long ans = 0;
    for (i = Q - 1; i >= 0; i--) {
      if (qtype[i] == 'M') {
        uf_unite(parent[qindex[i]], qindex[i]);
      } else {
        ans += uf_find(qindex[i]) + 1;
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}

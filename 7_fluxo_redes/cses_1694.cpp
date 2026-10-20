#include <bits/stdc++.h>
#include <cstdlib>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> adj;

void bfs() {
  queue<int> queue;
  queue.push(0);
}

int main() {
  cin >> n >> m;
  adj.resize(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int a, b;
    long long c;
    cin >> a >> b >> c;
    a--;
    b--;

    adj[a].push_back(b);
  }
}
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

const int INF = numeric_limits<int>::max();

int n, m;
int timer = 0;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> tin;
vector<int> low;
set<pair<int, int>> necessary;

void dfs(int u, int father = -1) {
  visited[u] = true;
  tin[u] = low[u] = timer++;
  for (int v : adj[u]) {
    if (v == father)
      continue;
    if (visited[v])
      low[u] = min(low[u], tin[v]);
    else {
      dfs(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] > tin[u])
        necessary.insert({u, v});
    }
  }
}

int main() {
  cin >> n >> m;
  adj.resize(n, vector<int>());
  visited.resize(n, false);
  tin.resize(n, INF);
  low.resize(n, INF);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs(0);

  cout << necessary.size() << endl;
  for (auto [u, v] : necessary)
    cout << (u + 1) << " " << (v + 1) << endl;
}
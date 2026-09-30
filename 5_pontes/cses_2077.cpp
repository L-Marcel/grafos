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
set<int> necessary;

void dfs(int u, int father = -1) {
  visited[u] = true;
  tin[u] = low[u] = timer++;
  int childrens = 0;
  for (int v : adj[u]) {
    if (v == father)
      continue;
    if (visited[v])
      low[u] = min(low[u], tin[v]);
    else {
      dfs(v, u);
      low[u] = min(low[u], low[v]);
      if (father != -1 && low[v] >= tin[u])
        necessary.insert(u);
      childrens++;
    }
  }

  if (father == -1 && childrens >= 2)
    necessary.insert(u);
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
  for (int i : necessary)
    cout << (i + 1) << " ";
}
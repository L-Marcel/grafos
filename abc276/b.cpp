#include <bits/stdc++.h>
#include <ostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for (int i = 0; i < n; i++) {
    int d = adj[i].size();
    cout << d;
    sort(adj[i].begin(), adj[i].end());
    for (int j = 0; j < d; j++) {
      cout << " " << (adj[i][j] + 1);
    }
    cout << endl;
  }
}
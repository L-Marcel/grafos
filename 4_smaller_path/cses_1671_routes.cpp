#include <bits/stdc++.h>
#include <cmath>
#include <limits>
#include <queue>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
  vector<long long int> dist(n, numeric_limits<long long int>::max());
  vector<bool> visited(n, false);

  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;

    a--;
    b--;
    adj[a].push_back({c, b});
  }

  priority_queue<pair<long long int, int>> queue;
  dist[0] = 0;
  queue.push({0, 0});

  while (!queue.empty()) {
    int current = queue.top().second;
    queue.pop();
    if (!visited[current]) {
      visited[current] = true;
      for (pair<int, int> neighbor : adj[current]) {
        long long int current_distance = dist[current] + neighbor.first;
        if (current_distance < dist[neighbor.second]) {
          dist[neighbor.second] = current_distance;
          queue.push({-current_distance, neighbor.second});
        }
      }
    }
  }

  cout << dist[0];
  for (int i = 1; i < n; i++) {
    cout << " " << dist[i];
  }
  cout << endl;

  return 0;
}
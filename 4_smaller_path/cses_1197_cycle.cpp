#include <bits/stdc++.h>
#include <limits>
#include <stack>
#include <utility>

using namespace std;

typedef long long int weight;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<pair<weight, int>>> adj(n);
  vector<weight> dist(n, numeric_limits<int>::max());
  vector<int> pred(n);

  for (int i = 0; i < m; i++) {
    int a, b;
    weight c;
    cin >> a >> b >> c;
    a--;
    b--;
    adj[a].push_back({c, b});
  }

  bool has_cycle = false;
  int start_cycle_index = 0;

  dist[0] = 0;
  pred[0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (pair<weight, int> neighbor : adj[j]) {
        weight current_dist = dist[j] + neighbor.first;
        if (current_dist < dist[neighbor.second]) {
          if (i == n - 1) {
            has_cycle = true;
            start_cycle_index = j;
            break;
          }

          dist[neighbor.second] = current_dist;
          pred[neighbor.second] = j;
        }

        if (has_cycle)
          break;
      }

      if (has_cycle)
        break;
    }
  }

  if (has_cycle) {
    cout << "YES" << endl;

    for (int i = 0; i < n; i++) {
      start_cycle_index = pred[start_cycle_index];
    }

    stack<int> cycle;
    int index = start_cycle_index;
    cycle.push(index);

    do {
      index = pred[index];
      cycle.push(index);
    } while (start_cycle_index != index);

    while(!cycle.empty()) {
      cout << (cycle.top() + 1);
      cycle.pop();
      if (!cycle.empty())
        cout << " ";
    }
    cout << endl;
  } else {
    cout << "NO" << endl;
  }
}
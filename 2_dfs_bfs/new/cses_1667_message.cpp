#include <bits/stdc++.h>

using namespace std;

const int start_index = 0;
int end_index = 0;

int main() {
  int n, m;
  cin >> n >> m;
  end_index = n - 1;
  vector<vector<int>> adj(n);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  bool found = false;
  queue<int> queue;
  vector<bool> visited(n, false);
  vector<int> predecesor(n, -1);

  queue.push(start_index);
  predecesor[start_index] = start_index;
  visited[start_index] = true;

  while (!queue.empty() && !found) {
    int current = queue.front();
    queue.pop();

    for (int j : adj[current]) {
      if (!visited[j]) {
        visited[j] = true;
        predecesor[j] = current;
        queue.push(j);

        if (j == end_index)
          found = true;
      }
    }
  }

  if (found) {
    stack<int> path;
    path.push(end_index);
    int current = end_index;
    int current_predecesor = predecesor[current];
    while (current != current_predecesor) {
      path.push(current_predecesor);
      current = current_predecesor;
      current_predecesor = predecesor[current];
    }

    cout << path.size() << endl;
    while (!path.empty()) {
      int current_path = path.top();
      path.pop();
      cout << (current_path + 1);
      if (!path.empty())
        cout << " ";
      else
        cout << endl;
    }
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
}
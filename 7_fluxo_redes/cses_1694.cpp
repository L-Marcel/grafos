#include <bits/stdc++.h>
#include <cstdlib>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> adj;
vector<vector<long long>> capacity;
vector<vector<long long>> flow;
vector<int> pred;

bool bfs() {
  queue<int> queue;
  queue.push(0);
  pred[0] = 0;

  while (!queue.empty()) {
    int k = queue.front();
    queue.pop();

    if (k == n - 1)
      return true;

    for (int i : adj[k]) {
      long long diff = capacity[k][i] - flow[k][i];
      if (diff > 0 && pred[i] == -1) {
        pred[i] = k;
        queue.push(i);
      }
    }
  }

  return false;
}

int main() {
  cin >> n >> m;
  adj.resize(n, vector<int>());
  capacity.resize(n, vector<long long>(n, 0));
  flow.resize(n, vector<long long>(n, 0));
  pred.resize(n, -1);

  for (int i = 0; i < m; i++) {
    int a, b;
    long long c;
    cin >> a >> b >> c;
    a--;
    b--;

    adj[a].push_back(b);
    adj[b].push_back(a);
    capacity[a][b] += c;
    capacity[b][a] += 0l;
    flow[a][b] = 0l;
    flow[b][a] = 0l;
  }

  long long max_flow = 0;
  while (bfs()) {
    long long ceil = LLONG_MAX;

    int current = n - 1;
    while (current != 0) {
      int previous = pred[current];
      long long diff = capacity[previous][current] - flow[previous][current];
      ceil = min(ceil, diff);
      current = previous;
    }

    current = n - 1;
    while (current != 0) {
      int previous = pred[current];
      flow[previous][current] += ceil;
      flow[current][previous] -= ceil;
      current = previous;
    }

    max_flow += ceil;
    fill(pred.begin(), pred.end(), -1);
  }

  cout << max_flow << endl;
}
#include <bits/stdc++.h>
#include <cstdlib>
#include <queue>

using namespace std;

int n, m, k, total;
vector<vector<int>> adj;
vector<vector<int>> capacity;
vector<vector<int>> flow;
vector<int> pairs;
vector<int> pred;

bool bfs() {
  queue<int> queue;
  queue.push(0);
  pred[0] = 0;

  while (!queue.empty()) {
    int i = queue.front();
    queue.pop();

    if (i == total - 1)
      return true;

    for (int j : adj[i]) {
      int diff = capacity[i][j] - flow[i][j];
      if (diff > 0 && pred[j] == -1) {
        pred[j] = i;
        queue.push(j);
      }
    }
  }

  return false;
}

int main() {
  cin >> n >> m >> k;
  total = n + m + 2;

  adj.resize(total, vector<int>());
  capacity.resize(total, vector<int>(total, 0));
  flow.resize(total, vector<int>(total, 0));
  pred.resize(total, -1);

  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    b += n;

    adj[a].push_back(b);
    adj[b].push_back(a);
    capacity[a][b] = 1;
  }

  for (int i = 1; i <= n; i++) {
    adj[0].push_back(i);
    adj[i].push_back(0);
    capacity[0][i] = 1;
  }

  for (int i = n + 1; i <= n + m; i++) {
    adj[i].push_back(total - 1);
    adj[total - 1].push_back(i);
    capacity[i][total - 1] = 1;
  }

  int max_flow = 0;
  while (bfs()) {
    int ceil = 1;

    int current = total - 1;
    while (current != 0) {
      int previous = pred[current];
      int diff = capacity[previous][current] - flow[previous][current];
      ceil = min(ceil, diff);
      current = previous;
    }

    current = total - 1;
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

  for (int i = 1; i < (n + 1); i++) {
    for (int j : adj[i]) {
      if (flow[i][j] == 1) {
        cout << i << " " << (j - n) << endl;
        break;
      }
    }
  }
}
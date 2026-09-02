#include <bits/stdc++.h>
#include <limits>

using namespace std;

typedef long long int weight;

const long long INF = numeric_limits<weight>::max();

int main() { 
  int n, m, q;
  cin >> n >> m >> q;

  vector<vector<weight>> dist(
    n, 
    vector<weight>(
      n, 
      INF
    )
  );

  vector<vector<int>> pred(
    n, 
    vector<int>(n, -1)
  );

  for (int i = 0; i < n; i++) {
    dist[i][i] = 0;
    pred[i][i] = i;
  }

  for (int i = 0; i < m; i++) {
    int a, b;
    weight c;
    cin >> a >> b >> c;
    a--;
    b--;
    if (c < dist[a][b]) {
      dist[a][b] = c;
      dist[b][a] = c;
      pred[a][b] = a;
      pred[b][a] = b;
    }
  }

  vector<pair<int, int>> queries(q);
  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    queries[i] = {a, b};
  }

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (
          dist[i][k] != INF &&
          dist[k][j] != INF &&
          dist[i][k] + dist[k][j] < dist[i][j]
        ) {
          dist[i][j] = dist[i][k] + dist[k][j];
          pred[i][j] = pred[k][j];
        }
      }
    }
  }

  for (pair<int, int> query : queries) {
    if (pred[query.first][query.second] != -1)
      cout << dist[query.first][query.second] << endl;
    else
      cout << -1 << endl;
  }

  return 0; 
}
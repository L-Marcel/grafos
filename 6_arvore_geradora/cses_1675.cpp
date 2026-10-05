#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

struct Edge {
  int a;
  int b;
  int cost;
} typedef Edge;

int n, m;
vector<int> fathers;
vector<int> postos;
vector<Edge> edges;

int get_father(int a) {
  if (fathers[a] == a)
    return a;
  fathers[a] = get_father(fathers[a]);
  return fathers[a];
}

void apply_union(int a, int b) {
  a = get_father(a);
  b = get_father(b);

  if (a != b) {
    if (postos[a] > postos[b])
      fathers[b] = a;
    else {
      fathers[a] = b;
      if (postos[a] == postos[b])
        postos[b] = postos[b] + 1;
    }
  }
}

int compare(const void *a, const void *b) {
  Edge ea = *static_cast<const Edge *>(a);
  Edge eb = *static_cast<const Edge *>(b);
  if (ea.cost < eb.cost)
    return -1;
  if (ea.cost > eb.cost)
    return 1;
  return 0;
}

long kruskal() {
  int j = 0;
  long long cost = 0;

  for (int i = 0; i < n - 1; i++) {
    while (j < m && get_father(edges[j].a) == get_father(edges[j].b))
      j++;

    if (j == m)
      return -1;

    cost += edges[j].cost;
    apply_union(edges[j].a, edges[j].b);
  }

  return cost;
}

int main() {
  cin >> n >> m;
  edges.resize(m);

  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    Edge edge{a, b, c};
    edges[i] = edge;
  }

  postos.resize(n);
  fathers.resize(n);

  for (int i = 0; i < n; i++) {
    postos[i] = 0;
    fathers[i] = i;
  }

  qsort(edges.data(), edges.size(), sizeof(Edge), compare);

  long long cost = kruskal();

  if (cost < 0)
    cout << "IMPOSSIBLE" << endl;
  else
    cout << cost << endl;
}
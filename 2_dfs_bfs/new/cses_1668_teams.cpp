#include <bits/stdc++.h>
#include <cstdlib>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int next_team(int team) {
  if (team == 1)
    return 2;
  else
    return 1;
}

bool dfs(int i, int team, vector<int> *result, vector<vector<int>> *adj) {
  stack<int> stack;
  stack.push(i);
  (*result)[i] = team;

  while (!stack.empty()) {
    int current = stack.top();
    int current_team = (*result)[current];
    stack.pop();

    for (int f : (*adj)[current]) {
      if ((*result)[f] == 0) {
        stack.push(f);
        (*result)[f] = next_team(current_team);
      } else if ((*result)[f] == current_team) {
        return false;
      }
    }
  }

  return true;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n, vector<int>());
  vector<int> result = vector<int>(n, 0);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  int team = 1;
  bool has_solution = true;
  for (int i = 0; i < n; i++) {
    if (result[i] == 0) {
      has_solution = dfs(i, team, &result, &adj);
      team = next_team(team);
    }

    if (!has_solution)
      break;
  }

  if (has_solution) {
    bool first = true;
    for (int i : result) {
      if (!first)
        cout << " ";
      cout << i;
      first = false;
    }
    cout << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
}
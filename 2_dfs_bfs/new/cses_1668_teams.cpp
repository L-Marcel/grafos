#include <bits/stdc++.h>
#include <cstdlib>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool has_friend_in_team(int candidate, int team, vector<vector<bool>> *members,
                        vector<vector<bool>> *friendship) {
  for (int i = 0; i < (*members)[team].size(); i++) {
    if ((*members)[team][i] && (*friendship)[candidate][i])
      return true;
  }

  return false;
}

void add_team_member(int member, int team, vector<int> *participations,
                     vector<vector<bool>> *members) {
  (*participations)[member] = team;
  (*members)[team][member] = true;
}

void dfs(int start, int team, vector<vector<bool>> *members,
         vector<int> *participations, vector<vector<bool>> *friendship) {
  int n = (*participations).size();

  stack<int> stack;
  stack.push(start);
  add_team_member(start, team, participations, members);

  while (!stack.empty()) {
    int current = stack.top();
    stack.pop();

    for (int i = 0; i < n; i++) {
      if (i != current && (*participations)[i] < 0 &&
          !has_friend_in_team(i, team, members, friendship)) {
        add_team_member(i, team, participations, members);
        stack.push(i);
      }
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<bool>> friendship(n, vector<bool>(n, false));
  vector<vector<bool>> members = vector<vector<bool>>();
  vector<int> participations(n, -1);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    friendship[a][b] = true;
    friendship[b][a] = true;
  }

  int team = 0;
  members.push_back(vector<bool>(n, false));
  for (int i = 0; i < n; i++) {
    if (participations[i] < 0) {
      dfs(i, team, &members, &participations, &friendship);
      team++;
      members.push_back(vector<bool>(n, false));
    }
  }

  if (team == 2) {
    bool first = true;
    for (int i : participations) {
      if (!first)
        cout << " ";
      cout << (i + 1);
      first = false;
    }
    cout << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
}
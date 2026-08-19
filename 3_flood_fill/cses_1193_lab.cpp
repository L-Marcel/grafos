#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;
typedef pair<int, int> position;
typedef vector<vector<char>> matrix;
typedef vector<vector<bool>> visited_matrix;

const char FLOOR = '.';
const char WALL = '#';
const char START = 'A';
const char END = 'B';
const char LEFT = 'L';
const char RIGHT = 'R';
const char UP = 'U';
const char DOWN = 'D';

void print_map(matrix map) {
  for (vector<char> row : map) {
    for (char cell : row) {
      cout << cell;
    }
    cout << "\n";
  }
}

pair<matrix, position> fill_map(matrix map) {
  position start_index;

  for (int i = 0; i < map.size(); i++) {
    for (int j = 0; j < map[i].size(); j++) {
      char cell;
      cin >> cell;
      map[i][j] = cell;
      if (cell == START)
        start_index = make_pair(i, j);
    }
  }

  return make_pair(map, start_index);
}

pair<vector<char>, bool> dfs(matrix map, position start_index) {
  vector<char> path = vector<char>();
  stack<position> stack;
  // vector<vector<bool>> visiteds = vector();
  bool found = false;

  stack.push(start_index);

  return make_pair(path, found);
}

int main() {
  int h, w;
  cin >> h >> w;
  int nodes = h + w;

  matrix map(h, vector<char>(w, WALL));
  position start_index;

  pair<matrix, position> fill = fill_map(map);
  map = fill.first;
  start_index = fill.second;

  print_map(map);

  dfs(map, start_index);
}
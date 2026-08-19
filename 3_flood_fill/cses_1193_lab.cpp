#include <bits/stdc++.h>
#include <cstdlib>
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
    cout << endl;
  }
}

pair<matrix, position> fill_map(matrix map) {
  position start_position;

  for (int i = 0; i < map.size(); i++) {
    for (int j = 0; j < map[i].size(); j++) {
      char cell;
      cin >> cell;
      map[i][j] = cell;
      if (cell == START)
        start_position = make_pair(i, j);
    }
  }

  return make_pair(map, start_position);
}

pair<stack<char>, bool> bfs(matrix map, int h, int w, position start_position) {
  queue<position> queue;
  vector<vector<position>> predecessors =
      vector(h, vector<position>(w, make_pair(-1, -1)));
  vector<vector<bool>> visiteds = vector(h, vector<bool>(w, false));

  position end_position = start_position;
  bool found = false;

  queue.push(start_position);
  visiteds[start_position.first][start_position.second] = true;
  predecessors[start_position.first][start_position.second] = start_position;

  while (!queue.empty()) {
    position current_start_position = queue.front();
    queue.pop();

    for (int di = -1; di <= 1; di++) {
      for (int dj = -1; dj <= 1; dj++) {
        if (abs(di) == abs(dj))
          continue;

        int i = current_start_position.first + di;
        int j = current_start_position.second + dj;
        if (i < 0 || j < 0 || i >= h || j >= w)
          continue;

        if (!visiteds[i][j]) {
          position current_cell_position = make_pair(i, j);

          if (map[i][j] != WALL)
            queue.push(current_cell_position);

          if (map[i][j] == END) {
            end_position = current_cell_position;
            found = true;
          }

          visiteds[i][j] = true;
          predecessors[i][j] = current_start_position;
        }
      }
    }
  }

  stack<char> reverse_path = stack<char>();
  if (found) {
    position current_cell_position = end_position;
    position predecessor =
        predecessors[current_cell_position.first][current_cell_position.second];

    while (predecessor.first != current_cell_position.first ||
           predecessor.second != current_cell_position.second) {
      int di = predecessor.first - current_cell_position.first;
      int dj = predecessor.second - current_cell_position.second;

      if (di > 0)
        reverse_path.push(UP);
      else if (di < 0)
        reverse_path.push(DOWN);
      else if (dj > 0)
        reverse_path.push(LEFT);
      else
        reverse_path.push(RIGHT);

      current_cell_position = predecessor;
      predecessor = predecessors[current_cell_position.first]
                                [current_cell_position.second];
    }
  }

  return make_pair(reverse_path, found);
}

int main() {
  int h, w;
  cin >> h >> w;
  int nodes = h + w;

  matrix map(h, vector<char>(w, WALL));
  position start_position;

  pair<matrix, position> fill = fill_map(map);
  map = fill.first;
  start_position = fill.second;

  // print_map(map);

  pair<stack<char>, bool> result = bfs(map, h, w, start_position);
  stack<char> reverse_path = result.first;
  bool found = result.second;

  if (found) {
    cout << "YES" << endl;
    cout << reverse_path.size() << endl;
    while (!reverse_path.empty()) {
      char command = reverse_path.top();
      reverse_path.pop();
      cout << command;
    }
    cout << endl;
  } else {
    cout << "NO" << endl;
  }
}
#include <bits/stdc++.h>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

const char GROUND = '#';
const char WATER = '.';

const int UNKNOWN = -1;
const int OCEAN = 0;
const int ISLAND = 1;
const int LAKE = 2;

int main() {
  int w, h;
  cin >> h >> w;

  vector<vector<char>> matrix(w, vector<char>(h));
  vector<vector<int>> states(w, vector<int>(h, UNKNOWN));
  vector<vector<int>> debug_islands(w, vector<int>(h, -1));

  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h; j++) {
      char v;
      cin >> v;
      matrix[i][j] = v;
    }
  }

  queue<pair<int, int>> queue;
  queue.push({0, 0});
  states[0][0] = {OCEAN};
  debug_islands[0][0] = -1;

  while (!queue.empty()) {
    pair<int, int> k = queue.front();
    queue.pop();

    for (int dx = -1; dx <= 1; dx++) {
      for (int dy = -1; dy <= 1; dy++) {
        if (dx == 0 && dy == 0)
          continue;

        int x = k.first + dx;
        int y = k.second + dy;

        if (x < 0 || x >= w || y < 0 || y >= h)
          continue;

        if (states[x][y] == UNKNOWN && matrix[x][y] == WATER) {
          states[x][y] = OCEAN;
          debug_islands[x][y] = -1;
          queue.push({x, y});
        }
      }
    }
  }

  vector<vector<pair<int, int>>> components(0, vector<pair<int, int>>());

  int islands_with_lake = 0;
  int bigger = 0;
  int component = 0;
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h; j++) {
      if (states[i][j] == UNKNOWN) {
        components.push_back(vector<pair<int, int>>());
        queue.push({i, j});
        bool has_lake = false;
        while (!queue.empty()) {
          pair<int, int> k = queue.front();
          queue.pop();

          if (matrix[k.first][k.second] == GROUND) {
            components[component].push_back({k.first, k.second});
            states[k.first][k.second] = ISLAND;
            debug_islands[k.first][k.second] = component;

            for (int dx = -1; dx <= 1; dx++) {
              for (int dy = -1; dy <= 1; dy++) {
                if (dx == 0 && dy == 0)
                  continue;

                int x = k.first + dx;
                int y = k.second + dy;

                if (x < 0 || x >= w || y < 0 || y >= h)
                  continue;

                if (states[x][y] == UNKNOWN && matrix[x][y] == GROUND) {
                  states[x][y] = ISLAND;
                  queue.push({x, y});
                  debug_islands[x][y] = component;
                } else if (states[x][y] == UNKNOWN && matrix[x][y] == WATER) {
                  states[x][y] = LAKE;
                  queue.push({x, y});
                  has_lake = true;
                  debug_islands[x][y] = -1;
                }
              }
            }
          }
        }

        if (components[bigger].size() < components[component].size()) {
          bigger = component;
        }

        if (has_lake)
          islands_with_lake++;
        component++;
      }
    }
  }

  cout << "components: " << endl;
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h; j++) {
      if (debug_islands[i][j] == -1) {
        cout << ". ";
      } else {
        cout << debug_islands[i][j] << " ";
      }
    }
    cout << endl;
  }

  cout << "estados: " << endl;
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h; j++) {
      cout << states[i][j] << " ";
    }
    cout << endl;
  }

  cout << "matrix: " << endl;
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }

  if (components.size() == 0) {
    cout << "Não tem ilha" << endl;
    return 0;
  };

  cout << "Maior ilha: " << bigger << endl;
  cout << "Tamanho da maior ilha: " << components[bigger].size() << endl;
  cout << "Célula de referência da maior ilha: " << components[bigger][0].second
       << ", " << components[bigger][0].first << endl;
  cout << "Quantas ilhas tem lago: " << islands_with_lake << endl;
}
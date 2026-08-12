#include <bits/stdc++.h>
#include <ostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> m(n, vector<int>(n, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int x;
      cin >> x;
      m[i][j] = x;
      m[j][i] = x;
    }
  }

  for (int i = 0; i < n; i++) {
    bool has_some = false;
    for (int j = 0; j < n; j++) {
      int x = m[i][j];
      if (x == 1) {
        if (has_some)
          cout << " ";
        else if (i != 0)
          cout << endl;
        cout << (j + 1);
        has_some = true;
      }
    }
  }
}
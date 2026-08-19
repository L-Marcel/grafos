#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void imprimir_lista_adjacencia(vector<vector<int>> lista_adjacencia) {
  for (int i = 0; i < lista_adjacencia.size(); i++) {
    cout << "[" << (i + 1) << "]:";
    for (int j : lista_adjacencia[i]) {
      cout << " " << (j + 1);
    }
    cout << "\n";
  }
}

void imprimir_visitados(vector<bool> visitados) {
  cout << "visitados:";
  for (int i = 0; i < visitados.size(); i++) {
    if (visitados[i])
      cout << " " << (i + 1);
  }
  cout << "\n";
}

void imprimir_iniciais(vector<int> iniciais) {
  cout << "iniciais:";
  for (int i : iniciais) {
    cout << " " << (i + 1);
  }
  cout << "\n";
}

vector<int> montar_iniciais() {
  int quantidade_iniciais;
  cin >> quantidade_iniciais;
  vector<int> iniciais;
  for (int i = 0; i < quantidade_iniciais; i++) {
    int inicial;
    cin >> inicial;
    iniciais.push_back(inicial - 1);
  }

  // imprimir_iniciais(iniciais);
  return iniciais;
}

vector<vector<int>> montar_lista_adjacencia(int n) {
  vector<vector<int>> lista_adjacencia(n, vector<int>());

  while (true) {
    int current;
    cin >> current;
    if (current == 0)
      break;
    while (current != 0) {
      int next;
      cin >> next;
      if (next != 0) {
        lista_adjacencia[current - 1].push_back(next - 1);
        // cout << "edge: " << current << " -> " << next << "\n";
      }
      current = next;
    };
  }

  // imprimir_lista_adjacencia(lista_adjacencia);
  return lista_adjacencia;
}

vector<vector<int>> identificar_inalcancaveis(int n) {
  if (n == 0)
    return vector<vector<int>>();

  vector<vector<int>> inalcancaveis;
  vector<vector<int>> lista_adjacencia = montar_lista_adjacencia(n);
  vector<int> iniciais = montar_iniciais();

  for (int i : iniciais) {
    stack<int> pilha;
    vector<bool> visitados(n, false);

    pilha.push(i);

    while (!pilha.empty()) {
      int k = pilha.top();
      pilha.pop();
      // cout << "em: " << (k + 1) << "\n";
      for (int v : lista_adjacencia[k]) {
        if (!visitados[v]) {
          // cout << "visitou: " << (v + 1) << "\n";
          visitados[v] = true;
          pilha.push(v);
        }
      }
    }

    // imprimir_visitados(visitados);
    vector<int> inalcancados;
    for (int i = 0; i < n; i++) {
      bool visitado = visitados[i];
      if (!visitado)
        inalcancados.push_back(i);
    }

    inalcancaveis.push_back(inalcancados);
  }

  return inalcancaveis;
}

int main() {
  int n;
  vector<vector<int>> inalcancaveis;
  while (true) {
    cin >> n;
    if (n == 0)
      break;
    vector<vector<int>> inalcancados = identificar_inalcancaveis(n);
    for (vector<int> i : inalcancados)
      inalcancaveis.push_back(i);
  };

  for (vector<int> _inalcancaveis : inalcancaveis) {
    cout << _inalcancaveis.size();
    for (int i : _inalcancaveis) {
      cout << " " << (i + 1);
    }
    cout << "\n";
  }
}
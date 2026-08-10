#include <bits/stdc++.h>

using namespace std;

// OBSERVAÇÃO: todas as questões devem ser resolvidas com recursão, sem utilizar
// nenhum for/while

// retorna a soma dos elementos entre os índices a e b do vetor v
// por exemplo, sendo v = {4, 5, 2, 1, 3}, somaElementos(v, 0, 2) deve retornar
// 11
int somaElementos(vector<int> v, int a, int b) {
  if (a == b)
    return v[a];
  else
    return v[a] + somaElementos(v, a + 1, b);
}

// retorna se a substring s entre os índices a e b é um palíndromo
// por exemplo, ehPalindromo("fbabg", 1, 3) deve retornar true pois a substring
// "bab" é um palíndromo
bool ehPalindromo(string s, int a, int b) {
  if (a >= b)
    return true;
  else
    return s[a] == s[b] && ehPalindromo(s, a + 1, b - 1);
}

// retorna a quantidade de elementos gerados a partir de n seguindo as regras do
// problema 3n+1 se n for ímpar, multiple por 3 e some 1; se for par, divida por
// 2; repita até chegar em 1 por exemplo, qtdElementos3n1(5) deve retornar 6,
// pois a sequência gerada (5 16 8 4 2 1) possui 6 elementos
int qtdElementos3n1(int n) {
  if (n == 1)
    return 1;
  else if ((n % 2) == 0)
    return 1 + qtdElementos3n1(n / 2);
  else
    return 1 + qtdElementos3n1((n * 3) + 1);
}

// retorna a soma dos dígitos de um número n. O número pode ser negativo.
int somaDigitos(int n) {
  if (n < 0)
    return somaDigitos(n * -1);
  else if (n < 10)
    return n;
  else {
    int digito = n % 10;
    return digito + somaDigitos((n - digito) / 10);
  }
}

// retorna a string palindromo k(k-1)(k-2)...a...(k-2)(k-1)k, onde k é um
// caractere, k-1 é o caractere anterior, etc por exemplo, gerarPalindromo('d')
// deve retornar dcbabcd gerarPalindromo('e') deve retornar edcbabcde lembre-se
// de que você pode concatenar strings com o operador +
string gerarPalindromo(char k) {
  if (k == 'a')
    return "a";
  else
    return k + gerarPalindromo(k - 1) + k;
}

// retorna o resultado da exponenciação base^expoente
// considere que o expoente é sempre não negativo
// por exemplo, potencia(2, 3) deve retornar 8
int potencia(int base, int expoente) {
  if (expoente == 0)
    return 1;
  else
    return base * potencia(base, expoente - 1);
}

// retorna se é possível compor (sem resto) n reais com x notas de a reais e y
// notas de b reais não precisa necessariamente utilizar todas as notas por
// exemplo, saquePossivel(10, 1, 5, 1, 10) retorna true, pois dá para compor 10
// reais com 1 nota de 10 reais saquePossivel(13, 4, 1, 3, 5) retorna true, pois
// dá para compor 13 reais com 3 notas de 1 real e 2 notas de 5 reais
// saquePossivel(13, 2, 1, 3, 5) retorna false, pois não dá para compor 13 reais
// tendo 2 notas disponíveis de 1 e 3 notas disponíveis de 5
bool saquePossivel(int n, int x, int a, int y, int b) {
  if (x < 0 || y < 0)
    return false;

  int a_max = x * a;
  int b_max = y * b;

  if (a_max + b_max == n)
    return true;
  else if (a_max + b_max < n)
    return false;
  else
    return saquePossivel(n, x - 1, a, y, b) || saquePossivel(n, x, a, y - 1, b);
}

int main() {
  int op;
  cout << "Escolha a função a ser testada: " << endl;
  cout << "1: somaElementos" << endl;
  cout << "2: ehPalindromo" << endl;
  cout << "3: qtdElementos3n1" << endl;
  cout << "4: somaDigitos" << endl;
  cout << "5: gerarPalindromo" << endl;
  cout << "6: potencia" << endl;
  cout << "7: saquePossivel" << endl;
  cout << "0: todas as funções" << endl;

  cin >> op;

  if (op == 0 || op == 1) {
    vector<int> v = {4, 5, 2, 1, 3};
    assert(somaElementos(v, 0, 2) == 11);
    assert(somaElementos(v, 2, 4) == 6);
  }

  if (op == 0 || op == 2) {
    assert(ehPalindromo("", 0, 0) == 1);
    assert(ehPalindromo("a", 0, 0) == 1);
    assert(ehPalindromo("aba", 0, 2) == 1);
    assert(ehPalindromo("abba", 0, 3) == 1);
    assert(ehPalindromo("abcba", 0, 4) == 1);
    assert(ehPalindromo("abccba", 0, 5) == 1);
    assert(ehPalindromo("abcd", 0, 3) == 0);
    assert(ehPalindromo("abccbx", 0, 5) == 0);
    assert(ehPalindromo("araara", 0, 5) == 1);
    assert(ehPalindromo("fbabg", 1, 3) == 1);
    assert(ehPalindromo("fbabg", 0, 4) == 0);
    assert(ehPalindromo("arara", 0, 4) == 1);
    assert(ehPalindromo("asa", 0, 2) == 1);
    assert(ehPalindromo("osso", 0, 3) == 1);
    assert(ehPalindromo("ovo", 0, 2) == 1);
    assert(ehPalindromo("radar", 0, 4) == 1);
    assert(ehPalindromo("reviver", 0, 6) == 1);
    assert(ehPalindromo("salas", 0, 4) == 1);
    assert(ehPalindromo("anilina", 0, 6) == 1);
    assert(ehPalindromo("mirim", 0, 4) == 1);
    assert(ehPalindromo("socos", 0, 4) == 1);
    assert(ehPalindromo("amor a roma", 0, 10) == 1);
    assert(ehPalindromo("1234321", 0, 6) == 1);
    assert(ehPalindromo("1234322", 0, 6) == 0);
    assert(ehPalindromo("anotaram a data da maratona", 0, 26) == 0);
  }

  if (op == 0 || op == 3) {
    assert(qtdElementos3n1(5) == 6);
    assert(qtdElementos3n1(6) == 9);
  }

  if (op == 0 || op == 4) {
    assert(somaDigitos(810027) == 18);
    assert(somaDigitos(-1823) == 14);
  }

  if (op == 0 || op == 5) {
    assert(gerarPalindromo('a') == "a");
    assert(gerarPalindromo('c') == "cbabc");
    assert(gerarPalindromo('e') == "edcbabcde");
    assert(gerarPalindromo('z') ==
           "zyxwvutsrqponmlkjihgfedcbabcdefghijklmnopqrstuvwxyz");
  }

  if (op == 0 || op == 6) {
    assert(potencia(2, 3) == 8);
    assert(potencia(2, 5) == 32);
    assert(potencia(3, 5) == 243);
    assert(potencia(7, 2) == 49);
    assert(potencia(5, 0) == 1);
  }

  if (op == 0 || op == 7) {
    assert(saquePossivel(56, 9, 6, 8, 2) == 1);
    assert(saquePossivel(50, 10, 8, 9, 5) == 1);
    assert(saquePossivel(21, 4, 7, 3, 3) == 1);
    assert(saquePossivel(56, 6, 7, 9, 2) == 1);
    assert(saquePossivel(85, 6, 3, 10, 7) == 1);
    assert(saquePossivel(96, 8, 9, 9, 8) == 1);
    assert(saquePossivel(9, 0, 9, 6, 3) == 1);
    assert(saquePossivel(9, 0, 5, 3, 3) == 1);
    assert(saquePossivel(27, 7, 7, 5, 9) == 1);
    assert(saquePossivel(20, 6, 3, 8, 7) == 1);
    assert(saquePossivel(31, 6, 6, 4, 7) == 1);
    assert(saquePossivel(14, 6, 3, 1, 2) == 1);
    assert(saquePossivel(60, 8, 6, 10, 6) == 1);
    assert(saquePossivel(18, 4, 4, 2, 7) == 1);
    assert(saquePossivel(36, 8, 3, 5, 7) == 1);
    assert(saquePossivel(29, 5, 7, 8, 2) == 1);
    assert(saquePossivel(98, 7, 9, 8, 7) == 1);
    assert(saquePossivel(80, 5, 4, 10, 9) == 1);
    assert(saquePossivel(69, 10, 7, 6, 6) == 1);
    assert(saquePossivel(14, 5, 4, 6, 5) == 1);
    assert(saquePossivel(83, 1, 9, 9, 10) == 0);
    assert(saquePossivel(84, 8, 9, 6, 1) == 0);
    assert(saquePossivel(84, 4, 2, 9, 7) == 0);
    assert(saquePossivel(37, 6, 3, 8, 9) == 0);
    assert(saquePossivel(58, 9, 10, 1, 5) == 0);
    assert(saquePossivel(4, 9, 3, 5, 3) == 0);
    assert(saquePossivel(81, 10, 5, 3, 1) == 0);
    assert(saquePossivel(99, 3, 5, 1, 6) == 0);
    assert(saquePossivel(66, 7, 6, 3, 5) == 0);
    assert(saquePossivel(11, 2, 9, 1, 8) == 0);
    assert(saquePossivel(14, 10, 6, 5, 10) == 0);
    assert(saquePossivel(8, 2, 1, 7, 9) == 0);
    assert(saquePossivel(15, 4, 2, 0, 3) == 0);
    assert(saquePossivel(30, 2, 8, 0, 8) == 0);
    assert(saquePossivel(14, 6, 10, 3, 3) == 0);
    assert(saquePossivel(88, 9, 3, 2, 5) == 0);
    assert(saquePossivel(27, 1, 1, 4, 7) == 0);
    assert(saquePossivel(73, 2, 10, 5, 7) == 0);
    assert(saquePossivel(83, 2, 7, 0, 1) == 0);
    assert(saquePossivel(84, 0, 1, 8, 7) == 0);
  }

  return 0;
}

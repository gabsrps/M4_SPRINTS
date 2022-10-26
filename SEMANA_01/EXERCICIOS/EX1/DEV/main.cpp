// Ex 1:
/*
#include <iostream>
using namespace std;

int main() {
  int num1 = 0, num2 = 0, num3 = 0;

  cout << "Escreva o número de medida: ";
  cin >> num1;
  cout << "Escreva o número máximo: ";
  cin >> num2;
  cout << "Escreva o número mínimo: ";
  cin >> num3;

  int sub1 = 0, sub2 = 0;
  sub1 = num1 - num3;
  cout << "Subtração da medida pelo mínimo: " << sub1 << endl;

  sub2 = num2 - num3;
  cout << "Subtração do máximo pelo mínimo: " << sub2 << endl;

  if (num1 > num2) {
    cout << "A medida é maior que o valor máximo! ";
  } else if (num1 < num3) {
    cout << "A medida é menor que o valor mínimo! ";
  } else {
    cout << num1 << " vale ";
  }
  float res = 0;
  res = sub1 * 100 / sub2;
  cout << res << "% do intervalo entre " << num3 << " e " << num2;
}
*/

// Ex 2:
/*
#include <iostream>

using namespace std;

int main() {
  int num;
      cout << "Digite um número:" <<endl;
  cin >> num;

  cout << "Seu número é: " << num <<endl;
}
*/

// Ex3:
/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
int num = 0;
  vector<int> vetor {1, 2, 3, 4, 5};

  cout << "\nVetor inicial: ";

  for (const int& i : vetor) {
    cout << i << "  ";
  }

cout << "\nDigite um número para adicionar ao vetor: " <<endl;
cin >> num;

  vetor.push_back(num);

  cout << "\nO tamanho do vetor é: " << vetor.size() <<endl;


  cout << "\nVetor atualizado: ";
  for (const int& i : vetor) {
    cout << i << "  ";

  }

  return 0;
}
*/

// Ex 4:
/*
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
int main() {
int num = 0, direita = 0, esquerda = 0, frente = 0, tras = 0, maior_val = 0;
  vector<int> vetor {};

  cout << "\nInsira o valor de direita: ";
  cin >> direita;
  vetor.push_back(direita);

  cout << "\nInsira o valor de esquerda: ";
  cin >> esquerda;
  vetor.push_back(esquerda);

  cout << "\nInsira o valor de frente: ";
  cin >> frente;
  vetor.push_back(frente);

  cout << "\nInsira o valor de trás: ";
  cin >> tras;
  vetor.push_back(tras);

  cout << "\nO vetor é esse: ";
  for (const int& i : vetor) {
    cout << i << "  ";
    }
    maior_val = *max_element(vetor.begin(), vetor.end());
    cout << "\nValor máximo: " << maior_val <<endl;

  if (direita == maior_val){
    cout << "direita";
    }else if (esquerda == maior_val){
    cout << "esquerda";
    }else if (frente == maior_val){
    cout << "frente";
    }else if (tras == maior_val){
    cout << "trás";
  }
}
*/

// Ex 5:
/*
#include <iostream>
using namespace std;
int main() {
int val = 1;
  while (val != 0){
    cout << "Digite 0 ou 1 " <<endl;
    cin >> val;
    while (val != 0) {
      cout << "Acesso negado! Tente digitar outra vez: " <<endl;
      cin >> val;
  if (val != 1) {
    cout << "Acesso concedido!";
}}}}
*/

// Ex 6:
/*
#include <bits/stdc++.h>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int main() {
int num = 0, direita = 0, esquerda = 0, frente = 0, tras = 0;
  cout << "\nDigite o valor de direita: ";
  cin >> direita;
  cout << "\nDigite o valor de esquerda: ";
  cin >> esquerda;
  cout << "\nDigite o valor de frente: ";
  cin >> frente;
  cout << "\nDigite o valor de trás: ";
  cin >> tras;

  cout << "{Direita: " << direita << "; Esquerda: " << esquerda << "; Frente: "
<< frente << "; Trás: " << tras << "}";

  }
*/
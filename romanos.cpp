#include "romanos.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<char> vetor_chars = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
vector<int> vetor_valores = {1,5,10,50,100,500,1000};

bool numero_valido(string num_romano){
  char char_anterior;
  int cont = 1;
  for (int i = 0; i < num_romano.size(); i++){
    // Numeros romanos inválidos - com algarismo inválido
    if (num_romano[i] != 'I' && num_romano[i] != 'V' && num_romano[i] != 'X' && num_romano[i] != 'L' && num_romano[i] != 'C' && num_romano[i] != 'D' && num_romano[i] != 'M') return false;

    // Numeros romanos inválidos - algarismos como V, L e D repetidos mais que uma vez
    if ( (num_romano[i] == 'V' || num_romano[i] == 'L' || num_romano[i] == 'D') && ( num_romano[i] == char_anterior)  ) return false;
    
    // Numeros romanos inválidos - algarismos que podem ser usados para subtração, porém nao mais de uma vez
    if (num_romano[i] == char_anterior) cont++;
    else{
      char_anterior = num_romano[i];
      cont = 1;
    }

    if (cont == 4){
      return false;
    }
  }
  // resetar char_anterior
  char_anterior = 'a';

  int valor_anterior = 1000;
  int indexAnterior = 1000;

  for ( int stringIndex = 0; stringIndex < num_romano.size(); stringIndex++){
    for ( int vetorIndex = 0; vetorIndex < 7; vetorIndex++){
      if ( num_romano[stringIndex] == vetor_chars[vetorIndex]){
        if ( valor_anterior < vetor_valores[vetorIndex]){
          // Numeros romanos inválidos - algarismos como V, L e D usados na operação de subtração
          if ( char_anterior == 'V' || char_anterior == 'L' || char_anterior == 'D')return false;

          // Numeros romanos - ordem inválida de algorismos
          else if (vetorIndex - indexAnterior > 2) return false;

          // Numeros romanos inválidos - algarismos que podem ser usados para subtração, porém nao mais de uma vez
          else if( char_anterior == num_romano[stringIndex - 2]) return false;
          
        }

      indexAnterior = vetorIndex;
      valor_anterior = vetor_valores[vetorIndex];
      char_anterior = vetor_chars[vetorIndex];
      break;
      }
    }
  }          
  return true;
}

int romanos_para_decimal(string num_romano){
  // checa se o numero eh valido
  if (!numero_valido(num_romano)) return -1;

  int resultado = 0;
  char char_anterior = 'a';
  int valor_anterior = 1000;
  int indexAnterior = 1000;

  for (int stringIndex = 0; stringIndex < num_romano.size(); stringIndex++){
    for (int vetorIndex = 0; vetorIndex < 7; vetorIndex++){
      if (num_romano[stringIndex] == vetor_chars[vetorIndex]){
        // subtracao
        if (valor_anterior < vetor_valores[vetorIndex]) resultado -= valor_anterior * 2;
        
        indexAnterior = vetorIndex;
        valor_anterior = vetor_valores[vetorIndex];
        char_anterior = vetor_chars[vetorIndex];
        resultado += valor_anterior;
        break;
      }
    }
  }
  // Numeros romanos inválidos - algarismos maior que 3000
  if (resultado == 0 || resultado > 3000) return -1;
  return resultado;
}


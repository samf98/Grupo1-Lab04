
#include <iostream>

using namespace std;

int** crearMatriz(int**, int);

void liberarEspacio(int**);

int main() {

  cout<<"1-Frontal"<<endl<<"2 - Trasera"<<endl<<"3 - Superior"<<endl<<
  "4 - Inferior"<<endl<<"5 - Izquierda"<<endl<<"6 - Derecha"<<endl;
  int** matriz_frontal;
  int** matriz_trasera;
  int** matriz_superior;
  int** matriz_inferior;
  int** matriz_izquierda;
  int** matriz_derecha;

  matriz_frontal = new int*[3];

  for (int i = 0; i < 3; i++) {
    matriz_frontal[i] = new int[3];
  }

  matriz_trasera = new int*[3];

  for (int i = 0; i < 3; i++) {
    matriz_trasera[i] = new int[3];
  }

  matriz_superior = new int*[3];

  for (int i = 0; i < 3; i++) {
    matriz_superior[i] = new int[3];
  }

  matriz_inferior = new int*[3];

  for (int i = 0; i < 3; i++) {
    matriz_inferior[i] = new int[3];
  }

  matriz_izquierda = new int*[3];

  for (int i = 0; i < 3; i++) {
    matriz_izquierda[i] = new int[3];
  }

  matriz_derecha = new int*[3];

  for (int i = 0; i < 3; i++) {
    matriz_derecha[i] = new int[3];
  }
  /*crearMatriz(matriz_frontal,1);
  crearMatriz(matriz_trasera,2);
  crearMatriz(matriz_superior,3);
  crearMatriz(matriz_inferior,4);
  crearMatriz(matriz_izquierda,5);
  crearMatriz(matriz_derecha,6);*/

  liberarEspacio(matriz_frontal);
  liberarEspacio(matriz_trasera);
  liberarEspacio(matriz_superior);
  liberarEspacio(matriz_inferior);
  liberarEspacio(matriz_izquierda);
  liberarEspacio(matriz_derecha);
  return 0;

}
/*
int** crearMatriz(int** matriz, int posicion)
{
  matriz = new int*[3];
  cout<<"Matriz "<<posicion<<" creada"<<endl;
  for(int i = 0; i < 3; i++)
  {
    matriz = new int[3];
  }

  for(i = 0; i < 3; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      matriz[i][j] = i;
    }
  }
  return matriz;

}*/

void liberarEspacio(int** matriz)
{
  cout<<"Liberando espacio"<<endl;
  for(int i = 0; i < 3; i++)
  {
    delete[] matriz[i];
    matriz[i] = NULL;
  }
  delete[] matriz;

}


#include <iostream>

using namespace std;

void llenarMatriz(int**, int);

void liberarEspacio(int**);

void superior_clockwise(int**mint**,int**,int**);

void superior_anticlockwise(int**,int**,int**,int**);

void inferior_clockwise(int**mint**,int**,int**);

void inferior_anticlockwise(int**,int**,int**,int**);

void izquierda_clockwise(int**mint**,int**,int**);

void izquierda_anticlockwise(int**,int**,int**,int**);

void derecha_clockwise(int**mint**,int**,int**);

void derecha_anticlockwise(int**,int**,int**,int**);

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
  llenarMatriz(matriz_frontal,1);

  matriz_trasera = new int*[3];

  for (int i = 0; i < 3; i++) {
    matriz_trasera[i] = new int[3];
  }
  llenarMatriz(matriz_trasera,2);

  matriz_superior = new int*[3];

  for (int i = 0; i < 3; i++) {
    matriz_superior[i] = new int[3];
  }
  llenarMatriz(matriz_superior,3);

  matriz_inferior = new int*[3];

  for (int i = 0; i < 3; i++) {
    matriz_inferior[i] = new int[3];
  }
  llenarMatriz(matriz_inferior,4);

  matriz_izquierda = new int*[3];

  for (int i = 0; i < 3; i++) {
    matriz_izquierda[i] = new int[3];
  }
  llenarMatriz(matriz_izquierda,5);

  matriz_derecha = new int*[3];

  for (int i = 0; i < 3; i++) {
    matriz_derecha[i] = new int[3];
  }
  llenarMatriz(matriz_derecha,6);
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

void llenarMatriz(int** matriz, int posicion)
{
  cout<<"Matriz "<<posicion<<" creada"<<endl;

  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      matriz[i][j] = posicion;
    }
  }

}

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

//revisa movimiento clockwise de la cara superior
void superior_clockwise(int**frontal, int**izquierda, int**trasera, int**derecha){
  int posicion1, int posicion2, int posicion3, int posicion4, int posicion5, int posicion6;
  posicion1 = frontal[0][0];
  posicion2 = frontal[0][1];
  posicion3 = frontal[0][2];

  frontal[0][0] = izquierda[0][0];
  forntal[0][1] = izquierda[0][1];
  frontal[0][2] = izquierda[0][2];

  posicion4 = izquierda[0][0];
  posicion5 = izquierda[0][1];
  posicion6 = izquierda[0][2];

  izquierda[0][0] = trasera[0][0];
  izquierda[0][1] = trasera[0][1];
  izquierda[0][2] = trasera[0][2];

  posicion3 = trasera[0][0];
  posicion3 = trasera[0][1];
  posicion3 = trasera[0][2];

  trasera[0][0] = derecha[0][0];
  trasera[0][1] = derecha[0][1];
  trasera[0][2] = derecha[0][2];

  posicion4 = derecha[0][0];
  posicion4 = derecha[0][1];
  posicion4 = derecha[0][2];

  derecha[0][0] = frontal[0][0];
  derecha[0][1] = frontal[0][1];
  derecha[0][2] = frontal[0][2];
}

//revisa movimiento clockwise de la cara inferior
void inferior_clockwise(int**frontal, int** izquierda, int** trasera, int**derecha){
  int posicion1, int posicion2, int posicion3, int posicion4, int posicion5, int posicion6;
  posicion1 = frontal[0][0];
  posicion2 = frontal[0][1];
  posicion3 = frontal[0][2];

  frontal[0][0] = izquierda[0][0];
  forntal[0][1] = izquierda[0][1];
  frontal[0][2] = izquierda[0][2];

  posicion4 = izquierda[0][0];
  posicion5 = izquierda[0][1];
  posicion6 = izquierda[0][2];

  izquierda[0][0] = trasera[0][0];
  izquierda[0][1] = trasera[0][1];
  izquierda[0][2] = trasera[0][2];

  posicion1 = trasera[0][0];
  posicion2 = trasera[0][1];
  posicion3 = trasera[0][2];

  trasera[0][0] = derecha[0][0];
  trasera[0][1] = derecha[0][1];
  trasera[0][2] = derecha[0][2];

  posicion4 = derecha[0][0];
  posicion5 = derecha[0][1];
  posicion6 = derecha[0][2];

  derecha[0][0] = frontal[0][0];
  derecha[0][1] = frontal[0][1];
  derecha[0][2] = frontal[0][2];
}

//revisa movimiento clockwise de cara derecha
void derecha_clockwise(int**frontal, int** inferior, int** trasera, int** superior){
  int posicion1, int posicion2, int posicion3, int posicion4, int posicion5, int posicion6;
  posicion1 = frontal[0][2];
  posicion2 = frontal[1][2];
  posicion3 = frontal[2][2];

  frontal[0][2] = superior[0][2];
  frontal[1][2] = superior[1][2];
  frontal[2][2] = superior[2][2];

  posicion4 = superior[0][2];
  posicion5 = superior[1][2];
  posicion6 = superior[2][2];

  superior = trasera[0][2];
  superior = trasera[1][2];
  superior = trasera[2][2];

  posicion1 = trasera[0][2];
  posicion2 = trasera[1][2];
  posicion3 = trasera[2][2];

  trasera[0][2] = inferior[0][2];
  trasera[1][2] = inferior[1][2];
  trasera[2][2] = inferior[2][2];

  posicion4 = inferior[0][2];
  posicion5 = inferior[1][2];
  posicion6 = inferior[2][2];

  inferior[0][2] = frontal[0][2];
  inferior[1][2] = fronta;[1][2];
  inferior[2][2] = frontal[2][2];
 }

 //revisa movimiento clockwise de cara izquierda
 void izquierda_clockwise(int**frontal, int** inferior, int**trasera, int** superior){
   int posicion1, int posicion2, int posicion3, int posicion4, int posicion5, int posicion6;
   posicion1 = frontal[0][2];
   posicion2 = frontal[1][2];
   posicion3 = frontal[2][2];

   frontal[0][2] = superior[0][2];
   frontal[1][2] = superior[1][2];
   frontal[2][2] = superior[2][2];

   posicion4 = superior[0][2];
   posicion5 = superior[1][2];
   posicion6 = superior[2][2];

   superior[0][2] = trasera[0][2];
   superior[1][2] = trasera[1][2];
   superior[2][2] = trasera[2][2];

   posicion1 = trasera[0][2];
   posicion2 = trasera[1][2];
   posicion3 = trasera[2][2];

   trasera[0][2] = inferior[0][2];
   trasera[1][2] = inferior[1][2];
   trasera[2][2] = inferior[2][2];

   posicion4 = inferior[0][2];
   posicion5 = inferior[1][2];
   posicion6 = inferior[2][2];

   inferior[0][2] = frontal[0][2];
   inferior[1][2] = fronta;[1][2];
   inferior[2][2] = frontal[2][2];
 }

//revisa movimiento counterclockwise de cara superior
 void superior_anticlockwise(int**frontal, int**derecha, int**trasera, int** izquierda){
   int posicion1, int posicion2, int posicion3, int posicion4, int posicion5, int posicion6;
   posicion1 = frontal[0][0];
   posicion2 = frontal[0][1];
   posicion3 = frontal[0][2];

   frontal[0][0] = derecha[0][0];
   frontal[0][1] = derecha[0][1];
   frontal[0][2] = derecha[0][2];
 }

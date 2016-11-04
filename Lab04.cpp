
#include <iostream>

using namespace std;

void llenarMatriz(int**, int);

void liberarEspacio(int**);

void frontal_clockwise(int**,int**,int**,int**);

void frontal_counterclockwise(int**,int**,int**,int**);

void trasera_clockwise(int**,int**,int**,int**);

void trasera_counterclockwise(int**,int**,int**,int**);

void imprimirCubo(int**,int**,int**,int**,int**,int**);

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
  llenarMatriz(matriz_izquierda,6);

  matriz_derecha = new int*[3];

  for (int i = 0; i < 3; i++) {
    matriz_derecha[i] = new int[3];
  }
  llenarMatriz(matriz_derecha,5);

  cout<<endl;
  cout<<endl;
  cout<<endl;

  int op = 1;
  do {
    cout<<"1 - Frontal en sentido horario"<<endl;
    cout<<"2 - Frontal en sentido anti-horario"<<endl;
    cout<<"3 - Trasera en sentido horario"<<endl;
    cout<<"4 - Trasera en sentido anti-horario"<<endl;
    cout<<"5 - Superior en sentido horario"<<endl;
    cout<<"6 - Superior en sentido anti-horario"<<endl;
    cout<<"7 - Inferior en sentido horario"<<endl;
    cout<<"8 - Inferior en sentido anti-horario"<<endl;
    cout<<"9 - Derecha en sentido horario"<<endl;
    cout<<"10 - Derecha en sentido anti-horario"<<endl;
    cout<<"11 - Izquierda en sentido horario"<<endl;
    cout<<"12 - Izuierda en sentido anti-horario"<<endl;
    cout<<"Escoja una operación: "<<endl;
    cin>>op;
    switch(op)
    {
      case 1:{
        frontal_clockwise(matriz_superior,matriz_inferior,matriz_izquierda,matriz_derecha);
        break;
      }
      case 2:
      {
        frontal_counterclockwise(matriz_superior,matriz_inferior,matriz_izquierda,matriz_derecha);
        break;
      }
      case 3:
      {
        trasera_clockwise(matriz_superior,matriz_inferior,matriz_izquierda,matriz_derecha);
        break;
      }
      case 4:
      {
        trasera_counterclockwise(matriz_superior,matriz_inferior,matriz_izquierda,matriz_derecha);
        break;
      }
    }
    imprimirCubo(matriz_frontal,matriz_trasera,matriz_superior,
      matriz_inferior,matriz_izquierda,matriz_derecha);
      cout<<"Salir?[0=No||1=Si]";
      cin>>op;
  } while(op == 0);

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
  for(int i = 0; i < 3; i++)
  {
    delete[] matriz[i];
    matriz[i] = NULL;
  }
  delete[] matriz;

}

void frontal_clockwise(int** superior, int** inferior, int** izquierda, int** derecha)
{
  int posicion1, posicion2, posicion3, posicion4, posicion5, posicion6;

  //Mod de cara Derecha
  posicion1 = derecha[0][0];
  posicion2 = derecha[1][0];
  posicion3 = derecha[2][0];

  derecha[0][0] = superior[2][0];
  derecha[1][0] = superior[2][1];
  derecha[2][0] = superior[2][2];

  //Mod de cara Inferior
  posicion4 = inferior[2][0];
  posicion5 = inferior[2][1];
  posicion6 = inferior[2][2];

  inferior[2][0] = posicion1;
  inferior[2][1] = posicion2;
  inferior[2][2] = posicion3;

  //Mod de cara Izquierda
  posicion1 = izquierda[0][2];
  posicion2 = izquierda[1][2];
  posicion3 = izquierda[2][2];

  izquierda[0][2] = posicion4;
  izquierda[1][2] = posicion5;
  izquierda[2][2] = posicion6;

  //Mod de cara Superior
  superior[2][0] = posicion1;
  superior[2][1] = posicion2;
  superior[2][2] = posicion3;
}

void frontal_counterclockwise(int** superior, int** inferior, int** izquierda, int** derecha)
{
  int posicion1, posicion2, posicion3, posicion4, posicion5, posicion6;

  //Mod de cara Izquierda
  posicion1 = izquierda[0][2];
  posicion2 = izquierda[1][2];
  posicion3 = izquierda[2][2];

  izquierda[0][2] = superior[2][0];
  izquierda[1][2] = superior[2][1];
  izquierda[2][2] = superior[2][2];

  //Mod de cara Inferior
  posicion4 = inferior[2][0];
  posicion5 = inferior[2][1];
  posicion6 = inferior[2][2];

  inferior[2][0] = posicion1;
  inferior[2][1] = posicion2;
  inferior[2][2] = posicion3;

  //Mod de cara Derecha
  posicion1 = derecha[0][0];
  posicion2 = derecha[0][1];
  posicion3 = derecha[0][2];

  derecha[0][0] = posicion4;
  derecha[0][1] = posicion5;
  derecha[0][2] = posicion6;

  //Mod de cara Superior
  superior[2][0] = posicion1;
  superior[2][1] = posicion2;
  superior[2][2] = posicion3;
}

void trasera_clockwise(int** superior, int** inferior, int** izquierda, int** derecha)
{
  int posicion1, posicion2, posicion3, posicion4, posicion5, posicion6;

  //Mod de cara Derecha
  posicion1 = derecha[0][0];
  posicion2 = derecha[0][1];
  posicion3 = derecha[0][2];

  derecha[0][2] = superior[0][0];
  derecha[1][2] = superior[0][1];
  derecha[2][2] = superior[0][2];

  //Mod de cara Inferior
  posicion4 = inferior[0][0];
  posicion5 = inferior[0][1];
  posicion6 = inferior[0][2];

  inferior[0][0] = posicion1;
  inferior[0][1] = posicion2;
  inferior[0][2] = posicion3;

  //Mod de cara Izquierda
  posicion1 = izquierda[0][0];
  posicion2 = izquierda[1][0];
  posicion3 = izquierda[2][0];

  izquierda[0][0] = posicion4;
  izquierda[1][0] = posicion5;
  izquierda[2][0] = posicion6;

  //Mod de cara Superior
  superior[0][0] = posicion1;
  superior[0][1] = posicion2;
  superior[0][2] = posicion3;
}

void trasera_counterclockwise(int** superior, int** inferior, int** izquierda, int** derecha)
{
  int posicion1, posicion2, posicion3, posicion4, posicion5, posicion6;

  //Mod de cara Izquierda
  posicion1 = izquierda[0][0];
  posicion2 = izquierda[1][0];
  posicion3 = izquierda[2][0];

  izquierda[0][0] = superior[0][0];
  izquierda[1][0] = superior[0][1];
  izquierda[2][0] = superior[0][2];

  //Mod de cara Inferior
  posicion4 = inferior[0][0];
  posicion5 = inferior[0][1];
  posicion6 = inferior[0][2];

  inferior[0][0] = posicion1;
  inferior[0][1] = posicion2;
  inferior[0][2] = posicion3;

  //Mod de cara Derecha
  posicion1 = derecha[0][2];
  posicion2 = derecha[1][2];
  posicion3 = derecha[2][2];

  derecha[0][2] = posicion4;
  derecha[1][2] = posicion5;
  derecha[2][2] = posicion6;

  //Mod de cara Superior
  superior[0][0] = posicion1;
  superior[0][1] = posicion2;
  superior[0][2] = posicion3;

}

void imprimirCubo(int** front, int** back, int** up, int** down, int** left, int** right)
{
  cout<<"Cara frontal"<<endl;
  for ( int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cout<<front[i][j]<<" ";
    }
    cout<<endl;
  }

  cout<<"Cara trasera"<<endl;
  for ( int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cout<<back[i][j]<<" ";
    }
    cout<<endl;
  }

  cout<<"Cara superior"<<endl;
  for ( int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cout<<up[i][j]<<" ";
    }
    cout<<endl;
  }

  cout<<"Cara inferior"<<endl;
  for ( int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cout<<down[i][j]<<" ";
    }
    cout<<endl;
  }

  cout<<"Cara de la izquierda"<<endl;
  for ( int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cout<<left[i][j]<<" ";
    }
    cout<<endl;
  }

  cout<<"Cara de la derecha"<<endl;
  for ( int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cout<<right[i][j]<<" ";
    }
    cout<<endl;
  }

}

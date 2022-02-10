#include<iostream>

using namespace std;

int main(){
int NumeroGatos = 5;
int NumeroPerros = 7;
int NumeroAnimales = NumeroGatos + NumeroPerros;

cout << "Numero de gatos: " << NumeroGatos << endl;
cout << "Numero de perros: " << NumeroPerros << endl;

cout << "Numero total de animales: " << NumeroAnimales << endl;
cout << "Nuevo perro adquirido: " << endl;
NumeroPerros = NumeroPerros + 1;
cout << "Nuevo numero de perros: " << NumeroPerros << endl;

return 0;
}

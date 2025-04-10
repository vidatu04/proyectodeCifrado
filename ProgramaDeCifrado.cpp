#include <iostream>
#include <string>
using namespace::std;

//inicializo un array alfabeto para asignar un valor por default a cada letra
char alfabeto[26]= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

//se inicializa una matriz de tamaño indefinido para que el usuario se lo asigne
string **madero;

//---variables a usar---
string mensaje="";
int clave = 0, filas = 0, columnas = 0;
int longitudMensaje = 0;
int formula = 0;

//---lista de metodos---

//metodos submenus
void subMenuCesar();
void subMenuEscitala();

//metodo que captura el mensaje
void ingresarMensaje();

//metodos para el cifrado cesar
void ingresarClaveCesar();
void cifrarCesar();
void descifrarCesar();

//metodos para el cifrado escitala
void ingresarClaveEscitala();
void cifrarEscitala();
void descifrarEscitala();




//Mensaje a cifrar se usa en ambos programas el mismo metodo
void ingresarMensaje(){
     cout<<"Ingrese el mensaje: ";
     fflush(stdin);
     getline(cin,mensaje);
     longitudMensaje=mensaje.length();
}

//Submenu que controla el cifrado y descifrado Cesar
void subMenuCesar(){
    int opc;

    do {
        cout<<"\n---CIFRADO CESAR---\n";
        cout<<"1. Cifrar.\n";
        cout<<"2. Descifrar.\n";
        cout<<"3. Salir.\n";
        cout<<"Selecione una opcion: "; cin>>opc;

        switch(opc){

            case 1: ingresarMensaje();
                    ingresarClaveCesar();
                    cifrarCesar();
                    break;

            case 2: ingresarMensaje();
                    ingresarClaveCesar();
                    descifrarCesar();
                    break;
            case 3: cout<<"Saliendo...!\n"; break;

            default: cout<<"Opcion invalida.\n";

        }


    }while(opc!=3);

}

//Solicitar al usuario clave de cifrado cesar
void ingresarClaveCesar(){
    cout<<"ingrese la clave para el cifrado: ";
    cin>>clave;

}

//implementacion metodo para cifrar por cesar
void cifrarCesar(){
    for (int i = 0; i < longitudMensaje ; i++){
        for(int j = 0; j < 26 ; j++){
            if(mensaje[i]==alfabeto[j]){
                formula=(j+clave)%26;
                mensaje[i]=alfabeto[formula];
                break;

            }
        }
    }
    cout<<"Mensaje cifrado: "<<mensaje<<endl;
}

//implementacion metodo para descifrar por cesar
void descifrarCesar(){

    for (int i = 0; i < longitudMensaje; i++){
        for (int j = 0 ; j < 26 ; j++){
            if (mensaje[i]==alfabeto[j]){
                formula=(j-clave)%26;
                if(formula<0){
                    formula+=26;
                }
                mensaje[i]=alfabeto[formula];
            }
        }
    }
    cout<<"Mensaje descifrado: "<<mensaje<<endl;
}

//Submenu que controla el cifrado y descifrado Cesar
void subMenuEscitala(){
    int opc;

    do {
        cout<<"\n---CIFRADO ESCITALA ESPARTANA---\n";
        cout<<"1. Cifrar.\n";
        cout<<"2. Descifrar.\n";
        cout<<"3. Salir.\n";
        cout<<"Selecione una opcion: "; cin>>opc;

        switch(opc){

            case 1: ingresarMensaje();
                    ingresarClaveEscitala();
                    cifrarEscitala();
                    break;

            case 2: ingresarMensaje();
                    ingresarClaveEscitala();
                    descifrarEscitala();
                    break;

            case 3: cout<<"Saliendo...!\n\n"; break;

            default: cout<<"Opcion invalida.\n";
        }
    }while(opc!=3);
}

//solicitar filas y columnas para la escitala
void ingresarClaveEscitala(){

    cout<<"Ingrese la cantidad de filas: "; cin>>filas;
    cout<<"Ingrese la cantidad de columnas: "; cin>>columnas;

    madero = new string *[filas];
    for(int i = 0 ; i < filas ; i++){
        madero[i]= new string [columnas];
    }
}

//implementar metodo que cifra escitala
void cifrarEscitala(){
    int s=0;
    for(int i = 0 ; i < filas ; i++){

        for(int j = 0 ; j < columnas ; j++ ){

                madero[i][j]=mensaje[s];
                s++;
        }
    }

    cout<<"Mensaje cifrado:\n";
    for(int x = 0 ; x < columnas ; x++ ){

        for(int k = 0 ; k < filas ; k++ ) {

            cout<<madero[k][x];
        }
    }
    cout<<endl;
}

//implementacion metodo que descifra escitala
void descifrarEscitala(){

     int s=0;
    for(int i = 0 ; i < columnas ; i++){

        for(int j = 0 ; j < filas ; j++ ){

                madero[j][i]=mensaje[s];
                s++;
        }

    }

    cout<<"Mensaje descifrado:\n";
    for(int x = 0 ; x < filas ; x++ ){

        for(int k = 0 ; k < columnas ; k++ ) {

            cout<<madero[x][k];
        }
        cout<<endl;
    }

}


int main (){

 int opc;

    do {
        cout<<"---BIENVENIDO AL SISTEMA---\n";
        cout<<"1. Cifrado Cesar.\n";
        cout<<"2. Cifrado Escitala Espartana.\n";
        cout<<"3. Salir\n";
        cout<<"0. Datos del programador\n";
        cout<<"Selecione una opcion: "; cin>>opc;

        switch(opc){

            case 1: subMenuCesar();
                    break;

            case 2: subMenuEscitala();
                    break;
            case 3: cout<<"Saliendo...!\n\n"; break;

            case 0:  cout << "\n--- DATOS DEL PROGRAMADOR ---\n";
                     cout << "Victor Daniel Tigreros - 202357768\n";
                     break;

            default: cout<<"Opcion invalida.\n";

        }


    }while(opc!=3);

    return 0;
}

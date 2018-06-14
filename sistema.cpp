#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include<cstdlib>
#include<windows.h>
#include<string.h>
#include<fstream>
#include <ctime>
#include <time.h>
#include<cstring>

using namespace std;

void gotoxy(int, int);


COORD coord={0,0};
void gotoxy(int x,int y){
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

class Persona{
private:
    int DNI;
    string Nombre;
    string Apellido;
    int Telefono;
    string Sexo;
public:
    Persona(int, string, string, int, string);
    void CrearPersona(int,string, string, int, string);
    void MostrarPersona();
    void EliminarPersonas(int);
    ~Persona();
};

class Empleado:public Persona{
private:
    string usuario;
    string clave;
    int cargo;
public:
    Empleado(int, string,string,int, string,string,string, int);
    void administrarUsuarios();//Crear, ver y eliminar usuarios
    void CrearUsuario(int);
    void MostrarUsuario();
    void EliminarUsuario();
    void inventario();//Agregar, eliminar, buscar y ver productos
    void agotandose();//Lista de productos por agotarse
    void login(string, string, int);//Ingresar al sistema con sus datos
    void vender();//Agrega el producto a vender e imprime

    ~Empleado();
};
class Cliente:public Persona{
public:
    Cliente(int, string,string,int, string);
    ~Cliente();
};

class Boleta{
private:
    int total;
    int fecha_emision;
    int subtotal;
    int igv;
public:
    Boleta(string,string,string,string,int,int,string,int,int,int,int);
    void imprimir();
};

class Producto:public Boleta{
private:
    string producto;
    string descripcion;
    int Precio_compra;
    int Precio_venta;
    int Stock_actual;
    int Stock_minimo;
    int Stock_maximo;
    int Fecha_vencimiento;
public:
    Producto(int,int,int,int,string,string,int,int,int,int,int,int);
    void pedido();
    void mostrar_stock();
    void ingresar_producto();
};
class Producto_factura:public Producto{
private:
    int Cantidad;
public:
    void venta();
};

//Constructor Persona
Persona::Persona(int _DNI, string _Nombre, string _Apellido, int _Telefono, string _Sexo){
    DNI=_DNI;
    Nombre=_Nombre;
    Apellido=_Apellido;
    Telefono=_Telefono;
    Sexo=_Sexo;
}
//Destructor Persona
Persona::~Persona(){
}

void Persona::CrearPersona(int DNI,string Nombre, string Apellido,int Telefono,string Sexo){
    cout<<"DNI: "<<endl; cin>>DNI;
    cout<<"Nombre: "<<endl; cin>>Nombre;
    cout<<"Apellido: "<<endl; cin>>Apellido;
    cout<<"Telefono: "<<endl; cin>>Telefono;
    cout<<"Sexo: "<<endl; cin>>Sexo;

}

void Persona::MostrarPersona(){
    cout<<"DNI: "<<DNI<<endl;
    cout<<"Nombre: "<<Nombre<<endl;
    cout<<"Apellido: "<<Apellido<<endl;
    cout<<"Telefono: "<<Telefono<<endl;
    cout<<"Sexo: "<<Sexo<<endl;
}

void Persona::EliminarPersonas(int DNI){
    cout<<"Ingrese el DNI de la persona a eliminar: "<<endl;
    cin>>DNI;
}

//Constructor Empleado
Empleado::Empleado(int _DNI,string _Nombre,string _Apellido,int _Telefono,string _Sexo,string _Usuario,string _Clave,int _Cargo): Persona(_DNI,_Nombre,_Apellido,_Telefono,_Sexo){
    usuario=_Usuario;
    clave=_Clave;
    cargo=_Cargo;

}
//Destructor Empleado
Empleado::~Empleado(){
}

void Empleado::administrarUsuarios(){
    int op;
    gotoxy(25,19);
		cout << "    Ingrese opcion: ";
		cin >> op;

		switch(op)
		{
			case '1':
				{
					system("cls");
					CrearUsuario();
					system("cls");
					break;
				}
			case '2':
				{
					system("cls");
				    MostrarUsuario();
				    system("cls");
					break;
				}
			case '3':
				{
					system("cls");
					EliminarUsuario();
					system("cls");
					break;
				}
			case '4':
				{
					system("cls");
					verMedicamentos();
					system("cls");
					break;
				}
			case '5':
				{
					system("cls");
					agotando();
					system("cls");
					break;
				}
			case '0':
				{
					system("cls");
					break;
				}

			default:
				{
					system("cls");
					cout << "Error, opcion desconocida";
					Sleep(500);
					system("cls");
					break;
				}
		}

	system("cls");

	}while(op!= '0');
}
void Empleado::CrearUsuario(int cargo){
    CrearPersona();
    cout<<"Cargo: "<<endl; cin>>cargo;
}

void Persona::mostrarUsuario(){
    MostrarPersona();
    cout<<"Cargo: "<<cargo<<endl;

void Empleado::EliminarUsuario(int DNI){


}

void login(string USUARIO, string clave, int cargo){
    SetConsoleTitle("LOGIN");
    string user;
    string pass;
    int contador = 0;
    char caracter;
    bool ingresa = false;
    do {
		system("cls");
		gotoxy(35,9);
			cout << "-A C C E S O   A L   S I S T E M A-" << endl;
			gotoxy(45,10);
			cout<<"C a f e c i t o s"<<endl;
			gotoxy(45,13);
			cout << "Usuario: ";
			gotoxy(42,15);
			cout << "Contraseña: ";
			gotoxy(55,13);
			cin >> user;
			gotoxy(55,15);
			caracter = getch();

		getline(cin, user);
		pass = "";
		caracter = getch();
		while (caracter != 13){// 13 = ENTER
			if (caracter != 8){// 8 = BACKSPACE
				pass.push_back(caracter);
				cout<<"*";
				caracter = getch();
			} else {
				if (pass.length() > 0) {
					cout<<"\b \b";
					pass = pass.substr(0, pass.length() - 1);
				}
			}
		}
		if (user == USUARIO && pass == clave){
			ingresa = true;
		} else {
			cout<<"\n\tEl usuario y/o password son incorrectos"<<endl;
			cin.get();
			contador++;
		}
	} while(ingresa == false && contador < 3);

	if (ingresa == false){
		cout <<"\n\tSus 3 intentos fallidos han bloqueado el sistema."<< endl;
	} else {
		cout <<"\n\tBienvenido al sistema"<<endl;
	}
	cin.get();
}

int main()
{
    Empleado Joao= Empleado(74091359, "Joao", "Chavez", 980754999, "M", "JoaoMax", "1234", 0);
	SetConsoleTitle("SISTEMA ERP");
	gotoxy(45,13);
    string introduccion = "C A F E T E R I A";
    for(int i = 0 ; i <= introduccion.length(); i++)
    {
        cout << introduccion[i];
        Sleep(100);
    }
	login(Joao.usuario, Joao.clave, Joao.cargo);
	return 0;
	system("pause");
}



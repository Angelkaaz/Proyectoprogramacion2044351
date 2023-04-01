#include <iostream>
#include <conio.h>
#include <cmath>
#include <string.h>

using namespace std;

int main() {
	/*Declaracion de las variables*/
	char V1[2], N1[100], D1[100], R1[100], G1[100], C1[100], Co1[100];
	float P1, PI1;
	int Eleccion;

	/*Menu principal de la tienda*/
	cout << "\t ---**Menu de inicio**---" << endl;
	cout << "1. Alta de articulos" << endl;
	cout << "2. Modificacion de articulos" << endl;
	cout << "3. Baja de articulos" << endl;
	cout << "4. Lista de articulos" << endl;
	cout << "5. Limpiar la pantalla" << endl;
	cout << "6. Salir" << endl;

	/*Eleccion de apartado de la tienda*/
	cin >> Eleccion; //Esto truena si le ingresan letras o espacios
	//Filtro para que se ingresen elecciones validas
	if (Eleccion < 1 || Eleccion>6)
	{
		cout << "Ingrese una opcion valida" << endl;
		return main();
	}
	else
	{
		switch (Eleccion) //Inicio de ingreso de datos para el articulo que se dara de alta
		{
		case 1:cin.ignore();

			cout << "Ingrese el nombre del articulo " << endl;
			cin.getline(N1, 100, '\n');

			cout << "Ingrese una descripcion del articulo" << endl;
			cin.getline(D1, 100, '\n');

			cout << "Ingrese la resena del articulo" << endl;
			cin.getline(R1, 100, '\n');

			cout << "Ingrese el genero del articulo" << endl;
			cin.getline(G1, 100, '\n');

			cout << "Ingrese la clasificacion del articulo" << endl;
			cin.getline(C1, 100, '\n');

			cout << "Ingrese la consola a la que pertenece el articulo" << endl;
			cin.getline(Co1, 100, '\n');

			cout << "Ingrese el precio unitario del articulo" << endl;
			cin >> P1;
			PI1 = P1 * 1.16;

			//como todavia no hay lista se da la impresion de los datos para su verificacion, }
			//pero cuando ya la tengamos ya no es necesario
			cout << "Nombre del articulo " << N1 << endl;
			cout << "Descripcion: " << D1 << endl;
			cout << "Resena: " << R1 << endl;
			cout << "Genero: " << G1 << endl;
			cout << "Clasificacion: " << C1 << endl;
			cout << "Consola: " << Co1 << endl;
			cout << "El precio total del articulo es: " << PI1 << endl;

			//leccion de continuar o no ingresando articulos, si continua le regresara al menu sin ningun aviso
			//* si no desea continuar e ingresa otro valor, entonces de igual manera regresara al menu pero esta vez con
			//*el aviso de la finalizacion del proceso

			cout << "Si desea agregar otro producto ingrese: 1" << endl;
			cout << "Si no desea continuar ingrese cualquier otro numero" << endl;
			cin >> V1[2];


			if (V1[2] == '1') //Esto truena si le ingresan letras, o espacios, solo acepta numeros
			{
				return main();
			}
			else
			{
				cout << "Fin del ingreso de articulos" << endl;
				return main();
			}
			break;

			// las siguientes 3 opciones no hacen nada
		case 2: cout << "Disponible en un futuro" << endl;
			return main();
			break;

		case 3: cout << "Disponible en un futuro" << endl;
			return main();
			break;

		case 4: cout << "Disponible en un futuro" << endl;
			return main();
			break;

		case 5: system("cls");//Borra lo que se imprimio en la pantalla anteriormente//
			return main();
			break;

		case 6: exit(1); //cierra la consola//
			break;
		}
	}

}

#include <iostream>
#include <conio.h>
#include <cmath>
#include <string.h>
#include <wchar.h>
#include <stdio.h>
#include <math.h>
#include <string>

using namespace std;
struct Videojuego
{
	string nombre, descripcion, resena, genero, clasificacion, consola;
	float costo;
};

/*Creo que una opcion mas util o mas simple para este avance es: Utilizar el apartado default que tiene el switch
Se podria sustituir el Do/While por una opcion default dentro del switch que nos imprima que elijamos una opcion valida
y retorne al inicio*/

//Si sacamos del int main la llamada de la estructura podremos hacer que funcione sin errores sin necesidad de usar Do/While

Videojuego games[3];	



int main()
{
	int seleccion;
	do
	{
		//Menu principal de la tienda
		printf("\t -*-*-*Menu de inicio*-*-*- \n");
		printf("1. Alta de articulos \n");
		printf("2. Modificacion de articulos \n");
		printf("3. Baja de articulos \n");
		printf("4. Lista de articulos \n");
		printf("5. Limpiar la pantalla \n");
		printf("6. Salir \n");
		scanf_s("%d", &seleccion);


		// Switch para determinar que acciones o procesos realizara el programa dependiendo de la eleccion inicial el usuario

		switch (seleccion)
		{
		case 1: //Alta de articulos
			for (int i = 0; i < 3; i++)
			{
				cin.ignore();
				printf("Ingrese el nombre del videojuego \n");
				getline(cin, games[i].nombre);
				printf("Ingrese la descripcion del videojuego \n");
				getline(cin, games[i].descripcion);
				printf("Ingrese la resena del videojuego \n");
				getline(cin, games[i].resena);
				printf("Ingrese el genero del videojuego \n");
				getline(cin, games[i].genero);
				printf("Ingrese la clasificacion del videojuego \n");
				getline(cin, games[i].clasificacion);
				printf("Ingrese la consola compatible del videojuego \n");
				getline(cin, games[i].consola);
				system("pause");
				printf("Ingrese el costo del videojuego \n");
				scanf_s("%f", &games[i].costo);
				
				//Validacion para que el precio sea un valor positivo
				while (games[i].costo < 1)
				{
					printf("El costo es invalido, favor de ingresar volver a ingresar el dato \n");
					scanf_s("%f", &games[i].costo);
				}
		
				games[i].costo = (games[i].costo * 1.16);
				/*A la hora de imprimir el precio ya con el impuesto el programa imprime demasiados
				numeros decimales, correctos, pero algunos innecesarios*/
			}
			return main();
			break;

		case 2: //Parte del programa que no es parte de este avance
			printf("Disponible en un futuro");
			return main();
			break;

		case 3: //Parte del programa que no es parte de este avance
			printf("Disponible en un futuro");
			return main();
			break;



		case 4://Menu de articulos
			printf("\n ***Lista de articulos*** \n");
			for (int i = 0; i < 3; i++)
			{
				printf("Articulo #%d \n", i + 1); //Creo que este metodo sera suficiente por ahora para imprimir el numero del articulo

				printf("Nombre: %s \n", games[i].nombre.c_str());
				printf("Descripcion: %s \n", games[i].descripcion.c_str());
				printf("Resena: %s \n", games[i].resena.c_str());
				printf("Genero: %s \n", games[i].genero.c_str());
				printf("Clasificacion: %s \n", games[i].clasificacion.c_str());
				printf("Consola: %s \n", games[i].consola.c_str());
				printf("Precio total: %f \n", games[i].costo);
			}
			return main();
			break;
			
		case 5:
			system("cls");//Borra lo que se imprimio en la pantalla anteriormente//
			return main();
			break;

		case 6:
			exit(1); //cierra la consola//
			break;
		}
	} while (seleccion != 6);

}





/*
* EL ANTERIOR AVANCE 
* 
* 
int main() {
	/*Declaracion de las variables



	char V1[2], N1[100], D1[100], R1[100], G1[100], C1[100], Co1[100];
	float P1, PI1;
	int Eleccion;





	/*Menu principal de la tienda
	cout << "\t ---**Menu de inicio**---" << endl;
	cout << "1. Alta de articulos" << endl;
	cout << "2. Modificacion de articulos" << endl;
	cout << "3. Baja de articulos" << endl;
	cout << "4. Lista de articulos" << endl;
	cout << "5. Limpiar la pantalla" << endl;
	cout << "6. Salir" << endl;






	/*Eleccion de apartado de la tienda
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
*/
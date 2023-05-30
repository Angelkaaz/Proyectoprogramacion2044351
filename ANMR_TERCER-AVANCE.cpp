//El programa truena si le ingresan letras en variables numericas y en ciertas partes con valores decimales en variables de tipo int
#include <iostream>					//Libreria estandar
#include <conio.h>					//Permite mejorar la presentacion del programa
#include <string.h>					//Manipula cadenas
#include <string>					
#include <fstream>					//Archivos 
#include <stdlib.h>                 //NOTA DE CLASE: funcione new y delete
#include <vector>					//Almacena colecciondes de objetos del mismo tipo


using namespace std;

//DECLARACION DE FUNCIONES
void Alta();
void Modificacion();
void Baja();
void Lista();
void Archivos();

int alta, contador, * year;
string* name, * description, * review, * genre, * classification, * console, * item;
float* cost, * subtotal;
double* iva;

int main()
{
	int selec;
	printf("\t -*-*-*Menu de inicio*-*-*- \n");
	printf("1. Alta de articulos \n");
	printf("2. Modificacion de articulos \n");
	printf("3. Baja de articulos \n");
	printf("4. Lista de articulos \n");
	printf("5. Limpiar la pantalla \n");
	printf("6. Salir \n");
	scanf_s("%d", &selec);
	while (getchar() != '\n')			//Filtro para decimales, verifica que la variable no contenga elementos extra que puedan generar error 
	{
		printf("Favor de ingresar un numero entero\n");
		scanf_s("%d", &selec);
	}
	switch (selec)
	{
	case 1:
		Alta();
		return main();
		break;
	case 2:
		Modificacion();
		return main();
		break;

	case 3:
		Baja();
		return main();
		break;

	case 4:
		Lista();
		return main();
		break;

	case 5:
		system("cls");//Borra lo que se imprimio en la pantalla anteriormente
		return main();//Nos regresa al inicio imprimiendo el menu de nuevo
		break;

	case 6:
		Archivos();
		//exit(1); //cierra la consola/se acaba el programa
		break;

	default: //"Filtro"
		printf("Ingrese una de las opciones disponibles \nRecomendamos ingresar un valor numerico positivo y entero.\n ");
		return main();
	}
}

void Alta() //Apartado de alta de datos
{
	printf("Digite el numero de registros que desea dar de alta \n");
	scanf_s("%d", &alta);
	/*while (getchar() != '\n')			//Filtro para decimales, aunque contiene fallos
	{
		printf("Favor de ingresar un numero entero\n");
		scanf_s("%d", &alta);
	}*/

	//Error de usuario: filtro que bloquea que el usuario pueda ingresar una respuesta numerica negativa
	while (alta <= 0)
	{
		printf("Ingrese un numero de articulo valido\n");
		scanf_s("%d", &alta);
	}

	//arreglos ("Declaracion")
	name = new string[alta];
	description = new string[alta];
	review = new string[alta];
	genre = new string[alta];
	classification = new string[alta];
	console = new string[alta];
	cost = new float[alta];
	year = new int[alta];
	subtotal = new float[alta];
	iva = new double[alta];
	item = new string[alta];

	for (int i = 0; i < alta; i++)
	{
		while (getchar() != '\n');                    //NOTA DE CLASE: se vacia el buffer o el espacio o cin.ignore
		printf("Ingrese el nombre del videojuego \n");
		getline(cin, name[i]);
		printf("Ingrese la descripcion del videojuego \n");
		getline(cin, description[i]);
		printf("Ingrese la rese%ca \n", 164);
		getline(cin, review[i]);
		printf("Ingrese el genero del videojuego \n");
		getline(cin, genre[i]);
		printf("Ingrese la clasificacion del videojuego \n");
		getline(cin, classification[i]);
		printf("Ingrese la consola en la que se encuentra disponible \n");
		getline(cin, console[i]);
		printf("Ingrese el A%co de publicacion del videojuego\n", 164);
		scanf_s("%d", &year[i]);
		//Error de usuario: filtro que bloquea datos imposibles, el primer videojuego fue creado en 1952, por lo tanto datos menores son erroneos
		while (year[i] < 1950 || year[i] > 2023)
		{
			printf("Ingrese un año valido\n");
			scanf_s("%d", &year[i]);
		}
		printf("Ingrese el costo del videojuego \n");
		scanf_s("%f", &cost[i]);
		//Error de usuario: filtro que bloquea el ingreso de un valor numerico negativo
		while (cost[i] <= 0)
		{
			printf("Ingrese un precio valido\n");
			scanf_s("%f", &cost[i]);
		}
		iva[i] = cost[i] * .16;  //Calculo de costos, individuales, iva y totales
		subtotal[i] = cost[i];
		cost[i] = cost[i] * 1.16;

	}
}

void Lista() //Lista de articulos disponibles, imprimira todos los datos ingresados mas el calculo de costos
{
	int filter = 0, filter2 = 0;
	string searchc, searchg, searchcon; //Variables para la busqueda de cada tipo

	//Filtro para que no imprima nada si no ha dado de alta nada
	if (alta < 1)
	{
		printf("Para ver la lista primero tiene que dar de alta algun articulo\n");
		return;
	}

	printf("¿Desea iniciar una busqueda por medio de filtros?\n1.- Si\n2.- No\n");
	scanf_s("%d", &filter);
	while (filter < 1 || filter > 2)
	{
		printf("Ingrese una de las opciones disponibles\n");
		scanf_s("%d", &filter);
	}

	if (filter == 1)
	{
		printf("Seleccione el tipo de filtro\n1.- Clasificacion\n2.- Genero\n3.- Consola\n");
		scanf_s("%d", &filter2);
		
		switch (filter2)
		{
		case 1:
			while (getchar() != '\n');
			printf("Ingrese el dato a buscar");
			getline(cin, searchc);
			for (int i = 0; i < alta; i++)
			{
				if (classification[i] == searchc && item[i] != "ELIMINADO")
				{
					printf("Registro numero %d\n", i + 1);
					printf("Articulo %d \n", i + 1);
					printf("El nombre del videojuego es %s\n", name[i].c_str()); //".c_str() permite la impresion de variables que contienen cadenas de caracteres
					printf("La descripcion del videojuego es %s\n", description[i].c_str());
					printf("La rese%ca  del videojuego es %s\n", 164, review[i].c_str());
					printf("El genero del videojuego es %s\n", genre[i].c_str());
					printf("La clasificacion del videojuego es %s\n", classification[i].c_str());
					printf("La consola a la que pertenece el juego es %s\n", console[i].c_str());
					printf("El a%co en que fue publicado el videojuego es %d\n", 164, year[i]);
					printf("El impuesto aplicado al producto es %f\n", iva[i]);
					printf("El subtotal del producto es %f\n", subtotal[i]);
					printf("El costo total del videojuego es %f\n", cost[i]);
				}
			}

			break;
		case 2:
			while (getchar() != '\n');
			printf("Ingrese el dato a buscar");
			getline(cin, searchg);

			for (int i =0; i < alta; i++)
			{
				if (genre[i] == searchg && item[i] != "ELIMINADO")
				{
					printf("Registro numero %d\n", i + 1);
					printf("Articulo %d \n", i + 1);
					printf("El nombre del videojuego es %s\n", name[i].c_str()); //".c_str() permite la impresion de variables que contienen cadenas de caracteres
					printf("La descripcion del videojuego es %s\n", description[i].c_str());
					printf("La rese%ca  del videojuego es %s\n", 164, review[i].c_str());
					printf("El genero del videojuego es %s\n", genre[i].c_str());
					printf("La clasificacion del videojuego es %s\n", classification[i].c_str());
					printf("La consola a la que pertenece el juego es %s\n", console[i].c_str());
					printf("El a%co en que fue publicado el videojuego es %d\n", 164, year[i]);
					printf("El impuesto aplicado al producto es %f\n", iva[i]);
					printf("El subtotal del producto es %f\n", subtotal[i]);
					printf("El costo total del videojuego es %f\n", cost[i]);
				}
			}
			break;
			
		case 3:
			while (getchar() != '\n');
			printf("Ingrese el dato a buscar");
			getline(cin, searchcon);
			for (int i = 0; i < alta; i++)
			{
				if (console[i] == searchcon && item[i] != "ELIMINADO")
				{
					printf("Registro numero %d\n", i + 1);
					printf("Articulo %d \n", i + 1);
					printf("El nombre del videojuego es %s\n", name[i].c_str()); //".c_str() permite la impresion de variables que contienen cadenas de caracteres
					printf("La descripcion del videojuego es %s\n", description[i].c_str());
					printf("La rese%ca  del videojuego es %s\n", 164, review[i].c_str());
					printf("El genero del videojuego es %s\n", genre[i].c_str());
					printf("La clasificacion del videojuego es %s\n", classification[i].c_str());
					printf("La consola a la que pertenece el juego es %s\n", console[i].c_str());
					printf("El a%co en que fue publicado el videojuego es %d\n", 164, year[i]);
					printf("El impuesto aplicado al producto es %f\n", iva[i]);
					printf("El subtotal del producto es %f\n", subtotal[i]);
					printf("El costo total del videojuego es %f\n", cost[i]);
				}
			}
			break;
		}
	}
	else
	{
		for (int i = 0; i < alta; i++)
		{
			if (item[i] == "ELIMINADO")      // Si el articulo se borro con anterioridad, se le hara saber en la lista de articulos
			{
				printf("ARTICULO %d ELIMINADO  \n", i + 1);
			}
			else
			{
				printf("Registro numero %d\n", i + 1);
				printf("Articulo %d \n", i + 1);
				printf("El nombre del videojuego es %s\n", name[i].c_str()); //".c_str() permite la impresion de variables que contienen cadenas de caracteres
				printf("La descripcion del videojuego es %s\n", description[i].c_str());
				printf("La rese%ca  del videojuego es %s\n", 164, review[i].c_str());
				printf("El genero del videojuego es %s\n", genre[i].c_str());
				printf("La clasificacion del videojuego es %s\n", classification[i].c_str());
				printf("La consola a la que pertenece el juego es %s\n", console[i].c_str());
				printf("El a%co en que fue publicado el videojuego es %d\n", 164, year[i]);
				printf("El impuesto aplicado al producto es %f\n", iva[i]);
				printf("El subtotal del producto es %f\n", subtotal[i]);
				printf("El costo total del videojuego es %f\n", cost[i]);
			}
		}
	}
}


void Modificacion() //Permite modificar datos de un articulo ya ingresado
{
	int j, op1, op2;
	do
	{
		printf("Ingrese el numero del articulo a modificar \n");
		scanf_s("%d", &j);
		/*while (getchar() != '\n')			//Filtro para decimales, contiene errores
		{
			printf("Favor de ingresar un numero entero\n");
			scanf_s("%d", &j);
		}*/

		//Errores de usuario: filtro que se encargan de bloquear la modificacion de un articulo inexistente
		while (j <= 0 || j > alta)
		{
			printf("Articulo inexistente, ingrese un articulo valido o proporcione datos para poder modificarlo\n");
			return;

		}

		j = j - 1; // esto debido a que i inicia en 0

		for (int i = j; i == j; i++) //i esta igualada a j para que solo se realice una vez, en cuanto i incremente no permitira que el ciclo se repita
		{
			if ((item[i] == "ELIMINADO"))
			{
				printf("ARTICULO ELIMINADO %d \n", i + 1);
				printf("Ingrese un registro valido \n");
				op2 = 1;
			}
			else
			{
				op2 = 2;
			}
		}

	} while (op2 == 1); //Filtro que se encarga de evitar la modificacion de un articulo eliminado

	//Seleecion de dato que se busca modificar
	printf("Seleccione el dato a modificar\n1.-Nombre\n2.-Descripcion\n3.-Rese%ca\n4.-Genero\n5.-Clasificacion\n6.-Consola\n7.-A%co de publicacion\n8.-Costo\n", 164, 164);
	scanf_s("%d", &op1);
	/*while (getchar() != '\n')			//Filtro para decimales, contiene errores
	{
		printf("Favor de ingresar un numero entero\n");
		scanf_s("%d", &op1);
	}*/

	//Error de usuario: Filtro que bloquea el ingreso de valores numericos fuera de los numeros de las opciones disponibles
	while (op1 < 1 || op1 >7)
	{
		printf("Dato inexistente... Favor de volver a seleccionar el dato a modificar");
		printf("Seleccione el dato a modificar\n1.-Nombre\n2.-Descripcion\n3.-Rese%ca\n4.-Genero\n5.-Clasificacion\n6.-Consola\n7.-A%co de publicacion\n8.-Costo\n", 164, 164);
		scanf_s("%d", &op1);
	}

	switch (op1)
	{
	case 1:
		for (int i = j; i == j; i++) //Solo se realiza una vez
		{
			while (getchar() != '\n');                         //NOTA DE CLASE: se vacia el buffer o el espacio
			printf("Ingrese el nombre del videojuego \n");
			getline(cin, name[i]);
			system("pause");
		}
		break;

	case 2:
		for (int i = j; i == j; i++) //Solo se realiza una vez
		{
			while (getchar() != '\n');                         //NOTA DE CLASE: se vacia el buffer o el espacio
			printf("Ingrese la descripcion del videojuego \n");
			getline(cin, description[i]);
			system("pause");
		}
		break;

	case 3:
		for (int i = j; i == j; i++) //Solo se realiza una vez
		{
			while (getchar() != '\n');                         //NOTA DE CLASE: se vacia el buffer o el espacio
			printf("Ingrese la rese%ca \n", 164);
			getline(cin, review[i]);
			system("pause");
		}
		break;

	case 4:
		for (int i = j; i == j; i++) //Solo se realiza una vez
		{
			while (getchar() != '\n');                         //NOTA DE CLASE: se vacia el buffer o el espacio
			printf("Ingrese el genero del videojuego \n");
			getline(cin, genre[i]);
			system("pause");
		}
		break;

	case 5:
		for (int i = j; i == j; i++) //Solo se realiza una vez
		{
			while (getchar() != '\n');                         //NOTA DE CLASE: se vacia el buffer o el espacio
			printf("Ingrese la clasificacion del videojuego \n");
			getline(cin, classification[i]);
			system("pause");
		}
		break;


	case 6:
		for (int i = j; i == j; i++) //Solo se realiza una vez
		{
			while (getchar() != '\n');                         //NOTA DE CLASE: se vacia el buffer o el espacio
			printf("Ingrese la consola en la que se encuentra disponible \n");
			getline(cin, console[i]);
			system("pause");
		}
		break;


	case 7:
		for (int i = j; i == j; i++) //Solo se realiza una vez
		{
			printf("Ingrese el a%co de publicacion del videojuego\n", 164);
			scanf_s("%d", &year[i]);
		}
		break;

	case 8:
		for (int i = j; i == j; i++) //Solo se realiza una vez
		{
			printf("Ingrese el costo del videojuego \n");
			scanf_s("%f", &cost[i]);
			//Filtro para errores de usuario
			while (cost[i] < 0)
			{
				printf("Ingrese un precio valido\n");
				scanf_s("%f", &cost[i]);
			}

			iva[i] = cost[i] * .16;
			subtotal[i] = cost[i];
			cost[i] = cost[i] * 1.16;

			system("pause");
		}
		break;

	default:
		printf("Ingrese una de las opciones disponibles\n");
		return;
		break;
	}
}

void Baja() //""Eliminacion de un articulo especifico
{
	int j;
	printf("Ingrese el numero del articulo que desea eliminar \n");
	scanf_s("%d", &j);
	/*while (getchar() != '\n')			//Filtro para decimales, contiene errores
	{
		printf("Favor de ingresar un numero entero\n");
		scanf_s("%d", &j);
	}*/

	//Error de usuario: filtro que bloquea el avance si no se ha dado de alta algun articulo o si se ingresa un valor menor a los articulos disponibles
	while (j > alta || j <= 0)
	{
		printf("No hay articulos disponibles para eliminar, seleccione un articulo valido o proporcione datos para poder eliminarlo\n");
		return;
	}
	j = j - 1;
	for (int i = j; i == j; i++)
	{
		printf("Eliminando el articulo de la base de datos...\n");
		item[i] = "ELIMINADO";
	}
}

void Archivos()
{
	ofstream archive;                  //NOTA DE CLASE: clase ifstream para leer archivos
	string namearchive; //Variable que guarda el nombre del archivo
	int text7;
	float text0; // Variable que guarda los precios totales
	string text1, text2, text3, text4, text5, text6;  //Variables que guardan los datos de todos los articulos

	namearchive = "REGISTRO DE VIDEOJUEGOS.txt";

	archive.open(namearchive.c_str(), ios::out);

	if (archive.fail()) //En caso de algun error, el programara avisara que no se ha logrado crear el archivo y se cerrara enseguida
	{
		printf("Error al crear el archivo...\n");
		exit(1);
	}

	archive << "Nombre" << "\t" << "\t";
	archive << "Descripcion" << "\t" << "\t";
	//archive << "Rese%ca" << 164 << "\t" << "\t";
	archive << "Resena" << "\t" << "\t";
	archive << "Genero" << "\t" << "\t";
	archive << "Clasificacion" << "\t" << "\t";
	archive << "Consola" << "\t" << "\t";
	archive << "Año de publicacion" << "\t" << "\t";
	archive << "Precio" << "\t" << "\n";
	//archive << "Item" << "\n";           //se puede agregar una igualacion de item a "Disponible" o numeros de "serie" para que tenga uso en el archivo .txt

	for (int i = 0; i < alta; i++)
	{
		if (item[i] == "ELIMINADO")
		{
			text1 = "ARTICULO ELIMINADO ";
			text2 = " ";
			text3 = " ";
			text4 = " ";
			text5 = " ";
			text6 = " ";
			text0 = i + 1;
			archive << text1 << text0 << "\n";
		}
		else
		{
			text1 = name[i];
			archive << text1 << "\t" << "\t";

			text2 = description[i];
			archive << text2 << "\t" << "\t" << "\t";

			text3 = review[i];
			archive << text3 << "\t" << "\t";

			text4 = genre[i];
			archive << text4 << "\t" << "\t";

			text5 = classification[i];
			archive << text5 << "\t" << "\t" << "\t";

			text6 = console[i];
			archive << text6 << "\t" << "\t";

			text7 = year[i];
			archive << text7 << "\t" << "\t" << "\t";

			text0 = cost[i];
			archive << text0 << "\t" << "\n";
		}
	}
	archive.close();
}

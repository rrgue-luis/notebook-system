# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <stdbool.h>
# include <sys/stat.h>
# include <windows.h>
# include <unistd.h>

#define AUTORES "JUAN FERRARA, LUIS CARRIZO, JOAQUIN NANIA, LAURA CORPU, PABLO RETAMAR"

#define SIZE 50
struct pc{
	
	char marca[SIZE];
	char modelo[SIZE];
	char procesador[SIZE];
	int memoriavideo;
	float cpughz,precio;
	int ram,hdd,ssd,puertos, adquiridas, vendidas, stock;
	char wifi[10];
	bool rj45 = false;
	char so[10];
	int codigoPcs;

	
}netbook;
void mayusculas(char arr[]);
void getoxy(int x, int y);
bool existeNetbook(int codigo);
int returnCantNets();

void listarNetbooks() {

	FILE *arch;
    arch=fopen("productos.dat","r+b");
    if (arch==NULL)
        exit(1);
    fseek(arch, 0, SEEK_END);
	int tamvec = ftell(arch) / sizeof(pc); 
	fclose(arch);
	
	pc vector[tamvec];
	pc aux;
	int aux1=0;
	
	arch=fopen("productos.dat","r+b");
	
	fread(&aux, sizeof(pc), 1, arch);
	while(!feof(arch)) {
		vector[aux1] = aux;
		fread(&aux, sizeof(pc), 1, arch);
		aux1++;
	}
	fclose(arch);
    char auxres[2];
    
    
    system("cls");
    int opcion;
    printf("\t[1] - Listado general\n");
    printf("\t[2] - Listado en particular\n");
    getoxy(18,2); printf("[ "); getoxy(21,2); printf(" ]"); getoxy(20,2);
	scanf("%i", &opcion);
	system("cls");
	
	switch(opcion) {
		case 1:
			printf("\tMostrando listado general de todas las netbooks: \n");
			for(int i=0; i<tamvec; i++){
				printf("[CODIGO %i - %s %s - CPU %s %0.2f - VIDEO %i gb - RAM %i gb - HDD %i - SSD %i - %i PUERTOS - WIFI %s - RJ45 %s - SO %s - %i ADQUIRIDAS - %i EN STOCK - %i VENDIDAS - PRECIO $%0.2f] \n\n", 
				vector[i].codigoPcs, 
				vector[i].marca, 
				vector[i].modelo, 
				vector[i].procesador, 
				vector[i].cpughz,
				vector[i].memoriavideo,
				vector[i].ram,
				vector[i].hdd,
				vector[i].ssd,
				vector[i].puertos,
				vector[i].wifi,
				vector[i].rj45 ? "si":"no",
				vector[i].so,
				vector[i].adquiridas,
				vector[i].stock,
				vector[i].vendidas,
				vector[i].precio);
		    }
		    system("pause");
		    system("cls");
			break;
		case 2:
		
			printf("\tSeleccione de que item quiere hacer un listado en particular\n");
			printf("\t[1] - Listado particular de marcas\n");
			printf("\t[2] - Listado particular de modelos\n");
			printf("\t[3] - Listado particular de procesadores\n");
			printf("\t[4] - Listado particular de memorias de video\n");
			printf("\t[5] - Listado particular de CPU GHZ\n");
			printf("\t[6] - Listado particular de precios\n");
			printf("\t[7] - Listado particular de RAM\n");
			printf("\t[8] - Listado particular de HDD\n");
			printf("\t[9] - Listado particular de SSD\n");
			printf("\t[10] - Listado particular de puertos\n");
			printf("\t[11] - Listado particular de adquiridas\n");
			printf("\t[12] - Listado particular de vendidas\n");
			printf("\t[13] - Listado particular de cantidad en stock\n");
			printf("\t[14] - Listado particular que tienen wifi\n");
			printf("\t[15] - Listado particular que tienen RJ45\n");
			printf("\t[16] - Listado particular de sistemas operativos\n");
			getoxy(18,17); printf("[ "); getoxy(21,17); printf(" ]"); getoxy(20,17);
			int opcionAux;
			scanf("%i", &opcionAux);
			system("cls");
			switch(opcionAux) {
				case 1:
					printf("\tListando todas las marcas: ");
					for(int i=0; i<tamvec; i++){
						printf("\nCODIGO DE NETBOOK: %i - MARCA: %s", vector[i].codigoPcs, vector[i].marca);
					}
						printf("\n");
					    system("pause");
					    system("cls");
					break;
				case 2:
					printf("\tListando todos los modelos: ");
					for(int i=0; i<tamvec; i++){
						printf("\nCODIGO DE NETBOOK: %i - MODELO: %s \n", vector[i].codigoPcs, vector[i].modelo);
					}	
						printf("\n");
					    system("pause");
					    system("cls");
					break;
				case 3:
					printf("\tListando todos los procesadores: ");
					for(int i=0; i<tamvec; i++){
						printf("\nCODIGO DE NETBOOK: %i - PROCESADOR: %s", vector[i].codigoPcs, vector[i].procesador);
					}	
						printf("\n");
					    system("pause");
					    system("cls");
					break;
				case 4:
					printf("\tListando todas las memorias de video: ");
					for(int i=0; i<tamvec; i++){
						printf("\nCODIGO DE NETBOOK: %i - MEMORIA VIDEO: %i gb", vector[i].codigoPcs, vector[i].memoriavideo);
					}	
						printf("\n");
					    system("pause");
					    system("cls");
					break;
				case 5:
					printf("\tListando todas las velocidades GHZ de CPU: ");
					for(int i=0; i<tamvec; i++){
						printf("\nCODIGO DE NETBOOK: %i - GHZ: %0.2f", vector[i].codigoPcs, vector[i].cpughz);
					}	
						printf("\n");
					    system("pause");
					    system("cls");
					break;
				case 6:
					printf("\tListando todos los precios: ");
					for(int i=0; i<tamvec; i++){
						printf("\nCODIGO DE NETBOOK: %i - PRECIO: %0.2f", vector[i].codigoPcs, vector[i].precio);
					}	
						printf("\n");
					    system("pause");
					    system("cls");
					break;
				case 7:
					printf("\tListando todas las RAM: ");
					for(int i=0; i<tamvec; i++){
						printf("\nCODIGO DE NETBOOK: %i - RAM: %i gb", vector[i].codigoPcs, vector[i].ram);
					}	
						printf("\n");
					    system("pause");
					    system("cls");
					break;
				case 8:
					printf("\tListando todas los HDD: ");
					for(int i=0; i<tamvec; i++){
						printf("\nCODIGO DE NETBOOK: %i - HDD: %i gb", vector[i].codigoPcs, vector[i].hdd);
					}	
						printf("\n");
					    system("pause");
					    system("cls");
					break;
				case 9:
					printf("\tListando todas los SSD: ");
					for(int i=0; i<tamvec; i++){
						printf("\nCODIGO DE NETBOOK: %i - SSD: %i gb", vector[i].codigoPcs, vector[i].ssd);
					}	
						printf("\n");
					    system("pause");
					    system("cls");
					break;
				case 10:
					printf("\tListando todos los puertos: ");
					for(int i=0; i<tamvec; i++){
						printf("\nCODIGO DE NETBOOK: %i - PUERTOS: %i", vector[i].codigoPcs, vector[i].puertos);
					}	
						printf("\n");
					    system("pause");
					    system("cls");
					break;
				case 11:
					printf("\tListando por cantidad de adquiridas: ");
					for(int i=0; i<tamvec; i++){
						printf("\nCODIGO DE NETBOOK: %i - ADQUIRIDAS: %i", vector[i].codigoPcs, vector[i].adquiridas);
					}	
						printf("\n");
					    system("pause");
					    system("cls");
					break;
				case 12:
					printf("\tListando por cantidad de vendidas: ");
					for(int i=0; i<tamvec; i++){
						printf("\nCODIGO DE NETBOOK: %i - VENDIDAS: %i", vector[i].codigoPcs, vector[i].vendidas);
					}	
						printf("\n");
					    system("pause");
					    system("cls");
					break;
				case 13:
					printf("\tListando por cantidad en stock: ");
					for(int i=0; i<tamvec; i++){
						printf("\nCODIGO DE NETBOOK: %i - STOCK: %i", vector[i].codigoPcs, vector[i].stock);
					}	
						printf("\n");
					    system("pause");
					    system("cls");
					break;
				case 14:
					printf("\tListando todas las que tienen WIFI: ");
					for(int i=0; i<tamvec; i++){
						printf("\nCODIGO DE NETBOOK: %i - WIFI: %s", vector[i].codigoPcs, vector[i].wifi ? "si" : "no");
					}	
						printf("\n");
					    system("pause");
					    system("cls");
					break;
				case 15:
					printf("\tListando todas las que tienen RJ45: ");
					for(int i=0; i<tamvec; i++){
						printf("\nCODIGO DE NETBOOK: %i - RJ45: %s", vector[i].codigoPcs, vector[i].rj45 ? "si" : "no");
					}	
						printf("\n");
					    system("pause");
					    system("cls");
					break;
				case 16:
					printf("\tListando todos los sistemas operativos: ");
					for(int i=0; i<tamvec; i++){
						printf("\nCODIGO DE NETBOOK: %i - SO: %s", vector[i].codigoPcs, vector[i].so);
					}	
						printf("\n");
					    system("pause");
					    system("cls");
					break;
				default:
					system("cls");
					printf("\tError: opcion incorrecto.\n\n");	
					system("pause");
					break;
			}
			break;
		default:
			system("cls");
			printf("\tError: opcion incorrecta.\n\n");

	}
}

void buscarNetbook() {
	//CREAMOS VECTOR CON TODAS LAS ESTRUCTURAS PARA INTERACTUAR COMODAMENTE CON EL LISTADO
	FILE *arch;
    arch=fopen("productos.dat","r+b");
    if (arch==NULL)
        exit(1);
    fseek(arch, 0, SEEK_END);
	int tamvec = ftell(arch) / sizeof(pc); //tamaño del vector
	fclose(arch);
	
	pc vector[tamvec];
	pc aux;
	int aux1=0;
	
	arch=fopen("productos.dat","r+b");
	
	fread(&aux, sizeof(pc), 1, arch);
	while(!feof(arch)) {
		vector[aux1] = aux;
		fread(&aux, sizeof(pc), 1, arch);
		aux1++;
	}
	fclose(arch);

	int opcion;
	printf("\n \t Seleccione el tipo busqueda que desea realizar");
	printf("\n \t [1] Busqueda por codigo");
	printf("\n \t [2] Busqueda por marca");
	printf("\n \t [3] Busqueda por modelo");
	printf("\n \t [4] Busqueda por procesador");
	printf("\n \t [5] Busqueda por velocidad de procesador");
	printf("\n \t [6] Busqueda por memoria de video");
	printf("\n \t [7] Busqueda por memoria ram");
	printf("\n \t [8] Busqueda por HDD");
	printf("\n \t [9] Busqueda por SSD");
	printf("\n \t [10] Busqueda por puertos");
	printf("\n \t [11] Busqueda por wifi");
	printf("\n \t [12] Busqueda por rj45");
	printf("\n \t [13] Busqueda por Sistema Operativo");
	printf("\n \t [14] Busqueda por stock");
	printf("\n \t [15] Busqueda por vendidas");
	printf("\n \t [16] Busqueda por precio\n");
	getoxy(18,18); printf("[ "); getoxy(21,18); printf(" ]"); getoxy(20,18);
	scanf("%i", &opcion);
	int encontradas = 0;
	switch (opcion){
		case 1:
			system("cls");
			printf("\n\t Ingrese el codigo que desea buscar: ");
			int auxCodigo;
			scanf("%i",&auxCodigo);
			for(int i=0;i<tamvec;i++){
	    	    if(auxCodigo==vector[i].codigoPcs){
	    	    printf("[CODIGO %i - %s %s - CPU %s %0.2f - VIDEO %i gb - RAM %i gb - HDD %i - SSD %i - %i PUERTOS - WIFI %s - RJ45 %s - SO %s - %i ADQUIRIDAS - %i EN STOCK - %i VENDIDAS - PRECIO $%0.2f] \n\n", 
				vector[i].codigoPcs, 
				vector[i].marca, 
				vector[i].modelo, 
				vector[i].procesador, 
				vector[i].cpughz,
				vector[i].memoriavideo,
				vector[i].ram,
				vector[i].hdd,
				vector[i].ssd,
				vector[i].puertos,
				vector[i].wifi,
				vector[i].rj45 ? "si":"no",
				vector[i].so,
				vector[i].adquiridas,
				vector[i].stock,
				vector[i].vendidas,
				vector[i].precio);
				encontradas++;
				}
		      }
		      printf("\n\tSe encontraron %i unidades de la busqueda realizada\n", encontradas);
		      system("pause");
		      system("cls");
			break;
		case 2:
			system("cls");
			printf("\n\t Ingrese la marca que desea buscar: ");
			char auxMarca [20];
			fflush(stdin);
			gets(auxMarca);
			mayusculas(auxMarca);
			for(int i=0;i<tamvec;i++){
	    	    if(strcmp(auxMarca,vector[i].marca)==0){
	    	    printf("[CODIGO %i - %s %s - CPU %s %0.2f - VIDEO %i gb - RAM %i gb - HDD %i - SSD %i - %i PUERTOS - WIFI %s - RJ45 %s - SO %s - %i ADQUIRIDAS - %i EN STOCK - %i VENDIDAS - PRECIO $%0.2f] \n\n", 
				vector[i].codigoPcs, 
				vector[i].marca, 
				vector[i].modelo, 
				vector[i].procesador, 
				vector[i].cpughz,
				vector[i].memoriavideo,
				vector[i].ram,
				vector[i].hdd,
				vector[i].ssd,
				vector[i].puertos,
				vector[i].wifi,
				vector[i].rj45 ? "si":"no",
				vector[i].so,
				vector[i].adquiridas,
				vector[i].stock,
				vector[i].vendidas,
				vector[i].precio);
				encontradas++;
				}
		      }
		      printf("\n\tSe encontraron %i unidades de la busqueda realizada\n", encontradas);
		      system("pause");
		      system("cls");
			break;
		case 3:
			system("cls");
			printf("\n\t Ingrese el modelo que desea buscar: ");
			char auxModelo [20];
			fflush(stdin);
			gets(auxModelo);
			mayusculas(auxModelo);
			for(int i=0;i<tamvec;i++){
	    	    if(strcmp(auxModelo,vector[i].modelo)==0){
	    	    printf("[CODIGO %i - %s %s - CPU %s %0.2f - VIDEO %i gb - RAM %i gb - HDD %i - SSD %i - %i PUERTOS - WIFI %s - RJ45 %s - SO %s - %i ADQUIRIDAS - %i EN STOCK - %i VENDIDAS - PRECIO $%0.2f] \n\n", 
				vector[i].codigoPcs, 
				vector[i].marca, 
				vector[i].modelo, 
				vector[i].procesador, 
				vector[i].cpughz,
				vector[i].memoriavideo,
				vector[i].ram,
				vector[i].hdd,
				vector[i].ssd,
				vector[i].puertos,
				vector[i].wifi,
				vector[i].rj45 ? "si":"no",
				vector[i].so,
				vector[i].adquiridas,
				vector[i].stock,
				vector[i].vendidas,
				vector[i].precio);
				encontradas++;
				}
		      }
		      printf("\n\tSe encontraron %i unidades de la busqueda realizada\n", encontradas);
		      system("pause");
		      system("cls");
			break;
		case 4:
			system("cls");  
			printf("\n\t Ingrese el procesador que desea buscar: ");
			fflush(stdin);
			char auxProce [20];
			gets(auxProce);
			mayusculas(auxProce);
			for(int i=0;i<tamvec;i++){
	    	    if(strcmp(auxProce,vector[i].procesador)==0){
	    	    printf("[CODIGO %i - %s %s - CPU %s %0.2f - VIDEO %i gb - RAM %i gb - HDD %i - SSD %i - %i PUERTOS - WIFI %s - RJ45 %s - SO %s - %i ADQUIRIDAS - %i EN STOCK - %i VENDIDAS - PRECIO $%0.2f] \n\n", 
				vector[i].codigoPcs, 
				vector[i].marca, 
				vector[i].modelo, 
				vector[i].procesador, 
				vector[i].cpughz,
				vector[i].memoriavideo,
				vector[i].ram,
				vector[i].hdd,
				vector[i].ssd,
				vector[i].puertos,
				vector[i].wifi,
				vector[i].rj45 ? "si":"no",
				vector[i].so,
				vector[i].adquiridas,
				vector[i].stock,
				vector[i].vendidas,
				vector[i].precio);
				encontradas++;
				}
		      }
		      printf("\n\tSe encontraron %i unidades de la busqueda realizada\n", encontradas);
		      system("pause");
		      system("cls");
			break;
		case 5:
			system("cls");
			printf("\n\t Ingrese la velocidad de procesador (en ghz) que desea buscar: ");
			float auxVel;
			scanf("%f",&auxVel);
			for(int i=0;i<tamvec;i++){
	    	    if(auxVel==vector[i].cpughz){
	    	    printf("[CODIGO %i - %s %s - CPU %s %0.2f - VIDEO %i gb - RAM %i gb - HDD %i - SSD %i - %i PUERTOS - WIFI %s - RJ45 %s - SO %s - %i ADQUIRIDAS - %i EN STOCK - %i VENDIDAS - PRECIO $%0.2f] \n\n", 
				vector[i].codigoPcs, 
				vector[i].marca, 
				vector[i].modelo, 
				vector[i].procesador, 
				vector[i].cpughz,
				vector[i].memoriavideo,
				vector[i].ram,
				vector[i].hdd,
				vector[i].ssd,
				vector[i].puertos,
				vector[i].wifi,
				vector[i].rj45 ? "si":"no",
				vector[i].so,
				vector[i].adquiridas,
				vector[i].stock,
				vector[i].vendidas,
				vector[i].precio);
				encontradas++;
				}
		      }
		      printf("\n\tSe encontraron %i unidades de la busqueda realizada\n", encontradas);
		      system("pause");
		      system("cls");
			break;
			
		case 6:
			system("cls");
			printf("\n\t Ingrese la cantidad de memoria de video por la que desea buscar: ");
			int auxVram;
			scanf("%i",&auxVram);
			for(int i=0;i<tamvec;i++){
	    	    if(auxVram==vector[i].memoriavideo){
	    	    printf("[CODIGO %i - %s %s - CPU %s %0.2f - VIDEO %i gb - RAM %i gb - HDD %i - SSD %i - %i PUERTOS - WIFI %s - RJ45 %s - SO %s - %i ADQUIRIDAS - %i EN STOCK - %i VENDIDAS - PRECIO $%0.2f] \n\n", 
				vector[i].codigoPcs, 
				vector[i].marca, 
				vector[i].modelo, 
				vector[i].procesador, 
				vector[i].cpughz,
				vector[i].memoriavideo,
				vector[i].ram,
				vector[i].hdd,
				vector[i].ssd,
				vector[i].puertos,
				vector[i].wifi,
				vector[i].rj45 ? "si":"no",
				vector[i].so,
				vector[i].adquiridas,
				vector[i].stock,
				vector[i].vendidas,
				vector[i].precio);
				encontradas++;
				}
		      }
		      printf("\n\tSe encontraron %i unidades de la busqueda realizada\n", encontradas);
		      system("pause");
		      system("cls");
			break;
			
		case 7:
			system("cls");
			printf("\n\t Ingrese la cantidad de ram por la que desea buscar: ");
			int auxRam;
			scanf("%i",&auxRam);
			for(int i=0;i<tamvec;i++){
	    	    if(auxRam==vector[i].ram){
	    	    printf("[CODIGO %i - %s %s - CPU %s %0.2f - VIDEO %i gb - RAM %i gb - HDD %i - SSD %i - %i PUERTOS - WIFI %s - RJ45 %s - SO %s - %i ADQUIRIDAS - %i EN STOCK - %i VENDIDAS - PRECIO $%0.2f] \n\n", 
				vector[i].codigoPcs, 
				vector[i].marca, 
				vector[i].modelo, 
				vector[i].procesador, 
				vector[i].cpughz,
				vector[i].memoriavideo,
				vector[i].ram,
				vector[i].hdd,
				vector[i].ssd,
				vector[i].puertos,
				vector[i].wifi,
				vector[i].rj45 ? "si":"no",
				vector[i].so,
				vector[i].adquiridas,
				vector[i].stock,
				vector[i].vendidas,
				vector[i].precio);
				encontradas++;
				}
		      }
		      printf("\n\tSe encontraron %i unidades de la busqueda realizada\n", encontradas);
		      system("pause");
		      system("cls");
			break;
		case 8:
			system("cls");
			printf("\n\t Ingrese por la capacidad de HDD que desea buscar (en gb): ");
			int auxHdd;
			scanf("%i",&auxHdd);
			for(int i=0;i<tamvec;i++){
	    	    if(auxHdd==vector[i].hdd){
	    	    printf("[CODIGO %i - %s %s - CPU %s %0.2f - VIDEO %i gb - RAM %i gb - HDD %i - SSD %i - %i PUERTOS - WIFI %s - RJ45 %s - SO %s - %i ADQUIRIDAS - %i EN STOCK - %i VENDIDAS - PRECIO $%0.2f] \n\n", 
				vector[i].codigoPcs, 
				vector[i].marca, 
				vector[i].modelo, 
				vector[i].procesador, 
				vector[i].cpughz,
				vector[i].memoriavideo,
				vector[i].ram,
				vector[i].hdd,
				vector[i].ssd,
				vector[i].puertos,
				vector[i].wifi,
				vector[i].rj45 ? "si":"no",
				vector[i].so,
				vector[i].adquiridas,
				vector[i].stock,
				vector[i].vendidas,
				vector[i].precio);
				encontradas++;
				}
		      }
		      printf("\n\tSe encontraron %i unidades de la busqueda realizada\n", encontradas);
		      system("pause");
		      system("cls");
			break;
		case 9:
			system("cls");
			printf("\n\t Ingrese por la capacidad de SSD que desea buscar (en gb): ");
			int auxSsd;
			scanf("%i",&auxSsd);
			for(int i=0;i<tamvec;i++){
	    	    if(auxSsd==vector[i].ssd){
	    	    printf("[CODIGO %i - %s %s - CPU %s %0.2f - VIDEO %i gb - RAM %i gb - HDD %i - SSD %i - %i PUERTOS - WIFI %s - RJ45 %s - SO %s - %i ADQUIRIDAS - %i EN STOCK - %i VENDIDAS - PRECIO $%0.2f] \n\n", 
				vector[i].codigoPcs, 
				vector[i].marca, 
				vector[i].modelo, 
				vector[i].procesador, 
				vector[i].cpughz,
				vector[i].memoriavideo,
				vector[i].ram,
				vector[i].hdd,
				vector[i].ssd,
				vector[i].puertos,
				vector[i].wifi,
				vector[i].rj45 ? "si":"no",
				vector[i].so,
				vector[i].adquiridas,
				vector[i].stock,
				vector[i].vendidas,
				vector[i].precio);
				encontradas++;
				}
		      }
		      printf("\n\tSe encontraron %i unidades de la busqueda realizada\n", encontradas);
		      system("pause");
		      system("cls");
			break;
		case 10:
			system("cls");
			printf("\n\t Ingrese por la cantidad de puertos que desea buscar: ");
			int auxPort;
			scanf("%i",&auxPort);
			for(int i=0;i<tamvec;i++){
	    	    if(auxPort==vector[i].puertos){
	    	    printf("[CODIGO %i - %s %s - CPU %s %0.2f - VIDEO %i gb - RAM %i gb - HDD %i - SSD %i - %i PUERTOS - WIFI %s - RJ45 %s - SO %s - %i ADQUIRIDAS - %i EN STOCK - %i VENDIDAS - PRECIO $%0.2f] \n\n", 
				vector[i].codigoPcs, 
				vector[i].marca, 
				vector[i].modelo, 
				vector[i].procesador, 
				vector[i].cpughz,
				vector[i].memoriavideo,
				vector[i].ram,
				vector[i].hdd,
				vector[i].ssd,
				vector[i].puertos,
				vector[i].wifi,
				vector[i].rj45 ? "si":"no",
				vector[i].so,
				vector[i].adquiridas,
				vector[i].stock,
				vector[i].vendidas,
				vector[i].precio);
				encontradas++;
				}
		      }
		      printf("\n\tSe encontraron %i unidades de la busqueda realizada\n", encontradas);
		      system("pause");
		      system("cls");
			break;
		case 11:
			system("cls");
			printf("\n\t Desea buscar las que tienen o no Wifi? (si/no): ");
			fflush(stdin);
			char auxWifi [2];
			gets(auxWifi);
			if(strcmp(auxWifi, "si")==0) {
				for(int i=0;i<tamvec;i++){
		    	    if(strcmp(vector[i].wifi, "no")!=0) {
			    	    printf("[CODIGO %i - %s %s - CPU %s %0.2f - VIDEO %i gb - RAM %i gb - HDD %i - SSD %i - %i PUERTOS - WIFI %s - RJ45 %s - SO %s - %i ADQUIRIDAS - %i EN STOCK - %i VENDIDAS - PRECIO $%0.2f] \n\n", 
						vector[i].codigoPcs, 
						vector[i].marca, 
						vector[i].modelo, 
						vector[i].procesador, 
						vector[i].cpughz,
						vector[i].memoriavideo,
						vector[i].ram,
						vector[i].hdd,
						vector[i].ssd,
						vector[i].puertos,
						vector[i].wifi,
						vector[i].rj45 ? "si":"no",
						vector[i].so,
						vector[i].adquiridas,
						vector[i].stock,
						vector[i].vendidas,
						vector[i].precio);
						encontradas++;
					}
		      }
			} else {
				for(int i=0;i<tamvec;i++){
		    	    if(strcmp(vector[i].wifi, "no")==0) {
			    	    printf("[CODIGO %i - %s %s - CPU %s %0.2f - VIDEO %i gb - RAM %i gb - HDD %i - SSD %i - %i PUERTOS - WIFI %s - RJ45 %s - SO %s - %i ADQUIRIDAS - %i EN STOCK - %i VENDIDAS - PRECIO $%0.2f] \n\n", 
						vector[i].codigoPcs, 
						vector[i].marca, 
						vector[i].modelo, 
						vector[i].procesador, 
						vector[i].cpughz,
						vector[i].memoriavideo,
						vector[i].ram,
						vector[i].hdd,
						vector[i].ssd,
						vector[i].puertos,
						vector[i].wifi,
						vector[i].rj45 ? "si":"no",
						vector[i].so,
						vector[i].adquiridas,
						vector[i].stock,
						vector[i].vendidas,
						vector[i].precio);
						encontradas++;
					}
				
				}
		      }
		      printf("\n\tSe encontraron %i unidades de la busqueda realizada\n", encontradas);
		      system("pause");
		      system("cls");
			break;
					
		case 12:
			  system("cls");
			  printf("\n\tDesea buscar las que tienen o no RJ45? (si/no): ");
			  char auxRj45[2];
			  fflush(stdin);
			  gets(auxRj45);
			  if(strcmp(auxRj45, "si")==0) {
			   for(int i=0;i<tamvec;i++) {
			    if(vector[i].rj45) {
			    	    printf("[CODIGO %i - %s %s - CPU %s %0.2f - VIDEO %i gb - RAM %i gb - HDD %i - SSD %i - %i PUERTOS - WIFI %s - RJ45 %s - SO %s - %i ADQUIRIDAS - %i EN STOCK - %i VENDIDAS - PRECIO $%0.2f] \n\n", 
						vector[i].codigoPcs, 
						vector[i].marca, 
						vector[i].modelo, 
						vector[i].procesador, 
						vector[i].cpughz,
						vector[i].memoriavideo,
						vector[i].ram,
						vector[i].hdd,
						vector[i].ssd,
						vector[i].puertos,
						vector[i].wifi,
						vector[i].rj45 ? "si":"no",
						vector[i].so,
						vector[i].adquiridas,
						vector[i].stock,
						vector[i].vendidas,
						vector[i].precio);
						encontradas++;
			    }
			   }
			  } else {
			   for(int i=0;i<tamvec;i++) {
			    if(!vector[i].rj45) {
			    	    printf("[CODIGO %i - %s %s - CPU %s %0.2f - VIDEO %i gb - RAM %i gb - HDD %i - SSD %i - %i PUERTOS - WIFI %s - RJ45 %s - SO %s - %i ADQUIRIDAS - %i EN STOCK - %i VENDIDAS - PRECIO $%0.2f] \n\n", 
						vector[i].codigoPcs, 
						vector[i].marca, 
						vector[i].modelo, 
						vector[i].procesador, 
						vector[i].cpughz,
						vector[i].memoriavideo,
						vector[i].ram,
						vector[i].hdd,
						vector[i].ssd,
						vector[i].puertos,
						vector[i].wifi,
						vector[i].rj45 ? "si":"no",
						vector[i].so,
						vector[i].adquiridas,
						vector[i].stock,
						vector[i].vendidas,
						vector[i].precio);
						encontradas++;
			    }
				}
		      }
		      printf("\n\tSe encontraron %i unidades de la busqueda realizada\n", encontradas);
			  system("pause");
			  system("cls");
			break;
		case 13:
			system("cls");
			printf("\n\t Ingrese el sistema operativo por el que desea buscar: ");
			char auxSo [20];
			fflush(stdin);
			gets(auxSo);
			mayusculas(auxSo);
			for(int i=0;i<tamvec;i++){
	    	    if(strcmp(auxSo,vector[i].so)==0){
	    	    printf("[CODIGO %i - %s %s - CPU %s %0.2f - VIDEO %i gb - RAM %i gb - HDD %i - SSD %i - %i PUERTOS - WIFI %s - RJ45 %s - SO %s - %i ADQUIRIDAS - %i EN STOCK - %i VENDIDAS - PRECIO $%0.2f] \n\n", 
				vector[i].codigoPcs, 
				vector[i].marca, 
				vector[i].modelo, 
				vector[i].procesador, 
				vector[i].cpughz,
				vector[i].memoriavideo,
				vector[i].ram,
				vector[i].hdd,
				vector[i].ssd,
				vector[i].puertos,
				vector[i].wifi,
				vector[i].rj45 ? "si":"no",
				vector[i].so,
				vector[i].adquiridas,
				vector[i].stock,
				vector[i].vendidas,
				vector[i].precio);
				encontradas++;
				}
		      }
		      printf("\n\tSe encontraron %i unidades de la busqueda realizada\n", encontradas);
		      system("pause");
		      system("cls");
			break;
		case 14:
			system("cls");
			printf("\n\t Ingrese la cantidad de stock por la que desea buscar: ");
			int auxSt;
			scanf("%i",&auxSt);
			for(int i=0;i<tamvec;i++){
	    	    if(auxSt==vector[i].stock){
	    	    printf("[CODIGO %i - %s %s - CPU %s %0.2f - VIDEO %i gb - RAM %i gb - HDD %i - SSD %i - %i PUERTOS - WIFI %s - RJ45 %s - SO %s - %i ADQUIRIDAS - %i EN STOCK - %i VENDIDAS - PRECIO $%0.2f] \n\n", 
				vector[i].codigoPcs, 
				vector[i].marca, 
				vector[i].modelo, 
				vector[i].procesador, 
				vector[i].cpughz,
				vector[i].memoriavideo,
				vector[i].ram,
				vector[i].hdd,
				vector[i].ssd,
				vector[i].puertos,
				vector[i].wifi,
				vector[i].rj45 ? "si":"no",
				vector[i].so,
				vector[i].adquiridas,
				vector[i].stock,
				vector[i].vendidas,
				vector[i].precio);
				encontradas++;
				}
		      }
		      printf("\n\tSe encontraron %i unidades de la busqueda realizada\n", encontradas);
		      system("pause");
		      system("cls");
			break;
		case 15:
			system("cls");
			printf("\n\t Ingrese la cantidad de vendidas por las que desea buscar: ");
			int auxVen;
			scanf("%i",&auxVen);
			for(int i=0;i<tamvec;i++){
	    	    if(auxVen==vector[i].vendidas){
	    	    printf("[CODIGO %i - %s %s - CPU %s %0.2f - VIDEO %i gb - RAM %i gb - HDD %i - SSD %i - %i PUERTOS - WIFI %s - RJ45 %s - SO %s - %i ADQUIRIDAS - %i EN STOCK - %i VENDIDAS - PRECIO $%0.2f] \n\n", 
				vector[i].codigoPcs,
				vector[i].marca, 
				vector[i].modelo, 
				vector[i].procesador, 
				vector[i].cpughz,
				vector[i].memoriavideo,
				vector[i].ram,
				vector[i].hdd,
				vector[i].ssd,
				vector[i].puertos,
				vector[i].wifi,
				vector[i].rj45 ? "si":"no",
				vector[i].so,
				vector[i].adquiridas, 
				vector[i].stock,
				vector[i].vendidas,
				vector[i].precio);
				encontradas++;
				}
		      }
		      printf("\n\tSe encontraron %i unidades de la busqueda realizada\n", encontradas);
		      system("pause");
		      system("cls");
			break;
		case 16:
			system("cls");
			printf("\n\t Ingrese el precio por el que desea buscar: ");
			float auxPrecio;
			scanf("%f",&auxPrecio);
			for(int i=0;i<tamvec;i++){
	    	    if(auxPrecio==vector[i].precio){
	    	    printf("[CODIGO %i - %s %s - CPU %s %0.2f - VIDEO %i gb - RAM %i gb - HDD %i - SSD %i - %i PUERTOS - WIFI %s - RJ45 %s - SO %s - %i ADQUIRIDAS - %i EN STOCK - %i VENDIDAS - PRECIO $%0.2f] \n\n", 
				vector[i].codigoPcs,
				vector[i].marca, 
				vector[i].modelo, 
				vector[i].procesador, 
				vector[i].cpughz,
				vector[i].memoriavideo,
				vector[i].ram,
				vector[i].hdd,
				vector[i].ssd,
				vector[i].puertos,
				vector[i].wifi,
				vector[i].rj45 ? "si":"no",
				vector[i].so,
				vector[i].adquiridas, 
				vector[i].stock,
				vector[i].vendidas,
				vector[i].precio);
				encontradas++;
				}
		      }
		      printf("\n\tSe encontraron %i unidades de la busqueda realizada\n", encontradas);
		      system("pause");
		      system("cls");
			break;
		default:
			system("cls");
			printf("\n\tHa seleccionado una opcion incorrecta.");
			system("pause");
			break;
		
		}
		
}

void modificarNetbook() {
	pc aux;
	
	int codigo;
	printf("\n\t Ingrese el codigo de la notebook correspondiente: ");
	scanf("%i",&codigo);

	bool existe = false;
	FILE *arch;
    arch=fopen("productos.dat","r+b");
    if (arch==NULL)
        exit(1);
    fread(&aux, sizeof(pc), 1, arch);
    while(!feof(arch)) {
    	if(codigo==aux.codigoPcs) {
    		existe = true;

    		char aux1[2], aux2[2], aux3[2], aux4[2];
	
			system("cls");
			printf("\n\t  Ingrese marca: ");
			fflush(stdin);
			char auxmarca[30];
			gets(auxmarca);
			mayusculas(auxmarca);
			while(strlen(auxmarca)>20){
				printf("\t\n La marca no puede tener mas de 20 caracteres");
				printf("\t\n Ingrese marca: ");
				fflush(stdin);
				gets(auxmarca);
				mayusculas(auxmarca);
			}
			
			strcpy(aux.marca,auxmarca);
		
			printf("\n\t  Ingrese modelo: ");
			fflush(stdin);
			char auxmodelo[30];
			gets(auxmodelo);
			mayusculas(auxmodelo);
			while(strlen(auxmodelo)>20){
				printf("\t\n El nombre del modelo no puede tener mas de 20 caracteres");
				printf("\t\n Ingrese modelo: ");
				fflush(stdin);
				gets(auxmodelo);
				mayusculas(auxmodelo);
			}
			strcpy(aux.modelo,auxmodelo);
			
			
			printf("\n\t  Ingrese codigo de barra: ");
			scanf("%i",&aux.codigoPcs);
			printf("\n\t  Ingrese procesador: ");
			fflush(stdin);
			gets(aux.procesador);
			
			printf("\n\t  Ingrese velocidad de procesador: ");
			scanf("%f", &aux.cpughz);
			printf("\n\t  Ingrese memoria RAM: ");
			scanf("%i", &aux.ram);
			
			printf("\n\t  Ingrese memoria de video: ");
			scanf("%i", &aux.memoriavideo);
			
			printf("\n\t  Tiene disco hdd? si/no : ");
			fflush(stdin);
			gets(aux1);
			if(strcmp(aux1,"si")==0){
				printf("\n  Cual es la capacidad de hdd? : ");
				scanf("%i",&aux.hdd);
				} else {
					aux.hdd = 0;
				}
				
			printf("\n\t  Tiene disco ssd? si/no : ");
			fflush(stdin);
			gets(aux2);
			
			if(strcmp(aux2,"si")==0){
				printf("\n\t  Cual es la capacidad de ssd?: ");
				scanf("%i",&aux.ssd);
				} else {
					aux.ssd = 0;
				}
		    printf("\n\t  Ingrese cantidad de puertos usb: ");
			scanf("%i", &aux.puertos);
			printf("\n\t  Tiene puerto rj45? si/no : ");
			fflush(stdin);
			gets(aux3);
			
			if(strcmp(aux3,"si")==0){
					aux.rj45=true;
				}
			
			printf("\n\t  Tiene wifi? si/no : ");
				fflush(stdin);
				gets(aux4);
				if(strcmp(aux4,"si")==0){
					printf("\n\t  Cual es el nombre de la placa de wifi?: ");
					fflush(stdin);
					char auxwifi[20];
					gets(auxwifi);
					mayusculas(auxwifi);
					strcpy(aux.wifi,auxwifi);
				} else {
				strcpy(aux.wifi,"no");
				}	
				
			
			printf("\n\t  Ingrese sistema operativo: ");
			fflush(stdin);
			char auxso[50];
			gets(aux.so);
			mayusculas(auxso);
			strcpy(aux.so,auxso);
			printf("\n\t  Ingrese precio: ");
			scanf("%f", &aux.precio);
			
			
			printf("\n\t  Ingrese cantidad adquirida: ");
			int aux5;
			scanf("%i", &aux5);
			aux.adquiridas=aux5;
			aux.stock=aux5;
			aux.vendidas=0;
    		//
    		
    		int pos=ftell(arch)-sizeof(pc);
            fseek(arch,pos,SEEK_SET);
            fwrite(&aux, sizeof(pc), 1, arch);
    		break;
		} else {
			fread(&aux, sizeof(pc), 1, arch);
		}
	}
	fclose(arch);
	

	if(!existe) {
		system("cls");
		printf("\n\tNo existe una netbook con el codigo ingresado.\n\n");
		system("pause");
	} 

}

void eliminarNetbook() {
	
	pc aux;
	
	system("CLS");
	int codigo;
	printf("\n\tIngrese el codigo de la netbook que desea eliminar: ");
	scanf("%i",&codigo);
	
	
	bool existe = false;
	FILE *arch;
    arch=fopen("productos.dat","rb");
    if (arch==NULL)
        exit(1);
        printf("Ook");
    FILE *temp;
    temp=fopen("productos.tmp","ab");
    if (arch==NULL)
        exit(1);
        
        
	fread(&aux, sizeof(pc), 1, arch);
	while(!feof(arch)) {
		if(codigo==aux.codigoPcs) {
			existe=true;
			system("CLS");
			printf("\tEliminando la netbook: \n");
			printf("\n\tcodigo - %i", aux.codigoPcs);
			printf("\n\tmarca - %s", aux.marca);
			printf("\n\tmodelo - %s \n\n", aux.modelo);
			
			system("pause");
			system("cls");
		} else {
			fwrite(&aux, sizeof(pc), 1, temp);
		}
		fread(&aux, sizeof(pc), 1, arch);
	}
	
	if(!existe) {
		system("cls");
		printf("ERROR: No existe ninguna netbook con dicho codigo\n\n");
		system("pause");
	} else{
		printf("\n\n");
	}
	
	fclose(arch);
	fclose(temp);
	
	remove("productos.dat");
	rename("productos.tmp", "productos.dat");
	
}

void cargarNetbook() {
	//instanciamos la estructura para crear una netbook
		int opcion=0;
		do{
		int auxcantnets = returnCantNets();
		if(auxcantnets<50){
			char aux1[2], aux2[2], aux3[2], aux4[2];
			pc pcs;
			
			system("cls");
			printf("\n\t  Ingrese marca: ");
			fflush(stdin);
			char auxmarca[30];
			gets(auxmarca);
			mayusculas(auxmarca);
			while(strlen(auxmarca)>20){
				printf("\t\n La marca no puede tener mas de 20 caracteres");
				printf("\t\n Ingrese marca: ");
				fflush(stdin);
				gets(auxmarca);
				mayusculas(auxmarca);
			}
			
			strcpy(pcs.marca,auxmarca);
		
			printf("\n\t  Ingrese modelo: ");
			fflush(stdin);
			char auxmodelo[30];
			gets(auxmodelo);
			mayusculas(auxmodelo);
			while(strlen(auxmodelo)>20){
				printf("\t\n El nombre del modelo no puede tener mas de 20 caracteres");
				printf("\t\n Ingrese modelo: ");
				fflush(stdin);
				gets(auxmodelo);
				mayusculas(auxmodelo);
			}
			strcpy(pcs.modelo,auxmodelo);
			
			int auxCodigo2=0;
			do{
				int auxCodigo;
				printf("\n\t  Ingrese codigo de barra: ");
		 		scanf("%i",&auxCodigo);
		 		bool checkAuxCodigo = existeNetbook(auxCodigo);
			 	if(checkAuxCodigo == true){
		  			printf("\n\t  Ya existe una netbook con ese codigo de barra ");
					auxCodigo2=1;			  
		 		}else{
		 			auxCodigo2=0;
		 			pcs.codigoPcs =auxCodigo;
			  	}
			  			
			}while(auxCodigo2==1);
		
			printf("\n\t  Ingrese procesador: ");
			fflush(stdin);
			char auxprocesador[30];
			gets(auxprocesador);
			mayusculas(auxprocesador);
			strcpy(pcs.procesador,auxprocesador);
			
			
			printf("\n\t  Ingrese velocidad de procesador (en GHZ ): ");
			scanf("%f", &pcs.cpughz);
			printf("\n\t  Ingrese memoria RAM (en GB): ");
			scanf("%i", &pcs.ram);
			printf("\n\t  Ingrese memoria de video (en GB): ");
			scanf("%i", &pcs.memoriavideo);
			
			
			printf("\n\t  Tiene disco hdd? si/no : ");
			fflush(stdin);
			gets(aux1);
			if(strcmp(aux1,"si")==0){
				printf("\n\t  Cual es la capacidad del hdd? (en GB): ");
				scanf("%i",&pcs.hdd);
				} else {
					pcs.hdd = 0;
				}
				
			printf("\n\t  Tiene disco ssd? si/no : ");
			fflush(stdin);
			gets(aux2);
			
			if(strcmp(aux2,"si")==0){
				printf("\n\t  Cual es la capacidad del ssd? (en gb): ");
				scanf("%i",&pcs.ssd);
				} else {
					pcs.ssd = 0;
				}
		    printf("\n\t  Ingrese cantidad de puertos usb: ");
			scanf("%i", &pcs.puertos);
			
			printf("\n\t  Tiene puerto RJ45? si/no : ");
			fflush(stdin);
			gets(aux3);
			if(strcmp(aux3,"si")==0){
					pcs.rj45=true;
				}
			
			printf("\n\t  Tiene wifi? si/no : ");
			fflush(stdin);
			gets(aux4);
			if(strcmp(aux4,"si")==0){
				printf("\n\t  Cual es el nombre de la placa de wifi?: ");
				fflush(stdin);
				char auxwifi[20];
				gets(auxwifi);
				mayusculas(auxwifi);
				strcpy(pcs.wifi,auxwifi);
				} else {
					strcpy(pcs.wifi,"no");
			
				}
			printf("\n\t  Ingrese sistema operativo: ");
			fflush(stdin);
			char auxSo[20];
			gets(auxSo);
			mayusculas(auxSo);
			strcpy(pcs.so, auxSo);
			
			printf("\n\t  Ingrese precio: ");
			scanf("%f", &pcs.precio);
			
			printf("\n\t  Ingrese cantidad adquirida: ");
			int aux5;
			scanf("%i", &aux5);
			pcs.adquiridas=aux5;
			pcs.stock=aux5;
			pcs.vendidas=0;
			
			
			FILE *arch;
		    arch=fopen("productos.dat","ab");
		    if (arch==NULL)
		        exit(1);
		    fwrite(&pcs, sizeof(pc), 1, arch);
		    fclose(arch);
			
			system("cls");
			printf("\n\t Carga exitosa!");
			printf("\n\t-marca: %s", pcs.marca);
			printf("\n\t-modelo: %s", pcs.modelo);
			printf("\n\t-codigo: %i", pcs.codigoPcs);
			printf("\n\t-procesador: %s", pcs.procesador);
			printf("\n\t-velocidad procesador: %0.2f", pcs.cpughz);
			printf("\n\t-ram: %i gb", pcs.ram);
			printf("\n\t-memoria de video: %i gb", pcs.memoriavideo);
			printf("\n\t-hdd: ");
				if(pcs.hdd!=0){
				printf("%i gb", pcs.hdd);
				} else {
					printf("no posee");
				}
			printf("\n\t-ssd: ");
				if(pcs.ssd!=0){
				printf("%i gb", pcs.ssd);
				} else {
					printf("no posee");
				}
			printf("\n\t-puertos usb: %i", pcs.puertos);
			printf("\n\t-puerto rj45: %s", pcs.rj45 ? "si" : "no");
			printf("\n\t-wifi: %s", pcs.wifi );
			printf("\n\t-SO: %s", pcs.so);
			printf("\n\t-Precio unitario: $%0.2f", pcs.precio);
			printf("\n\t-Cantidad adquirida: %i\n\n", pcs.adquiridas);
			
			system("pause");
			system("cls");
			
			char auxRespuesta [2];
			printf("\t\nDesea seguir cargando mas netbooks? (si/no) : ");
			fflush(stdin);
			gets(auxRespuesta);
			if(strcmp(auxRespuesta,"si")==0){
				opcion=1;	
			}else{
				opcion=0;
			}
			}else{
		system("cls");
		printf("\n\t No se puede cargar mas de 50 notebooks \n\n");
		opcion=0;
		system("pause");
		system("cls");
	}
	}
	while(opcion==1);

}

void cargarVenta(){
	pc aux;
	
	int codigo;
	printf("\n\t Ingrese el codigo de la notebook a vender: ");
	scanf("%i",&codigo);
	system("cls");
	
	bool existe = false;
	FILE *arch;
    arch=fopen("productos.dat","r+b");
    if (arch==NULL)
        exit(1);
    fread(&aux, sizeof(pc), 1, arch);
    while(!feof(arch)) {
    	if(codigo==aux.codigoPcs) {
    		existe = true;
    		int cantvent;
    		printf("\n\t Actualmente hay %i unidades en stock",aux.stock);
			printf("\n\t Cuantas unidades desea vender? : ");
    		scanf("%i",&cantvent);
    		system("cls");
    		if(cantvent<=aux.stock){
    			aux.stock=aux.stock-cantvent;
    			aux.vendidas=aux.vendidas+cantvent;
    			printf("\n\tVenta exitosa!\n");
    			
    			float dinerovendido = aux.precio*cantvent;
    			
				printf("\tHa vendido x%i %s %s por un total de $%0.2f\n", cantvent, aux.marca, aux.modelo, dinerovendido); 
    			printf("\tUsted tiene ahora %i unidades en stock de ese producto!\n\n",aux.stock);
    			
    			system("pause");
    			system("cls");
				
			}else{
				
				printf("\t\n No hay suficiente stock para esa venta, ofrezca al cliente otro producto.\n\n");
				system("pause");
				system("cls");
			}	
					    		
    		
    		
    		int pos=ftell(arch)-sizeof(pc);
            fseek(arch,pos,SEEK_SET);
            fwrite(&aux, sizeof(pc), 1, arch);
    		break;
		} else {
			fread(&aux, sizeof(pc), 1, arch);
		}
	}
	fclose(arch);
	

	if(!existe) {
		system("cls");
		printf("\t\n\n El codigo ingresado no existe. Por favor, reviselo\n\n");
		system("pause");
	} 	
}

void cantidadCPU(){
	FILE *arch;
    arch=fopen("productos.dat","r+b");
    if (arch==NULL)
        exit(1);
    fseek(arch, 0, SEEK_END);
	int tamvec = ftell(arch) / sizeof(pc);
	fclose(arch);
	
	pc vector[tamvec];
	pc aux;
	int aux1=0;
	
	arch=fopen("productos.dat","r+b");
	
	fread(&aux, sizeof(pc), 1, arch);
	while(!feof(arch)) {
		vector[aux1] = aux;
		fread(&aux, sizeof(pc), 1, arch);
		aux1++;
	}
	fclose(arch);
	system("cls");
	printf("\n\tIngrese nombre de procesador: ");
	char aux2[20];
	int cont=0;
	fflush(stdin);
	gets(aux2);
	
	for(int i=0; i<tamvec ; i++){
		if(strcmp(aux2,vector[i].procesador)==0){
			cont++;
		}
		
	}
	system("cls");
	printf("\n\tSe encontraron %i notebooks con el procesador %s \n\n", cont, aux2);
	system("pause");
	system("cls");
}

void cantidadRAM(){
	FILE *arch;
    arch=fopen("productos.dat","r+b");
    if (arch==NULL)
        exit(1);
    fseek(arch, 0, SEEK_END);
	int tamvec = ftell(arch) / sizeof(pc); 
	fclose(arch);
	
	pc vector[tamvec];
	pc aux;
	int aux1=0;
	
	
	arch=fopen("productos.dat","r+b");
	
	fread(&aux, sizeof(pc), 1, arch);
	while(!feof(arch)) {
		vector[aux1] = aux;
		fread(&aux, sizeof(pc), 1, arch);
		aux1++;
	}
	fclose(arch);
	
	
	system("cls");
	printf("\n\tIngrese cantidad de RAM: ");
	int aux2;
	int cont=0;
	scanf("%i", &aux2);
	
	for(int i=0; i<tamvec ; i++){
		if(aux2==vector[i].ram){
			cont++;
		}
		
	}
	
	system("cls");
	printf("\n\t Se encontraron %i notebooks con %i gb de RAM\n\n", cont, aux2);
	system("pause");
	system("cls");
	
	
}

void stockValorizado(){
	FILE *arch;
    arch=fopen("productos.dat","r+b");
    if (arch==NULL)
        exit(1);
    fseek(arch, 0, SEEK_END);
	int tamvec = ftell(arch) / sizeof(pc); 
	fclose(arch);
	
	pc vector[tamvec];
	pc aux;
	int aux1=0;
	
	arch=fopen("productos.dat","r+b");
	
	fread(&aux, sizeof(pc), 1, arch);
	while(!feof(arch)) {
		vector[aux1] = aux;
		fread(&aux, sizeof(pc), 1, arch);
		aux1++;
	}
	fclose(arch);
	
	float aux2[tamvec];
	for(int i=0;i<tamvec;i++){
		float aux3;
		aux3 = vector[i].stock*vector[i].precio;
		aux2[i]=aux3;
	}
	float aux5;
	pc aux4;
	
	for(int x=0;x<tamvec;x++){
		for(int j=0; j<tamvec-1; j++) {
		

			int siguienteElemento = j + 1;
			int valorizadoActual = vector[j].stock * vector[j].precio;
			int valorizadoSiguiente = vector[siguienteElemento].stock * vector[siguienteElemento].precio;
			if(valorizadoActual > valorizadoSiguiente){
				aux4 = vector[j];
				vector[j] = vector[siguienteElemento];
				vector[siguienteElemento] = aux4;
				
				aux5 = aux2[j];
				aux2[j] = aux2[siguienteElemento];
				aux2[siguienteElemento] = aux5; 
			}
		}
	}
	
	system("cls");
	printf("\t\nListando stock valorizado de netbooks ordenado de menor a mayor: \n");
	for(int i=0; i<tamvec;i++) {
		printf("#%i ", i+1); printf("%s %s - %i unidades - $%0.2f\n", vector[i].marca, vector[i].modelo, vector[i].stock, aux2[i]);
	}
	
	printf("\n");
	system("pause");
	system("cls");
}

void ordenAdquiridas(){
	FILE *arch;
    arch=fopen("productos.dat","r+b");
    if (arch==NULL)
        exit(1);
    fseek(arch, 0, SEEK_END);
	int tamvec = ftell(arch) / sizeof(pc); 
	fclose(arch);
	
	pc vector[tamvec];
	pc aux;
	int aux1=0;
	
	arch=fopen("productos.dat","r+b");
	
	fread(&aux, sizeof(pc), 1, arch);
	while(!feof(arch)) {
		vector[aux1] = aux;
		fread(&aux, sizeof(pc), 1, arch);
		aux1++;
	}
	fclose(arch);
	float aux5;
	pc aux4;
	
	for(int x=0;x<tamvec;x++){
		for(int j=0; j<tamvec-1; j++) {
		
			
			int siguienteElemento = j + 1;
			int adquiridasActual = vector[j].adquiridas;
			int adquiridasSiguiente = vector[siguienteElemento].adquiridas;
			if(adquiridasActual > adquiridasSiguiente){
				aux4 = vector[j];
				vector[j] = vector[siguienteElemento];
				vector[siguienteElemento] = aux4;
				 
			}
		}
	}
	
	system("cls");
	printf("\t\n Listando por menor a mayor notebooks ADQUIRIDAS \n");
	for(int i=0; i<tamvec;i++){
		printf("#%i ", i+1); printf("%s %s - %i unidades\n ", vector[i].marca, vector[i].modelo, vector[i].adquiridas);
	}
	
	printf("\n");
	system("pause");
	system("cls");
}

void ordenStock(){
	FILE *arch;
    arch=fopen("productos.dat","r+b");
    if (arch==NULL)
        exit(1);
    fseek(arch, 0, SEEK_END);
	int tamvec = ftell(arch) / sizeof(pc); 
	fclose(arch);
	
	pc vector[tamvec];
	pc aux;
	int aux1=0;
	
	arch=fopen("productos.dat","r+b");
	
	fread(&aux, sizeof(pc), 1, arch);
	while(!feof(arch)) {
		vector[aux1] = aux;
		fread(&aux, sizeof(pc), 1, arch);
		aux1++;
	}
	fclose(arch);
	float aux5;
	pc aux4;
	
	for(int x=0;x<tamvec;x++){
		for(int j=0; j<tamvec-1; j++) {
		
			
			int siguienteElemento = j + 1;
			int stockActual = vector[j].stock;
			int stockSiguiente = vector[siguienteElemento].stock;
			if(stockActual > stockSiguiente){
				aux4 = vector[j];
				vector[j] = vector[siguienteElemento];
				vector[siguienteElemento] = aux4;
				 
			}
		}
	}
	
	system("cls");
	printf("\t\n Listando stock ordenado de menor a mayor (Cantidades) \n");
	for(int i=0; i<tamvec;i++) {
		printf("#%i ", i+1); printf("%s %s - %i unidades\n ", vector[i].marca, vector[i].modelo, vector[i].stock);
	}
	
	printf("\n");
	system("pause");
	system("cls");
}
		
void ordenVentas(){
	FILE *arch;
    arch=fopen("productos.dat","r+b");
    if (arch==NULL)
        exit(1);
    fseek(arch, 0, SEEK_END);
	int tamvec = ftell(arch) / sizeof(pc); 
	fclose(arch);
	
	pc vector[tamvec];
	pc aux;
	int aux1=0;
	
	arch=fopen("productos.dat","r+b");
	
	fread(&aux, sizeof(pc), 1, arch);
	while(!feof(arch)) {
		vector[aux1] = aux;
		fread(&aux, sizeof(pc), 1, arch);
		aux1++;
	}
	fclose(arch);
	float aux5;
	pc aux4;
	
	for(int x=0;x<tamvec;x++){
		for(int j=0; j<tamvec-1; j++) {
		
			
			int siguienteElemento = j + 1;
			int vendidasActual = vector[j].vendidas;
			int vendidasSiguiente = vector[siguienteElemento].vendidas;
			if(vendidasActual > vendidasSiguiente){
				aux4 = vector[j];
				vector[j] = vector[siguienteElemento];
				vector[siguienteElemento] = aux4;
				 
			}
		}
	}
	
	system("cls");
	printf("\t\n Listando ventas ordenado de menor a mayor \n");
	for(int i=0; i<tamvec;i++) {
		printf("#%i ", i+1); printf("%s %s - %i unidades\n ", vector[i].marca, vector[i].modelo, vector[i].vendidas);
	}
	
	printf("\n");
	system("pause");
	system("cls");
}

void Ordenamientos(){
	int opcion=0;
	
	printf("\t\n [1] Ordenar por menor a mayor STOCK");
	printf("\t\n [2] Ordenar por menor a mayor VENDIDAS ");
	printf("\t\n [3] Ordenar por menor a mayor ADQUIRIDAS");
	printf("\t\n [4] Ordenar por stock valorizado\n");
	getoxy(18,6); printf("[ "); getoxy(21,6); printf(" ]"); getoxy(20,6);
	scanf("%i",&opcion);
	switch(opcion){
		case 1:
			system("cls");
			ordenStock();
				break;
		case 2:
			system("cls");
			ordenVentas();
				break;
		case 3:
			system("cls");
			ordenAdquiridas();
			    break;
		case 4:
			system("cls");
			stockValorizado();
				break;
	    default:
			system("CLS");
			printf("\t\n ERROR: Opcion incorrecta\n\n");
			system("pause");
			break;
	}
	

}

void agregarStock(){
	
	pc aux;
	
	int codigo;
	system("cls");
	printf("\n\tIngrese el codigo de la netbook que desea agregar stock: ");
	scanf("%i",&codigo);
	system("cls");
	
	
	bool existe = false;
	FILE *arch;
    arch=fopen("productos.dat","r+b");
    if (arch==NULL)
        exit(1);
    fread(&aux, sizeof(pc), 1, arch);
    while(!feof(arch)) {
    	if(codigo==aux.codigoPcs) {
    		existe = true;
    		int aux1;
    		printf("\n\tCuantas netbook desea agregar al stock: ");
    		scanf("%i",&aux1);
    		aux.stock = aux.stock+aux1;
            aux.adquiridas = aux.stock+aux1;
            system("cls");
    		printf("\n\tSe agrego correctamente %i netbooks al stock de %s %s\n\n",aux1,aux.marca,aux.modelo);
    		system("pause");
    		system("cls");
    		
    		
    		int pos=ftell(arch)-sizeof(pc);
            fseek(arch,pos,SEEK_SET);
            fwrite(&aux, sizeof(pc), 1, arch);
    		break;
		} else {
			fread(&aux, sizeof(pc), 1, arch);
		}
	}
	fclose(arch);

	if(!existe) {
		system("cls");
		printf("\n\tNo existe la netbook con el codigo buscado");
		system("pause");
	}
	 
	}

void mayusculas(char arr[]){
    size_t i = 0;
    if(arr == NULL) return;
    while(arr[i])
    {
        if(arr[i] <= 'z' && arr[i] >= 'a'){
          arr[i] = arr[i] - ' ' ;
        }
        i++;
    }
}

bool checkifFileExist() {
	struct stat buffer;
	int exist = stat("productos.dat", &buffer);
	if(exist != 0) {
		return false;
	} else {
		FILE *rv;
		rv = fopen("productos.dat","r");
		fseek(rv, 0, SEEK_END);
		if(ftell(rv)==0) {
			fclose(rv);
			return false;
		} else {
			fclose(rv);
			return true;
		}
	}
	
	
}

int returnCantNets() {
	struct stat buffer;
	int exist = stat("productos.dat", &buffer);
	if(exist != 0) {
		return 0;
	} else {
		FILE *rv;
		rv = fopen("productos.dat","r");
		fseek(rv, 0, SEEK_END);
		if(ftell(rv)==0) {
			fclose(rv);
			return 0;
		} else {
			FILE *arch;
		    arch=fopen("productos.dat","r+b");
		    if (arch==NULL)
		        exit(1);
		    fseek(arch, 0, SEEK_END);
			int tamvec = ftell(arch) / sizeof(pc);
			return tamvec;
			fclose(arch);
		}
		
}
}

bool existeNetbook(int codigo) {
	struct stat buffer;
	int exist = stat("productos.dat", &buffer);
	if(exist==0) {
		pc aux;
		bool existe = false;
		FILE *arch;
	    arch=fopen("productos.dat","r");
	    fseek(arch, 0, SEEK_END);
	    if(ftell(arch)==0) {
	    	fclose(arch);
	    	return false;
		} else  {
			arch=fopen("productos.dat","r");
		    if (arch==NULL)
		        exit(1);
		    fread(&aux, sizeof(pc), 1, arch);
		    while(!feof(arch)) {
		    	if(codigo==aux.codigoPcs) {
		    		existe = true;
		    		break;
				} else {
					fread(&aux, sizeof(pc), 1, arch);
				}
			}
			fclose(arch);
			return existe;
		} 
	} else {
		return false;
	}
}

void getoxy(int x, int y) {
	HANDLE Manipulador;
	COORD Coordenadas;
	Manipulador = GetStdHandle(STD_OUTPUT_HANDLE);
	Coordenadas.X = x;
	Coordenadas.Y = y;
	SetConsoleCursorPosition(Manipulador, Coordenadas);
}

int main(){
	
	int opcion=0;
	system("COLOR 0A");

	
				system("cls");
				printf(R"EOF(
.__   __.   ______   .___________._______ .______     ______     ______    __  ___    
|  \ |  |  /  __  \  |           |   ____||   _  \   /  __  \   /  __  \  |  |/  /    
|   \|  | |  |  |  | `---|  |----|  |__   |  |_)  | |  |  |  | |  |  |  | |  '  /     
|  . `  | |  |  |  |     |  |    |   __|  |   _  <  |  |  |  | |  |  |  | |    <      
|  |\   | |  `--'  |     |  |    |  |____ |  |_)  | |  `--'  | |  `--'  | |  .  \     
|__| \__|  \______/      |__|    |_______||______/   \______/   \______/  |__|\__\    
                                                                                      
     ___________    ____  _______.___________._______ .___  ___.                      
    /       \   \  /   / /       |           |   ____||   \/   |                      
   |   (----`\   \/   / |   (----`---|  |----|  |__   |  \  /  |                      
    \   \     \_    _/   \   \       |  |    |   __|  |  |\/|  |                      
.----)   |      |  | .----)   |      |  |    |  |____ |  |  |  |                      
|_______/       |__| |_______/       |__|    |_______||__|  |__|                      
                                                                                      
)EOF");
				Sleep(1100);
				system("cls");
		
		printf(R"EOF(
 _____ ______ _   _______ _____    _   __
|  __ \| ___ \ | | | ___ \  _  |  | | / /
| |  \/| |_/ / | | | |_/ / | | |  | |/ / 
| | __ |    /| | | |  __/| | | |  |    \ 
| |_\ \| |\ \| |_| | |   \ \_/ /  | |\  \
 \____/\_| \_|\___/\_|    \___/   \_| \_/
                                         
                                         

)EOF");
				Sleep(1100);
				system("cls");	
	do {
			bool haydatos = checkifFileExist();
			if(haydatos){
				system("cls");

				printf(R"EOF(
.__   __.   ______   .___________._______ .______     ______     ______    __  ___    
|  \ |  |  /  __  \  |           |   ____||   _  \   /  __  \   /  __  \  |  |/  /    
|   \|  | |  |  |  | `---|  |----|  |__   |  |_)  | |  |  |  | |  |  |  | |  '  /     
|  . `  | |  |  |  |     |  |    |   __|  |   _  <  |  |  |  | |  |  |  | |    <      
|  |\   | |  `--'  |     |  |    |  |____ |  |_)  | |  `--'  | |  `--'  | |  .  \     
|__| \__|  \______/      |__|    |_______||______/   \______/   \______/  |__|\__\    
                                                                                      
     ___________    ____  _______.___________._______ .___  ___.                      
    /       \   \  /   / /       |           |   ____||   \/   |                      
   |   (----`\   \/   / |   (----`---|  |----|  |__   |  \  /  |                      
    \   \     \_    _/   \   \       |  |    |   __|  |  |\/|  |                      
.----)   |      |  | .----)   |      |  |    |  |____ |  |  |  |                      
|_______/       |__| |_______/       |__|    |_______||__|  |__|                      
                                                                                      
)EOF");
				
				printf(" ");
				printf("\t [1] Cargar notebook \n");
				printf("\t [2] Eliminar notebook \n");
				printf("\t [3] Modificar notebook \n");
				printf("\t [4] Buscar Notebok \n");
				printf("\t [5] Listar notebooks \n");
				printf("\t [6] Agregar stock \n");
				printf("\t [7] Cargar venta \n");
				printf("\t [8] Cantidad de netbooks con x procesador \n");
				printf("\t [9] Cantidad de netbooks con x RAM \n");
				printf("\t [10] Ordenamientos (ABRIR MENU) \n");
				printf("\t [11] Salir del programa \n");
				printf("\t [12] Creditos!\n\n");
				getoxy(18,28); printf("[ "); getoxy(21,28); printf(" ]"); getoxy(20,28);
				scanf("%i",&opcion);
				
				switch(opcion){
					case 1:
					system("cls");
					cargarNetbook();
						break;
						
					case 2:
						system("cls");
						eliminarNetbook();
						break;
					
					case 3:
						system("cls");
						modificarNetbook();
						break;
						
					case 4:
						system("cls");
						buscarNetbook();
						break;
					
					case 5:
						system("cls");
						listarNetbooks();
						break;
					
					case 6:
						system("cls");
						agregarStock();
						break;
						
					case 7:
						system("cls");
						cargarVenta();
						break;
						
					case 8:
						system("cls");
						cantidadCPU();
						break;
						
					case 9:
						system("cls");
						cantidadRAM();
						break;
		
					case 10: 
						system("cls");
					    Ordenamientos();
					    break;		
					case 11:
						opcion=11;
						system("cls");
						printf("HASTA LUEGO!");	
						system("exit");
						break;
					
					case 12:
						opcion=12;
						system("CLS");
						printf(R"EOF(
                            
   ____  ___   _   _   __  __  _   _   ____  _   _   ___     ____     _     ____   ___  _   _   ___  
  / ___|/ _ \ | \ | | |  \/  || | | | / ___|| | | | / _ \   / ___|   / \   |  _ \ |_ _|| \ | | / _ \ 
 | |   | | | ||  \| | | |\/| || | | || |    | |_| || | | | | |      / _ \  | |_) | | | |  \| || | | |
 | |___| |_| || |\  | | |  | || |_| || |___ |  _  || |_| | | |___  / ___ \ |  _ <  | | | |\  || |_| |
  \____|\___/ |_| \_| |_|  |_| \___/  \____||_| |_| \___/   \____|/_/   \_\|_| \_\|___||_| \_| \___/ 
                        )EOF");
					
					 	Sleep(1800);
						system("cls");
					printf(R"EOF(
  ____    _     ____      _      _____  _       ____   ____    ___   _____  _____ 
 |  _ \  / \   |  _ \    / \    | ____|| |     |  _ \ |  _ \  / _ \ |  ___|| ____|
 | |_) |/ _ \  | |_) |  / _ \   |  _|  | |     | |_) || |_) || | | || |_   |  _|  
 |  __// ___ \ |  _ <  / ___ \  | |___ | |___  |  __/ |  _ < | |_| ||  _|  | |___ 
 |_|  /_/   \_\|_| \_\/_/   \_\ |_____||_____| |_|    |_| \_\ \___/ |_|    |_____|
      _   ___   ____    ____  _____                                               
     | | / _ \ |  _ \  / ___|| ____|                                              
  _  | || | | || |_) || |  _ |  _|                                                
 | |_| || |_| ||  _ < | |_| || |___                                               
  \___/  \___/ |_| \_\ \____||_____|                                              
                    	                                                    
)EOF");
						Sleep(1800);
						system("cls");  
						printf(R"EOF(
 _____ ______ _   _______ _____    _   __
|  __ \| ___ \ | | | ___ \  _  |  | | / /
| |  \/| |_/ / | | | |_/ / | | |  | |/ / 
| | __ |    /| | | |  __/| | | |  |    \ 
| |_\ \| |\ \| |_| | |   \ \_/ /  | |\  \
 \____/\_| \_|\___/\_|    \___/   \_| \_/
                                         
                                         

)EOF");

						Sleep(1100);
						system("cls");
						printf(R"EOF(
______                                      ___                          ___                   
|  ___|                                    |_  |                        |_  |                  
| |_  ___  _ __  _ __  __ _  _ __  __ _      | | _   _   __ _  _ __       | |  ___   ___   ___ 
|  _|/ _ \| '__|| '__|/ _` || '__|/ _` |     | || | | | / _` || '_ \      | | / _ \ / __| / _ \
| | |  __/| |   | |  | (_| || |  | (_| | /\__/ /| |_| || (_| || | | | /\__/ /| (_) |\__ \|  __/
\_|  \___||_|   |_|   \__,_||_|   \__,_| \____/  \__,_| \__,_||_| |_| \____/  \___/ |___/ \___|
                                                                                               
                                                                                               
)EOF");

						Sleep(1100);
						system("cls");
						
						printf(R"EOF(
 _____                     _              _             _      
/  __ \                   (_)            | |           (_)     
| /  \/  __ _  _ __  _ __  _  ____ ___   | |     _   _  _  ___ 
| |     / _` || '__|| '__|| ||_  // _ \  | |    | | | || |/ __|
| \__/\| (_| || |   | |   | | / /| (_) | | |____| |_| || |\__ \
 \____/ \__,_||_|   |_|   |_|/___|\___/  \_____/ \__,_||_||___/
                                                               
                                                                                                                                                 
)EOF");

						Sleep(1100);
						system("cls");
						
							printf(R"EOF(
 _   _                _            ___                              _        
| \ | |              (_)          |_  |                            (_)       
|  \| |  __ _  _ __   _   __ _      | |  ___    __ _   __ _  _   _  _  _ __  
| . ` | / _` || '_ \ | | / _` |     | | / _ \  / _` | / _` || | | || || '_ \ 
| |\  || (_| || | | || || (_| | /\__/ /| (_) || (_| || (_| || |_| || || | | |
\_| \_/ \__,_||_| |_||_| \__,_| \____/  \___/  \__,_| \__, | \__,_||_||_| |_|
                                                         | |                 
                                                         |_|                                                                                                  
)EOF");

						Sleep(1100);
						system("cls");
						
						printf(R"EOF(
 _____                              _                               
/  __ \                            | |                              
| /  \/  ___   _ __  _ __   _   _  | |      __ _  _   _  _ __  __ _ 
| |     / _ \ | '__|| '_ \ | | | | | |     / _` || | | || '__|/ _` |
| \__/\| (_) || |   | |_) || |_| | | |____| (_| || |_| || |  | (_| |
 \____/ \___/ |_|   | .__/  \__,_| \_____/ \__,_| \__,_||_|   \__,_|
                    | |                                             
                    |_|                                                                                                                                                                       
)EOF");

						Sleep(1100);
						system("cls");
					
					printf(R"EOF(
______       _                                  ______       _      _        
| ___ \     | |                                 | ___ \     | |    | |       
| |_/ / ___ | |_  __ _  _ __ ___    __ _  _ __  | |_/ /__ _ | |__  | |  ___  
|    / / _ \| __|/ _` || '_ ` _ \  / _` || '__| |  __// _` || '_ \ | | / _ \ 
| |\ \|  __/| |_| (_| || | | | | || (_| || |    | |  | (_| || |_) || || (_) |
\_| \_|\___| \__|\__,_||_| |_| |_| \__,_||_|    \_|   \__,_||_.__/ |_| \___/ 
                                                                             
                                                                                                                                                                                                                     
)EOF");

						Sleep(1100);
						system("cls");
		
				}
			}else{
				do{
				
				printf("\n\t Bienvenido a Notebook System");
				printf("\n\t Debe cargar al menos una notebook para comenzar a trabajar\n");
				printf("\n\t [1] Cargar notebook ");
				printf("\n\t [2] Salir de programa \n\n");
				int opcion2;
				scanf("%i", &opcion2);
				
				switch(opcion2){
					case 1:
					system("cls");
					cargarNetbook();
						break;
					case 2:
						opcion=11;
						system("cls");
						printf("HASTA LUEGO!");
						system("exit");
						break;
					
					default: 
					printf("\n\t Opcion incorrecta\n\n");
						break;
				}
					haydatos = checkifFileExist();
				}while(!haydatos&&opcion!=11);
			}
			
		} while (opcion!=11);
		
	
	
	return 0;
}
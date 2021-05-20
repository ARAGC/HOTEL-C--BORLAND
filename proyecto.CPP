//////////--MARLON ARAELY CASTILLO GARCÍA CARNET: 4890-18-20988--/////////////

////////PROGRAMA PARA EL CONTROL DE SERVICIOS DEL HOTEL LAS ESTRELLAS/////////

/////////////////DECLARACION DE LIBRERIAS A UTILIZAR/////////////////////////

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

///////////////--DECLARACION DE ESTRUCTURAS Y VARIABLES--/////////////////////
struct sHabitacion {
	int fecha,fecha2, num;
   char nombre[30];
   char tipo[30];
   char estado[20];
}vHabitacion;

struct cafeteria {
	int precio, total;
   char alimento[50];
   char refaccion[50];
}cmenu;

struct cuarto
{
	char dato[30];
   int tiempo,num;
   }dservicio;

struct quejas {
	char datos[50];
   char tipo[30];
   }vQuejas;

/*****************************************************************************/
/***************---------------MENU PRINCIPAL---------------******************/
void menu (){
	system ("COLOR 3");
	clrscr();
   gotoxy(45,7);	printf("HOTEL LAS ESTRELLAS");
   gotoxy(45,8);	printf("SERVICIOS DEL HOTEL");
   gotoxy(45,9);	printf("1.HABITACIONES");
   gotoxy(45,10);	printf("2.CAFETERIA");
   gotoxy(45,11);	printf("3.SERVICIO AL CUARTO");
   gotoxy(45,12);	printf("4.QUEJAS");
   gotoxy(45,13);	printf("5.Finalizar");
  }
/*****************************************************************************/
/*****************-------------HABITACIONES------------***********************/
void Habitacion (){
   system ("COLOR 2");
	clrscr();
   gotoxy(45,8);	printf("1.Crear Archivo de Habitacion");
   gotoxy(45,9); 	printf("2.Reservar");
   gotoxy(45,10);	printf("3.Inactivar/Activar");
   gotoxy(45,11);	printf("4.Monitoreo de Habitaciones");
   gotoxy(45,12);	printf("5.Regresar");
  }
void CrearArchivo(FILE *Archivo){
	Archivo=fopen("habitaciones.bin", "wb");
   if(!Archivo){
   	Archivo=fopen("habitaciones.bin", "rb");
      printf("\n Archivo Creado");
      }
   else{
   	printf("\nEl archivo ya existe");
      }
   fclose(Archivo);
}

void InsertarDatos(FILE *Archivo){

	clrscr();
   char cod[10];
   Archivo = fopen("habitaciones.bin", "ab+");
   if(Archivo == NULL)
   {
   	printf("\nEl archivo no existe! \nPor favor creélo");
      return;
	}
		printf("Nombre del Cliente:");
   	cprintf("");
   	gets(vHabitacion.nombre);
	  	printf("Fecha Llegada:");
   	cprintf("");
   	vHabitacion.fecha=atoi(gets(cod));
      printf("Numero de Habitacion:");
      cprintf("");
      vHabitacion.num=atoi(gets(cod));
   	printf("Tipo de Habitacion:");
  		cprintf("");
   	gets(vHabitacion.tipo);
      printf("Fecha de Salida:");
  		cprintf("");
   	vHabitacion.fecha2=atoi(gets(cod));
   fwrite(&vHabitacion, sizeof(struct sHabitacion), 1, Archivo);
   fclose(Archivo);
}
void encabezado()
{
	clrscr();
	gotoxy(10,1);	printf("--------------------------------------------------------------------------------------------------");
	gotoxy(10,2);	printf("--------------------------------------------------------------------------------------------------");
   gotoxy(10,4);	printf("--------------------------------------------------------------------------------------------------");
   gotoxy(10,3);	printf("Registro");
	gotoxy(20,3);	cprintf("Cliente");
   gotoxy(40,3);	cprintf("Llegada");
   gotoxy(55,3);	cprintf("No Hab.");
   gotoxy(65,3);	cprintf("Habitacion");
   gotoxy(85,3);	cprintf("Salida");
   gotoxy(95,3);	cprintf("Estado");
   getch();

}
void VerDatos(FILE *Archivo)
{
	clrscr();
   encabezado();
   int numero=1;
   Archivo =fopen("habitaciones.bin", "rb");
   if(Archivo == NULL)
   {
   	printf("\nArchivo no existe! \nPor favor Creelo");
      return;
   }

   fread(&vHabitacion, sizeof(struct sHabitacion), 1, Archivo);
   while(!feof(Archivo))
   {  gotoxy(10, numero+4); printf("%d", numero);
      gotoxy(20, numero+4); printf("%s", vHabitacion.nombre);
      gotoxy(40, numero+4); printf("%d", vHabitacion.fecha);
      gotoxy(55, numero+4); printf("%d", vHabitacion.num);
      gotoxy(65, numero+4); printf("%s", vHabitacion.tipo);
      gotoxy(85, numero+4); printf("%d", vHabitacion.fecha2);
      gotoxy(95, numero+4); printf("%s", vHabitacion.estado);
      fread(&vHabitacion, sizeof(struct sHabitacion), 1, Archivo);
      numero ++;
   }
  fclose(Archivo);
    getch();
}

void Activar(FILE *Archivo)
{   clrscr();
    Archivo =fopen("habitaciones.bin","rb+");
    if (Archivo == NULL)
        exit(1);
    printf("Ingrese el numero de la habitacion para inactivar o activar:");
    int cod;
    scanf("%i", &cod);
    int existe=0;
   fread(&vHabitacion, sizeof(struct sHabitacion), 1, Archivo);
    while(!feof(Archivo))
    {
        if (cod==vHabitacion.num)
        {
           gotoxy(10,2); printf("%s", vHabitacion.nombre);
           gotoxy(10,4); printf("%d", vHabitacion.num);
           gotoxy(10,6); printf("%s", vHabitacion.tipo);
           printf("\nIngrese el Estado de la Habitacion:");
           scanf("%s",&vHabitacion.estado);
           int pos=ftell(Archivo)- sizeof(vHabitacion);
           fseek(Archivo,pos,SEEK_SET);
           fwrite(&vHabitacion, sizeof(struct sHabitacion), 1, Archivo);
           printf("Se realizo el cambio en el Estado de la Habitacion\n");
           existe=1;
           break;
        }
         fread(&vHabitacion, sizeof(struct sHabitacion), 1, Archivo);
    }
    if (existe==0)
    printf("No existe una habitacion con dicho numero\n");
    fclose(Archivo);
    getch();
    }

void mHabitacion (){

	int opcion;
	char Cop[2];
	int exit = 0;
   FILE *archivo;
    while(!exit){
	Habitacion();
   gotoxy(45,14); printf("Opcion:");
   opcion = atoi(gets(Cop));
   switch(opcion)
      {
        	case 1: CrearArchivo(archivo); break;
         case 2: InsertarDatos(archivo); break;
         case 3: Activar(archivo); break;
         case 4: VerDatos(archivo); break;
        	case 5: exit = 1; break;
         default: gotoxy(45,16);	printf("Opcion no valida");
         getch();
      }
      }
	}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
/*****************------------CAFETERIA----------------***********************/
void MenuC(){
	clrscr();
   textcolor(23);
   gotoxy(45,8);	printf("1.Crear Nuevo Archivo de Menu");
   gotoxy(45,9);	printf("2.Mostrar Menu");
   gotoxy(45,10);	printf("3.Modificar Menu");
   gotoxy(45,11);	printf("4.Monitoreo de Cafeteria");
   gotoxy(45,12);	printf("5.Regresar");

  }
void CrearArchCa(FILE *ArchivoC){
	ArchivoC=fopen("cafeteria.bin", "wb");
   if(!ArchivoC){
   	ArchivoC=fopen("cafeteria.bin", "rb");
      printf("\n Archivo Creado");
      }
   else{
   	printf("\nEl archivo ya existe");
      }
   fclose(ArchivoC);
}

void IngresarDatos(FILE *ArchivoC){

	clrscr();
   char cod[4];
   ArchivoC = fopen("cafeteria.bin", "ab+");

   if(ArchivoC == NULL)
   {
   	printf("\nEl archivo no existe! \nPor favor creélo");
      return;
	}
		printf("Ingrese el Alimento:");
   	cprintf("");
   	gets(cmenu.alimento);
	  	printf("Ingrese Refaccion:");
   	cprintf("");
      gets(cmenu.refaccion);
   	printf("Ingrese el Precio:");
  		cprintf("");
		cmenu.precio=atoi(gets(cod));
      printf("Ingrese el Total de Existencias:");
  		cprintf("");
   	cmenu.total=atoi(gets(cod));
   fwrite(&cmenu, sizeof(struct cafeteria), 1, ArchivoC);
   fclose(ArchivoC);
}
void encabezadoC()
{
	clrscr();
	gotoxy(10,1);	printf("---------------------------------------------------------------------------------------");
	gotoxy(10,2);	printf("---------------------------------------------------------------------------------------");
   gotoxy(10,4);	printf("---------------------------------------------------------------------------------------");
   gotoxy(10,3);	printf("Registro");
	gotoxy(20,3);	cprintf("Alimento");
   gotoxy(50,3);	cprintf("Refaccion");
   gotoxy(70,3);	cprintf("Precio");
   gotoxy(80,3);	cprintf("Existencia");
   getch();

}
void VerDatosC(FILE *ArchivoC)
{
	clrscr();
   encabezadoC();
   int numero=1;
   ArchivoC =fopen("cafeteria.bin", "rb");
   if(ArchivoC == NULL)
   {
   	printf("\nArchivo no existe! \nPor favor Creelo");
      return;
   }

   fread(&cmenu, sizeof(struct cafeteria), 1, ArchivoC);
   while(!feof(ArchivoC))
   {  gotoxy(10, numero+4);	printf("%d", numero);
      gotoxy(20, numero+4);	printf("%s", cmenu.alimento);
      gotoxy(50, numero+4);	printf("%s", cmenu.refaccion);
      gotoxy(70, numero+4);	printf("%d", cmenu.precio);
      gotoxy(80, numero+4);	printf("%d", cmenu.total);
      fread(&cmenu, sizeof(struct cafeteria), 1, ArchivoC);
      numero ++;
   }
  fclose(ArchivoC);
    getch();
}
void Modificacion(FILE *ArchivoC)
{   clrscr();
    ArchivoC =fopen("cafeteria.bin","rb+");
    if (ArchivoC == NULL)
        exit(1);
    printf("Ingrese el numero de registro de la opcion a modificar:");
    int cod;
    scanf("%i", &cod);
    int existe=0;
   fread(&cmenu, sizeof(struct cafeteria), 1, ArchivoC);
    while(!feof(ArchivoC))
    {
        if (cod==cmenu.precio)
        {
           gotoxy(10,2); printf("%s", cmenu.alimento);
           gotoxy(10,4); printf("%s", cmenu.refaccion);
           gotoxy(10,6); printf("%d", cmenu.precio);
           gotoxy(10,8); printf("%d", cmenu.total);
           printf("\nIngrese el nuevo alimento:");
           scanf("%s",&cmenu.alimento);
           printf("\nIngrese la nueva refaccion:");
           scanf("%s",&cmenu.refaccion);
           printf("\nIngrese el nuevo precio:");
           scanf("%d",&cmenu.precio);
           printf("\nIngrese el nuevo total de existencias:");
           scanf("%d",&cmenu.total);
           int pos=ftell(ArchivoC)- sizeof(cmenu);
           fseek(ArchivoC,pos,SEEK_SET);
           fwrite(&cmenu, sizeof(struct cafeteria), 1, ArchivoC);
           printf("Se modifico los datos\n");
           existe=1;
           break;
        }
         fread(&cmenu, sizeof(struct cafeteria), 1, ArchivoC);
    }
    if (existe==0)
        printf("No existe una opcion con dicho numero\n");
    fclose(ArchivoC);
    getch();
    }
void mCafeteria (){
int opcion;
	char Cop[2];
	int exit = 0;
   FILE *archivoC;
    while(!exit){
	MenuC();
   gotoxy(45,14); printf("Opcion:");
   opcion = atoi(gets(Cop));
   switch(opcion)
      {
         case 1: CrearArchCa(archivoC); break;
         case 2: IngresarDatos(archivoC); break;
         case 3: Modificacion(archivoC); break;
         case 4: VerDatosC(archivoC); break;
        	case 5: exit = 1; break;
         default: gotoxy(45,16);	printf("Opcion no valida");
         getch();
      }
   }
 }
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
/***********--------------SERVICIO AL CUARTO--------------*******************/
void Servicio (){

	clrscr();
   gotoxy(45,7);	printf("1.Crear Archivo de Servicios");
   gotoxy(45,8);	printf("2.Solicitar Servicio Limpieza, Alimentos, Masajes");
   gotoxy(45,9);	printf("3.Monitoreo de Servicios");
   gotoxy(45,10);	printf("4.Regresar al Menu Principal");
   }
void NuevoArchivo (FILE *Servi){
	Servi=fopen("servicios.bin", "wb");
   if(!Servi){
   Servi=fopen("servicios.bin", "rb");
   printf("\n Archivo Creado");
      }
   else{
   	printf("\nEl archivo ya existe");
      }
   fclose(Servi);
}

void Datos(FILE *Servi){
 clrscr();
   char cod[10];
   Servi = fopen("servicios.bin", "ab+");
   if(Servi == NULL)
   {
   	printf("\nEl archivo no existe! \nPor favor creélo");
      return;
	}
      printf("----------Servicio de Limpieza, Alimentos y Masajes-------------");
		printf("\nQue Servicio desea en su Habitacion:");
   	cprintf("");
   	gets(dservicio.dato);
	  	printf("Ingrese los minutos en que requiere el servicio:");
   	cprintf("");
   	dservicio.tiempo=atoi(gets(cod));
      printf("Ingrese el Numero de Habitacion:");
      cprintf("");
      dservicio.num=atoi(gets(cod));
      fwrite(&dservicio, sizeof(struct cuarto), 1, Servi);
      printf("\nEn un momento se atendera el servicio Solicitado...."); getch();
   fclose(Servi);
}
void EncServicios()
{
	clrscr();
	gotoxy(10,1);	printf("--------------------------------------------------------------------------------------------------");
	gotoxy(10,2);	printf("--------------------------------------------------------------------------------------------------");
   gotoxy(10,4);	printf("--------------------------------------------------------------------------------------------------");
   gotoxy(10,3);	printf("Registro");
	gotoxy(20,3);	cprintf("Servicio");
   gotoxy(35,3);	cprintf("Tiempo (Minutos)");
   gotoxy(55,3);	cprintf("No Habitacion");
   gotoxy(80,3);	cprintf("Estado");
   getch();

}
void MonitoreoServicios(FILE *Servi)
{
	clrscr();
   EncServicios();
   int numero=1;
   Servi =fopen("servicios.bin", "rb");
   if(Servi == NULL)
   {
   	printf("\nArchivo no existe! \nPor favor Creelo");
      return;
   }

   fread(&dservicio, sizeof(struct cuarto), 1, Servi);
   while(!feof(Servi))
   {  gotoxy(10, numero+4); printf("%d", numero);
      gotoxy(20, numero+4); printf("%s", dservicio.dato);
      gotoxy(40, numero+4); printf("%d", dservicio.tiempo);
      gotoxy(60, numero+4); printf("%d", dservicio.num);
      fread(&dservicio, sizeof(struct cuarto), 1, Servi);
      numero ++;
   }
  fclose(Servi);
    getch();
}

void mServicio (){
int opcion;
	char Cop[2];
	int exit = 0;
   FILE *servi;
   while(!exit){
	Servicio();
   gotoxy(45,13); printf("Opcion:");
   opcion = atoi(gets(Cop));
   switch(opcion)
      {
        	case 1: NuevoArchivo(servi); break;
         case 2: Datos(servi); break;
         case 3: MonitoreoServicios(servi); break;
         case 4: exit = 1; break;
         default: gotoxy(45,15);	printf("Opcion no valida");
         getch();
      }
      }
 }
/*****************************************************************************/
/*********************------------QUEJAS----------****************************/
void Quejas (){
system ("COLOR 5");
	clrscr();
   gotoxy(45,7);	printf("1.Crear un Nuevo Archivo de Quejas");
   gotoxy(45,8);	printf("2.Ingresar Queja");
   gotoxy(45,9);	printf("3.Monitoreo de Quejas");
   gotoxy(45,10);	printf("4.Volver al Menu Principal");
   }

void CrearQuejas (FILE *archQ){
archQ=fopen("quejas.bin", "wb");
	if(!archQ){
   	archQ=fopen("quejas.bin", "rb");
      printf("\n Archivo Creado");
      }
   else{
   	printf("\nYa existe un archivo con este nombre");
      }getch();
      fclose(archQ);
   }
void IngresarQuejas (FILE *archQ){
   clrscr();
   archQ = fopen("quejas.bin", "ab+");

   if(archQ == NULL)
   {
   	printf("\nEl archivo no existe! \nPor favor crear un archivo");
      return; getch();
   }
   	printf("---------Por Favor Ingrese un Comentario o Queja de los Servicios---------");
      printf("\n----------------Especifique de que tipo Administrativo/Tecnico------------");
      printf("\nIngrese el tipo de Queja:");
      gets(vQuejas.tipo);
      printf("\nDetalle la Queja:");
      gets(vQuejas.datos);
   fwrite(&vQuejas, sizeof(struct quejas), 1, archQ);
   	printf("\nRegistro Completo..."); getch();
   fclose(archQ);
   }
void encQuejas(){
         clrscr();
         gotoxy(10,1);	printf("------------------MONITOREO DE LAS QUEJAS DEL SERVICIO DEL HOTEL LAS ESTRELLAS--------------------");
			gotoxy(10,2);	printf("--------------------------------------------------------------------------------------------------");
   		gotoxy(10,4);	printf("--------------------------------------------------------------------------------------------------");
   		gotoxy(10,3);	printf("Registro");
			gotoxy(20,3);	cprintf("Administrativo/Tecnico");
   		gotoxy(50,3);	cprintf("Queja");
         getch();
}

void verQuejas (FILE *archQ){
	clrscr();
   encQuejas();
   int numero=1;
   archQ = fopen ("quejas.bin", "rb");
   if(archQ == NULL)
   {
   	printf("\nEl archivo no existe! \nPor favor crear un archivo");
      return; getch();
   }
   fread(&vQuejas, sizeof(struct quejas), 1, archQ);
   while(!feof(archQ))
   {
      gotoxy(10, numero+4); printf("%d", numero);
      gotoxy(25, numero+4); printf("%s", vQuejas.tipo);
      gotoxy(50, numero+4); printf("%s", vQuejas.datos);
      fread(&vQuejas, sizeof(struct quejas), 1, archQ);
      numero ++;
   }
   fclose(archQ);
   getch();
}
void mQuejas (){


	int opcion;
	char Cop[2];
	int exit = 0;
   FILE *archQ;
    while(!exit){
	Quejas();
   gotoxy(45,14);	printf("Opcion:");
   opcion = atoi(gets(Cop));
   switch(opcion)
      {
        	case 1: CrearQuejas(archQ); break;
         case 2: IngresarQuejas(archQ); break;
         case 3: verQuejas(archQ); break;
        	case 4: exit = 1; break;
         default: gotoxy(45,16);	printf("Opcion no valida");
         getch();
      }
      }

}
/****************************************************************************/
/****************------------FUNCION PRINCIPAL------------******************/
void main()
{
	int opcion;
   char Cop[2];
  int exit = 0;
  while(!exit)
  {
      menu();
      gotoxy(45,15);	printf("Opcion:");
      opcion = atoi(gets(Cop));
      switch(opcion)

      {
       	case 1: mHabitacion(); break;
         case 2: mCafeteria(); break;
         case 3: mServicio(); break;
         case 4: mQuejas(); break;
         case 5: exit = 1; break;
         default: gotoxy(45,17);	printf("Opcion no valida");
         getch();
      }
  }
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//asignamos sinonimos
typedef struct Asignatura Asignatura;
typedef struct Fecha Fecha;
typedef  Asignatura *ptrAsignatura;

//estructura secundaria
struct Fecha{   
    int hora;
    int minuto;
};

//estructura principal 
struct Asignatura{
    int diaSemana;
    char *nombreAsignatura;
    Fecha *horarioEntrada;
    Fecha *horarioSalida;
    Asignatura *next;
};


//funcion para leer datos
void leerDatos(ptrAsignatura*lista);
//funcion para crear nodo
void crearNodo(char ordenamiento, ptrAsignatura*lista, char *nombreAsignatura, Fecha *horarioEntrada,Fecha *horarioSalida,int diaClase);
//funcion para ordenar el nodo de manera ascendente
void ordenarNodoAscendente(ptrAsignatura*lista, ptrAsignatura nuevaAsigtura, int diaClase);
//funcion para ordenar el nodo de manera descendente
void ordenarNodoDescendente(ptrAsignatura*lista, ptrAsignatura nuevaAsigtura, int diaClase);
//funcion para imprimir el horario
void imprimir(ptrAsignatura lista);
//funcion para ordenar

int main(){

    ptrAsignatura lista = NULL; 
    leerDatos(&lista);
    imprimir(lista);
}



void leerDatos(ptrAsignatura*lista){
	
    char ordenamiento;
    char nombreMateria[84];
    char resp;
    int diaClase;

    //punteros auxiliares de tipo Fecha
    Fecha *datosEntrada,*datosSalida;
    
	//preguntamos si el usuario desea correr el programa
    printf("Desea generar su horario?\n");
    scanf("%c",&resp);
    fflush(stdin);
    
    if(resp!='s'||resp!='S'){
    	printf("Programa finalizado\n");
	}

    printf("De que manera desea ordenar su horario?\n");
    printf("1.- Ascendente\n");
    printf("2.- Descendente\n");
    scanf("%c", &ordenamiento);
    fflush(stdin);

    //solicitamos los datos sobre el horario
    while(resp=='s'||resp=='S'){
        datosEntrada=(Fecha*)malloc(sizeof(Fecha));
        datosSalida=(Fecha*)malloc(sizeof(Fecha));
        
		printf("Ingrese el nombre de la Asignatura\n");
        gets(nombreMateria);
        fflush(stdin);

        printf("Ingrese el dia de la semana que tiene clase de dicha Asignatura \n");
        scanf("%d",&diaClase);
        printf("Ingrese la hora de entrada a la asignatura\n");
        scanf("%d",&datosEntrada->hora);
        printf("Ingrese el minuto de entrada a la asignatura\n");
        scanf("%d",&datosEntrada->minuto);
        printf("Ingrese la hora de salida de la asignatura\n");
        scanf("%d",&datosSalida->hora);
        printf("Ingrese el minuto de salida de la asignatura\n");
        scanf("%d",&datosSalida->minuto);
        fflush(stdin);

        crearNodo(ordenamiento,lista,nombreMateria,datosEntrada,datosSalida,diaClase);
        fflush(stdin);

        printf("Desea meter otra asignatura al horario?\n");
        scanf("%c",&resp);
        fflush(stdin);
        system("cls");
    }
}


void crearNodo(char ordenamiento,ptrAsignatura*lista, char *nombreAsignatura, Fecha *horarioEntrada,Fecha *horarioSalida,int diaClase){


    ptrAsignatura nuevaAsigtura,auxiliar,anterior;
    nuevaAsigtura = (Asignatura*)malloc(sizeof(Asignatura)); //Creamos el nodo

    //Metemos los datos al nodo
    nuevaAsigtura->nombreAsignatura = (char*)malloc((strlen(nombreAsignatura)+1) *sizeof(char));
    strcpy(nuevaAsigtura->nombreAsignatura,nombreAsignatura);
    
    nuevaAsigtura->horarioEntrada=horarioEntrada;
    nuevaAsigtura->horarioSalida=horarioSalida;
    nuevaAsigtura->diaSemana=diaClase;

    if(ordenamiento=='1'){
        ordenarNodoAscendente(lista, nuevaAsigtura, diaClase);
    }
    else if(ordenamiento=='2'){
        ordenarNodoDescendente(lista, nuevaAsigtura, diaClase);
    }

}



void ordenarNodoAscendente(ptrAsignatura*lista, ptrAsignatura nuevaAsigtura, int diaClase){
    ptrAsignatura auxiliar,anterior;
    anterior=NULL;
    auxiliar=*lista;

    while (auxiliar!=NULL&&diaClase>auxiliar->diaSemana){
        anterior=auxiliar;
        auxiliar=auxiliar->next;
        /* code */
    }

    if(anterior==NULL){
        nuevaAsigtura->next=*lista;
        *lista=nuevaAsigtura;
    }else{
        anterior->next=nuevaAsigtura;
        nuevaAsigtura->next=auxiliar;
    }
}



void ordenarNodoDescendente(ptrAsignatura*lista,ptrAsignatura nuevaAsigtura, int diaClase){
    ptrAsignatura auxiliar,anterior;
    anterior=NULL;
    auxiliar=*lista;
    

    while (auxiliar!=NULL&&diaClase<auxiliar->diaSemana){
        anterior=auxiliar;
        auxiliar=auxiliar->next;
        /* code */
    }

    if(anterior==NULL){
        nuevaAsigtura->next=*lista;
        *lista=nuevaAsigtura;
    }else{
        anterior->next=nuevaAsigtura;
        nuevaAsigtura->next=auxiliar;
    }
}


void imprimir(ptrAsignatura lista){
    char escritura[6][15] ={"Lunes","Martes","Miercoles","Jueves","Viernes","Sabado"};
    
    while(lista  != NULL){

        printf("Nombre materia: %s \n",lista->nombreAsignatura);
        printf("El dia de la semana es: %s\n",escritura[lista->diaSemana]);
        printf("Hora de Entrada: %d\n",lista->horarioEntrada->hora);
        printf("Minuto de Entrada: %d\n",lista->horarioEntrada->minuto);
        printf("Hora de Salida %d\n",lista->horarioSalida->hora);
        printf("Minuto de Salida: %d\n",lista->horarioSalida->minuto);
        printf("-------------------------------------\n");
        lista= lista->next;
    }
}







#include <stdio.h>
#include <stdlib.h>

typedef struct _Nodo {
  int data;
  struct _Nodo *next;
} Nodo;

void menu();
Nodo * allocateMemory(int);
Nodo * push(Nodo *, int );
Nodo *pop(Nodo* );
void show(Nodo *);


int main(int argc, char *argv[]) {
  Nodo *queue = NULL;
  int opt=0, data=0, dataNumber = 0, i =0;
  do{
    printf("\n1.Meter en queue\n2.Quitar elemento\n(-1).Salir\nOpcion: ");
    scanf("%i",&opt);
    switch (opt){
      case 1:
        printf("Ingresa de elementos para la queue: ");
        scanf("%i",&dataNumber);
        for(i = 0; i < dataNumber; i++){
        printf("Ingresa dato %i: ", i+1);
        scanf("%i",&data);
          queue=push(queue, data);
        }  
      break;
      case 2:
        queue=pop(queue);
      break;
    }
  printf("La queue hasta ahora es: ");
  show(queue); 

  }while (opt!=-1);
  printf("\n");
  system("pause");
	return 0;
}



Nodo * allocateMemory(int _data){
  Nodo * nData;
  nData = (Nodo*)malloc(sizeof(Nodo));
  nData->data= _data;
  nData->next=NULL;
  return nData;     
}

Nodo * push(Nodo *_front, int _data){
 Nodo *nFront, *nAux;
  nFront = allocateMemory(_data);
	if(_front==NULL){
		_front=nFront;
	}else{
		nAux = _front;
		while(nAux->next){
			nAux=nAux->next;
		}
		nAux->next=nFront;
	}
  return _front;
}

void show(Nodo *cabeza){
  if(cabeza == NULL){
    printf("\nTu Cola esta vacia.\n");
  }
  while(cabeza!=NULL){
    printf("data: %i\t -> ",cabeza->data);
    cabeza=cabeza->next;
  }
}

Nodo *pop(Nodo *_start){
  Nodo *aux;
    if(_start!=NULL){
      aux=_start;
      _start=_start->next;
      free(aux);
    }
  return _start;
}
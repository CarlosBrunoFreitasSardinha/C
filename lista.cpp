#include <stdio.h>
#include <stdlib.h>
#include <lista.h>

#define INSERT 1
#define DELECT 2
#define SELECT 3
#define EXIT 4

int main(){
    int op,ano;
    lista *l;
    char produtora[45], idioma[45], titulo[45];
    do{
       printf("\n\n%d - Inserir   na Lista;\n",INSERT);
       printf("%d - Remover   da Lista;\n",DELECT);
       printf("%d - Apresentar a Lista;\n",SELECT);
       printf("%d - SAIR;\n",EXIT);
       printf("\n\n informe a opcao: ");
       scanf("%d",&op);
    switch (op){
          case INSERT:
               //informação A SER INSERIDA
               printf("\n\n informe o titulo: ");
               gets  (titulo);
               gets  (titulo);
               printf("\n\n informe o produtora: ");
               gets  (produtora);
               printf("\n\n informe o Idioma: ");
               gets  (idioma);
               printf("\n\n informe o ano: ");
               scanf ("%d",&ano);
               inserir(&l, ano, titulo, produtora, idioma);
               system("cls");
               break; 
          case DELECT: remover(&l); system("cls"); break; 
          case SELECT: listar(&l); break;
          case EXIT: free(l); system("cls"); break;
          default:
                printf ("\n\nERRO: Opcao Invalida.");
               break;
     }
     }while(op!=EXIT);
    system("PAUSE");
}

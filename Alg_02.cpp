#include <stdio.h>
#include <stdlib.h>
#include <trabalho04.h>

#define CADASTRAR 1
#define CONSULTAR 2
#define REMOVER 3
#define SAI 4

int main () {
    lista *l = NULL;
    int opcao, ano;
    char produtora[45], titulo[45], idioma[30];
    
    do{
         
         printf("\n\nDigite: ");
         printf("\n\n %d - Cadastrar ", CADASTRAR);
         printf("\n\n %d - Exibir", CONSULTAR);
         printf("\n\n %d - REMOVER", REMOVER);
         printf("\n\n %d - SAIR", SAIR);
         printf("\n\n Informe a opcao: ");
         scanf("%d", &opcao);
         
         switch (opcao){
                case CADASTRAR:
                     printf ("Informe o titulo: ");
                     gets (titulo);
                     gets (titulo);
                     printf ("Informe o produto: ");
                     gets (produtora);
                     printf ("Informe o idioma: ");
                     gets (idioma);
                     printf ("Informe o ano: ");
                     scanf ("%d",&ano);
                     inserir(&l, ano, titulo, produtora, idioma);
                     system("cls");
                     break;
                     
                case REMOVER:
                     remover(&l);
                     break;
                
                case CONSULTAR:
                     exibir(&l);
                     break;
                case SAIR:
                     break;
                
                default:
                        
                     printf("\n\n\t\tOpcao Invalida");
                     break;
                     
}
}while(opcao!=SAIR);
free(l);

system("PAUSE");
}

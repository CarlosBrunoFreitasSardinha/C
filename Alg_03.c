/*Implemente um programa em C, utilizando aloca��o din�mica com ponteiros de mem�ria,
que leia as seguintes informa��es sobre um n�mero indeterminado de alunos de uma
escola;
a) Nome;
b) S�rie;
c) Curso (1-Inform�tica, 2-Meio Ambiente, 3-Agroind�stria);
d) Idade .
Ap�s a leitura dos dados, o programa dever� oferecer as seguintes op��es para o usu�rio;
a) Listar o nome de todos os alunos em ordem alfab�tica;
b) Listar todos os alunos ordenados pela idade;
c) Listar todos os alunos de inform�tica;
d) Listar todos os alunos do sexo masculino;
e) Listar todos os alunos sexo feminino.
Nome do arquivo: alunos.c*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cadastro{
        char nome[35];
        char serie[35];
        int curso;
        int sexo;
        int idade;
        }cadastro;
       
        int main(){
            int i,j,t,s=1,*id=NULL;
            char *f=NULL;
            cadastro  *n=NULL,m;
            
            printf("quantos alunos ira listar: ");
            scanf("%d",&t);
            n=(cadastro*)malloc(sizeof(cadastro)*t);
            
            for (i=0;i<t;i++){
                printf("\n informe o nome: ");
                gets(n[i].nome);
                gets(n[i].nome);
                               
                printf("\n informe a serie: ");
                
                gets(n[i].serie);
                
                
                printf("\n Cursos (1-Inform�tica, 2-Meio Ambiente, 3-Agroind�stria): ");
                printf("\n informe o valor correspondente ao curso: ");
                scanf("%d",&n[i].curso);
                
                printf("\n Sexos(1-Masculino,2-feminino)");
                printf("\n informe o sexo: ");
                scanf("%d",&n[i].sexo);
                
                printf("\n informe a idade: ");
                scanf("%d",&n[i].idade);
                
                
             }
             system("cls");
             printf("\n\n listar por idade. \n");
             m=n[0];
             
             for (i=0;i<t;i++){
                 for (j=i+1;j<t;j++){
                     if (n[i].idade<n[j].idade){
                        m=n[i];
                        n[i]=n[j];
                        n[j]=m;
                        
                      }
                  }
              }
              for (i=0;i<t;i++){
                  printf("\n %s com %d\n\n",n[i].nome,n[i].idade);
               }
               printf("\n\n listar em ordem alfabetica. \n");
             
             for (i=0;i<t;i++){
                 for (j=i+1;j<t;j++){
                     if (strcmp(n[i].nome,n[j].nome)>0){
                        m=n[i];
                        n[i]=n[j];
                        n[j]=m;
                        
                      }
                  }
              }
              for (i=0;i<t;i++){
                  printf("\n %s\n\n",n[i].nome);
               }
               printf("\n\n\n\n listar alunos de Informatica. \n");
             
              for (i=0;i<t;i++){
                  if(n[i].curso==1)printf("\n %s \n\n",n[i].nome);
               }
               printf("\n\n listar alunos do sexo masculino. \n");
             
              for (i=0;i<t;i++){
                  if (n[i].sexo==1){
                     printf("\n %s\n\n",n[i].nome);
                     }
               }
               
               printf("\n\n\n\n listar alunos do sexo feminino. \n");
             
              for (i=0;i<t;i++){
                  if (n[i].sexo==1){
                     printf("\n %s\n\n",n[i].nome);
                     }
               }
               
               free(n);
            system("PAUSE");
            }

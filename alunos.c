#include <stdio.h>

typedef struct{
    char nome[50];
    int rga;
    float n1, n2, n3, ma;
    int result;
}regaluno;

void cadastroAluno(int n);
void mostrandoValores(int n);

int main(void){
    
    regaluno alunos[50];
    int n, i, j, flag, num, resp;
    
    flag = 1;
    
    while(flag == 1){
        printf("O que vc deseja fazer agora? \n ");
        printf("------------------------\n");
        printf("1 - Cadastrar um novo Aluno \n"); /* Feito */
        printf("2 - Remover Aluno \n"); /**/
        printf("3 - Atualizar as notas dos Alunos \n"); /**/
        printf("4 - Exibir Alunos cadastrados \n"); /* Feito */
        printf("5 - Exibir as medias dos Alunos \n"); /**/
        printf("7 - Sair \n");
        printf("------------------------\n");
        
        printf("Informe um numero para poder continuar: \n ");
        scanf("%d", &resp);
        
        if(resp == 7){
            printf("Muito Obrigado!  Volte sempre!");
            flag = 0;
        }
        else{
            switch(resp){
                case 1:
                    printf("Quantos Alunos vc ira cadastrar?  ");
                    scanf("%d", &n);

                    cadastroAluno(n);

                    printf("Informe um numero para poder continuar: (1 sim ou 0 nao)\n ");
                    scanf("%d", &resp);
                    
                    if(resp == 0)
                        flag = 0;
                break;
                
                case 2:
                    printf("Informe o rga que deseja remover:  ");
                    scanf("%d", &num);
                    
                    i = 0;
                    while(i < n){
                        
                        if(num == alunos[i].rga){
                            for(j = i; j < n; j++){
                                alunos[i].rga = alunos[i + 1].rga;
                            }
                            i = i + n;
                        }
                        
                        i = i + 1;
                    }

                    printf("Informe um numero para poder continuar: (1 sim ou 0 nao)\n ");
                    scanf("%d", &resp);
                    
                    if(resp == 0)
                        flag = 0;
                break;
                
                case 3:
                    printf("Informe o rga:  ");
                    scanf("%d", &num);

                    printf("Informe um numero para poder continuar: (1 sim ou 0 nao)\n ");
                    scanf("%d", &resp);
                    
                    if(resp == 0)
                        flag = 0;
                break;
                
                case 4:
                    mostrandoValores(n);

                    printf("Informe um numero para poder continuar: (1 sim ou 0 nao)\n ");
                    scanf("%d", &resp);
                    
                    if(resp == 0)
                        flag = 0;
                break;
                
                case 5:
                
                break;
                
                case 6:
                
                break;
            }
            
        }
        
    }
    
    
    
    return 0;
}


/* Funções do sistema */

void cadastroAluno(int n){

    regaluno alunos[50];
    int i;
                    
    for(i = 0; i < n; i++){
        printf("Digite o nome do Aluno:  ");
        scanf(" %[^\n]", alunos[i].nome);
                        
        printf("Informe o RGA:  ");
        scanf("%d", &alunos[i].rga);
                        
        printf("Informe a primeira nota:  ");
        scanf("%f", &alunos[i].n1);
                        
        printf("Informe a segunda nota:  ");
        scanf("%f", &alunos[i].n2);
                    
        printf("Informe a terceira nota:  ");
        scanf("%f", &alunos[i].n3);

       
    }
                    
    printf("CADASTRADO COM SUCESSO!!\n");
}




void mostrandoValores(int n){

    regaluno alunos[50];
    int i;

    for(i = 0; i < n; i++){
        printf("%s \n", alunos[i].nome);
        printf("%d \n", alunos[i].rga);
        printf("%.2f \n", alunos[i].n1);
        printf("%.2f \n", alunos[i].n2);
        printf("%.2f \n", alunos[i].n3);
    }
}
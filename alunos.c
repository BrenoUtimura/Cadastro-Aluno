#include <stdio.h>

typedef struct{
    char nome[50];
    int rga;
    float n1, n2, n3, ma;
}regaluno;

void cadastroAluno(regaluno alunos[], int n);
void mostrandoValores(regaluno alunos[], int n);
int buscaAluno(regaluno alunos[], int num, int n);

int main(void){
    
    regaluno alunos[50];
    int n, i, flag, num, resp, posicao;
    
    flag = 1;
    
    while(flag == 1){
        printf("O que vc deseja fazer agora? \n ");
        printf("------------------------\n");
        printf("1 - Cadastrar um novo Aluno \n"); 
        printf("2 - Remover Aluno \n"); 
        printf("3 - Atualizar as notas dos Alunos \n"); 
        printf("4 - Exibir Alunos cadastrados \n"); 
        printf("5 - Exibir as medias dos Alunos \n"); 
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

                    cadastroAluno(alunos, n);

                    printf("Informe um numero para poder continuar: (1 sim ou 0 nao)\n ");
                    scanf("%d", &resp);
                    
                    if(resp == 0)
                        flag = 0;
                break;
                
                case 2:
                    printf("Informe o rga que deseja remover:  ");
                    scanf("%d", &num);
                    
                    posicao = buscaAluno(alunos, num, n);

                    if(posicao == -1)
                        printf("RGA não encontrado!!\n");
                    else{
                        for(i = posicao; i < n - 1; i++){
                           alunos[i] = alunos[i + 1];  
                        }
                        n = n - 1;

                        printf("\nALUNO REMOVIDO COM SUCESSO!! \n\n");
                    } 

                    printf("Informe um numero para poder continuar: (1 sim ou 0 nao)\n ");
                    scanf("%d", &resp);
                    
                    if(resp == 0)
                        flag = 0;
                break;
                
                case 3:
                    printf("Informe o rga para atualizar as notas:  ");
                    scanf("%d", &num);

                    posicao = buscaAluno(alunos, num, n);

                    if(posicao == -1)
                        printf("RGA não encontrado!! \n");
                    else{
                        printf("Informe o valor da primeira nota:  ");
                        scanf("%f", &alunos[posicao].n1);

                        printf("Informe o valor da segunda nota:  ");
                        scanf("%f", &alunos[posicao].n2);

                        printf("Informe o valor da terceira nota:  ");
                        scanf("%f", &alunos[posicao].n3);


                        printf("\nNOTAS ATUALIZADAS COM SUCESSO!! \n\n");
                    }

                    printf("Informe um numero para poder continuar: (1 sim ou 0 nao)\n ");
                    scanf("%d", &resp);
                    
                    if(resp == 0)
                        flag = 0;
                break;
                
                case 4:
                    mostrandoValores(alunos, n);

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

void cadastroAluno(regaluno alunos[], int n){
    
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
                    
    printf("\nCADASTRADO COM SUCESSO!! \n\n");
}




void mostrandoValores(regaluno alunos[], int n){

    int i;

    for(i = 0; i < n; i++){
        printf("Nome: %s \n", alunos[i].nome);
        printf("RGA:  %d \n", alunos[i].rga);
        printf("Nota 1:  %.2f \n", alunos[i].n1);
        printf("Nota 2:  %.2f \n", alunos[i].n2);
        printf("Nota 3:  %.2f \n", alunos[i].n3);
        alunos[i].ma = (alunos[i].n1 + alunos[i].n2 + alunos[i].n3) / 3;
        printf("Media do Aluno:  %.2f \n", alunos[i].ma);
    }
}



int buscaAluno(regaluno alunos[], int num, int n){

    int i, posicao;

    i = 0;
    while(i < n){
        if(alunos[i].rga == num){
            posicao = i;
            i = i + n;
        }
        else{
            posicao = -1;
        }
        i = i + 1;
    }


    return posicao;
}
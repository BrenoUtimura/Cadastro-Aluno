#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Struct com as informações */
typedef struct{
    char nome[50], resultado[10];
    int rga;
    float n1, n2, n3, ma, mf;
}regaluno;

/* Declaração de funções utilizadas */
int cadastroAluno(regaluno alunos[], int n);
void mostrandoValores(regaluno alunos[], int n);
int buscaAluno(regaluno alunos[], int num, int n);

/* Função principal */
int main(void){
    
    regaluno alunos[50];
    int n, i, flag, num, resp, posicao, qtd_aluno;

    qtd_aluno = 0;
    flag = 1;
    
    while(flag == 1){
        printf("O que vc deseja fazer agora? \n ");
        printf("------------------------\n");
        printf("1 - Cadastrar um novo Aluno \n"); 
        printf("2 - Remover Aluno \n"); 
        printf("3 - Atualizar as notas dos Alunos \n"); 
        printf("4 - Exibir Alunos cadastrados em ordem por nome \n"); 
        printf("5 - Exibir as medias dos Alunos em ordem alfabética \n"); 
        printf("6 - Sair \n");
        printf("------------------------\n");
        
        printf("Informe um numero para poder continuar: \n ");
        scanf("%d", &resp);
        

		switch(resp){

			/* Cadastrar alunos */
			case 1:
				printf("Quantos Alunos vc ira cadastrar?  ");
				scanf("%d", &n);

				if(qtd_aluno + n < 50){
					for(i = 0; i < n; i++){
						posicao = cadastroAluno(alunos, i);
					}
					qtd_aluno = qtd_aluno + n;
				}
				else
					printf("Limite máximo para cadastro atingido!!\n\n");

				printf("Informe um numero para poder continuar: (1 sim ou 0 nao)\n ");
				scanf("%d", &resp);
				
				if(resp == 0)
					flag = 0;
			break;
			
			/* Remover Alunos */
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
					qtd_aluno = qtd_aluno - 1;

					printf("\nALUNO REMOVIDO COM SUCESSO!! \n\n");
				} 

				printf("Informe um numero para poder continuar: (1 sim ou 0 nao)\n ");
				scanf("%d", &resp);
				
				if(resp == 0)
					flag = 0;
			break;
			
			/* Atualizar notas do aluno */
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
			
			/* Exibi os Alunos cadastrados */
			case 4:
				mostrandoValores(alunos, n);

				printf("Informe um numero para poder continuar: (1 sim ou 0 nao)\n ");
				scanf("%d", &resp);
				
				if(resp == 0)
					flag = 0;
			break;
			
			/* Exibir as medias dos Alunos em ordem alfabética */
			case 5:
				
			break;
			
			/* Sair da aplicação */
			case 6:
				printf("Muito Obrigado!  Volte sempre!\n");
				flag = 0;
			break;

			/* Para se caso o usuário digitar um número inválido */
			default:
				printf("Informe um número válido!!\n");
			break;
		}
            
    }
 
	return 0;
}


/* Funções do sistema */

/* Função de cadastrar o aluno */
int cadastroAluno(regaluno alunos[], int n){
    
    int rga, posicao;

    /* Chamando a função de busca para verificar se tem alunos cadastrados em tal posição */
	printf("Informe o RGA que deseja pesquisar: \n");
	scanf("%d", &rga);

	posicao = buscaAluno(alunos, rga, n);

	/* Verifica se o RGA já existe no meu vetor */
	while(posicao != -1){
		printf("Este RGA já existe!\n");

		printf("Informe outro RGA!\n");
		
		printf("Informe o RGA que deseja pesquisar: \n");
		scanf("%d", &rga);

		posicao = buscaAluno(alunos, rga, n);
	}


	
	/* Cadastrando o aluno e suas informações */
    printf("Digite o nome do Aluno:  ");
    scanf(" %[^\n]", alunos[n].nome);
                        
    alunos[n].rga = rga;
                        
    printf("Informe a primeira nota:  ");
    scanf("%f", &alunos[n].n1);
                        
    printf("Informe a segunda nota:  ");
    scanf("%f", &alunos[n].n2);
                    
    printf("Informe a terceira nota:  ");
    scanf("%f", &alunos[n].n3);
	
                    
    printf("\nCADASTRADO COM SUCESSO!! \n\n");
}


/* Função que mostra as informações do aluno */
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

        if(alunos[i].ma < 6)
            printf("\nREPROVADO!!\n\n");
            /*alunos[i].resultado = "Reprovado";*/
        else
            printf("\nAPROVADO!!\n\n");
    }
}


/*  Função sem recursão de busca de alunos 
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
*/


/* Função recursiva de busca de alunos */
int buscaAluno(regaluno alunos[], int num, int n){
	
	if(n == 0){
		return -1;
	}
	else{
		if(alunos[n - 1].rga == num){
			return n - 1;
		}
		else
			return buscaAluno(alunos, num, n - 1);
	}
}


/* Media Geral em função recursiva */
int mediaGeral(regaluno alunos[], int n){

    if(n == 0)
        return 0;
    else
        return alunos[n - 1].ma + mediaGeral(alunos, n - 1);
}
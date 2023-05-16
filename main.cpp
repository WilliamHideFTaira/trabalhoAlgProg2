#include <stdio.h>
#include "funcoes.cpp"
#define MAX 40
#define MAXPS 16
//============================================================DECLARAÇÃO FUNÇÕES================================================
void imprimeUPALogin();
void preencheVetor(tipoRecepcionista v[], int &i);

//=================================================================STRUCTS======================================================
struct tipoData
{
	int dia;
	int mes;
	int ano;
};

struct tipoFuncionario
{
	char nome[MAX];
	int CPF;
	char senha[MAXPS];
};

/*
struct tipoRecepcionista
{
	String nome[MAX];
	int CPF;
	String senha[MAXPS];
};

struct tipoEnfermeiro
{
	String nome[MAX];
	int CPF;
	String senha[MAXPS];
};

struct tipoMedico
{
	String nome[MAX];
	int CPF;
	String senha[MAXPS];
};
*/
struct tipoPaciente
{
	String nome[MAX];
	int CPF;
	tipoData nasc;
};

//============================================================================MAIN=====================================================================================
int main()
{
	int op;
	tipoFuncionario recepcionista[];
	tipoFuncionario enfermeiro[];
	tipoFuncionario medico[];
	tipoPaciente paciente[];
	FILE *ptRecepcionista, *ptEnfermeiro, *ptMedico;
	ptRecepcionista = fopen("recepcionistas.txt", "r");
	ptEnfermeiro = fopen("enfermeiros.txt", "r");
	ptMedico = fopen("medicos.txt", "r");
	preencheVetor(recepcionista, ptRecepcionista);
	preencheVetor(enfermeiro, ptEnfermeiro);
	preencheVetor(medico, ptMedico);
	
	do
	{
		imprimeUPALogin();
		printf("\n1 - Recepcionista\n2 - Enfermeiro(a)\n3 - Médico(a)\n0 - Encerrar Programa\n")
		scanf("%d", &op);
		if (op == 1)
		{
			do
			{
				imprimeUPALogin();
				printf("\n             1- Recepcionista");
				printf("\nCPF (apenas números): ");
				scanf("%[^\n]", recepcionista.nome);
				printf("\nSenha: ");
				if (verifica)
				{
					menuRecepcionista();
				}
				else
				{
					printf("Senha incorreta. Tente novamente, ou digite 0 para voltar\n");
					scanf(" %s", senha);
				}
			}while (senha != 0) //?????????????

		}
		else if (op == 2)
		{
			
		}
	}while (op != 0);
	return 0;
}
//===================================FUNCOES=================================

void imprimeUPALogin()
{
	printf("               UPA - Login\n");
	printf("               Enfermeiro")
}

void preencheVetor(tipoRecepcionista v[], int &i)
{

}
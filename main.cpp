#include <stdio.h>
#include <string.h>
//#include "funcoes.cpp"
#define MAX 40
#define MAXPS 12
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

struct tipoPaciente
{
	char nome[MAX];
	int CPF;
	tipoData nasc;
};

//============================================================DECLARAÇÃO FUNÇÕES================================================
void imprimeUPALogin();
void preencheVetor(tipoFuncionario v[], int *p, int q);
void preencheVetorP(tipoPaciente v[], int *p, int q);
void imprimetxtFunc(int a);
bool verificaCredenciais(char c[], char n[], int cpf, tipoPessoa v[], int X);
void menuRecepcionista();
void menuEnfermeiro();
void menuMedico();


//============================================================================MAIN=====================================================================================
int main()
{
	int op;
	int quantR, quantE, quantM, quantP;

	FILE *ptRecepcionista, *ptEnfermeiro, *ptMedico, *ptPaciente;

	//=========INICIALIZANDO VETORES COM SEUS TAMANHOS==============

	ptRecepcionista = fopen("recepcionistas.txt", "r");
	if (ptRecepcionista == NULL)
	{
		printf("Erro na leitura do arquivo recepcionistas.txt\n");
	}
	else
	{
		fscanf(ptRecepcionista, "%d", &quantR);
		tipoFuncionario recepcionista[quantR];
		preencheVetor(recepcionista, ptRecepcionista, quantR);
		fclose(ptRecepcionista);
	}
	
	//=========INICIALIZANDO VETORES COM SEUS TAMANHOS==============

	ptEnfermeiro = fopen("enfermeiros.txt", "r");
	if (ptEnfermeiro == NULL)
	{
		printf("Erro na leitura do arquivo enfermeiros.txt\n");
	}
	else
	{
		fscanf(ptRecepcionista, "%d", &quantE);
		tipoFuncionario enfermeiro[quantE];
		preencheVetor(enfermeiro, ptEnfermeiro, quantE);
		fclose(ptRecepcionista);
	}

	//=========INICIALIZANDO VETORES COM SEUS TAMANHOS==============

	ptMedico = fopen("medicos.txt", "r");
	if (ptMedico == NULL)
	{
		printf("Erro na leitura do arquivo medicos.txt\n");
	}
	else
	{
		fscanf(ptMedico, "%d", &quantM);
		tipoFuncionario medico[quantM];
		preencheVetor(medico, ptMedico, quantM);
		fclose(ptMedico);
	}
	
	//=========INICIALIZANDO VETOR PACIENTE COM SEU TAMANHO========== (PASSIVEL DE MUDANÇA)
	
	ptPaciente = fopen("pacientes.txt", "r");
	if (ptPaciente == NULL)
	{
		printf("Erro na leitura do arquivo pacientes.txt\n");
	}
	else
	{
		fscanf(ptPaciente, "%d", &quantP);
		tipoPaciente paciente[quantP];
		preencheVetorP(paciente, ptPaciente, quantP);
		fclose(ptPaciente);
	}
	//===============================MENU===========================
	do
	{
		/*char senha[MAXPS];
		int CPF;*/
		printf("\n====================== MENU - UPA ==================");
		printf("\n1 - Recepcionista\n2 - Enfermeiro(a)\n3 - Médico(a)\n0 - Encerrar Programa\n");
		scanf("%d", &op);
		do
		{
			int c;
			imprimeUPALogin();
			imprimetxtFunc(op);
			printf("\nCPF (apenas números): ");
			scanf("%d", &CPF);
			printf("\nSenha: ");
			printf(" %s", senha);
			if (op == 1)
			{
				if (verificaCredenciais(senha, CPF, recepcionista, quantR))
				{
					menuRecepcionista();
					c = 0;
				}
				else
				{
					printf("Senha incorreta. Digite 0 para voltar ou 1 para tentar novamente\n\n");
					scanf("%d", &c);
				}
			}

			else if (op == 2)
			{
				if (verificaCredenciais(senha, CPF, enfermeiro, quantE))
				{
					menuEnfermeiro();
					c = 0;
				}
				else
				{
					printf("Senha incorreta. Digite 0 para voltar ou 1 para tentar novamente\n\n");
					scanf("%d", &c);
				}
			}

			else if (op == 3)
			{
				if (verificaCredenciais(senha, CPF, medico, quantM))
				{
					menuMedico();
					c = 0;
				}
				else
				{
					printf("Senha incorreta. Digite 0 para voltar ou 1 para tentar novamente\n\n");
					scanf("%d", &c);
				}
			}
		}while (c!=0);
		/*
		if (op == 1)
		{
			do
			{
				char senha[MAXPS];
				int CPF;
				int c;
				imprimeUPALogin();
				printf("\n             1- Recepcionista");
				printf("\nCPF (apenas números): ");
				scanf("%d", &CPF);
				printf("\nSenha: ");
				printf(" %s", senha);
				if (verificaCredenciais(senha, CPF, recepcionista, quantR))
				{
					menuRecepcionista();
					c = 0;
				}
				else
				{
					printf("Senha incorreta. Digite 0 para voltar ou 1 para tentar novamente\n\n");
					scanf("%d", &c);
				}
			}while (c != 0);
		}
		else if (op == 2)
		{
			do
			{
				char senha[MAXPS];
				int CPF;
				int c;
				imprimeUPALogin();
				printf("\n             2- Enfermeiro");
				printf("\nCPF (apenas números): ");
				scanf("%d", &CPF);
				printf("\nSenha: ");
				printf(" %s", senha);
				if (verificaCredenciais(senha, CPF, enfermeiro, quantE))
				{
					menuEnfermeiro();
					c = 0;
				}
				else
				{
					printf("Senha incorreta. Digite 0 para voltar ou 1 para tentar novamente\n\n");
					scanf("%d", &c);
				}
			}while (c != 0);
		}
		else if (op == 3)
		{
			do
			{
				char senha[MAXPS];
				int CPF;
				int c;
				imprimeUPALogin();
				printf("\n             1- Recepcionista");
				printf("\nCPF (apenas números): ");
				scanf("%d", &CPF);
				printf("\nSenha: ");
				printf(" %s", senha);
				if (verificaCredenciais(senha, CPF, recepcionista, quantR))
				{
					menuRecepcionista();
					c = 0;
				}
				else
				{
					printf("Senha incorreta. Digite 0 para voltar ou 1 para tentar novamente\n\n");
					scanf("%d", &c);
				}
			}while (c != 0);
		}*/
	}while (op != 0);
	return 0;
}
//===================================FUNCOES=================================

void imprimeUPALogin()
{
	printf("               UPA - Login\n");
}

void preencheVetor(tipoFuncionario v[], int *p, int q)
{
	for (int i = 0; i < q; i++)
	{
		fscanf(p, " %[^\n]", v[i].nome);
		fscanf(p, "%d", &v[i].CPF);
		fscanf(p, " %s", v[i].senha);
	}
}

void preencheVetorP(tipoPaciente v[], int *p, int q)
{
	for (int i = 0; i < q; i++)
	{
		fscanf(p, " %[^\n]", v[i].nome);
		fscanf(p, "%d/%d/%d", &v[i].nasc.dia, &v[i].nasc.mes, &v[i].nasc.ano);
		fscanf(p, "%d", &v[i].CPF);
	}
}

void imprimetxtFunc(int a)
{
	if (a == 1)
		printf("\n             1- Recepcionista");
	else if (a == 2)
	{
		printf("\n              2- Enfermeiro");
	}
	else if (a == 3)
	{
		printf("\n               3- Médico");
	}
}

bool verificaCredenciais(char c[], int cpf, tipoPessoa v[], int X)
{
	int tam;
    char cSenha[strlen(c) + 1];
    tam = strlen(c);
    strcpy(cSenha, c);
    for (int i = 0; i < tam; i++) 
    {
        if (c[i] >= 'A' && c[i] <= 'Z') 
        {
            cSenha[i] = (char) ((int) c[i] + 3);
        } 
        else if (c[i] >= 'a' && c[i] <= 'z') 
        {
            cSenha[i] = (char) ((int) c[i] + 3);
        }
    } 
    /*int i = 0, j = tam - 1;
    while (i < j)
    {
        char aux = cSenha[i];
        cSenha[i] = cSenha[j];
        cSenha[j] = aux;
        i++;
        j--;
    }*/
    int j = tam - 1;
    for (int i = 0; i < j; i++)
    {
    	char aux = cSenha[i];
        cSenha[i] = cSenha[j];
        cSenha[j] = aux;
        j--;
    }

    for (int i = 0; i < X; i++)
    {
    	if(v[i].CPF == cpf)
       	{
        	if (strcmp(v[i].senha, cSenha) == 0)
            	return true;
            else
            	i = X;
        }
    }
    return false;
}
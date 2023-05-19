#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "funcoes.cpp"
#define MAX 27
#define MAXPS 12
#define tamCPF 11
//=================================================================STRUCTS======================================================
struct tipoData
{
	int dia;
	int mes;
	int ano;
};

struct tipoFuncionario
{
	char nome[MAX+1];
	char CPF[tamCPF+1];
	char senha[MAXPS];
};

struct tipoPaciente
{
	char nome[MAX];
	char CPF[tamCPF+1];
	tipoData nasc;
};

//============================================================DECLARAÇÃO FUNÇÕES================================================
void imprimeUPALogin();
void preencheVetor(tipoFuncionario v[], FILE *p, int q);
void preencheVetorP(tipoPaciente v[], FILE *p, int q);
void imprimetxtFunc(int a);
bool verificaCredenciais(char c[], char cpf[], tipoFuncionario v[], int X);
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

	tipoFuncionario *recepcionista = NULL;
	ptRecepcionista = fopen("recepcionistas.txt", "r");
	if (ptRecepcionista == NULL)
	{
		printf("Erro na leitura do arquivo recepcionistas.txt\n");
	}
	else
	{
		fscanf(ptRecepcionista, "%d", &quantR);
		recepcionista = (tipoFuncionario*)malloc(quantR * sizeof(tipoFuncionario));
		preencheVetor(recepcionista, ptRecepcionista, quantR);
		fclose(ptRecepcionista);
	}
	
	//=========INICIALIZANDO VETORES COM SEUS TAMANHOS==============

	tipoFuncionario *enfermeiro = NULL;
	ptEnfermeiro = fopen("enfermeiros.txt", "r");
	if (ptEnfermeiro == NULL)
	{
		printf("Erro na leitura do arquivo enfermeiros.txt\n");
	}
	else
	{
		fscanf(ptRecepcionista, "%d", &quantE);
		enfermeiro = (tipoFuncionario*)malloc(quantE * sizeof(tipoFuncionario));
		preencheVetor(enfermeiro, ptEnfermeiro, quantE);
		fclose(ptRecepcionista);
	}

	//=========INICIALIZANDO VETORES COM SEUS TAMANHOS==============

	tipoFuncionario *medico = NULL;
	ptMedico = fopen("medicos.txt", "r");
	if (ptMedico == NULL)
	{
		printf("Erro na leitura do arquivo medicos.txt\n");
	}
	else
	{
		fscanf(ptMedico, "%d", &quantM);
		medico = (tipoFuncionario*)malloc(quantM * sizeof(tipoFuncionario));
		preencheVetor(medico, ptMedico, quantM);
		fclose(ptMedico);
	}
	
	//=========INICIALIZANDO VETOR PACIENTE COM SEU TAMANHO========== (PASSIVEL DE MUDANÇA)
	tipoPaciente *paciente = NULL;
	ptPaciente = fopen("pacientes.txt", "r");
	if (ptPaciente == NULL)
	{
		printf("Erro na leitura do arquivo pacientes.txt\n");
	}
	else
	{
		fscanf(ptPaciente, "%d", &quantP);
		paciente = (tipoPaciente*)malloc(quantP * sizeof(tipoPaciente));
		preencheVetorP(paciente, ptPaciente, quantP);
		fclose(ptPaciente);
	}
	//===============================MENU===========================
	do
	{
		char senha[MAXPS];
		char CPF[tamCPF+1];
		int c;
		printf("\n============================================ MENU - UPA ============================================\n");
		printf("\n1 - Recepcionista\n2 - Enfermeiro(a)\n3 - Medico(a)\n0 - Encerrar Programa\n");
		scanf("%d", &op);
		if (op == 0) // PARA FINALIZAR O PROGRAMA, PASSÍVEL DE MUDANÇA
			return 0; 
		do
		{
			imprimeUPALogin();
			imprimetxtFunc(op);
			printf("\nCPF (apenas numeros): ");
			scanf(" %s", CPF);
			printf("\nSenha: ");
			scanf(" %s", senha);
			if (op == 1)
			{
				if (verificaCredenciais(senha, CPF, recepcionista, quantR) == true)
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
				if (verificaCredenciais(senha, CPF, enfermeiro, quantE) == true)
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
				if (verificaCredenciais(senha, CPF, medico, quantM) == true)
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
		}while (c != 0);
	}while (op != 0);
	free(recepcionista);
	free(enfermeiro);
	free(medico);
	free(paciente);
	return 0;
}
//===================================FUNCOES=================================

void imprimeUPALogin()
{
	printf("               UPA - Login\n");
}

void preencheVetor(tipoFuncionario v[], FILE *p, int q)
{
	for (int i = 0; i < q; i++)
	{
		fscanf(p, " %27[^\n]", v[i].nome);
		fscanf(p, " %11s", v[i].CPF);
		fscanf(p, " %s", v[i].senha);
	}
}

void preencheVetorP(tipoPaciente v[], FILE *p, int q)
{
	for (int i = 0; i < q; i++)
	{
		fscanf(p, " %27[^\n]", v[i].nome);
		fscanf(p, "%d/%d/%d", &v[i].nasc.dia, &v[i].nasc.mes, &v[i].nasc.ano);
		fscanf(p, " %s", v[i].CPF);
	}
}

void imprimetxtFunc(int a)
{
	if (a == 1)
		printf("             1- Recepcionista\n");
	else if (a == 2)
	{
		printf("              2- Enfermeiro\n");
	}
	else if (a == 3)
	{
		printf("               3- Médico\n");
	}
}

bool verificaCredenciais(char c[], char cpf[], tipoFuncionario v[], int X)
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
    int j = tam - 1;
    for (int i = 0; i < j; i++)
    {
    	char aux = cSenha[i];
        cSenha[i] = cSenha[j];
        cSenha[j] = aux;
        j--;
    }
    printf("%s\n\n", cSenha);
    for (int i = 0; i < X; i++)
    {
    	if (strcmp(v[i].CPF, cpf) == 0 && strcmp(v[i].senha, cSenha) == 0)
    		return true;
    }
    return false;
}

void menuRecepcionista()
{
	printf("AQUI SERA MENU DO RECEPCIONISTA");
}
void menuEnfermeiro()
{
	printf("AQUI SERA MENU ENFERMEIRO");
}
void menuMedico()
{
	printf("AQUI SERA MENU MEDICO");
}
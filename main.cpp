#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "corpoFunc.h"
#define MAX 40
#define MAXPS 11
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
	char senha[MAXPS+1]; // 11 + '\0'
};

struct tipoPaciente
{
	char nome[MAX];
	char CPF[tamCPF+1];
	float peso;
	float altura;
	char sexo;
	char sintomas[100];
	int gravidade;
	tipoData nasc;
	struct tipoPaciente *prox;
};

//============================================================DECLARAÇÃO FUNÇÕES================================================
void imprimeUPALogin();
void preencheVetor(tipoFuncionario v[], FILE *p, int q);
void cadastraPaciente(tipoPaciente *&i, tipoPaciente *&f, char n[], char cpf[], tipoData d);
void imprimetxtFunc(int a);
bool verificaCredenciais(char c[], char cpf[], tipoFuncionario v[], int X);
void menuRecepcionista();
void menuEnfermeiro();
void menuMedico();
int removePaciente(char cpf[], tipoPaciente *&i, tipoPaciente *&f);
void inspilhaRemovidos(tipoPaciente x, tipoPaciente *&lst);
int buscaPaciente(char cpf[], tipoPaciente *i, tipoPaciente *AT1, tipoPaciente *AT2, tipoPaciente *AT3);
void imprimeSituacao(int N);
int calculaIdade(tipoPaciente *P)
void imprimeGravidade(int gravidade);
int alteraGravidade(int ng, tipoPaciente v[]);
void imprimePObservacao(tipoPaciente v[], int q);
int removePObservacao(char cpf[], tipoPaciente v[], int q);

//============================================================================MAIN=====================================================================================
int main()
{
	int op;
	int quantR, quantE, quantM, quantPO, quantPT; // VERIFICAR VARIAVEIS

	FILE *ptRecepcionista, *ptEnfermeiro, *ptMedico, *ptTriagem, *ptObs;
	
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
	
	//=========INICIALIZANDO VETOR PACIENTES TRIAGEM COM SEU TAMANHO==========
	tipoPaciente *filaTriagemI = NULL, *filaTriagemF = NULL;
	ptTriagem = fopen("pacientes.txt", "r");
	if (ptTriagem == NULL)
	{
		printf("Erro na leitura do arquivo pacientes.txt\n");
	}
	else
	{
		fscanf(ptTriagem, "%d", &quantPT);
		for (int i = 0; i < quantPT; i++)
		{
			char nomeP[28];
			char cpfP[tamCPF];
			tipoData nascP;
			fscanf(p, " %27[^\n]", nomeP);
			fscanf(p, "%d/%d/%d", &nascP.dia, &nascP.mes, &nascP.ano);
			fscanf(p, " %s", cpfP);
			cadastraPaciente(filaTriagemI, filaTriagemF, nomeP, cpfP, nascP);
		}
		fclose(ptTriagem);
	}

	//=========INICIALIZANDO VETOR PACIENTES OBSERVACAO COM SEU TAMANHO========== (NECESSÁRIAS ALTERAÇÕES)
	tipoPaciente *pacienteObs = NULL;
	ptObs = fopen("observacao.txt", "r");
	if (ptObs == NULL)
	{
		printf("Erro na leitura do arquivo observacao.txt\n");
	}
	else
	{
		fscanf(ptObs, "%d", &quantPO);
		pacienteObs = (tipoFuncionario*)malloc(quantM * sizeof(tipoFuncionario));
		preencheVetor(medico, ptObs, quantM);
		fclose(ptObs);
	}
	
	//==============================================================MENU==============================================================
	//==============================================================MENU==============================================================
	//==============================================================MENU==============================================================
	//==============================================================MENU==============================================================
	//==============================================================MENU==============================================================
	do
	{
		char senha[MAXPS];
		char CPF[tamCPF+1];
		int c;
		printf("\n=============================== MENU - UPA ===============================\n");
		printf("\n1 - Recepcionista\n2 - Enfermeiro(a)\n3 - Medico(a)\n0 - Encerrar Programa\n");
		scanf("%d", &op);
		if (op != 0)
		{
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
		}
	}while (op != 0);

	// CRIAR FUNÇÃO PARA GUARDAR PACIENTES NAO ATENDIDOS OU AGUARDANDO ATENDIMENTO EM ARQUIVO "naoAtendidos.txt"
	// CRIAR FUNÇÃO PARA GUARDAR PACIENTES EM OBSERVAÇÃO EM ARQUIVO "observacao.txt"
	free(recepcionista);
	free(enfermeiro);
	free(medico);
	free(paciente);
	return 0;
}

//===================================================FUNCOES=================================================================
//===================================================FUNCOES=================================================================
//===================================================FUNCOES=================================================================
//===================================================FUNCOES=================================================================

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

void cadastraPaciente(tipoPaciente *&i, tipoPaciente *&f, char n[], char cpf[], tipoData d)
{
	tipoPaciente *novo;
	novo = (tipoPaciente *) malloc(sizeof(tipoPaciente));
	strcpy(novo->nome, n);
	novo->nasc = d;
	strcpy(novo->CPF, cpf);
	novo->prox = NULL;
	if(i == NULL)
 		i = f = nova;
 	else
 	{
 		f->prox = nova;
 		f = nova;
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
		printf("                3- Medico\n");
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
    for (int i = 0; i < X; i++)
    {
    	if (strcmp(v[i].CPF, cpf) == 0 && strcmp(v[i].senha, cSenha) == 0)
    		return true;
    }
    return false;
}
//=====================================================================================================================
void menuRecepcionista()
{
	int op1;
	char nomePac[MAX];
	char CPF[tamCPF+1];
	tipoData D;
	do
	{
		printf("\n/////////////////////////// MENU RECEPCIONISTA ///////////////////////////\n");
		printf("\n1 - Cadastrar Paciente\n2 - Remover Paciente\n3 - Buscar Paciente\n0 - Logout -> Menu Principal\n");
		scanf("%d", &op1);
		if(op1 == 1)
		{
			printf("\n              Cadastrar Paciente\n");
			printf("\nCPF: ");
			scanf(" %s", cpfP);
			printf("\nNome: ");
			scanf(" %27[^\n]", nomePac);
			printf("\nData Nascimento (DD/MM/AAAA): ");
			scanf("%d/%d/%d", &nascP.dia, &nascP.mes, &nascP.ano);
			cadastraPaciente(filaTI, filaTF, nomePac, cpfP, D);
			printf("\nPaciente Registrado\n");
		}
		else if(op1 == 2)
		{
			printf("\n               Remover Paciente\n");
			printf("CPF: "); // char
			scanf(" %s", cpfP);
			tipoPaciente *removido = removePaciente(cpfP, filaTI, filaTF)
			if(removido != NULL)
			{
				inspilhaRemovidos(removido, removidos);
				printf("\nPaciente removido com sucesso.\n");
			}
			else
			{
				printf("\nPaciente não encontrado");
			}
		}
		else if(op1 == 3)
		{
			printf("\n               Buscar Paciente\n");
			printf("CPF: ");
			scanf(" %s", cpfP);
			int y = buscaPaciente(cpfP, filaTI, filaAt1, filaAt2, filaAt3);
			if (y == 0)
				printf("\n\nPaciente não encontrado\n");
			else
			{
				printf("\n\nPaciente encontrado em ");
				imprimeSituacao(y);
				printf("\n");
			}
		}
	}while (op1 != 0);
	printf("                          Logout -> Menu Principal\n");
}
tipoPaciente* removePaciente(char cpf[], tipoPaciente *&i, tipoPaciente *&f)
{
	tipoPaciente *p, *q;
	tipoPaciente aux;
	p = NULL;
	q = i;
	while (q != NULL && q->CPF != cpf)
	{
		p = q;
		q = q->prox;
	}
	if (q == NULL)
		return q;
	else
	{
		if (p == NULL)
		{
			if(i == f)
				i == f == i->prox;
			else
				i = i->prox;
		}
		else if (q->prox == NULL)
		{
			f = p;
			p->prox = NULL;
		}
		else
			p->prox = q->prox;
		aux = *q;
		free(q);
		return aux;
	}
}

void inspilhaRemovidos(tipoPaciente x, tipoPaciente *&lst)
{
	tipoPaciente *novo;
 	novo = (tipoPaciente *) malloc(sizeof (tipoPaciente));
 	novo = x;
 	novo->prox = lst;
 	lst = novo;
}

int buscaPaciente(char cpf[], tipoPaciente *i, tipoPaciente *AT1, tipoPaciente *AT2, tipoPaciente *AT3)
{
	tipoPaciente *aux;
	aux = i;
	while (aux != NULL && aux->CPF != cpf)
		aux = aux->prox;
	if (aux != NULL)
		return 1;
	aux = AT1;
	while (aux != NULL && aux->CPF != cpf)
		aux = aux->prox;
	if (aux != NULL)
		return 2;
	aux = AT2;
	while (aux != NULL && aux->CPF != cpf)
		aux = aux->prox;
	if (aux != NULL)
		return 3;
	aux = AT3;
	while (aux != NULL && aux->CPF != cpf)
		aux = aux->prox;
	if (aux != NULL)
		return 4;
	return 0;
}

void imprimeSituacao(int N)
{
	if (N == 1)
		printf("fila da triagem\n");
	else if (N == 2)
		printf("fila de espera para chamada medica (Emergente)\n");
	else if (N == 3)
		printf("fila de espera para chamada medica (Urgente)\n");
	else if (N == 4)
		printf("fila de espera para chamada medica (Nao Urgente)\n");
}
//=====================================================================================================================
void menuEnfermeiro(tipoPaciente *&filaTI, tipoPaciente *&filaTF, tipoPaciente *&filaAt1, tipoPaciente *&filaAt2, tipoPaciente *&filaAt3)
{
	int op2;
	char cpf[tamCPF+1];
	do
	{
		printf("\n///////////////////////////// MENU ENFERMEIRO ////////////////////////////\n");
		printf("\n1 - Chamar Paciente Triagem\n2 - Visualizar Prontuario\n0 - Logout -> Menu Principal\n");
		scanf("%d", &op2);
		if(op2 == 1)
		{
			if (filaTI != NULL)
			{
				printf("           Chamar Paciente Triagem\n");
				printf("%s   ", filaTI->nome);
				printf("%d   ", calculaIdade(filaTI));
				printf("%s   ", filaTI->CPF);
				printf("\nPeso: ");
				scanf("%f", &filaTI->peso);
				printf("\nAltura: ");
				scanf("%f", &filaTI->altura);
				do
				{
					printf("Sexo (F/M):  \n");
					scanf("%c", filaTI->sexo);
				}while (filaTI->sexo != 'M' || filaTI->sexo != 'F');

				printf("\nSintomas: ");
				scanf(" %[^\n]", filaTI->sintomas);
				printf("\n1 - Emergente    2 - Urgente    3 - Nao Urgente\n");
				scanf("%d", &filaTI->gravidade);
				if(filaTI->gravidade == 1)
					filaAtend(filaTI, filaTF, filaAt1);
				else if(filaTI->gravidade == 2)
					filaAtend(filaTI, filaTF, filaAt2);
				else if(filaTI->gravidade == 3)
					filaAtend(filaTI, filaTF, filaAt3);
			}
			else
				printf("Não há pacientes na fila\n");
		}
		else if(op2 == 2)
		{
			int op2a;
			tipoPaciente *aux;
			do
			{
				printf("Digite CPF do paciente ou 0 para voltar para o Menu Enfermeiro\n");
				scanf(" %s", cpf);
				if (strcmp(cpf, "0") != 0)
				{
					aux = buscaPacienteEsp(cpf, filaAt1, filaAt2, filaAt3);
					char primeiroNome[MAX];
					strcpy(primeiroNome, strtok(aux->nome, " "));
					do
					{
						printf("\n\n               Visualizar Prontuario\n\n");
						printf("%s   ", aux->nome);
						printf("%d   ", calculaIdade(aux->nasc));
						printf("%s\n", aux->CPF);
						printf("%.2f   ", aux->peso);
						printf("%.2f   ", aux->altura);
						printf("%c\n", aux->sexo);

						printf("Sintomas: \n");
						printf("%s   ", aux->sintomas);
						imprimeGravidade(aux->gravidade);
						printf("\n1 - Alterar Gravidade\n2 - Alterar Sintomas\n0 - Voltar\n");
						scanf("%d", &op2a);
						if (op2a == 1)
						{
							int novaGravidade;
							printf("\n\n            1 - Alterar Gravidade");
							printf("\n\n   1- Emergente  2 - Urgente  3 - Nao Urgente\n");
							printf("Digite a nova Gravidade do(a) %s", primeiroNome);
							scanf("%d", &novaGravidade);
							if (aux)
						}
						else if(op2a == 2)
						{
							char novoSintoma[100];
							printf("\n\n            2 - Alterar Sintoma\n");
							//printf("\nDigite o(s) novo(s) sintoma(s) de %s", pacienteTriagem[ind].nome);
							printf("Digite o(s) novo(s) sintoma(s)"); // PRINT DE TESTE, equivale a linha 388
							scanf(" %[^\n]", novoSintoma);
							/*if (alteraSintoma(novoSintoma, pacienteTriagem[ind].sintoma) == 1)
								printf("\nSintomas Alterados com sucesso!\n");
							else
								printf("\nErro na alteração!\n");*/}
					}while (op2a != 0);
				}
			}while (strcmp(cpf, "0") != 0);	
		}
	}while (op2 != 0);
	printf("                          Logout -> Menu Principal\n");
}

int calculaIdade(tipoPaciente *P) // FUNÇÃO NÃO ATUALIZA O TEMPO DE FORMA AUTOMÁTICA. NECESSÁRIA ALTERAÇÃO
{
	int idade = 2023 - P->nasc.ano; // EM CASO DE REUSO DO PROGRAMA, NECESSÁRIA MUDANÇA

    // Verificar se a data de nascimento ainda não ocorreu no ano atual
    if (6 < P->nasc.mes || (6 == P->nasc.mes && 4 < P->nasc.dia))
    	idade--;

    return idade;
}

void filaAtend(tipoPaciente *&i, tipoPaciente *&f, tipoPaciente *&lsti, tipoPaciente *&lstf)
{
	tipoPaciente *aux;
	aux = i;
	if (i->prox == NULL)
		i = f = i->prox;
	else
		i = i->prox;
	aux->prox = lsti;
	lsti = aux;
	if (lstf == NULL)
		lstf = lsti;
}

tipoPaciente* buscaPacienteEsp(char cpf[], tipoPaciente *lst1, tipoPaciente *lst2, tipoPaciente *lst3)
{
	tipoPaciente *q;
	q = lst1;
	while (q != NULL && q->CPF != cpf)
		q = q->prox;
	if (q != NULL)
		return q;
	q = lst2;
	while (q != NULL && q->CPF != cpf)
		q = q->prox;
	if (q != NULL)
		return q;
	q = lst3;
	while (q != NULL && q->CPF != cpf)
		q = q->prox;
	if (q != NULL)
		return q;
	return q;
}

void imprimeGravidade(int gravidade)
{
	if (gravidade == 1)
		printf("1 - Emergente\n");
	else if (gravidade == 2)
		printf("2 - Urgente\n");
	else if (gravidade == 3)
		printf("3 - Nao Urgente\n");
	else
		printf("Gravidade nao cadastrada!\n");
}
int alteraGravidade(int ng, int g) //FUNÇÃO PARA ALTERAR GRAVIDADE - PREENCHER POSTERIORMENTE
{
	/*if (ERRO)
		return 0;*/
	return 1;
}
int alteraSintoma(char ns[], char s[])
{
	/*if (ERRO)
		return 0;*/
	return 1;
}
void menuMedico()
{
	int op3;
	do
	{
		printf("\n/////////////////////////////// MENU MEDICO //////////////////////////////\n");
		printf("\n1 - Consultar Paciente\n2 - Mostrar Pacientes em Observacao\n3 - Retirar Paciente da Observacao\n0 - Logout -> Menu Principal\n");
		scanf("%d", &op3);
		if (op3 == 1)
		{
			int op3a;
			printf("NOME IDADE CPF\n"); // (ATUALIZAR PARA IMPRIMIR DADOS DO CLIENTE) pacienteTriagem[i].nome / pacienteTriagem[i].cpf (PRIMEIRO DA FILA)
			printf("\nPeso Altura Sexo\n"); // (ATUALIZAR PARA IMPRIMIR DADOS DO CLIENTE)
			printf("Sintomas: \n");
			printf("sintoma urgencia\n"); // (ATUALIZAR PARA IMPRIMIR DADOS DO CLIENTE)
			printf("1 - Encerrar Consulta\n2 - Colocar em Observacao\n");
			scanf("%d", &op3a);
			if(op3a == 1)
			{
				char parecer[100];
				printf("Parecer da consulta: ");
				scanf(" %[^\n]", parecer);
				printf("\nFUNCAO PARA INSERIR NOME CPF PACIENTES + PARECER MEDICO EM ARQUIVO TXT.\nImprimindo parecer: %s\n", parecer);
				/* FAZER FUNÇÃO PARA GUARDAR INFORMAÇOES NO ARQUIVO atendidos.txt, MOSTRANDO SUCESSO OU NAO DO ARMAZENAMENTO (MODELO ABAIXO)
				NOME CPF
				PARECER*/
			}
			else if (op3a == 2)
			{
				printf("FUNCAO PARA INSERIR PACIENTES NA OBSERVACAO");
			}
		}
		else if (op3 == 2)
		{
			//imprimePObservacao(pacienteObs, quantP);
			printf("PRINT TESTE - FUNCAO IMPRIMEPOBSERVACAO");
		}
		else if(op3 == 3)
		{
			char cpfA[tamCPF+1];
			printf("Digite o CPF do paciente para dar alta: ");
			scanf(" %s", cpfA);
			/*if (removePObservacao(cpfA, pacienteObs, quantP) == 1) NECESSÁRIA INTERAÇÃO COM ARQUIVO ATENDIDOS.TXT (FPRINTF EM ORDEM DE ATENDIMENTO)
				printf("Paciente liberado!");
			else
				printf("Erro ao liberar paciente.");*/
			printf("PRINT TESTE - FUNCAO REMOVEPOBSERVACAO");
		}
	}while (op3 != 0);
	printf("                          Logout -> Menu Principal\n");
}

void imprimePObservacao(tipoPaciente v[], int q)
{
	/*for (int i = 0; i < q; i++)
	{
		printf("\n%s %d %s %.2fkg %.2fm %c\n"); // NOME IDADE(FUNÇÃO) CPF PESO ALTURA SEXO
		printf("Sintomas: %s\n", pacienteObs[i].sintoma);
	}*/
	printf("CHAMADA IMPRIMEOBSERVACAO FUNCIONAL"); // PARA TESTE
}

int removePObservacao(char cpf[], tipoPaciente v[], int q) // RETORNAR INTEIRO (CASO OCORRA ERRO, RETORNAR 0)
{
	/*for (int i = 0; i < q; i++)
	{
		if (strcmp(cpf, v[i].CPF) == 0)
	}              ARRUMAR FUNCAO*/
	printf("FUNCAO REMOVEPOBSERVACAO FUNCIONAL"); // PARA TESTE
	return 1;
}

void txtPaciente(tipoFuncionario *&list)
{
	FILE *ptPaciente; //ABRIR ARQUIVO TXT
	ptPaciente = fopen("pacientes.txt", "r");
	if (ptPaciente == NULL)
	{
		printf("Erro na leitura do arquivo pacientes.txt\n");
		return;
	}
	else
	{
		char nomeArq[MAX];
		char cpfArq[tamCPF+1];
		float Ps;
		float Alt;
		char S;
		char sintomasArq[100];
		int gravidadeArq;
		tipoData nascArq;
		struct tipoPaciente *prox; //?
		fscanf(ptPaciente, "%d", &quantP);
		for (int i = 0; i < quantP; i++)
		{
			tipoPaciente *novo;
			novo = (tipoPaciente*) malloc(sizeof(tipoFuncionario));
			novo->
		}
		paciente = (tipoPaciente*)malloc(quantP * sizeof(tipoPaciente));
		preencheVetorP(paciente, ptPaciente, quantP);
		fclose(ptPaciente);
	}
}
// ===============================================================================================================

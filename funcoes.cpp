#include <stdio.h>
#include "corpoFunc.h"
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
	do
	{
		printf("\n/////////////////////////// MENU RECEPCIONISTA ///////////////////////////\n");
		printf("\n1 - Cadastrar Paciente\n2 - Remover Paciente\n3 - Buscar Paciente\n0 - Logout -> Menu Principal\n");
		scanf("%d", &op1);
		if(op1 == 1)
		{
			printf("\n              Cadastrar Paciente\n");
			printf("CPF: \n");
			printf("Nome: \n");
			printf("Data Nascimento: \n");
		}
		else if(op1 == 2)
		{
			printf("\n               Remover Paciente\n");
			printf("CPF: "); // char
			int x = 1; // VARIAVEL APENAS PARA TESTE!!!! SERÁ REMOVIDA PARA INSERÇÃO DA FUNÇÃO QUE RETORNA INTEIRO
			if(x == 1)
			{
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
			printf("CPF: "); // char
			int y = 1; // VARIAVEL APENAS PARA TESTE!!!! SERÁ SUBSTITUIDA POR FUNÇÃO QUE RETORNA INTEIRO
			if (y == 0)
				printf("\nPaciente não encontrado\n");
			else
			{
				printf("\nPaciente encontrado em ");
				imprimeSituacao(y);
			}
		}
	}while (op1 != 0);
	printf("                          Logout -> Menu Principal\n");
}
/*int removePaciente() FUNÇÃO PARA REMOVER PACIENTE (PODERÁ SER USADA PARA BUSCAR TAMBEM)
{

}*/
void imprimeSituacao(int N)
{
	if (N == 1)
		printf("fila da triagem\n");
	else if (N == 2)
		printf("fila de espera para chamada médica\n");
}
//=====================================================================================================================
void menuEnfermeiro()
{
	int op2;
	char cpfa[tamCPF+1];
	do
	{
		printf("\n///////////////////////////// MENU ENFERMEIRO ////////////////////////////\n");
		printf("\n1 - Chamar Paciente Triagem\n2 - Visualizar Prontuario\n0 - Logout -> Menu Principal\n");
		scanf("%d", &op2);
		if(op2 == 1)
		{
			printf("           Chamar Paciente Triagem\n");
			printf("NOME IDADE CPF\n"); // (ATUALIZAR PARA IMPRIMIR DADOS DO CLIENTE) pacienteTriagem[i].nome / pacienteTriagem[i].cpf (PRIMEIRO DA FILA)
			printf("\nPeso: ");
			//scanf("%f", &pacienteTriagem[i].peso);
			printf("\nAltura: ");
			//scanf("%f", &pacienteTriagem[i].altura);
			/*while (pacienteTriagem[i].sexo != 'M' || pacienteTriagem[i].sexo != 'F');
			{
				printf("Sexo (F/M):  \n");
				//scanf("%c", &pacienteTriagem[i].sexo);
			}*/
			printf("\nSintomas: ");
			//scanf(" %[^\n]", pacienteTriagem[i].sintomas);
			printf("\n1 - Emergente    2 - Urgente    3 - Nao Urgente\n");
			//scanf("%d", &pacienteTriagem[i].gravidade)
		}
		else if(op2 == 2)
		{
			int op2a;
			printf("Digite CPF do paciente ou 0 para voltar para o Menu Enfermeiro\n");
			scanf(" %s", cpfa);
			// int ind = buscaPaciente(cpfa, pacienteTriagem); - BUSCARÁ INDICE DO PACIENTES NA FILA DA TRIAGEM
			if (strcmp(cpfa, "0") == 0)
				;
			else
			{
				do
				{
					printf("\n\n               Visualizar Prontuario\n\n");
					printf("Nome Idade CPF\n"); // pacienteTriagem[ind].nome / pacienteTriagem[ind].cpf
					printf("Peso Altura Sexo\n"); // pacienteTriagem[ind].peso / pacienteTriagem[ind].altura / 
					printf("Sintomas: \n"); // pacienteTriagem[ind].sintomas
					//printf("%s      ", pacienteTriagem[ind].sintomas)
					int X = 1; //VARIAVEL PARA TESTE, SERÁ REMOVIDA
					imprimeGravidade(X); //paciente[ind].gravidade
					printf("\n1 - Alterar Gravidade\n2 - Alterar Sintomas\n0 - Voltar\n");
					scanf("%d", &op2a);
					if (op2a == 1)
					{
						int novaGravidade;
						printf("\n\n            1 - Alterar Gravidade");
						printf("\n\n   1- Emergente  2 - Urgente  3 - Nao Urgente\n");
						//printf("Digite a nova Gravidade do(a) %s", paciente[ind].nome);
						scanf("%d", &novaGravidade);
						/*if (alteraGravidade(novaGravidade, pacienteTriagem[ind].gravidade) == 1)=========NAO========================================================
							printf("\nGravidade alterada com sucesso!\n");=================================REMOVER====================================================
						else                             ==================================================ESSAS======================================================
							printf("\nErro na alteração!\n");==============================================LINHAS=====================================================*/
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
		}
	}while (op2 != 0);
	printf("                          Logout -> Menu Principal\n");
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

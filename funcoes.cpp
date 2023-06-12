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

void cadastraPaciente(tipoPaciente *&i, tipoPaciente *&f, char n[], char cpf[], tipoData d)
{
	tipoPaciente *novo;
	novo = (tipoPaciente *) malloc(sizeof(tipoPaciente));
	strcpy(novo->nome, n);
	novo->nasc = d;
	strcpy(novo->CPF, cpf);
	novo->prox = NULL;
	if(i == NULL)
 		i = f = novo;
 	else
 	{
 		f->prox = novo;
 		f = novo;
 	}
}

void cadastraPacienteO (tipoPaciente *&i, tipoPaciente *&f, char n[], char cpf[], tipoData d, char C, float P, float H, char s[])
{
	tipoPaciente *novo;
	novo = (tipoPaciente *) malloc(sizeof(tipoPaciente));
	strcpy(novo->nome, n);
	novo->nasc = d;
	strcpy(novo->CPF, cpf);
	novo->nasc = d;
	novo->sexo = C;
	novo->peso = P;
	novo->altura = H;
	strcpy(novo->sintomas, s);
	novo->prox = NULL;
	if(i == NULL)
 		i = f = novo;
 	else
 	{
 		f->prox = novo;
 		f = novo;
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

void empilharRestantes(tipoPaciente *&i, tipoPaciente *&f, tipoPaciente *pilha)
{
	while(i != NULL)
	{
		inspilhaRemovidos(i, pilha);
		i = i->prox;
	}
	i = f = NULL;
}
void arquivaNAtend(tipoPaciente *pilha)
{
    tipoPaciente *fim = NULL;
    tipoPaciente *aux = pilha;
    int cont = 0;

    while (pilha != NULL) {
        cont++;
        pilha = pilha->prox;
    }
    fim = (tipoPaciente*)malloc(cont * sizeof(tipoPaciente));
    pilha = aux;
    for (int i = 0; i < cont; i++) {
        tipoPaciente *K;
        fim[i] = *pilha;
        K = pilha;
        pilha = pilha->prox;
        free(K);
    }

    for (int i = 0; i < cont - 1; i++) {
        for (int j = i + 1; j < cont; j++) {
            if (strcmp(fim[i].nome, fim[j].nome) > 0) {
                tipoPaciente temp = fim[i];
                fim[i] = fim[j];
                fim[j] = temp;
            }
        }
    }

    FILE *arquivo = fopen("naoAtendidos.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo naoAtendidos.txt!\n");
        return;
    }

    for (int i = 0; i < cont; i++) {
        fprintf(arquivo, "%s\n", fim[i].nome);
    }

    fclose(arquivo);
}

void arquivaObs(tipoPaciente* L1, tipoPaciente* L2)
{
	FILE* pont = fopen("observacao.txt", "w");
    tipoPaciente* atual = L1;

    while (atual != NULL) {
        fprintf(pont, "%s\n", atual->nome);
        atual = atual->prox;
    }

    fclose(pont);
}

//=====================================================================================================================
void menuRecepcionista(tipoPaciente *&filaTI, tipoPaciente *&filaTF, tipoPaciente *&filaAt1I, tipoPaciente *&filaAt1F, tipoPaciente *&filaAt2I, tipoPaciente *&filaAt2F, tipoPaciente *&filaAt3I, tipoPaciente *&filaAt3F, tipoPaciente *&removidos)
{
	int op1;
	char nomePac[MAX];
	char cpfP[tamCPF+1];
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
			scanf("%d/%d/%d", &D.dia, &D.mes, &D.ano);
			cadastraPaciente(filaTI, filaTF, nomePac, cpfP, D);
			printf("\nPaciente Registrado\n");
		}

		else if(op1 == 2)
		{
			printf("\n               Remover Paciente\n");
			printf("CPF: ");
			scanf(" %s", cpfP);
			tipoPaciente *removido = removePaciente(cpfP, filaTI, filaTF);
			if(removido == NULL)
			{
				removido = removePaciente(cpfP, filaAt1I, filaAt1F);
				if(removido == NULL)
				{
					removido = removePaciente(cpfP, filaAt2I, filaAt2F);
					if(removido == NULL)
						removido = removePaciente(cpfP, filaAt3I, filaAt3F);
				}
			}

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
			int y = buscaPaciente(cpfP, filaTI, filaAt1I, filaAt2I, filaAt3I);
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


tipoPaciente* removePaciente(char cpf[], tipoPaciente *&lsti, tipoPaciente *&lstf)
{
	tipoPaciente *p, *q;
	p = NULL;
	q = lsti;
	while (q != NULL && strcmp(q->CPF, cpf) != 0)
	{
		p = q;
		q = q->prox;
	}
	if (q == NULL)
		return NULL;
	else if (p == NULL)
		lsti = q->prox;
	else
		p->prox = q->prox;
	if (q->prox == NULL)
		lstf = p;
	return q;
}

void inspilhaRemovidos(tipoPaciente *x, tipoPaciente *&lst)
{
    x->prox = lst;
    lst = x;
}

int buscaPaciente(char cpf[], tipoPaciente *i, tipoPaciente *AT1, tipoPaciente *AT2, tipoPaciente *AT3)
{
	tipoPaciente *aux;
	aux = i;
	while (aux != NULL && strcmp(aux->CPF, cpf) != 0)
		aux = aux->prox;
	if (aux != NULL)
		return 1;
	aux = AT1;
	while (aux != NULL && strcmp(aux->CPF, cpf) != 0)
		aux = aux->prox;
	if (aux != NULL)
		return 2;
	aux = AT2;
	while (aux != NULL && strcmp(aux->CPF, cpf) != 0)
		aux = aux->prox;
	if (aux != NULL)
		return 3;
	aux = AT3;
	while (aux != NULL && strcmp(aux->CPF, cpf) != 0)
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
void menuEnfermeiro(tipoPaciente *&filaTI, tipoPaciente *&filaTF, tipoPaciente *&filaAt1I, tipoPaciente *&filaAt1F, tipoPaciente *&filaAt2I, tipoPaciente *&filaAt2F, tipoPaciente *&filaAt3I, tipoPaciente *&filaAt3F)
{
	int op2;
	char cpf[tamCPF+1];
	tipoPaciente *P;
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
				P = removeFila(filaTI, filaTF);
				printf("%s   ", P->nome);
				printf("%d   ", calculaIdade(P));
				printf("%s   ", P->CPF);
				printf("\nPeso: ");
				scanf("%f", &P->peso);
				printf("\nAltura: ");
				scanf("%f", &P->altura);
				do
				{
					printf("Sexo (F/M):  \n");
					scanf(" %c", &P->sexo);
				}while (P->sexo != 'M' && P->sexo != 'F');

				printf("\nSintomas: ");
				scanf(" %[^\n]", P->sintomas);
				printf("\n1 - Emergente    2 - Urgente    3 - Nao Urgente\n");
				scanf("%d", &P->gravidade);
				if(P->gravidade == 1)
				{
					filaAtend(P, filaAt1I, filaAt1F);
					printf("Paciente registrado na fila Emergente com sucesso!");
				}
				else if(P->gravidade == 2)
				{
					filaAtend(P, filaAt2I, filaAt2F);
					printf("Paciente registrado na fila Urgente com sucesso!");
				}
				else if(P->gravidade == 3)
				{
					filaAtend(P, filaAt3I, filaAt3F);
					printf("Paciente registrado na fila Nao Urgente com sucesso!");
				}
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
					aux = buscaPacienteEsp(cpf, filaAt1I, filaAt2I, filaAt3I);
					char primeiroNome[MAX];
					strcpy(primeiroNome, strtok(aux->nome, " "));
					do
					{
						printf("\n\n               Visualizar Prontuario\n\n");
						printf("%s   ", aux->nome);
						printf("%d   ", calculaIdade(aux));
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
							printf("Digite a nova Gravidade do(a) %s: ", primeiroNome);
							scanf("%d", &novaGravidade);
							if (aux->gravidade == novaGravidade)
								printf("Erro na alteração\n");
							else
							{
								alteraGravidade(novaGravidade, aux, filaAt1I, filaAt1F, filaAt2I, filaAt2F, filaAt3I, filaAt3F);
								printf("Gravidade alterada com sucesso!\n");
							}
						}
						else if(op2a == 2)
						{
							char novoSintoma[100];
							printf("\n\n            2 - Alterar Sintoma\n");
							printf("\nDigite o(s) novo(s) sintoma(s) de %s: ", primeiroNome);
							scanf(" %[^\n]", novoSintoma);
							if (alteraSintoma(aux, novoSintoma) == 0)
								printf("\nErro na alteração!\n");
							else
								printf("\nSintomas Alterados com sucesso!\n");
						}
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
tipoPaciente* removeFila(tipoPaciente *&lsti, tipoPaciente *&lstf)
{
	tipoPaciente *aux;
	if (lsti == NULL)
		return NULL;
	else if (lsti == lstf)
	{
		aux = lsti;
		lsti = lstf = NULL;
		return aux;
	}
	else
	{
		aux = lsti;
		lsti = lsti->prox;
		return aux;
	}
}
void filaAtend(tipoPaciente *p, tipoPaciente *&lsti, tipoPaciente *&lstf)
{
	if (lstf == NULL)
	{
		lsti = lstf = p;
	}
	else
	{
		lstf->prox = p;
		lstf = p;
	}
	p->prox = NULL;

}

tipoPaciente* buscaPacienteEsp(char cpf[], tipoPaciente *lst1, tipoPaciente *lst2, tipoPaciente *lst3)
{
	tipoPaciente *q;
	q = lst1;
	while (q != NULL && strcmp(q->CPF, cpf) != 0)
		q = q->prox;
	if (q != NULL)
		return q;
	q = lst2;
	while (q != NULL && strcmp(q->CPF, cpf) != 0)
		q = q->prox;
	if (q != NULL)
		return q;
	q = lst3;
	while (q != NULL && strcmp(q->CPF, cpf) != 0)
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
void alteraGravidade(int ng, tipoPaciente *p, tipoPaciente *&L1i, tipoPaciente *&L1f, tipoPaciente *&L2i, tipoPaciente *&L2f, tipoPaciente *&L3i, tipoPaciente *&L3f)
{
	if (p->gravidade == 1)
	{
		removeNo(p, L1i, L1f);
		printf("REMOVIDO DA FILA 1\n");
	}
	else if (p->gravidade == 2)
	{
		removeNo(p, L2i, L2f);
		printf("REMOVIDO DA FILA 2\n");
	}
	else if (p->gravidade == 3)
	{
		removeNo(p, L3i, L3f);
		printf("REMOVIDO DA FILA 3\n");
	}

	p->gravidade = ng;

	if (ng == 1)
		inserefimLista(p, L1i, L1f);
	else if(ng == 2)
		inserefimLista(p, L2i, L2f);
	else if(ng == 3)
		inserefimLista(p, L3i, L3f);
}

void removeNo(tipoPaciente *P, tipoPaciente *&i, tipoPaciente *&f) // PERCORRE A LISTA, BUSCANDO UM NÓ E O REMOVE
{
	tipoPaciente *p = NULL;
    tipoPaciente *q = i;

    while (q != NULL && q != P) {
        p = q;
        q = q->prox;
    }

    if (q == NULL)
        ;

    if (p == NULL)
        i = q->prox;
    else
        p->prox = q->prox;

    if (q == f)
        f = p;
}

void inserefimLista(tipoPaciente *P, tipoPaciente *&I, tipoPaciente *&F)
{
	if (I == NULL)
        I = F = P;
    else
    {
        F->prox = P;
        F = P;
    }
    P->prox = NULL;
}

int alteraSintoma(tipoPaciente *p, char ss[])
{
	if (strcasecmp(p->sintomas, ss) == 0)
		return 0;
	strcpy(p->sintomas, ss);
	return 1;
}
//==================================================================================================
void menuMedico(tipoPaciente *&lst1i, tipoPaciente *&lst1f, tipoPaciente *&lst2i, tipoPaciente *&lst2f, tipoPaciente *&lst3i, tipoPaciente *&lst3f, tipoPaciente *&lstOi, tipoPaciente *&lstOf)
{
	int op3;
	tipoPaciente *P = NULL;
	char cpfA[tamCPF+1];
	do
	{
		printf("\n/////////////////////////////// MENU MEDICO //////////////////////////////\n");
		printf("\n1 - Consultar Paciente\n2 - Mostrar Pacientes em Observacao\n3 - Retirar Paciente da Observacao\n0 - Logout -> Menu Principal\n");
		scanf("%d", &op3);
		if (op3 == 1)
		{
			if(lst1i != NULL)
				P = removeFila(lst1i, lst1f);
			else
			{
				if (lst2i != NULL)
					P = removeFila(lst2i, lst2f);
				else
				{
					if (lst3i != NULL)
						P = removeFila(lst3i, lst3f);
				}
			}
				
			if (P == NULL)
				printf("Não ha pacientes nas filas\n");
			else
				consulta(P, lstOi, lstOf);
		}
		else if (op3 == 2)
			imprimePObservacao(lstOi);
		else if(op3 == 3)
		{
			printf("Digite o CPF do paciente para dar alta: ");
			scanf(" %s", cpfA);
			P = removePaciente(cpfA, lstOi, lstOf);
			if (P == NULL)
				printf("Paciente nao encontrado!\n\n");
			else
			{
				FILE* arq = fopen("atendidos.txt", "a");
    			if (arq == NULL) 
    				printf("Erro ao abrir arquivo atendidos.txt\n\n");
    			else
    			{
        			fprintf(arq, "%s %s\n", P->nome, P->CPF);
        			fclose(arq);
        			printf("Consulta armazenada com sucesso!\n");
        			printf("Paciente liberado!\n");
    			}
			}
		}
	}while (op3 != 0);
	printf("                          Logout -> Menu Principal\n");
}

void consulta(tipoPaciente *p, tipoPaciente *&i, tipoPaciente *&f)
{
	int op3a;
	printf("%s   ", p->nome);
	printf("%d   ", calculaIdade(p));
	printf("%s\n", p->CPF);
	printf("%.2fkg   ", p->peso);
	printf("%.2fm    ", p->altura); 
	printf("%c\n", p->sexo);
	printf("Sintomas: \n");
	printf("%s   ", p->sintomas);
	imprimeGravidade(p->gravidade);
	printf("\n\n");
	printf("1 - Encerrar Consulta\n2 - Colocar em Observacao\n");
	scanf("%d", &op3a);
	if(op3a == 1)
	{
		char parecer[100];
		printf("Parecer da consulta: ");
		scanf(" %[^\n]", parecer);
		gravaAtendidos(p, parecer);
		free(p);
	}
	else if (op3a == 2)
	{
		inserefimLista(p, i, f);
	}
}

void gravaAtendidos(tipoPaciente *p, char parecer[])
{
    FILE* arq = fopen("atendidos.txt", "a");
    if (arq == NULL) 
    	printf("Erro ao abrir arquivo atendidos.txt\n");
    else
    {
        fprintf(arq, "%s, %s\n%s\n", p->nome, p->CPF, parecer);
        fclose(arq);
        printf("Consulta armazenada com sucesso!\n");
    }
}

void imprimePObservacao(tipoPaciente *lst)
{
	tipoPaciente *aux = lst;
	while (aux != NULL)
	{
		printf("\n%s %d %s %.2fkg %.2fm %c\n", aux->nome, calculaIdade(aux), aux->CPF, aux->peso, aux->altura, aux->sexo);
		printf("Sintomas: %s\n", aux->sintomas);
		aux = aux->prox;
	}
}
// ===============================================================================================================

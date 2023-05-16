#include <stdio.h>

void imprimeRecepcionista();
char imprimeGravidade(int gravidade);

void imprimeRecepcionista();
int menuRecepcionista()
{
	int op1;
	imprimeRecepcionista();
	do
	{
		printf("\n1 - Cadastrar Paciente\n2 - Remover Paciente\n3 - Buscar Paciente\n0 - Logout -> Menu Principal\n");
		scanf("%d", &op1);
		if(op1 == 1)
		{
			imprimeRecepcionista();
			printf("\n              Cadastrar Paciente\n");
			printf("CPF: \n");
			printf("Nome: \n");
			printf("Data Nascimento: \n");
		}
		else if(op1 == 2)
		{
			imprimeRecepcionista();
			printf("\n               Remover Paciente\n");
			printf("CPF: ");
			if()
			{
				printf("\nPaciente removido com sucesso.\n")
			}
		}
		else if(op1 == 3)
		{
			imprimeRecepcionista();
			printf("\n               Buscar Paciente\n");

		}
	}while (op1 != 0);
}
//======================================================================================================================
int menuEnfermeiro();
{
	int op2;
	imprimeEnfermeiro()
	do
	{
		printf("\n1 - Chamar Paciente Triagem\n2 - Visualizar Prontuário\n0 - Logout -> Menu Principal\n");
		scanf("%d", &op2);
		if(op2 == 1)
		{
			printf("Digite CPF do paciente ou 0 para voltar para o Menu Enfermeiro\n");
			scanf("%d", &cpf);
			do
			{
				imprimeEnfermeiro();
				printf("           Chamar Paciente Triagem\n");
				printf("NOME IDADE CPF\n"); // (ATUALIZAR PARA IMPRIMIR DADOS DO CLIENTE)
				printf("Peso: \n");
				printf("Altura: \n");
				printf("Sexo: \n");
				printf("Sintomas: \n");
				printf("1 - Emergente    2 - Urgente    3 - Não Urgente\n");
				printf("Digite CPF do paciente ou 0 para voltar para o Menu Enfermeiro\n");
				scanf("%d", &cpf);
			}while (cpf != 0);
			
		}
		else if(op2 == 2)
		{
			int op2a;
			imprimeEnfermeiro();
			do{
				printf("               Visualizar Prontuário\n\n");
				scanf("%d", &cpf);
				printf("Nome Idade CPF\n");
				printf("Peso Altura Sexo\n");
				printf("Sintomas: %s ", paciente.nome);
				printf("%s\n", imprimeGravidade(paciente.gravidade));
				printf("\n1 - Alterar Gravidade\n2 - Alterar Sintomas\n0 - Voltar");
				scanf("%d", &op2a);
				if (op2a == 1)
				{
					printf("\n\n            1 - Alterar Gravidade");
					printf("\n\n   1- Emergente  2 - Urgente  3 - Não Urgente\n");
					printf("Digite a nova Gravidade do(a) %s", paciente.nome);
					scanf("%d", &paciente.gravidade);
				}
				else if(op2a == 2)
			}while (op2a != 0)	
		}
	}while (op2 != 0);
}
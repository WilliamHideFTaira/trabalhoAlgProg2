#include <stdio.h>

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

//====================================FUNCOES==================================

void imprimeRecepcionista()
{
	printf("\n\n              Recepcionista\n");

}
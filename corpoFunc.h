//=======FUNÇÕES PARA COMPARTILHAR ENTRE MAIN.CPP E FUNCOES.CPP=============
#define MAX 27
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
void preencheVetorP(tipoPaciente v[], FILE *p, int q);
void imprimetxtFunc(int a);
bool verificaCredenciais(char c[], char cpf[], tipoFuncionario v[], int X);
void menuRecepcionista();
void menuEnfermeiro();
void menuMedico();
void imprimeSituacao(int N);
void imprimeGravidade(int gravidade);
int alteraGravidade(int ng, tipoPaciente v[]);
void imprimePObservacao(tipoPaciente v[], int q);
int removePObservacao(char cpf[], tipoPaciente v[], int q);
void txtPaciente(tipoFuncionario *&list);
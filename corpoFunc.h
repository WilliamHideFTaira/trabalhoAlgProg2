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
void menuRecepcionista(tipoPaciente *&filaTI, tipoPaciente *&filaTF, tipoPaciente *&filaAt1I, tipoPaciente *&filaAt1F, tipoPaciente *&filaAt2I, tipoPaciente *&filaAt2F, tipoPaciente *&filaAt3I, tipoPaciente *&filaAt3F, tipoPaciente *&removidos);
void menuEnfermeiro(tipoPaciente *&filaTI, tipoPaciente *&filaTF, tipoPaciente *&filaAt1I, tipoPaciente *&filaAt1F, tipoPaciente *&filaAt2I, tipoPaciente *&filaAt2F, tipoPaciente *&filaAt3I, tipoPaciente *&filaAt3F);
void menuMedico(tipoPaciente *&lst1i, tipoPaciente *&lst1f, tipoPaciente *&lst2i, tipoPaciente *&lst2f, tipoPaciente *&lst3i, tipoPaciente *&lst3f, tipoPaciente *&lstOi, tipoPaciente *&lstOf);
tipoPaciente* removePaciente(char cpf[], tipoPaciente *&i, tipoPaciente *&f);
void inspilhaRemovidos(tipoPaciente *x, tipoPaciente *&lst);
int buscaPaciente(char cpf[], tipoPaciente *i, tipoPaciente *AT1, tipoPaciente *AT2, tipoPaciente *AT3);
void imprimeSituacao(int N);
int calculaIdade(tipoPaciente *P);
void imprimeGravidade(int gravidade);
void alteraGravidade(int ng, tipoPaciente *p, tipoPaciente *&L1i, tipoPaciente *&L1f, tipoPaciente *&L2i, tipoPaciente *&L2f, tipoPaciente *&L3i, tipoPaciente *&L3f);
void removeNo(tipoPaciente *P, tipoPaciente *&i, tipoPaciente *&f);
void inserefimLista(tipoPaciente *P, tipoPaciente *&I, tipoPaciente *&F); 
void imprimePObservacao(tipoPaciente *lst);
int removePObservacao(char cpf[], tipoPaciente v[], int q);
void empilharRestantes(tipoPaciente *&i, tipoPaciente *&f, tipoPaciente *pilha);
void arquivaNAtend(tipoPaciente *pilha);
void arquivaObs(tipoPaciente* L1, tipoPaciente* L2);
tipoPaciente* removeFila(tipoPaciente *&lsti, tipoPaciente *&lstf);
void gravaAtendidos(tipoPaciente *p, char parecer[]);
void cadastraPacienteO (tipoPaciente *&i, tipoPaciente *&f, char n[], char cpf[], tipoData d, char C, float P, float H, char s[]);
void filaAtend(tipoPaciente *p, tipoPaciente *&lsti, tipoPaciente *&lstf);
tipoPaciente* buscaPacienteEsp(char cpf[], tipoPaciente *lst1, tipoPaciente *lst2, tipoPaciente *lst3);
int alteraSintoma(tipoPaciente *p, char ss[]);
void consulta(tipoPaciente *p, tipoPaciente *&i, tipoPaciente *&f);
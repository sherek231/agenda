
#define MAX_CONTATOS 100// Define uma constante que representa o número máximo de contatos que a agenda pode armazenar


// Estrutura para armazenar informações de um contato
typedef struct {
    char nome[100];
    char telefone[15];
    char email[50];
} Contato;

// Funções da agenda

//Adicionar contatos na agenda
void adicionarContato(Contato agenda[], int *contador);
// Lista todos os contatos na agenda
void listarContatos(Contato agenda[], int contador);
// Busca um contato na agenda pelo nome
void buscarContato(Contato agenda[], int contador, const char *nome);
// Remove um contato da agenda pelo nome
void removerContato(Contato agenda[], int *contador, const char *nome);
// Exibe o menu principal da agenda e lida com as opções do usuário
void Menuagenda();



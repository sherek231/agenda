#include <stdio.h>// Biblioteca padr�o para opera��es de entrada e sa�da (ex: printf, scanf)
#include <unistd.h> // Biblioteca para fornecer acesso a chamadas do sistema POSIX, como sleep (pausa) e manipula��o de processos
#include <stdlib.h> // Biblioteca padr�o para fun��es de prop�sito geral, como aloca��o de mem�ria, controle de processos, convers�o de n�meros, etc.
#include <conio.h>   // Biblioteca para fun��es de entrada/sa�da do console, especialmente para manipula��o de teclado, como getch() (dispon�vel principalmente em ambientes Windows)
#include <string.h>  // Biblioteca para manipula��o de strings, oferecendo fun��es como strcpy, strcat, strcmp, entre outras
#include "listaEstatica.h"  // Inclus�o do arquivo de cabe�alho onde as fun��es e defini��es espec�ficas do projeto (como as da agenda) est�o declaradas


void Menuagenda(){
	
	// Exibe o menu principal da agenda e lida com as op��es do usu�rio

	system("cls");
	Contato agenda[MAX_CONTATOS]; // Array de contatos
    int contador = 0; // N�mero de contatos na agenda
    int opcao; // Vari�vel para armazenar a escolha do usu�rio
    char nome[100]; // Armazena o nome do contato para busca/remover

    do {
    	    	// Exibe o menu de op��es

    	printf("\t\t\t\t\t\t\t\t\t|-----------------------------------|\n");
        printf("\t\t\t\t\t\t\t\t\t|------------Menu da Agenda---------|\n");
        printf("\t\t\t\t\t\t\t\t\t|-----------------------------------|\n");
        printf("\t\t\t\t\t\t\t\t\t||1|. Adicionar Contato             |\n");
        printf("\t\t\t\t\t\t\t\t\t||2|. Listar Contatos               |\n");
        printf("\t\t\t\t\t\t\t\t\t||3|. Buscar Contato                |\n");
        printf("\t\t\t\t\t\t\t\t\t||4|. Remover Contato               |\n");
        printf("\t\t\t\t\t\t\t\t\t||5|. Sair                          |\n");
         printf("\t\t\t\t\t\t\t\t\t|-----------------------------------|\n");
        printf("\t\t\t\t\t\t\t\t\tEscolha uma op��o: ");
       
        scanf("%d", &opcao); // Captura a op��o escolhida pelo usu�rio

        switch (opcao) {
            case 1:

                adicionarContato(agenda, &contador); //Adicionar contatos
                break;
            case 2:

                listarContatos(agenda, contador); //listar contatos
                break;
            case 3:
		system("cls"); // Limpa a tela
  				 // Solicita ao usu�rio o nome do contato para buscar
                printf("Digite o nome do contato a ser buscado: ");
                scanf(" %s", nome);
                 // Chama a fun��o para buscar o contato pelo nome
                buscarContato(agenda, contador, nome);
                break;
            case 4:
				system("cls"); //limpa a tela
				  // Solicita ao usu�rio o nome do contato para remover
                printf("Digite o nome do contato a ser removido: ");
                scanf(" %s", nome);
                removerContato(agenda, &contador, nome); // Busca um contato pelo nome
                break;
            case 5:

                printf("Saindo...\n"); //sair
                break;
            default:
                printf("Op��o inv�lida!\n"); // Informa que a op��o � inv�lida
        }
    } while (opcao != 5); // Repete at� o usu�rio escolher sair

}

// Adiciona um novo contato � agenda
void adicionarContato(Contato agenda[], int *contador) {
system("cls");//limpar tela
    if (*contador < MAX_CONTATOS) { // Verifica se a agenda n�o est� cheia

        printf("\nDigite o nome do contato: \n");
        scanf(" %s", agenda[*contador].nome);
        printf("Digite o telefone do contato: ");
        scanf(" %s", agenda[*contador].telefone);
        printf("Digite o email do contato: ");
        scanf(" %s", agenda[*contador].email);
        (*contador)++; // Incrementa o contador de contatos
        	

        printf("\033[0;32mContato adicionado com sucesso!\033[0m\n");
         sleep(3); // Pausa por 3 segundos
        system("cls"); // Limpa a tela
        
    } else {
        printf("Agenda cheia! N�o � poss�vel adicionar mais contatos.\n");
    }
}
// Fun��o auxiliar para comparar nomes (usada para ordena��o)
int compararNomes(const void *a, const void *b) {//Esses s�o ponteiros gen�ricos que apontam para os elementos a serem comparados.
    Contato *contatoA = (Contato *)a;//convertemos esses ponteiros gen�ricos (void *) para ponteiros do tipo Contato usando (Contato *)a e (Contato *)b.
    Contato *contatoB = (Contato *)b;
    return strcmp(contatoA->nome, contatoB->nome);//para comparar os nomes dos dois contatos
}
// Lista todos os contatos em ordem alfab�tica
void listarContatos(Contato agenda[], int contador) {
   

    if (contador == 0) {
        printf("A agenda est� vazia.\n"); // Verifica se a agenda est� vazia
    } else {
        // Ordena os contatos em ordem alfab�tica
        qsort(agenda, contador, sizeof(Contato), compararNomes);

        // Exibe os contatos
        for (int i = 0; i < contador; i++) {
        	system("cls");
        	printf("\t\t\t\t\t\t\t\t\t--------------------------|\n");
            printf("\t\t\t\t\t\t\t\t\t|Contato %d:\n", i + 1);
            printf("\t\t\t\t\t\t\t\t\t|Nome: %s\n", agenda[i].nome);
            printf("\t\t\t\t\t\t\t\t\t|Telefone: %s\n", agenda[i].telefone);
            printf("\t\t\t\t\t\t\t\t\t|Email: %s\n", agenda[i].email);
            printf("\t\t\t\t\t\t\t\t\t|-------------------------|\n");
           	  system("pause"); // Pausa at� que o usu�rio pressione uma tecla
             system("cls");
        }
    }
}
// Busca um contato pelo nome
void buscarContato(Contato agenda[], int contador, const char *nome) {
            	

    for (int i = 0; i < contador; i++) {
    		
        if (strcmp(agenda[i].nome, nome) == 0) { // Verifica se o nome corresponde
            printf("\t\t\t\t\t\t\t\t\tContato encontrado:\n");
            printf("\t\t\t\t\t\t\t\t\tNome: %s\n", agenda[i].nome);
            printf("\t\t\t\t\t\t\t\t\tTelefone: %s\n", agenda[i].telefone);
            printf("\t\t\t\t\t\t\t\t\tEmail: %s\n", agenda[i].email);
            system("pause"); // Pausa para o usu�rio ver o resultado
        	system("cls");//limpar tela
        	
        	
        }
    }
    // Exibe mensagem em vermelho se o contato n�o for encontrado
    printf("\x1B[0;31mContato n�o encontrado.\x1B[0m\n");
}
// Remove um contato pelo nome
void removerContato(Contato agenda[], int *contador, const char *nome) {
            		system("cls");

    for (int i = 0; i < *contador; i++) { // Verifica se o nome corresponde
            // Move todos os contatos seguintes para preencher o espa�o
    		

        if (strcmp(agenda[i].nome, nome) == 0) {
            for (int j = i; j < *contador - 1; j++) {
                agenda[j] = agenda[j + 1];
            }
            (*contador)--; // Decrementa o contador de contatos
            
		  // Exibe uma mensagem de sucesso em verde
            printf("\033[0;32mContato removido com sucesso!\033[0m\n");
            	sleep(3); // Pausa por 3 segundos
            	system("cls");
        }
    }
     // Exibe mensagem em vermelho se o contato n�o for encontrado
    printf("\x1B[0;31mContato n�o encontrado.\x1B[0m");
     	 sleep(3); // Pausa por 3 segundos
   		system("cls");
}


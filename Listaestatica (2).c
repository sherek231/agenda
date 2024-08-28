#include <stdio.h>// Biblioteca padrão para operações de entrada e saída (ex: printf, scanf)
#include <unistd.h> // Biblioteca para fornecer acesso a chamadas do sistema POSIX, como sleep (pausa) e manipulação de processos
#include <stdlib.h> // Biblioteca padrão para funções de propósito geral, como alocação de memória, controle de processos, conversão de números, etc.
#include <conio.h>   // Biblioteca para funções de entrada/saída do console, especialmente para manipulação de teclado, como getch() (disponível principalmente em ambientes Windows)
#include <string.h>  // Biblioteca para manipulação de strings, oferecendo funções como strcpy, strcat, strcmp, entre outras
#include "listaEstatica.h"  // Inclusão do arquivo de cabeçalho onde as funções e definições específicas do projeto (como as da agenda) estão declaradas


void Menuagenda(){
	
	// Exibe o menu principal da agenda e lida com as opções do usuário

	system("cls");
	Contato agenda[MAX_CONTATOS]; // Array de contatos
    int contador = 0; // Número de contatos na agenda
    int opcao; // Variável para armazenar a escolha do usuário
    char nome[100]; // Armazena o nome do contato para busca/remover

    do {
    	    	// Exibe o menu de opções

    	printf("\t\t\t\t\t\t\t\t\t|-----------------------------------|\n");
        printf("\t\t\t\t\t\t\t\t\t|------------Menu da Agenda---------|\n");
        printf("\t\t\t\t\t\t\t\t\t|-----------------------------------|\n");
        printf("\t\t\t\t\t\t\t\t\t||1|. Adicionar Contato             |\n");
        printf("\t\t\t\t\t\t\t\t\t||2|. Listar Contatos               |\n");
        printf("\t\t\t\t\t\t\t\t\t||3|. Buscar Contato                |\n");
        printf("\t\t\t\t\t\t\t\t\t||4|. Remover Contato               |\n");
        printf("\t\t\t\t\t\t\t\t\t||5|. Sair                          |\n");
         printf("\t\t\t\t\t\t\t\t\t|-----------------------------------|\n");
        printf("\t\t\t\t\t\t\t\t\tEscolha uma opção: ");
       
        scanf("%d", &opcao); // Captura a opção escolhida pelo usuário

        switch (opcao) {
            case 1:

                adicionarContato(agenda, &contador); //Adicionar contatos
                break;
            case 2:

                listarContatos(agenda, contador); //listar contatos
                break;
            case 3:
		system("cls"); // Limpa a tela
  				 // Solicita ao usuário o nome do contato para buscar
                printf("Digite o nome do contato a ser buscado: ");
                scanf(" %s", nome);
                 // Chama a função para buscar o contato pelo nome
                buscarContato(agenda, contador, nome);
                break;
            case 4:
				system("cls"); //limpa a tela
				  // Solicita ao usuário o nome do contato para remover
                printf("Digite o nome do contato a ser removido: ");
                scanf(" %s", nome);
                removerContato(agenda, &contador, nome); // Busca um contato pelo nome
                break;
            case 5:

                printf("Saindo...\n"); //sair
                break;
            default:
                printf("Opção inválida!\n"); // Informa que a opção é inválida
        }
    } while (opcao != 5); // Repete até o usuário escolher sair

}

// Adiciona um novo contato à agenda
void adicionarContato(Contato agenda[], int *contador) {
system("cls");//limpar tela
    if (*contador < MAX_CONTATOS) { // Verifica se a agenda não está cheia

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
        printf("Agenda cheia! Não é possível adicionar mais contatos.\n");
    }
}
// Função auxiliar para comparar nomes (usada para ordenação)
int compararNomes(const void *a, const void *b) {//Esses são ponteiros genéricos que apontam para os elementos a serem comparados.
    Contato *contatoA = (Contato *)a;//convertemos esses ponteiros genéricos (void *) para ponteiros do tipo Contato usando (Contato *)a e (Contato *)b.
    Contato *contatoB = (Contato *)b;
    return strcmp(contatoA->nome, contatoB->nome);//para comparar os nomes dos dois contatos
}
// Lista todos os contatos em ordem alfabética
void listarContatos(Contato agenda[], int contador) {
   

    if (contador == 0) {
        printf("A agenda está vazia.\n"); // Verifica se a agenda está vazia
    } else {
        // Ordena os contatos em ordem alfabética
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
           	  system("pause"); // Pausa até que o usuário pressione uma tecla
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
            system("pause"); // Pausa para o usuário ver o resultado
        	system("cls");//limpar tela
        	
        	
        }
    }
    // Exibe mensagem em vermelho se o contato não for encontrado
    printf("\x1B[0;31mContato não encontrado.\x1B[0m\n");
}
// Remove um contato pelo nome
void removerContato(Contato agenda[], int *contador, const char *nome) {
            		system("cls");

    for (int i = 0; i < *contador; i++) { // Verifica se o nome corresponde
            // Move todos os contatos seguintes para preencher o espaço
    		

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
     // Exibe mensagem em vermelho se o contato não for encontrado
    printf("\x1B[0;31mContato não encontrado.\x1B[0m");
     	 sleep(3); // Pausa por 3 segundos
   		system("cls");
}

